import mongoose from 'mongoose';
import modelOptions from './model.options.js';

const messageSchema = new mongoose.Schema(
    {
        sender: {
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

const messageModel = mongoose.model('Message', messageSchema);
export default messageModel;