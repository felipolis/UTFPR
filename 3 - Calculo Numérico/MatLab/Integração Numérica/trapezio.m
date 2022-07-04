clc;clear;
syms('NAME', 'OUP', 'I', 'P', 'Q','x','s');
 TRUE = 1;
 FALSE = 0;
 disp('Regra dos Trapézios');
  disp('');
a=input('Digite o limite inferior "a", por exemplo, 1: '); % exmple a=1
 b=input('Digite o limite superior "b" por exemplo, 4: ');  % exmple b=2
  fprintf(1,'Insira a função f(x) em termos de  x\n');
 fprintf(1,'Por exemplo, x^.5\n');
 s = input(' ');
 f = inline(s,'x');
 n=input('insira o número de subintervalos n: '); % exmple n=21

h=(b-a)/n;
sum=0;
%disp('Tabela dos valores de x e f(x)');
fprintf(' \t %8s \t %13s\n','x','f(x)');
fprintf(' \t %3f \t %7.10f\n',a,f(a));
for i=1:1:n-1
    sum= sum + f(a+i*h);
    fprintf(' \t %3f \t %7.10f\n',a+i*h,f(a+i*h)); 
end
fprintf(' \t %3f \t %7.10f\n',b,f(b));
result = h/2*(f(a)+f(b)+2*sum);
fprintf('O valor aproximado da integral é %7.10f',result);