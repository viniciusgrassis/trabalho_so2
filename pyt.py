import random
import math
from typing import List, Tuple

def generate_memory_accesses(num_accesses: int, pattern_type: str) -> List[Tuple[str, str]]:
    """
    Gera uma sequência de acessos à memória com padrões específicos
    
    Args:
        num_accesses: número total de acessos a gerar
        pattern_type: tipo de padrão ('compilador', 'matriz', 'compressor', 'simulador')
    
    Returns:
        Lista de tuplas (endereço_hex, tipo_acesso)
    """
    accesses = []
    
    if pattern_type == 'compilador':
        # Padrão de compilador: muitos acessos aleatórios com algumas localidades temporais
        for i in range(num_accesses):
            # 70% de chance de acessar uma região local
            if random.random() < 0.7:
                base = random.choice([0x00000000, 0x07800000, 0x10000000])
                offset = random.randint(0, 0xFFFFF)
                address = base + offset
            else:
                address = random.randint(0, 0xFFFFFFFF)
            
            # Compiladores tendem a ter mais leituras que escritas
            access_type = 'W' if random.random() < 0.3 else 'R'
            accesses.append((f"{address:08x}".upper(), access_type))
    
    elif pattern_type == 'matriz':
        # compressor Padrão de matriz: acessos sequenciais e em padrões regulares
        matrix_size = 1000  # Tamanho da matriz "virtual"
        element_size = 8    # Tamanho de cada elemento (8 bytes)
        
        for i in range(num_accesses):
            # Alterna entre acesso por linha e por coluna
            if random.random() < 0.7:  # 70% de acesso por linha
                row = random.randint(0, matrix_size-1)
                col = random.randint(0, matrix_size-1)
                address = row * matrix_size * element_size + col * element_size
            else:  # 30% de acesso por coluna
                col = random.randint(0, matrix_size-1)
                row = random.randint(0, matrix_size-1)
                address = col * matrix_size * element_size + row * element_size
            
            # Programas matriciais têm balance entre leitura e escrita
            access_type = 'W' if random.random() < 0.5 else 'R'
            accesses.append((f"{address:08x}".upper(), access_type))
    
    elif pattern_type == 'compressor':
        # Padrão de compressor: acessos mais sequenciais com algumas aleatoriedades
        window_size = 65536  # Tamanho da janela de compressão
        
        for i in range(num_accesses):
            # 80% de chance de acesso sequencial, 20% de acesso aleatório
            if random.random() < 0.8 and i > 0:
                # Continua da última posição com pequeno desvio
                last_addr = int(accesses[-1][0], 16)
                address = last_addr + random.randint(1, 64)
            else:
                address = random.randint(0, window_size)
            
            # Compressores tendem a ler mais do que escrever
            access_type = 'W' if random.random() < 0.2 else 'R'
            accesses.append((f"{address:08x}".upper(), access_type))
    
    elif pattern_type == 'simulador':
        # Padrão de simulador: mistura de acessos sequenciais e aleatórios
        particle_count = 10000
        particle_size = 32  # bytes por partícula
        
        for i in range(num_accesses):
            # 60% de acesso a partículas sequenciais, 40% aleatório
            if random.random() < 0.6:
                particle_id = (i % particle_count)
                field_offset = random.randint(0, 3) * 8  # Campos de 8 bytes
                address = particle_id * particle_size + field_offset
            else:
                address = random.randint(0, particle_count * particle_size)
            
            # Simuladores têm mais leituras que escritas
            access_type = 'W' if random.random() < 0.4 else 'R'
            accesses.append((f"{address:08x}".upper(), access_type))
    
    else:
        raise ValueError(f"Padrão desconhecido: {pattern_type}")
    
    return accesses

def save_to_file(accesses: List[Tuple[str, str]], filename: str):
    """Salva os acessos em um arquivo no formato especificado"""
    with open(filename, 'w') as f:
        for addr, acc_type in accesses:
            f.write(f"{addr} {acc_type}\n")

# Exemplo de geração de arquivos de teste
if __name__ == "__main__":
    # Gera 10,000 acessos para cada tipo de programa
    
    patterns = ['compilador', 'matriz', 'compressor', 'simulador']
    # patterns = ['compilador']
    
    for pattern in patterns:
        accesses = generate_memory_accesses(500000, pattern)
        filename = f"{pattern}.log"
        save_to_file(accesses, filename)
        print(f"Arquivo gerado: {filename} com {len(accesses)} acessos")