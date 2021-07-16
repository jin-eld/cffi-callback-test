from cffi import FFI

ffibuilder = FFI()
ffibuilder.cdef(
"""
typedef void (*cb_t)(int data);

extern void register_cb(cb_t func);

extern "Python" void my_event_callback(int);
""")
ffibuilder.set_source("cb_test",'#include "cbtest.h"', sources=["cbtest.c"])
ffibuilder.emit_c_code("cffi-bindings.c")

