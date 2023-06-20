defmodule SomaLista do
  def calcular_soma(lista) do
    calcular_soma_recursiva(lista, 0)
  end

  defp calcular_soma_recursiva([], soma) do
    soma
  end

  defp calcular_soma_recursiva([cabeca | cauda], soma) do
    calcular_soma_recursiva(cauda, soma + cabeca)
  end
end

lista = [1, 2, 3, 4, 5]

soma = SomaLista.calcular_soma(lista)
IO.puts("A soma dos elementos da lista eh: #{soma}")
