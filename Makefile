# Tux Store — build & install helpers (the real build system is cargo).

PREFIX  ?= /usr
DESTDIR ?=
PROFILE ?= release
TARGET  := target/$(PROFILE)

.PHONY: all build run test check install uninstall clean

all: build

# Builds the executable AND every libtux_*.so (all workspace members).
build:
	cargo build $(if $(filter release,$(PROFILE)),--release,)

run: build
	$(TARGET)/tux-store

test:
	cargo test --workspace

check:
	cargo check --workspace

install: build
	install -Dm755 $(TARGET)/tux-store $(DESTDIR)$(PREFIX)/bin/tux-store
	install -d $(DESTDIR)$(PREFIX)/lib/tux-store
	install -m755 $(TARGET)/libtux_*.so $(DESTDIR)$(PREFIX)/lib/tux-store/
	install -d $(DESTDIR)$(PREFIX)/share/tux-store
	cp -r data/. $(DESTDIR)$(PREFIX)/share/tux-store/
	install -Dm644 packaging/tux-store.desktop $(DESTDIR)$(PREFIX)/share/applications/tux-store.desktop
	install -Dm644 LICENSE $(DESTDIR)$(PREFIX)/share/licenses/tux-store/LICENSE

uninstall:
	rm -f  $(DESTDIR)$(PREFIX)/bin/tux-store
	rm -rf $(DESTDIR)$(PREFIX)/lib/tux-store $(DESTDIR)$(PREFIX)/share/tux-store
	rm -f  $(DESTDIR)$(PREFIX)/share/applications/tux-store.desktop

clean:
	cargo clean
