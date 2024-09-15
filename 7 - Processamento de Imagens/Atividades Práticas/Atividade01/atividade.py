import cv2
import numpy as np

# Carrega as imagens
filamento = cv2.imread('tungsten_filament_shaded.tif', cv2.IMREAD_UNCHANGED)
sombreamento = cv2.imread('tungsten_sensor_shading.tif', cv2.IMREAD_UNCHANGED)

# Converte as imagens para double para evitar problemas de aritmética de inteiros
filamento_float = filamento.astype(np.float32)
sombreamento_float = sombreamento.astype(np.float32)

# Evita a divisão por zero adicionando um pequeno valor ao denominador
sombreamento_float[sombreamento_float == 0] = np.finfo(np.float32).eps

# Realiza a correção do sombreamento
corrigida_float = filamento_float / sombreamento_float

# Normaliza a imagem corrigida para o intervalo [0, 255] e converte para uint8
corrigida = cv2.normalize(corrigida_float, None, 0, 255, cv2.NORM_MINMAX).astype('uint8')

# Exibe a imagem original e a corrigida
cv2.imshow('Original', filamento)
cv2.imshow('Corrigida', corrigida)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Salva a imagem corrigida
cv2.imwrite('tungsten_filament_corrected.tif', corrigida)
