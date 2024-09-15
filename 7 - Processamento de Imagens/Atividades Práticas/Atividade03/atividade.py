import numpy as np
import cv2
from matplotlib import pyplot as plt

# Carregar a imagem do disco
img_gray = cv2.imread('imagem.jpg')

# Calcula o histograma não normalizado da imagem
counts, bins = np.histogram(img_gray.flatten(), 256, [0, 256])

# Calcula a função de distribuição cumulativa (CDF)
cdf = counts.cumsum()
cdf_normalized = cdf * counts.max() / cdf.max()

# Realiza a transformação dos níveis de intensidade (equalização)
cdf_m = np.ma.masked_equal(cdf, 0)
cdf_m = (cdf_m - cdf_m.min()) * 255 / (cdf_m.max() - cdf_m.min())
cdf = np.ma.filled(cdf_m, 0).astype('uint8')
img_eq = cdf[img_gray]

# Calcula o histograma da imagem equalizada
counts_eq, bins_eq = np.histogram(img_eq.flatten(), 256, [0, 256])

# Exibindo a imagem original e a imagem equalizada lado a lado
plt.figure(figsize=(18, 12))

plt.subplot(221)
plt.imshow(img_gray, cmap='gray')
plt.title('Original')

plt.subplot(222)
plt.imshow(img_eq, cmap='gray')
plt.title('Equalizada')

# Plotar o gráfico de T(r) na terceira parte
plt.subplot(223)
plt.plot(cdf_normalized, color='b')
plt.hist(img_gray.flatten(), 256, [0,256], color='r', alpha=0.5)
plt.xlim([0, 255])
plt.legend(('CDF','Histograma Original'), loc = 'upper left')
plt.title('Função de Mapeamento T(r) e Histograma Original')

# Plotando o histograma da imagem equalizada
plt.subplot(224)
plt.hist(img_eq.flatten(), 256, [0, 256], color='g', alpha=0.5)
plt.xlim([0, 255])
plt.title('Histograma Equalizado')

# Salva a imagem equalizada no disco
cv2.imwrite('imagem_equalizada.jpg', img_eq)

plt.show()
