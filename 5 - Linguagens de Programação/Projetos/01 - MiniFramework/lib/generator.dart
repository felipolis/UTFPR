import 'reflexion.dart';
import 'dart:io'; // Biblioteca de entrada e saída

void register(List<Object> objetos) {

    // Cria o Frontend
    generateFrontend(objetos);

    // Cria o Backend
    generateBackend(objetos);
}

void generateFrontend(List<Object> objetos) {
    // Cria uma lista que recebe retornos da função inspecionarClasse
    List<Map<String, dynamic>> classes = [];
    for (Object objeto in objetos) {
        classes.add(inspecionarClasse(objeto));
    }

    // Crie um diretorio chamado frontend, se nao tiver
    Directory('frontend').createSync();

    // Crie o arquivo index.html no diretorio frontend
    File('frontend/index.html').writeAsStringSync(generateMainHTML(classes));

    // Cria o arquivo style.css no diretorio frontend
    File('frontend/style.css').writeAsStringSync(generateMainCSS());

    // Cria um diretorio chamado forms, se nao tiver
    Directory('frontend/forms').createSync();

    // Cria os arquivos de formulário
    for (Map<String, dynamic> classe in classes) {
        File('frontend/forms/' + classe['nome'].toLowerCase() + '.html').writeAsStringSync(generateFormHTML(classe));
    }

    // Cria um arquivo style.css no diretorio forms
    File('frontend/forms/style.css').writeAsStringSync(generateFormCss());

}

void generateBackend(List<Object> objetos) {
    List<Map<String, dynamic>> classes = [];
    for (Object objeto in objetos) {
        classes.add(inspecionarClasse(objeto));
    }

    // Crie um diretorio chamado backend, se nao tiver
    Directory('backend').createSync();

    // Cria o arquivo package.json no diretorio backend
    File('backend/package.json').writeAsStringSync(createPackageJson());

    // Cria o arquivo .env
    File('backend/.env').writeAsStringSync(createEnv());

    // Cria o arquivo index.js
    File('backend/index.js').writeAsStringSync(createIndexJs());

    // Cria o diretório src
    Directory('backend/src').createSync();

    // Cria o diretório models
    Directory('backend/src/models').createSync();

    // Cria os models
    File('backend/src/models/model.options.js').writeAsStringSync(createModelOptionsJs());

    for (Map<String, dynamic> classe in classes) {
        File('backend/src/models/' + classe['nome'].toLowerCase() + '.model.js').writeAsStringSync(createModelJs(classe));
    }

    // Cria o diretório controllers
    Directory('backend/src/controllers').createSync();

    // Cria os controllers
    for (Map<String, dynamic> classe in classes) {
        File('backend/src/controllers/' + classe['nome'].toLowerCase() + '.controller.js').writeAsStringSync(createControllerJs(classe));
    }

    // Cria o diretório routes
    Directory('backend/src/routes').createSync();

    // Cria os routes
    File ('backend/src/routes/index.js').writeAsStringSync(createRoutesIndexJs(classes));

    for (Map<String, dynamic> classe in classes) {
        File('backend/src/routes/' + classe['nome'].toLowerCase() + '.route.js').writeAsStringSync(createRoutesJs(classe));
    }
}

String generateMainCSS() {
  String css = '';

  css += '* {\n';
  css += '   margin: 0;\n';
  css += '   padding: 0;\n';
  css += '   box-sizing: border-box;\n';
  css += '}\n';
  css += 'body {\n';
  css += '   display: flex;\n';
  css += '   flex-direction: column;\n';
  css += '   align-items: center;\n';
  css += '   justify-content: center;\n';
  css += '}\n';
  css += 'h1 {\n';
  css += '   font-size: 3rem;\n';
  css += '   font-weight: 700;\n';
  css += '   margin: 2rem;\n';
  css += '}\n';
  css += 'ul {\n';
  css += '   list-style: none;\n';
  css += '   display: flex;\n';
  css += '   flex-direction: column;\n';
  css += '   align-items: center;\n';
  css += '   justify-content: center;\n';
  css += '}\n';
  css += 'li {\n';
  css += '   margin: 1rem;\n';
  css += '}\n';
  css += 'a {\n';
  css += '   width: 20rem;\n';
  css += '   height: 3rem;\n';
  css += '   background-color: #f1f1f1;\n';
  css += '   border-radius: 1rem;\n';
  css += '   display: flex;\n';
  css += '   align-items: center;\n';
  css += '   justify-content: center;\n';
  css += '   flex-direction: column;\n';
  css += '   text-decoration: none;\n';
  css += '   font-size: 1.5rem;\n';
  css += '   font-weight: 700;\n';
  css += '}\n';

  return css;
}

String generateMainHTML(List<Map<String, dynamic>> classes) {

    String html = '';

    // Cria o head
    html += '<!DOCTYPE html>\n';
    html += '<html lang="pt-br">\n';
    html += '<head>\n';
    html += '   <meta charset="UTF-8">\n';
    html += '   <meta http-equiv="X-UA-Compatible" content="IE=edge">\n';
    html += '   <meta name="viewport" content="width=device-width, initial-scale=1.0">\n';
    html += '   <title>Página Principal</title>\n';
    html += '   <link rel="stylesheet" href="./style.css">\n';
    html += '</head>\n';

    // Cria o body (possui links para os formulários no dir ./forms)
    html += '<body>\n';
    html += '   <h1>Página Principal</h1>\n';
    html += '   <ul>\n';
    for (Map<String, dynamic> classe in classes) {
        html += '       <li><a href="./forms/' + classe['nome'].toLowerCase() + '.html">' + classe['nome'] + '</a></li>\n';
    }
    html += '   </ul>\n';
    html += '</body>\n';
    html += '</html>\n';

    return html;
    
}

String createPackageJson() {
    String json = '{\n';
    json = '';
    json += '{\n';
    json += '   "name": "backend",\n';
    json += '   "type": "module",\n';
    json += '   "version": "1.0.0",\n';
    json += '   "author": "Felipe",\n';
    json += '   "main": "index.js",\n';
    json += '   "license": "MIT",\n';
    json += '   "scripts": {\n';
    json += '       "start": "nodemon index.js"\n';
    json += '   },\n';
    json += '   "dependencies": {\n';
    json += '       "cors": "^2.8.5",\n';
    json += '       "cookie-parser": "^1.4.6",\n';
    json += '       "dotenv": "^16.0.3",\n';
    json += '       "express": "^4.18.2",\n';
    json += '       "express-validator": "^6.14.2",\n';
    json += '       "mongoose": "^6.8.1",\n';
    json += '       "nodemon": "^2.0.20"\n';
    json += '   }\n';
    json += '}\n';

    return json;
}

String createEnv() {
    String env = '';

    env += 'PORT=5000\n';
    env += 'MONGODB_URL=\n';

    return env;
}

String createIndexJs() {
    String js = '';

    js += 'import express from "express";\n';
    js += 'import cookieParser from "cookie-parser";\n';
    js += 'import cors from "cors";\n';
    js += 'import http from "http";\n';
    js += 'import mongoose from "mongoose";\n';
    js += 'import "dotenv/config";\n';
    js += 'import routes from "./src/routes/index.js";\n';
    js += '\n';
    js += 'const app = express();\n';
    js += '\n';
    js += 'app.use(cors());\n';
    js += 'app.use(express.json());\n';
    js += 'app.use(express.urlencoded({ extended: true }));\n';
    js += 'app.use(cookieParser());\n';
    js += '\n';
    js += 'app.use("/api/v1", routes);\n';
    js += '\n';
    js += 'const PORT = process.env.PORT || 5000;\n';
    js += '\n';
    js += 'const server = http.createServer(app);\n';
    js += '\n';
    js += 'mongoose.set("strictQuery", false);\n';
    js += 'mongoose.connect(process.env.MONGODB_URL).then(() => {\n';
    js += '   console.log("Connected to MongoDB");\n';
    js += '   server.listen(PORT, () => {\n';
    js += '       console.log("Server is running on port " + PORT);\n';
    js += '   });\n';
    js += '}).catch((error) => {\n';
    js += '   console.log(error);\n';
    js += '   process.exit(1);\n';
    js += '});\n';

    return js;
}

String createModelOptionsJs() {
    String js = '';

    js += 'const modelOptions = {\n';
    js += '   toJSON: {\n';
    js += '       virtuals: true,\n';
    js += '       transform: (_, obj) => {\n';
    js += '           delete obj._id;\n';
    js += '           return obj;\n';
    js += '       },\n';
    js += '   },\n';
    js += '   toObject: {\n';
    js += '       virtuals: true,\n';
    js += '       transform: (_, obj) => {\n';
    js += '           delete obj._id;\n';
    js += '           return obj;\n';
    js += '       },\n';
    js += '   },\n';
    js += '   versionKey: false,\n';
    js += '   timestamps: true,\n';
    js += '};\n';
    js += '\n';
    js += 'export default modelOptions;\n';

    return js;
}

String createModelJs(Map<String, dynamic> classe) {
    String js = '';

    js += 'import mongoose from "mongoose";\n';
    js += 'import modelOptions from "./model.options.js";\n';
    js += '\n';
    js += 'const ' + classe['nome'].toLowerCase() + 'Schema = new mongoose.Schema({\n';

    for (Map<String, dynamic> atributo in classe['atributos']) {
        String tipo = atributo['tipo'].toString().toLowerCase() == 'texto' ? 'String' : atributo['tipo'].toString().toLowerCase() == 'inteiro' ? 'Number' : atributo['tipo'].toString().toLowerCase() == 'flutuante' ? 'Number' : 'String';

        // Se o tipo nao for Texto, Inteiro ou Flutuante, entao eh uma relação cujo nome tem id
        String nome = '';
        if (atributo['tipo'].toString() == 'Texto' || atributo['tipo'].toString() == 'Inteiro' || atributo['tipo'].toString() == 'Flutuante') {
            nome = atributo['nome'].toLowerCase();
        } else {
            nome = atributo['nome'].toLowerCase() + 'Id';     
        }

        js += '   ' + nome + ': {\n';
        js += '       type: ' + tipo + ',\n';
        js += '       required: true,\n';
        js += '   },\n';
    }

    js += '}, modelOptions);\n';
    js += '\n';
    js += 'const ' + classe['nome'].toLowerCase() + 'Model = mongoose.model("' + classe['nome'] + '", ' + classe['nome'].toLowerCase() + 'Schema);\n';
    js += '\n';
    js += 'export default ' + classe['nome'].toLowerCase() + 'Model;\n';

    return js;
}

String createControllerJs(Map<String, dynamic> classe) {
    String js = '';

    js += 'import ' + classe['nome'].toLowerCase() + 'Model from "../models/' + classe['nome'].toLowerCase() + '.model.js";\n';
    js += '\n';
    js += 'const create' + classe['nome'] + ' = async (req, res) => {\n';
    js += '   try {\n';
    js += '       const ' + classe['nome'].toLowerCase() + ' = await ' + classe['nome'].toLowerCase() + 'Model.create(req.body);\n';
    js += '       res.status(201).json(' + classe['nome'].toLowerCase() + ');\n';
    js += '   } catch (error) {\n';
    js += '       res.status(400).json({ message: error.message });\n';
    js += '   }\n';
    js += '};\n';
    js += '\n';
    js += 'export default {\n';
    js += '   create' + classe['nome'] + ',\n';
    js += '};\n';
    js += '\n';
    js += 'export { create' + classe['nome'] + ' };\n';

    return js;
}

String createRoutesIndexJs(List<Map<String, dynamic>> classes) {
    String js = '';

    js += 'import express from "express";\n';
    for (Map<String, dynamic> classe in classes) {
        js += 'import ' + classe['nome'].toLowerCase() + 'Route from "./' + classe['nome'].toLowerCase() + '.route.js";\n';
    }
    js += '\n';
    js += 'const router = express.Router();\n';
    js += '\n';
    for (Map<String, dynamic> classe in classes) {
        js += 'router.use("/' + classe['nome'].toLowerCase() + '", ' + classe['nome'].toLowerCase() + 'Route);\n';
    }
    js += '\n';
    js += 'export default router;\n';

    return js;
}

String createRoutesJs(Map<String, dynamic> classe) {
    String js = '';

    js += 'import express from "express";\n';
    js += 'import { body } from "express-validator";\n';
    js += 'import ' + classe['nome'].toLowerCase() + 'Controller from "../controllers/' + classe['nome'].toLowerCase() + '.controller.js";\n';
    js += '\n';
    js += 'const router = express.Router();\n';
    js += '\n';
    js += 'router.post(\n';
    js += '   "/",\n';
    for (Map<String, dynamic> atributo in classe['atributos']) {
        String tipo = atributo['tipo'].toString().toLowerCase() == 'texto' ? 'String' : atributo['tipo'].toString().toLowerCase() == 'inteiro' ? 'Number' : atributo['tipo'].toString().toLowerCase() == 'flutuante' ? 'Number' : 'String';

        // Se o tipo nao for Texto, Inteiro ou Flutuante, entao eh uma relação cujo nome tem id
        String nome = '';
        if (atributo['tipo'].toString() == 'Texto' || atributo['tipo'].toString() == 'Inteiro' || atributo['tipo'].toString() == 'Flutuante') {
            nome = atributo['nome'].toLowerCase();
        } else {
            nome = atributo['nome'].toLowerCase() + 'Id';     
        }

        js += '   body("' + nome + '")\n';
        js += '       .exists().withMessage("' + nome + ' is required"),\n';
    }
    js += '   ' + classe['nome'].toLowerCase() + 'Controller.create' + classe['nome'] + '\n';
    js += ');\n';
    js += '\n';
    js += 'export default router;\n';

    return js;
}

String generateFormCss() {
  String css = '';

  css += '* {\n';
  css += '   margin: 0;\n';
  css += '   padding: 0;\n';
  css += '   box-sizing: border-box;\n';
  css += '}\n';
  css += '\n';
  css += 'body {\n';
  css += '   display: flex;\n';
  css += '   flex-direction: column;\n';
  css += '   align-items: center;\n';
  css += '   justify-content: center;\n';
  css += '}\n';
  css += '\n';
  css += 'h1 {\n';
  css += '   font-size: 3rem;\n';
  css += '   font-weight: 700;\n';
  css += '   margin: 2rem;\n';
  css += '}\n';
  css += '\n';
  css += 'form {\n';
  css += '   display: flex;\n';
  css += '   flex-direction: column;\n';
  css += '   align-items: center;\n';
  css += '   justify-content: center;\n';
  css += '}\n';
  css += '\n';
  css += 'input {\n';
  css += '   width: 20rem;\n';
  css += '   height: 3rem;\n';
  css += '   margin: 1rem;\n';
  css += '   border-radius: 1rem;\n';
  css += '   font-size: 1.5rem;\n';
  css += '   font-weight: 700;\n';
  css += '}\n';
  css += '\n';
  css += 'input:last-child {\n';
  css += '   background-color: #f1f1f1;\n';
  css += '   cursor: pointer;\n';
  css += '}\n';
  css += '\n';

  return css;
}

String generateFormHTML(Map<String, dynamic> classe) {
    String html = '';

    // Cria o head
    html += '<!DOCTYPE html>\n';
    html += '<html lang="pt-br">\n';
    html += '<head>\n';
    html += '   <meta charset="UTF-8">\n';
    html += '   <meta http-equiv="X-UA-Compatible" content="IE=edge">\n';
    html += '   <meta name="viewport" content="width=device-width, initial-scale=1.0">\n';
    html += '   <title>' + classe['nome'] + '</title>\n';
    html += '   <link rel="stylesheet" href="./style.css">\n';
    html += '</head>\n';


    // Cria o body
    html += '<body>\n';
    html += '   <h1>' + classe['nome'] + '</h1>\n';
    html += '   <form action="">\n';
    for (Map<String, dynamic> atributo in classe['atributos']) {
        html += '       <label for="' + atributo['configuracao']['label'] + '">' + atributo['configuracao']['label'] + '</label>\n';

        if (atributo['tipo'] == 'Texto') {
            html += '       <input type="' + atributo['configuracao']['tipo_input'] + '" id="' + atributo['configuracao']['label'] + '" name="' + atributo['configuracao']['label'].substring(0, 1).toLowerCase() + atributo['configuracao']['label'].substring(1) + '">\n';
        } else if (atributo['tipo'] == 'Inteiro') {
            html += '       <input type="' + atributo['configuracao']['tipo_input'] + '" id="' + atributo['configuracao']['label'] + '" name="' + atributo['configuracao']['label'].substring(0, 1).toLowerCase() + atributo['configuracao']['label'].substring(1) + '">\n';
        } else if (atributo['tipo'] == 'Flutuante') {
            html += '       <input type="number" id="' + atributo['configuracao']['label'] + '" name="' + atributo['configuracao']['label'].substring(0, 1).toLowerCase() + atributo['configuracao']['label'].substring(1) + '" step="0.1">\n';
        } else {
            html += '       <input type="' + atributo['configuracao']['tipo_input'] + '" id="' + atributo['configuracao']['label'] + '" name="' + atributo['configuracao']['label'].substring(0, 1).toLowerCase() + atributo['configuracao']['label'].substring(1) + '">\n';
        }
    }
    html += '       <input type="submit" value="Enviar">\n';
    html += '   </form>\n';


    // Cria o script (requisição ao backend)
    html += '   <script>\n';
    html += '       const form = document.querySelector("form");\n';
    html += '       form.addEventListener("submit", (event) => {\n';
    html += '           event.preventDefault();\n';
    html += '           const formData = new FormData(form);\n';
    html += '           const data = Object.fromEntries(formData);\n';
    html += '           fetch("http://localhost:5000/api/v1/' + classe['nome'].toLowerCase() + '/", {\n';
    html += '               method: "POST",\n';
    html += '               headers: {\n';
    html += '                   "Content-Type": "application/json",\n';
    html += '               },\n';
    html += '               body: JSON.stringify(data),\n';
    html += '           })\n';
    html += '           .then((response) => response.json())\n';
    html += '           .then((data) => {\n';
    html += '               console.log("Success:", data);\n';
    html += '           })\n';
    html += '           .catch((error) => {\n';
    html += '               console.error("Error:", error);\n';
    html += '           });\n';
    html += '       });\n';
    html += '   </script>\n';
    html += '</body>\n';
    html += '</html>\n';

    return html;

}