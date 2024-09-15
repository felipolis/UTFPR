img_gray = imread('imagem.jpg'); % Ler a imagem do disco

% Calcula o histograma não normalizado da imagem
[counts, ~] = imhist(img_gray);

% Calcula a função de distribuição cumulativa (CDF)
cdf = cumsum(counts) / numel(img_gray);

% Realiza a transformação dos níveis de intensidade
img_eq = cdf(double(img_gray)+1) * 255;

% Converte a imagem equalizada para o tipo de dados original
img_eq = uint8(img_eq);

% Exibindo a imagem original e a imagem equalizada lado a lado
figure; % Cria uma nova figura

subplot(2,2,1); % Ajusta para a primeira imagem na posição superior esquerda
imshow(img_gray);
title('Original');

subplot(2,2,2); % Ajusta para a segunda imagem na posição superior direita
imshow(img_eq);
title('Equalizada');

% Plotar o gráfico de T(r) na parte inferior esquerda
subplot(2,2,3);
plot((0:255), cdf*255);
axis([0 255 0 255]);
xlabel('Valores de intensidade originais');
ylabel('Valores de intensidade equalizados');
title('Função de Mapeamento T(r)');

% Calcula e plota o histograma equalizado na parte inferior direita
[counts_eq, ~] = imhist(img_eq); % Calcula o histograma da imagem equalizada
subplot(2,2,4); % Ajusta para plotar o histograma equalizado
bar((0:255), counts_eq, 'k');
axis([0 255 0 max(counts_eq)]); % Ajusta os eixos para melhor visualização
title('Histograma Equalizado');
xlabel('Valores de intensidade');
ylabel('Quantidade de Pixels');

% Salva a imagem equalizada no disco
imwrite(img_eq, 'imagem_equalizada.jpg');

