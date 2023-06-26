import express from 'express';
import cookieParser from 'cookie-parser';
import cors from 'cors';
import http from 'http';
import mongoose from 'mongoose';
import "dotenv/config";
import colors from 'colors';
import routes from './src/routes/index.js';

// -------- CONFIGURAÇÕES DO SERVIDOR --------
const app = express();

app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());

app.use('/api/v1', routes);

const port = process.env.PORT || 5000;
const server = http.createServer(app);


// -------- INICIALIZAÇÃO DO SERVIDOR HTTP E CONEXÃO AO BANCO DE DADOS --------

const startServer = async () => {
    try {
        await mongoose.connect(process.env.MONGODB_URL, {
            useNewUrlParser: true,
            useUnifiedTopology: true,
        });
        console.log(`MongoDB connected`.cyan.underline.bold);
        server.listen(port, () => console.log(`Server running on port ${port}`.yellow.bold));
    } catch (error) {
        console.log(error);
    }
};

startServer();

// -------- SOCKETS --------
// cria o server socket
import { Server } from 'socket.io';

const io = new Server(server, {
    pingTimeout: 60000,
    cors: {
        origin: 'http://localhost:3000',
    }
});

// Eventos de conexão e desconexão
global.onlineUsers = [];

io.on('connection', (socket) => {
    console.log('a user connected');

    socket.on('setup', (userData) => {
        socket.join(userData._id);
        socket.emit('connected');
        console.log(`User ${userData._id} connected`);

        // Adiciona [userData._id, socket.id] ao array global.onlineUsers
        global.onlineUsers.push([userData._id, socket.id]);
        io.emit('onlineUsers', global.onlineUsers);
    });

    socket.on("join chat", (room) => {
        socket.join(room);
        console.log(`User joined room ${room}`);
    });

    socket.on("new message", (newMessageRecieved) => {
        //console.log(newMessageRecieved);

        var chat = newMessageRecieved.chat;

        if (!chat.users) return console.log("Chat.users not defined");

        chat.users.forEach((user) => {
            if (user._id == newMessageRecieved.sender._id) return;

            socket.in(user._id).emit("message received", newMessageRecieved);
        });
    });

    socket.on("typing", (room) => {
        socket.in(room).emit("typing", room);
    });

    socket.on("stop typing", (room) => {
        socket.in(room).emit("stop typing");
    });

    socket.on("disconnect", () => {
        console.log("user disconnected");
        const index = global.onlineUsers.findIndex((user) => user[1] === socket.id);
        if (index > -1) {
            global.onlineUsers.splice(index, 1);
            io.emit('onlineUsers', global.onlineUsers);
        }
    });
});