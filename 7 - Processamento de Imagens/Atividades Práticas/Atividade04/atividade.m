% Carregar imagem de entrada
I = imread('pratica4.jpg');

% Converter a imagem para double
I_double = im2double(I);

% Criar um filtro de média 9x9
filtro_media = ones(9, 9) / 81;

% Aplicar o filtro de média usando a função filter2
J1 = filter2(filtro_media, I_double, 'same');

% Adicionar padding replicando os pixels da borda
padded_image = padarray(I_double, [4 4], 'replicate', 'both');

% Aplicar o filtro de média na imagem com padding
J2 = filter2(filtro_media, padded_image, 'valid');

% Definir os filtros de Sobel
sobel_x = [1 0 -1; 2 0 -2; 1 0 -1];
sobel_y = [1 2 1; 0 0 0; -1 -2 -1];

% Aplicar os filtros de Sobel
Gx = filter2(sobel_x, padded_image, 'valid');
Gy = filter2(sobel_y, padded_image, 'valid');

% Calcular a magnitude do gradiente
M = abs(Gx) + abs(Gy);

% Exibir todas as imagens juntas para comparação
figure;
subplot(2,2,1), imshow(I), title('Imagem Original');
subplot(2,2,2), imshow(J1), title('Imagem com Filtro de Média');
subplot(2,2,3), imshow(J2), title('Imagem com Filtro de Média com Padding');
subplot(2,2,4), imshow(M), title('Magnitude do Gradiente com Sobel');

% RESULTADOS:
% Aplicação do Filtro de Média ('same'):
% A imagem resultante mostra um borramento geral devido ao efeito de suavização do filtro de média. Utilizando o parâmetro 'same' na função filter2, as dimensões da imagem permanecem inalteradas, mas as bordas aparecem mais escuras. Isso ocorre porque a operação de média não é totalmente aplicável nas bordas, onde faltam pixels para completar a vizinhança definida pelo filtro.

% Aplicação do Filtro de Média com Padding:
% Neste caso, o padding replicado minimiza os efeitos de borda escurecida observados anteriormente. A replicação dos pixels da borda antes de aplicar o filtro de média assegura que cada pixel da imagem tenha uma vizinhança completa para a operação de média, resultando em um borramento uniforme em toda a imagem, incluindo as bordas.

% Aplicação dos Filtros de Sobel:
% Os filtros de Sobel são aplicados para destacar as bordas verticais e horizontais. A imagem resultante, mostrando a magnitude do gradiente, revela as bordas com alta clareza e precisão. As bordas aparecem mais grossas e definidas, destacando transições abruptas de intensidade que indicam as fronteiras dos objetos na imagem. Essa técnica é crucial para aplicações de detecção de bordas em processamento de imagens.

% Visualização Geral:
% A comparação lado a lado das imagens mostra claramente o efeito de cada operação. A imagem original serve como referência, enquanto a imagem com filtro de média mostra o suavizado geral, a imagem com filtro de média e padding não apresenta as bordas escuras, e a imagem de magnitude do gradiente Sobel destaca efetivamente as bordas e contornos dentro da imagem.


