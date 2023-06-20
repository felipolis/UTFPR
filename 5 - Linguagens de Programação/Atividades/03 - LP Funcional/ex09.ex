defmodule QuickSort do
  def sort(lista) do
    if length(lista) <= 1 do
      lista
    else
      pivot = hd(lista)
      menores = sort(for x <- tl(lista), x <= pivot, do: x)
      maiores = sort(for x <- tl(lista), x > pivot, do: x)
      menores ++ [pivot] ++ maiores
    end
  end
end

lista = [7, 2, 9, 4, 1, 5, 3, 6, 8]

lista_ordenada = QuickSort.sort(lista)
IO.inspect(lista_ordenada)
