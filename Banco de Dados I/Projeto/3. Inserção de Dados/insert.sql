/*------------------------------USUARIO---------------------------*/

INSERT INTO USUARIOS (USUARIO, NOME, SOBRENOME, EMAIL, SENHA)
VALUES  ('felipe263236', 'Felipe', 'Mendes', 'abc@gmail.com', 'felipe123'),
        ('lucas37728', 'Lucas', 'Higa', 'fsggg@gmail.com', 'lucas123'),
        ('vini771631', 'Vinicius', 'Hasse', 'aeh@gmail.com', 'vini123'),
        ('jame4928', 'James', 'Potter', 'jhgwre@gmail.com', 'james123'),
        ('maria293784', 'Maria', 'Eduarda', 'jnhbsd@gmail.com', 'maria123'),
        ('pedro2354623', 'Pedro', 'Henrique', 'ksjhc@gmail.com', 'pedro123'),
        ('matheus7674238', 'Matheus', 'Olievira', 'kjssf@gmail.com', 'matheus123'),
        ('julia6235674', 'Julia', 'Mendes', 'ewfre@gmail.com', 'julia123'),
        ('rubia1343141', 'Rubia', 'Archanjo', 'g3tt345@gmail.com', 'rubia123'),
        ('vitor3423424', 'Victor', 'Archanjo', 'tehrgw@gmail.com', 'vitor123');


/*------------------------------LIVROS---------------------------*/

INSERT INTO LIVROS (ID, STATUS, CAPITULOS, TITULO, AUTOR, EDITORA, ANO)
VALUES  (1, 'Lido', 26, 'Harry Potter e a pedra filosofal', 'J.K Rowling', 'Rocco', 1997),
        (2, 'Lido', 34, 'Harry Potter e a camara secreta', 'J.K Rowling', 'Rocco', 1999),
        (3, 'Lido', 21, 'Harry Potter e o prisioeiro de azkabam', 'J.K Rowling', 'Rocco', 2000),
        (4, 'Lido', 31, 'Harry Potter e o calice de fogo', 'J.K Rowling', 'Rocco', 2001),
        (5, 'Lido', 18, 'Harry Potter e a ordem da fenix', 'J.K Rowling', 'Rocco', 2003),
        (6, 'Lendo', 27, 'Harry Potter e o enigma do principe', 'J.K Rowling', 'Rocco', 2005),
        (7, 'Quero ler', 28, 'Harry Potter e as reliquias da morte', 'J.K Rowling', 'Rocco', 2007),
        (8, 'Quero ler', 24, 'Harry Potter e a criança amaldiçoada', 'J.K Rowling', 'Rocco', 2015),
        (9, 'Quero ler', 23, 'O Senhor dos Anéis', 'J.R.R. Tolkien', 'Rocco', 1954),
        (10, 'Quero ler', 40, 'expresso oriente', 'Agatha Christie', 'Rocco', 1954);

/*------------------------------USUARIO_ACOMPANHA_LIVROS---------------------------*/
INSERT INTO USUARIO_ACOMPANHA_LIVROS (USUARIO, ID_LIVRO)
VALUES  ('felipe263236', 1),
        ('lucas37728', 2),
        ('vini771631', 3),
        ('jame4928', 4),
        ('maria293784', 5),
        ('pedro2354623', 6),
        ('matheus7674238', 7),
        ('julia6235674', 8),
        ('rubia1343141', 9),
        ('vitor3423424', 10);

/*------------------------------CAPITULOS---------------------------*/
INSERT INTO CAPITULOS (ID, TITULO, PAGINAS, STATUS)
VALUES  (1, 'O menino que sobreviveu', '26', 'Lido'),
        (2, 'Ovidro que sumiu', '23', 'Lido'),
        (3, 'As cartas de ninguem', '21', 'Lido'),
        (4, 'O guardião das chaves', '25', 'Lido'),
        (5, 'O beco diagonal', '26', 'Lido'),
        (6, 'O embarque na plataforma nove e tres quartos', '26', 'Lido'),
        (7, 'O chapeu Seletor', '21', 'Lido'),
        (8, 'O mestre das poções', '22', 'Lido'),
        (9, 'O duelo a meia noite', '23', 'Lido'),
        (10, 'O dia das buxas', '24', 'Lido');

/*------------------------------LIVRO_TEM_CAPITULOS---------------------------*/
INSERT INTO LIVRO_TEM_CAPITULOS (ID_LIVRO, ID_CAPITULO)
VALUES  (1, 1),
        (1, 2),
        (1, 3),
        (1, 4),
        (1, 5),
        (1, 6),
        (1, 7),
        (1, 8),
        (1, 9),
        (1, 10);

/*------------------------------AUTORES---------------------------*/
INSERT INTO AUTORES (ID, NOME, SOBRENOME, NACIONALIDADE)
VALUES  (1, 'J.K', 'Rowling', 'Inglaterra'),
        (2, 'Machado', 'de Assis', 'Brasil'),
        (3, 'Monteiro', 'Lobato', 'Brasil'),
        (4, 'Guimarães', 'Rosa', 'Brasil'),
        (5, 'José', 'Saramago', 'Brasil'),
        (6, 'Clarice', 'Lispector', 'Brasil'),
        (7, 'José', 'de Alencar', 'Brasil'),
        (8, 'Fernando', 'Pessoa', 'Brasil'),
        (9, 'Jorge', 'Amado', 'Brasil'),
        (10, 'Vinicius', 'de Moraes', 'Brasil');

/*------------------------------LIVRO_ESCRITO_POR---------------------------*/
INSERT INTO LIVRO_ESCRITO_POR (ID_LIVRO, ID_AUTOR)
VALUES  (1, 1),
        (2, 1),
        (3, 1),
        (4, 1),
        (5, 1),
        (6, 1),
        (7, 1),
        (8, 1),
        (9, 1),
        (10, 1);
        
/*------------------------------SERIES---------------------------*/
INSERT INTO SERIES (ID, TITULO, ANO, TEMPORADAS, NOTA_IMDB, STATUS)
VALUES  (1, 'Supernatural', 2005, 15, 6.5),
        (2, 'The Vampire Diaries', 2005, 8, 7.5),
        (3, 'Breaking Bad', 2012, 5, 9.5),
        (4, 'Chucky', 2021, 1, 5.5),
        (5, 'The Office', 2002, 5, 9.5),
        (6, 'Revenge', 2008, 4, 3.5),
        (7, 'Atypical', 2018, 4, 2.5),
        (8, 'Game of Thrones', 5, 15, 9.5),
        (9, 'Dr. House', 2005, 7, 4.5),
        (10, 'The Walking Dead', 2010, 8, 7.5);

/*------------------------------USUARIO_ACOMPANHA_SERIES---------------------------*/
INSERT INTO USUARIO_ACOMPANHA_SERIES (USUARIO, SERIE)
VALUES  ('felipe263236', 1),
        ('lucas37728', 2),
        ('vini771631', 3),
        ('jame4928', 4),
        ('maria293784', 5),
        ('pedro2354623', 6),
        ('matheus7674238', 7),
        ('julia6235674', 8),
        ('rubia1343141', 9),
        ('vitor3423424', 10);
    
/*------------------------------TEMPORADAS---------------------------*/
INSERT INTO TEMPORADAS (ID, STATUS, EPISODIOS)
VALUES  (1, 'Assistida', 10),
        (2, 'Assistida', 15),
        (3, 'Assistida', 12),
        (4, 'Assistida', 11),
        (5, 'Quero Assistir', 13),
        (6, 'Quero Assistir', 15),
        (7, 'Quero Assistir', 13),
        (8, 'Quero Assistir', 12),
        (9, 'Quero Assistir', 10),
        (10, 'Quero Assistir', 10);

/*------------------------------SERIE_TEM_TEMPORADAS---------------------------*/
INSERT INTO SERIE_TEM_TEMPORADAS (ID_SERIE, ID_TEMPORADA)
VALUES  (1, 1),
        (1, 2),
        (1, 3),
        (1, 4),
        (1, 5),
        (1, 6),
        (1, 7),
        (1, 8),
        (1, 9),
        (1, 10);

/*------------------------------EPISODIOS---------------------------*/
INSERT INTO EPISODIOS (ID, NOME, DURAÇÃO, STATUS)
VALUES  (1, '1. Piloto', 45, 'Assistido'),
        (2, '2. Wendigo', 45, 'Assistido'),
        (3, '3. Morte na agua', 45, 'Assistido'),
        (4, '4. Viajante fantasma', 45, 'Assistido'),
        (5, '5. Bloody Mary', 45, 'Assistido'),
        (6, '6. Pele', 45, 'Assistido'),
        (7, '7. Homem-gancho', 45, 'Assistido'),
        (8, '8. Insetos', 45, 'Assistido'),
        (9, '9. Volta ao lar', 45, 'Assistido'),
        (10, '10. Asilo', 45, 'Assistido');

/*------------------------------TEMPORADA_TEM_EPISODIOS---------------------------*/
INSERT INTO TEMPORADA_TEM_EPISODIOS (ID_TEMPORADA, ID_EPISODIO)
VALUES  (1, 1),
        (1, 2),
        (1, 3),
        (1, 4),
        (1, 5),
        (1, 6),
        (1, 7),
        (1, 8),
        (1, 9),
        (1, 10);

/*------------------------------ATORES---------------------------*/
INSERT INTO ATORES (ID, NOME, SOBRENOME, NACIONALIDADE, PERSONAGEM)
VALUES  (1, 'Daniel', 'Radcliffe', 'Inglaterra', 'Harry Potter'),
        (2, 'Emma', 'Watson', 'Inglaterra', 'Hermione Granger'),
        (3, 'Rupert', 'Grint', 'Inglaterra', 'Ronald Weasley'),
        (4, 'Tom', 'Felton', 'Inglaterra', 'Draco Malfoy'),
        (5, 'Bonnie', 'Wright', 'Inglaterra', 'Gina Weasley'),
        (6, 'Alan', 'Rickman', 'Inglaterra', 'Severus Snape'),
        (7, 'Matthew', 'Lewis', 'Inglaterra', 'Neville Longbotton'),
        (8, 'Helena', 'Bonham', 'Inglaterra', 'Bellatrix Lestrange'),
        (9, 'Robbie', 'Coltrane', 'Inglaterra', 'Hagrid'),
        (10, 'Gary', 'Oldman', 'Inglaterra', 'Sirius Black');

/*------------------------------TRABALHA_PARA---------------------------*/
INSERT INTO TRABALHA_PARA (ID_ATOR, ID_DIRETOR, ID_PRODUTORA)
VALUES  (1, 1, 1),
        (2, 2, 2),
        (3, 3, 3),
        (4, 4, 4),
        (5, 5, 5),
        (6, 6, 6),
        (7, 7, 7),
        (8, 8, 8),
        (9, 9, 9),
        (10, 10, 10);

/*------------------------------SERIE_ATORES---------------------------*/
INSERT INTO SERIE_ATORES (ID_SERIE, ID_ATOR)
VALUES  (1, 1),
        (2, 2),
        (3, 3),
        (4, 4),
        (5, 5),
        (6, 6),
        (7, 7),
        (8, 8),
        (9, 9),
        (10, 10);
        

/*------------------------------PREMIOS---------------------------*/
INSERT INTO PREMIOS (ID_ATOR, NOME, ANO, CATEGORIA)
VALUES  (1, 'Oscar', 2018, 'Melhor Ator'),
        (1, 'Oscar', 2013, 'Melhor Ator'),
        (2, 'Oscar', 2014, 'Melhor Ator'),
        (2, 'Oscar', 2008, 'Melhor Ator'),
        (2, 'Oscar', 2004, 'Melhor Ator'),
        (2, 'Oscar', 2007, 'Melhor Ator'),
        (3, 'Oscar', 2001, 'Melhor Ator'),
        (3, 'Oscar', 2018, 'Melhor Ator'),
        (4, 'Oscar', 2018, 'Melhor Ator'),
        (4, 'Oscar', 2018, 'Melhor Ator');

/*------------------------------DIRETORES---------------------------*/
INSERT INTO DIRETORES (ID, NOME, SOBRENOME, NACIONALIDADE, FILMES_DIRIGIDOS)
VALUES  (1, 'Steven', 'Spielberg', 'Estados Unidos', '10'),
        (2, 'Quentin', 'Tarantino', 'Estados Unidos', '10'),
        (3, 'James', 'Cameron', 'Reino Unido', '10'),
        (4, 'Martin', 'Scorsese', 'Estados Unidos', '10'),
        (5, 'Christopher', 'Nolan', 'Estados Unidos', '10'),
        (6, 'Ridley', 'Scott', 'Estados Unidos', '10'),
        (7, 'Woody', 'Allen', 'Estados Unidos', '10'),
        (8, 'Tim', 'Burton', 'Estados Unidos', '10'),
        (9, 'Ingmar', 'Bergman', 'Estados Unidos', '10'),
        (10, 'Bernardo', 'Bertolucci', 'Estados Unidos', '10');

/*------------------------------PRODUTORAS---------------------------*/
INSERT INTO PRODUTORAS (ID, NOME, ESTUDIO)
VALUES  (1, 'Universal', 'Universal Pictures'),
        (2, 'Paramount', 'Paramount Pictures'),
        (3, '20th Century Fox', '20th Century Fox'),
        (4, 'DreamWorks', 'DreamWorks'),
        (5, 'Sony', 'Sony Pictures'),
        (6, 'Fox', 'Fox'),
        (7, 'MGM', 'Metro Goldwyn Mayer'),
        (8, 'Lions Gate', 'Lions Gate Entertainment'),
        (9, 'Disney', 'Walt Disney Studios'),
        (10, 'WB', 'WB studios');

/*------------------------------FILMES---------------------------*/
INSERT INTO FILMES (ID, NOME, ANO, DURAÇÃO, NOTA_IMDB, STATUS)
VALUES  (1, 'Piratas do Caribe: A Maldição do Pérola Negra', 2003, 130, 9.5, 'Assistido'),
        (2, 'Piratas do Caribe: O Baú da Morte', 2006, 130, 9.5, 'Assistido'),
        (3, 'Piratas do Caribe: No Fim do Mundo', 2007, 130, 9.5, 'Assistido'),
        (4, 'Piratas do Caribe: Navegando em Águas Misteriosas', 2011, 130, 9.5, 'Assistido'),
        (5, 'Piratas do Caribe: A Vingança de Salazar', 2017, 130, 9.5, 'Assistido'),
        (6, 'Homem-Aranha: Longe de Casa', 2019, 130, 9.5, 'Assistido'),
        (7, 'Homem-Aranha: De Volta ao Lar', 2017, 130, 9.5, 'Assistido'),
        (8, 'Vingadores: Ultimato', 2019, 130, 9.5, 'Assistido'),
        (9, 'Capitão América: Guerra Civil', 2016, 130, 9.5, 'Assistido'),
        (10, 'Homem-Aranha 3', 2017, 130, 9.5, 'Assistido');

/*------------------------------FILME_ATORES---------------------------*/
INSERT INTO FILME_ATORES (ID_FILME, ID_ATOR)
VALUES  (1, 1),
        (2, 2),
        (3, 3),
        (4, 4),
        (5, 5),
        (6, 6),
        (7, 7),
        (8, 8),
        (9, 9),
        (10, 10);

/*------------------------------FILME_PLATAFORMAS---------------------------*/
INSERT INTO FILME_PLATAFORMAS (ID_FILME, ID_PLATAFORMA)
VALUES  (1, 1),
        (2, 2),
        (3, 3),
        (4, 4),
        (5, 5),
        (6, 6),
        (7, 7),
        (8, 8),
        (9, 9),
        (10, 10);

/*------------------------------USUARIO_ACOMPANHA_FILMES---------------------------*/
INSERT INTO USUARIO_ACOMPANHA_FILMES (USUARIO, ID_FILME)
VALUES  ('felipe263236', 1),
        ('lucas37728', 2),
        ('vini771631', 3),
        ('jame4928', 4),
        ('maria293784', 5),
        ('pedro2354623', 6),
        ('matheus7674238', 7),
        ('julia6235674', 8),
        ('rubia1343141', 9),
        ('vitor3423424', 10);
        

/*------------------------------PLATAFORMAS---------------------------*/
INSERT INTO PLATAFORMAS (ID, NOME, LINK)
VALUES  (1, 'Netflix', 'https://www.netflix.com/'),
        (2, 'Amazon Prime Video', 'https://www.primevideo.com/'),
        (3, 'HBO', 'https://www.hbo.com/'),
        (4, 'HBO GO', 'https://www.hbogo.com/'),
        (5, 'Disney+', 'https://www.disneyplus.com/'),
        (6, 'NetMovies', 'https://www.netmovies.com.br'),
        (7, 'Filmelier', 'https://www.filmelier.com/br/assistir-filmes-online'),
        (8, 'Looke', 'https://www.looke.com.br/home'),
        (9, 'FilmesOnlines', 'https://filmesonlines.org'),
        (10, 'AssistirFilmesOnline', 'https://assistirfilmesonline.pro');

/*------------------------------SERIE_PLATAFORMAS---------------------------*/
INSERT INTO SERIE_PLATAFORMAS (ID_SERIE, ID_PLATAFORMA)
VALUES  (1, 1),
        (2, 2),
        (3, 3),
        (4, 4),
        (5, 5),
        (6, 6),
        (7, 7),
        (8, 8),
        (9, 9),
        (10, 10);
        
/*------------------------------GENEROS---------------------------*/
INSERT INTO GENEROS (ID, NOME)
VALUES  (1, 'Ação'),
        (2, 'Aventura'),
        (3, 'Comédia'),
        (4, 'Drama'),
        (5, 'Ficção Científica'),
        (6, 'Fantasia'),
        (7, 'Terror'),
        (8, 'Suspense'),
        (9, 'Romance'),
        (10, 'Animação');

/*------------------------------LIVRO-GENEROS---------------------------*/
INSERT INTO LIVRO_GENEROS (ID_LIVRO, ID_GENERO)
VALUES  (1, 6),
        (2, 6),
        (3, 6),
        (4, 6),
        (5, 6),
        (6, 6),
        (7, 6),
        (8, 6),
        (9, 6),
        (10, 8);

/*------------------------------SERIE_GENERO---------------------------*/
INSERT INTO SERIE_GENERO (ID_SERIE, ID_GENERO)
VALUES  (1, 7),
        (2, 4),
        (3, 1),
        (4, 7),
        (5, 3),
        (6, 8),
        (7, 3),
        (8, 1),
        (9, 3),
        (10, 7);

/*------------------------------FILME_GENERO---------------------------*/
INSERT INTO FILME_GENERO (ID_FILME, ID_GENERO)
VALUES  (1, 5),
        (2, 3),
        (3, 6),
        (4, 9),
        (5, 1),
        (6, 5),
        (7, 3),
        (8, 2),
        (9, 4),
        (10, 8);