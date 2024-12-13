CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17

# Librerías de SFML
LIBS = -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window

# Directorios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN = Game

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Regla principal
all: $(BIN)

# Enlace final
$(BIN): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LIBS) -o $@

# Compilación de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BIN)
