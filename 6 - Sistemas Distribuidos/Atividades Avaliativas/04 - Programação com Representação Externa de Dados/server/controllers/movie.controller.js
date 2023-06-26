import movieModel from '../models/movie.model.js';

const createMovie = async (req, socket, CreateMovieResponse) => {
    try {
        const plot = req.plot;
        const genres = req.genres;
        const runtime = req.runtime;
        const cast = req.cast;
        const num_mflix_comments = req.numMflixComments;
        const title = req.title;
        const fullplot = req.fullplot;
        const countries = req.countries;
        const directors = req.directors;
        const rated = req.rated;
        const awards = req.awards;
        const year = req.year;

        const movie = new movieModel({
            plot,
            genres,
            runtime,
            cast,
            num_mflix_comments,
            title,
            fullplot,
            countries,
            directors,
            rated,
            awards,
            year
        });

        const createdMovie = await movie.save();

        // Cria a response
        const response = CreateMovieResponse.create({
            status: 200,
            id: createdMovie._id.toString()
        });
        
        // Serializa a mensagem protobuf em string
        const buffer = CreateMovieResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);


    } catch (error) {
        console.log(error)

        // Cria a response
        const response = CreateMovieResponse.create({
            status: 500,
            id: ''
        });

        // Serializa a mensagem protobuf em string
        const buffer = CreateMovieResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);
    }
};


const updateMovie = async (req, socket, UpdateMovieResponse) => {
    try {
        const movie_id = req.movieId;
        const plot = req.plot ? req.plot : null;
        const genres = req.genres ? req.genres : null;
        const runtime = req.runtime ? req.runtime : null;
        const cast = req.cast ? req.cast : null;
        const num_mflix_comments = req.numMflixComments ? req.numMflixComments : null;
        const title = req.title ? req.title : null;
        const fullplot = req.fullplot ? req.fullplot : null;
        const countries = req.countries ? req.countries : null;
        const directors = req.directors ? req.directors : null;
        const rated = req.rated ? req.rated : null;
        const awards = req.awards ? req.awards : null;
        const year = req.year ? req.year : null;

        const movie = await movieModel.findByIdAndUpdate(movie_id, {
            ...(plot && { plot }),
            ...(genres && { genres }),
            ...(runtime && { runtime }),
            ...(cast && { cast }),
            ...(num_mflix_comments && { num_mflix_comments }),
            ...(title && { title }),
            ...(fullplot && { fullplot }),
            ...(countries && { countries }),
            ...(directors && { directors }),
            ...(rated && { rated }),
            ...(awards && { awards }),
            ...(year && { year })

        }, {
            new: true
        });

        // Verifica se o filme existe
        if (!movie) {
            // Cria a response
            const response = UpdateMovieResponse.create({
                status: 404,
                id: ''
            });

            // Serializa a mensagem protobuf em string
            const buffer = UpdateMovieResponse.encode(response).finish();

            // Define o tamanho da mensagem
            const size = Buffer.byteLength(buffer);

            // envia o tamanho da mensagem em 4 bytes por socket
            socket.write(Buffer.alloc(4, size));

            // envia a mensagem
            socket.write(buffer);

            return;
        }

        // Cria a response
        const response = UpdateMovieResponse.create({
            status: 200,
            id: movie._id.toString()
        });

        // Serializa a mensagem protobuf em string
        const buffer = UpdateMovieResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);
        
        
    } catch (error) {
        console.log(error)
        // Cria a response
        const response = UpdateMovieResponse.create({
            status: 500,
            id: movie._id.toString()
        });
    
        // Serializa a mensagem protobuf em string
        const buffer = UpdateMovieResponse.encode(response).finish();
    
        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);
    
        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));
    
        // envia a mensagem
        socket.write(buffer);
    }
};


const getMovie = async (req, socket, GetMovieResponse) => {
    try {
        const movie_id = req.movieId;

        const movie = await movieModel.findById(movie_id);

        // Verifica se o filme existe
        if (!movie) {
            // Cria a response
            const response = GetMovieResponse.create({
                status: 404,
                movie: null
            });

            // Serializa a mensagem protobuf em string
            const buffer = GetMovieResponse.encode(response).finish();

            // Define o tamanho da mensagem
            const size = Buffer.byteLength(buffer);

            // envia o tamanho da mensagem em 4 bytes por socket
            socket.write(Buffer.alloc(4, size));

            // envia a mensagem
            socket.write(buffer);

            return;
        }

        // Cria a response
        const response = GetMovieResponse.create({
            status: 200,
            movie: {
                id: movie._id.toString(),
                plot: movie.plot,
                genres: movie.genres,
                runtime: movie.runtime,
                cast: movie.cast,
                numMflixComments: movie.num_mflix_comments,
                title: movie.title,
                fullplot: movie.fullplot,
                countries: movie.countries,
                directors: movie.directors,
                rated: movie.rated,
                awards: movie.awards,
                year: movie.year
            }
        });

        console.log(response.movie.cast)

        // Serializa a mensagem protobuf em string
        const buffer = GetMovieResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);

    } catch (error) {
        console.log(error)
        // Cria a response
        const response = GetMovieResponse.create({
            status: 500,
            movie: {
                id: '',
                plot: '',
                genres: [],
                runtime: 0,
                cast: [],
                numMflixComments: 0,
                title: '',
                fullplot: '',
                countries: [],
                directors: [],
                rated: '',
                awards: '',
                year: 0
            }
        });

        // Serializa a mensagem protobuf em string
        const buffer = GetMovieResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);
    }
};


const deleteMovie = async (req, socket, DeleteMovieResponse) => {
    try {
        const movie_id = req.movieId;

        const movie = await movieModel.findByIdAndDelete(movie_id);

        // Verifica se o filme existe
        if (!movie) {
            // Cria a response
            const response = DeleteMovieResponse.create({
                status: 404,
                id: ''
            });

            // Serializa a mensagem protobuf em string
            const buffer = DeleteMovieResponse.encode(response).finish();

            // Define o tamanho da mensagem
            const size = Buffer.byteLength(buffer);

            // envia o tamanho da mensagem em 4 bytes por socket
            socket.write(Buffer.alloc(4, size));

            // envia a mensagem
            socket.write(buffer);

            return;
        }

        // Cria a response
        const response = DeleteMovieResponse.create({
            status: 200,
            id: movie._id.toString()
        });

        // Serializa a mensagem protobuf em string
        const buffer = DeleteMovieResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);
    } catch (error) {
        console.log(error)
        // Cria a response
        const response = DeleteMovieResponse.create({
            status: 404,
            id: ''
        });

        // Serializa a mensagem protobuf em string
        const buffer = DeleteMovieResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);
    }
}


const getMoviesByActor = async (req, socket, GetMoviesByActorResponse) => {
    try{
        const actor = req.actor;

        const movies = await movieModel.find({ cast: { $in: [actor] } });

        // Verifica se o filme existe
        if (!movies.length) {
            // Cria a response
            const response = GetMoviesByActorResponse.create({
                status: 404,
                movies: []
            });

            // Serializa a mensagem protobuf em string
            const buffer = GetMoviesByActorResponse.encode(response).finish();

            // Define o tamanho da mensagem
            const size = Buffer.byteLength(buffer);

            // envia o tamanho da mensagem em 4 bytes por socket
            socket.write(Buffer.alloc(4, size));

            // envia a mensagem
            socket.write(buffer);

            return;
        }

        // Cria a response
        const response = GetMoviesByActorResponse.create({
            status: 200,
            movies: movies.map(movie => {
                return {
                    id: movie._id.toString(),
                    plot: movie.plot,
                    genres: movie.genres,
                    runtime: movie.runtime,
                    cast: movie.cast,
                    numMflixComments: movie.num_mflix_comments,
                    title: movie.title,
                    fullplot: movie.fullplot,
                    countries: movie.countries,
                    directors: movie.directors,
                    rated: movie.rated,
                    awards: movie.awards,
                    year: movie.year
                }
            })
        });

        // Serializa a mensagem protobuf em string
        const buffer = GetMoviesByActorResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));
        // envia a mensagem
        socket.write(buffer);
    } catch (error) {
        console.log(error)
        // Cria a response
        const response = GetMoviesByActorResponse.create({
            status: 500,
            movies: []
        });

        // Serializa a mensagem protobuf em string
        const buffer = GetMoviesByActorResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);

    }
}


const getMoviesByCategory = async (req, socket, GetMoviesByCategoryResponse) => {
    try {
        const category = req.category;

        const movies = await movieModel.find({ genres: { $in: [category] } });

        // Verifica se o filme existe
        if (!movies.length) {
            // Cria a response
            const response = GetMoviesByCategoryResponse.create({
                status: 404,
                movies: []
            });

            // Serializa a mensagem protobuf em string
            const buffer = GetMoviesByCategoryResponse.encode(response).finish();

            // Define o tamanho da mensagem
            const size = Buffer.byteLength(buffer);

            // envia o tamanho da mensagem em 4 bytes por socket
            socket.write(Buffer.alloc(4, size));

            // envia a mensagem
            socket.write(buffer);

            return;
        }

        // Cria a response
        const response = GetMoviesByCategoryResponse.create({
            status: 200,
            movies: movies.map(movie => {
                return {
                    id: movie._id.toString(),
                    plot: movie.plot,
                    genres: movie.genres,
                    runtime: movie.runtime,
                    cast: movie.cast,
                    numMflixComments: movie.num_mflix_comments,
                    title: movie.title,
                    fullplot: movie.fullplot,
                    countries: movie.countries,
                    directors: movie.directors,
                    rated: movie.rated,
                    awards: movie.awards,
                    year: movie.year
                }
            })
        });

        // Serializa a mensagem protobuf em string
        const buffer = GetMoviesByCategoryResponse.encode(response).finish();

        // Define o tamanho da mensagem
        const size = Buffer.byteLength(buffer);

        // envia o tamanho da mensagem em 4 bytes por socket
        socket.write(Buffer.alloc(4, size));

        // envia a mensagem
        socket.write(buffer);

    } catch (error) {
        console.log(error)
    }
}


export default {
    createMovie,
    updateMovie,
    getMovie,
    deleteMovie,
    getMoviesByActor,
    getMoviesByCategory
}