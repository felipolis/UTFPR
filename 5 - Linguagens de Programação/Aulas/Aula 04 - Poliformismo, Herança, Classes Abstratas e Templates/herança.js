/* // DEFINIÇÕES COM "PROTOTYPE"

function Pessoa(primeiro, ultimo, idade, altura) {
    this.nome = {primeiro, ultimo}
    this.idade = idade
    this.altura = altura
    
    this.aniversario = function() {
        this.idade++
    }
    
    this.oi = function() {
        console.log('Olá! Meu nome é ' + this.nome.primeiro + ', tenho ' +
            this.idade + ' anos e ensino ' + this.ensina)
    }
}

function Professor(ensina) {
    this.ensina = ensina
} */

// DEFINIÇÕES COM "CLASSES"

class Pessoa {
    constructor(primeiro, ultimo, idade, altura) {
        this.nome = {primeiro, ultimo}
        this.idade = idade
        this.altura = altura
    }
    aniversario() { this.idade++ }
    oi() {
        console.log('Olá! Meu nome é ' + this.nome.primeiro + ', tenho ' +
            this.idade + ' anos e ensino ' + this.ensina)
    }
}

class Professor extends Pessoa {
    constructor(primeiro, ultimo, idade, altura, ensina) {
        super(primeiro, ultimo, idade, altura)
        this.ensina = ensina
    }
}

// INSTANCIANDO VARIÁVEL A PARTIR DO "PROTOTYPE"
/* Professor.prototype = new Pessoa('Rodrigo', 'Hübner', 37, 1.80)
Professor.prototype.constructor = Professor
var prof = new Professor('Algoritmos') */

//INSTANCIANDO OBJETO A PARTIR Da "CLASSE"
var prof = new Professor('Rodrigo', 'Hübner', 37, 1.80, 'Algoritmos')

// UTILIZAÇÃO IGUAL PARA AMBOS
prof.aniversario()
prof.aniversario()
prof.oi()