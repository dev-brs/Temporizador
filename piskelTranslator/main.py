from PIL import Image

# Função para converter imagem para matriz binária (0 para branco, 1 para preto)
def imagem_para_matriz(imagem_path, matriz_path):
    # Abrir a imagem
    imagem = Image.open(imagem_path)

    # Converter para escala de cinza
    imagem_cinza = imagem.convert('L')

    # Obter os pixels da imagem
    pixels = list(imagem_cinza.getdata())

    # Obter largura e altura da imagem
    largura, altura = imagem_cinza.size

    # Criar arquivo de saída
    with open(matriz_path, 'w') as arquivo:
        # Escrever largura e altura da matriz
        arquivo.write("struct estruturaDefault nomeStruct = {\n")
        arquivo.write(f"\t.colunas = {largura},\n")
        arquivo.write(f"\t.linhas = {altura},\n")
        arquivo.write("\t.matriz = {\n")

        # Escrever os valores da matriz binária (0 para branco, 1 para preto)
        for i in range(altura):
            arquivo.write("\t\t")
            for j in range(largura):
                # Obter valor do pixel na posição (j, i)
                valor_pixel = pixels[i * largura + j]

                # Converter valor para binário (0 para branco, 1 para preto)
                if valor_pixel < 128:
                    arquivo.write("0, ")  # Branco
                else:
                    arquivo.write("1, ")  # Preto

            arquivo.write("\n")
        
        arquivo.write("\t}\n};")

    print(f"Matriz binária gerada em '{matriz_path}'")

if __name__ == "__main__":
    imagem_path = 'a.png'
    matriz_path = 'matriz.txt'
    imagem_para_matriz(imagem_path, matriz_path)
