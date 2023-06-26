import mongoose from 'mongoose';
import modelOptions from './model.options.js';

const notificationSchema = new mongoose.Schema(
    {
        sender: { // quem 
            type: mongoose.Schema.Types.ObjectId,
            ref: 'User',
        },
        receiver: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'User',
        },
        content: {
            type: String,
            trim: true,
        },
        chat: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'Chat',
        }
    },
    modelOptions
);

const notificationModel = mongoose.model('Notification', notificationSchema);
export default notificationModel;