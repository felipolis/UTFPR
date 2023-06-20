Function incremento(int valorInicial) {
  int atual = 0;
  return () {
    atual += valorInicial;
    return atual;
  };
}

void main() {
  var proximo = incremento(2);
  print(proximo());
  print(proximo());
  print(proximo());
  print(proximo());
}
