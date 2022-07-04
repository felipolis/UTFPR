const express = require('express');
const app = express();
const cors = require('cors');

const routes = require('./routes.js');


app.use(express.json());
app.use(cors());
app.use(routes);

app.listen(3333, () => {
    console.log("Server started on port 3333");
});