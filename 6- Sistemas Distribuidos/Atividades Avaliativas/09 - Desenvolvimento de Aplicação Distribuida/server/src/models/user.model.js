import mongoose from 'mongoose';
import modelOptions from './model.options.js';
import crypto from 'crypto';

const userSchema = new mongoose.Schema(
    {
        name: {
            type: String,
            required: true
        },
        email: {
            type: String,
            lowercase: true,
            unique: true,
            required: true
        },
        pic: {
            type: String,
            default: "https://icon-library.com/images/anonymous-avatar-icon/anonymous-avatar-icon-25.jpg"
        },
        isAdmin: {
            type: Boolean,
            required: true,
            default: false
        },
        password: {
            type: String,
            required: true,
            select: false
        },
        salt: {
            type: String,
            required: true,
            select: false
        },
    },
    modelOptions
)

userSchema.methods.setPassword = function (password) {
    // Gera uma string aleatória de 16 bytes
    this.salt = crypto.randomBytes(16).toString('hex');

    // Gera um hash com a senha e a string aleatória
    this.password = crypto.pbkdf2Sync(password, this.salt, 1000, 64, `sha512`).toString(`hex`);
}

userSchema.methods.validPassword = function (password) {
    // Gera um hash com a senha e a string aleatória
    const hash = crypto.pbkdf2Sync(password, this.salt, 1000, 64, `sha512`).toString(`hex`);

    // Verifica se o hash gerado é igual ao hash armazenado
    return this.password === hash;
}

const userModel = mongoose.model('User', userSchema);
export default userModel;