#####################################################
# Define some Makefile variables
#####################################################

CC = g++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./libs/"
SRC_FILES = src/*.cpp src/Game/*.cpp src/Logger/*.cpp src/ECS/*.cpp
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua
OBJ_NAME = Folke

#####################################################
# Define some Makefile rules
#####################################################

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./Folke

clean:
	rm Folke