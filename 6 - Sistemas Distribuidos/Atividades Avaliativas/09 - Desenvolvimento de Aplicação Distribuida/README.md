# Talk-In-Clouds

## Introdução

A aplicação  Talk-In-Clouds é uma aplicação web de chat em tempo real, projetada para permitir que os usuários se comuniquem de forma eficiente e conveniente. A principal função da aplicação é possibilitar conversas entre duas ou mais pessoas, seja em um ambiente de chat individual ou em grupos.

A aplicação foi construída utilizando a stack MERN (MongoDB, Express, React e Node.js), que é um conjunto de tecnologias amplamente utilizadas no desenvolvimento web. O MongoDB foi escolhido como banco de dados, hospedado no Atlas, para armazenar os dados da aplicação de forma escalável e confiável. A estrutura de back-end é baseada no Node.js e no framework Express, que permitem a criação de APIs robustas e escaláveis.

Para garantir a comunicação em tempo real, integramos o socket.io, que é uma biblioteca JavaScript que facilita a troca de eventos em tempo real entre o cliente e o servidor. Isso permite que as mensagens sejam enviadas e recebidas instantaneamente, proporcionando uma experiência de chat em tempo real.

Além disso, a aplicação oferece recursos de cadastro e login para os usuários, garantindo a autenticação e a segurança dos dados. Também implementamos a funcionalidade de armazenamento de fotos de perfil, utilizando o serviço de hospedagem de imagens do Cloudinary.

Para manter a consistência dos dados, utilizamos o LocalStorage, que é uma forma de armazenamento de dados local no navegador. Essa abordagem permite que as informações do usuário sejam armazenadas localmente e acessíveis mesmo quando houver uma desconexão temporária ou perda de conexão com a internet.

No geral, essa aplicação de sistema distribuído foi projetada para fornecer uma plataforma de chat em tempo real, com recursos de cadastro, autenticação, grupos de conversa e armazenamento seguro de dados. Essa combinação de tecnologias e abordagens permite uma comunicação eficiente e confiável entre os usuários, independentemente de sua localização geográfica.

## Layout

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/login.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/register.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/search.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/typing.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/messages1.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/new-group.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/edit-group.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/notifications.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/grupo.png?raw=true)

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/client/src/layouts/messages2.png?raw=true)

## Sistema Distribuido

A aplicação se encaixa na definição de sistemas distribuídos de várias maneiras. Um sistema distribuído é composto por um conjunto de componentes interconectados que trabalham juntos para realizar uma função específica. Nesse caso, a aplicação web de chat em tempo real utiliza diferentes tecnologias e serviços distribuídos para criar uma experiência colaborativa entre os usuários. Abaixo, detalharei como a aplicação se encaixa nessa definição:

1. Comunicação entre componentes distribuídos: A aplicação permite a comunicação entre diferentes componentes distribuídos, como o cliente (navegador web) e o servidor. O cliente se conecta ao servidor para enviar e receber mensagens em tempo real. Essa comunicação é estabelecida por meio do protocolo de comunicação do socket.io, que facilita a troca de eventos em tempo real. Dessa forma, a aplicação permite que usuários em diferentes dispositivos e locais se comuniquem entre si.
2. Escalabilidade e disponibilidade: A aplicação utiliza o MongoDB hospedado no Atlas como banco de dados. Essa escolha permite que os dados sejam armazenados de forma distribuída em vários servidores, garantindo a escalabilidade e a disponibilidade do sistema. O MongoDB é projetado para funcionar em ambientes distribuídos, permitindo que os dados sejam replicados e distribuídos em várias máquinas para lidar com um grande número de usuários e garantir a disponibilidade contínua do serviço.
3. Gerenciamento de autenticação e autorização: A aplicação possui recursos de cadastro e login, o que requer um gerenciamento adequado de autenticação e autorização. Quando um usuário se cadastra ou faz login, as informações de autenticação são verificadas no servidor para garantir que apenas usuários autorizados tenham acesso aos recursos da aplicação. Esse processo envolve a troca de informações entre o cliente e o servidor distribuído, onde os dados de autenticação e autorização são validados e mantidos de forma consistente.
4. Armazenamento de arquivos na nuvem: A aplicação utiliza o serviço de hospedagem de imagens do Cloudinary para armazenar as fotos de perfil dos usuários. O Cloudinary é uma solução distribuída de armazenamento em nuvem, que permite que as imagens sejam carregadas, armazenadas e acessadas de forma eficiente e confiável. Ao utilizar esse serviço distribuído, a aplicação garante a escalabilidade e a disponibilidade do armazenamento de arquivos, além de fornecer recursos avançados de processamento de imagens.
5. Consistência dos dados: Para garantir a consistência dos dados, a aplicação utiliza o LocalStorage no navegador. O LocalStorage é uma forma de armazenamento de dados local no cliente, o que significa que as informações do usuário são armazenadas no próprio dispositivo. Essa abordagem distribuída permite que os dados sejam acessíveis mesmo quando houver uma desconexão temporária ou perda de conexão com a internet. Assim, os usuários podem continuar a usar a aplicação e visualizar suas informações mesmo em situações de conectividade instável.

Em resumo, a aplicação de chat em tempo real se encaixa na definição de sistemas distribuídos por meio da comunicação entre componentes distribuídos, escalabilidade

## Arquitetura do sistema

![image](https://github.com/felipolis/Talk-In-Clouds/blob/main/arquitetura.png?raw=true)

## Interface de Serviço

As solicitações e respostas descritas são exemplos de requisições HTTP em uma API de bate-papo (chat). Vou explicar cada uma delas em detalhes:

1. CADASTRO:

   - Requisição:
     - Método: POST
     - URL: http://localhost:5000/api/v1/user/signup
     - Cabeçalhos:
       - "Content-Type": "application/json"
     - Corpo:
       ```
       {
         "name": "<NAME>",
         "email": "<EMAIL>",
         "password": "<PASSWORD>",
         "confirmPassword": "<CONFIRM_PASSWORD>"
       }
       ```
   - Resposta:
     ```
     {
       "_id": "<ID>",
       "name": "<NAME>",
       "email": "<EMAIL>",
       "pic": "<URL>",
       "token": <TOKEN>
     }
     ```
   - Explicação: Essa solicitação é usada para cadastrar um novo usuário na plataforma de bate-papo. O cliente faz uma solicitação POST com os detalhes do usuário no corpo da requisição. A resposta contém os detalhes do usuário recém-criado, incluindo um ID único, nome, email, URL de imagem (pic) e um token de autenticação.
2. LOGIN:

   - Requisição:
     - Método: POST
     - URL: http://localhost:5000/api/v1/user/signin
     - Cabeçalhos:
       - "Content-Type": "application/json"
     - Corpo:
       ```
       {
         "email": "<EMAIL>",
         "password": "<PASSWORD>"
       }
       ```
   - Resposta:
     ```
     {
       "_id": "<ID>",
       "name": "<NAME>",
       "email": "<EMAIL>",
       "pic": "<URL>",
       "token": <TOKEN>
     }
     ```
   - Explicação: Essa solicitação é usada para autenticar um usuário existente. O cliente envia o email e senha do usuário no corpo da requisição. Se as credenciais estiverem corretas, a resposta retornará os detalhes do usuário autenticado, incluindo um ID único, nome, email, URL de imagem (pic) e um token de autenticação.
3. BUSCAR USUÁRIOS:

   - Requisição:
     - Método: GET
     - URL: http://localhost:5000/api/v1/user?search=`<SEARCH>`
     - Cabeçalhos:
       - "Content-Type": "application/json"
       - "Authorization": "`Bearer <TOKEN>`"
     - Corpo: vazio
   - Resposta:
     ```
     [<USERS>]
     ```
   - Explicação: Essa solicitação é usada para buscar usuários na plataforma de bate-papo. O cliente faz uma solicitação GET para a URL especificada, fornecendo um parâmetro de pesquisa (search) para filtrar os usuários. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna uma lista de usuários correspondentes aos critérios de pesquisa.
4. CRIAR OU ACESSAR UM CHAT ENTRE DUAS PESSOAS:

   - Requisição:
     - Método: POST
     - URL: http://localhost:5000/api/v1/chat
     - Cabeçalhos:
       - "Content-Type": "application/json"
       - "Authorization": `Bearer <TOKEN>`
     - Corpo:
       ```
       {
         "userId": "<USER_ID>"
       }
       ```
   - Resposta:
     ```
     {
       "_id": "<ID>",
       "chatName": "<CHAT_NAME>",
       "isGroupChat": <FALSE>,
       "users": [<USERS>],
       "createdAt": "<DATE>",
       "updatedAt": "<DATE>"
     }
     ```
   - Explicação: Essa solicitação é usada para criar ou acessar um chat entre duas pessoas. O cliente faz uma solicitação POST com o ID do usuário no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. Se o chat entre as duas pessoas já existir, a resposta retornará os detalhes do chat. Caso contrário, um novo chat será criado com um ID único, nome do chat (chatName), indicador de chat em grupo (isGroupChat), lista de usuários participantes (users), data de criação (createdAt) e data de atualização (updatedAt).
5. BUSCAR CHATS:

   - Requisição:
     - Método: GET
     - URL: http://localhost:5000/api/v1/chat
     - Cabeçalhos:
       - "Content-Type": "application/json"
       - "Authorization": `Bearer <TOKEN>`
     - Corpo: vazio
   - Resposta:
     ```
     [<CHATS>]
     ```
   - Explicação: Essa solicitação é usada para buscar todos os chats do usuário na plataforma de bate-papo. O cliente faz uma solicitação GET para a URL especificada. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna uma lista de chats aos quais o usuário pertence.
6. CRIAR UM GRUPO A PARTIR DE 3 PESSOAS:

   - Requisição:
     - Método: POST
     - URL: http://localhost:5000/api/v1/chat/group
     - Cabeçalhos:
       - "Content-Type": "application/json"
       - "Authorization": `Bearer <TOKEN>`
     - Corpo:
       ```
       {
         "name": "<NAME>",
         "users": "[<USER_IDS>]"
       }
       ```
   - Resposta:
     ```
     {
       "_id": "<ID>",
       "chatName": "<CHAT_NAME>",
       "isGroupChat": <TRUE>,
       "users": [<USERS>],
       "createdAt": "<DATE>",
       "updatedAt": "<DATE>"
     }
     ```
   - Explicação: Essa solicitação é usada para criar um grupo de chat com três ou mais pessoas. O cliente faz uma solicitação POST com o nome do grupo (name) e uma lista de IDs de usuários participantes (users) no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna os detalhes do grupo criado, incluindo um ID único, nome do chat (chatName), indicador de chat em grupo (isGroupChat), lista de usuários participantes (users), data de criação (createdAt) e data de atualização (updatedAt).
7. RENOMEAR UM GRUPO:

   - Requisição:
     - Método: PUT
     - URL: http://localhost:5000/api/v1/chat/rename
     - Cabeçalhos:
       - "Content-Type": "application/json"
       - "Authorization": `Bearer <TOKEN>`
     - Corpo:
       ```
       {
         "chatId": "<CHAT_ID>",
         "chatName": "<CHAT_NAME"
       }

       ```
   - Resposta:
     ```
     {
       "_id": "<ID>",
       "chatName": "<CHAT_NAME>",
       "isGroupChat": <TRUE>,
       "users": [<USERS>],
       "createdAt": "<DATE>",
       "updatedAt": "<DATE>"
     }
     ```
   - Explicação: Essa solicitação é usada para renomear um grupo de chat. O cliente faz uma solicitação PUT com o ID do chat (chatId) e o novo nome do chat (chatName) no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna os detalhes do grupo de chat atualizado, incluindo o ID único, nome do chat (chatName), indicador de chat em grupo (isGroupChat), lista de usuários participantes (users), data de criação (createdAt) e data de atualização (updatedAt).
8. ADICIONAR UM NOVO USUÁRIO AO GRUPO:

   - Requisição:
     - Método: PUT
     - URL: http://localhost:5000/api/v1/chat/groupadd
     - Cabeçalhos:
       - "Content-Type": "application/json"
       - "Authorization": `Bearer <TOKEN>`
     - Corpo:
       ```
       {
         "chatId": "<CHAT_ID>",
         "userId": "<USER_ID>"
       }
       ```
   - Resposta:
     ```
     {
       "_id": "<ID>",
       "chatName": "<CHAT_NAME>",
       "isGroupChat": <TRUE>,
       "users": [<USERS>],
       "createdAt": "<DATE>",
       "updatedAt": "<DATE>"
     }
     ```
   - Explicação: Essa solicitação é usada para adicionar um novo usuário a um grupo de chat existente. O cliente faz uma solicitação PUT com o ID do chat (chatId) e o ID do usuário a ser adicionado (userId) no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna os detalhes do grupo de chat atualizado, incluindo o ID único, nome do chat (chatName), indicador de chat em grupo (isGroupChat), lista de usuários participantes (users), data de criação (createdAt) e data de atualização (updatedAt).
9. REMOVER UM USUÁRIO DO GRUPO:

   - Requisição:
     - Método: PUT
     - URL: http://localhost:5000/api/v1/chat/groupremove
     - Cabeçalhos:
       - "Content-Type": "application/json"
       - "Authorization": `Bearer <TOKEN>`
     - Corpo:
       ```
       {
         "chatId": "<CHAT_ID>",
         "userId": "<USER_ID>"
       }
       ```
   - Resposta:
     ```
     {
       "_id": "<ID>",
       "chatName": "<CHAT_NAME>",
       "isGroupChat": <TRUE>,
       "users": [<USERS>],
       "createdAt": "<DATE>",
       "updatedAt": "<DATE>"
     }
     ```
   - Explicação: Essa solicitação é usada para remover um usuário de um grupo de chat existente. O cliente faz uma solicitação PUT com o ID do chat (chatId) e o ID do usuário a ser removido (userId) no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna os detalhes do grupo de chat atualizado, incluindo o ID único, nome do chat (chatName), indicador de chat em grupo (isGroupChat), lista de usuários participantes (users), data de criação (createdAt) e data de atualização (updatedAt).
10. BUSCAR TODAS AS MENSAGENS DE UM DETERMINADO CHAT:

    - Requisição:
      - Método: GET
      - URL: http://localhost:5000/api/v1/message/:<CHAT_ID>
      - Cabeçalhos:
        - "Content-Type": "application/json"
        - "Authorization": `Bearer <TOKEN>`
      - Corpo: vazio
    - Resposta:
      ```
      [<MESSAGE>]
      ```
    - Essa solicitação é usada para buscar todas as mensagens de um chat específico. O cliente faz uma solicitação GET para a URL especificada, onde <CHAT_ID> é substituído pelo ID único do chat desejado. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna uma lista de todas as mensagens (`<MESSAGES>`) associadas ao chat.
11. ENVIAR UMA NOVA MENSAGEM:

    - Requisição:
      - Método: POST
      - URL: http://localhost:5000/api/v1/message
      - Cabeçalhos:
        - "Content-Type": "application/json"
        - "Authorization": `Bearer <TOKEN>`
      - Corpo:
        ```
        {
          "content": "<CONTENT>",
          "chatId": "<CHAT_ID>"
        }
        ```
    - Resposta:
      ```
      {
        "_id": "<ID>",
        "sender": "<USER>",
        "content": "<CONTENT>",
        "chat": "<CHAT>",
        "createdAt": "<DATE>",
        "updatedAt": "<DATE>"
      }
      ```
    - Explicação: Essa solicitação é usada para enviar uma nova mensagem para um chat específico. O cliente faz uma solicitação POST com o conteúdo da mensagem (content) e o ID do chat (chatId) no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna os detalhes da mensagem enviada, incluindo o ID único, remetente (sender), conteúdo (content), chat associado (chat), data de criação (createdAt) e data de atualização (updatedAt).
12. BUSCAR TODAS AS NOTIFICAÇÕES:

    - Requisição:
      - Método: GET
      - URL: http://localhost:5000/api/v1/notification
      - Cabeçalhos:
        - "Content-Type": "application/json"
        - "Authorization": `Bearer <TOKEN>`
      - Corpo: vazio
    - Resposta:
      ```
      [<NOTIFICATION>]
      ```
    - Explicação: Essa solicitação é usada para buscar todas as notificações do usuário. O cliente faz uma solicitação GET para a URL especificada. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna os detalhes da notificação, incluindo o ID único, remetente (sender), destinatário (receiver), conteúdo (content), chat associado (chat), data de criação (createdAt) e data de atualização (updatedAt).
13. ENVIAR NOTIFICAÇÃO:

    - Requisição:
      - Método: POST
      - URL: http://localhost:5000/api/v1/notification
      - Cabeçalhos:
        - "Content-Type": "application/json"
        - "Authorization": `Bearer <TOKEN>`
      - Corpo:
        ```
        {
          "content": "<CONTENT>",
          "receiverId": "<RECEIVER_ID>",
          "chatId": "<CHAT_ID>"
        }
        ```
    - Resposta:
      ```
      {
        "message": "<MESSAGE>"
      }
      ```
    - Explicação: Essa solicitação é usada para enviar uma nova notificação para um usuário específico. O cliente faz uma solicitação POST com o conteúdo da notificação (content), o ID do destinatário (receiverId) e o ID do chat associado (chatId) no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna uma mensagem indicando o sucesso do envio da notificação.
14. DELETAR NOTIFICAÇÕES:

    - Requisição:
      - Método: DELETE
      - URL: http://localhost:5000/api/v1/notification
      - Cabeçalhos:
        - "Content-Type": "application/json"
        - "Authorization": `Bearer <TOKEN>`
      - Corpo:
        ```
        {
          "receiverId": "<RECEIVER_ID>",
          "chatId": "<CHAT_ID>"
        }
        ```
    - Resposta:
      ```
      {
        "message": "<MESSAGE>"
      }
      ```
    - Explicação: Essa solicitação é usada para deletar as notificações de um usuário em um chat específico. O cliente faz uma solicitação DELETE com o ID do chat (chatId) e o ID do destinatário (receiverId) no corpo da requisição. O cabeçalho inclui um token de autenticação para autorização. A resposta retorna uma mensagem indicando o sucesso da exclusão das notificações.

##### Client:

> /client
>
>> /src
>>
>>> /animations
>>>
>>>> typing.json
>>>>
>>>
>>> /api
>>>
>>>> /client
>>>>
>>>>> private.client.js
>>>>>
>>>>> public.client.js
>>>>>
>>>>
>>>> /modules
>>>>
>>>>> chat.api.js
>>>>>
>>>>> message.api.js
>>>>>
>>>>> notification.api.js
>>>>>
>>>>> user.api.js
>>>>>
>>>>
>>>
>>> /components
>>>
>>>> Register.jsx
>>>>
>>>> Login.jsx
>>>>
>>>> Navbar.jsx
>>>>
>>>> ChatLoading.jsx
>>>>
>>>> ProfileModal.jsx
>>>>
>>>> UserListItem.jsx
>>>>
>>>> MyChats.jsx
>>>>
>>>> GroupChatModal.jsx
>>>>
>>>> UserBadgeItem.jsx
>>>>
>>>> ChatBox.jsx
>>>>
>>>> SingleChat.jsx
>>>>
>>>> ScrollableChat.jsx
>>>>
>>>> UpdateGroupChatModal.jsx
>>>>
>>>> styles.css
>>>>
>>>
>>> /config
>>>
>>>> ChatLogics.js
>>>>
>>>
>>> /context
>>>
>>>> ChatProvider.jsx
>>>>
>>>
>>> /pages
>>>
>>>> HomePage.jsx
>>>>
>>>> ChatPage.jsx
>>>>
>>>
>>> App.jsx
>>>
>>> App.css
>>>
>>> index.jsx
>>>
>>> index.css
>>>
>>
>> .env
>>
>> package.json
>>

##### Server:

> /server
>
>> /src
>>
>>> /middlewares
>>>
>>>> token.middleware.js
>>>>
>>>
>>> /handlers
>>>
>>>> request.handler.js
>>>>
>>>> response.handler.js
>>>>
>>>
>>> /models
>>>
>>>> model.options.js
>>>>
>>>> user.model.js
>>>>
>>>> chat.model.js
>>>>
>>>> message.model.js
>>>>
>>>> notification.model.js
>>>>
>>>
>>> /routes
>>>
>>>> index.js
>>>>
>>>> user.route.js
>>>>
>>>> chat.route.js
>>>>
>>>> message.route.js
>>>>
>>>> notification.route.js
>>>>
>>>
>>> /controllers
>>>
>>>> user.controller.js
>>>>
>>>> chat.controller.js
>>>>
>>>> message.controller.js
>>>>
>>>> notification.controller.js
>>>>
>>>
>>
>> index.js
>>
>> .env
>>
>> package.json
>>

## Explicação detalhada

**/client/.env.example:** O arquivo .env.example localizado na pasta /client é um exemplo de arquivo de ambiente para um aplicativo cliente baseado em React. Esse tipo de arquivo é usado para armazenar variáveis de ambiente que podem ser acessadas durante o desenvolvimento do aplicativo. Nesse exemplo, há três variáveis de ambiente definidas: REACT_APP_API_URL, REACT_APP_SOCKET_URL e REACT_APP_CLOUDINARY_URL. Essas variáveis são usadas para armazenar as URLs da API, do socket e do serviço de hospedagem de imagens do Cloudinary, respectivamente. No arquivo de exemplo, as variáveis estão vazias, pois é apenas um modelo para orientar o desenvolvedor sobre quais variáveis devem ser definidas e preenchidas com as URLs corretas. Durante o desenvolvimento, o arquivo .env.example é copiado para um arquivo .env real, onde as variáveis de ambiente são definidas com os valores apropriados. Dessa forma, o aplicativo cliente pode acessar as URLs necessárias para se comunicar com a API, o socket e o serviço de hospedagem de imagens. A lógica por trás desse arquivo é fornecer um modelo para as variáveis de ambiente e garantir que as informações sensíveis, como as URLs, não sejam expostas no repositório do código-fonte.

**/client/src/animations/typing.json**: é um arquivo de animação no formato JSON.

**/client/src/api/client/private.client.js:** O arquivo "private.client.js" é um módulo JavaScript que configura e exporta um cliente para fazer requisições HTTP em uma API privada. Ele utiliza a biblioteca "axios" para lidar com as requisições e "queryString" para serializar os parâmetros. O cliente é configurado com uma URL base que é obtida da variável de ambiente "REACT_APP_API_URL" ou, caso não esteja definida, usa a URL padrão "http://127.0.0.1:5000/api/v1". O cliente também define interceptors, que são funções que são executadas antes de cada requisição ou após cada resposta. No interceptor de requisição, é adicionado um cabeçalho com o tipo de conteúdo e um token de autorização, que é obtido do armazenamento local do navegador. O interceptor de resposta retorna os dados da resposta ou lança um erro com os dados da resposta de erro. O cliente é exportado para ser usado em outros arquivos do projeto. Em resumo, o arquivo configura um cliente HTTP personalizado com cabeçalhos de autenticação para interagir com uma API.

**/client/src/api/client/public.client.js:** O arquivo "public.client.js" é um módulo JavaScript que configura e exporta um cliente para fazer requisições HTTP em uma API pública. Assim como o arquivo anterior, ele utiliza a biblioteca "axios" para lidar com as requisições e "queryString" para serializar os parâmetros. O cliente é configurado com uma URL base que é obtida da variável de ambiente "REACT_APP_API_URL" ou, caso não esteja definida, usa a URL padrão "http://127.0.0.1:5000/api/v1". O cliente não possui interceptors para autenticação, portanto não adiciona cabeçalhos de autorização nas requisições. O interceptor de resposta retorna os dados da resposta ou lança um erro com os dados da resposta de erro. O cliente é exportado para ser usado em outros arquivos do projeto. Em resumo, o arquivo configura um cliente HTTP personalizado para interagir com uma API pública, sem a necessidade de autenticação.

**/client/src/api/modules/user.api.js:** O arquivo "user.api.js" é um módulo JavaScript que define e exporta um conjunto de funções relacionadas à API de usuários. Ele importa os clientes personalizados "privateClient" e "publicClient" de outros arquivos, que foram explicados anteriormente. O objeto "userEndpoints" contém os endpoints da API relacionados aos usuários, como o endpoint de login, cadastro e obtenção de usuários. Em seguida, o objeto "userApi" contém três funções assíncronas: "signup" para realizar o cadastro de um novo usuário, "signin" para realizar o login de um usuário existente e "getUsers" para obter usuários com base em um parâmetro de pesquisa. Cada função faz uma chamada à API utilizando o cliente apropriado (público ou privado) e os endpoints correspondentes. Em caso de sucesso, a função retorna um objeto com a resposta da API. Em caso de erro, a função captura o erro e o imprime no console, retornando um objeto com o erro. O objeto "userApi" é exportado para ser usado em outros arquivos do projeto. Em resumo, o arquivo encapsula as chamadas à API relacionadas aos usuários, utilizando os clientes personalizados e endpoints específicos para cada operação.

**/client/src/api/modules/chat.api.js:** O arquivo "chat.api.js" é um módulo JavaScript que define e exporta um conjunto de funções relacionadas à API de bate-papo. Ele importa o cliente personalizado "privateClient" de outro arquivo, que foi explicado anteriormente. O objeto "chatEndpoints" contém os endpoints da API relacionados ao bate-papo, como obtenção de chats, acesso a um chat específico, criação de chat em grupo, renomeação de grupo, remoção de um usuário de um grupo e adição de um usuário a um grupo. Em seguida, o objeto "chatApi" contém várias funções assíncronas, cada uma correspondendo a uma operação relacionada ao bate-papo. Cada função faz uma chamada à API utilizando o cliente privado e o endpoint correspondente. Elas passam os parâmetros necessários para a API, como o ID do usuário, nome do grupo, ID do chat, etc. Em caso de sucesso, a função retorna um objeto com a resposta da API. Em caso de erro, a função captura o erro e o imprime no console, retornando um objeto com o erro. O objeto "chatApi" é exportado para ser usado em outros arquivos do projeto. Em resumo, o arquivo encapsula as chamadas à API relacionadas ao bate-papo, utilizando o cliente privado e endpoints específicos para cada operação.

**/client/src/api/modules/message.api.js:** O arquivo "message.api.js" é um módulo JavaScript que define e exporta um conjunto de funções relacionadas à API de mensagens. Ele importa o cliente personalizado "privateClient" de outro arquivo, que foi explicado anteriormente. O objeto "messageEndpoints" contém os endpoints da API relacionados às mensagens, como obtenção de mensagens de um chat específico e envio de uma nova mensagem. O endpoint de obtenção de mensagens requer o parâmetro "chatId" para identificar o chat do qual as mensagens devem ser obtidas. Em seguida, o objeto "messageApi" contém duas funções assíncronas: "fetchMessages" para obter as mensagens de um chat específico e "sendMessage" para enviar uma nova mensagem para um chat. Cada função faz uma chamada à API utilizando o cliente privado e os endpoints correspondentes. Elas passam os parâmetros necessários para a API, como o conteúdo da mensagem e o ID do chat. Em caso de sucesso, a função retorna um objeto com a resposta da API. Em caso de erro, a função captura o erro e o imprime no console, retornando um objeto com o erro. O objeto "messageApi" é exportado para ser usado em outros arquivos do projeto. Em resumo, o arquivo encapsula as chamadas à API relacionadas às mensagens, utilizando o cliente privado e endpoints específicos para obter e enviar mensagens.

**/client/src/App.jsx:** O arquivo "App.jsx" é o componente principal da aplicação e define o roteamento das páginas utilizando o pacote "react-router-dom". Ele estabelece as rotas para a página inicial e a página de chats, representadas pelos componentes HomePage e ChatPage, respectivamente. Através da utilização da componente "Routes", é possível mapear as URLs para os componentes correspondentes, permitindo a renderização correta da página com base na rota acessada. Em resumo, o arquivo App.jsx é responsável por gerenciar o roteamento e a renderização das páginas da aplicação, proporcionando a navegação adequada entre os diferentes conteúdos.

**/client/src/index.jsx:** O arquivo "index.jsx" é o ponto de entrada da aplicação React. Ele importa as dependências necessárias, como React, ReactDOM e estilos CSS, e define a estrutura da aplicação. Através da função render do ReactDOM, o componente principal da aplicação, App, é renderizado dentro de uma hierarquia de provedores de contexto, incluindo ChatProvider e ChakraProvider. Além disso, o BrowserRouter é utilizado para gerenciar o roteamento da aplicação. Em resumo, o arquivo index.jsx configura a renderização do componente principal, juntamente com os provedores de contexto e o roteamento necessários para o funcionamento correto da aplicação React.

**/client/src/pages/HomePage.jsx:** O arquivo "HomePage.jsx" é responsável por definir a página inicial da aplicação. Ele importa os componentes Login e Register, que são responsáveis pelos formulários de login e registro, respectivamente. A página é composta por um contêiner centralizado, que contém um cabeçalho com o nome da aplicação "Talk-In-Clouds" e uma área de conteúdo principal. A área de conteúdo principal é composta por abas (Tabs) que permitem alternar entre as opções de login e registro. Cada aba exibe o componente correspondente: Login ou Register. Ao clicar em uma das abas, o respectivo formulário é exibido na área de conteúdo principal. A página utiliza estilos e componentes do Chakra UI, como Box, Container, Tab, TabList, TabPanel e TabPanels, para criar a estrutura visual da página. Através do hook useNavigate do react-router-dom, é possível navegar entre as páginas da aplicação. Em resumo, o arquivo HomePage.jsx define a estrutura e o comportamento da página inicial, incluindo os formulários de login e registro.

**/client/src/pages/ChatPage.jsx:** O arquivo "ChatPage.jsx" é responsável por definir a página de bate-papo da aplicação. Ele importa componentes como Box, useState e ChatState do Chakra UI, react, e ChatProvider, bem como os componentes ChatBox, MyChats e Navbar. A página é composta por um contêiner principal que ocupa toda a largura da página. Dentro desse contêiner, há uma verificação para exibir a barra de navegação (Navbar) somente se houver um usuário logado. Em seguida, há um contêiner flexível (Box) que ocupa a maior parte da altura da página (92vh). Dentro desse contêiner, são renderizados os componentes MyChats e ChatBox, que são responsáveis pela exibição dos chats disponíveis e pela caixa de bate-papo, respectivamente. A variável "user" é obtida através do hook ChatState, que faz parte do contexto do chat. Além disso, a variável de estado "fetchAgain" e a função "setFetchAgain" são utilizadas para controlar o comportamento de atualização dos chats. Em resumo, o arquivo ChatPage.jsx define a estrutura e o comportamento da página de bate-papo, exibindo os componentes necessários para a interação do usuário com os chats disponíveis.

**/client/src/components/Register.jsx:** O arquivo "Register.jsx" trata-se de um componente que implementa o formulário de registro em uma aplicação. Ele é responsável por capturar os dados inseridos pelo usuário, como nome, email, senha e foto de perfil. Além disso, o componente realiza validações nos campos, exibe mensagens de aviso ou sucesso e faz o upload da foto para um serviço de hospedagem. Ao clicar no botão de registro, os dados são enviados para o backend e, em caso de sucesso, o usuário é redirecionado para a página de chats. Em suma, o componente Register.jsx desempenha um papel crucial no processo de registro de novos usuários na aplicação.

**/client/src/components/Login.jsx:** O arquivo "Login.jsx" é um componente responsável por exibir o formulário de login em uma aplicação. Ele captura as informações inseridas pelo usuário, como o email e a senha, e realiza validações nos campos. Quando o usuário clica no botão de login, as informações são enviadas para o backend e são feitas verificações. Em caso de sucesso, o usuário é redirecionado para a página de chats. O componente também inclui um botão para exibir ou ocultar a senha e um botão para preencher automaticamente os campos com as credenciais de um usuário convidado. O componente utiliza hooks do React, como useState e useToast, para gerenciar o estado dos campos e exibir mensagens de aviso ou sucesso. Em resumo, o componente Login.jsx desempenha um papel essencial no processo de autenticação e acesso do usuário à aplicação.

**/client/src/components/Navbar.jsx:** O arquivo Navbar.jsx, localizado no diretório /client/src/components, é um componente de barra de navegação utilizado na interface do usuário. Ele importa várias dependências e componentes do Chakra UI, React e outras bibliotecas. A lógica do componente envolve a criação da barra de navegação com botões de pesquisa, notificações, perfil do usuário e opção de logout. O componente também inclui um drawer (gaveta) para exibir os resultados da pesquisa de usuários, permitindo ao usuário interagir com eles e acessar as conversas correspondentes. Ele faz uso do contexto ChatState para obter informações sobre o usuário, notificações e chats. O componente também possui funções para lidar com a pesquisa de usuários, o acesso a uma conversa específica e o logout.

**/client/src/components/ChatLoading.jsx:** O arquivo "ChatLoading.jsx" é um componente que exibe uma animação de carregamento em forma de esqueletos para simular o carregamento de conteúdo em um chat. Ele cria uma pilha vertical de esqueletos que representam mensagens e têm uma altura fixa. Essa abordagem visual indica que o conteúdo está sendo carregado enquanto os dados reais do chat são processados.

**/client/src/components/ProfileModal.jsx:** O arquivo "ProfileModal.jsx" é um componente que exibe o perfil de um usuário em um modal. Ele pode ser acionado por meio de um botão ou qualquer outro elemento que seja passado como filho do componente. O modal exibe o nome do usuário, uma imagem de perfil e o endereço de e-mail correspondente. Ao abrir o modal, ele é exibido centralizado na tela e possui um botão "Fechar" para permitir que o usuário o feche quando necessário. A lógica do componente envolve o uso do hook useDisclosure para controlar o estado de abertura e fechamento do modal. Quando o usuário clica no botão ou no elemento filho, o modal é aberto, exibindo as informações do usuário. O componente usa os componentes do Chakra UI, como Modal, ModalOverlay, ModalContent, ModalHeader, ModalBody, ModalCloseButton, ModalFooter, Button, IconButton, Text e Image, para criar a estrutura e o estilo do modal.

**/client/src/components/UserListItem.jsx:** O arquivo "UserListItem.jsx" é um componente que exibe informações de um usuário em um formato de item da lista. Ele renderiza um avatar do usuário, seu nome e seu endereço de e-mail. Além disso, o componente é interativo, permitindo que o usuário clique nele e execute uma determinada função, que é passada como propriedade para o componente. Ao ser clicado, o item da lista muda de cor e destaca-se visualmente para fornecer feedback visual ao usuário. A lógica do componente é simples: renderizar as informações do usuário em um formato visualmente agradável e permitir a interação com o item da lista através do clique, ativando a função especificada.

**/client/src/components/MyChats.jsx:** O arquivo MyChats.jsx, localizado no diretório /client/src/components, é um componente responsável por exibir a lista de chats do usuário na interface do usuário. Ele importa várias dependências e componentes do Chakra UI, React e outras bibliotecas. A lógica do componente envolve a recuperação dos chats do usuário, exibição dos chats na lista, atualização do chat selecionado e a opção de criar um novo grupo de chat. O componente utiliza o contexto ChatState para obter informações sobre o usuário, chats e o chat selecionado. Ele também possui funções para recuperar os chats do usuário, exibir uma mensagem de erro caso ocorra algum problema e atualizar a lista de chats sempre que necessário. A lista de chats é exibida com informações como nome do remetente, última mensagem e imagem do perfil.

**/client/src/components/GroupChatModal.jsx:** O arquivo "GroupChatModal.jsx" é um componente responsável por exibir um modal de criação de grupo de chat. Ele permite que os usuários insiram o nome do chat, adicionem membros ao grupo e visualizem os resultados da pesquisa de usuários. O componente faz chamadas à API para obter os resultados da pesquisa e criar o grupo de chat. Ao submeter o formulário com sucesso, o componente atualiza o estado dos chats e exibe uma mensagem de sucesso. Ele oferece uma interface intuitiva e funcional para a criação de grupos de chat, tornando a interação e organização em conversas em grupo mais eficientes.

**/client/src/components/UserBadgeItem.jsx:** O arquivo "UserBadgeItem.jsx" é um componente que representa um distintivo de usuário em um grupo de chat. O componente recebe como propriedades o objeto do usuário, uma função de manipulação e o ID do administrador do grupo. O componente renderiza um distintivo usando o componente Badge do Chakra UI, exibindo o nome do usuário. Se o usuário for o administrador do grupo, é exibida uma indicação "(Admin)". Ao lado do nome do usuário, é exibido um ícone de fechar representado pelo componente CloseIcon. O componente é estilizado com propriedades como espaçamento, borda arredondada, esquema de cores e tamanho de fonte. Quando o distintivo é clicado, a função de manipulação passada como propriedade é chamada. O componente permite a exibição e interação com os usuários do grupo de chat, incluindo a identificação do administrador e a capacidade de removê-los do grupo.

**/client/src/components/ChatBox.jsx:** O arquivo ChatBox.jsx, localizado no diretório /client/src/components, é um componente responsável por exibir a caixa de chat na interface do usuário. Ele importa o componente SingleChat e o contexto ChatState do diretório correspondente. O componente ChatBox recebe as propriedades fetchAgain e setFetchAgain, que são usadas para atualizar o estado e forçar a recuperação dos dados do chat. A lógica do componente envolve exibir a caixa de chat apenas quando um chat específico é selecionado, o que é determinado pela variável selectedChat do contexto ChatState. Dentro da caixa de chat, o componente SingleChat é renderizado, recebendo as propriedades fetchAgain e setFetchAgain. Essas propriedades são repassadas para que o componente SingleChat possa atualizar o estado e forçar a recuperação dos dados do chat sempre que necessário.

**/client/src/components/SingleChat.jsx:** O arquivo SingleChat.jsx é um componente que faz parte da implementação de um sistema de chat em uma aplicação. Ele é responsável por exibir a interface de chat para uma conversa individual, permitindo aos usuários enviar e receber mensagens, visualizar notificações, verificar o status online/offline de outros participantes da conversa, entre outras funcionalidades. O componente utiliza diversos estados e efeitos para gerenciar o carregamento das mensagens, o envio de novas mensagens, a detecção de digitação e a atualização dinâmica da interface. Ele também se comunica com um servidor WebSocket para receber atualizações em tempo real, como novas mensagens e alterações no status dos usuários. Em resumo, o arquivo SingleChat.jsx desempenha um papel fundamental na implementação de uma experiência de chat interativa e dinâmica na aplicação.

**/client/src/components/ScrollableChat.jsx:** O arquivo "ScrollableChat.jsx" é um componente responsável por exibir uma lista de mensagens de chat em uma área com rolagem vertical. O componente itera sobre o array de mensagens recebido como propriedade e renderiza cada mensagem, exibindo o Avatar do remetente ao lado da mensagem correspondente. Ele também utiliza estilizações condicionais para diferenciar as mensagens enviadas pelo próprio usuário das mensagens enviadas por outros participantes, ajustando cores de fundo, cores de texto, margens e outros estilos. O componente permite uma experiência de chat interativa e visualmente agradável, facilitando a visualização e a rolagem das mensagens na interface.

**/client/src/components/UpdateGroupChatModal.jsx:** O arquivo "UpdateGroupChatModal.jsx" é um componente de uma aplicação que exibe um modal para atualização de um grupo de chat. Esse modal inclui informações sobre o grupo, como seu nome e participantes, e oferece funcionalidades para adicionar ou remover usuários do grupo. O componente utiliza diversos componentes do Chakra UI para construir o modal, como botões, campos de entrada e ícones. Ele também faz uso de estados para controlar o comportamento do modal, como o estado de abertura/fechamento, o nome do grupo, os resultados da busca por usuários e os estados de carregamento durante as operações. Além disso, o componente se comunica com APIs relacionadas a usuários e chats para realizar as ações de busca, adição e remoção de usuários, bem como a atualização do nome do grupo. Em resumo, o UpdateGroupChatModal é responsável por fornecer uma interface interativa para gerenciar os grupos de chat da aplicação.

**/client/src/config/ChatLogics.js:** O arquivo ChatLogics.js contém um conjunto de funções que fornecem a lógica necessária para exibir e manipular mensagens em um chat. Essas funções são responsáveis por determinar a formatação das mensagens, identificar remetentes, verificar se as mensagens são do mesmo remetente ou se são as últimas da lista, entre outras funcionalidades relacionadas. Elas desempenham um papel fundamental na apresentação adequada das mensagens e na obtenção das informações corretas sobre os remetentes envolvidos no chat. Essas funções são amplamente utilizadas em outros componentes do sistema de chat para garantir uma experiência de usuário coerente e intuitiva.

**/client/src/context/ChatProvider.jsx:** O arquivo ChatProvider.jsx é responsável por criar e fornecer um contexto de chat para o aplicativo React. Ele define o estado relacionado aos chats, usuário, notificações e fornece esse estado para os componentes filhos através do ChatContext.Provider. Além disso, o componente realiza a verificação do usuário no localStorage e gerencia a navegação entre as páginas. Dessa forma, outros componentes podem acessar e utilizar as informações do chat através do useContext(ChatContext). Esse arquivo desempenha um papel fundamental na organização e compartilhamento dos dados relacionados aos chats no aplicativo.

**/server/.env.example:** O arquivo .env.example é um modelo que serve como referência para a criação do arquivo de ambiente .env. Esse arquivo é comumente utilizado em projetos para armazenar variáveis de ambiente, como configurações sensíveis e chaves de acesso. No exemplo fornecido, temos três variáveis vazias: MONGODB_URL, PORT e TOKEN_SECRET_KEY. Essas variáveis são utilizadas para configurar a conexão com um banco de dados MongoDB, definir a porta em que o servidor será executado e definir a chave secreta usada para assinar e verificar tokens de autenticação, respectivamente. Ao copiar o arquivo .env.example e renomeá-lo para .env, é necessário preencher essas variáveis com os valores apropriados para que o sistema funcione corretamente. Isso permite separar as configurações específicas do ambiente do código-fonte, facilitando a manutenção e a segurança do sistema.

**/server.index.js:** O arquivo index.js localizado no diretório /server é o ponto de entrada principal do servidor Node.js. Ele configura o servidor HTTP utilizando o framework Express, define as rotas, realiza a conexão com o banco de dados MongoDB usando o Mongoose e configura o Socket.io para permitir a comunicação em tempo real. O arquivo inicializa o servidor na porta especificada, estabelece a conexão com o banco de dados e inicia o servidor Socket.io para lidar com eventos de comunicação entre os clientes. Essa implementação permite que o servidor receba solicitações HTTP, interaja com o banco de dados e facilite a troca de mensagens e notificações em tempo real entre os usuários conectados.

**/server/src/middlewares/token.middleware.js:** O arquivo token.middleware.js contém a implementação de um middleware responsável pela autenticação e validação do token de autenticação em requisições. Ele verifica se o token está presente no cabeçalho da requisição, decodifica-o utilizando a chave secreta definida em process.env.TOKEN_SECRET_KEY e, em seguida, verifica se o usuário associado ao token existe no banco de dados. Se o token for válido e o usuário existir, o middleware permite o fluxo normal da requisição, armazenando as informações do usuário no objeto req para uso posterior nas rotas. Caso contrário, o middleware retorna uma resposta de "unauthorized", indicando que o acesso não é permitido. Esse middleware é usado para proteger rotas e recursos que exigem autenticação, garantindo que apenas usuários autenticados tenham acesso.

**/server/src/handlers/request.handler.js:** O arquivo request.handler.js contém um handler responsável por validar os dados de uma requisição utilizando o pacote express-validator. O handler é um middleware que é inserido na cadeia de processamento das rotas e é executado antes da lógica principal da rota. A lógica do handler consiste em verificar se há erros de validação nos dados da requisição. Se houver erros, o handler retorna uma resposta com status 400 (Bad Request) e uma mensagem de erro contendo o primeiro erro da lista de validação. Caso contrário, se não houver erros de validação, o handler chama a função next() para prosseguir com o fluxo normal da requisição. Esse handler é útil para garantir que os dados recebidos nas requisições estejam de acordo com as regras de validação definidas, fornecendo feedback imediato em caso de erros e evitando o processamento de dados inválidos.

**/server/src/handlers/response.handler.js:** O arquivo response.handler.js contém um conjunto de funções para lidar com a geração de respostas HTTP padronizadas em uma aplicação. Cada função é responsável por retornar uma resposta com um status específico e um corpo de dados correspondente. A lógica dessas funções é simples: elas recebem o objeto de resposta (res), juntamente com os dados relevantes para a resposta, como o código de status e a mensagem, e chamam a função responseWithData para enviar a resposta completa ao cliente. As funções fornecidas incluem error para lidar com erros internos do servidor, badrequest para erros de solicitação inválida, ok para respostas bem-sucedidas, created para respostas de criação de recursos, unauthorize para respostas de não autorizado e notfound para recursos não encontrados. Essas funções auxiliam na padronização das respostas da API, facilitando o desenvolvimento e a manutenção do código.

**/server/src/models/model.options.js:** O arquivo model.options.js contém um objeto chamado modelOptions, que define as opções de configuração para um modelo de dados utilizado em um aplicativo. O objeto possui duas propriedades: versionKey e timestamps. A propriedade versionKey é definida como false, o que significa que o modelo não terá um campo adicional para controlar a versão do documento. A propriedade timestamps é definida como true, o que indica que o modelo terá campos de timestamp automáticos para registrar a data de criação e atualização de cada documento. Essas opções são comumente usadas em bancos de dados NoSQL, como o MongoDB, para fornecer informações adicionais sobre as versões e as datas de modificação dos documentos. Ao exportar o objeto modelOptions, ele pode ser importado e utilizado em outros arquivos relacionados à definição e manipulação de modelos de dados. Essa abordagem permite uma configuração centralizada e reutilizável das opções do modelo, facilitando a consistência e a manutenção do código.

**/server/src/models/user.model.js:** O arquivo user.model.js trata da definição do modelo de dados para usuários em um aplicativo usando o Mongoose, que é uma biblioteca do Node.js para interagir com bancos de dados MongoDB. O modelo possui campos como nome, email, foto de perfil, status de administrador, senha e salt (sequência aleatória de bytes). Além disso, o arquivo adiciona métodos personalizados ao esquema do usuário, como setPassword para definir e armazenar a senha criptografada e validPassword para verificar se uma senha fornecida corresponde à senha armazenada. Por meio do modelo User criado, é possível interagir com os dados dos usuários, como criar, atualizar, pesquisar e autenticar, de forma segura e organizada.

**/server/src/models/chat.model.js:** O arquivo chat.model.js trata da definição do modelo de dados para chats em um aplicativo utilizando o Mongoose, que é uma biblioteca do Node.js para interagir com bancos de dados MongoDB. O modelo possui campos como nome do chat, indicador se é um chat em grupo, referências aos usuários envolvidos no chat, referência à última mensagem enviada no chat e referência ao administrador do grupo, caso seja um chat em grupo. O arquivo utiliza o esquema do Mongoose para definir a estrutura do modelo, especificando os tipos de dados, opções de validação e as referências a outros modelos (User e Message). Além disso, é aplicado um conjunto de opções de modelo definidas no arquivo model.options.js. O modelo Chat criado permite interagir com os dados dos chats, como criar novos chats, adicionar usuários, definir a última mensagem e obter informações sobre o chat de forma coerente e organizada.

**/server/src/models/message.model.js:** O arquivo message.model.js trata da definição do modelo de dados para mensagens em um aplicativo utilizando o Mongoose. O modelo possui campos como o remetente da mensagem (referenciando o modelo User), o conteúdo da mensagem e o chat ao qual a mensagem pertence (referenciando o modelo Chat). O arquivo utiliza o esquema do Mongoose para definir a estrutura do modelo, especificando os tipos de dados, opções de validação e as referências a outros modelos (User e Chat). Além disso, é aplicado um conjunto de opções de modelo definidas no arquivo model.options.js. O modelo Message criado permite interagir com os dados das mensagens, como criar novas mensagens, associá-las a remetentes e chats específicos e acessar o conteúdo das mensagens de forma organizada. Isso possibilita o armazenamento e manipulação eficiente das mensagens no banco de dados MongoDB.

**/server/src/models/notification.model.js:** O arquivo notification.model.js trata da definição do modelo de dados para notificações em um aplicativo utilizando o Mongoose. O modelo possui campos como o remetente da notificação (referenciando o modelo User), o destinatário da notificação (também referenciando o modelo User), o conteúdo da notificação e o chat relacionado à notificação (referenciando o modelo Chat). O arquivo utiliza o esquema do Mongoose para definir a estrutura do modelo, especificando os tipos de dados, opções de validação e as referências a outros modelos (User e Chat). Além disso, é aplicado um conjunto de opções de modelo definidas no arquivo model.options.js. O modelo Notification criado permite interagir com os dados das notificações, como criar novas notificações, associá-las a remetentes, destinatários e chats específicos, e acessar o conteúdo das notificações de forma organizada. Isso possibilita o armazenamento e manipulação eficiente das notificações no banco de dados MongoDB.

**/server/src/routes/index.js:** O arquivo index.js localizado na pasta /src/routes trata das rotas principais do aplicativo. Ele importa as rotas específicas para usuários, chats, mensagens e notificações (user.route.js, chat.route.js, message.route.js, notification.route.js) e as associa a um objeto router do Express. Essas rotas são então configuradas usando o método use do objeto router, que define os caminhos de URL para cada rota específica. Por exemplo, a rota /user é associada à rota userRoute, a rota /chat é associada à rota chatRoute, e assim por diante. Dessa forma, quando o servidor recebe uma solicitação com um determinado caminho de URL, o Express encaminha essa solicitação para a rota correspondente definida nesse arquivo. Isso permite a separação e organização das diferentes funcionalidades do aplicativo em rotas distintas, facilitando a manutenção e escalabilidade do sistema.

**/server/src/routes/user.route.js:** O arquivo user.route.js contém as definições das rotas relacionadas aos usuários em um aplicativo. Ele utiliza o framework express para criar um objeto router que define as rotas para o registro (signup), autenticação (signin) e obtenção de usuários. O arquivo também utiliza o módulo express-validator para validar os dados recebidos nas requisições, como email, nome e senha. As rotas são protegidas pelo middleware tokenMiddleware.auth, que verifica a presença e validade do token de autenticação. Após a validação dos dados e autenticação, as rotas invocam os controladores correspondentes no userController para realizar as operações, como registro de usuário, autenticação e obtenção de usuários. Essas rotas permitem a interação com os recursos de usuário no aplicativo por meio de requisições HTTP, seguindo as regras de validação e autenticação estabelecidas.

**/server/src/routes/chat.route.js:** O arquivo chat.route.js é responsável por definir as rotas relacionadas aos chats no aplicativo. Ele utiliza o módulo express para criar um objeto router que define as rotas para acesso, criação e manipulação de chats. As rotas são protegidas por autenticação, verificando o token do usuário por meio do middleware tokenMiddleware.auth. O arquivo também utiliza o módulo express-validator para validar os dados recebidos nas requisições. As rotas POST são utilizadas para acessar um chat específico, criar um chat em grupo e adicionar usuários a um chat em grupo. As rotas GET são utilizadas para obter a lista de chats. As rotas PUT são utilizadas para renomear um chat em grupo e remover ou adicionar um usuário a um chat em grupo. Após a validação dos dados das requisições, as rotas chamam os controladores apropriados no chatController para realizar as operações correspondentes. Essas rotas permitem interagir com os recursos de chat no aplicativo por meio de requisições HTTP, como acessar um chat, criar chats em grupo, renomear e manipular membros de um chat em grupo.

**/server/src/routes/message.route.js:** O arquivo message.route.js contém as definições das rotas relacionadas às mensagens em um aplicativo. Ele utiliza o framework express para criar um objeto router que define as rotas para obtenção de todas as mensagens em um determinado chat (allMessages) e para o envio de uma nova mensagem (sendMessage). O arquivo também utiliza o módulo express-validator para validar os dados recebidos nas requisições, como o conteúdo da mensagem e o ID do chat. As rotas são protegidas pelo middleware tokenMiddleware.auth, que verifica a presença e validade do token de autenticação. Após a validação dos dados e autenticação, as rotas invocam os controladores correspondentes no messageController para realizar as operações, como obter todas as mensagens de um chat e enviar uma nova mensagem. Essas rotas permitem a interação com os recursos de mensagem no aplicativo por meio de requisições HTTP, seguindo as regras de validação e autenticação estabelecidas.

**/server/src/routes/notification.route.js:** O arquivo notification.route.js contém as definições das rotas relacionadas às notificações em um aplicativo. Ele utiliza o framework express para criar um objeto router que define as rotas para obtenção de todas as notificações (allNotifications), envio de uma nova notificação (sendNotification) e exclusão de notificações (deleteNotifications). O arquivo também utiliza o módulo express-validator para validar os dados recebidos nas requisições, como o conteúdo da notificação, o ID do destinatário e o ID do chat. As rotas são protegidas pelo middleware tokenMiddleware.auth, que verifica a presença e validade do token de autenticação. Após a validação dos dados e autenticação, as rotas invocam os controladores correspondentes no notificationController para realizar as operações, como obter todas as notificações, enviar uma nova notificação e excluir notificações. Essas rotas permitem a interação com os recursos de notificação no aplicativo por meio de requisições HTTP, seguindo as regras de validação e autenticação estabelecidas.

**/server/src/controllers/user.controller.js:** O arquivo user.controller.js contém os controladores responsáveis pelas operações relacionadas aos usuários em um aplicativo. O controlador signup cria um novo usuário, verificando se ele já existe no banco de dados e, em seguida, gera um token de autenticação para o usuário. O controlador signin lida com a autenticação de um usuário existente, verificando se o email e a senha correspondem. O controlador allUsers retorna todos os usuários do sistema, exceto o usuário atual, permitindo a busca por nome ou email. Esses controladores implementam a lógica necessária para manipular os dados do usuário, realizar autenticação e responder com as informações adequadas.

**/server/src/controllers/chat.controller.js:** O arquivo chat.controller.js contém os controladores responsáveis pelas operações relacionadas aos chats em um aplicativo. O controlador accessChat lida com o acesso a um chat entre dois usuários. Ele verifica se já existe um chat existente entre os usuários e, se existir, retorna o chat. Caso contrário, ele cria um novo chat e retorna o chat recém-criado. O controlador fetchChats recupera todos os chats de um usuário, popula os campos necessários e retorna os chats em ordem de atualização. Os controladores createGroupChat, renameGroup, removeFromGroup e addToGroup são responsáveis por criar grupos de chat, renomear grupos, remover usuários de grupos e adicionar usuários a grupos, respectivamente. Esses controladores implementam a lógica para manipular os chats, realizar operações de grupo e fornecer respostas adequadas aos usuários.

**/server/src/controllers/message.controller.js:** O arquivo message.controller.js contém os controladores responsáveis pelas operações relacionadas às mensagens em um aplicativo de chat. O controlador allMessages recupera todas as mensagens de um chat específico, com base no parâmetro chatId fornecido. Ele busca as mensagens no banco de dados, popula os campos necessários (como o remetente da mensagem e o chat associado) e retorna as mensagens. O controlador sendMessage lida com o envio de uma nova mensagem. Ele recebe o conteúdo da mensagem e o ID do chat, cria uma nova mensagem com base nesses dados e no usuário atualmente autenticado, salva a mensagem no banco de dados e retorna a mensagem enviada. Além disso, ele também atualiza a última mensagem do chat associado. Esses controladores implementam a lógica para manipular mensagens, realizar operações de busca e envio de mensagens e fornecer respostas adequadas aos usuários.

**/server/src/controllers/notification.controller.js:** O arquivo notification.controller.js contém os controladores responsáveis por lidar com as notificações em um aplicativo. O controlador allNotifications recupera todas as notificações destinadas ao usuário atualmente autenticado. Ele busca as notificações no banco de dados com base no ID do receptor, popula os campos necessários (como remetente, receptor e chat associado) e retorna as notificações. O controlador sendNotification lida com o envio de uma nova notificação. Ele recebe o conteúdo da notificação, o ID do receptor e o ID do chat associado. Em seguida, cria uma nova notificação com base nesses dados, salva-a no banco de dados e retorna uma resposta indicando o sucesso do envio. O controlador deleteNotifications lida com a exclusão de notificações de um determinado chat e receptor. Ele recebe o ID do chat e o ID do receptor, busca as notificações correspondentes no banco de dados e as exclui. Em seguida, retorna uma resposta indicando o sucesso da exclusão. Esses controladores implementam a lógica para recuperar, enviar e excluir notificações, além de fornecer respostas adequadas aos usuários.

## Como executar

##### Server

1. instalação das dependencias:

   ```bash
   $ cd server
   $ yarn
   ```
2. Configuração das variaveis de ambiente:

   ```bash
   $ cp .env.example .env
   ```

   ```
   MONGODB_URL="<MONGODB_URL>"
   PORT=<PORT>
   TOKEN_SECRET_KEY='<SECRET>'
   ```
3. Iniciar o servidor:

   ```bash
   $ yarn start
   ```

##### Client

1. Instalação das dependencias:

   ```bash
   $ cd client
   $ yarn
   ```
2. Configuração das variaveis de ambiente:

   ```bash
   $ cp .env.example .env
   ```

   ```
   REACT_APP_API_URL="<API_URL>"
   REACT_APP_SOCKET_URL="<SOCKET_URL>"
   REACT_APP_CLOUDINARY_URL="<CLOUDINARY_URL>"
   ```
3. Inicia o cliente:

   ```
   $ yarn start
   ```

***Made by Felipe Archanjo.***
