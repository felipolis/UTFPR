defmodule IntersecaoListaRecursiva do
  def intersecao_listas(lista1, lista2) do
    intersecao_recursiva(lista1, lista2, [])
  end

  defp intersecao_recursiva([], _lista2, resultado) do
    resultado
  end

  defp intersecao_recursiva([cabeca | cauda], lista2, resultado) do
    if Enum.member?(lista2, cabeca) do
      intersecao_recursiva(cauda, lista2, [cabeca | resultado])
    else
      intersecao_recursiva(cauda, lista2, resultado)
    end
  end
end

lista1 = [1, 2, 3, 4, 5]
lista2 = [4, 5, 6, 7, 8]

intersecao = IntersecaoListaRecursiva.intersecao_listas(lista1, lista2)
IO.inspect(intersecao)
