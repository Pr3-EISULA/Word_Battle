SRC_DIR = include

OUTPUT_DIR = release

OBJS = $(SRC_DIR)/*.cpp

OBJ_NAME = words_battle-0.1

COMPILER_FLAGS = -w -I/usr/include/SDL2

LINKER_FLAGS = -lSDL2 -lSDL2_mixer -lSDL2_image

all : $(OBJS)
	mkdir -p $(OUTPUT_DIR)
	cp -r $(SRC_DIR)/images $(OUTPUT_DIR)
	cp -r $(SRC_DIR)/sounds $(OUTPUT_DIR)
	clang++-4.0 -std=c++14 $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) \
	-o $(OUTPUT_DIR)/$(OBJ_NAME)

clean:
	rm -fr $(OUTPUT_DIR)
