
 % FIXED-POINT ALGORITHM 2.2
 %
 % To find a solution to p = g(p) given an
 % initial approximation p0
 %
 % INPUT:  initial approximation p0; tolerance TOL;
 %         maximum number of iterations NO.
 %
 % OUTPUT: approximate solution p or 
 %         a message that the method fails.
 format long
 syms('OK', 'P0', 'TOL', 'NO', 'FLAG', 'NAME', 'OUP', 'I', 'P');
 syms('x','s');
 TRUE = 1;
 FALSE = 0;
 fprintf(1,'Este é o Método do Ponto Fixo.\n');
 fprintf(1,'Insira a função de iteração F(x) em termos de x\n');
 fprintf(1,'Por exemplo,para a equação f(x)=cos(x)-x=0, vamos escolher F(x)= cos(x) \n');
 s = input(' ');
 G = inline(s,'x');
 OK = FALSE;
 fprintf(1,'Coloque a aproximação inicial x_0\n');
 P0 = input(' '); 
 while OK == FALSE 
 fprintf(1,'Insira tolerância\n');
 TOL = input(' ');
 if TOL <= 0 
 fprintf(1,'Tolerância deve ser positiva\n');
 else 
 OK = TRUE;
 end
 end
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Insira número máximo de iterações - número inteiro positivo\n');
 NO = input(' ');
 if NO <= 0 
 fprintf(1,'Deve ser inteiro positivo\n');
 else 
 OK = TRUE;
 end
 end
 if OK == TRUE 
 fprintf(1,'Selecione a saída de destino\n');
 fprintf(1,'1. Tela\n');
 fprintf(1,'2. Arquivo de texto\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 if FLAG == 2 
 fprintf(1,'Insira o nome do arquivo da forma - drive:\\nome.ext\n');
 fprintf(1,'Por exemplo,   A:\\OUTPUT.DTA\n');
 NAME = input(' ','s');
 OUP = fopen(NAME,'wt');
 else
 OUP = 1;
 end
 fprintf(1,'Escolha um valor de saída\n');
 fprintf(1,'1. Somente a resposta\n');
 fprintf(1,'2. A tabela completa\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 fprintf(OUP, 'FIXED-POINT METHOD\n');
 if FLAG == 2 
 fprintf(OUP, '%3s%12s%23s\n', 'k',     'x_k',  '|x_k-x_{k-1}|');
 fprintf(OUP, '%3s%14f%16s\n', '0',  P0  ,  '--');
 end
% STEP 1
 I = 1;
 OK = TRUE; 
% STEP 2
 while I <= NO & OK == TRUE 
% STEP 3
% compute P(I)
 P = G(P0);
 if FLAG == 2 
     format long
 fprintf(OUP, '%3d \t %3.10f  \t %3.10f\n', I, P, abs(P-P0));
 end
% STEP 4
 if abs(P-P0) < TOL 
% procedure completed successfully
 fprintf(OUP, '\nSolução aproximada P = %12.10f\n', P);
 fprintf(OUP, 'Número de iterações = %3d', I);
 %fprintf(OUP, '    Tolerância = %14.8e\n',TOL);
 OK = FALSE;
 else
% STEP 5
 I = I+1;
% STEP 6
% update P0
 P0 = P;
 end
 end
 if OK == TRUE 
% STEP 7
% procedure completed unsuccessfully
 fprintf(OUP, '\nIteration number %3d', NO);
 fprintf(OUP, ' gave approximation %12.8f\n', P);
 fprintf(OUP, 'not within tolerance %14.8e\n',TOL);
 end
 if OUP ~= 1
 fclose(OUP);
 fprintf(1,'Output file %s created successfully \n',NAME);
 end
 end

