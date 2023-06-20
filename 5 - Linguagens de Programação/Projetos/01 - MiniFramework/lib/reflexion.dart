// Classe de inspeção e reflexão de objetos
/* 

Com a classe:
class Produto {
    Texto nome = Texto('Nome', 'text');
    Inteiro quantidade = Inteiro('Quantidade', 'number');
    Flutuante preco = Flutuante('Preço', 'number');
    Categoria categoria = Categoria();
}

Faça a função
inspecionarClasse(Object objeto)

RETORNO:
{
    "nome": "Produto",
    "atributos": [
        {
            "nome": "nome",
            "tipo": "Texto",
            "configuracao": {
                "label": "Nome",
                "tipo_input": "text"
            }
        },
        {
            "nome": "quantidade",
            "tipo": "Inteiro",
            "configuracao": {
                "label": "Quantidade",
                "tipo_input": "number"
            }
        },
        {
            "nome": "preco",
            "tipo": "Flutuante",
            "configuracao": {
                "label": "Preço",
                "tipo_input": "number"
            }
        },
        {
            "nome": "categoriaId",
            "tipo": "Categoria",
            "configuracao": {
                "label": "Categoria",
                "tipo_input": "text"
            }
        }
    ]
}

*/
import 'dart:mirrors'; // Biblioteca de introspecção e reflexão

Map<String, dynamic> inspecionarClasse(Object objeto) {
  // Obtém a classe do objeto
  ClassMirror classe = reflect(objeto).type;

  // Obtém o nome da classe
  String nomeClasse = MirrorSystem.getName(classe.simpleName);

  // Obtém os atributos da classe
  List<InstanceMirror> atributos = classe.declarations.values
      .whereType<VariableMirror>()
      .map((im) => reflect(objeto).getField(im.simpleName))
      .toList();

  // Obtém o nome dos atributos
  List<String> nomesAtributos = classe.declarations.values
      .whereType<VariableMirror>()
      .map((im) => MirrorSystem.getName(im.simpleName))
      .toList();

  // Obtém o tipo dos atributos
  List<String> tiposAtributos =
      atributos.map((im) => im.type.reflectedType.toString()).toList();

  // Para cada atributo da classe, obtenha os argumentos passados no construtor
  List<Map<String, dynamic>> configuracoesAtributos =
      atributos.map((im) {
    // Obtém a classe do atributo
    ClassMirror classeAtributo = im.type;

    // Obtém o nome da classe do atributo
    String nomeClasseAtributo =
        MirrorSystem.getName(classeAtributo.simpleName);

    if (nomeClasseAtributo == 'Texto' ||
        nomeClasseAtributo == 'Inteiro' ||
        nomeClasseAtributo == 'Flutuante') {
      // Obtém os argumentos passados no construtor da classe do atributo
      List<InstanceMirror> argumentosConstrutor = classeAtributo
          .declarations.values
          .whereType<MethodMirror>()
          .where((mm) => mm.isConstructor)
          .map((mm) => mm.parameters)
          .expand((params) => params)
          .map((pm) => im.getField(pm.simpleName))
          .toList();

      // Obtém os nomes dos argumentos passados no construtor da classe do atributo
      List<String> nomesArgumentosConstrutor = classeAtributo
          .declarations.values
          .whereType<MethodMirror>()
          .where((mm) => mm.isConstructor)
          .map((mm) => mm.parameters)
          .expand((params) => params)
          .map((pm) => MirrorSystem.getName(pm.simpleName))
          .toList();

      // Obtém os valores dos argumentos passados no construtor da classe do atributo
      List<dynamic> valoresArgumentosConstrutor =
          argumentosConstrutor.map((im) => im.reflectee).toList();

      // Cria um mapa com os nomes e valores dos argumentos passados no construtor da classe do atributo
      Map<String, dynamic> configuracaoAtributo =
          Map.fromIterables(nomesArgumentosConstrutor, valoresArgumentosConstrutor);

      return {
        'nome': nomesAtributos[atributos.indexOf(im)],
        'tipo': nomeClasseAtributo,
        'configuracao': configuracaoAtributo,
      };
    } else {
      return {
        'nome': nomesAtributos[atributos.indexOf(im)],
        'tipo': nomeClasseAtributo,
        'configuracao': {
          'label': nomeClasseAtributo + 'Id',
          'tipo_input': 'text',
        },
      };
    }
  }).toList();
  // Cria um mapa com as informações da classe e seus atributos
    Map<String, dynamic> configuracaoClasse = {
    'nome': nomeClasse,
    'atributos': []
    };

    // Adiciona as informações dos atributos à configuração da classe
    for (int i = 0; i < nomesAtributos.length; i++) {
    configuracaoClasse['atributos'].add(configuracoesAtributos[i]);
    }

    return configuracaoClasse;
}