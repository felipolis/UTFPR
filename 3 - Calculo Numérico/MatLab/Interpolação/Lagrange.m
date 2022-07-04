x=input('Insira os valores de x na tabela (por exemplo [-1 0 3] )\n ');
y=input('Insira os valores de y na tabela (por exemplo [15 8 -1] )\n ');
u1=input('Digite o valor de x que você deseja obter a aproximação\n ');
u=x(1)-1:.01:x(length(x))+1;
symx = sym('x');
P = polyinterp(x,y,symx);
P = simplify(P);
disp('Método de Lagrange:');
formatSpec = 'O polinômio interpolador é  P(x)= %s\n';
fprintf(formatSpec,P);
v1=polyinterp(x,y,u1);
v=polyinterp(x,y,u);
formatSpec1 = 'Temos que P(%4.5f) = %4.5f\n';
fprintf(formatSpec1,u1,v1);
plot(x,y,'o',u,v,'r-', 'LineWidth', 1.5);
hold on;
plot(u1,v1,'r.',  'MarkerSize',20);
title('Polinônimo Interpolador - Método de Lagrange');
legend('Pontos Interpolados', 'Polinômio interpolador', 'Aproximação')
hold off;
function v = polyinterp(x,y,u)
n = length(x);
v = zeros(size(u));
for k = 1:n
w = ones(size(u));
for j = [1:k-1 k+1:n]
w = (u-x(j))./(x(k)-x(j)).*w;
end
v = v + w*y(k);
end
end 



