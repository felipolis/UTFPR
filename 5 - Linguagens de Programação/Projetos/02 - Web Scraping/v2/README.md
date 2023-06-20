# Web Scraping Funcional

### Objetivo

O código fornecido é um módulo Elixir chamado "Movies" que contém funções para realizar scraping em três sites diferentes (AdoroCinema, IMDb e Filmow) e obter informações sobre filmes. O objetivo é pesquisar filmes usando uma determinada chave e salvar os resultados em arquivos de texto.Extração de filmes em 3 sites diferentes a partir de uma palavra-chave.

### Funcionamento

Este código define um módulo chamado "Movies" que contém várias funções relacionadas a raspagem de dados de diferentes fontes de filmes na web. Vou explicar cada uma das funções de forma resumida:

1. `get_movies_adorocinema(key)`: Essa função é a interface pública para obter filmes do site AdoroCinema. Chama a função privada `get_movies_adorocinema(key, page, acc)` com valores iniciais.
2. `get_movies_adorocinema(key, page, acc)`: Essa função privada é responsável por fazer a raspagem dos filmes do AdoroCinema. Ela recebe uma chave de pesquisa, número da página e uma lista acumuladora como parâmetros. Faz uma requisição HTTP para obter a página correspondente usando a biblioteca HTTPoison. Em seguida, usa a biblioteca Floki para encontrar os elementos HTML desejados, como o título e a sinopse do filme. Se a chave de pesquisa corresponder ao título ou à sinopse do filme, escreve as informações em um arquivo e adiciona o filme à lista acumuladora. Depois, verifica se há mais páginas para raspar e, se sim, chama recursivamente essa função com o número da próxima página.
3. `get_movies_filmow(key)`: Essa função é semelhante à função `get_movies_adorocinema(key)`, mas para o site Filmow. Faz a raspagem dos filmes do Filmow usando as mesmas etapas da função anterior.
4. `get_movies_imdb(key)`: Essa função é semelhante às duas anteriores, mas para o site IMDb. Faz a raspagem dos filmes mais bem avaliados do IMDb.
5. `main(key)`: Essa função é a principal e é responsável por coordenar o processo de raspagem de filmes de todas as fontes. Cria uma pasta chamada "output" se ela ainda não existir. Em seguida, inicia tarefas assíncronas usando a função `Task.async/1` para chamar as funções de raspagem dos três sites. Aguarda a conclusão de cada tarefa usando `Task.await/2` e combina os resultados em uma lista. Por fim, retorna a lista de filmes raspados.

O código geralmente segue a abordagem de raspagem usando bibliotecas como HTTPoison para fazer requisições HTTP e Floki para analisar o conteúdo HTML e extrair as informações desejadas. Também utiliza o módulo Logger para registrar mensagens informativas e de erro durante o processo de raspagem.

### Caracteristicas do uso de linguagem funcional

O código apresentado possui várias características que evidenciam o uso de uma linguagem funcional. Algumas dessas características são:

1. **Funções puras:** A maioria das funções no código não tem efeitos colaterais, ou seja, elas não modificam o estado externo ou dependem dele. Elas recebem argumentos e retornam valores, sem alterar nenhum estado compartilhado. Por exemplo, as funções `get_movies_adorocinema/1`, `get_movies_filmow/1` e `get_movies_imdb/1` são funções puras que recebem uma chave como argumento e retornam uma lista de filmes. Essas funções não modificam nenhum estado externo.
2. **Imutabilidade:** Os dados no código são imutáveis, o que significa que eles não podem ser modificados após serem criados. Por exemplo, as variáveis `url`, `content`, `movies`, `title` e `sinopse` não sofrem alterações após serem definidas. Em vez disso, novos valores são criados a cada etapa de processamento, mantendo os dados originais imutáveis.
3. **Recursão:** O código faz uso de recursão para iterar sobre páginas de resultados e coletar filmes. As funções `get_movies_adorocinema/3`, `get_movies_filmow/3` e `get_movies_imdb/1` são chamadas recursivas que incrementam o número da página para buscar filmes adicionais. Essa abordagem é comum em linguagens funcionais, onde laços de repetição são substituídos por recursão.
4. **Composição de funções:** O código faz uso de funções de ordem superior, como `Enum.map/2` e `Enum.uniq/1`, para transformar e combinar os dados. Essas funções permitem a composição de várias operações em uma única expressão funcional.
5. **Tratamento de erros com padrões de casamento:** O código utiliza padrões de casamento (pattern matching) para tratar diferentes situações de erro. Por exemplo, a expressão `case HTTPoison.get(url) do` é usada para verificar se a requisição HTTP foi bem-sucedida ou resultou em um erro. O padrão de casamento permite tratar cada caso de forma adequada.

Essas são apenas algumas das características do código em Elixir que evidenciam o uso de uma linguagem funcional. A linguagem também oferece outras funcionalidades, como imutabilidade estrutural, pipeline operator, high-order functions e concorrência leve, que não estão explicitamente presentes no código fornecido, mas são parte do paradigma funcional e estão disponíveis para uso em Elixir.

### Explicação linha a linha

O código em Elixir apresentado define um módulo chamado `Movies` que contém várias funções relacionadas à raspagem de dados de filmes de diferentes sites, como AdoroCinema, Filmow e IMDB. Vou explicar detalhadamente cada função do código:

1. `defmodule Movies do`:
   * Define o início do módulo chamado `Movies`.
2. `require Logger`:
   * Inclui a biblioteca `Logger` para permitir a saída de logs durante a execução do código.
3. `require HTTPoison`:
   * Inclui a biblioteca `HTTPoison`, que é uma biblioteca HTTP para requisições em Elixir.
4. `require Floki`:
   * Inclui a biblioteca `Floki`, que é um parser e manipulador de documentos HTML em Elixir.
5. `def get_movies_adorocinema(key) do`:
   * Define uma função pública chamada `get_movies_adorocinema` que recebe uma chave de pesquisa `key`.
   * Chama a função `get_movies_adorocinema/3` com os argumentos `key`, `1` e uma lista vazia `[]`.
6. `defp get_movies_adorocinema(key, page, acc) do`:
   * Define uma função privada chamada `get_movies_adorocinema` que recebe uma chave de pesquisa `key`, um número de página `page` e uma lista acumuladora `acc`.
   * Verifica se `page` é igual a 1 e define a URL de acordo com a condição.
   * Registra um log informando a página sendo raspada e a URL correspondente.
   * Faz uma requisição HTTP para a URL usando a biblioteca `HTTPoison`.
   * Se a resposta da requisição for bem-sucedida (código de status 200), o corpo da resposta é analisado usando a biblioteca `Floki`.
   * A função procura no corpo da página os elementos `<a>` com a classe `meta-title-link` e extrai os atributos `href` desses elementos.
   * Mapeia os links encontrados e para cada link, faz uma nova requisição HTTP para obter o corpo da página correspondente ao link.
   * Se a resposta da requisição for bem-sucedida, o título e a sinopse do filme são extraídos do corpo da página usando a biblioteca `Floki`.
   * Verifica se o título ou a sinopse contêm a chave de pesquisa `key` (ignorando maiúsculas/minúsculas).
   * Se a condição for verdadeira, o título, a sinopse e o link completo do filme são escritos em um arquivo de saída e adicionados a uma lista.
   * Caso contrário, uma lista vazia é retornada.
   * Verifica se a lista de filmes é vazia.
   * Se for vazia, retorna a lista acumulada `acc`.
   * Caso contrário, chama recursivamente a função `get_movies_adorocinema` incrementando o número da página em 1 e concatenando a lista atual de filmes à lista acumulada `acc`.
7. `def get_movies_filmow(key) do`:
   * Define uma função pública chamada `get_movies_filmow` que recebe uma chave de pesquisa `key`.
   * Chama a função `get_movies_filmow/3` com os argumentos `key`, `1` e uma lista vazia `[]`.
8. `defp get_movies_filmow(key, page, acc) do`:
   * Define uma função privada chamada `get_movies_filmow` que recebe uma chave de pesquisa `key`, um número de página `page` e uma lista acumuladora `acc`.
   * Verifica se `page` é igual a 1 e define a URL de acordo com a condição.
   * Registra um log informando a página sendo raspada e a URL correspondente.
   * Faz uma requisição HTTP para a URL usando a biblioteca `HTTPoison`.
   * Se a resposta da requisição for bem-sucedida (código de status 200), o corpo da resposta é analisado usando a biblioteca `Floki`.
   * A função procura no corpo da página os elementos `<li>` com a classe `movie_list_item` e extrai os atributos `href` dos elementos `<a>` dentro desses elementos `<li>`.
   * Remove os links duplicados usando `Enum.uniq/1`.
   * Mapeia os links encontrados e para cada link, faz uma nova requisição HTTP para obter o corpo da página correspondente ao link.
   * Se a resposta da requisição for bem-sucedida, o título e a sinopse do filme são extraídos do corpo da página usando a biblioteca `Floki`.
   * Verifica se o título ou a sinopse contêm a chave de pesquisa `key` (ignorando maiúsculas/minúsculas).
   * Se a condição for verdadeira, o título, a sinopse e o link completo do filme são escritos em um arquivo de saída e adicionados a uma lista.
   * Caso contrário, uma lista vazia é retornada.
   * Verifica se a lista de filmes é vazia.
   * Se for vazia, retorna a lista acumulada `acc`.
   * Caso contrário, chama recursivamente a função `get_movies_filmow` incrementando o número da página em 1 e concatenando a lista atual de filmes à lista acumulada `acc`.
9. `def get_movies_imdb(key) do`:
   * Define uma função pública chamada `get_movies_imdb` que recebe uma chave de pesquisa `key`.
   * Faz uma requisição HTTP para a URL do IMDB.
   * Se a resposta da requisição for bem-sucedida (código de status 200), o corpo da resposta é analisado usando a biblioteca `Floki`.
   * A função procura no corpo da página os elementos da tabela de filmes e extrai os atributos `href` dos elementos `<a>` correspondentes aos links dos filmes.
   * Mapeia os links encontrados e para cada link, faz uma nova requisição HTTP para obter o corpo da página correspondente ao link.
   * Se a resposta da requisição for bem-sucedida, o título e a sinopse do filme são extraídos do corpo da página usando a biblioteca `Floki`.
   * Verifica se o título ou a sinopse contêm a chave de pesquisa `key` (ignorando maiúsculas/minúsculas).
   * Se a condição for verdadeira, o título, a sinopse e o link completo do filme são escritos em um arquivo de saída e adicionados a uma lista.
   * Caso contrário, uma lista vazia é retornada.
   * Retorna a lista de filmes encontrados ou uma lista vazia.
10. `def main(key) do`:
    * Define a função pública `main` que recebe uma chave de pesquisa `key`.
    * Verifica se o diretório de saída não existe e cria o diretório se necessário.
    * Registra um log informando o início da raspagem para a chave de pesquisa `key`.
    * Cria tarefas assíncronas usando `Task.async/1` para chamar as funções de raspagem dos sites AdoroCinema, Filmow e IMDB.
    * Aguarda a conclusão das tarefas usando `Task.await/2`.
    * Concatena as listas de filmes obtidos de cada site em uma única lista.
    * Registra um log informando o término da raspagem para a chave de pesquisa `key`.
    * Retorna a lista de filmes encontrados.
11. `end`:
    * Encerra a definição do módulo `Movies`.

Essas funções permitem raspar informações sobre filmes dos sites AdoroCinema, Filmow e IMDB com base em uma chave de pesquisa. Os filmes encontrados que correspondem à chave de pesquisa são gravados em arquivos de saída e retornados como uma lista. O código utiliza bibliotecas como `HTTPoison` para fazer requisições HTTP, `Floki` para analisar documentos HTML e `Logger` para registrar logs durante a execução.

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
