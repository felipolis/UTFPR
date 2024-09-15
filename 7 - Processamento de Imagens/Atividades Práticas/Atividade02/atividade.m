% 1. Carregue a imagem de entrada.
imgEntrada = imread('pollen.jpg');

% 2. Crie uma matriz de zeros com a mesma dimensão da imagem de entrada.
imgSaida = zeros(size(imgEntrada), 'uint8');

% 3. Defina as posições dos pontos (r1, s1) e (r2, s2).
%r1 = 90; s1 = 30;  % Definindo ponto r1, s1
%r2 = 140; s2 = 225; % Definindo ponto r2, s2

%r1 = 90; s1 = 15;  % Definindo ponto r1, s1
%r2 = 140; s2 = 240; % Definindo ponto r2, s2

r1 = 90; s1 = 0;  % Definindo ponto r1, s1
r2 = 140; s2 = 255; % Definindo ponto r2, s2

% 4. Utilize a equação da reta para definir a intensidade de saída (s)
% para cada intensidade de entrada (r).
T = zeros(256,1,'uint8'); % Inicializa o vetor de transformação
for r = 0:255
    if r < r1
        T(r+1) = uint8(double(s1)/r1*r);
    elseif r > r2
        T(r+1) = uint8(double(255-s2)/double(255-r2)*(r-r2) + s2);
    else
        T(r+1) = uint8(double(s2-s1)/double(r2-r1)*(r-r1) + s1);
    end
end

% 5. Exiba a sua função de transformação de intensidade.
plot(T); title('Função de Transformação de Intensidade');
xlabel('Intensidade de Entrada'); ylabel('Intensidade de Saída');
saveas(gcf, 'funcaoTransformacao.jpg');

% 6. A imagem de saída será obtendo aplicação a função T(r) sobre a imagem de entrada.
for i = 1:size(imgEntrada,1)
    for j = 1:size(imgEntrada,2)
        imgSaida(i,j) = T(imgEntrada(i,j)+1);
    end
end

% 7. Salve a imagem de saída em disco.
imwrite(imgSaida, 'imagemSaida.jpg');

figure;
subplot(1, 2, 1); imshow(imgEntrada); title('Imagem de Entrada');
subplot(1, 2, 2); imshow(imgSaida); title('Imagem de Saída');

% 8. Sobre a melhor configuração para (r1, s1) e (r2, s2), isso depende do contraste desejado.
%Foram realizados experimentos com diversos valores para os pontos (r1, s1) e (r2, s2) a fim de observar o impacto no contraste da imagem resultante. Os resultados foram os seguintes:
%Com r1=90, s1=30, e r2=140, s2=225: Observou-se uma melhoria significativa no contraste da imagem. No entanto, essa configuração não alcançou uma semelhança ótima com a imagem de saída desejada.
%Com r1=90, s1=15, e r2=140, s2=240: Houve uma melhoria adicional no contraste, superando a configuração anterior. Apesar da melhoria, a semelhança com a imagem de saída desejada ainda não foi totalmente alcançada.
%Com r1=90, s1=0, e r2=140, s2=255: Esta configuração resultou em uma notável intensificação do contraste, culminando em uma imagem que se assemelha de maneira ideal à imagem de saída esperada.
%Conclusão: A justificativa para a melhoria progressiva do contraste com a diminuição de s1 e o aumento de s2 reside na forma como essas alterações expandem a gama de intensidades de saída. Ao definir s1 para um valor mais baixo e s2 para o valor máximo permitido (255), a função de transformação de intensidade estica o espectro de intensidades ao longo de toda a faixa possível. Esse estiramento maximiza o contraste da imagem, pois as regiões escuras tornam-se mais escuras e as regiões claras tornam-se mais claras, ampliando a diferença de intensidade entre os diferentes elementos da imagem. Essa manipulação direta das intensidades de saída permite um controle refinado sobre o contraste da imagem resultante, o que é claramente demonstrado pela melhoria observada nas imagens de saída à medida que ajustamos os valores de s1 para baixo e de s2 para cima.

