# project info
PROJECT_NAME := physics-engine
VERSION := 0.0.1
AUTHOR := Aditya Jyoti

# compiler settings
CXX := g++
CXXVERSION := c++20
CXXFLAGS := -Wall -Wextra -Werror -std=${CXXVERSION} -MMD -MP

# directories 
SRC_DIR := ${PROJECT_NAME}/src
LIB_DIR := ${PROJECT_NAME}/lib

BUILD_DIR := build
OBJ_DIR := ${BUILD_DIR}/obj

# files
SRC_FILES := $(shell find ${SRC_DIR} -name '*.cpp')
OBJ_FILES := $(patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR}/%.o, ${SRC_FILES})

# dependency files
DEPS := $(OBJ_FILES:.o=.d)

# compilation rules

TARGET := ${BUILD_DIR}/${PROJECT_NAME}

.PHONY: all
all: ${TARGET}

# $@ - target
# $^ - obj_files
${TARGET}: ${OBJ_FILES} 
	${CXX} ${CXXFLAGS} -o $@ $^ 

# $< - source file
${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	@mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -c $< -o $@

-include ${DEPS}

# run
.PHONY: run
run: ${TARGET}
	./${TARGET}

# clean up
.PHONY: clean 
clean: 
	rm -rf ${BUILD_DIR}