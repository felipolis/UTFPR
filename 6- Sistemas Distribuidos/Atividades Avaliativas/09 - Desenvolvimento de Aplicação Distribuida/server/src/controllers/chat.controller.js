import userModel from "../models/user.model.js";
import chatModel from "../models/chat.model.js";
import responseHandler from "../handlers/response.handler.js";


const accessChat = async (req, res) => {
    try {
        // Recebe os dados do body
        const { userId } = req.body;

        // Verifica se já existe um chat entre os usuários
        var isChat = await chatModel.find({
            isGroupChat: false,
            $and: [
                { users: { $elemMatch: { $eq: req.user._id } } },
                { users: { $elemMatch: { $eq: userId } } },
            ]
        })
            .populate("users", "-password")
            .populate("latestMessage");

        isChat = await userModel.populate(isChat, {
            path: "latestMessage.sender",
            select: "name, pic, email"
        });

        // Se já existe um chat, retorna o chat
        if (isChat.length > 0) {
            return responseHandler.ok(res, isChat[0]);
        } else{
            // Se não existe um chat, cria um novo chat
            var chatData = {
                chatName: "sender",
                isGroupChat: false,
                users: [req.user._id, userId],
            }

            try {
                const createdChat = await chatModel.create(chatData);
                const fullChat = await chatModel.findOne({ _id: createdChat._id })
                    .populate("users", "-password")

                return responseHandler.created(res, fullChat);
            } catch (error) {
                console.log(error);
                responseHandler.error(res);
            }
        }

    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
};

const fetchChats = async (req, res) => {
    try {
        // Encontra os chats do usuário
        chatModel.find({ users: { $elemMatch: { $eq: req.user._id } } })
            .populate("users", "-password") // Popula o campo users
            .populate("groupAdmin", "-password") // Popula o campo groupAdmin
            .populate("latestMessage") // Popula o campo latestMessage
            .sort({ updatedAt: -1 }) // Ordena os chats por data de atualização
            .then(async (results) => {
                // Popula o campo sender
                results = await userModel.populate(results, {
                    path: "latestMessage.sender",
                    select: "name, pic, email"
                });

                // Retorna os chats
                return responseHandler.ok(res, results);
            });
            
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
};


const createGroupChat = async (req, res) => {
    try {
        const users = req.body.users;
        users.push(req.user._id);

        // Crar o grupo
        const groupChat = await chatModel.create({
            chatName: req.body.name,
            users: users,
            isGroupChat: true,
            groupAdmin: req.user
        });

        // Busca o grupo criado
        const fullGroupChat = await chatModel.findOne({ _id: groupChat._id })
            .populate("users", "-password")
            .populate("groupAdmin", "-password");

        // Retorna o grupo criado
        return responseHandler.created(res, fullGroupChat);
        
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}


const renameGroup = async (req, res) => {
    try {
        const { chatId, chatName } = req.body;

        // Busca o grupo e atualiza o nome
        const updateChat = await chatModel.findByIdAndUpdate(
            chatId,
            { chatName: chatName },
            { new: true }
        )
            .populate("users", "-password")
            .populate("groupAdmin", "-password");

        if (!updateChat) {
            return responseHandler.notfound(res);
        } else {
            return responseHandler.ok(res, updateChat);
        }
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}


const removeFromGroup = async (req, res) => {
    try {
        const { chatId, userId } = req.body;

        // Verifica se o usuario que está removendo é o admin do grupo
        const isGroupAdmin = await chatModel.find({
            _id: chatId,
            groupAdmin: req.user._id
        });

        if (isGroupAdmin.length == 0) {
            return responseHandler.unauthorize(res);
        }

        // Busca o grupo e remove o usuário
        const removed = await chatModel.findByIdAndUpdate(
            chatId,
            { $pull: { users: userId } },
            { new: true }
        )
            .populate("users", "-password")
            .populate("groupAdmin", "-password");

        return responseHandler.ok(res, removed);
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}

const addToGroup = async (req, res) => {
    try {
        const { chatId, userId } = req.body;

        // Verifica se o usuario que está adicionando é o admin do grupo
        const isGroupAdmin = await chatModel.find({
            _id: chatId,
            groupAdmin: req.user._id
        });
        if (isGroupAdmin.length == 0) {
            return responseHandler.unauthorize(res);
        }

        // Busca o grupo e adiciona o usuário
        const added = await chatModel.findByIdAndUpdate(
            chatId,
            { $push: { users: userId } },
            { new: true }
        )
            .populate("users", "-password")
            .populate("groupAdmin", "-password");

        return responseHandler.ok(res, added);

    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
}





export default {
    accessChat,
    fetchChats,
    createGroupChat,
    renameGroup,
    removeFromGroup,
    addToGroup
}