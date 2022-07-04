format long
 % METHOD OF FALSE POSITION ALGORITHM 2.5
 %
 % To find a solution to f(x) = 0 given the continuous function
 % f on the interval [p0,p1], where f(p0) and f(p1) have
 % opposite signs:
 %
 % INPUT:   endpoints p0, p1; tolerance TOL;
 %          maximum number of iterations N0.
 %
 % OUTPUT:  approximate solution p or
 %          a message that the algorithm fails.
 syms('OK', 'P0', 'P1', 'X', 'Q0', 'Q1', 'TOL', 'NO', 'FLAG');
 syms('NAME', 'OUP', 'I', 'P', 'Q','x','s');
 TRUE = 1;
 FALSE = 0;
 fprintf(1,'Este é o método Regula Falsi\n');
 fprintf(1,'Insira a função f(x) em termos de  x\n');
 fprintf(1,'Por exemplo, cos(x)-x\n');
 s = input(' ');
 F = inline(s,'x');
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Insira as extremidades A < B em linhas separadas.\n');
 P0 = input(' '); 
 P1 = input(' ');
 if P0 > P1 
 X = P0;
 P0 = P1;
 P1 = X;
 end
 if P0 == P1 
 fprintf(1,'a não pode ser igual a b\n');
 else
 Q0 = F(P0);
 Q1 = F(P1);
 if Q0*Q1 > 0 
 fprintf(1,'f(a) e f(b) têm o mesmo sinal.\n');
 else
 OK = TRUE;
 end
 end
 end
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Insira Tolerância\n');
 TOL = input(' ');
 if TOL <= 0 
 fprintf(1,'Tolerance must be positive\n');
 else 
 OK = TRUE;
 end
 end
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Insira o número máximo de iterações - número inteiro positivo\n');
 NO = input(' ');
 if NO <= 0 
 fprintf(1,'número inteiro positivo\n');
 else 
 OK = TRUE;
 end
 end
 if OK == TRUE 
 fprintf(1,'Selecione a saída de destino\n');
 fprintf(1,'1. Tela\n');
 fprintf(1,'2. Arquivo de Texto\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 if FLAG == 2 
 fprintf(1,'Insira o nome do arquivo na forma - drive:\\nome.ext\n');
 fprintf(1,'or exemplo,   A:\\OUTPUT.DTA\n');
 NAME = input(' ','s');
 OUP = fopen(NAME,'wt');
 else
 OUP = 1;
 end
 fprintf(1,'Escolha um valor de saídat\n');
 fprintf(1,'1. Somente a resposta\n');
 fprintf(1,'2. Todas as iterações\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 fprintf(OUP, 'Método da Falsa Posição ou Regula Falsi\n\n');
 if FLAG == 2 
fprintf(OUP, '%3s%12s%23s\n', 'k',     'x_k',  '|x_k-x_{k-1}|');
 end
% STEP 1
 I = 2;
 OK = TRUE;
 Q0 = F(P0);
 Q1 = F(P1);
% STEP 2
 while I <= NO & OK == TRUE
% STEP 3
% compute P(I)
 P = P1-Q1*(P1-P0)/(Q1-Q0);
 Q = F(P);
 if FLAG == 2 
  fprintf(OUP, '%3d \t %8.10f  \t %8.10f\n', I, P, abs(P-P1));
 end
% STEP 4
 if abs(P-P1) < TOL 
% procedure completed successfully
 fprintf(OUP,'\nSolução aproximada P = %12.10f\n',P);
 %fprintf(OUP,'with F(P) = %12.8f\n',Q);
 fprintf(OUP,'com número de iterações = %3d',I);
 %fprintf(OUP,' Tolerance = %15.8e\n',TOL);
 OK = FALSE;
 else
% STEP 5
 I = I+1;
% STEP 6
% compute P0(I) and P1(I)
 if Q*Q1 < 0 
 P0 = P1;
 Q0 = Q1;
 end
% STEP 7
 P1 = P;
 Q1 = Q;
 end
 end
 if OK == TRUE 
% procedure completed unsuccessfully
 fprintf(OUP,'\nIteration number %3d',NO);
 fprintf(OUP,' gave approximation %12.8f\n',P);
 fprintf(OUP,'F(P) = %12.8f not within tolerance: %15.8e\n',Q,TOL);
 end
 if OUP ~= 1 
 fclose(OUP);
 fprintf(1,'Output file %s created successfully\n',NAME);
 end
 end