CREATE TABLE DISCIPLINA(
  nome VARCHAR(100) PRIMARY KEY,
  preRequisito VARCHAR(100),
  FOREIGN KEY(preRequisito) REFERENCES DISCIPLINA(nome)
);

CREATE TABLE ALUNO(
   id INTEGER PRIMARY KEY,
   nome VARCHAR(100)
);

CREATE TABLE PROFESSOR(
   id INTEGER PRIMARY KEY,
   nome VARCHAR(100)
);

CREATE TABLE TURMA(
   ano INTEGER,
   nomeDisciplina VARCHAR(100),
   professor INTEGER,
   PRIMARY KEY (nomeDisciplina,ano),
   FOREIGN KEY(nomeDisciplina) REFERENCES DISCIPLINA(nome),
   FOREIGN KEY(professor) REFERENCES PROFESSOR(id)
);

CREATE TABLE MATRICULA(
    idAluno INTEGER PRIMARY KEY,
    nomeDisciplina VARCHAR(100),
    ano INTEGER,
    nota DECIMAL(10,2),
    FOREIGN KEY(nomeDisciplina, ano) REFERENCES TURMA(nomeDisciplina, ano),
    FOREIGN KEY(idAluno) REFERENCES ALUNO(id)
);

-- 1) selecione todos os alunos que fizeram a disciplina de Banco de Dados na turma de 2020 com o professor André
SELECT ALUNO.nome
FROM ALUNO, MATRICULA, TURMA, PROFESSOR, DISCIPLINA
WHERE ALUNO.id = MATRICULA.idAluno
AND TURMA.nomeDisciplina = DISCIPLINA.nome
AND TURMA.professor = PROFESSOR.id
AND DISCIPLINA.nome = 'Banco de Dados'
AND TURMA.ano = 2020
AND PROFESSOR.nome = 'André';

-- 2) selecione o nome dos professores (sem repetição) que ministraram disciplinas de 2010 a 2020.
SELECT DISTINCT PROFESSOR.nome
FROM PROFESSOR, TURMA
WHERE PROFESSOR.id = TURMA.professor
AND TURMA.ano BETWEEN 2010 AND 2020;

-- 3) selecione o nome das disciplinas e a quantidade de turmas já ofertadas.
SELECT DISCIPLINA.nome, COUNT(*)
FROM DISCIPLINA, TURMA
WHERE DISCIPLINA.nome = TURMA.nomeDisciplina
GROUP BY DISCIPLINA.nome;

-- 4) selecione as disciplinas que NÃO foram ofertadas em 2020.
SELECT DISCIPLINA.nome
FROM DISCIPLINA, TURMA
WHERE DISCIPLINA.nome = TURMA.nomeDisciplina
AND TURMA.ano <> 2020;

-- 5) selecione o nome das disciplinas e o número de vezes que ela é pré-requisito.
SELECT DISCIPLINA.nome, COUNT(*)
FROM DISCIPLINA, DISCIPLINA AS DISCIPLINA_PRE
WHERE DISCIPLINA.preRequisito = DISCIPLINA_PRE.nome
GROUP BY DISCIPLINA.nome;

-- 6) Escreva uma consulta em Álgebra Relacional que exiba as disciplinas que foram ofertadas em 2019 e em 2020.
