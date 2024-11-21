TARGET = build/bin/onpoint
TARGET_TEST = build/bin/test_runner

# Flags pro compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
# TODO Adicionar path para a lib de GUI quando decidirmos

# Diretorios para compilacao
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = test
INCLUDE_DIR = include
BIN_DIR = build/bin
OBJ_DIR = build/obj

# TODO Adicionar flags e diretorios pra lib de GUI

# Lib de testes
CATCH2_INCLUDE = -I$(INCLUDE_DIR)/catch2

# Fontes e objetos dos testes
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SRCS))

# Regra default
all: $(TARGET)

# Criacao dos diretorios de build
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Compilacao geral do projeto
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilacao dos objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Executar testes
test: $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TEST) $(OBJS) $(TEST_OBJS)
	./test_runner

# Compilar testes
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar build e cache
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET) test_runner
