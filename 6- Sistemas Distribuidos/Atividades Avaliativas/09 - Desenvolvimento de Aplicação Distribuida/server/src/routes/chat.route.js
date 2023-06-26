import express from 'express';
import { body } from 'express-validator';
import requestHandler from "../handlers/request.handler.js";
import tokenMiddleware from '../middlewares/token.middleware.js';
import chatController from '../controllers/chat.controller.js';

const router = express.Router();


router.post(
    '/',
    tokenMiddleware.auth,
    body('userId')
        .exists().withMessage('userId é obrigatório'),
        
    requestHandler.validate,
    chatController.accessChat

)


router.get(
    '/',
    tokenMiddleware.auth,
    requestHandler.validate,
    chatController.fetchChats
)


router.post(
    '/group',
    tokenMiddleware.auth,
    body('users')
        .exists().withMessage('users é obrigatório')
        .custom((value, { req }) => {
            // verifica se o array tem mais de 2 elementos
            if (value.length < 2) {
                throw new Error('users deve ter pelo menos 2 elementos');
            }
            return true;
        }),
        
    body('name')
        .exists().withMessage('name é obrigatório'),
    requestHandler.validate,
    chatController.createGroupChat
)

router.put(
    '/rename',
    tokenMiddleware.auth,
    body('chatId')
        .exists().withMessage('chatId é obrigatório'),

    body('chatName')
        .exists().withMessage('chatName é obrigatório'),
    requestHandler.validate,
    chatController.renameGroup
)

router.put(
    '/groupremove',
    tokenMiddleware.auth,
    body('chatId')
        .exists().withMessage('chatId é obrigatório'),

    body('userId')
        .exists().withMessage('userId é obrigatório'),

    requestHandler.validate,
    chatController.removeFromGroup
)



router.put(
    '/groupadd',
    tokenMiddleware.auth,
    body('chatId')
        .exists().withMessage('chatId é obrigatório'),

    body('userId')
        .exists().withMessage('userId é obrigatório'),

    requestHandler.validate,
    chatController.addToGroup
)



export default router;