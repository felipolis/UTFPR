import os
import cv2
import numpy as np
from joblib import Parallel, delayed

# Diretórios
SPECTROGRAM_DIR = "../data/espectrogramas"
PATCHES_DIR = "../data/patches/5_patches"

# Número de patches desejado
N_PATCHES = 5  # Altere para o número desejado

# Se o diretório para salvar os patches não existir, crie-o
if not os.path.exists(PATCHES_DIR):
    os.mkdir(PATCHES_DIR)

# Função para cortar e salvar os patches de um espectrograma
def cut_and_save_patches(spectrogram_path, output_dir, n_patches):
    # Carrega o espectrograma colorido
    spectrogram = cv2.imread(spectrogram_path)

    # Calcula a largura (número de colunas) do espectrograma
    width = spectrogram.shape[1]

    # Calcula o tamanho de cada patch
    patch_width = width // n_patches

    # Loop para cortar e salvar os patches
    for i in range(n_patches):
        start_col = i * patch_width
        end_col = start_col + patch_width

        # Corta o patch
        patch = spectrogram[:, start_col:end_col, :]

        # Cria o nome do arquivo de saída
        output_path = os.path.join(output_dir, f"{os.path.basename(spectrogram_path).replace('.png', f'_patch_{i}.png')}")

        # Salva o patch
        cv2.imwrite(output_path, patch)

def process_spectrogram(spectrogram_path):
    output_subdir = os.path.relpath(os.path.dirname(spectrogram_path), SPECTROGRAM_DIR)
    output_dir = os.path.join(PATCHES_DIR, output_subdir)
    os.makedirs(output_dir, exist_ok=True)
    cut_and_save_patches(spectrogram_path, output_dir, N_PATCHES)


# Percorre os espectrogramas e corta em patches
Parallel(n_jobs=4)(delayed(process_spectrogram)(os.path.join(root, file)) for root, dirs, files in os.walk(SPECTROGRAM_DIR) for file in files if file.endswith(".png"))

print(f"Patches cortados e salvos em '{PATCHES_DIR}'")
