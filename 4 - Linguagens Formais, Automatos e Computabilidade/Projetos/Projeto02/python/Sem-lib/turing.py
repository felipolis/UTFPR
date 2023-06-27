
nomeArquivo = 'entrada.txt'

def automatoSoma(fita):
    resultado = fita
    estado_inicial = 'q0'
    estado_final = 'qf'
    estado_atual = estado_inicial
    position = 0

    while estado_atual != estado_final:
        if estado_atual == 'q0':
            if resultado[position] == '#':
                resultado[position] = "#"
                position += 1
                estado_atual = 'q1'
        
        elif estado_atual == 'q1':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q1'
            elif resultado[position] == '+':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q2'

        elif estado_atual == 'q2':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q2'
            elif resultado[position] == '#':
                resultado[position] = '#'
                position -= 1
                estado_atual = 'q3'
        
        elif estado_atual == 'q3':
            if resultado[position] == '1':
                resultado[position] = '#'
                estado_atual = estado_final
    
    return ''.join(resultado)


def automatoSubtracao(fita):
    resultado = fita
    estado_inicial = 'q0'
    estado_final = 'qf'
    estado_atual = estado_inicial
    position = 0

    while estado_atual != estado_final:
        if estado_atual == 'q0':
            if resultado[position] == '#':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q1'
        
        elif estado_atual == 'q1':
            if resultado[position] == '1':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q2'

        elif estado_atual == 'q2':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q2'
            elif resultado[position] == '-':
                resultado[position] = '-'
                position += 1
                estado_atual = 'q3'
        
        elif estado_atual == 'q3':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q3'
            elif resultado[position] == '#':
                resultado[position] = '#'
                position -= 1
                estado_atual = 'q4'
        
        elif estado_atual == 'q4':
            if resultado[position] == '1':
                resultado[position] = '#'
                position -= 1
                estado_atual = 'q5'
        
        elif estado_atual == 'q5':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q6'
            elif resultado[position] == '-':
                resultado[position] = '#'
                estado_atual = estado_final
        
        elif estado_atual == 'q6':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q6'
            elif resultado[position] == '-':
                resultado[position] = '-'
                position -= 1
                estado_atual = 'q7'
        
        elif estado_atual == 'q7':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q8'
            elif resultado[position] == '#':
                resultado[position] = '#'
                estado_atual = estado_final
        
        elif estado_atual == 'q8':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q8'
            elif resultado[position] == '#':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q1'

    return ''.join(resultado)


def automatoMultiplicacao(fita):
    resultado = fita
    estado_inicial = 'q0'
    estado_final = 'qf'
    estado_atual = estado_inicial
    position = 1

    while estado_atual != estado_final:
        if estado_atual == 'q0':
            if resultado[position] == '1':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q1'
        
        elif estado_atual == 'q1':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q4'
            elif resultado[position] == '*':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q2'

        elif estado_atual == 'q2':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q2'
            elif resultado[position] == 'Z':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q2'
            elif resultado[position] == '#':
                resultado[position] = '#'
                position -= 1
                estado_atual = 'q3'
        
        elif estado_atual == 'q3':
            if resultado[position] == '1':
                resultado[position] = '#'
                estado_atual = estado_final
        
        elif estado_atual == 'q4':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q4'
            elif resultado[position] == '*':
                resultado[position] = '*'
                position += 1
                estado_atual = 'q5'
        
        elif estado_atual == 'q5':
            if resultado[position] == '1':
                resultado[position] = 'E'
                position += 1
                estado_atual = 'q6'
            elif resultado[position] == 'Z':
                resultado[position] = 'Z'
                position -= 1
                estado_atual = 'q8'
        
        elif estado_atual == 'q6':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q6'
            elif resultado[position] == 'Z':
                resultado[position] = 'Z'
                position += 1
                estado_atual = 'q6'
            elif resultado[position] == '#':
                resultado[position] = 'Z'
                position -= 1
                estado_atual = 'q7'
        
        elif estado_atual == 'q7':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q7'
            elif resultado[position] == 'E':
                resultado[position] = 'E'
                position += 1
                estado_atual = 'q5'
            elif resultado[position] == 'Z':
                resultado[position] = 'Z'
                position -= 1
                estado_atual = 'q7'

        elif estado_atual == 'q8':
            if resultado[position] == 'E':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q8'
            elif resultado[position] == '*':
                resultado[position] = '*'
                position -= 1
                estado_atual = 'q9'
        
        elif estado_atual == 'q9':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q9'
            elif resultado[position] == '#':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q0'

    return ''.join(resultado)


def automatoDivisao(fita):
    resultado = fita
    estado_inicial = 'q0'
    estado_final = 'qf'
    estado_atual = estado_inicial
    position = 0
    
    while estado_atual != estado_final:
        if estado_atual == 'q0':
            if resultado[position] == '#':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q1'
        
        elif estado_atual == 'q1':
            if resultado[position] == '1':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q2'
            elif resultado[position] == '/':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q10'
        
        elif estado_atual == 'q2':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q2'
            elif resultado[position] == '/':
                resultado[position] = '/'
                position += 1
                estado_atual = 'q3'

        elif estado_atual == 'q3':
            if resultado[position] == '1':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q3'
            elif resultado[position] == 'E':
                resultado[position] = 'E'
                position += 1
                estado_atual = 'q3'
            elif resultado[position] == 'Z':
                resultado[position] = 'Z'
                position -= 1
                estado_atual = 'q3'
            elif resultado[position] == '#':
                resultado[position] = '#'
                position -= 1
                estado_atual = 'q4'
        
        elif estado_atual == 'q4':
            if resultado[position] == '1':
                resultado[position] = 'E'
                position -= 1
                estado_atual = 'q5'
            elif resultado[position] == 'E':
                resultado[position] = 'E'
                position -= 1
                estado_atual = 'q4'
        
        elif estado_atual == 'q5':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q8'
            elif resultado[position] == '/':
                resultado[position] = '/'
                position += 1
                estado_atual = 'q6'
        
        elif estado_atual == 'q6':
            if resultado[position] == 'E':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q6'
            elif resultado[position] == 'Z':
                resultado[position] = 'Z'
                position += 1
                estado_atual = 'q6'
            elif resultado[position] == '#':
                resultado[position] = 'Z'
                position -= 1
                estado_atual = 'q8'
        
        elif estado_atual == 'q8':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q8'
            elif resultado[position] == '/':
                resultado[position] = '/'
                position -= 1
                estado_atual = 'q9'
            elif resultado[position] == 'Z':
                resultado[position] = 'Z'
                position -= 1
                estado_atual = 'q8'
        
        elif estado_atual == 'q9':
            if resultado[position] == '1':
                resultado[position] = '1'
                position -= 1
                estado_atual = 'q9'
            elif resultado[position] == '#':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q1'
        
        elif estado_atual == 'q10':
            if resultado[position] == '1':
                resultado[position] = '#'
                position += 1
                estado_atual = 'q10'
            elif resultado[position] == 'Z':
                resultado[position] = '1'
                position += 1
                estado_atual = 'q10'
            elif resultado[position] == '#':
                resultado[position] = '#'
                estado_atual = estado_final
    return ''.join(resultado)


def main():
    # Abrindo o arquivo de entrada
    try:
        entrada = open(nomeArquivo, 'r')
    except FileNotFoundError:
        print('Arquivo não encontrado')
        return

    # Abrindo o arquivo de saida
    try:
        saida = open('saida.out', 'w')
    except:
        print('Erro ao criar arquivo de saida')
        return

    # Lendo o arquivo de entrada
    for line in entrada:
        expressao = list(line)

        if '+' in line:
            resultado = automatoSoma(expressao)
        elif '-' in line:
            resultado = automatoSubtracao(expressao)
        elif '*' in line:
            resultado = automatoMultiplicacao(expressao)
        elif '/' in line:
            resultado = automatoDivisao(expressao)
        else:
            print('Operacao invalida')
            return
        
        saida.write(resultado)
        print(f'{line.strip()} = {resultado}', end='')
    
    print('\nFim da execucao')


if __name__ == '__main__':
    main()
