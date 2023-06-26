"""
DESCRIÇÃO:
    - Cliente de filmes
    - Envia requisições para o servidor JS através do protocolo gRPC
    - Requisições:
        - Criar filme
        - Buscar filme
        - Atualizar filme
        - Deletar filme
        - Buscar filme por ator
        - Buscar filme por categoria

AUTOR:
    - Felipe Archanjo da Cunha Mendes

DATA: 06/05/2023
"""
import grpc
import movies_pb2
import movies_pb2_grpc

class MoviesClient:
    def __init__(self, host, port):
        channel = grpc.insecure_channel(f"{host}:{port}")
        self.stub = movies_pb2_grpc.MoviesServiceStub(channel)

    def create_movie(self, body):

        # Cria a requisicao
        request = movies_pb2.CreateMovieRequest(
            plot=body["plot"],
            genres=body["genres"],
            runtime=body["runtime"],
            cast=body["cast"],
            num_mflix_comments=body["num_mflix_comments"],
            title=body["title"],
            fullplot=body["fullplot"],
            countries=body["countries"],
            directors=body["directors"],
            rated=body["rated"],
            awards=movies_pb2.Awards(
                wins=body["awards"]["wins"],
                nominations=body["awards"]["nominations"],
                text=body["awards"]["text"],
            ),
            year=body["year"],
        )

        # Recebe a resposta
        response = self.stub.CreateMovie(request)

        # Exibe a resposta
        if response.status == 200:
            print(f"Movie created with id: {response.id}")
        else:
            print(f"Error: {response.message}")

    def get_movie(self, body):

        # Cria a requisicao
        request = movies_pb2.GetMovieRequest(movie_id=body["movie_id"])

        # Recebe a resposta
        response = self.stub.GetMovie(request)

        # Exibe a resposta
        if response.status == 200:
            print(f"Movie found: {response.movie}")
        elif response.status == 404:
            print(f"Movie not found")
        else:
            print(f"Error: {response.message}")

    
    def update_movie(self, body):
        # Verifica se tem o campo movie_id
        if 'movie_id' not in body:
            print('Missing field: movie_id')
            return
        
        # Verifica se há pelo menos um campo para atualizar
        if len(body) == 1:
            print('Missing fields to update')
            return
        
        # Cria a requisicao
        request = movies_pb2.UpdateMovieRequest(
            movie_id=body["movie_id"],
            plot=body["plot"] if "plot" in body else None,
            genres=body["genres"] if "genres" in body else None,
            runtime=body["runtime"] if "runtime" in body else None,
            cast=body["cast"] if "cast" in body else None,
            num_mflix_comments=body["num_mflix_comments"] if "num_mflix_comments" in body else None,
            title=body["title"] if "title" in body else None,
            fullplot=body["fullplot"] if "fullplot" in body else None,
            countries=body["countries"] if "countries" in body else None,
            directors=body["directors"] if "directors" in body else None,
            rated=body["rated"] if "rated" in body else None,
            awards=movies_pb2.Awards(
                wins=body["awards"]["wins"] if "awards" in body and "wins" in body["awards"] else None,
                nominations=body["awards"]["nominations"] if "awards" in body and "nominations" in body["awards"] else None,
                text=body["awards"]["text"] if "awards" in body and "text" in body["awards"] else None,
            ) if "awards" in body else None,
            year=body["year"] if "year" in body else None,
        )

        # Recebe a resposta
        response = self.stub.UpdateMovie(request)

        # Exibe a resposta
        if response.status == 200:
            print(f"Movie updated with id: {response.id}")
        elif response.status == 404:
            print(f"Movie not found")
        else:
            print(f"Error: {response.message}")

    
    def delete_movie(self, body):

        # Cria a requisicao
        request = movies_pb2.DeleteMovieRequest(movie_id=body["movie_id"])

        # Recebe a resposta
        response = self.stub.DeleteMovie(request)

        # Exibe a resposta
        if response.status == 200:
            print(f"Movie deleted with id: {response.id}")
        elif response.status == 404:
            print(f"Movie not found")
        else:
            print(f"Error: {response.message}")
    
    def get_movie_by_actor(self, body):

        # Cria a requisicao
        request = movies_pb2.GetMovieByActorRequest(actor=body["actor"])

        # Recebe a resposta
        response = self.stub.GetMovieByActor(request)

        # Exibe a resposta
        if response.status == 200:
            print(f"Movies found: {response.movies}")
        elif response.status == 404:
            print(f"Movies not found")
        else:
            print(f"Error: {response.message}")

    
    def get_movie_by_category(self, body):

        # Cria a requisicao
        request = movies_pb2.GetMovieByCategoryRequest(category=body["category"])

        # Recebe a resposta
        response = self.stub.GetMovieByCategory(request)

        # Exibe a resposta
        if response.status == 200:
            print(f"Movies found: {response.movies}")
        elif response.status == 404:
            print(f"Movies not found")
        else:
            print(f"Error: {response.message}")


def main():
    client = MoviesClient("localhost", 50051)


    client.create_movie(
        {
            "plot": "A test movie",
            "genres": ["Action", "Adventure"],
            "runtime": 120,
            "cast": ["John Doe", "Jane Doe"],
            "num_mflix_comments": 0,
            "title": "Test Movie",
            "fullplot": "A test movie",
            "countries": ["USA"],
            "directors": ["John Doe"],
            "rated": "PG-13",
            "awards": {"wins": 3, "nominations": 5, "text": "A test movie"},
            "year": 2020,
        }
    )

    """ client.get_movie(
        {
            "movie_id": "64568121a0278c142b5ffa4f"
        }
    ) """

    """ client.update_movie(
        {
            "movie_id": "64568121a0278c142b5ffa4f",
            "plot": "Nao sei nada sobre isso",
            "genres": ["Action", "Horror"],
        }
    ) """

    """ client.delete_movie(
        {
            "movie_id": "64568121a0278c142b5ffa4f"
        }
    ) """


    """ client.get_movie_by_actor(
        {
            "actor": "John Doe"
        }
    ) """

    """ client.get_movie_by_category(
        {
            "category": "Action"
        }
    ) """


if __name__ == "__main__":
    main()