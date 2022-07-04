A = input('Insira as entradas da matriz A: por exemplo, [5 1 1; 3 4 1; 3 3 6]\n');
b=input('Insira a matriz B: por exemplo, [5; 6; 0]\n');
x=input('Insira a solução inicial X^(0): por exemplo, [0; 0; 0]\n');
tol=input('Insira a tolerância tol: por exemplo, 1e-2\n');
n=size(x,1);
normVal=Inf;
nmax=1000; %número máximo de iterações que pode ser alcançado%
xk0=x;
iter=0;
fprintf(1, '\n');
   fprintf( '%48s\n', 'Método de Gauss-Seidel:');
     fprintf(1, '\n');
   fprintf( '%3s%30s%35s\n', 'k',     'x_k',  'Erro relativo');
   
     fprintf('%3s%15.f%15.f%15.f%20.s\n', '0', xk0', '---') ;
     fprintf(1, '\n');
     % fprintf('%3s%15.10f%15.10f%15.10f%20.10f\n', '1', x(1), 1) ;
while normVal>tol && iter<nmax
    x_old=x;
        
    for i=1:n
        
        guess=0;
        
        for j=1:i-1
            guess=guess+A(i,j)*x(j);
        end
        
        for j=i+1:n
            guess=guess+A(i,j)*x_old(j);
        end
        
        x(i)=(1/A(i,i))*(b(i)-guess);
        
    end
    iter=iter+1;
    normVal=max(abs(x_old-x))/max(abs(x));
    str = sprintf('%3d%15.10f%15.10f%15.10f%20.10f\n', iter, [x]', normVal) ;
    fprintf('%s\n', str)
end