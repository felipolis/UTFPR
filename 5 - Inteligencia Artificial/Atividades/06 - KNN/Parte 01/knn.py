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
    distancia = input('Deseja usar a distância Euclidiana ou Manhattan? (euclidiana/manhattan) ')
    if distancia == 'euclidiana' or distancia == 'manhattan':
        break
    else:
        print('Entrada inválida!')

# PATH do arquivo:
path_treino = './data/treinamento.txt'
path_teste = './data/teste.txt'

# Tranforma os arquivos txt (com dados separados por espaço) em arquivos csv (com dados separados por vírgula)
with open(path_treino, 'r') as f:
    with open('./data/treinamento.csv', 'w') as f1:
        for line in f:
            f1.write(line.replace(' ', ','))
with open(path_teste, 'r') as f:
    with open('./data/teste.csv', 'w') as f1:
        for line in f:
            f1.write(line.replace(' ', ','))
path_treino = './data/treinamento.csv'
path_teste = './data/teste.csv'



# Carregar os dados de treinamento
df_treino = pd.read_csv(path_treino)
y_treino = df_treino.iloc[:, -1].values
X_treino = df_treino.iloc[:, :-1].values

# Carregar os dados de teste
df_teste = pd.read_csv(path_teste)
y_teste = df_teste.iloc[:, -1].values
X_teste = df_teste.iloc[:, :-1].values

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


