TARGET = build/bin/onpoint
TARGET_TEST = build/bin/test_runner

# Flags pro compilador
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -Iinclude/backends

# Diretorios para compilacao
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = test
INCLUDE_DIR = include
BIN_DIR = build/bin
OBJ_DIR = build/obj

# Dependencias de GUI (Este trecho so deve funfar no Linux nn sei como faz para win)
GLFW_INCLUDE = -I/usr/include/GLFW
GLFW_LIB = -lglfw
OPENGL_LIB = -lGL
GLEW_LIB = -lGLEW

# Lib de GUI
IMGUI_DIR = imgui
IMGUI_INCLUDE = -I$(INCLUDE_DIR)
IMGUI_SRC = $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp\
            $(IMGUI_DIR)/imgui_widgets.cpp $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp \
            $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp

# Lib de testes
CATCH2_INCLUDE = -I$(INCLUDE_DIR)/catch2

# Fontes e objetos dos testes
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/view/*.cpp) \
		$(wildcard $(SRC_DIR)/model/*.cpp) $(wildcard $(SRC_DIR)/controller/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_SRCS))

# Regra default
all: $(TARGET)

# Criacao dos diretorios de build
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Compilacao geral do projeto
$(TARGET): $(OBJS) $(IMGUI_SRC) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GLFW_LIB) $(OPENGL_LIB) $(GLEW_LIB)

# Compilacao dos objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Executar testes
test: $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TEST) $(OBJS) $(TEST_OBJS) $(GLFW_LIB) $(OPENGL_LIB) $(GLEW_LIB)
	./test_runner

# Compilar testes
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(GLFW_INCLUDE) $(IMGUI_INCLUDE) -c $< -o $@

# Roda o binario
run:
	@if [ -f $(TARGET) ]; then \
		echo "Running $(TARGET)..."; \
		$(TARGET); \
	else \
		echo "Error: $(TARGET) not found. Compile the project first using 'make'."; \
		exit 1; \
	fi

# Limpar build e cache
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET) test_runner
