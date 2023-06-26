import express from "express";
import userRoute from "./user.route.js";
import chatRoute from "./chat.route.js";
import messageRoute from "./message.route.js";
import notificationRoute from "./notification.route.js";

const router = express.Router();

router.use('/user', userRoute);
router.use('/chat', chatRoute);
router.use('/message', messageRoute);
router.use('/notification', notificationRoute);



export default router;