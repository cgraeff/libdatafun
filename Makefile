SHELL := /bin/bash # Use bash as shell
TARGET = libdatafun.a

.PHONY: all debug clean

all:
	@echo "[Compiling...]"
	@cd src; make
	@echo "[done.]"
debug:
	@echo "[Compiling with debug symbols...]"
	@cd src; make debug
	@echo "[done]"
clean:
	@echo "[Cleaning...]"
	@-rm -f $(TARGET)
	@cd src; make clean
	@echo "[done.]"
