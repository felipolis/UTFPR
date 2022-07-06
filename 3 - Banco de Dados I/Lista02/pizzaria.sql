DROP TABLE IF EXISTS ATENDENTE_PEDE_PEDIDO;
DROP TABLE IF EXISTS ENTREGADOR_ENTREGA_PEDIDO;
DROP TABLE IF EXISTS PIZZA_PEDIDO;
DROP TABLE IF EXISTS CLIENTE_FAZ_PEDIDO;
DROP TABLE IF EXISTS CLIENTE_MORA_BAIRRO;
DROP TABLE IF EXISTS PIZZA_TEM_TAMANHO;

DROP TABLE IF EXISTS ATENDENTE;
DROP TABLE IF EXISTS ENTREGADOR;
DROP TABLE IF EXISTS FUNCIONARIO;
DROP TABLE IF EXISTS PEDIDO;
DROP TABLE IF EXISTS TAMANHO;
DROP TABLE IF EXISTS PIZZA;
DROP TABLE IF EXISTS CLIENTE;


CREATE TABLE BAIRRO (
    NOME VARCHAR(50) NOT NULL PRIMARY KEY,
    TEMPO INTEGER NOT NULL
);

CREATE TABLE CLIENTE (
    TELEFONE VARCHAR(20) NOT NULL PRIMARY KEY,
    NOME VARCHAR(50) NOT NULL
);

CREATE TABLE PIZZA (
    NUMERO INTEGER NOT NULL PRIMARY KEY,
    NOME VARCHAR(50) NOT NULL,
    INGREDIENTES VARCHAR(50) NOT NULL
);

CREATE TABLE TAMANHO (
    DESCRIÇÃO VARCHAR(50) NOT NULL PRIMARY KEY
);

CREATE TABLE PEDIDO (
    NUM INTEGER NOT NULL PRIMARY KEY,
    DATA DATE NOT NULL,
    ENDEREÇO VARCHAR(50) NOT NULL
);

CREATE TABLE FUNCIONARIO (
    ID INTEGER NOT NULL PRIMARY KEY
);

CREATE TABLE ENTREGADOR (
    ID INTEGER NOT NULL,
    TELEFONE VARCHAR(20) NOT NULL,

    FOREIGN KEY (ID) REFERENCES FUNCIONARIO(ID),
    PRIMARY KEY (ID)
);

CREATE TABLE ATENDENTE (
    ID INTEGER NOT NULL,

    FOREIGN KEY (ID) REFERENCES FUNCIONARIO(ID),
    PRIMARY KEY (ID)
);

/*------------RELAÇÕES----------------*/

CREATE TABLE PIZZA_TEM_TAMANHO (
    NUMERO INTEGER NOT NULL,
    TAMANHO VARCHAR(50) NOT NULL,

    FOREIGN KEY (NUMERO) REFERENCES PIZZA(NUMERO),
    FOREIGN KEY (TAMANHO) REFERENCES TAMANHO(DESCRIÇÃO)
);

CREATE TABLE CLIENTE_MORA_BAIRRO (
    TELEFONE VARCHAR(20) NOT NULL,
    BAIRRO VARCHAR(50) NOT NULL,

    PRIMARY KEY (TELEFONE),
    FOREIGN KEY (TELEFONE) REFERENCES CLIENTE(TELEFONE),
    FOREIGN KEY (BAIRRO) REFERENCES BAIRRO(NOME)
);

CREATE TABLE CLIENTE_FAZ_PEDIDO (
    TELEFONE VARCHAR(20) NOT NULL,
    NUM INTEGER NOT NULL,

    PRIMARY KEY (NUM),
    FOREIGN KEY (TELEFONE) REFERENCES CLIENTE(TELEFONE),
    FOREIGN KEY (NUM) REFERENCES PEDIDO(NUM)
);

CREATE TABLE PIZZA_PEDIDO (
    NUM_PIZZA INTEGER NOT NULL,
    TAMANHO VARCHAR(50) NOT NULL,
    NUM_PEDIDO INTEGER NOT NULL,

    PRIMARY KEY (NUM_PIZZA, TAMANHO, NUM_PEDIDO),
    FOREIGN KEY (NUM_PIZZA) REFERENCES PIZZA(NUMERO),
    FOREIGN KEY (TAMANHO) REFERENCES TAMANHO(DESCRIÇÃO)
);

CREATE TABLE ENTREGADOR_ENTREGA_PEDIDO (
    NUM_PEDIDO INTEGER NOT NULL,
    ID_ENTREGADOR INTEGER NOT NULL,

    PRIMARY KEY (NUM_PEDIDO),
    FOREIGN KEY (NUM_PEDIDO) REFERENCES PEDIDO(NUM),
    FOREIGN KEY (ID_ENTREGADOR) REFERENCES ENTREGADOR(ID)
);

CREATE TABLE ATENDENTE_PEDE_PEDIDO (
    NUM_PEDIDO INTEGER NOT NULL,
    ID_ATENDENTE INTEGER NOT NULL,

    PRIMARY KEY (NUM_PEDIDO),
    FOREIGN KEY (NUM_PEDIDO) REFERENCES PEDIDO(NUM),
    FOREIGN KEY (ID_ATENDENTE) REFERENCES ATENDENTE(ID)
);
