ALUNO(nroAlun:integer, nomeAlun:string, formação:string, nível:string, idade:integer);
CURSO(nome:string, horário:time, sala:string, idProf:integer);
MATRICULADO(nroAlun:integer, nomeCurso:string);
PROFESSOR(idProf:integer, nomeProf:string, idDepto: integer);


-- Encontre os nomes de todos os Juniors (nível = JR) que estão matriculados em um curso ministrado por Ivana Teach.
SELECT A.nomeAlun
FROM ALUNO A
WHERE A.nroAlun IN (
    SELECT M.nroAlun
    FROM MATRICULADO M
    WHERE M.nomeCurso IN (
        SELECT C.nome
        FROM CURSO C
        WHERE C.idProf IN (
            SELECT P.idProf
            FROM PROFESSOR P
            WHERE P.nomeProf = 'Ivana Teach'
        )
    )
);


-- Encontre a idade do aluno mais velho que é formado em History ou matriculado em um curso ministrado por Ivana Teach.
SELECT MAX(idade)
FROM (
    SELECT A.idade
    FROM ALUNO A
    WHERE A.formação = 'History'
    UNION
    SELECT A.idade
    FROM ALUNO A
    WHERE A.nroAlun IN (
        SELECT M.nroAlun
        FROM MATRICULADO M
        WHERE M.nomeCurso IN (
            SELECT C.nome
            FROM CURSO C
            WHERE C.idProf IN (
                SELECT P.idProf
                FROM PROFESSOR P
                WHERE P.nomeProf = 'Ivana Teach'
            )
        )
    )
) AS T;

-- Encontre os nome de todos os cursos que são ministrados na sala R128 ou que têm cinco ou mais alunos matriculados.
SELECT C.nome
FROM CURSO C
WHERE C.sala = 'R128'
OR C.nome IN (
    SELECT M.nomeCurso
    FROM MATRICULADO M
    WHERE COUNT(M.nroAlun) >= 5
);


-- Encontre os nomes de todos os alunos que estão matriculados em dois cursos que são ministrados no mesmo horário.
SELECT A.nomeAlun, C1.nome, C2.nome
FROM ALUNO A
JOIN MATRICULADO M1 ON A.nroAlun = M1.nroAlun
JOIN MATRICULADO M2 ON A.nroAlun = M2.nroAlun
JOIN CURSO C1 ON M1.nomeCurso = C1.nome
JOIN CURSO C2 ON M2.nomeCurso = C2.nome
WHERE C1.horário = C2.horário;


-- Encontre os nomes dos professores que ministram cursos em todas as salas em que algum curso é ministrado. Há uma solução mais simples usando EXCEPT, mas não é suportado pelo MySQL.
SELECT P.nomeProf
FROM PROFESSOR P
WHERE P.idProf IN (
    SELECT C.idProf
    FROM CURSO C
    WHERE C.sala IN (
        SELECT C.sala
        FROM CURSO C
        WHERE C.idProf IN (
            SELECT C.idProf
            FROM CURSO C
            WHERE C.nome IN (
                SELECT M.nomeCurso
                FROM MATRICULADO M
            )
        )
    )
);


-- Encontre os nomes dos professores para os quais a lista de matriculados dos cursos que eles ministram é menor do que cinco.
SELECT P.nomeProf
FROM PROFESSOR P
WHERE P.idProf IN (
    SELECT C.idProf
    FROM CURSO C
    WHERE C.nome IN (
        SELECT M.nomeCurso
        FROM MATRICULADO M
    )
    AND COUNT(M.nroAlun) < 5
);


-- Imprima o nível e a idade média dos alunos desse nível, para cada nível.
SELECT A.nível, AVG(A.idade)
FROM ALUNO A
GROUP BY A.nível;


-- Imprima o nível e a idade média dos alunos desse nível, para todos os níveis exceto JR.
SELECT A.nível, AVG(A.idade)
FROM ALUNO A
WHERE A.nível != 'JR';


-- Para cada professor que ministra cursos apenas na sala R128, imprima seu nome e o número total de cursos que ele ou ela ministra. Há uma solução BEM mais simples usando o HAVING EVERY(C.SALA = ’R128’), mas o EVERY não é suportado pelo MySQL.
SELECT P.nomeProf, COUNT(C.nome)
FROM PROFESSOR P
JOIN CURSO C ON P.idProf = C.idProf
WHERE C.sala = 'R128';

-- Encontre os nomes dos alunos matriculados no número máximo de cursos.
SELECT A.nomeAlun
FROM ALUNO A
WHERE A.nroAlun IN (
    SELECT M.nroAlun
    FROM MATRICULADO M
    GROUP BY M.nroAlun
    HAVING COUNT(M.nomeCurso) = (
        SELECT MAX(COUNT(M.nomeCurso))
        FROM MATRICULADO M
    )
);


-- Encontre os nomes dos alunos não matriculados em nenhum curso.
SELECT A.nomeAlun
FROM ALUNO A
WHERE A.nroAlun NOT IN (
    SELECT M.nroAlun
    FROM MATRICULADO M
);

-- Para cada valor de idade que aparece em Aluno, encontre o valor do nível que aparece com mais frequência. Por exemplo, se houver mais alunos no nível FR com idade 18 do que alunos com idade 18 dos níveis SR, JR ou SR, você deve imprimir o par (18, FR).
SELECT A.idade, A.nível
FROM ALUNO A
GROUP BY A.idade
HAVING COUNT(A.nível) = (
    SELECT MAX(COUNT(A.nível))
    FROM ALUNO A
);