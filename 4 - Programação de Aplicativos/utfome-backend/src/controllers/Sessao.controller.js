const jwt = require('jsonwebtoken');
const { checkPassword } = require('../services/auth');

const authConfig = require('../config/auth');

const { PrismaClient } = require('@prisma/client');
const prisma = new PrismaClient();

exports.criarSessao = async function(req, res) {
    try{
        const { email, senha } = req.body;

        const usuario = await prisma.usuario.findUnique({
            where: {
                email
            }
        });

        if (!usuario) {
            res.status(401).json({ error: 'Usuário invalido' });
        }

        if (! checkPassword(usuario, senha)) {
            res.status(401).json({ error: 'Senha invalida' });
        }

        const { id } = usuario;
        const token = jwt.sign({ id }, authConfig.secret, {
            expiresIn: authConfig.expiresIn
        });

        res.json({
            usuario: {
                id,
                email
            },
            token
        });

    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}