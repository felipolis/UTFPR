import { Avatar } from "@chakra-ui/avatar";
import { Tooltip } from "@chakra-ui/tooltip";
import ScrollableFeed from "react-scrollable-feed";
import {
  isLastMessage,
  isSameSender,
  isSameSenderMargin,
  isSameUser,
} from "../config/ChatLogics";
import { ChatState } from "../context/ChatProvider";

const ScrollableChat = ({ messages }) => {
  const { user } = ChatState();
  //console.log(messages)

  return (
    <ScrollableFeed>
            {messages &&
                messages.map((m, i) => (
                <div style={{ display: "flex" }} key={m._id}>
                    {(isSameSender(messages, m, i, user._id) ||
                    isLastMessage(messages, i, user._id)) && (
                    <Tooltip label={m.sender.name} placement="bottom-start" hasArrow>
                        <Avatar
                        mt="7px"
                        mr={1}
                        size="sm"
                        cursor="pointer"
                        name={m.sender.name}
                        src={m.sender.pic}
                        />
                    </Tooltip>
                    )}
                    <span
                    style={{
                        backgroundColor: `${
                        m.sender._id === user._id ? "#FC4F4F" : "#EBF4FB"
                        }`,
                        color: `${
                        m.sender._id === user._id ? "#fff" : "#000"
                        }`,
                        marginLeft: isSameSenderMargin(messages, m, i, user._id),
                        marginTop: isSameUser(messages, m, i, user._id) ? 3 : 10,
                        borderRadius: "20px",
                        padding: "10px 20px",
                        maxWidth: "75%",
                    }}
                    >
                    {m.content}
                    </span>
                </div>
                ))}
        </ScrollableFeed>
  )
}

export default ScrollableChat