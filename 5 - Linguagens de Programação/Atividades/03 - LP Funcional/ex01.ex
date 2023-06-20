defmodule BuscaElementoRecursivo do
  def encontrar_elemento(elemento, lista) do
    encontrar_elemento_recursivo(elemento, lista, 0)
  end

  defp encontrar_elemento_recursivo(_elemento, [], _index) do # Se a lista estiver vazia, retorna nil
    nil
  end

  defp encontrar_elemento_recursivo(elemento, [cabeca | _cauda], index) when cabeca == elemento do # Se o elemento for encontrado, retorna o index
    index
  end

  defp encontrar_elemento_recursivo(elemento, [_cabeca | cauda], index) do # Se o elemento não for encontrado, chama a função novamente com a cauda da lista
    encontrar_elemento_recursivo(elemento, cauda, index + 1)
  end
end

lista = [1, 2, 3, 4, 5]
elemento = 3

resultado = BuscaElementoRecursivo.encontrar_elemento(elemento, lista)
IO.puts("O elemento #{elemento} foi encontrado na lista? #{resultado != nil}")
