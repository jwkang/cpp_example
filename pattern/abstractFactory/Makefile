#TOOLCHAIN_PATH = 
#CC = $(TOOLCHAIN_PATH)/bin/arm-linux-g++
CC = g++

TARGET = main

SRCS = main.cpp
OBJECTS = main.o
OUTPUT = a.out

LIBS = -Llib 
INCLUDES = -Iinclude 
CFLAGS = $(LIBS) $(INCLUDES) -lm -std=c++11 -Wall -pedantic

all: $(TARGET)
	
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)
#	$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	$(call after_build)

$(OBJECTS): $(SRCS) 
	$(CC) $(CFLAGS) -c $<

.SUFFIXES : .cpp .o
.PHONY: clean

clean :
	rm -f $(OBJECTS) $(TARGET) $(OUTPUT)

define after_build
	@echo "make complete $(1)"
	@echo ""
	@echo ""
	-@./$(OUTPUT)
endef
