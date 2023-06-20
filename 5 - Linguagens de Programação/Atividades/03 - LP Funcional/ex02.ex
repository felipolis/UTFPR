defmodule TamanhoLista do
  def calcular_tamanho(lista) do
    calcular_tamanho_recursivo(lista, 0)
  end

  defp calcular_tamanho_recursivo([], tamanho) do
    tamanho
  end

  defp calcular_tamanho_recursivo([_ | cauda], tamanho) do
    calcular_tamanho_recursivo(cauda, tamanho + 1)
  end
end

lista = [1, 2, 3, 4, 5]

tamanho = TamanhoLista.calcular_tamanho(lista)
IO.puts("O tamanho da lista eh: #{tamanho}")
