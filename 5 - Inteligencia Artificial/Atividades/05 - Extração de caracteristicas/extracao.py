from PIL import Image
import os
import numpy as np

def contar_pixels_1x1(diretorio):
    resultados = [] # lista de dicionários

    for classe in os.listdir(diretorio):    # Para cada diretorio de classe
        classe_dir = os.path.join(diretorio, classe)
        for arquivo in os.listdir(classe_dir):  # Para cada arquivo de imagem
            if arquivo.endswith(".bmp"):    # Se o arquivo for uma imagem
                caminho = os.path.join(classe_dir, arquivo) # Caminho da imagem
                imagem = Image.open(caminho)    # Abre a imagem
                pixels = imagem.load()  # Carrega os pixels da imagem
                largura, altura = imagem.size   # Tamanho da imagem

                # Define o tamanho dos quadrantes
                quadrante_largura = largura
                quadrante_altura = altura

                # Dicionário para armazenar os resultados
                resultado = {
                    'classe': classe,
                    'quadrante1': {
                        'brancos': 0,
                        'pretos': 0
                    }
                }

                # Conta os pixels pretos e brancos do quadrante atual
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante1']['pretos'] += 1
                        else:
                            resultado['quadrante1']['brancos'] += 1

                # Adiciona o resultado na lista de resultados
                resultados.append(resultado)

    return resultados

def contar_pixels_2x2(diretorio):
    resultados = [] # lista de dicionários

    for classe in os.listdir(diretorio):    # Para cada diretorio de classe
        classe_dir = os.path.join(diretorio, classe)
        for arquivo in os.listdir(classe_dir):  # Para cada arquivo de imagem
            if arquivo.endswith(".bmp"):    # Se o arquivo for uma imagem
                caminho = os.path.join(classe_dir, arquivo) # Caminho da imagem
                imagem = Image.open(caminho)    # Abre a imagem
                pixels = imagem.load()  # Carrega os pixels da imagem
                largura, altura = imagem.size   # Tamanho da imagem

                # Define o tamanho dos quadrantes
                quadrante_largura = largura // 2
                quadrante_altura = altura // 2

                # Dicionário para armazenar os resultados
                resultado = {
                    'classe': classe,
                    'quadrante1': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante2': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante3': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante4': {
                        'brancos': 0,
                        'pretos': 0
                    }
                }

                # Conta os pixels pretos e brancos do primeiro quadrante (1/4)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante1']['pretos'] += 1
                        else:
                            resultado['quadrante1']['brancos'] += 1

                # Conta os pixels pretos e brancos do segundo quadrante (2/4)
                for x in range(quadrante_largura, largura):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante2']['pretos'] += 1
                        else:
                            resultado['quadrante2']['brancos'] += 1

                # Conta os pixels pretos e brancos do terceiro quadrante (3/4)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura, altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante3']['pretos'] += 1
                        else:
                            resultado['quadrante3']['brancos'] += 1

                # Conta os pixels pretos e brancos do quarto quadrante (4/4)
                for x in range(quadrante_largura, largura):
                    for y in range(quadrante_altura, altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante4']['pretos'] += 1
                        else:
                            resultado['quadrante4']['brancos'] += 1

                # Adiciona o resultado na lista de resultados
                resultados.append(resultado)

    return resultados

def contar_pixels_3x3(diretorio):
    resultados = [] # lista de dicionários

    for classe in os.listdir(diretorio):    # Para cada diretorio de classe
        classe_dir = os.path.join(diretorio, classe)
        for arquivo in os.listdir(classe_dir):  # Para cada arquivo de imagem
            if arquivo.endswith(".bmp"):    # Se o arquivo for uma imagem
                caminho = os.path.join(classe_dir, arquivo) # Caminho da imagem
                imagem = Image.open(caminho)    # Abre a imagem
                pixels = imagem.load()  # Carrega os pixels da imagem
                largura, altura = imagem.size   # Tamanho da imagem

                # Define o tamanho dos quadrantes
                quadrante_largura = largura // 3
                quadrante_altura = altura // 3

                # Dicionário para armazenar os resultados
                resultado = {
                    'classe': classe,
                    'quadrante1': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante2': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante3': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante4': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante5': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante6': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante7': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante8': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante9': {
                        'brancos': 0,
                        'pretos': 0
                    }
                }

                # Conta os pixels pretos e brancos do primeiro quadrante (1/9)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante1']['pretos'] += 1
                        else:
                            resultado['quadrante1']['brancos'] += 1

                # Conta os pixels pretos e brancos do segundo quadrante (2/9)
                for x in range(quadrante_largura, largura):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante2']['pretos'] += 1
                        else:
                            resultado['quadrante2']['brancos'] += 1

                # Conta os pixels pretos e brancos do terceiro quadrante (3/9)
                for x in range(quadrante_largura, largura):
                    for y in range(quadrante_altura, altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante3']['pretos'] += 1
                        else:
                            resultado['quadrante3']['brancos'] += 1

                # Conta os pixels pretos e brancos do quarto quadrante (4/9)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura, altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante4']['pretos'] += 1
                        else:
                            resultado['quadrante4']['brancos'] += 1

                # Conta os pixels pretos e brancos do quinto quadrante (5/9)
                for x in range(quadrante_largura, largura, quadrante_largura):
                    for y in range(quadrante_altura, altura, quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante5']['pretos'] += 1
                        else:
                            resultado['quadrante5']['brancos'] += 1

                # Conta os pixels pretos e brancos do sexto quadrante (6/9)
                for x in range(quadrante_largura, largura, quadrante_largura):
                    for y in range(0, altura, quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante6']['pretos'] += 1
                        else:
                            resultado['quadrante6']['brancos'] += 1

                # Conta os pixels pretos e brancos do sétimo quadrante (7/9)
                for x in range(0, largura, quadrante_largura):
                    for y in range(0, altura, quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante7']['pretos'] += 1
                        else:
                            resultado['quadrante7']['brancos'] += 1

                # Conta os pixels pretos e brancos do oitavo quadrante (8/9)
                for x in range(0, largura, quadrante_largura):
                    for y in range(quadrante_altura, altura, quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante8']['pretos'] += 1
                        else:
                            resultado['quadrante8']['brancos'] += 1

                # Conta os pixels pretos e brancos do nono quadrante (9/9)
                for x in range(0, largura, quadrante_largura):
                    for y in range(0, altura, quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante9']['pretos'] += 1
                        else:
                            resultado['quadrante9']['brancos'] += 1

                # Adiciona o resultado à lista de resultados
                resultados.append(resultado)

    return resultados


def contar_pixels_5x5(diretorio):
    resultados = [] # lista de dicionários

    for classe in os.listdir(diretorio):    # Para cada diretorio de classe
        classe_dir = os.path.join(diretorio, classe)
        for arquivo in os.listdir(classe_dir):  # Para cada arquivo de imagem
            if arquivo.endswith(".bmp"):    # Se o arquivo for uma imagem
                caminho = os.path.join(classe_dir, arquivo) # Caminho da imagem
                imagem = Image.open(caminho)    # Abre a imagem
                pixels = imagem.load()  # Carrega os pixels da imagem
                largura, altura = imagem.size   # Tamanho da imagem

                # Define o tamanho dos quadrantes
                quadrante_largura = largura // 5
                quadrante_altura = altura // 5

                # Dicionário com os resultados
                resultado = {
                    'classe': classe,
                    'quadrante1': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante2': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante3': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante4': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante5': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante6': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante7': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante8': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante9': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante10': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante11': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante12': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante13': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante14': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante15': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante16': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante17': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante18': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante19': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante20': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante21': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante22': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante23': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante24': {
                        'brancos': 0,
                        'pretos': 0
                    },
                    'quadrante25': {
                        'brancos': 0,
                        'pretos': 0
                    }
                }

                # Conta os pixels pretos e brancos do primeiro quadrante (1/25)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante1']['pretos'] += 1
                        else:
                            resultado['quadrante1']['brancos'] += 1

                # Conta os pixels pretos e brancos do segundo quadrante (2/25)
                for x in range(quadrante_largura, quadrante_largura * 2):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante2']['pretos'] += 1
                        else:
                            resultado['quadrante2']['brancos'] += 1

                # Conta os pixels pretos e brancos do terceiro quadrante (3/25)
                for x in range(quadrante_largura * 2, quadrante_largura * 3):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante3']['pretos'] += 1
                        else:
                            resultado['quadrante3']['brancos'] += 1

                # Conta os pixels pretos e brancos do quarto quadrante (4/25)
                for x in range(quadrante_largura * 3, quadrante_largura * 4):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante4']['pretos'] += 1
                        else:
                            resultado['quadrante4']['brancos'] += 1

                # Conta os pixels pretos e brancos do quinto quadrante (5/25)
                for x in range(quadrante_largura * 4, quadrante_largura * 5):
                    for y in range(quadrante_altura):
                        if pixels[x, y] == 0:
                            resultado['quadrante5']['pretos'] += 1
                        else:
                            resultado['quadrante5']['brancos'] += 1

                # Conta os pixels pretos e brancos do sexto quadrante (6/25)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura, quadrante_altura * 2):
                        if pixels[x, y] == 0:
                            resultado['quadrante6']['pretos'] += 1
                        else:
                            resultado['quadrante6']['brancos'] += 1

                # Conta os pixels pretos e brancos do sétimo quadrante (7/25)
                for x in range(quadrante_largura, quadrante_largura * 2):
                    for y in range(quadrante_altura, quadrante_altura * 2):
                        if pixels[x, y] == 0:
                            resultado['quadrante7']['pretos'] += 1
                        else:
                            resultado['quadrante7']['brancos'] += 1

                # Conta os pixels pretos e brancos do oitavo quadrante (8/25)
                for x in range(quadrante_largura * 2, quadrante_largura * 3):
                    for y in range(quadrante_altura, quadrante_altura * 2):
                        if pixels[x, y] == 0:
                            resultado['quadrante8']['pretos'] += 1
                        else:
                            resultado['quadrante8']['brancos'] += 1

                # Conta os pixels pretos e brancos do nono quadrante (9/25)
                for x in range(quadrante_largura * 3, quadrante_largura * 4):
                    for y in range(quadrante_altura, quadrante_altura * 2):
                        if pixels[x, y] == 0:
                            resultado['quadrante9']['pretos'] += 1
                        else:
                            resultado['quadrante9']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo quadrante (10/25)
                for x in range(quadrante_largura * 4, quadrante_largura * 5):
                    for y in range(quadrante_altura, quadrante_altura * 2):
                        if pixels[x, y] == 0:
                            resultado['quadrante10']['pretos'] += 1
                        else:
                            resultado['quadrante10']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo primeiro quadrante (11/25)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura * 2, quadrante_altura * 3):
                        if pixels[x, y] == 0:
                            resultado['quadrante11']['pretos'] += 1
                        else:
                            resultado['quadrante11']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo segundo quadrante (12/25)
                for x in range(quadrante_largura, quadrante_largura * 2):
                    for y in range(quadrante_altura * 2, quadrante_altura * 3):
                        if pixels[x, y] == 0:
                            resultado['quadrante12']['pretos'] += 1
                        else:
                            resultado['quadrante12']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo terceiro quadrante (13/25)
                for x in range(quadrante_largura * 2, quadrante_largura * 3):
                    for y in range(quadrante_altura * 2, quadrante_altura * 3):
                        if pixels[x, y] == 0:
                            resultado['quadrante13']['pretos'] += 1
                        else:
                            resultado['quadrante13']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo quarto quadrante (14/25)
                for x in range(quadrante_largura * 3, quadrante_largura * 4):
                    for y in range(quadrante_altura * 2, quadrante_altura * 3):
                        if pixels[x, y] == 0:
                            resultado['quadrante14']['pretos'] += 1
                        else:
                            resultado['quadrante14']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo quinto quadrante (15/25)
                for x in range(quadrante_largura * 4, quadrante_largura * 5):
                    for y in range(quadrante_altura * 2, quadrante_altura * 3):
                        if pixels[x, y] == 0:
                            resultado['quadrante15']['pretos'] += 1
                        else:
                            resultado['quadrante15']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo sexto quadrante (16/25)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura * 3, quadrante_altura * 4):
                        if pixels[x, y] == 0:
                            resultado['quadrante16']['pretos'] += 1
                        else:
                            resultado['quadrante16']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo sétimo quadrante (17/25)
                for x in range(quadrante_largura, quadrante_largura * 2):
                    for y in range(quadrante_altura * 3, quadrante_altura * 4):
                        if pixels[x, y] == 0:
                            resultado['quadrante17']['pretos'] += 1
                        else:
                            resultado['quadrante17']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo oitavo quadrante (18/25)
                for x in range(quadrante_largura * 2, quadrante_largura * 3):
                    for y in range(quadrante_altura * 3, quadrante_altura * 4):
                        if pixels[x, y] == 0:
                            resultado['quadrante18']['pretos'] += 1
                        else:
                            resultado['quadrante18']['brancos'] += 1

                # Conta os pixels pretos e brancos do décimo nono quadrante (19/25)
                for x in range(quadrante_largura * 3, quadrante_largura * 4):
                    for y in range(quadrante_altura * 3, quadrante_altura * 4):
                        if pixels[x, y] == 0:
                            resultado['quadrante19']['pretos'] += 1
                        else:
                            resultado['quadrante19']['brancos'] += 1

                # Conta os pixels pretos e brancos do vigésimo quadrante (20/25)
                for x in range(quadrante_largura * 4, quadrante_largura * 5):
                    for y in range(quadrante_altura * 3, quadrante_altura * 4):
                        if pixels[x, y] == 0:
                            resultado['quadrante20']['pretos'] += 1
                        else:
                            resultado['quadrante20']['brancos'] += 1

                # Conta os pixels pretos e brancos do vigésimo primeiro quadrante (21/25)
                for x in range(quadrante_largura):
                    for y in range(quadrante_altura * 4, quadrante_altura * 5):
                        if pixels[x, y] == 0:
                            resultado['quadrante21']['pretos'] += 1
                        else:
                            resultado['quadrante21']['brancos'] += 1

                # Conta os pixels pretos e brancos do vigésimo segundo quadrante (22/25)
                for x in range(quadrante_largura, quadrante_largura * 2):
                    for y in range(quadrante_altura * 4, quadrante_altura * 5):
                        if pixels[x, y] == 0:
                            resultado['quadrante22']['pretos'] += 1
                        else:
                            resultado['quadrante22']['brancos'] += 1

                # Conta os pixels pretos e brancos do vigésimo terceiro quadrante (23/25)
                for x in range(quadrante_largura * 2, quadrante_largura * 3):
                    for y in range(quadrante_altura * 4, quadrante_altura * 5):
                        if pixels[x, y] == 0:
                            resultado['quadrante23']['pretos'] += 1
                        else:
                            resultado['quadrante23']['brancos'] += 1
                            
                # Conta os pixels pretos e brancos do vigésimo quarto quadrante (24/25)
                for x in range(quadrante_largura * 3, quadrante_largura * 4):
                    for y in range(quadrante_altura * 4, quadrante_altura * 5):
                        if pixels[x, y] == 0:
                            resultado['quadrante24']['pretos'] += 1
                        else:
                            resultado['quadrante24']['brancos'] += 1

                # Conta os pixels pretos e brancos do vigésimo quinto quadrante (25/25)
                for x in range(quadrante_largura * 4, quadrante_largura * 5):
                    for y in range(quadrante_altura * 4, quadrante_altura * 5):
                        if pixels[x, y] == 0:
                            resultado['quadrante25']['pretos'] += 1
                        else:
                            resultado['quadrante25']['brancos'] += 1

                # Adiciona o resultado à lista de resultados
                resultados.append(resultado)

    return resultados

# define os diretórios de treino e teste
treino_dir = "data/treino"
teste_dir = "data/teste"

# gera o arquivo .csv de treino 1x1
treino_resultados = contar_pixels_1x1(treino_dir)
with open("data/treino_1x1.csv", "w") as arquivo:
    arquivo.write("classe,brancos,pretos\n")
    for resultado in treino_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']} \n")

# gera o arquivo .csv de teste 1x1
teste_resultados = contar_pixels_1x1(teste_dir)
with open("data/teste_1x1.csv", "w") as arquivo:
    arquivo.write("classe,brancos,pretos\n")
    for resultado in teste_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']} \n")

# gera o arquivo .csv de treino 2x2
treino_resultados = contar_pixels_2x2(treino_dir)
with open("data/treino_2x2.csv", "w") as arquivo:
    arquivo.write("classe,brancos1,pretos1,brancos2,pretos2,brancos3,pretos3,brancos4,pretos4\n")
    for resultado in treino_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']},{resultado['quadrante2']['brancos']},{resultado['quadrante2']['pretos']},{resultado['quadrante3']['brancos']},{resultado['quadrante3']['pretos']},{resultado['quadrante4']['brancos']},{resultado['quadrante4']['pretos']} \n")

# gera o arquivo .csv de teste 2x2
teste_resultados = contar_pixels_2x2(teste_dir)
with open("data/teste_2x2.csv", "w") as arquivo:
    arquivo.write("classe,brancos1,pretos1,brancos2,pretos2,brancos3,pretos3,brancos4,pretos4\n")
    for resultado in teste_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']},{resultado['quadrante2']['brancos']},{resultado['quadrante2']['pretos']},{resultado['quadrante3']['brancos']},{resultado['quadrante3']['pretos']},{resultado['quadrante4']['brancos']},{resultado['quadrante4']['pretos']} \n")

# gera o arquivo .csv de treino
treino_resultados = contar_pixels_3x3(treino_dir)
with open("data/treino_3x3.csv", "w") as arquivo:
    arquivo.write("classe,brancos1,pretos1,brancos2,pretos2,brancos3,pretos3,brancos4,pretos4,brancos5,pretos5,brancos6,pretos6,brancos7,pretos7,brancos8,pretos8,brancos9,pretos9\n")
    for resultado in treino_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']},{resultado['quadrante2']['brancos']},{resultado['quadrante2']['pretos']},{resultado['quadrante3']['brancos']},{resultado['quadrante3']['pretos']},{resultado['quadrante4']['brancos']},{resultado['quadrante4']['pretos']},{resultado['quadrante5']['brancos']},{resultado['quadrante5']['pretos']},{resultado['quadrante6']['brancos']},{resultado['quadrante6']['pretos']},{resultado['quadrante7']['brancos']},{resultado['quadrante7']['pretos']},{resultado['quadrante8']['brancos']},{resultado['quadrante8']['pretos']},{resultado['quadrante9']['brancos']},{resultado['quadrante9']['pretos']}\n")

# gera o arquivo .csv de teste
teste_resultados = contar_pixels_3x3(teste_dir)
with open("data/teste_3x3.csv", "w") as arquivo:
    arquivo.write("classe,brancos1,pretos1,brancos2,pretos2,brancos3,pretos3,brancos4,pretos4,brancos5,pretos5,brancos6,pretos6,brancos7,pretos7,brancos8,pretos8,brancos9,pretos9\n")
    for resultado in teste_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']},{resultado['quadrante2']['brancos']},{resultado['quadrante2']['pretos']},{resultado['quadrante3']['brancos']},{resultado['quadrante3']['pretos']},{resultado['quadrante4']['brancos']},{resultado['quadrante4']['pretos']},{resultado['quadrante5']['brancos']},{resultado['quadrante5']['pretos']},{resultado['quadrante6']['brancos']},{resultado['quadrante6']['pretos']},{resultado['quadrante7']['brancos']},{resultado['quadrante7']['pretos']},{resultado['quadrante8']['brancos']},{resultado['quadrante8']['pretos']},{resultado['quadrante9']['brancos']},{resultado['quadrante9']['pretos']}\n")

# gera o arquivo .csv de treino 5x5
treino_resultados = contar_pixels_5x5(treino_dir)
with open("data/treino_5x5.csv", "w") as arquivo:
    arquivo.write("classe,brancos1,pretos1,brancos2,pretos2,brancos3,pretos3,brancos4,pretos4,brancos5,pretos5,brancos6,pretos6,brancos7,pretos7,brancos8,pretos8,brancos9,pretos9,brancos10,pretos10,brancos11,pretos11,brancos12,pretos12,brancos13,pretos13,brancos14,pretos14,brancos15,pretos15,brancos16,pretos16,brancos17,pretos17,brancos18,pretos18,brancos19,pretos19,brancos20,pretos20,brancos21,pretos21,brancos22,pretos22,brancos23,pretos23,brancos24,pretos24,brancos25,pretos25\n")

    for resultado in treino_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']},{resultado['quadrante2']['brancos']},{resultado['quadrante2']['pretos']},{resultado['quadrante3']['brancos']},{resultado['quadrante3']['pretos']},{resultado['quadrante4']['brancos']},{resultado['quadrante4']['pretos']},{resultado['quadrante5']['brancos']},{resultado['quadrante5']['pretos']},{resultado['quadrante6']['brancos']},{resultado['quadrante6']['pretos']},{resultado['quadrante7']['brancos']},{resultado['quadrante7']['pretos']},{resultado['quadrante8']['brancos']},{resultado['quadrante8']['pretos']},{resultado['quadrante9']['brancos']},{resultado['quadrante9']['pretos']},{resultado['quadrante10']['brancos']},{resultado['quadrante10']['pretos']},{resultado['quadrante11']['brancos']},{resultado['quadrante11']['pretos']},{resultado['quadrante12']['brancos']},{resultado['quadrante12']['pretos']},{resultado['quadrante13']['brancos']},{resultado['quadrante13']['pretos']},{resultado['quadrante14']['brancos']},{resultado['quadrante14']['pretos']},{resultado['quadrante15']['brancos']},{resultado['quadrante15']['pretos']},{resultado['quadrante16']['brancos']},{resultado['quadrante16']['pretos']},{resultado['quadrante17']['brancos']},{resultado['quadrante17']['pretos']},{resultado['quadrante18']['brancos']},{resultado['quadrante18']['pretos']},{resultado['quadrante19']['brancos']},{resultado['quadrante19']['pretos']},{resultado['quadrante20']['brancos']},{resultado['quadrante20']['pretos']},{resultado['quadrante21']['brancos']},{resultado['quadrante21']['pretos']},{resultado['quadrante22']['brancos']},{resultado['quadrante22']['pretos']},{resultado['quadrante23']['brancos']},{resultado['quadrante23']['pretos']},{resultado['quadrante24']['brancos']},{resultado['quadrante24']['pretos']},{resultado['quadrante25']['brancos']},{resultado['quadrante25']['pretos']}\n")

# gera o arquivo .csv de teste 5x5
teste_resultados = contar_pixels_5x5(teste_dir)
with open("data/teste_5x5.csv", "w") as arquivo:
    arquivo.write("classe,brancos1,pretos1,brancos2,pretos2,brancos3,pretos3,brancos4,pretos4,brancos5,pretos5,brancos6,pretos6,brancos7,pretos7,brancos8,pretos8,brancos9,pretos9,brancos10,pretos10,brancos11,pretos11,brancos12,pretos12,brancos13,pretos13,brancos14,pretos14,brancos15,pretos15,brancos16,pretos16,brancos17,pretos17,brancos18,pretos18,brancos19,pretos19,brancos20,pretos20,brancos21,pretos21,brancos22,pretos22,brancos23,pretos23,brancos24,pretos24,brancos25,pretos25\n")

    for resultado in treino_resultados:
        arquivo.write(f"{resultado['classe']},{resultado['quadrante1']['brancos']},{resultado['quadrante1']['pretos']},{resultado['quadrante2']['brancos']},{resultado['quadrante2']['pretos']},{resultado['quadrante3']['brancos']},{resultado['quadrante3']['pretos']},{resultado['quadrante4']['brancos']},{resultado['quadrante4']['pretos']},{resultado['quadrante5']['brancos']},{resultado['quadrante5']['pretos']},{resultado['quadrante6']['brancos']},{resultado['quadrante6']['pretos']},{resultado['quadrante7']['brancos']},{resultado['quadrante7']['pretos']},{resultado['quadrante8']['brancos']},{resultado['quadrante8']['pretos']},{resultado['quadrante9']['brancos']},{resultado['quadrante9']['pretos']},{resultado['quadrante10']['brancos']},{resultado['quadrante10']['pretos']},{resultado['quadrante11']['brancos']},{resultado['quadrante11']['pretos']},{resultado['quadrante12']['brancos']},{resultado['quadrante12']['pretos']},{resultado['quadrante13']['brancos']},{resultado['quadrante13']['pretos']},{resultado['quadrante14']['brancos']},{resultado['quadrante14']['pretos']},{resultado['quadrante15']['brancos']},{resultado['quadrante15']['pretos']},{resultado['quadrante16']['brancos']},{resultado['quadrante16']['pretos']},{resultado['quadrante17']['brancos']},{resultado['quadrante17']['pretos']},{resultado['quadrante18']['brancos']},{resultado['quadrante18']['pretos']},{resultado['quadrante19']['brancos']},{resultado['quadrante19']['pretos']},{resultado['quadrante20']['brancos']},{resultado['quadrante20']['pretos']},{resultado['quadrante21']['brancos']},{resultado['quadrante21']['pretos']},{resultado['quadrante22']['brancos']},{resultado['quadrante22']['pretos']},{resultado['quadrante23']['brancos']},{resultado['quadrante23']['pretos']},{resultado['quadrante24']['brancos']},{resultado['quadrante24']['pretos']},{resultado['quadrante25']['brancos']},{resultado['quadrante25']['pretos']}\n")
        
print("Arquivos gerados com sucesso!")