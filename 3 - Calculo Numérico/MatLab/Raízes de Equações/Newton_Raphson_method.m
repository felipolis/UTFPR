
 % NEWTON-RAPHSON ALGORITHM 2.3               
 %
 % To find a solution to f(x) = 0 given an
 % initial approximation p0:
 %
 % INPUT:   initial approximation p0; tolerance TOL;
 %          maximum number of iterations NO.
 %
 % OUTPUT:  approximate solution p or a message of failure
 syms('OK', 'P0', 'P0prev', 'TOL', 'NO', 'FLAG', 'NAME', 'OUP', 'F0');
 syms('I', 'FP0', 'FPP0', 'D','x','s');
 TRUE = 1;
 FALSE = 0;
 fprintf(1,'Este é o método de Newton-Raphson\n');
 fprintf(1,'Insira a função f(x) em termos de  x\n');
 fprintf(1,'Por exemplo, x^2-2\n');
 syms x; % <-- Se declara a variável simbólica x
 s = input(' '); % <--- ingreso da função
 sp = diff(s,x); % <--- derivada da função
 spp = diff(sp,x); % <--- segunda derivada
 F = inline(s,'x'); % <--- paso de função simbólica a inline para que 
 FP = inline(sp,'x');%      o código possa trabalhar sem problemas
 FPP = inline(spp,'x');
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
  FPP0 = FPP(0);
 FPPA = FPP(A);
 if FPPA*FA>0
    P0 = A;
 else
     
     P0 = B;
 end
 end
 end
 OK = FALSE;
 while OK == FALSE 
 fprintf(1,'Digite Tolerância\n');
 TOL = input(' ');
 if TOL <= 0 
 fprintf(1,'Tolerância dever ser positiva\n');
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
 fprintf(1,'2. Arquivo de texto\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 if FLAG == 2 
 fprintf(1,'Insira o nome do arquivo na forma - drive:\\nome.ext\n');
 fprintf(1,'Por exemplo,   A:\\OUTPUT.DTA\n');
 NAME = input(' ','s');
 OUP = fopen(NAME,'wt');
 else
 OUP = 1;
 end
 fprintf(1,'Escolha um valor de saída\n');
 fprintf(1,'1. Somente a resposta\n');
 fprintf(1,'2. Todas as iterações\n');
 fprintf(1,'Digite 1 ou 2\n');
 FLAG = input(' ');
 fprintf(OUP, 'Newtons Method\n');
 if FLAG == 2 
 fprintf(OUP, '%3s%12s%23s\n', 'k',     'x_k',  '|x_k-x_{k-1}|');
% fprintf(OUP, '%3s%14f%10s\n', '0',  P0  ,  abs(U-P0));
 end
 F0 = F(P0);

% STEP 1
 I = 1;
 OK = TRUE;        
% STEP 2

 while I <= NO & OK == TRUE   
% STEP 3
% compute P(I)
 FP0 = FP(P0);
 D = F0/FP0;
% STEP 6
 P0prev = P0;
 P0 = P0 - D; 
 F0 = F(P0);
 if FLAG == 2 

 fprintf(OUP, '%3d \t %3.10f  \t %3.10f\n', I, P0, abs(P0-P0prev));
 end
% STEP 4
 if abs(P0prev-P0) < TOL 
% procedure completed successfully
 fprintf(OUP,'\nA solução aproximada é %.10f\n',P0);
 %fprintf(OUP,'with F(P) = %.10e\n',F0);
 fprintf(OUP,'Número de iterações = %d\n',I);
 %fprintf(OUP,'Tolerance = %.10f\n',TOL);
 OK = FALSE;
% STEP 5
 else
 I = I+1;
 end
 end
 if OK == TRUE 
% STEP 7
% procedure completed unsuccessfully
 fprintf(OUP,'\nIteration number %d',NO);
 fprintf(OUP,' gave approximation %.10e\n',P0);
 fprintf(OUP,'with F(P) = %.10e not within tolerance  %.10e\n',F0,TOL);
 end
 if OUP ~= 1
 fclose(OUP);
 fprintf(1,'Output file %s created successfully \n',NAME);
 end
 end