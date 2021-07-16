# CFFI C to Python callacks: cffi_start_python() initialization workaround

The cffi embedding docs say, that one can call `cffi_start_python()` directly
in order to force Python initialization when needed. However, the function
is being generated with a static declaration, which makes it impossible to
call it from `main()`.

This example presents a workaround by injecting a non static wrapper function
into the generated code via `ffibuilder.set_source()`.

## Build

To enable `-O0 -g` run configure with the `--enable-debug` parameter.

```
autoreconf -if
./configure
make
```

## Run

After building run:

`./cbtest`

Press Ctrl-C to quit.
