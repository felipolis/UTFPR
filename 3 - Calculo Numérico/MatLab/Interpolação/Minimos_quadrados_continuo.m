clear;
syms('x');
fprintf(1,'Insira as extremidades A < B em linhas separadas\n');
 a = input(' ');
 b = input(' ');
 fprintf(1,'Insira a função f(x) em termos de x\n');
 s = input(' ');
 F = inline(s,'x');
deg=input('Digite o grau do polinômio\n ');
disp('Método dos mínimos quadrados - caso contínuo:');
p1 = [0:1:deg];
for i=1:deg+1
    for j=1:deg+1

A1(i,j)=integral(@(x)  x^(p1(j)+p1(i)),a,b, 'ArrayValued', true);
      
    end
end
disp('Matriz A:');
disp(vpa(A1));
for i=1:deg+1
    

B1(i,1)=vpa(integral(@(x)  x^(p1(i))*F(x),a,b, 'ArrayValued', true));
      
    end
 disp('Matriz B:');
 disp(B1);
 disp('Solução do sistema linear A*X=B:');
   C1= A1\B1;
   disp(C1);
syms('x');
S=0;
for i=0:deg
    S=S+C1(i+1,1).*x^i;
end
fprintf('%s %d %s %s', 'O polinômio de grau',deg,'é', 'y = ',S);

x = a-1:.1:b+1;


p = (polyfit(x,F(x),1));
f1 = polyval(p,x);
figure
figure
plot(x,F(x));
 hold on
 plot(x,f1)
 hold off
 %
 % axis([a-1  b+1  F(a-1)  F(b+1)])
 title('Método dos Mínimos Quadrados - caso contínuo');
 legend('y=f(x)','Polinômio','LineWidth', 1.5);
