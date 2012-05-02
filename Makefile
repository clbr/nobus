NAME = libnobus.a
SRC = stubs.c
OBJ = stubs.o

PREFIX = /usr/local
DESTDIR =

CFLAGS += -Iinclude/dbus-1.0 -Wall
CFLAGS += $(shell pkg-config --cflags glib-2.0)

LDFLAGS += -Wl,-O1


all: $(NAME)

$(NAME): $(OBJ)
	ar cru $(NAME) $(OBJ)
	ranlib $(NAME)


.PHONY: clean all install


clean:
	rm -f *.o *.a

install:
	@echo Installing
