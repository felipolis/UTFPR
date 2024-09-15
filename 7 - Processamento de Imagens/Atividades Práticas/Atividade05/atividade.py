import numpy as np
import matplotlib.pyplot as plt
import imageio
from scipy.fft import fft2, ifft2, fftshift, ifftshift

# Passo 2: Carregar a imagem de entrada
img = imageio.imread('pratica5.png')

# Passo 3: Converter a imagem para double
img_double = img / 255.0

# Passo 4: Fazer o zero padding e aplicar a transformada rápida de Fourier 2D
m, n = img_double.shape
P = 2 * m
Q = 2 * n
F = fft2(img_double, (P, Q))

# Passo 5: Centralizar a transformada de Fourier
F_shifted = fftshift(F)

# Passo 6: Mostrar o espectro de Fourier
magnitude_spectrum = np.log(1 + np.abs(F_shifted))
magnitude_spectrum_uint8 = np.uint8(255 * (magnitude_spectrum / np.max(magnitude_spectrum)))

# Passo 7: Construir o filtro passa-baixa gaussiano
D0 = 20
u, v = np.meshgrid(np.arange(Q), np.arange(P))
D = np.sqrt((u - Q / 2) ** 2 + (v - P / 2) ** 2)
H = np.exp(-(D ** 2) / (2 * D0 ** 2))

# Passo 8: Multiplicar a transformada de Fourier pelo filtro gaussiano
G = F_shifted * H

# Passo 9: Descentralizar a matriz resultado
G_shifted_back = ifftshift(G)

# Passo 10: Aplicar a transformada inversa rápida de Fourier 2D
img_filtered = ifft2(G_shifted_back)

# Passo 11: Selecionar apenas a parte real da matriz
img_filtered_real = np.real(img_filtered)

# Passo 12: Obter o resultado final extraindo a região MxN
img_result = img_filtered_real[:m, :n]

# Passo 13: Mostrar a imagem do resultado final
img_result_uint8 = np.uint8(255 * img_result)

# Mostrar todas as imagens na mesma janela
plt.figure(figsize=(10, 10))

# Imagem de entrada
plt.subplot(2, 2, 1)
plt.imshow(img, cmap='gray')
plt.title('Imagem de Entrada')

# Espectro de Fourier
plt.subplot(2, 2, 2)
plt.imshow(magnitude_spectrum, cmap='gray')
plt.title('Espectro de Fourier')

# Filtro passa-baixa gaussiano
plt.subplot(2, 2, 3)
plt.imshow(H, cmap='gray')
plt.title('Filtro Passa-Baixa Gaussiano')

# Imagem final filtrada
plt.subplot(2, 2, 4)
plt.imshow(img_result_uint8, cmap='gray')
plt.title('Imagem Filtrada')

plt.show()
