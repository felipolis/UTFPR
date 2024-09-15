import os
import cv2
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras.applications import VGG16
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Flatten
from tensorflow.keras.preprocessing import image
from skimage import feature
from tensorflow.keras.applications.vgg16 import preprocess_input
from sklearn.neighbors import KernelDensity
from scipy.spatial import distance

# Diretórios
diretorio_imagens = '../data/patches/patches_500_colunas' # MUDAR AQUI
arquivo_csv = '../data/caracteristicas/VGG16_[PATCHES-500-COLUNAS]_[10-CLASSES].csv' # MUDAR AQUI
diretorio_caracteristicas = '../data/caracteristicas/'
arquivo_metadata = '../data/metadata.csv'

# Constantes
QUANT_CLASSES = 10

# Funções
def calcular_ponto_maior_densidade(dados_classe):
	# Remove as linhas com valores ausentes
	dados_classe = dados_classe.dropna(subset=['longitude', 'latitude'])

	# Cria uma matriz 2D com os valores de longitude e latitude
	data = dados_classe[['longitude', 'latitude']].values

	if len(data) == 0:
			return None  # Retorna None se não houver pontos de dados válidos

	# Ajusta o modelo de Densidade Kernel aos dados
	kde = KernelDensity(bandwidth=1.0, kernel='gaussian')
	kde.fit(data)

	# Gera pontos amostrados para obter uma estimativa melhor da densidade máxima
	pontos_amostrados = kde.sample(n_samples=1000, random_state=0)

	# Encontra o ponto com a maior densidade entre os pontos amostrados
	indice_maior_densidade = kde.score_samples(pontos_amostrados).argmax()
	ponto_maior_densidade = pontos_amostrados[indice_maior_densidade]

	return ponto_maior_densidade

def calcular_ponto_referencia(data):
	# Pega as coordenadas de cada classe
	coordenadas = [coordenadas for classe, coordenadas in data.items()]

	# Ajusta o modelo de Densidade Kernel aos dados
	kde = KernelDensity(bandwidth=1.0, kernel='gaussian')
	kde.fit(coordenadas)

	# Gera pontos amostrados para obter uma estimativa melhor da densidade máxima
	pontos_amostrados = kde.sample(n_samples=1000, random_state=0)

	# Encontra o ponto com a maior densidade entre os pontos amostrados
	indice_maior_densidade = kde.score_samples(pontos_amostrados).argmax()
	ponto_maior_densidade = pontos_amostrados[indice_maior_densidade]

	return ponto_maior_densidade

def encontrar_classes_proximas(arquivo_csv, numero_minimo_amostras, N):
	# Ler o arquivo CSV
	data = pd.read_csv(arquivo_csv)

	# Contar o número de amostras por classe
	class_counts = data['primary_label'].value_counts()

	# Selecionar classes com mais de 'numero_minimo_amostras' amostras
	selected_classes = class_counts[class_counts > numero_minimo_amostras].index.tolist()

	# Filtrar os dados para classes selecionadas
	filtered_data = data[data['primary_label'].isin(selected_classes)]

	# Agrupar por classe
	grouped = filtered_data.groupby('primary_label')

	# Encontrar os pontos de maior densidade para cada classe
	for class_name, class_data in grouped:
		highest_density_point = calcular_ponto_maior_densidade(class_data)
		highest_density_points[class_name] = highest_density_point

	# Encontrar o ponto de referência
	reference_point = calcular_ponto_referencia(highest_density_points)

	# Ordenar os pontos por distância para o ponto de referência
	distances = {class_name: distance.euclidean(reference_point, point) for class_name, point in highest_density_points.items()}
	sorted_distances = sorted(distances.items(), key=lambda x: x[1])

	# Selecionar as N classes mais próximas do ponto de referência
	closest_classes = [class_name for class_name, dist in sorted_distances[:N]]

	return closest_classes

def extrair_lat_long(metadata_csv, filename):
	# Extrair a classe do nome do arquivo
	classe = filename.split('/')[0]

	# Carregar o arquivo CSV de metadados
	metadata = pd.read_csv(metadata_csv)

	# Encontrar os registros correspondentes no metadata.csv com base na classe e no nome do arquivo
	metadata_subset = metadata[(metadata['primary_label'] == classe) & (metadata['filename'].str.contains(filename))]

	latitude = metadata_subset['latitude'].values[0]
	longitude = metadata_subset['longitude'].values[0]

	# Verifica se latitude e longitude são válidas
	if np.isnan(latitude) or np.isnan(longitude):
		latitude = highest_density_points[classe][1]
		longitude = highest_density_points[classe][0]

		return latitude, longitude
	
	return latitude, longitude

def extrair_caracteristicas_VGG16(imagem):
    # Redimensione a imagem para o tamanho esperado pelo modelo VGG16
    imagem = cv2.resize(imagem, (224, 224))
    # Pré-processamento da imagem de acordo com as especificações da VGG16
    imagem = preprocess_input(imagem)
    # Expanda as dimensões da imagem para corresponder ao input_shape do modelo
    imagem = np.expand_dims(imagem, axis=0)
    # Obtenha as características usando o modelo VGG16
    features = vgg_model.predict(imagem)
    # Aplique flatten nas características
    features = features.flatten()
    return features

def main():
    classes = encontrar_classes_proximas(arquivo_metadata, 100, QUANT_CLASSES)
    classes = ['rerswa1']
    print(f"Classes com mais imagens: {classes}")

    # Crie o diretório se não existir
    if not os.path.exists(diretorio_caracteristicas):
        os.makedirs(diretorio_caracteristicas)

    # Inicialize um DataFrame vazio para armazenar as características LBP
    df = pd.DataFrame()

    # Percorra os diretórios da lista de classes
    for key in os.listdir(diretorio_imagens):
        if key in classes:
            key_path = os.path.join(diretorio_imagens, key)

            # Percorra todas as imagens no diretório
            for image_name in os.listdir(key_path):
                image_path = os.path.join(key_path, image_name)

                # Obtenha o nome do arquivo original
                nome_arquivo_original = image_name.split('_')[0]

                # Extrair latitude e longitude do metadata.csv com base no nome do arquivo
                filename = f"{key}/{nome_arquivo_original}.ogg"
                latitude, longitude = extrair_lat_long('../data/metadata.csv', filename)

                if latitude is not None and longitude is not None:
                    # Carregue a imagem
                    image = cv2.imread(image_path)

                    # Calcule o vetor de características Gabor
                    caracteristicas_vgg16 = extrair_caracteristicas_VGG16(image)

                    # Adicione as características ao DataFrame
                    data_to_append = pd.Series([key, nome_arquivo_original, latitude, longitude] + list(caracteristicas_vgg16))

                    # Concatene os dados ao DataFrame principal
                    df = pd.concat([df, data_to_append.to_frame().T], ignore_index=True)

                    print(f'Processando {image_path}')
                else:
                    print(f'Erro ao processar {image_path}')

            # Salve o DataFrame em um arquivo CSV após processar uma classe
            # Defina os nomes das colunas no DataFrame
            colunas = ['key', 'nome_arquivo', 'latitude', 'longitude'] + [f'VGG16_{i}' for i in range(len(caracteristicas_vgg16))]
            df.columns = colunas

            # Salve os dados no arquivo CSV
            df.to_csv(arquivo_csv, mode='a', index=False, header=not os.path.exists(arquivo_csv))

            # Reinicie o DataFrame para a próxima classe
            df = pd.DataFrame()

if __name__ == '__main__':
    vgg_model = VGG16(weights='imagenet', include_top=False, pooling='avg', input_shape=(224, 224, 3))
    highest_density_points = {}
    main()
    