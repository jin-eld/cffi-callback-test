# CFFI C to Python callacks - crash reproduction

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

## Provoke crash

Edit `./script.py` and set the `DO_CRASH` variable to `True`, this will
eliminate the endless `while` loop at the end of the program and cause
a crash when a callback from C is triggered into Python.



