# 컴파일러 및 옵션 설정
CC = gcc
CFLAGS = -Wall
LDFLAGS = -L./lib

# 디렉토리 설정
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

# 소스 및 목적 파일
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# 타겟 설정
STATIC_LIB = $(LIB_DIR)/libcalc.a
SHARED_LIB = $(LIB_DIR)/libcalc.so
EXEC = $(BIN_DIR)/prog_static $(BIN_DIR)/prog_shared $(BIN_DIR)/prog_dynamic

# 기본 타겟
all: dirs $(STATIC_LIB) $(SHARED_LIB) $(EXEC)

# 디렉토리 생성
dirs:
	mkdir -p $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

# 목적 파일 생성 규칙
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# calc.o 파일 PIC 버전 생성 (공유 라이브러리용)
$(OBJ_DIR)/calc_pic.o: $(SRC_DIR)/calc.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# 정적 라이브러리 생성
$(STATIC_LIB): $(OBJ_DIR)/calc.o
	ar rcs $@ $<

# 공유 라이브러리 생성
$(SHARED_LIB): $(OBJ_DIR)/calc_pic.o
	$(CC) -shared $< -o $@

# 실행 파일 생성 (정적 링크)
$(BIN_DIR)/prog_static: $(OBJ_DIR)/functest.o $(STATIC_LIB)
	$(CC) $< $(LIB_DIR)/libcalc.a -o $@

# 실행 파일 생성 (공유 라이브러리)
$(BIN_DIR)/prog_shared: $(OBJ_DIR)/functest.o $(SHARED_LIB)
	$(CC) $< $(LDFLAGS) -lcalc -Wl,-rpath=./lib -o $@

# 실행 파일 생성 (동적 링크)
$(BIN_DIR)/prog_dynamic: $(OBJ_DIR)/functest.o $(SHARED_LIB)
	$(CC) $< $(LDFLAGS) -lcalc -Wl,-rpath=./lib -o $@

# 실행
run: all
	@echo "\n=== Static Library Program ==="
	./$(BIN_DIR)/prog_static
	@echo "\n=== Shared Library Program ==="
	./$(BIN_DIR)/prog_shared
	@echo "\n=== Dynamic Library Program ==="
	./$(BIN_DIR)/prog_dynamic

# 청소
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

.PHONY: all dirs clean run
