import cv2
import numpy as np
from matplotlib import pyplot as plt

# Carregar imagem de entrada
I = cv2.imread('pratica4.jpg', cv2.IMREAD_GRAYSCALE)

# Converter a imagem para double
I_double = I.astype(np.float64) / 255

# Criar um filtro de média 9x9
filtro_media = np.ones((9, 9)) / 81

# Aplicar o filtro de média
J1 = cv2.filter2D(I_double, -1, filtro_media, borderType=cv2.BORDER_CONSTANT)

# Adicionar padding replicando os pixels da borda
padded_image = cv2.copyMakeBorder(I_double, 4, 4, 4, 4, cv2.BORDER_REPLICATE)

# Aplicar o filtro de média na imagem com padding
J2 = cv2.filter2D(padded_image, -1, filtro_media)[4:-4, 4:-4]

# Definir os filtros de Sobel
sobel_x = np.array([[1, 0, -1], [2, 0, -2], [1, 0, -1]], dtype=np.float64)
sobel_y = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]], dtype=np.float64)

# Aplicar os filtros de Sobel
Gx = cv2.filter2D(padded_image, -1, sobel_x)[4:-4, 4:-4]
Gy = cv2.filter2D(padded_image, -1, sobel_y)[4:-4, 4:-4]

# Calcular a magnitude do gradiente
M = np.abs(Gx) + np.abs(Gy)

# Exibir todas as imagens juntas para comparação
plt.figure(figsize=(10, 8))
plt.subplot(2, 2, 1)
plt.imshow(I, cmap='gray')
plt.title('Imagem Original')
plt.axis('off')

plt.subplot(2, 2, 2)
plt.imshow(J1, cmap='gray')
plt.title('Imagem com Filtro de Média')
plt.axis('off')

plt.subplot(2, 2, 3)
plt.imshow(J2, cmap='gray')
plt.title('Imagem com Filtro de Média com Padding')
plt.axis('off')

plt.subplot(2, 2, 4)
plt.imshow(M, cmap='gray')
plt.title('Magnitude do Gradiente com Sobel')
plt.axis('off')

plt.show()

""" 
RESULTADOS:
Aplicação do Filtro de Média ('same'):
A imagem resultante mostra um borramento geral devido ao efeito de suavização do filtro de média. Utilizando o parâmetro 'same' na função filter2, as dimensões da imagem permanecem inalteradas, mas as bordas aparecem mais escuras. Isso ocorre porque a operação de média não é totalmente aplicável nas bordas, onde faltam pixels para completar a vizinhança definida pelo filtro.

Aplicação do Filtro de Média com Padding:
Neste caso, o padding replicado minimiza os efeitos de borda escurecida observados anteriormente. A replicação dos pixels da borda antes de aplicar o filtro de média assegura que cada pixel da imagem tenha uma vizinhança completa para a operação de média, resultando em um borramento uniforme em toda a imagem, incluindo as bordas.

Aplicação dos Filtros de Sobel:
Os filtros de Sobel são aplicados para destacar as bordas verticais e horizontais. A imagem resultante, mostrando a magnitude do gradiente, revela as bordas com alta clareza e precisão. As bordas aparecem mais grossas e definidas, destacando transições abruptas de intensidade que indicam as fronteiras dos objetos na imagem. Essa técnica é crucial para aplicações de detecção de bordas em processamento de imagens.

Visualização Geral:
A comparação lado a lado das imagens mostra claramente o efeito de cada operação. A imagem original serve como referência, enquanto a imagem com filtro de média mostra o suavizado geral, a imagem com filtro de média e padding não apresenta as bordas escuras, e a imagem de magnitude do gradiente Sobel destaca efetivamente as bordas e contornos dentro da imagem.

"""