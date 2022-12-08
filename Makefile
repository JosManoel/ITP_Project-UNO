# Flags de compilação, utilizadas para passar paramentros para o gcc

C_FLAGS = -g       \
		  -std=c99 \
		  -Wall	   \
		  -Wextra  \
		  -pedantic

# ---------- CONTROLLERS ----------

COMMENT_CONTROLLER = controllers/commentController.c
MOVEMENT_CONTROLLER = controllers/movementController.c
PLAYER_CONTROLLER = controllers/playerController.c

CONTROLLERS = commentController.o movementController.o playerController.o


# ---------- RESOURCES ----------

FUNCS = resources/funcs.c

# Compilar componentes todos os componentes
all: yugi clean
	clear
	@ echo 'Yugi: É HORA DO DUELO!'

yugi: main.c funcs commentController movementController playerController
	gcc funcs.o $(CONTROLLERS) main.c -o yugi $(C_FLAGS)

funcs: $(FUNCS)
	gcc $(FUNCS) -c $(C_FLAGS)

commentController: $(COMMENT_CONTROLLER)
	gcc $(COMMENT_CONTROLLER) -c $(C_FLAGS)

movementController: $(MOVEMENT_CONTROLLER)
	gcc $(MOVEMENT_CONTROLLER) -c $(C_FLAGS)

playerController: $(PLAYER_CONTROLLER)
	gcc $(PLAYER_CONTROLLER) -c $(C_FLAGS)

# Limpa os arquivos .o
clean:
	rm -rf *.o *~ printy
