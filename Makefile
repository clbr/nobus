NAME = libnobus.a
SRC = stubs.c
OBJ = stubs.o

PREFIX ?= /usr/local
DESTDIR ?=

CFLAGS += -Iinclude/dbus-1.0 -Wall -fPIC
CFLAGS += $(shell pkg-config --cflags glib-2.0)

LDFLAGS += -Wl,-O1


all: $(NAME)

$(NAME): $(OBJ)
	ar cru $(NAME) $(OBJ)
	ranlib $(NAME)


.PHONY: clean all install


clean:
	rm -f *.o *.a *.pc

install: all
	@echo Installing to $(DESTDIR)/$(PREFIX)
	mkdir -p $(DESTDIR)/$(PREFIX)/lib/pkgconfig
	cp -a include $(DESTDIR)/$(PREFIX)

	sed "s@/tmp/kai@$(PREFIX)@" dbus-glib-1.pcin > dbus-glib.pc
	sed "s@/tmp/kai@$(PREFIX)@" dbus-1.pcin > dbus-1.pc

	cp *.pc $(DESTDIR)/$(PREFIX)/lib/pkgconfig

	cp $(NAME) $(DESTDIR)/$(PREFIX)/lib
