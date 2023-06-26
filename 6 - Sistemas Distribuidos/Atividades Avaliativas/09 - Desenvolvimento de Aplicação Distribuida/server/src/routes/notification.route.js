import express from 'express';
import { body } from 'express-validator';
import requestHandler from "../handlers/request.handler.js";
import tokenMiddleware from '../middlewares/token.middleware.js';
import notificationController from '../controllers/notification.controller.js';

const router = express.Router();

router.get(
    '/',
    tokenMiddleware.auth,
    requestHandler.validate,
    notificationController.allNotifications
)

router.post(
    '/',
    tokenMiddleware.auth,
    body('content')
        .exists().withMessage('Content is required')
        .notEmpty().withMessage('Content is required'),
    body('receiverId')
        .exists().withMessage('SenderId is required')
        .notEmpty().withMessage('SenderId is required'),
    body('chatId')
        .exists().withMessage('ChatId is required')
        .notEmpty().withMessage('ChatId is required'),

    requestHandler.validate,
    notificationController.sendNotification
)

router.delete(
    '/',
    tokenMiddleware.auth,
    body('chatId')
        .exists().withMessage('ChatId is required')
        .notEmpty().withMessage('ChatId is required'),

    body('receiverId')
        .exists().withMessage('ReceiverId is required')
        .notEmpty().withMessage('ReceiverId is required'),


    requestHandler.validate,
    notificationController.deleteNotifications
)

export default router;