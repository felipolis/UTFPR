import cv2
import numpy as np
import matplotlib.pyplot as plt

# Passo 1: Carregar a imagem de entrada
img = cv2.imread('pratica6.png', cv2.IMREAD_GRAYSCALE)

# Adicionar padding de zeros à imagem
M, N = img.shape
P = 2 * M
Q = 2 * N
padded_img = np.zeros((P, Q))
padded_img[:M, :N] = img

# Passo 2: Calcular o espectro de Fourier da imagem com padding
img_double = padded_img / 255.0
F = np.fft.fft2(img_double)
F_shifted = np.fft.fftshift(F)
spectro = np.log(1 + np.abs(F_shifted))

# Salvar o espectro de Fourier
cv2.imwrite('espectro.png', cv2.normalize(spectro, None, 0, 255, cv2.NORM_MINMAX).astype(np.uint8))

# Passo 3: Criar o filtro do zero
filtro = np.ones((P, Q))  # Começamos com uma matriz de uns
center_y = Q // 2
filtro[:, center_y-4:center_y+4] = 0  # Criamos uma linha vertical central de zeros com espessura de 5 pixels
filtro[P//2-10:P//2+10, center_y-4:center_y+4] = 1  # Deixamos um espaço em branco no centro

# Salvar o filtro criado
cv2.imwrite('filtro.png', cv2.normalize(filtro, None, 0, 255, cv2.NORM_MINMAX).astype(np.uint8))

# Passo 4: Aplicar o filtro no domínio da frequência
F_filtered = F_shifted * filtro

# Passo 5: Obter a imagem filtrada a partir do espectro filtrado
F_filtered_shifted_back = np.fft.ifftshift(F_filtered)
img_filtered = np.fft.ifft2(F_filtered_shifted_back)
img_filtered_real = np.real(img_filtered[:M, :N])  # Remover o padding

# Salvar a imagem do resultado obtido
cv2.imwrite('resultado.png', cv2.normalize(img_filtered_real, None, 0, 255, cv2.NORM_MINMAX).astype(np.uint8))

# Exibir todas as imagens em uma única janela
plt.figure(figsize=(10, 10))
plt.subplot(2, 2, 1)
plt.imshow(img, cmap='gray')
plt.title('Imagem de Entrada')
plt.subplot(2, 2, 2)
plt.imshow(spectro, cmap='gray')
plt.title('Espectro de Fourier')
plt.subplot(2, 2, 3)
plt.imshow(filtro, cmap='gray')
plt.title('Filtro Usado')
plt.subplot(2, 2, 4)
plt.imshow(img_filtered_real, cmap='gray')
plt.title('Imagem Filtrada')
plt.show()
