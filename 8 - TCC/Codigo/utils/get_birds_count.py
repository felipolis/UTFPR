import os
import csv
from collections import defaultdict

# Diretório base
base_dir = '../data/audios'

# Dicionário para armazenar a contagem de áudios por classe
audio_count = defaultdict(int)

# Percorre os diretórios e conta os arquivos de áudio por classe
for root, dirs, files in os.walk(base_dir):
    if files:
        class_name = os.path.basename(root)
        audio_count[class_name] += len(files)

# Gera um arquivo CSV ordenado pela contagem de áudios em ordem decrescente
csv_file = 'audio_count.csv'
sorted_audio_count = sorted(audio_count.items(), key=lambda x: x[1], reverse=True)

with open(csv_file, 'w', newline='') as file:
    writer = csv.writer(file)
    for class_name, count in sorted_audio_count:
        writer.writerow([class_name, count])

print(f'O arquivo CSV "{csv_file}" foi gerado com sucesso.')
