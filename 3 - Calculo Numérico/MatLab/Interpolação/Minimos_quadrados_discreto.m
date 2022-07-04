clear;
xi=input('Insira os valores de x na tabela (por exemplo, [-2 -1  1 2 ] )\n ');
y=input('Insira os valores de y na tabela (por exemplo,  [1 -3 1 9] )\n ');
deg=input('Digite o grau do polinômio\n ');
disp('Método dos mínimos quadrados - caso discreto:');
p1 = [0:1:deg];
for i=1:length(y)
    for j=1:length(p1)
        A1(i,j)=xi(i)^p1(j);
    end
end
syms('x');
disp('Vetores g_i:')
for i=1:length(xi)-1
 
disp(arrayfun(@(x) x.^(i-1),xi));

end

A2 = A1';
B0=y;
for k=1:length(y)-1
    B0=cat(1,B0,y);
end
B0;
B1=B0';
disp('Matriz A:');
C1 = A2*A1;
disp(C1);
disp('Matriz B:');

A3 = A2*B1(:,1);
disp(A3);
disp('Solução do sistema linear A*X=B');
disp(C1\A3);
% XX=['Polinômio de grau ', num2str(deg),':'];
% disp(XX);
p =  polyfit(xi,y,deg);
p11=flip(p);
syms('x');
S=0;
for i=0:deg
    S=S+p11(i+1).*x^(i);
end
fprintf('%s %d %s %s', 'O polinômio de grau',deg,'é', 'y = ',S);
x1 = xi(1)-1:.1:xi(length(xi))+1;
y1 = polyval(p,x1);
figure
plot(xi,y,'o')
hold on
plot(x1,y1)
hold off
title('Método dos Mínimos Quadrados');
legend('Pontos da tabela','Polinômio','LineWidth', 1.5);