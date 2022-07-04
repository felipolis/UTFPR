%  BISECTION ALGORITHM 2.1
% 
%  To find a solution to f(x) = 0 given the continuous function
%  f on the interval [a,b], where f(a) and f(b) have
%  opposite signs:
% 
%  INPUT:   endpoints a,b; tolerance TOL;
%           maximum number of iterations NO.
% 
%  OUTPUT:  approximate solution p or
%           a message that the algorithm fails.
 syms('OK','A','B','X','FA','FB','TOL','NO','FLAG','NAME','OUP','K')
 syms('C','P','FP','x','s')
 TRUE = 1;
 FALSE = 0;
 fprintf(1,'Este é o método da Bissecção.\n');
 fprintf(1,'Insira a função f(x) em termos de x\n');
 fprintf(1,'Por exemplo, x^2-3\n ');
 s = input(' ');
 F = inline(s,'x');
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Insira as extremidades A < B em linhas separadas\n');
 A = input(' ');
 B = input(' ');
 if A > B 
 X = A;
 A = B;
 B = X;
 end
 if A == B 
 fprintf(1,'a não pode ser igual a b\n');
 else
 FA = F(A);
 FB = F(B);
 if FA*FB > 0
 fprintf(1,'f(a) e f(b) têm o mesmo sinal.\n');
 else
 OK = TRUE;
 end
 end
 end
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Insira a tolerância\n');
 TOL = input(' ');
 if TOL <= 0 
 fprintf(1,'Tolerância deve ser positiva\n');
 else 
 OK = TRUE;
 end
 end
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Coloque o número máximo de iterações - número inteiro positivo\n');
 NO = input(' ');
 if NO <= 0 
 fprintf(1,'Must be positive integer\n');
 else 
 OK = TRUE;
 end
 end
 if OK == TRUE 
 fprintf(1,'Selecione o destino da saída do resultado\n');
 fprintf(1,'1. Tela\n');
 fprintf(1,'2. Arquivo texto\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 if FLAG == 2
 fprintf(1,'Coloque o nome do arquivo na forma - drive:\\nome.ext\n');
 fprintf(1,'Por exemplo:   A:\\SAIDA.DTA\n');
 NAME = input(' ','s'); 
 OUP = fopen(NAME,'wt');
 else
 OUP = 1;
 end
 fprintf(1,'Escolha um valor de saída\n');
 fprintf(1,'1. Resposta somente\n');
 fprintf(1,'2. A tabela inteira\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 fprintf(OUP,'Método da Bissecção\n');
 if FLAG == 2 
 fprintf('%3s%12s%12s%14s%12s%12s%16s%18s\n', 'k',    'a_k',  'b_k',  'f(a_k)',  'f(b_k)', 'x_k', 'f(x_k)', '|x_k-x_{k-1}|');
  %fprintf( '%3d \t %3f  \t %3f \t %3f \t %3f \t %3f \t %3f \t %11f\n',0,A,B,F(A), F(B),(A+B)/2, F((A+B)/2),  '--');
% fprintf('%3d \t %3f  \t %3f \t %3f \t %3f \t %3f \t %3f \t %10f\n',0,A(1), B(1),F(A(1)), F(B(1)), P(1),F(P(1)),erro(0));
 end
% STEP 1
 K = 1;
% STEP 2
 OK = TRUE;
 while K <= NO & OK == TRUE 
% STEP 3
% Compute P(I)
 C = (B - A) / 2.0;
 P = A + C;
% STEP 4
 FP = F(P);
erro=abs(C);
 %erro(0)='nenhum valor';
%  erro(1)={};

 if (FLAG == 2  && K == 1) % <--- aquí, se k = 1 então não vai imprimir erro
 fprintf('%3d \t %3f  \t %3f \t %3f \t %3f \t %3.10f \t %3f \t %7s\n',K-1,A, B,FA, FB, P,FP,'---');
 else
 fprintf('%3d \t %3f  \t %3f \t %3f \t %3f \t %3.10f \t %3f \t %12.10f\n',K-1,A, B,FA, FB, P,FP,erro);
 end
 if erro < 1.0e-20 | C < TOL 
% procedure completed successfully
 fprintf(OUP,'\nSolução aproximada é   %11.10f \n',P);
 %fprintf(OUP,'com b = %12f\n',B);
 fprintf(OUP,'Lembre-se que o erro absoluto em k=0 não é calculado. Número de iterações = %3f.',K-1);
 %fprintf(OUP,'Lembre-se que o erro absoluto em k=0 não é calculado %3f \n',TOL);
 OK = FALSE;
 else
% STEP 5
 K = K+1;
% STEP 6
% compute A(I) and B(I)
 if FA*FP > 0
 A = P;
 FA = FP;
 else
 B = P;
 FB = FP;
 end
 end
 end
 if OK == TRUE 
% STEP 7
% procedure completed unsuccessfully
 %fprintf(OUP,'\nIteration number %3d',NO);
 %fprintf(OUP,' gave approximation %12.8f\n',P);
 %fprintf(OUP,'F(P) = %12.8f not within tolerance : %15.8e\n',FP,TOL);
 end
 if OUP ~= 1 
 %fclose(OUP);
 %fprintf(1,'Output file %s created successfully \n',NAME);
 end
 end
 