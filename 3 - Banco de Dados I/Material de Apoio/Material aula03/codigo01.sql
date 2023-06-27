DROP TABLE IF EXISTS MATRICULAS;
DROP TABLE IF EXISTS CONCLUIDAS;
DROP TABLE IF EXISTS CURSOS_TEM_DISCIPLINAS;
DROP TABLE IF EXISTS ALUNOS;

DROP TABLE IF EXISTS PREREQUISITOS;
DROP TABLE IF EXISTS CURSOS;
DROP TABLE IF EXISTS DISCIPLINAS;
DROP TABLE IF EXISTS DEPARTAMENTOS;


CREATE TABLE DEPARTAMENTOS(
    codigo INTEGER ,
    detalhes VARCHAR(100),
    PRIMARY KEY(codigo)
);

CREATE TABLE CURSOS(
   nome VARCHAR(100),
   cod_depto INTEGER ,
   FOREIGN KEY (cod_depto) REFERENCES DEPARTAMENTOS(codigo),
   PRIMARY KEY (nome)
);

CREATE TABLE DISCIPLINAS(     
     nome VARCHAR(100),     
     ch INTEGER,     
     ementa VARCHAR(200),     
     PRIMARY KEY (nome) 
);

CREATE TABLE ALUNOS(    
    num INTEGER,    
    nome VARCHAR(100),
    nome_curso VARCHAR(100),
    PRIMARY KEY(num),
    FOREIGN KEY(nome_curso) REFERENCES CURSOS(nome)
);	

CREATE TABLE MATRICULAS(     
 nome_disciplina VARCHAR(100),     
 num_aluno INTEGER,     
 FOREIGN KEY(nome_disciplina) REFERENCES DISCIPLINAS(nome),     
 FOREIGN KEY(num_aluno) REFERENCES ALUNOS(num),     
 PRIMARY KEY(nome_disciplina, num_aluno) 
);

CREATE TABLE CONCLUIDAS(     
 nome_disciplina VARCHAR(100),     
 num_aluno INTEGER,     
 FOREIGN KEY(nome_disciplina) REFERENCES DISCIPLINAS(nome),     
 FOREIGN KEY(num_aluno) REFERENCES ALUNOS(num),     
 PRIMARY KEY(nome_disciplina, num_aluno) 
);

CREATE TABLE PREREQUISITOS(
   nome_disciplina1 VARCHAR(100),   
   nome_disciplina2 VARCHAR(100),  
   FOREIGN KEY(nome_disciplina1) REFERENCES DISCIPLINAS(nome), 
   FOREIGN KEY(nome_disciplina2) REFERENCES DISCIPLINAS(nome), 
   PRIMARY KEY(nome_disciplina1, nome_disciplina2)
);

CREATE TABLE CURSOS_TEM_DISCIPLINAS(
    nome_curso VARCHAR(100),
    nome_disciplina VARCHAR(100),
    tipo ENUM('Optativa', 'Obrigatorio'),
    FOREIGN KEY(nome_curso) REFERENCES CURSOS(nome), 
    FOREIGN KEY(nome_disciplina) REFERENCES DISCIPLINAS(nome), 
    PRIMARY KEY (nome_curso, nome_disciplina)
);

INSERT INTO DEPARTAMENTOS(codigo, detalhes) VALUES (1, 'DACOM'), (2, 'DACOC');
INSERT INTO CURSOS(nome, cod_depto) VALUES ('Ciencia da Computacao', 1), ('Engenharia Civil', 2);
INSERT INTO CURSOS(nome) VALUES ('Engenharia de Alimentos');
INSERT INTO ALUNOS(num, nome, nome_curso) 
        VALUES(1, 'Joao Tiago', 'Ciencia da Computacao'), 
              (2, 'Maria Eduarda', 'Engenharia Civil');
              
INSERT INTO DISCIPLINAS(nome) VALUES('BD1'), ('BD2'), ('BD3');
INSERT INTO MATRICULAS(nome_disciplina, num_aluno) VALUES('BD1', 1), ('BD1', 2), ('BD2', 2), ('BD3', 2);

