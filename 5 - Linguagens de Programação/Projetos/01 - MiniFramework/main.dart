import 'lib/models.dart';
import 'lib/generator.dart';


class Categoria {
    Texto nome = Texto('Nome', 'text');
}

class Produto {
    Texto nome = Texto('Nome', 'text');
    Inteiro quantidade = Inteiro('Quantidade', 'number');
    Flutuante preco = Flutuante('Preco', 'number');
    Categoria categoria = Categoria();
}

class Pessoa {
    Texto nome = Texto('Nome', 'text');
    Inteiro idade = Inteiro('Idade', 'number');
    Flutuante altura = Flutuante('Altura', 'number');
}

class Cachorro {
    Texto nome = Texto('Nome', 'text');
    Texto raca = Texto('Raça', 'text');
    Inteiro idade = Inteiro('Idade', 'number');
}


void main() async{

    register([Categoria(), Produto(), Pessoa()]);
    print('Aplicação gerada com sucesso!');
}