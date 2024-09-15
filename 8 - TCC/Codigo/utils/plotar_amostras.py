import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
from sklearn.neighbors import KernelDensity
from scipy.spatial import distance

def calcular_ponto_maior_densidade(dados_classe):
    # Remove as linhas com valores ausentes
    dados_classe = dados_classe.dropna(subset=['longitude', 'latitude'])

    # Retorna None se não houver pontos de dados válidos
    if dados_classe.empty:
        return None

    # Cria uma matriz 2D com os valores de longitude e latitude
    data = dados_classe[['longitude', 'latitude']].values

    # Ajusta o modelo de Densidade Kernel aos dados
    kde = KernelDensity(bandwidth=1.0, kernel='gaussian')
    kde.fit(data)

    return kde, dados_classe

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

    # Armazenar os modelos KDE de cada classe e seus dados correspondentes
    kde_models = {}

    for class_name, class_data in grouped:
        kde_model, class_subset = calcular_ponto_maior_densidade(class_data)
        if kde_model is not None:
            kde_models[class_name] = (kde_model, class_subset)

    # Plotagem de todos os pontos das classes
    fig, ax = plt.subplots()

    # Criar um mapeamento de cores exclusivas para cada classe
    unique_colors = list(mcolors.CSS4_COLORS.values())[:len(kde_models)]

    # Atribuir cores únicas para cada classe presente nos dados e plotar seus pontos
    for idx, (class_name, (kde_model, class_subset)) in enumerate(kde_models.items()):
        # Amostrar pontos a partir do modelo de densidade kernel
        sampled_points = kde_model.sample(n_samples=len(class_subset), random_state=0)
        ax.scatter(sampled_points[:, 0], sampled_points[:, 1], color=unique_colors[idx], label=class_name)

    ax.legend()
    ax.get_legend().remove()
    plt.show()

    # salvar imagem com fundo transparente
    #fig.savefig('geral.png', transparent=True)

# Exemplo de uso da função
encontrar_classes_proximas('../data/metadata.csv', 100, 10)
