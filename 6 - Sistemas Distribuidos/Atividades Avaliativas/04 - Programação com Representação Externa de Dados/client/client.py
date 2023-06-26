""" 
DESCRIÇÃO:
    - Cliente para o servidor de filmes
    - Envia requisições para o servidor e recebe as respostas
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

"""
import socket
import struct
from movies_pb2 import CreateMovieRequest
from movies_pb2 import CreateMovieResponse
from movies_pb2 import UpdateMovieRequest
from movies_pb2 import GetMovieRequest
from movies_pb2 import GetMovieResponse
from movies_pb2 import DeleteMovieRequest
from movies_pb2 import DeleteMovieResponse
from movies_pb2 import GetMoviesByActorRequest
from movies_pb2 import GetMoviesByActorResponse
from movies_pb2 import GetMoviesByCategoryRequest
from movies_pb2 import GetMoviesByCategoryResponse

HOST = 'localhost'
PORT = 3000

def createMovie(body):
    # Verifica se tem todos os campos
    fields = ['plot', 'genres', 'runtime', 'cast', 'num_mflix_comments', 'title', 'fullplot', 'countries', 'directors', 'rated', 'awards', 'year']
    for field in fields:
        if field not in body:
            print('Missing field: ' + field)
            return
    
    # Cria o objeto CreateMovieRequest
    request = CreateMovieRequest()
    request.plot = body['plot']
    request.genres.extend(body['genres'])
    request.runtime = body['runtime']
    request.cast.extend(body['cast'])
    request.num_mflix_comments = body['num_mflix_comments']
    request.title = body['title']
    request.fullplot = body['fullplot']
    request.countries.extend(body['countries'])
    request.directors.extend(body['directors'])
    request.rated = body['rated']
    request.awards.wins = body['awards']['wins']
    request.awards.nominations = body['awards']['nominations']
    request.awards.text = body['awards']['text']
    request.year = body['year']

    # Encode the message using protobuf
    request_data = request.SerializeToString()

    # Pack the message type and message length
    type_size = len('CreateMovieRequest')
    request_type = 'CreateMovieRequest'

    # Send the message to the server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(struct.pack('!B', type_size))
        s.sendall(request_type.encode('utf-8'))
        s.sendall(request_data)

        # Receive the response
        response_size = struct.unpack('>I', s.recv(4))[0]
        response_data = s.recv(response_size)

        # Decode the response
        response = CreateMovieResponse()
        response.ParseFromString(response_data)

        if response.status == 200:
            print('Movie created with id: ' + response.id)
        else:
            print('Error creating movie')



def updateMovie(body):
    # Verifica se tem o campo movie_id
    if 'movie_id' not in body:
        print('Missing field: movie_id')
        return
    
    # Verifica se há pelo menos um campo para atualizar
    if len(body) == 1:
        print('Missing fields to update')
        return
    
    # Cria o objeto UpdateMovieRequest e adiciona os campos que foram passados
    request = UpdateMovieRequest()
    request.movie_id = body['movie_id']
    if 'plot' in body:
        request.plot = body['plot']
    if 'genres' in body:
        request.genres.extend(body['genres'])
    if 'runtime' in body:
        request.runtime = body['runtime']
    if 'cast' in body:
        request.cast.extend(body['cast'])
    if 'num_mflix_comments' in body:
        request.num_mflix_comments = body['num_mflix_comments']
    if 'title' in body:
        request.title = body['title']
    if 'fullplot' in body:
        request.fullplot = body['fullplot']
    if 'countries' in body:
        request.countries.extend(body['countries'])
    if 'directors' in body:
        request.directors.extend(body['directors'])
    if 'rated' in body:
        request.rated = body['rated']
    if 'awards' in body:
        request.awards.wins = body['awards']['wins']
        request.awards.nominations = body['awards']['nominations']
        request.awards.text = body['awards']['text']
    if 'year' in body:
        request.year = body['year']

    # Encode the message using protobuf
    request_data = request.SerializeToString()

    # Pack the message type and message length
    type_size = len('UpdateMovieRequest')
    request_type = 'UpdateMovieRequest'

    # Send the message to the server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(struct.pack('!B', type_size))
        s.sendall(request_type.encode('utf-8'))
        s.sendall(request_data)

        # Receive the response
        response_size = struct.unpack('>I', s.recv(4))[0]
        response_data = s.recv(response_size)

        # Decode the response
        response = CreateMovieResponse()
        response.ParseFromString(response_data)

        if response.status == 200:
            print('Movie updated with id: ' + response.id)
        elif response.status == 404:
            print('Movie not found')
        else:
            print('Error updating movie')



def getMovie(body):
    # Verifica se tem o campo movie_id
    if 'movie_id' not in body:
        print('Missing field: movie_id')
        return
    
    # Cria o objeto GetMovieRequest
    request = GetMovieRequest()
    request.movie_id = body['movie_id']

    # Encode the message using protobuf
    request_data = request.SerializeToString()

    # Pack the message type and message length
    type_size = len('GetMovieRequest')
    request_type = 'GetMovieRequest'

    # Send the message to the server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(struct.pack('!B', type_size))
        s.sendall(request_type.encode('utf-8'))
        s.sendall(request_data)

        # Receive the response
        response_size = struct.unpack('>I', s.recv(4))[0]
        response_data = s.recv(response_size)

        # Decode the response
        response = GetMovieResponse()
        response.ParseFromString(response_data)

        if response.status == 200:
            print('--------------- Movie ---------------')
            print(response.movie)
        elif response.status == 404:
            print('Movie not found')

def deleteMovie(body):
    # Verifica se tem o campo movie_id
    if 'movie_id' not in body:
        print('Missing field: movie_id')
        return
    
    # Cria o objeto DeleteMovieRequest
    request = DeleteMovieRequest()
    request.movie_id = body['movie_id']

    # Encode the message using protobuf
    request_data = request.SerializeToString()

    # Pack the message type and message length
    type_size = len('DeleteMovieRequest')
    request_type = 'DeleteMovieRequest'

    # Send the message to the server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(struct.pack('!B', type_size))
        s.sendall(request_type.encode('utf-8'))
        s.sendall(request_data)

        # Receive the response
        response_size = struct.unpack('>I', s.recv(4))[0]
        response_data = s.recv(response_size)

        # Decode the response
        response = DeleteMovieResponse()
        response.ParseFromString(response_data)

        if response.status == 200:
            print('Movie deleted with id: ' + response.id)
        elif response.status == 404:
            print('Movie not found')
        else:
            print('Error deleting movie')


def getMoviesByActor(body):
    # Verifica se tem o campo actor
    if 'actor' not in body:
        print('Missing field: actor')
        return
    
    # Cria o objeto GetMoviesByActorRequest
    request = GetMoviesByActorRequest()
    request.actor = body['actor']

    # Encode the message using protobuf
    request_data = request.SerializeToString()

    # Pack the message type and message length
    type_size = len('GetMoviesByActorRequest')
    request_type = 'GetMoviesByActorRequest'

    # Send the message to the server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(struct.pack('!B', type_size))
        s.sendall(request_type.encode('utf-8'))
        s.sendall(request_data)

        # Receive the response
        response_size = struct.unpack('>I', s.recv(4))[0]

        response_data = s.recv(response_size)

        # Decode the response
        response = GetMoviesByActorResponse()
        response.ParseFromString(response_data)

        if response.status == 200:
            print('--------------- Movies ---------------')
            print(response)
        elif response.status == 404:
            print('Movies not found')
        else:
            print('Error getting movies by actor')


def getMoviesByCategory(body):
    # Verifica se tem o campo category
    if 'category' not in body:
        print('Missing field: category')
        return
    
    # Cria o objeto GetMoviesByCategoryRequest
    request = GetMoviesByCategoryRequest()
    request.category = body['category']

    # Encode the message using protobuf
    request_data = request.SerializeToString()

    # Pack the message type and message length
    type_size = len('GetMoviesByCategoryRequest')
    request_type = 'GetMoviesByCategoryRequest'

    # Send the message to the server
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(struct.pack('!B', type_size))
        s.sendall(request_type.encode('utf-8'))
        s.sendall(request_data)

        # Receive the response
        response_size = struct.unpack('>I', s.recv(4))[0]
        print(response_size)
        response_data = s.recv(response_size)
        #print(len(response_data))

        # Decode the response
        response = GetMoviesByCategoryResponse()
        response.ParseFromString(response_data)

        if response.status == 200:
            print('--------------- Movies ---------------')
            print(response)
        elif response.status == 404:
            print('Movies not found')
        else:
            print('Error getting movies by category')

# ---------------------------- REQUISIÇÃO ----------------------------
""" body = {
    "plot": "plot",
    "genres": ["genres"],
    "runtime": 1,
    "cast": ["cast"],
    "num_mflix_comments": 1,
    "title": "Piratas do Caribe",
    "fullplot": "fullplot",
    "countries": ["countries"],
    "directors": ["directors"],
    "rated": "rated",
    "awards": {
        "wins": 1,
        "nominations": 1,
        "text": "text"
    },
    "year": 1
}
createMovie(body) """

""" body = {
    "movie_id": "644acdc02980625ec6f64528",
    "genres": ["genres", "horror"],
    "cast": ["cast", "cast2"],
}

updateMovie(body) """

""" body = {
    "movie_id": "644acdc02980625ec6f64528"
}

getMovie(body) """

""" body = {
    "movie_id": "6449e7b119c567f34c42cf28"
}

deleteMovie(body) """

""" body = {
    "actor": "joao"
}
getMoviesByActor(body) """


body = {
    "category": "Short"
}
getMoviesByCategory(body)


# --------------------------------------------------------------------