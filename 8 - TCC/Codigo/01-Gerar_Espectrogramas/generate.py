import os
import librosa
import librosa.display
import matplotlib.pyplot as plt
import numpy as np
import matplotlib
from joblib import Parallel, delayed

matplotlib.use('Agg')

# Caminho dos diretórios de áudio e espectrogramas
AUDIO_DIR = "../data/audios/"
SPECTROGRAM_DIR = "../data/espectrogramas"

# Se não existir o diretório ./train_espectogramas, cria
if not os.path.exists(SPECTROGRAM_DIR):
    os.mkdir(SPECTROGRAM_DIR)

# Função para criar espectrograma e salvar a imagem
def create_spectrogram(audio_path, output_path):
    # Carrega o arquivo de áudio utilizando a biblioteca librosa
    y, sr = librosa.load(audio_path, sr=None)

    # ********** LIMITE DO AUDIO EM 15 MIN **********
    # Verifica o comprimento do áudio em segundos
    audio_length = librosa.get_duration(y=y, sr=sr)
    # Define o limite de 15 minutos em segundos
    max_duration = 900  # 15 minutos * 60 segundos
    if audio_length > max_duration:
        # Se o áudio for maior que 15 minutos, corte-o
        y = y[:int(max_duration * sr)]
    # ********** LIMITE DO AUDIO EM 15 MIN **********

    # Calcula a Transformada de Fourier de Curto Prazo (STFT) do sinal de áudio com n_fft=2048, hop_length=1024
    D = librosa.amplitude_to_db(np.abs(librosa.feature.melspectrogram(y=y, n_fft=2048, hop_length=1024)), ref=np.max)
    
    # Cria a figura com o tamanho proporcional
    try:
        # Cria a figura com o tamanho proporcional
        fig = plt.figure(figsize=(D.shape[1]/72, D.shape[0]/72), dpi=72)

        # Plota o espectrograma
        ax = plt.Axes(fig, [0., 0., 1., 1.])
        ax.set_axis_off()
        fig.add_axes(ax)

        plt.pcolormesh(D)

        # Salva a figura no diretório de espectrogramas
        plt.savefig(output_path, dpi=72, pad_inches=0, bbox_inches='tight')

        # Fecha a figura para liberar recursos de memória
        plt.close()

    except ValueError:
        print("******************************************************")
        print("Erro ao criar espectrograma para o arquivo: " + audio_path)
        print("Número de amostras no arquivo: " + str(len(y)))
        print("******************************************************")

# Função para processar um único arquivo de áudio
def process_audio(audio_name):
    if audio_name.endswith(".ogg"):
        audio_path = os.path.join(key_dir, audio_name)
        spectrogram_path = os.path.join(spectrogram_key_dir, audio_name.replace(".ogg", ".png"))
        create_spectrogram(audio_path, spectrogram_path)
        print(f"Espectrograma criado para {audio_name}")

# Percorrendo os diretórios de áudio
for key in os.listdir(AUDIO_DIR):
    key_dir = os.path.join(AUDIO_DIR, key)
    if os.path.isdir(key_dir):
        spectrogram_key_dir = os.path.join(SPECTROGRAM_DIR, key)
        os.makedirs(spectrogram_key_dir, exist_ok=True)
        
        # Usando Parallel e delayed do joblib para processamento paralelo
        Parallel(n_jobs=-1)(delayed(process_audio)(audio_name) for audio_name in os.listdir(key_dir))
