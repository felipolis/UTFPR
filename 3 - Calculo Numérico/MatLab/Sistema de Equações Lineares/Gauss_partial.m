A = input('Insira as entradas da matriz A: por exemplo, [1 2 3; 3 1 0;0 3 4]\n');
B=input('Insira a matriz B: por exemplo, [3; 4; 3]\n');
N = length(B);
X= zeros(N,1);
Aug = [A B];
disp('Matriz ampliada');
disp(Aug);
for j=1:N-1
    %partial pivoting
    [M,P] = max(abs(Aug(j:N,j)));
    C=Aug(j,:);
    Aug(j,:) = Aug(P+j-1,:);
    Aug(P+j-1,:) = C;
    %echlon form
    for i=j+1:N
        m= -Aug(i,j)/Aug(j,j);
        Aug(i,:) = Aug(i,:)+ m*Aug(j,:);
       
    end
   fprintf('%3s\n','Forma escalonada do sistema usando  eliminação de Gauss com pivotamento parcial');
 
fprintf('%3s\n','Matriz ampliada:');
Aug;
disp(Aug);
end


x=zeros(N,1); 
for i= N:-1:1
    x(i) = (Aug(i,N+1)-Aug(i,1:N)*x)/Aug(i,i);
end
disp('A solução do sistema linear A*X=B é');
disp(x);