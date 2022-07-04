clear all
clc
clc;clear;
syms('NAME', 'OUP', 'I', 'P', 'Q','x','s','y');
 TRUE = 1;
 FALSE = 0;
 disp('Método de Euler');
a=input('\n Digite a condição inicial x0=a: '); %example x0=0
y0=input('\n Digite o valor de y0: '); %example y0=0.5
b=input('\n Insira o valor de b: ');% where we need to find the value of y 
                                            %example x=2
                                          
                                             fprintf(1,'Insira a função f(x,y) em termos de  x e y\n');
 fprintf(1,'Por exemplo, cos(x)-y\n');
 s = input(' ');
 f= inline(s,'y','x');
 h=input('\n Digite o valor do passo h: '); %example h=0.2
 syms y(x)
%dydt = subs(f,{y,x},{y_i,x_i})

true_sol = dsolve(diff(y,x,1) == f(y,x),y(a) == y0);
fprintf('A solução analítica da e.d.o. é %s\n',true_sol);
                 % time step
x = a:h:b;                 %time range
y = zeros(size(x));     % set y array all 0's to same size as t
y(1) = y0;                  % set initial condition at time 0 to 2
n = numel(y);
fprintf(' \t %4s \t %13s','x_i','y_i');
for i=1 :  n-1                           % for loop to interate through y values for
    y(i+1)= y(i)+ h * f(y(i),x(i));  
     fprintf('\n%4.10f  %4.10f ',x(i),y(i)); % Euler update
end
fprintf('\n%4.10f  %4.10f ',b,y(n));
t1=a-.5:h:b+.5;
plot(x,y,'o')                                     %plot Euler
hold on
fplot(true_sol,[a-.5,b+.5]);     
hold off
% plots the exact solution to this differential equation