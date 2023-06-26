import { FormControl } from "@chakra-ui/form-control";
import { Input } from "@chakra-ui/input";
import { Box, Text } from "@chakra-ui/layout";
import { IconButton, Spinner, useToast } from "@chakra-ui/react";
import { getSender, getSenderFull, getSenderId, getSendersId } from "../config/ChatLogics";
import { useEffect, useState } from "react";
import axios from "axios";
import { ArrowBackIcon } from "@chakra-ui/icons";
import io from "socket.io-client";
import Lottie from "react-lottie";


import "./styles.css";
import ProfileModal from "./ProfileModal";
import ScrollableChat from "./ScrollableChat";
import animationData from "../animations/typing.json";
import UpdateGroupChatModal from "./UpdateGroupChatModal";
import { ChatState } from "../context/ChatProvider";
import EmojiPicker from 'emoji-picker-react';

import userApi from "../api/modules/user.api";
import chatApi from "../api/modules/chat.api";
import messageApi from "../api/modules/message.api";
import notificationApi from "../api/modules/notification.api";

const ENDPOINT = `${process.env.REACT_APP_SOCKET_URL}` || "http://127.0.0.1:5000";

var socket, selectedChatCompare;

const SingleChat = ({ fetchAgain, setFetchAgain }) => {

  const [messages, setMessages] = useState([]);
  const [loading, setLoading] = useState(false);
  const [newMessage, setNewMessage] = useState("");
  const [socketConnected, setSocketConnected] = useState(false);
  const [typing, setTyping] = useState(false);
  const [istyping, setIsTyping] = useState(false);
  const [isOnline, setIsOnline] = useState(false);
  const [onlineUsers , setOnlineUsers] = useState([]); // [(user._id, socket.id()), ...]
  const [showEmojiPicker, setShowEmojiPicker] = useState(false);
  const toast = useToast();
  const [room, setRoom] = useState("");

  const { selectedChat, setSelectedChat, user, notification, setNotification } = ChatState();

  const defaultOptions = {
    loop: true,
    autoplay: true,
    animationData: animationData,
    rendererSettings: {
      preserveAspectRatio: "xMidYMid slice",
    },
  };

  useEffect(() => {
    socket = io(ENDPOINT);
    socket.emit("setup", user);
    socket.on("connected", () => setSocketConnected(true));
    socket.on("typing", (room) => {
      setIsTyping(true)
      setRoom(room)
    });
    socket.on("stop typing", () => setIsTyping(false));
    socket.on("onlineUsers", (users) => setOnlineUsers(users));

    return () => {
      socket.disconnect();
    };

  }, []);

  const deleteNotifications = async (chatId) => {
    const { response, error } = await notificationApi.deleteNotifications({
      chatId,
      receiverId: user._id,
    });

    if (response) {
      setNotification(
        notification.filter((n) => n.chat._id !== selectedChat._id)
      );
      console.log("Notifications Deleted");
    }

    if (error) {
      console.log(error);
    }
  };
  
  useEffect(() => {
    fetchMessages();

    if (selectedChat) {
      deleteNotifications(selectedChat._id);
    }

    selectedChatCompare = selectedChat;
  }, [selectedChat]);

  useEffect(() => {
    socket.on("message received", (newMessageRecieved) => {
      if (
        !selectedChatCompare ||
        selectedChatCompare._id !== newMessageRecieved.chat._id
      ) {
        if (!notification.includes(newMessageRecieved)) {
          console.log(newMessageRecieved);
          setNotification([newMessageRecieved, ...notification]);
          setFetchAgain(!fetchAgain);
        }
      } else {
        setFetchAgain(!fetchAgain);
        setMessages([...messages, newMessageRecieved]);
        if (selectedChat) {
          deleteNotifications(selectedChat._id);
        }
      }
    });
  });


  const fetchMessages = async () => {
    if (!selectedChat) return;

    setLoading(true);
    const { response, error } = await messageApi.fetchMessages({
      chatId: selectedChat._id,
    });

    if (response) {
      setMessages(response);
      setLoading(false);

      socket.emit("join chat", selectedChat._id);
    }

    if (error) {
      toast({
        title: "Error Occured!",
        description: "Failed to Load the Messages",
        status: "error",
        duration: 5000,
        isClosable: true,
        position: "bottom",
      });
      setLoading(false);
    }
  }

  const sendMessage = async (event) => {
    if (event.key === "Enter" && newMessage) {

      socket.emit("stop typing", selectedChat._id);

      const { response, error } = await messageApi.sendMessage({
        content: newMessage,
        chatId: selectedChat._id,
      });

      setNewMessage("");

      if (response) {
        socket.emit("new message", response);
        setMessages([...messages, response]);
        setFetchAgain(!fetchAgain);

        // Enviar notificações
        const receivers = getSendersId(user, selectedChat.users);
        receivers.forEach(async (receiverId) => {
          const data = await notificationApi.sendNotification({
            receiverId,
            chatId: selectedChat._id,
            content: newMessage,
          });

          if (data.response) {
            console.log("Notification Sent");
          }

          if (data.error) {
            console.log(error);
          }
        });
        

      }

      if (error) {
        toast({
          title: "Error Occured!",
          description: "Failed to send the Message",
          status: "error",
          duration: 5000,
          isClosable: true,
          position: "bottom",
        });
      }
    }
  }

  const typingHandler = (e) => {
    setNewMessage(e.target.value);

    if (!socketConnected) return;

    if (!typing) {
      setTyping(true);
      socket.emit("typing", selectedChat._id);
    }
    
    let lastTypingTime = new Date().getTime();
    var timerLength = 3000;
    setTimeout(() => {
      var timeNow = new Date().getTime();
      var timeDiff = timeNow - lastTypingTime;
      if (timeDiff >= timerLength && !typing) {
        socket.emit("stop typing", selectedChat._id);
        setTyping(false);
      }
    }, timerLength);
  }


  return (
    <>
        {selectedChat ? (
            <>
                <Text
                    fontSize={{ base: "28px", md: "30px" }}
                    pb={3}
                    px={2}
                    w="100%"
                    fontFamily="Work sans"
                    display="flex"
                    justifyContent={{ base: "space-between" }}
                    alignItems="center"
                >
                    <IconButton
                        display={{ base: "flex", md: "none" }}
                        icon={<ArrowBackIcon />}
                        onClick={() => setSelectedChat("")}
                    />
                    {messages && (!selectedChat.isGroupChat ? (
                        <>
                            <Box>
                                <Text>
                                  {getSender(user, selectedChat.users)}
                                </Text>
                                  {onlineUsers.find((u) => u[0] === getSenderId(user, selectedChat.users)) ? (
                                    <Box
                                      display="flex"
                                      alignItems="center"
                                      justifyContent="flex-start"
                                      gap={1}
                                    >
                                      <i 
                                        className="fas fa-circle" 
                                        style={{ 
                                          color: "green", 
                                          fontSize: "10px" 
                                        }}></i>
                                      <Text fontSize="sm" color="gray.500">
                                        Online
                                      </Text>
                                    </Box>
                                  ) : (
                                    <Box
                                      display="flex"
                                      alignItems="center"
                                      justifyContent="flex-start"
                                      gap={1}
                                    >
                                      <i 
                                        className="fas fa-circle" 
                                        style={{ 
                                          color: "grey", 
                                          fontSize: "10px",
                                        }}></i>
                                      <Text fontSize="sm" color="gray.500">
                                        Offline
                                      </Text>
                                    </Box>
                                  )}
                            </Box>
                            <ProfileModal
                                user={getSenderFull(user, selectedChat.users)}
                            />
                        </>
                    ) : (
                        <>
                            {selectedChat.chatName.toUpperCase()}
                            <UpdateGroupChatModal
                                fetchMessages={fetchMessages}
                                fetchAgain={fetchAgain}
                                setFetchAgain={setFetchAgain}
                            />
                        </>
                        ))}
                </Text>
                <hr
                    style={{
                        color: "#E0E0E0",
                        backgroundColor: "#E0E0E0",
                        height: 1,
                        width: "100%",
                        border: "none",
                    }}
                />
                <Box
                    display="flex"
                    flexDir="column"
                    justifyContent="flex-end"
                    p={3}
                    w="100%"
                    h="100%"
                    overflowY="hidden"
                >
                  {loading ? (
                    <Spinner
                      size="xl"
                      w={20}
                      h={20}
                      alignSelf="center"
                      margin="auto"
                    />
                  ) : (
                    <div 
                      className="messages"
                      onClick={() => setShowEmojiPicker(false)}
                    >
                        <ScrollableChat messages={messages} />
                    </div>
                  )}
                    
                  <FormControl
                    onKeyDown={sendMessage}
                    id="first-name"
                    isRequired
                    mt={3}
                  >
                      {istyping && room === selectedChat._id ? (
                        <div style={{ position: "absolute", bottom: "2rem", zIndex: "998", left: "2rem" }}>
                          <Lottie
                            options={defaultOptions}
                            // height={50}
                            width={70}
                            style={{ marginBottom: 15, marginLeft: 0 }}
                          />
                        </div>
                      ) : (
                        <></>
                      )}
                      <Box display="flex" alignItems="center" justifyContent="space-between" w="100%" h="100%" position="relative" gap={2}>
                        {showEmojiPicker ? (
                          <Box position="absolute" bottom="60px" roundedLeft="0px" zIndex="999">
                            <EmojiPicker onEmojiClick={(emojiObject) => {
                              setNewMessage(newMessage + emojiObject.emoji);
                            }} />
                          </Box>
                        ) : (
                          <></>
                        )}
                        <i
                          className="far fa-smile"
                          onClick={() => setShowEmojiPicker(!showEmojiPicker)}
                          style={{
                            color: "black",
                            fontSize: "1.5rem",
                            cursor: "pointer",
                          }}
                        ></i>
                        <Input variant="filled" bg="#E0E0E0" placeholder="Enter a message.." value={newMessage} onChange={typingHandler} />
                    </Box>
                  </FormControl>
                </Box>
            </>
        ) : (
            <Box display="flex" alignItems="center" justifyContent="center" h="100%">
                <Text fontSize="3xl" pb={3} fontFamily="Work sans">
                    Click on a user to start chatting
                </Text>
            </Box>
        )}
    </>
  )
}

export default SingleChat