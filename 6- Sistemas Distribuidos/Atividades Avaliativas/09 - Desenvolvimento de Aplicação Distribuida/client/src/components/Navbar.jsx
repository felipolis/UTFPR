import { Button } from "@chakra-ui/button";
import { useDisclosure } from "@chakra-ui/hooks";
import { Input } from "@chakra-ui/input";
import { Box, Text } from "@chakra-ui/layout";
import {
  Menu,
  MenuButton,
  MenuDivider,
  MenuItem,
  MenuList,
} from "@chakra-ui/menu";
import {
  Drawer,
  DrawerBody,
  DrawerContent,
  DrawerHeader,
  DrawerOverlay,
} from "@chakra-ui/modal";
import { Tooltip } from "@chakra-ui/tooltip";
import { BellIcon, ChevronDownIcon } from "@chakra-ui/icons";
import { Avatar } from "@chakra-ui/avatar";
import { useNavigate } from "react-router-dom";
import { useEffect, useState } from "react";
import axios from "axios";
import { useToast } from "@chakra-ui/toast";
import ChatLoading from "./ChatLoading";
import { Spinner } from "@chakra-ui/spinner";
import ProfileModal from "./ProfileModal";
import NotificationBadge from "react-notification-badge";
import { Effect } from "react-notification-badge";
import { getSender } from "../config/ChatLogics";
import UserListItem from "./UserListItem";
import { ChatState } from "../context/ChatProvider";

import userApi from "../api/modules/user.api"
import chatApi from "../api/modules/chat.api"
import notificationApi from "../api/modules/notification.api";

const Navbar = () => {

	const [search, setSearch] = useState("");
	const [searchResult, setSearchResult] = useState([]);
	const [loading, setLoading] = useState(false);
	const [loadingChat, setLoadingChat] = useState(false);

	const navigate = useNavigate();
	const { isOpen, onOpen, onClose } = useDisclosure();
	const toast = useToast();

	const {
    setSelectedChat,
    user,
    notification,
    setNotification,
    chats,
    setChats,
  } = ChatState();

  useEffect(() => {
    const getAllNotifications = async () => {
      const { response, error } = await notificationApi.fetchNotifications();

      if (response) {
        console.log(response);
        setNotification(response);
      }

      if (error) {
        console.log(error);
      }
    }

    getAllNotifications();
  }, []);

	const logoutHandler = () => {
		localStorage.removeItem("userInfo");
		navigate("/login");
	}

	const handleSearch = async () => {
		if (!search) {
      toast({
        title: "Please Enter something in search",
        status: "warning",
        duration: 5000,
        isClosable: true,
        position: "top-left",
      });
      return;
    }

		setLoading(true);
		const { response, error } = await userApi.getUsers({ search });

		if (response) {
			setLoading(false);
      setSearchResult(response);
		}

		if (error) {
			toast({
        title: "Error Occured!",
        description: "Failed to Load the Search Results",
        status: "error",
        duration: 5000,
        isClosable: true,
        position: "bottom-left",
      });
			setLoading(false);
		}
	}

	const accessChat = async (userId) => {
		setLoadingChat(true);
		const { response, error } = await chatApi.accessChat({userId});

		if (response) {
			if (!chats.find((c) => c._id === response._id)) setChats([response, ...chats]);
      setSelectedChat(response);
      setLoadingChat(false);
      onClose();
		}

		if (error) {
			toast({
        title: "Error fetching the chat",
        description: error.message,
        status: "error",
        duration: 5000,
        isClosable: true,
        position: "bottom-left",
      });
			setLoadingChat(false);
		}
		
	}


  return (
    <>
      <Box
        display="flex"
        justifyContent="space-between"
        alignItems="center"
        bg="#181F2E"
        w="100%"
        p="10px 10px 10px 10px"
        h="8vh"
      >
        <Tooltip label="Search Users to chat" hasArrow placement="bottom-end">
          <Button variant="ghost" onClick={onOpen}>
            <i className="fas fa-search" style={{ color: "white" }}></i>
            <Text display={{ base: "none", md: "flex" }} px={4} color="white">
              Search User
            </Text>
          </Button>
        </Tooltip>

        <Text fontSize="2xl" fontFamily="Work sans" color="white" fontWeight="bold">
          Talk-In-Clouds
        </Text>

        <div>
          <Menu>
            <MenuButton p={1}>
              <NotificationBadge
                count={notification.length}
                effect={Effect.SCALE}
              />
              <BellIcon fontSize="2xl" m={1} color="white" />
            </MenuButton>
            <MenuList pl={2}>
              {!notification.length && "No New Messages"}
              {notification.map((notif) => (
                <MenuItem
                  key={notif._id}
                  onClick={() => {
                    setSelectedChat(notif.chat);
                    setNotification(notification.filter((n) => n.chat._id !== notif.chat._id));
                  }}
                >
                  {notif.chat.isGroupChat
                    ? `New Message in ${notif.chat.chatName}`
                    : `New Message from ${notif.sender.name !== undefined ? notif.sender.name : getSender(user, notif.chat.users)}`}
                </MenuItem>
              ))}
            </MenuList>
          </Menu>

          <Menu>
            <MenuButton as={Button} bg="#181F2E" rightIcon={<ChevronDownIcon />} colorScheme="red">
              <Avatar
                  size="sm"
                  cursor="pointer"
                  name={user.name}
                  src={user.pic}
                />

            </MenuButton>
            <MenuList>
              <ProfileModal user={user}>
                <MenuItem>My Profile</MenuItem>{" "}
              </ProfileModal>
              <MenuDivider />
              <MenuItem onClick={logoutHandler}>Logout</MenuItem>
            </MenuList>
          </Menu>
        </div>
      </Box>

      <Drawer placement="left" onClose={onClose} isOpen={isOpen}>
        <DrawerOverlay />
        <DrawerContent>
          <DrawerHeader borderBottomWidth="1px">Search Users</DrawerHeader>
          <DrawerBody>
            <Box display="flex" pb={2}>
              <Input
                placeholder="Search by name or email"
                mr={2}
                value={search}
                onChange={(e) => setSearch(e.target.value)}
              />
              <Button onClick={handleSearch}>Go</Button>
            </Box>
            {loading ? (
              <ChatLoading />
            ) : (
              searchResult?.map((user) => (
                <UserListItem
                  key={user._id}
                  user={user}
                  handleFunction={() => accessChat(user._id)}
                />
              ))
            )}
            {loadingChat && <Spinner ml="auto" d="flex" />}
          </DrawerBody>
        </DrawerContent>
      </Drawer>
      
    </>
  )
}

export default Navbar