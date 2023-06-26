import mongoose from 'mongoose';
import modelOptions from './model.options.js';

const chatSchema = new mongoose.Schema(
    {
        chatName: {
            type: String,
            trim: true,
        },
        isGroupChat: {
            type: Boolean,
            default: false,
        },
        users: [{
            type: mongoose.Schema.Types.ObjectId,
            ref: 'User',
        }],
        latestMessage: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'Message',
        },
        groupAdmin: {
            type: mongoose.Schema.Types.ObjectId,
            ref: 'User',
        }
    },
    modelOptions
);

const chatModel = mongoose.model('Chat', chatSchema);
export default chatModel;