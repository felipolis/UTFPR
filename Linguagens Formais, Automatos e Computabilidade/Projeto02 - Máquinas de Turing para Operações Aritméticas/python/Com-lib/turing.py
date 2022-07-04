from automata.tm.ntm import NTM

# Maquina de turing para soma
soma = NTM(
    states={'s0', 's1', 's2', 's3', 'halt'},
    input_symbols={'1', '+'},
    tape_symbols={'1', '+', '#'},
    transitions={
        's0': {
            '#': {('s1', '#', 'R')}
        },
        's1': {
            '1': {('s1', '1', 'R')},
            '+': {('s2', '1', 'R')}
        },
        's2': {
            '1': {('s2', '1', 'R')},
            '#': {('s3', '#', 'L')}
        },
        's3': {
            '1': {('halt', '#', 'N')}
        }
    },
    initial_state='s0',
    blank_symbol='#',
    final_states={'halt'}
)


# Maquina de turing para subtracao
subtracao = NTM(
    states={'s0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 's8', 'halt'},
    input_symbols={'1', '-'},
    tape_symbols={'1', '-', '#'},
    transitions={
        's0': {
            '#': {('s1', '#', 'R')}
        },
        's1': {
            '1': {('s2', '#', 'R')},
        },
        's2': {
            '1': {('s2', '1', 'R')},
            '-': {('s3', '-', 'R')}
        },
        's3': {
            '1': {('s3', '1', 'R')},
            '#': {('s4', '#', 'L')}
        },
        's4': {
            '1': {('s5', '#', 'L')},
        },
        's5': {
            '1': {('s6', '1', 'L')},
            '-': {('halt', '#', 'N')}
        },
        's6': {
            '1': {('s6', '1', 'L')},
            '-': {('s7', '-', 'L')}
        },
        's7': {
            '1': {('s8', '1', 'L')},
            '#': {('halt', '#', 'N')}
        },
        's8': {
            '1': {('s8', '1', 'L')},
            '#': {('s1', '#', 'R')}
        }
    },
    initial_state='s0',
    blank_symbol='#',
    final_states={'halt'}
)


# Maquina de turing para multiplicacao
multiplicacao = NTM(
    states={'s0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 's8', 's9', 'halt'},
    input_symbols={'1', '*'},
    tape_symbols={'1', '*', '#', 'Z', 'E'},
    transitions={
        's0': {
            '1': {('s1', '#', 'R')},
            '#': {('s0', '#', 'R')}
        },
        's1': {
            '1': {('s4', '1', 'R')},
            '*': {('s2', '1', 'R')}
        },
        's2': {
            '1': {('s2', '1', 'R')},
            'Z': {('s2', '1', 'R')},
            '#': {('s3', '#', 'L')}
        },
        's3': {
            '1': {('halt', '#', 'N')}
        },
        's4': {
            '1': {('s4', '1', 'R')},
            '*': {('s5', '*', 'R')}
        },
        's5': {
            '1': {('s6', 'E', 'R')},
            'Z': {('s8', 'Z', 'L')}
        },
        's6': {
            '1': {('s6', '1', 'R')},
            'Z': {('s6', 'Z', 'R')},
            '#': {('s7', 'Z', 'L')}
        },
        's7': {
            '1': {('s7', '1', 'L')},
            'E': {('s5', 'E', 'R')},
            'Z': {('s7', 'Z', 'L')}
        },
        's8': {
            'E': {('s8', '1', 'L')},
            '*': {('s9', '*', 'L')}
        },
        's9': {
            '1': {('s9', '1', 'L')},
            '#': {('s0', '#', 'R')}
        }
    },
    initial_state='s0',
    blank_symbol='#',
    final_states={'halt'}
)


# Maquina de turing para divisao
divisao = NTM(
    states={'s0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 's8', 's9', 'halt'},
    input_symbols={'1', '/'},
    tape_symbols={'1', '/', '#', 'Z', 'E'},
    transitions={
        's0': {
            '#': {('s1', '#', 'R')}
        },
        's1': {
            '1': {('s2', '#', 'R')},
            '/': {('s9', '#', 'R')}
        },
        's2': {
            '1': {('s2', '1', 'R')},
            '/': {('s3', '/', 'R')}
        },
        's3': {
            '1': {('s3', '1', 'R')},
            'E': {('s3', 'E', 'R')},
            'Z': {('s4', 'Z', 'L')},
            '#': {('s4', '#', 'L')}
        },
        's4': {
            'E': {('s4', 'E', 'L')},
            '1': {('s5', 'E', 'L')}
        },
        's5': {
            '/': {('s6', '/', 'R')},
            '1': {('s7', '1', 'L')}
        },
        's6': {
            'E': {('s6', '1', 'R')},
            'Z': {('s6', 'Z', 'R')},
            '#': {('s7', 'Z', 'L')}
        },
        's7': {
            '1': {('s7', '1', 'L')},
            'Z': {('s7', 'Z', 'L')},
            '/': {('s8', '/', 'L')}
        },
        's8': {
            '1': {('s8', '1', 'L')},
            '#': {('s1', '#', 'R')}
        },
        's9': {
            '1': {('s9', '#', 'R')},
            'Z': {('s9', '1', 'R')},
            '#': {('halt', '#', 'N')}
        }
    },
    initial_state='s0',
    blank_symbol='#',
    final_states={'halt'}
)


# Função main
def main():
    # Entrada de dados
    op_soma = [
        '#11111+11#',
        '#11111+111#',
        '#111+11#',
        '#1+11#',
        '#11111111+1111111#',
        '#11111+1#'
    ]

    op_subtracao = [
        '#11111-11#',
        '#11111-111#',
        '#111-11#',
        '#1-1#',
        '#11111111-1111111#',
        '#11111-1#'
    ]

    op_multiplicacao = [
        '#11111*11####',
        '#11111*111####',
        '#111*11####',
        '#1*1####',
        '#11111111*1111111####',
        '#11111*1####'
    ]

    op_divisao = [
        '#1111/11####',
        '#111111/11####',
        '#11/11####',
        '#11111111/1111####',
        '#111111/11####',
    ]


    # Execução de operações
    print("------ Resultado das somas ------")
    for op in op_soma:
        if soma.accepts_input(op):
            soma.read_input(op).pop().print()
    
    print("------ Resultado das subtrações ------")
    for op in op_subtracao:
        if subtracao.accepts_input(op):
            subtracao.read_input(op).pop().print()

    print("------ Resultado das multiplicações ------")
    for op in op_multiplicacao:
        if multiplicacao.accepts_input(op):
            multiplicacao.read_input(op).pop().print()
    
    print("------ Resultado das divisões ------")
    for op in op_divisao:
        if divisao.accepts_input(op):
            divisao.read_input(op).pop().print()


# Execução do programa
if __name__ == '__main__':
    main()
