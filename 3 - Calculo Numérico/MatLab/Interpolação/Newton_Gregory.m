clear;
x=input('Insira os valores de x na tabela (por exemplo [0 1 2] )\n ');
y=input('Insira os valores de y na tabela (por exemplo [1 1/2 1/3] )\n ');
u1=input('Digite o valor de x que você deseja obter a aproximação\n ');
disp('Fórmula de Newton-Grégory:');
for i=1:length(x)
   Q2(i)=1/(((x(2)-x(1)).^(i-1)).*factorial(i-1));
end
n=length(x); m=length(u1);
for t=1:m
    z=u1(t); A=zeros(n,n);A(:,1)=y';
    s=0.0; y=0.0; %c1=1.0;
    for  j=2:n
       for i=j:n
           A(i,j)=(A(i,j-1)- A(i-1,j-1));
       end
    end
    C=A(n,n);
    for k=1:n
        p=1.0;
        for j=1:k-1
            p=p*(z-x(j));
        end
        s=s+A(k,k)*p;        
    end
    ss(t)=s;
end
    y=ss;
    A=[x',A];
    disp('Tabela de Diferenças Finitas:');
disp(A);
     symx = sym('x');
  s=0;
  for k=1:n
        p=1.0;
        for j=1:k-1
            p=p*(symx-A(j,1));
        end
        s=s+A(k,k+1)*p*Q2(k);        
  end

  y1=simplify(s);
formatSpec = 'O polinômio interpolador é  P(x)= %s\n';
fprintf(formatSpec,y1);
yss=subs(y1,u1);
formatSpec1 = 'Temos que P(%4.5f) = %4.5f\n';
fprintf(formatSpec1,u1,ss);
x11=x; y22=subs(y1,x11);
plot(x11,y22,'o','LineWidth', 1.5);
hold all; 
ezplot(y1);
plot(u1,yss,'r.',  'MarkerSize',20);
title('Polinônimo Interpolador');
legend('Pontos Interpolados', 'Polinômio interpolador', 'Aproximação');