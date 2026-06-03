# Makefile - Sistema de Gerenciamento da Guilda (S.G.G)
CC     = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ    = main.o arsenal.o enfermaria.o mural.o
ALVO   = sgg

$(ALVO): $(OBJ)
	$(CC) $(CFLAGS) -o $(ALVO) $(OBJ)

main.o: main.c arsenal.h enfermaria.h mural.h
	$(CC) $(CFLAGS) -c main.c

arsenal.o: arsenal.c arsenal.h
	$(CC) $(CFLAGS) -c arsenal.c

enfermaria.o: enfermaria.c enfermaria.h
	$(CC) $(CFLAGS) -c enfermaria.c

mural.o: mural.c mural.h
	$(CC) $(CFLAGS) -c mural.c

limpar:
	rm -f $(OBJ) $(ALVO)

.PHONY: limpar
