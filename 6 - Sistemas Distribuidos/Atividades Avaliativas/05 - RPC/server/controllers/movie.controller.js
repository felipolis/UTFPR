import movieModel from '../models/movie.model.js';

const createMovie = async (req, callback) => {
    try {
        const plot = req.plot;
        const genres = req.genres;
        const runtime = req.runtime;
        const cast = req.cast;
        const num_mflix_comments = req.num_mflix_comments;
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

        // Cria a resposta
        callback(null, {
            status: 200,
            message: 'Movie created successfully',
            id: createdMovie._id
        });

    } catch (error) {
        callback(null, {
            status: 500,
            message: 'Error creating movie',
            id: ''
        });
    }
};

const getMovie = async (req, callback) => {
    try {
        const movie_id = req.movie_id;

        const movie = await movieModel.findById(movie_id);

        // Verifica se o filme existe
        if (!movie) {
            callback(null, {
                status: 404,
                message: 'Movie not found',
                movie: null
            });
            return;
        }

        // Cria a resposta
        callback(null, {
            status: 200,
            message: 'Movie retrieved successfully',
            movie: movie
        });

    } catch (error) {
        callback(null, {
            status: 500,
            message: 'Error retrieving movie',
            movie: null
        });
    }
}

const updateMovie = async (req, callback) => {
    try {
        const movie_id = req.movie_id;

        const plot = req.plot ? req.plot : null;
        const genres = req.genres ? req.genres : null;
        const runtime = req.runtime ? req.runtime : null;
        const cast = req.cast ? req.cast : null;
        const num_mflix_comments = req.num_mflix_comments ? req.num_mflix_comments : null;
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
        }, { new: true });

        // Verifica se o filme existe
        if (!movie) {
            callback(null, {
                status: 404,
                message: 'Movie not found',
                id: ''
            });
            return;
        }

        // Cria a resposta
        callback(null, {
            status: 200,
            message: 'Movie updated successfully',
            id: movie._id
        });


    } catch (error) {
        callback(null, {
            status: 500,
            message: 'Error updating movie',
            id: ''
        });
    }
};

const deleteMovie = async (req, callback) => {
    try {
        const movie_id = req.movie_id;

        const movie = await movieModel.findByIdAndDelete(movie_id);

        // Verifica se o filme existe
        if (!movie) {
            callback(null, {
                status: 404,
                message: 'Movie not found',
                id: ''
            });
            return;
        }

        // Cria a resposta
        callback(null, {
            status: 200,
            message: 'Movie deleted successfully',
            id: movie._id
        });

    } catch (error) {
        callback(null, {
            status: 500,
            message: 'Error deleting movie',
            id: ''
        });
    }
}

const getMovieByActor = async (req, callback) => {
    try {
        const actor = req.actor;

        const movies = await movieModel.find({ cast: { $in: [actor] } });

        // Verifica se o filme existe
        if (movies.length == 0) {
            callback(null, {
                status: 404,
                message: 'Movie not found',
                movies: null
            });
            return;
        }

        // Cria a resposta
        callback(null, {
            status: 200,
            message: 'Movie retrieved successfully',
            movies: movies
        });

    } catch (error) {
        callback(null, {
            status: 500,
            message: 'Error retrieving movies',
            movies: null
        });
    }
}

const getMovieByCategory = async (req, callback) => {
    try {
        const category = req.category;

        const movies = await movieModel.find({ genres: { $in: [category] } });

        // Verifica se o filme existe
        if (movies.length == 0) {
            callback(null, {
                status: 404,
                message: 'Movie not found',
                movies: null
            });
            return;
        }

        // Cria a resposta
        callback(null, {
            status: 200,
            message: 'Movie retrieved successfully',
            movies: movies
        });

    } catch (error) {
        callback(null, {
            status: 500,
            message: 'Error retrieving movies',
            movies: null
        });
    }
}


export default {
    createMovie,
    getMovie,
    updateMovie,
    getMovieByActor,
    getMovieByCategory,
    deleteMovie
}