
const responseWithData = (res, statusCode, data) => {
    return res.status(statusCode).json(data);
};

const error = (res) => {
    return responseWithData(res, 500, {
        status: 500,
        message: "Ooops! Algo deu errado!",
    });
}

const badrequest = (res, message) => {
    return responseWithData(res, 400, {
        status: 400,
        message,
    });
};

const ok = (res, data) => {
    return responseWithData(res, 200, data);
}

const created = (res, data) => {
    return responseWithData(res, 201, data);
};

const unauthorize = (res) => {
    return responseWithData(res, 401, {
        status: 401,
        message: "Não autorizado!"
    });
};

const notfound = (res) => {
    return responseWithData(res, 404, {
        status: 404,
        message: "Recurso não encontrado!"
    });
};


export default {
    error,
    badrequest,
    ok,
    created,
    unauthorize,
    notfound
}