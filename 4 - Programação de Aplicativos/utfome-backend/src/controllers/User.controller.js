const { PrismaClient } = require('@prisma/client');
const prisma = new PrismaClient();

const { createPasswordHash } = require('../services/auth');
// -------------------- User Controller --------------------

// C: Create
exports.criarUsuario = async function (req, res){
    try{
        const {nome, sobrenome, email, senha} = req.body;
        
        //verifica se o usuario ja existe
        const usuarioAlreadyExists = await prisma.usuario.findUnique({
            where: {
                email
            }
        });

        if(usuarioAlreadyExists){
            res.status(400).json({error: 'Usuário já existe'});
        } else {

            // Criptografa a senha
            const encryptedPassword = await createPasswordHash(senha);

            const novoUsuario = await prisma.usuario.create({
                data: {
                    nome,
                    sobrenome,
                    email,
                    senha: encryptedPassword
                }
            });
            res.status(201).json(novoUsuario);
        }
    } catch(error){
        console.log(error);
        res.status(400).json({error: error.message});
    }
}

// R: Read
exports.listarUsuarios = async function (req, res){
    try{
        const usuarios = await prisma.usuario.findMany();
        res.status(200).json(usuarios);
    } catch(error){
        console.log(error);
        res.status(400).json({error: error.message});
    }
}

exports.mostrarUsuario = async function (req, res){
    try{
        const {id} = req.params;

        const intId = parseInt(id);

        const usuario = await prisma.usuario.findUnique({
            where: {
                id: intId
            }
        });

        if(!usuario){
            res.status(400).json({error: 'Usuário não encontrado'});
        } else {
            res.status(200).json(usuario);
        }

    } catch(error){
        console.log(error);
        res.status(400).json({error: error.message});
    }
}

// U: Update
exports.atualizarUsuario = async function (req, res){
    try{
        const {id} = req.params;
        const {nome, sobrenome, email, senha} = req.body;

        const intId = parseInt(id);

        const usuario = await prisma.usuario.findUnique({
            where: {
                id: intId
            }
        });

        if(!usuario){
            res.status(400).json({error: 'Usuário não encontrado'});
        } else {
            const encryptedPassword = await createPasswordHash(senha);

            const novoUsuario = await prisma.usuario.update({
                where: { id: intId },
                data: {
                    nome,
                    sobrenome,
                    email,
                    senha: encryptedPassword
                }
            });
            res.status(200).json(novoUsuario);
        }

    } catch(error){
        console.log(error);
        res.status(400).json({error: error.message});
    }
}

// D: Delete
exports.deletarUsuario = async function (req, res){
    try{
        const {id} = req.params;

        const intId = parseInt(id);

        const usuario = await prisma.usuario.findUnique({
            where: {
                id: intId
            }
        });

        if(!usuario){
            res.status(400).json({error: 'Usuário não encontrado'});
        } else {
            const usuarioDeletado = await prisma.usuario.delete({
                where: { id: intId }
            });
            res.status(200).json(usuarioDeletado);
        }

    } catch(error){
        console.log(error);
        res.status(400).json({error: error.message});
    }
}
