# Trabalho de Conclusão de Curso

Titulo: Classificação de Pássaros por Meio de Cantos e Chamados: Uma Abordagem Integrada com Espectrogramas em Conjunto com Descritores Handcrafted e Transfer Learning, Aplicada ao Support Vector Machine (SVM)

Curso: Bacharelado em Ciência da Computação

Universidade: Universidade Tecnologica Federal do Paraná

Aluno: Felipe Archanjo da Cunha Mendes

Orientador: Prof. Dr. Juliano Enrique Foleis

## Sobre o Trabalho

Este projeto visa o desenvolvimento de um sistema robusto para a classificação de espécies de pássaros com base em suas vocalizações. Utilizando técnicas avançadas de processamento de sinal e aprendizado de máquina, o sistema identifica padrões únicos nas faixas de áudio dos pássaros para realizar a classificação.

### Processo de Classificação

O método de classificação adotado neste trabalho é subdividido em quatro etapas principais, descritas a seguir:

1. **Geração de Espectrogramas**: Primeiramente, convertemos as faixas de áudio dos pássaros em espectrogramas. Esta transformação permite a visualização das frequências presentes no áudio ao longo do tempo, facilitando a identificação de características distintivas.
2. **Geração de Patches**: Os espectrogramas são então segmentados em N patches (pequenas seções de igual tamanho). Esta etapa visa dividir o espectrograma em partes menores para uma análise mais detalhada e eficaz.
3. **Extração de Características**: A partir dos patches, procedemos à extração de características relevantes. Utilizamos descritores específicos, previamente definidos no projeto, para analisar os M pássaros mais similares. As características extraídas são compiladas em tabelas para posterior análise.
4. **Classificação**: Finalmente, aplicamos o método de Máquinas de Vetores de Suporte (SVM) para classificar os dados. A técnica de validação cruzada K-folds, juntamente com o GridSearchCV, é empregada para otimizar a seleção de parâmetros. Além disso, um sistema de votação é utilizado para consolidar os resultados dos patches, permitindo a classificação de cada espectrograma de maneira integral.

### Resultados

Os resultados obtidos serão apresentados em forma de tabelas e gráficos, detalhando as taxas de acerto, precisão, recall, e outras métricas relevantes. Essas informações serão cruciais para avaliar a eficácia do sistema proposto e identificar possíveis áreas para melhorias futuras.
