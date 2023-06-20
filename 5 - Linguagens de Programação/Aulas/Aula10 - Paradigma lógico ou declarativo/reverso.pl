consult('concatena.pl').

reverso([], []).
reverso([Head | Tail], List) :- reverso(Tail, Result),
    concatena(Result, [Head], List).