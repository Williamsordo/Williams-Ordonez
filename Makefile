# ============================================================================
# Makefile - Algoritmos y Programación (C Language Repository)
# ============================================================================

CC := gcc
CFLAGS := -Wall -Wextra -std=c99

# Buscar todos los archivos .c
SRCS := $(shell find . -name "*.c")
OBJS := $(SRCS:.c=.out)

.PHONY: all clean

all: $(OBJS)
	@echo "=========================================="
	@echo " Todos los programas en C compilados.    "
	@echo "=========================================="

%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "Limpiando ejecutables y temporales..."
	find . -name "*.out" -delete
	find . -name "*.exe" -delete
	find . -name "*.o" -delete
