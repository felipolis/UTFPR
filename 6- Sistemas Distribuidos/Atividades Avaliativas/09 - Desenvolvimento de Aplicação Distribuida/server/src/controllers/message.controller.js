import messageModel from "../models/message.model.js";
import responseHandler from "../handlers/response.handler.js";
import userModel from "../models/user.model.js";
import chatModel from "../models/chat.model.js";

const allMessages = async (req, res) => {
    try {
        // Encontra as mensagens do chat
        const messages = await messageModel.find({ chat: req.params.chatId })
            .populate("sender", "name pic email")
            .populate("chat")

        // Retorna as mensagens
        return responseHandler.ok(res, messages);

    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}



const sendMessage = async (req, res) => {
    try {
        const { content, chatId } = req.body;
        
        // Cria a mensagem
        var newMessage = {
            sender: req.user._id,
            content,
            chat: chatId
        }

        // Salva a mensagem
        var message = await messageModel.create(newMessage);

        message = await message.populate("sender", "name, pic")
        message = await message.populate("chat")
        message = await userModel.populate(message, { 
            path: "chat.users",
            select: "name pic email"
        })

        // atualiza a ultima mensagem do chat
        await chatModel.findByIdAndUpdate(req.body.chatId, { latestMessage: message });

        // Retorna a mensagem
        return responseHandler.ok(res, message);


    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}











export default {
    allMessages,
    sendMessage
}