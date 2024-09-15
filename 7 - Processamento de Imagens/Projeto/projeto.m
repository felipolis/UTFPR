pkg load image;  # Carregar o pacote de imagem do GNU Octave

# Funções auxiliares para conversão RGB para HSI e HSI para RGB
function hsi = rgb2hsi(rgb)
    rgb = im2double(rgb);
    r = rgb(:, :, 1);
    g = rgb(:, :, 2);
    b = rgb(:, :, 3);
    num = 0.5 * ((r - g) + (r - b));
    den = sqrt((r - g).^2 + (r - b).*(g - b));
    theta = acos(num ./ (den + eps));
    H = theta;
    H(b > g) = 2 * pi - H(b > g);
    H = H / (2 * pi);
    S = 1 - 3 .* min(min(r, g), b) ./ (r + g + b + eps);
    I = (r + g + b) / 3;
    hsi = cat(3, H, S, I);
end

function rgb = hsi2rgb(hsi)
    H = hsi(:, :, 1) * 2 * pi;
    S = hsi(:, :, 2);
    I = hsi(:, :, 3);
    R = zeros(size(hsi, 1), size(hsi, 2));
    G = zeros(size(hsi, 1), size(hsi, 2));
    B = zeros(size(hsi, 1), size(hsi, 2));
    idx = find((0 <= H) & (H < 2 * pi / 3));
    B(idx) = I(idx) .* (1 - S(idx));
    R(idx) = I(idx) .* (1 + S(idx) .* cos(H(idx)) ./ cos(pi / 3 - H(idx)));
    G(idx) = 3 * I(idx) - (R(idx) + B(idx));
    idx = find((2 * pi / 3 <= H) & (H < 4 * pi / 3));
    H(idx) = H(idx) - 2 * pi / 3;
    R(idx) = I(idx) .* (1 - S(idx));
    G(idx) = I(idx) .* (1 + S(idx) .* cos(H(idx)) ./ cos(pi / 3 - H(idx)));
    B(idx) = 3 * I(idx) - (R(idx) + G(idx));
    idx = find((4 * pi / 3 <= H) & (H <= 2 * pi));
    H(idx) = H(idx) - 4 * pi / 3;
    G(idx) = I(idx) .* (1 - S(idx));
    B(idx) = I(idx) .* (1 + S(idx) .* cos(H(idx)) ./ cos(pi / 3 - H(idx)));
    R(idx) = 3 * I(idx) - (G(idx) + B(idx));
    rgb = cat(3, R, G, B);
end

# Passo 1: Carregar a imagem e converter para o formato HSI
img_rgb = imread('imagem.jpg');
img_hsi = rgb2hsi(img_rgb);
img_i = img_hsi(:, :, 3);  # Extrair o componente de intensidade

# Passo 2: Adicionar zero padding
[m, n] = size(img_i);
P = 2*m; Q = 2*n;
F = fft2(img_i, P, Q);

# Passo 3: Centralizar a transformada de Fourier
F = fftshift(F);

# Exibir e salvar o espectro de Fourier
spectrum = uint8(255 * mat2gray(log(1 + abs(F))));
subplot(2, 2, 1), imshow(spectrum, []), colormap gray, title('Espectro de Fourier da Imagem');
imwrite(mat2gray(spectrum), 'espectro_fourier.jpg');

# Passo 5: Carregar o filtro notch
notch_filter = im2double(imread('filtro.jpg'));

# Aplicar o filtro na frequência
F_filtered = F .* notch_filter;

# Passo 6: Descentralizar a transformada de Fourier
F_filtered = ifftshift(F_filtered);

# Passo 7: Transformada inversa de Fourier
img_filtered = real(ifft2(F_filtered));

# Remover zero padding
img_filtered = img_filtered(1:m, 1:n);

# Passo 8: Ajustar o contraste da imagem
gamma = 0.8;
img_contrast = img_filtered .^ gamma;

# Passo 9: Reconstituir a imagem HSI
img_hsi(:, :, 3) = img_contrast;

# Converter de volta para RGB
img_rgb_filtered = hsi2rgb(img_hsi);

# Passo 10: Exibir as imagens
subplot(2, 2, 2), imshow(img_rgb), title('Imagem Original');
subplot(2, 2, 3), imshow(img_rgb_filtered), title('Imagem Filtrada e com Contraste Ajustado');

# Salvar a imagem resultante
imwrite(img_rgb_filtered, 'imagem_filtrada_contraste_ajustado.jpg');

# Passo 11: Calcular e exibir a imagem de ruído removido
ruido_removido = img_i - img_filtered;
subplot(2, 2, 4), imshow(ruido_removido, []), colormap gray, title('Ruído Removido');

# Salvar a imagem de ruído removido
imwrite(mat2gray(ruido_removido), 'ruido_removido.jpg');

