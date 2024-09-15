% Carrega as imagens
filamento = imread('tungsten_filament_shaded.tif');
sombreamento = imread('tungsten_sensor_shading.tif');

% Converte as imagens para double para evitar problemas de aritmética de inteiros
filamento_double = im2double(filamento);
sombreamento_double = im2double(sombreamento);

% Realiza a correção do sombreamento pela divisão da imagem pelo padrão de sombreamento
% Nota: É importante evitar a divisão por zero ou valores muito baixos no padrão de sombreamento.
% Podemos adicionar um pequeno valor (por exemplo, eps) para garantir a estabilidade numérica.
corrigida_double = filamento_double ./ (sombreamento_double + eps);

% Reescalonamento dos valores para o intervalo original de 0 a 255
corrigida = im2uint8(mat2gray(corrigida_double));

% Exibe a imagem original e a corrigida
figure;
subplot(1, 2, 1); imshow(filamento); title('Original');
subplot(1, 2, 2); imshow(corrigida); title('Corrigida');

% Salva a imagem corrigida
imwrite(corrigida, 'tungsten_filament_corrected.tif');

