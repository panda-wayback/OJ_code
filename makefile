# 用法: make run [DIR=路径]  默认 DIR=base_answer。只需根目录这一份 Makefile。
ROOT := $(shell git rev-parse --show-toplevel 2>/dev/null)
CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -O2
ifneq ($(ROOT),)
  CXXFLAGS += -I$(ROOT)/include
endif
DIR ?= base_answer
SRC := $(DIR)/main.cc
EXE := $(DIR)/main

.PHONY: run build clean push
run: build
	cd $(DIR) && ./main

build: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE)

clean:
	rm -f $(EXE) $(EXE).dSYM

push:
	git add .
	git commit -m "update"
	git push origin master
