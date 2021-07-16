from cffi import FFI

ffibuilder = FFI()

ffibuilder.cdef(
"""
typedef void (*cb_t)(int data);

extern void register_cb(cb_t func);

""")

ffibuilder.embedding_api(r"""
extern "Python" void my_mod_init();
extern "Python" void my_event_callback(int);
""")

ffibuilder.embedding_init_code(r"""
from cb_test import ffi, lib

@ffi.def_extern()
def my_event_callback(data):
    print(f"Got callback in python script {data}")

# automatic initialization did not happen, so force call a dummy function
# to init the interpreter

@ffi.def_extern()
def my_mod_init():
    print("Initialized interpreter")

# name is "builtins" here, so removed the __main__ check
print("Running script, name: ", __name__)

print("PYTHON: Registered callback!")
lib.register_cb(lib.my_event_callback)

""")

ffibuilder.set_source("cb_test",r"""
#include "cbtest.h"

int start_python_wrapper() {
    return cffi_start_python();
}
""", sources=["cbtest.c"])
ffibuilder.emit_c_code("cffi-bindings.c")

