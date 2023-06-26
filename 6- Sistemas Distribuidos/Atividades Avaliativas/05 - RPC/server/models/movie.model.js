import mongoose from 'mongoose';
import modelOptions from './model.options.js';

const movieSchema = new mongoose.Schema({
    plot: {
        type: String,
        required: true
    },

    genres: {
        type: [String],
        required: true
    },

    runtime: {
        type: Number,
        required: true
    },

    cast: {
        type: [String],
        required: true
    },

    num_mflix_comments: {
        type: Number,
        required: true
    },

    title: {
        type: String,
        required: true
    },

    fullplot: {
        type: String,
        required: true
    },

    countries: {
        type: [String],
        required: true
    },

    directors: {
        type: [String],
        required: true
    },

    rated: {
        type: String,
        required: true
    },

    awards: {
        type: Object,
        required: true
    },

    year: {
        type: Number,
        required: true
    }
}, modelOptions);

const movieModel = mongoose.model('Movie', movieSchema);
export default movieModel;