import os
import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import classification_report
from sklearn.model_selection import train_test_split, StratifiedKFold
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, f1_score
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.model_selection import GridSearchCV

TRAINING_FILE = '../data/caracteristicas/GABOR/GABOR_[03-PATCHES]_[10-CLASSES].csv'

############## SEPARANDO ENTRE DADOS DE TREINO E TESTE ##############

# Pega as duas primeiras colunas (key, nome_arquivo) do arquivo LBP.csv
df = pd.read_csv(TRAINING_FILE, usecols=[0, 1])

# Remove as linhas onde há um nome_arquivo repetido
df = df.drop_duplicates(subset=['nome_arquivo'])

# Coloca a coluna key em uma lista chamada classes e a coluna nome_arquivo em uma lista chamada arquivos
classes = df['key'].tolist()
arquivos = df['nome_arquivo'].tolist()

# Cria o objeto skf que divide os dados em 10 partes
skf = StratifiedKFold(n_splits=10)
acc = []
f1s = []

# Divide os dados em 10 partes
for train_index, test_index in skf.split(arquivos, classes):
  # Separe quais arquivos serão usados para treino e quais serão usados para teste
  arquivos_treino, arquivos_teste = np.array(arquivos)[train_index], np.array(arquivos)[test_index]
  classes_treino, classes_teste = np.array(classes)[train_index], np.array(classes)[test_index]

  # Carregar o arquivo de treino
  data = pd.read_csv(TRAINING_FILE)

  # Selecionar apenas as linhas que estão nos arquivos de treino
  data_treino = data[data['nome_arquivo'].isin(arquivos_treino)]

  # Selecionar apenas as linhas que estão nos arquivos de teste
  data_teste = data[data['nome_arquivo'].isin(arquivos_teste)]

  # Separa entre y_treino e x_treino
  y_treino = data_treino['key']
  x_treino = data_treino.drop(['key', 'nome_arquivo'], axis=1)

  # Separa entre y_teste e x_teste
  y_teste = data_teste['key']
  x_teste = data_teste.drop(['key', 'nome_arquivo'], axis=1)

  # Normaliza os dados
  scaler = StandardScaler()
  scaler.fit(x_treino)
  x_treino = scaler.transform(x_treino)
  x_teste = scaler.transform(x_teste)

  # Tratando os valores NaN
  x_treino = np.nan_to_num(x_treino)
  x_teste = np.nan_to_num(x_teste)

  # Encontra os melhores parâmetros para o SVM
  svm = SVC()
  C_range = [0.01, 0.1, 1, 10]
  kernel_options = ['linear', 'poly', 'rbf', 'sigmoid']
  gamma_range = list(np.logspace(-4, 1, 6, base=2)) + ['scale', 'auto']
  parametros_svm = dict(C=C_range, kernel=kernel_options, gamma=gamma_range)
  grid_svm = GridSearchCV(svm, parametros_svm, cv=5, scoring='f1_macro', verbose=1, n_jobs=-1)

  grid_svm.fit(x_treino, y_treino)

  print(f'Melhor valor de C: {grid_svm.best_params_["C"]}')
  print(f'Melhor valor de kernel: {grid_svm.best_params_["kernel"]}')
  print(f'Melhor valor de gamma: {grid_svm.best_params_["gamma"]}')
  print(f'Melhor F1 Macro AVG: {grid_svm.best_score_}')

  # Treina o SVM com os melhores parâmetros
  svm = SVC(C=grid_svm.best_params_["C"], kernel=grid_svm.best_params_["kernel"], gamma=grid_svm.best_params_["gamma"])
  svm.fit(x_treino, y_treino)

  # Faz a predição
  y_pred = svm.predict(x_teste)

  # Votação
  data_teste_votacao = data_teste.copy()
  data_teste_votacao['predicao'] = y_pred
  data_teste_votacao = data_teste_votacao.groupby('nome_arquivo')['predicao'].agg(lambda x:x.value_counts().index[0]).reset_index()

  data_teste_real = data_teste.drop_duplicates(subset=['nome_arquivo'])
  data_teste_real = data_teste_real.merge(data_teste_votacao, on='nome_arquivo')

  # Calcula a acurácia
  acc.append(accuracy_score(data_teste_real['key'], data_teste_real['predicao']))

  # Calcula o F1 Score
  f1s.append(f1_score(data_teste_real['key'], data_teste_real['predicao'], average='macro'))

print(f'Acurácia: {np.mean(acc)}')
print(f'F1 Score: {np.mean(f1s)}')

