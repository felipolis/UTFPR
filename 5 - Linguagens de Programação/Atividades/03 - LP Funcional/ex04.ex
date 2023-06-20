defmodule ProdutoLista do
  def calcular_produto(lista) do
    calcular_produto_recursivo(lista, 1)
  end

  defp calcular_produto_recursivo([], produto) do
    produto
  end

  defp calcular_produto_recursivo([cabeca | cauda], produto) do
    calcular_produto_recursivo(cauda, produto * cabeca)
  end
end

lista = [1, 2, 3, 4, 5]

produto = ProdutoLista.calcular_produto(lista)
IO.puts("O produto dos elementos da lista eh: #{produto}")
