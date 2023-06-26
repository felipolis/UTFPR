/* 
DESCRIÇÃO:
    - Servidor de filmes
    - Recebe requisições protobuf do cliente e as processa
    - Requisições:
        - CreateMovieRequest(body)
            - body: {
                "plot": "A test plot",
                "genres": ["Action", "Adventure"],
                "runtime": 120,
                "cast": ["Felipe", "João"],
                "num_mflix_comments": 10,
                "title": "A test title",
                "fullplot": "A test fullplot",
                "countries": ["Brazil", "USA"],
                "directors": ["Felipe", "João"],
                "rated": "PG-13",
                "awards": {
                    "wins": 10,
                    "nominations": 20,
                    "text": "A test text"
                },
                "year": 2021
            }
        - UpdateMovieRequest(body)
            - body: {
                "movie_id": "60a1b0d9e6d9a9b3f0f1b3a1",
                "plot": "A test plot",
                ...
            }
        - GetMovieRequest(body)
            - body: {
                "movie_id": "60a1b0d9e6d9a9b3f0f1b3a1"
            }
        - DeleteMovieRequest(body)
            - body: {
                "movie_id": "60a1b0d9e6d9a9b3f0f1b3a1"
            }
        - GetMoviesByActorRequest(body)
            - body: {
                "actor": "Felipe"
            }
        - GetMoviesByCategoryRequest(body)
            - body: {
                "category": "Action"
            }
    - Respostas:
        - CreateMovieResponse
            - response: {
                "status": 200,
                "id": "60a1b0d9e6d9a9b3f0f1b3a1"
            }
        - UpdateMovieResponse
            - response: {
                "status": 200,
                "id": "60a1b0d9e6d9a9b3f0f1b3a1"
            }
        - GetMovieResponse
            - response: {
                "status": 200,
                "movie": {
                    "plot": "A test plot",
                    "genres": ["Action", "Adventure"],
                    ...
                }
            }
        - DeleteMovieResponse
            - response: {
                "status": 200,
                "id": "60a1b0d9e6d9a9b3f0f1b3a1"
            }
        - GetMoviesByActorResponse
            - response: {
                "status": 200,
                "movies": [
                    ...
                ]
            }
        - GetMoviesByCategoryResponse
            - response: {
                "status": 200,
                "movies": [
                    ...
                ]
            }

AUTOR:
    - Felipe Archanjo da Cunha Mendes

DATA: 
    - 27/04/2023
*/


import mongoose from 'mongoose';
import protobuf from 'protobufjs';
import net from 'net';
import "dotenv/config";
import movieController from './controllers/movie.controller.js';



// Carrega o arquivo protobuf
protobuf.load('../movies.proto', function (err, root) {
    if (err) throw err;

    // Obtém as mensagens protobuf que foram definidas no arquivo
    const CreateMovieRequest = root.lookupType('CreateMovieRequest');
    const CreateMovieResponse = root.lookupType('CreateMovieResponse');

    const UpdateMovieRequest = root.lookupType('UpdateMovieRequest');
    const UpdateMovieResponse = root.lookupType('UpdateMovieResponse');

    const GetMovieRequest = root.lookupType('GetMovieRequest');
    const GetMovieResponse = root.lookupType('GetMovieResponse');

    const DeleteMovieRequest = root.lookupType('DeleteMovieRequest');
    const DeleteMovieResponse = root.lookupType('DeleteMovieResponse');

    const GetMoviesByActorRequest = root.lookupType('GetMoviesByActorRequest');
    const GetMoviesByActorResponse = root.lookupType('GetMoviesByActorResponse');

    const GetMoviesByCategoryRequest = root.lookupType('GetMoviesByCategoryRequest');
    const GetMoviesByCategoryResponse = root.lookupType('GetMoviesByCategoryResponse');

    // Cria um servidor TCP para receber mensagens protobuf
    const server = net.createServer(function (socket) {
        console.log('Conexão estabelecida');

        // Recebe os dados do cliente e analisa a mensagem protobuf
        socket.on('data', function (data) {
            try {
                // Le o primeiro byte
                const type_size = data.readUInt8(0);

                // Le os proximos type_size bytes
                const type = data.toString('utf8', 1, type_size + 1);

                // Le o restante dos bytes
                const req = root.lookupType(`${type}`).decode(data.slice(type_size + 1));
                //console.log(req);

                // Verifica o tipo de requisição

                if (type == 'CreateMovieRequest') {
                  console.log('Criando filme...');
                  movieController.createMovie(req, socket, CreateMovieResponse);

                } else if (type == 'UpdateMovieRequest') {
                  console.log('Atualizando filme...');
                  movieController.updateMovie(req, socket, UpdateMovieResponse);

                } else if (type == 'GetMovieRequest') {
                  console.log('Obtendo filme...');
                  movieController.getMovie(req, socket, GetMovieResponse);

                } else if (type == 'DeleteMovieRequest') {
                  console.log('Deletando filme...');
                  movieController.deleteMovie(req, socket, DeleteMovieResponse);

                } else if (type == 'GetMoviesByActorRequest') {
                  console.log('Obtendo filmes por ator...');
                  movieController.getMoviesByActor(req, socket, GetMoviesByActorResponse);

                } else if (type == 'GetMoviesByCategoryRequest') {
                  console.log('Obtendo filmes por categoria...');
                  movieController.getMoviesByCategory(req, socket, GetMoviesByCategoryResponse);

                } else {
                    console.log('Tipo de requisição inválido');
                }

            } catch (err) {
                console.error(err);
            }
        });

        // Fecha a conexão quando o cliente desconecta
        socket.on('end', function () {
            console.log('Conexão encerrada');
        });
    });

    mongoose.set('strictQuery', false);
    mongoose.connect(process.env.MONGODB_URL).then(() => {
        console.log('Connected to MongoDB');
        // Inicia o servidor TCP
        server.listen(3000, function () {
            console.log('Servidor iniciado na porta 3000');
        });
    }).catch((error) => {
        console.log(error);
        process.exit(1);
    });


});
