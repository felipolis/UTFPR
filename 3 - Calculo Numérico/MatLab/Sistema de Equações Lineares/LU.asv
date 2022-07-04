A = input('Insira as entradas da matriz A; por exemplo, [5 2 1; -1 4 2; 2 -3 10] \n');
B=input('Insira a matriz B: por exemplo, [-12; 20; 3]\n');
n = size(A, 1); % Obtain number of rows (should equal number of columns)
L = eye(n); % Start L off as identity and populate the lower triangular half slowly
for k = 1 : n
    % For each row k, access columns from k+1 to the end and divide by
    % the diagonal coefficient at A(k ,k)
    L(k + 1 : n, k) = A(k + 1 : n, k) / A(k, k);

    % For each row k+1 to the end, perform Gaussian elimination
    % In the end, A will contain U
    for l = k + 1 : n
        A(l, :) = A(l, :) - L(l, k) * A(k, :);
    end
end
disp('A matriz triangular inferior L é ');
disp(L);
disp('A matriz triangular superior U é');
U = A;
disp(U);
disp('Solução do sistema linear L*Y=B:');
Y = L\B;
disp(Y);
disp('Solução do sistema linear U*X=Y:');
X=U\Y;
disp(X);