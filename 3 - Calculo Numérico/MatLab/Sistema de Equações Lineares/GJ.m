A = input('Insira as entradas da matriz A: por exemplo, [10 2 1; 1 5 1; 2 3 10]\n');
b=input('Insira a matriz B: por exemplo, [14; 11; 8]\n');
xk=input('Insira a solução inicial X^(0): por exemplo, [0; 0; 0]\n');
tol=input('Insira a tolerância tol: por exemplo, 1e-2\n');
xk0=xk;
N = diag(diag(A));   % MATRIZ QUE CONTÉM A DIAGONAL DE A
    P = -(A-N);          % MATRIZ QUE CONTÉM A, EXCETO SUA DIAGONAL
    
    k = 1;               % DECLARAÇÃO DO CONTADOR
    xkp1 = N\(P*xk + b); % CÁLCULO DA PRIMEIRA ITERAÇÃO
    xkm1 = xk;           % ATUALIZAÇÃO DE x^(k-1) (AQUI, xkm1 = x^(0))
    xk = xkp1;           % ATUALIZAÇÃO DE x^(k)   (ACÁ, xk   = x^(1))
    
    err = 1.0e6;         % DECLARAÇÃO DO ERRO PARA ENTRAR NO CICLO while
   fprintf(1, '\n');
   fprintf( '%48s\n', 'Método de Gauss-Jacobi:');
     fprintf(1, '\n');
    fprintf( '%3s%30s%35s\n', 'k',     'x_k',  'Erro relativo');
   
     fprintf('%3s%15.f%15.f%15.f%20.s\n', '0', xk0', '---') ;
     fprintf(1, '\n');
      fprintf('%3s%15.10f%15.10f%15.10f%20.10f\n', '1', xk', 1) ;
      fprintf(1, '\n');
       while (err >= tol)
        k = k+1;         % ACTUALIZAÇÃO DO CONTADOR
        xkp1 = N\(P*xk + b); % CÁLCULO DA SOLUÇÃO x^(k+1)
        %mk = norm(xkp1-xk,2)/norm(xk-xkm1,2); % CÁLCULO DO FACTOR m_k
        err = max(abs(xkp1-xk))/(max(abs(xkp1)));      % CÁLCULO DO ERRO PARA
                                              % CRITÉRIO DA PARADA
        xkm1 = xk;       % ATUALIZAÇÃO DE x^(k-1)
        xk = xkp1;       % ATUALIZAÇÃO DE x^(k)
       
str = sprintf('%3d%15.10f%15.10f%15.10f%20.10f\n', k, [xkp1]', err) ;
    fprintf('%s\n', str)


         %fprintf( '%3f%1f%1f\n', k, [xkp1]', err);
    end