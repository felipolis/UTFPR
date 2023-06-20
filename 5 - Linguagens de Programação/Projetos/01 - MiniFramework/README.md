# Mini-Framework

### Objetivo

Geração automatica de formularios web

### Funcionamento

A partir da função register([obj1, obj2, obj3, ..., objN]), o framwork deverá gerar um frontend e um backend para a aplicação de geração automatica de formularios.

O frontend possui um arquivo index.html para representar a página principal, com links de formularios que representam cada uma das classes passadas como parametro para a função register(). Cada formulario tem seus campos de entrada de dados e um botão de enviar que faz uma requisição CREATE ao servidor.

O backend é composto por um servidor NodeJs com ExpressJs e Mongoose. Nesse sentido, para cada classe criada haverá um respectivo controller, model e route para o gerenciamento modular do projeto.

A estrutura de diretorios gerados deve ser a seguinte:

> /frontend
>
>> index.html
>>
>> style.css
>>
>> /forms
>>
>>> form1.html
>>>
>>> form2.html
>>>
>>> ...
>>>
>>> formN.html
>>>
>>> style.css
>>>
>>
>
> /backend
>
>> /src
>>
>>> /controllers
>>>
>>>> controller1.controller.js
>>>>
>>>> controller2.controller.js
>>>>
>>>> ...
>>>>
>>>> controllerN.controller.js
>>>>
>>>
>>> /models
>>>
>>>> model.options.js
>>>>
>>>> model1.model.js
>>>>
>>>> model2.model.js
>>>>
>>>> ...
>>>>
>>>> modelN.model.js
>>>>
>>>
>>> /routes
>>>
>>>> index.js
>>>>
>>>> route1.route.js
>>>>
>>>> route2.route.js
>>>>
>>>> ...
>>>>
>>>> routeN.route.js
>>>>
>>>
>>
>> .env
>>
>> index.js
>>
>> package.json
>>

### Requisitos

- Dart SDK v2.19.5
- NodeJs v18.13.0

### Como executar

1. Entre no diretório do script em dart e digite no terminal: `dart main.dart`
2. Abra o arquivo /backend/.env e coloque sua URL do banco de dados MongoDB e a porta de escuta do servidor NodeJs (5000)
3. No diretorio /backend, digite no terminal: `npm install`e depois `nodemon index.js` para iniciar o servidor.
4. Abra o arquivo index.html do diretorio /frontend e responda os formularios.

### Autores

- Felipe Archanjo da Cunha Mendes
- Bianca Miazaki
- João Tiago Mielli
