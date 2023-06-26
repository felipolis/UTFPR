import express from 'express';
import { body } from 'express-validator';
import requestHandler from "../handlers/request.handler.js";
import tokenMiddleware from '../middlewares/token.middleware.js';
import messageController from '../controllers/message.controller.js';


const router = express.Router();

router.get(
    '/:chatId',
    tokenMiddleware.auth,
    requestHandler.validate,
    messageController.allMessages
)


router.post(
    '/',
    tokenMiddleware.auth,
    body('content')
        .exists().withMessage('Content is required')
        .notEmpty().withMessage('Content is required'),
    body('chatId')
        .exists().withMessage('ChatId is required')
        .notEmpty().withMessage('ChatId is required'),

    requestHandler.validate,
    messageController.sendMessage
)








export default router;