CPPFLAGS = -Iinclude -MMD -MP
CFLAGS = -fPIC -Wall -Wextra -O2
LDLIBS = -lm

SRC_DIR = src
OBJ_DIR = build
TARGET_DIR = lib

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
TARGET = $(TARGET_DIR)/libpostfix.a

PREFIX ?= /usr/local

.PHONY: all clean install

all: $(TARGET)

$(TARGET): $(OBJ) | $(TARGET_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TARGET_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)

install: $(TARGET)
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 lib/*.a $(DESTDIR)$(PREFIX)/lib/
	install -d $(DESTDIR)$(PREFIX)/include/libpostfix
	install -m 644 include/*.h $(DESTDIR)$(PREFIX)/include/libpostfix

-include $(OBJ:.o=.d) 

