LIMBO_LIBRARY_VERSION = 0:0:0

AUTOMAKE_OPTIONS = foreign
EXTRA_DIST = README

lib_LTLIBRARIES = liblimbo.la
liblimbo_la_SOURCES = src/limbo.h src/limbo.c
library_includedir = $(includedir)/liblimbo
library_include_HEADERS = src/limbo.h
liblimbo_la_LDFLAGS = -m32 -version-info $(LIMBO_LIBRARY_VERSION)
liblimbo_la_CFLAGS = -m32
