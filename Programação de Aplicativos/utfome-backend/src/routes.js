var express = require('express');
var router = express.Router();

const { jwt } = require('jsonwebtoken');

// Modulos necessarios
const helloController = require('./controllers/Hello.controller');
const productController = require('./controllers/Product.controller');
const userController = require('./controllers/User.controller');
const authController = require('./middlewares/auth');
const sessionController = require('./controllers/Sessao.controller');


//              Controller publico
// #################### HELLO ####################
router.get('/hello', helloController.hello);

// #################### AUTH ####################
router.post('/usuarios', userController.criarUsuario);
router.post('/sessoes', sessionController.criarSessao);
router.use(authController.autenticar);



//              Controllers privados
// #################### USER ####################
router.get('/usuarios', userController.listarUsuarios);
router.get('/usuarios/:id', userController.mostrarUsuario);
router.put('/usuarios/:id', userController.atualizarUsuario);
router.delete('/usuarios/:id', userController.deletarUsuario);

// #################### PRODUCT ####################
router.post('/produtos/:user_id', productController.criarProdutos);
router.get('/produtos', productController.listarProdutos);
router.get('/produtos/:user_id', productController.listarProdutosDeUmUsuario)
router.put('/produtos', productController.atualizarProduto);
router.delete('/produtos/:id', productController.deletarProduto);




module.exports = router;