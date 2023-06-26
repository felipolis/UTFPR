import userModel from "../models/user.model.js";
import jsonwebtoken from "jsonwebtoken";
import responseHandler from "../handlers/response.handler.js";

const signup = async (req, res) => {
    try {
        // Recebe os dados do body
        const {
            name,
            email,
            password,
            pic
        } = req.body;

        // Verifica se o usuário já existe
        const checkUser =  await userModel.findOne({ email });
        if (checkUser) {
            return responseHandler.badrequest(res, 'Email já cadastrado');
        }

        // Cria um novo usuário
        const user = new userModel();

        user.name = name;
        user.email = email;
        user.pic = pic;
        user.setPassword(password);

        await user.save();

        // Gera o token
        const token = jsonwebtoken.sign(
            { data: user._id },
            process.env.TOKEN_SECRET_KEY,
            { expiresIn: "24h" }
        );

        // Busca o usuario no banco de dados
        const userNew = await userModel.findOne({ email }).select("pic");

        // Retorna o usuário e o token
        return responseHandler.created(res, {
            _id: user._id,
            name: user.name,
            email: user.email,
            pic: userNew.pic,
            token
        });

    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
};

const signin = async (req, res) => {
    try {
        // Recebe os dados do body
        const {
            email,
            password
        } = req.body;

        // Verifica se o usuário existe
        const user = await userModel.findOne({ email }).select("password id salt name email pic");

        if (!user) {
            return responseHandler.badrequest(res, 'Usuário não encontrado');
        }

        // Verifica se a senha está correta
        if (!user.validPassword(password)) {
            return responseHandler.badrequest(res, 'Senha incorreta');
        }

        // Gera o token
        const token = jsonwebtoken.sign(
            { data: user._id },
            process.env.TOKEN_SECRET_KEY,
            { expiresIn: "24h" }
        )

        // Retorna o usuário e o token
        return responseHandler.ok(res, {
            _id: user._id,
            name: user.name,
            email: user.email,
            pic: user.pic,
            token
        });


    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
};

const allUsers = async (req, res) => {
    try {
        const keyword = req.query.search ? {
            $or: [
                { name: { $regex: req.query.search, $options: 'i' } },
                { email: { $regex: req.query.search, $options: 'i' } }
            ]
        } : {}
    
        const users = await userModel
            .find(keyword)
            .find({ _id: { $ne: req.user._id } })
    
        return responseHandler.ok(res, users);
    } catch (error) {
        console.log(error);
        responseHandler.error(res);
    }
};

export default {
    signup,
    signin,
    allUsers
}