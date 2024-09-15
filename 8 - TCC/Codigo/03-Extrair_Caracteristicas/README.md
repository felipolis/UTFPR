# Extrair Caracteristicas

Esse script tem por objetivo extrair as caracteristicas dos patches e adiciona-las em tabelas .csv. Você pode utilizar os seguintes scripts:

* LBP.py
* Gabor.py
* VGG16.py
* ResNet50.py
* DenseNet121.py
* MobileNet.py

**Variaveis Globais:**

* diretorio_imagens: Caminho do diretorio onde estão os patches
* diretorio_caracteristicas: Caminho do diretorio onde será armazenada as tabelas de caracteristicas
* arquivo_csv: Caminho e nome do arquivo .csv que será gerado
* arquivo_metadata: Caminho do arquivo que está armazenado os metadados do dataset
