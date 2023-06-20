function incremento(valorInicial) {
    let atual = 0;
    return function() {
      atual += valorInicial;
      return atual;
    };
  }
  
  const proximo = incremento(2);
  console.log(proximo());
  console.log(proximo());
  console.log(proximo());
  console.log(proximo());
  