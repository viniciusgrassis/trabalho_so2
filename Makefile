CC = gcc
CFLAGS =
TARGET = tp2virtual 
OBJ_SRC = objetos
SOURCES_C = $(shell find . -name '*.c')
OBJ = $(patsubst ./%, $(OBJ_SRC)/%, $(SOURCES_C:.c=.o))
LIBFLAG = -lm

FILE = compilador.log
PAGE = 8
MEMORY = 128

$(OBJ_SRC)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build: $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBFLAG)

run: $(TARGET)
	@echo "$(FILE)"
	./$(TARGET) nru            $(FILE) $(PAGE) $(MEMORY)
	@echo ""
	./$(TARGET) lru            $(FILE) $(PAGE) $(MEMORY)
	@echo ""
	./$(TARGET) segunda_chance $(FILE) $(PAGE) $(MEMORY)
	@echo "--------------------------------------------"

debug: $(TARGET)
	./$(TARGET) nru $(FILE) $(PAGE) $(MEMORY) debug >> log.txt

clean:
	rm -rf $(OBJ_SRC)

cleanLog:
	rm *.log
