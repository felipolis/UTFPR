defmodule TesteIgualdadeLista do
  def listas_sao_iguais(lista1, lista2) do
    listas_sao_iguais_recursiva(lista1, lista2)
  end

  defp listas_sao_iguais_recursiva([], []) do
    true
  end

  defp listas_sao_iguais_recursiva([], _lista2) do
    false
  end

  defp listas_sao_iguais_recursiva(_lista1, []) do
    false
  end

  defp listas_sao_iguais_recursiva([cabeca1 | cauda1], [cabeca2 | cauda2]) do
    cabeca1 == cabeca2 && listas_sao_iguais_recursiva(cauda1, cauda2)
  end
end

lista1 = [1, 2, 3, 4, 5]
lista2 = [1, 2, 3, 4, 5]
lista3 = [1, 2, 3, 4, 6]

resultado1 = TesteIgualdadeLista.listas_sao_iguais(lista1, lista2)
resultado2 = TesteIgualdadeLista.listas_sao_iguais(lista1, lista3)

IO.puts("As listas lista1 e lista2 sao iguais? #{resultado1}")
IO.puts("As listas lista1 e lista3 sao iguais? #{resultado2}")
