bin_PROGRAMS = cbtest

cbtest_SOURCES = \
    main.c

cbtest_CFLAGS = \
    $(PTHREAD_CFLAGS) \
    $(PYTHON3_CFLAGS)

cbtest_LDADD = \
    $(PTHREAD_LIBS) \
    $(PYTHON3_LIBS) \
    $(top_builddir)/libpycbtest.a

noinst_LIBRARIES = libpycbtest.a

EXTRA_DIST = build.py

BUILT_SOURCES = cffi-bindings.c

CLEANFILES = $(BUILT_SOURCES)

nodist_libpycbtest_a_SOURCES = \
    $(BUILT_SOURCES) \
    cbtest.h \
    cbtest.c

libpycbtest_a_CFLAGS = \
    -I$(top_srcdir) \
    $(PYTHON3_CFLAGS)

cffi-bindings.c: build.py cbtest.h cbtest.c
	$(PYTHON3_BIN) -B $(top_builddir)/build.py
