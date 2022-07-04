clc;clear;
syms('NAME', 'OUP', 'I', 'P', 'Q','x','s');
 TRUE = 1;
 FALSE = 0;
 disp('Regra 1/3 de Simpson');
a=input('Digite o limite inferior "a", por exemplo 0: '); % exmple a=1
 b=input('Digite o limite superior "b", por exemplo 1: ');  % exmple b=2
  fprintf(1,'Insira a função f(x) em termos de  x\n');
 fprintf(1,'Por exemplo, 4/(1+x^2)\n');
 s = input(' ');
 f = inline(s,'x');
 n=input('insira o número de subintervalos n: '); % exmple n=21

 h=(b-a)/n;
if rem(n,2)==1
   fprintf('\n Digite um valor válido de  n!!!'); 
   n=input('\n Insira n como um número par ');
end
%disp('Tabela dos valores de x e f(x)');
fprintf(' \t %8s \t %13s\n','x','f(x)');
fprintf(' \t %3f \t %7.10f\n',a,f(a));
for k=1:1:n
  x(k)=a+k*h;
  y(k)=f(x(k));
   fprintf(' \t %3f \t %7.10f\n',x(k),y(k)); 
end
 so=0;se=0;
for k=1:1:n-1
    if rem(k,2)==1
       so=so+y(k);%sum of odd terms
     else
       se=se+y(k); %sum of even terms
    end
end
% Formula:  (h/3)*[(y0+yn)+2*(y3+y5+..odd term)+4*(y2+y4+y6+...even terms)]
answer=h/3*(f(a)+f(b)+4*so+2*se);
fprintf('\n O valor da integral é aproximadamente %7.10f',answer); % exmple The value of integration is 0.408009
