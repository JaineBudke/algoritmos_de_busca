# Makefile, separando os diferentes elementos da aplicacao
# como codigo (src), cabecalhos (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento e alocado em uma pasta especifica, organizando melhor seu codigo fonte.
#
# Algumas variaveis sao usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
RM = rm -rf 

# Compilador
CC = g++ 

# Variaveis para os subdiretorios
INC_DIR = ./include
LIB_DIR = ./lib
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc
TEST_DIR = ./test

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean doxy debug doc

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: bBinariaIterativa bBinariaRecursiva bSequencialIterativa bSequencialRecursiva
debug: CFLAGS += -g -O0
debug: bBinariaIterativa bBinariaRecursiva bSequencialIterativa bSequencialRecursiva

#------------------------------------------------------------------------------------------------------------------------------

# Alvo (target) para a construcao do objeto main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
#------------------------------------------------------------------------------------------------------------------------------

# Define os arquivos main.cpp bBinariaIterativa.cpp como dependencias
# Alvo (target) para a construcao do executavel bBinariaIterativa
bBinariaIterativa: $(OBJ_DIR)/main.o $(OBJ_DIR)/bBinariaIterativa.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'bBinariaIterativa' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto bBinariaIterativa.o
# Define os arquivos bBinariaIterativa.cpp bBinariaIterativa.h como dependencias
$(OBJ_DIR)/bBinariaIterativa.o: $(SRC_DIR)/bBinariaIterativa.cpp $(INC_DIR)/bBinariaIterativa.h
	$(CC) -c $(CFLAGS) -o $@ $<	

#------------------------------------------------------------------------------------------------------------------------------

# Define os arquivos main.cpp bBinariaRecursiva.cpp como dependencias
# Alvo (target) para a construcao do executavel bBinariaRecursiva
bBinariaRecursiva: $(OBJ_DIR)/main.o $(OBJ_DIR)/bBinariaRecursiva.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'bBinariaRecursiva' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto bBinariaRecursiva.o
# Define os arquivos bBinariaRecursiva.cpp bBinariaRecursiva.h como dependencias
$(OBJ_DIR)/bBinariaRecursiva.o: $(SRC_DIR)/bBinariaRecursiva.cpp $(INC_DIR)/bBinariaRecursiva.h
	$(CC) -c $(CFLAGS) -o $@ $<	

#------------------------------------------------------------------------------------------------------------------------------

# Define os arquivos main.cpp bSequencialIterativa.cpp como dependencias
# Alvo (target) para a construcao do executavel bSequencialIterativa
bSequencialIterativa: $(OBJ_DIR)/main.o $(OBJ_DIR)/bSequencialIterativa.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'bSequencialIterativa' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto bSequencialIterativa.o
# Define os arquivos bSequencialIterativa.cpp bSequencialIterativa.h como dependencias
$(OBJ_DIR)/bSequencialIterativa.o: $(SRC_DIR)/bSequencialIterativa.cpp $(INC_DIR)/bSequencialIterativa.h
	$(CC) -c $(CFLAGS) -o $@ $<	

#------------------------------------------------------------------------------------------------------------------------------

# Define os arquivos main.cpp bSequencialRecursiva.cpp como dependencias
# Alvo (target) para a construcao do executavel bSequencialRecursiva
bSequencialRecursiva: $(OBJ_DIR)/main.o $(OBJ_DIR)/bSequencialRecursiva.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'bSequencialRecursiva' criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto bSequencialRecursiva.o
# Define os arquivos bSequencialRecursiva.cpp bSequencialRecursiva.h como dependencias
$(OBJ_DIR)/bSequencialRecursiva.o: $(SRC_DIR)/bSequencialRecursiva.cpp $(INC_DIR)/bSequencialRecursiva.h
	$(CC) -c $(CFLAGS) -o $@ $<	

#------------------------------------------------------------------------------------------------------------------------------


# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*