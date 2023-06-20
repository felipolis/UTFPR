membro(Element, [Element | _]).
membro(Element, [_ | Tail]) :- membro(Element, Tail).