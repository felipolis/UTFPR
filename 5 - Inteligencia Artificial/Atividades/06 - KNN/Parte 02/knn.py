import math
import pandas as pd
import random
import numpy as np

# Função para calcular a distância euclidiana entre dois pontos
def distancia_euclidiana(ponto1, ponto2):
    dim, soma = len(ponto1), 0
    for i in range(dim):
        soma += math.pow(ponto1[i] - ponto2[i], 2)
    return math.sqrt(soma)

# Função para calcular a distância de Manhattan entre dois pontos
def distancia_manhattan(ponto1, ponto2):
    dim, soma = len(ponto1), 0
    for i in range(dim):
        soma += abs(ponto1[i] - ponto2[i])
    return soma


def minmax_normalization(samples):
    """
    Aplica normalização Min-Max em cada coluna do array de amostras.
    
    Args:
    samples (numpy.ndarray): Array de amostras a ser normalizado
    
    Returns:
    numpy.ndarray: Array de amostras normalizado
    """
    # Calcula os valores mínimo e máximo de cada coluna
    min_vals = np.min(samples, axis=0)
    max_vals = np.max(samples, axis=0)
    
    # Calcula o intervalo de cada coluna
    ranges = max_vals - min_vals
    
    # Aplica a fórmula de normalização Min-Max em cada coluna
    normalized_samples = (samples - min_vals) / ranges
    
    return normalized_samples

def zscore_normalization(samples):
    """
    Aplica normalização Z-score em cada coluna do array de amostras.
    
    Args:
    samples (numpy.ndarray): Array de amostras a ser normalizado
    
    Returns:
    numpy.ndarray: Array de amostras normalizado
    """
    # Calcula a média e o desvio padrão de cada coluna
    means = np.mean(samples, axis=0)
    stds = np.std(samples, axis=0)
    
    # Aplica a fórmula de normalização Z-score em cada coluna
    normalized_samples = (samples - means) / stds
    
    return normalized_samples



class KNN:
    def __init__(self, k):
        self.k = k

    def treinar(self, X, y):
        self.X = X
        self.y = y

    def prever(self, ponto):
        distancias = {}
        for i in range(len(self.X)):
            if distancia == 'euclidiana':
                d = distancia_euclidiana(self.X[i], ponto)
            else:
                d = distancia_manhattan(self.X[i], ponto)
            distancias[i] = d
        # Ordenar as distâncias do menor para o maior e obter os índices correspondentes
        indices = sorted(distancias, key=distancias.get)[:self.k]
        # Obter as classes dos k vizinhos mais próximos
        classes = [self.y[i] for i in indices]
        # Retornar a classe mais frequente
        return max(set(classes), key=classes.count)

while True:
    k = input('Digite o valor de k: ')
    try:
        k = int(k)
        break
    except ValueError:
        print('Entrada inválida!')

while True:
    porcentagem = input('Deseja usar 25%, 50% ou 100% dos dados? (25/50/100) ')
    if porcentagem == '25':
        porcentagem = 0.25
        break
    elif porcentagem == '50':
        porcentagem = 0.5
        break
    elif porcentagem == '100':
        porcentagem = 1
        break
    else:
        print('Entrada inválida!')

while True:
    metodo = input('Deseja normalizar os dados com o método Min-Max ou Z-score? (minmax/zscore) ')
    if metodo == 'minmax' or metodo == 'zscore':
        break
    else:
        print('Entrada inválida!')

while True:
    distancia = input('Deseja usar a distância Euclidiana ou Manhattan? (euclidiana/manhattan) ')
    if distancia == 'euclidiana' or distancia == 'manhattan':
        break
    else:
        print('Entrada inválida!')

# PATH do arquivo:
path_treino = './data/treino_2x2.csv'
path_teste = './data/teste_2x2.csv'

# Carregar os dados de treinamento
df_treino = pd.read_csv(path_treino)
y_treino = df_treino['classe'].values
X_treino = df_treino.drop('classe', axis=1).values

# Carregar os dados de teste
df_teste = pd.read_csv(path_teste)
y_teste = df_teste['classe'].values
X_teste = df_teste.drop('classe', axis=1).values

# Normalizar os dados de treinamento e teste
if metodo == 'minmax':
    X_treino = minmax_normalization(X_treino)
    X_teste = minmax_normalization(X_teste)
else:
    X_treino = zscore_normalization(X_treino)
    X_teste = zscore_normalization(X_teste)

# Selecionar uma amostra aleatória dos dados de treinamento
n = int(porcentagem * len(X_treino))
indices = random.sample(range(len(X_treino)), n)
X_treino = [X_treino[i] for i in indices]
y_treino = [y_treino[i] for i in indices]

# Treinar o modelo
modelo = KNN(k)
modelo.treinar(X_treino, y_treino)

# Prever as classes dos dados de teste
y_pred = [modelo.prever(ponto) for ponto in X_teste]

# Calcular a acurácia
acuracia = sum(y_pred == y_teste) / len(y_teste)
print('Acurácia: {:.2f}%'.format(acuracia * 100))


