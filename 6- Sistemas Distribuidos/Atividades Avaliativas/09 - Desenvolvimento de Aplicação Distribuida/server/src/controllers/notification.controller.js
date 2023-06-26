import notificationModel from "../models/notification.model.js";
import responseHandler from "../handlers/response.handler.js";
import userModel from "../models/user.model.js";
import chatModel from "../models/chat.model.js";


const allNotifications = async (req, res) => {
    try {
        const notifications = await notificationModel.find({ receiver: req.user._id })
            .populate("sender", "name pic email")
            .populate("receiver", "name pic email")
            .populate("chat")

        return responseHandler.ok(res, notifications);
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}

const sendNotification = async (req, res) => {
    try {
        const { content, receiverId, chatId } = req.body;

        var newNotification = {
            sender: req.user._id,
            receiver: receiverId,
            content,
            chat: chatId
        }

        await notificationModel.create(newNotification);

        return responseHandler.ok(res, "Notificação enviada com sucesso");
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}

const deleteNotifications = async (req, res) => {
    try {
        const { chatId, receiverId } = req.body;

        await notificationModel.deleteMany({ chat: chatId, receiver: receiverId });
        return responseHandler.ok(res, "Notificações excluídas com sucesso");
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}

export default {
    allNotifications,
    sendNotification,
    deleteNotifications
}