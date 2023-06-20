# Web Scraping Funcional

### Objetivo

O código fornecido é um módulo Elixir chamado "Movies" que contém funções para realizar scraping em três sites diferentes (AdoroCinema, IMDb e Filmow) e obter informações sobre filmes. O objetivo é pesquisar filmes usando uma determinada chave e salvar os resultados em arquivos de texto.Extração de filmes em 3 sites diferentes a partir de uma palavra-chave.

### Funcionamento

Aqui está uma descrição de cada função no código:

1. `get_movies_adorocinema(key)`: Esta função realiza scraping no site AdoroCinema. Ele itera por 10 páginas e para cada página faz uma requisição HTTP para obter o conteúdo da página. Em seguida, ele extrai os links dos filmes e faz uma nova requisição HTTP para cada link para obter informações detalhadas do filme, como título e sinopse. Se a chave fornecida estiver presente no título ou na sinopse, os detalhes do filme são gravados em um arquivo e uma lista contendo os detalhes do filme é retornada.
2. `get_movies_imdb(key)`: Esta função realiza scraping no site IMDb. Ele faz uma única requisição HTTP para obter o conteúdo da página principal do IMDb Top 250. Em seguida, ele extrai os links dos filmes e faz uma nova requisição HTTP para cada link para obter informações detalhadas do filme, como título e sinopse. Se a chave fornecida estiver presente no título ou na sinopse, os detalhes do filme são gravados em um arquivo e uma lista contendo os detalhes do filme é retornada.
3. `get_movies_filmow(key)`: Esta função realiza scraping no site Filmow. Ele itera por 6 páginas e para cada página faz uma requisição HTTP para obter o conteúdo da página. Em seguida, ele extrai os links dos filmes e faz uma nova requisição HTTP para cada link para obter informações detalhadas do filme, como título e sinopse. Se a chave fornecida estiver presente no título ou na sinopse, os detalhes do filme são gravados em um arquivo e uma lista contendo os detalhes do filme é retornada.
4. `main(key)`: Esta é a função principal que inicia o scraping. Ela chama as três funções de scraping (`get_movies_adorocinema`, `get_movies_imdb` e `get_movies_filmow`) com a chave fornecida como argumento. Os resultados das três funções são concatenados em uma lista de filmes e retornados como resultado da função principal.

Em resumo, o módulo "Movies" permite pesquisar filmes em três sites diferentes usando uma chave e salvar os detalhes dos filmes correspondentes em arquivos de texto.

### Requisitos

- Erlang/OTP 25
- Elixir 1.14.4 (compiled with Erlang/OTP 25)

### Como executar

1. Instale as dependencias utilizando o comando `mix deps.get`
2. Entre no diretório do projeto e digite no terminal: `iex -S mix` para entrar no erminal interativo.
3. Execute o script principal com o comando `Movies.main("<KEY>")`, onde \<KEY> é a palavra-chave utilizada como busca no scraping.
4. Será gerados até 3 arquivos no diretorio ./output com as informações recebidas em casa website.

### Autores

- Felipe Archanjo da Cunha Mendes
- Bianca Miazaki
- João Tiago Mielli
