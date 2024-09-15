pkg load image;

% Passo 1: Carregar a imagem de entrada
img = imread('pratica6.png');

% Adicionar padding de zeros à imagem
[M, N] = size(img);
P = 2 * M;
Q = 2 * N;
padded_img = zeros(P, Q);
padded_img(1:M, 1:N) = img;

% Passo 2: Calcular o espectro de Fourier da imagem com padding
img_double = im2double(padded_img);
F = fft2(img_double);
F_shifted = fftshift(F);
spectro = log(1 + abs(F_shifted));

% Salvar o espectro de Fourier
imwrite(mat2gray(spectro), 'espectro.png');

% Passo 3: Criar o filtro do zero
filtro = ones(P, Q);  % Começamos com uma matriz de uns
center_y = round(Q / 2);
filtro(:, center_y-4:center_y+4) = 0;  % Criamos uma linha vertical central de zeros com espessura de 5 pixels
filtro(round(P/2)-8:round(P/2)+8, center_y-4:center_y+4) = 1;  % Deixamos um espaço em branco no centro

% Salvar o filtro criado
imwrite(mat2gray(filtro), 'filtro.png');

% Passo 4: Aplicar o filtro no domínio da frequência
F_filtered = F_shifted .* filtro;

% Passo 5: Obter a imagem filtrada a partir do espectro filtrado
F_filtered_shifted_back = ifftshift(F_filtered);
img_filtered = ifft2(F_filtered_shifted_back);
img_filtered_real = real(img_filtered(1:M, 1:N));  % Remover o padding

% Salvar a imagem do resultado obtido
imwrite(mat2gray(img_filtered_real), 'resultado.png');

% Exibir todas as imagens em uma única janela
figure;
subplot(2,2,1), imshow(img), title('Imagem de Entrada');
subplot(2,2,2), imshow(mat2gray(spectro)), title('Espectro de Fourier');
subplot(2,2,3), imshow(mat2gray(filtro)), title('Filtro Usado');
subplot(2,2,4), imshow(mat2gray(img_filtered_real)), title('Imagem Filtrada');

