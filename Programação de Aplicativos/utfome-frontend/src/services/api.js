import axios from 'axios';

export const api = axios.create({
    baseURL: "http://localhost:3333",
});

export const sayHello = async() => {
    const response = await api.get('/hello');
    console.log(response.data);
}


// ############### SESSIONS ###############
export const createSession = async (email, senha) => {
    try{
        const response = api.post('/sessoes', {
            email,
            senha
        });
        return response;
    }catch(err){
        console.log("Erro ao criar sessão");
    }
}

// ############### USERS ###############
export const createUser = async (nome, sobrenome, email, senha) => {
    try{
        const response = api.post('/usuarios', {
            nome,
            sobrenome,
            email,
            senha
        });
        return response;
    }catch(err){
        console.log("Erro ao criar usuário");
    }
}