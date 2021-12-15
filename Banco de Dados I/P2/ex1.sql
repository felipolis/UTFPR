DROP TABLE IF EXISTS TEM;
DROP TABLE IF EXISTS ENTIDADE_A;
DROP TABLE IF EXISTS ENTIDADE_B;

CREATE TABLE ENTIDADE_A (
    ATRIBUTO_A1 INTEGER NOT NULL,
    ATRIBUTO_A2 VARCHAR(20) NOT NULL,
    PRIMARY KEY (ATRIBUTO_A1)
);

CREATE TABLE ENTIDADE_B (
    ATRIBUTO_B1 INTEGER NOT NULL,
    ATRIBUTO_B2 VARCHAR(20) NOT NULL,
    PRIMARY KEY (ATRIBUTO_B1)
);

CREATE TABLE TEM(
    ATRIBUTO_A1 INTEGER NOT NULL,
    ATRIBUTO_B1 INTEGER NOT NULL,
    ATRIBUTO_REL VARCHAR(20) NOT NULL,
    PRIMARY KEY (ATRIBUTO_A1, ATRIBUTO_B1),
    FOREIGN KEY (ATRIBUTO_A1) REFERENCES ENTIDADE_A(ATRIBUTO_A1),
    FOREIGN KEY (ATRIBUTO_B1) REFERENCES ENTIDADE_B(ATRIBUTO_B1)
);