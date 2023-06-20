fun fact(n : int): int = if n = 0 then 1
                         else n * fact(n - 1);
fact(5);

fun lenght([]) = 0
  | lenght(h :: t) = 1 + lenght(t);

lenght([1, 2, 3, 4, 5]);

fun append([], list2) = list2
  | append(h :: t, list2) = h :: append(t, list2);

append([1, 2], [3, 4, 5]);

let
  val pi = 3.14159265358979323846264338327950288419716939937510
  val radius = 20.0
in
  pi * radius * radius
end;