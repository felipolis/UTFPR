# Gerar Patches

Esse script tem por objetivo gerar patches a partir dos espectrogramas gerados na etapa anterior. É possivel utilizar tanto o script generate_N_patches.py ou generate_patches_N_colunas.py para gerar os patches. No entanto, para o escopo desse trabalho será utilizado apenas o generate_N_patches.py.

**Variaveis Globais:**

* SPECTROGRAM_DIR: Caminho para o diretório dos espectrogramas
* PATCHES_DIR: Caminho para o diretório que sera criado para armazenar os patches
* N_PATCHES: Quantidade de patches que você quer gerar
