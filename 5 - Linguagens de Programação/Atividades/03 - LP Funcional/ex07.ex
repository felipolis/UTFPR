defmodule ConcatenacaoRecursiva do
  def concatenar_listas(lista1, lista2) do
    concatenar_recursivo(lista1, lista2)
  end

  defp concatenar_recursivo([], lista2) do
    lista2
  end

  defp concatenar_recursivo([cabeca | cauda], lista2) do
    [cabeca | concatenar_recursivo(cauda, lista2)]
  end
end

lista1 = [1, 2, 3]
lista2 = [4, 5, 6]

lista_concatenada = ConcatenacaoRecursiva.concatenar_listas(lista1, lista2)
IO.inspect(lista_concatenada)
