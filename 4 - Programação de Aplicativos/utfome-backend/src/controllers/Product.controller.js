const { PrismaClient } = require('@prisma/client');
const prisma = new PrismaClient();
// -------------------- Product Controller --------------------

// C: Create
exports.criarProdutos = async function (req, res){
    const { nome, preco, descricao, quantidade } = req.body;
    const { user_id } = req.params;

    // Verificar se o usuário existe
    const intId = parseInt(user_id);

    const usuario = await prisma.usuario.findUnique({
        where: {
            id: intId
        }
    });

    if(!usuario){
        res.status(400).json({error: 'Usuário não encontrado'});
    }

    // Criar o produto
    const produto = await prisma.produto.create({data: {
        nome,
        preco,
        descricao,
        quantidade,
        usuarioId: intId
    }});
    res.status(201).json(produto);
}

// R: Read
exports.listarProdutos = async function (req, res){
    const produtos = await prisma.produto.findMany();
    res.status(200).json(produtos);
}

exports.listarProdutosDeUmUsuario = async function (req, res){
    const { user_id } = req.params;

    const intId = parseInt(user_id);

    const usuario = await prisma.usuario.findUnique({
        where: {
            id: intId
        }
    });

    if(!usuario){
        res.status(400).json({error: 'Usuário não encontrado'});
    }

    const produtos = await prisma.produto.findMany({
        where: {
            usuarioId: intId
        }
    });

    res.status(200).json(produtos);
}

// U: Update
exports.atualizarProduto = async function (req, res){
    const { id, nome, preco, descricao, quantidade } = req.body;

    if(!id){
        return res.status(400).json({error: "ID não informado"});
    }

    const produtoAlreadyExists = await prisma.produto.findUnique({
        where: {
            id
        }
    });

    if(!produtoAlreadyExists){
        return res.status(400).json({error: "Produto não encontrado"});
    }

    const produto = await prisma.produto.update({
        where: { id },
        data: {
            nome,
            preco,
            descricao,
            quantidade,
        }
    });
    res.status(200).json(produto);
}

// D: Delete
exports.deletarProduto = async function (req, res){
    const { id } = req.params;

    const intId = parseInt(id);
    
    if(!intId){
        return res.status(400).json({error: "ID não informado"});
    }

    const produtoAlreadyExists = await prisma.produto.findUnique({
        where: {
            id: intId
        }
    });

    if(!produtoAlreadyExists){
        return res.status(400).json({error: "Produto não encontrado"});
    }

    const produto = await prisma.produto.delete({
        where: { id: intId }
    });
    res.status(200).json(produto);
}

