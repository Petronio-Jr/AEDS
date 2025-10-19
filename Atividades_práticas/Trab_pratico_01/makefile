# ==========================
# Makefile para o programa
# ==========================

# Nome do executável
PROJ_NAME = main

# Fontes .c (se tiver mais arquivos, basta colocá-los na pasta)
C_SOURCE = $(wildcard *.c)

# Cabeçalhos .h (se você criar um header no futuro, ele entra aqui)
H_SOURCE = $(wildcard *.h)

# Objetos (.o) gerados a partir dos fontes
OBJ = $(C_SOURCE:.c=.o)

# Compilador
CC = gcc

# Opções de compilação
CC_FLAGS = -c -Wall -g -pedantic

############################
# Regras de compilação
############################

# Regra principal
all: $(PROJ_NAME)

# Linkagem
$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

# Como compilar qualquer .o a partir do .c (e .h, se existirem)
%.o: %.c $(H_SOURCE)
	$(CC) $(CC_FLAGS) -o $@ $<

# Limpeza de arquivos gerados
clean:
	rm -f *.o $(PROJ_NAME) *~

# Executar o programa (opcional)
run: all
	./$(PROJ_NAME)