PWD=.
project_name=DockerCircles
TARGET=$(project_name)

exclude_dirs= include bin lib
CXX=clang++
CC=gcc
RM=rm -rf

exec=./bin
include=./include
lib=./lib

LIBS=-lm -L/usr/local/Cellar/glog/0.3.4_1/lib \
	 -L/usr/local/Cellar/boost157/1.57.0/lib \
	 -L/usr/local/lib\
	 -lglog

CFLAGS= -Wall -c
CPPFLAGS= -g -Wall -Wno-unused -Wno-write-strings \
		  -I/usr/local/Cellar/boost157/1.57.0/include/ \
		  -I/usr/local/Cellar/glog/0.3.4_1/include/ \
		  -I/usr/local/include/

SRCS=$(wildcard *.cpp) \
     $(wildcard $(SRCS_DIR)/*.cpp)
CSRCS=$(wildcard $(SRCS_DIR)/*.c)

SRCS_DIR=./src
# OBJ=$(SRCS: .cpp=.o)
OBJ=$(patsubst %.cpp, %.o, $(SRCS))
COBJ=$(patsubst %.c, %.o, $(CSRCS))

# LINK WITH link flags
$(TARGET): $(OBJ) $(COBJ)
	$(CXX) -v $(CPPFLAGS) -I$(include) -std=c++11 -stdlib=libc++ $^ $(LIBS) -o $@
	mv $@ $(exec)/

# COMPILE with compile flagsa
%.o : %.c
	$(CC) -v -std=gnu99 -I$(include) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) [INFO] $(COLOR_OFF) "find C sources: " $(CSRCS)
%.o : %.cpp
	$(CXX) -v -std=c++11 -stdlib=libc++ -I$(include) $(CPPFLAGS) -c $< -o $@
	@echo $(GREEN) [INFO] $(COLOR_OFF) "find CPP sources: " $(SRCS)

.PHONY: clean
clean:
	@echo $(GREEN) [INFO] $(COLOR_OFF) "find objs: " $(OBJ) $(COBJ)
	$(RM) $(OBJ) $(exec)/$(TARGET)

all: $(TARGET)
	@echo $(GREEN) [INFO] $(COLOR_OFF) "find sources: " $(SRCS)
	@echo $(GREEN) [INFO] $(COLOR_OFF) "target has been complied!"

run: $(TARGET)
	$(exec)/$(TARGET)

COLOR_OFF='\033[0m'
GREEN='\033[0;32m'

headers=$(wildcard $(include)/*.h) \
		$(wildcard $(include)/*.hpp)

init:
		@ echo $(GREEN) [INFO] $(COLOR_OFF) "headers are : " "$(headers)"
		@ echo $(GREEN) [INFO] $(COLOR_OFF) "srcs are" : "$(SRCS)"
		@[ -d include ] || (mkdir include && -mv "$(HEADERS)" --target-directory=include/)
		@[ -d bin ] || mkdir bin
		@[ -d lib ] || mkdir lib
		@[ -d src ] || (mkdir src && mv "$(SRCS)" --target-directory=src/)
