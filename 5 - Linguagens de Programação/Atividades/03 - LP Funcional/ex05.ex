defmodule ReversaoLista do
  def reverter_lista(lista) do
    reverter_lista_recursiva(lista, [])
  end

  defp reverter_lista_recursiva([], resultado) do
    resultado
  end

  defp reverter_lista_recursiva([cabeca | cauda], resultado) do
    reverter_lista_recursiva(cauda, [cabeca | resultado])
  end
end

lista = [1, 2, 3, 4, 5]

lista_revertida = ReversaoLista.reverter_lista(lista)
IO.inspect(lista_revertida)
