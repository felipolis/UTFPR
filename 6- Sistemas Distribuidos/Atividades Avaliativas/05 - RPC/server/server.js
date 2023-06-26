/* 
DESCRIÇÃO:
    - Servidor de filmes
    - Recebe requisições do cliente atraves do protocolo gRPC
    - Conecta ao banco de dados MongoDB
    - Realiza as operações CRUD no banco de dados
    - Retorna respostas ao cliente atraves do protocolo gRPC

AUTOR:
    - Felipe Archanjo da Cunha Mendes

DATA: 06/05/2023
*/


import * as grpc from '@grpc/grpc-js';
import * as protoLoader from '@grpc/proto-loader';
import mongoose from 'mongoose';
import "dotenv/config";
import movieController from './controllers/movie.controller.js';

// ----------------- Proto Config -----------------
var PROTO_PATH = '../proto/movies.proto';
var packageDefinition = protoLoader.loadSync(
    PROTO_PATH,
    {
        keepCase: true,
        longs: String,
        enums: String,
        defaults: true,
        oneofs: true
    });
var movies_proto = grpc.loadPackageDefinition(packageDefinition).movies;

// ----------------- Functions -----------------
const createMovie = async (call, callback) => {
    console.log('Adicionando filme...');
    await movieController.createMovie(call.request, callback);
};

const getMovie = async (call, callback) => {
    console.log('Buscando filme...');
    await movieController.getMovie(call.request, callback);
};

const updateMovie = async (call, callback) => {
    console.log('Atualizando filme...');
    await movieController.updateMovie(call.request, callback);
};

const deleteMovie = async (call, callback) => {
    console.log('Deletando filme...');
    await movieController.deleteMovie(call.request, callback);
};

const getMovieByActor = async (call, callback) => {
    console.log('Buscando filme por ator...');
    await movieController.getMovieByActor(call.request, callback);
};

const getMovieByCategory = async (call, callback) => {
    console.log('Buscando filme por categoria...');
    await movieController.getMovieByCategory(call.request, callback);
};


function main() {
    var server = new grpc.Server();
    server.addService(movies_proto.MoviesService.service, {
        CreateMovie: createMovie,
        GetMovie: getMovie,
        UpdateMovie: updateMovie,
        DeleteMovie: deleteMovie,
        GetMovieByActor: getMovieByActor,
        GetMovieByCategory: getMovieByCategory
    });

    // Inicia o servidor
    server.bindAsync('localhost:50051', grpc.ServerCredentials.createInsecure(), () => {
        server.start();
        console.log("Server running at http://localhost:50051");
    })

    // Conecta ao MongoDB
    mongoose.connect(process.env.MONGODB_URL, {
        useNewUrlParser: true,
        useUnifiedTopology: true
    }).then(() => {
        console.log("MongoDB connected");
    })
}


main();
