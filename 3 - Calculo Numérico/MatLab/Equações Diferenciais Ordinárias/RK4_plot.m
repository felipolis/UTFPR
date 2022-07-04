clear all
clc
clc;clear;
 syms('NAME', 'OUP', 'I', 'P', 'Q','x','s','y');
 TRUE = 1;
 FALSE = 0;
 disp('Método de Runge-Kutta de Quarta Ordem');
a=input('\n Digite a condição inicial x0=a: '); %example x0=0
y0=input('\n Digite o valor de y0: '); %example y0=0.5
b=input('\n Insira o valor de b: ');% where we need to find the value of y 
                                            %example x=2
                                          
                                             fprintf(1,'Insira a função f(x,y) em termos de  x e y\n');
 fprintf(1,'Por exemplo, cos(x)-y\n');
 s = input(' ');
 f= inline(s,'x','y');
 h=input('\n Digite o valor do passo h: '); %example h=0.2
syms y(x)
% %dydt = subs(f,{y,x},{y_i,x_i})
% 
 true_sol = dsolve(diff(y,x,1) == f(x,y),y(a) == y0);
 fprintf('A solução analítica da e.d.o. é %s\n',true_sol);
                 % time step
x = a:h:b;                 %time range
y = zeros(size(x));     % set y array all 0's to same size as t
y(1) = y0;                  % set initial condition at time 0 to 2
 n = numel(y);
   disp('Método de Runge-Kutta de Quarta Ordem:');
   
 fprintf('\n%5s%19s%28s%28s%28s%28s%28s\n','i','x_i','k1','k2','k3','k4','y_i');
for i=1 :  n                    % for loop to interate through y values for
  k1 = f(x(i),y(i));
k2 = f(x(i)+0.5*h,y(i)+0.5*h*k1);
k3 = f((x(i)+0.5*h),(y(i)+0.5*h*k2));
k4 = f((x(i)+h),(y(i)+k3*h));

y(i+1) = y(i) + (1/6)*(k1+2*k2+2*k3+k4)*h;
  if i==n
    fprintf('%4d \t %8.10f \t %13s \t %25s \t %22s \t %20s  \t %22.10f \n',n-1, b,'---', '---','---','---', y(n));
else 
    fprintf('%4d \t %8.10f \t %8.10f \t %8.10f \t %4.10f \t %4.10f  \t %4.10f \n',i-1, x(i),k1, k2, k3, k4, y(i)); % RK4 update
end    
end

y1=y;
y1(n+1) = [];
y1;
t1=a-.5:h:b+.5;
plot(x,y1,'o')                                     %plot RK4
hold on
fplot(true_sol,[a-.5,b+.5]);     
hold off
