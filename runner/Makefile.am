LIMBO_LIBRARY_VERSION = 0:0:0

AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = liblimbo.la
liblimbo_la_SOURCES = limbo.h limbo.c
library_includedir = $(includedir)/liblimbo
library_include_HEADERS = limbo.h
liblimbo_la_LDFLAGS = -m32 -version-info $(LIMBO_LIBRARY_VERSION) -export-dynamic
liblimbo_la_CFLAGS = -m32
