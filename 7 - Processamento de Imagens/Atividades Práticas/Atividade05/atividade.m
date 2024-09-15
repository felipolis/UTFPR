pkg load image;

% Passo 2: Carregar a imagem de entrada
img = imread('pratica5.png');

% Passo 3: Converter a imagem para double
img_double = im2double(img);

% Passo 4: Fazer o zero padding e aplicar a transformada rápida de Fourier 2D
[m, n] = size(img_double);
P = 2*m;
Q = 2*n;
F = fft2(img_double, P, Q);

% Dimensão da transformada: P x Q
% A dimensão da transformada é 512 x 512

% Passo 5: Centralizar a transformada de Fourier
F_shifted = fftshift(F);

% Passo 6: Mostrar o espectro de Fourier
magnitude_spectrum = uint8(255 * mat2gray(log(1 + abs(F_shifted))));

% Passo 7: Construir o filtro passa-baixa gaussiano
D0 = 20;
[u, v] = meshgrid(0:Q-1, 0:P-1);
D = sqrt((u - Q/2).^2 + (v - P/2).^2);
H = exp(-(D.^2) / (2*D0^2));

% Passo 8: Multiplicar a transformada de Fourier pelo filtro gaussiano
G = F_shifted .* H;

% Passo 9: Descentralizar a matriz resultado
G_shifted_back = ifftshift(G);

% Passo 10: Aplicar a transformada inversa rápida de Fourier 2D
img_filtered = ifft2(G_shifted_back);

% Passo 11: Selecionar apenas a parte real da matriz
img_filtered_real = real(img_filtered);

% Passo 12: Obter o resultado final extraindo a região MxN
img_result = img_filtered_real(1:m, 1:n);

% Passo 13: Mostrar a imagem do resultado final
img_result_uint8 = im2uint8(img_result);

% Mostrar todas as imagens na mesma janela
figure;

% Imagem de entrada
subplot(2, 2, 1);
imshow(img);
title('Imagem de Entrada');

% Espectro de Fourier
subplot(2, 2, 2);
imshow(magnitude_spectrum);
title('Espectro de Fourier');

% Filtro passa-baixa gaussiano
subplot(2, 2, 3);
imshow(mat2gray(H));
title('Filtro Passa-Baixa Gaussiano');

% Imagem final filtrada
subplot(2, 2, 4);
imshow(img_result_uint8);
title('Imagem Filtrada');


