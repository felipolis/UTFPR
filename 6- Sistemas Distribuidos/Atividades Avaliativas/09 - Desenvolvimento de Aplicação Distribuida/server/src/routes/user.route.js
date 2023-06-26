import express from 'express';
import { body } from 'express-validator';
import userController from '../controllers/user.controller.js';
import requestHandler from "../handlers/request.handler.js";
import userModel from '../models/user.model.js';
import tokenMiddleware from '../middlewares/token.middleware.js';

const router = express.Router();



router.post(
    '/signup',
    body('email')
        .exists().withMessage('Email é obrigatório')
        .custom(async (value) => {
            const email = await userModel.findOne({ email: value });
            if (email) {
                return Promise.reject('Email já cadastrado');
            }
        }),

    body('name')
        .exists().withMessage('Nome é obrigatório')
        .isLength({ min: 3 }).withMessage('Nome deve ter no mínimo 3 caracteres'),

    body('password')
        .exists().withMessage('Senha é obrigatória')
        .isLength({ min: 8 }).withMessage('Senha deve ter no mínimo 8 caracteres'),
    
    body('confirmPassword')
        .exists().withMessage('Confirmação de senha é obrigatória')
        .isLength({ min: 8 }).withMessage('Confirmação de senha deve ter no mínimo 8 caracteres')
        .custom((value, { req }) => {
            if (value !== req.body.password) {
                throw new Error('Confirmação de senha não confere');
            }
            return true;
        }),

    requestHandler.validate,
    userController.signup
);

router.post(
    '/signin',
    body('email')
        .exists().withMessage('Email é obrigatório'),

    body('password')
        .exists().withMessage('Senha é obrigatória')
        .isLength({ min: 8 }).withMessage('Senha deve ter no mínimo 8 caracteres'),

    requestHandler.validate,
    userController.signin
    )
    
    
router.get(
    '/',
    tokenMiddleware.auth,
    requestHandler.validate,
    userController.allUsers
)






export default router;