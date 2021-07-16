#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "cbtest.h"

extern PyMODINIT_FUNC PyInit_cb_test();

void *runner(void *arg)
{
    PyConfig config;
    PyConfig_InitPythonConfig(&config);
    PyImport_AppendInittab("cb_test", &PyInit_cb_test);
    PyConfig_SetBytesString(&config, &config.run_filename, "./script.py");
    Py_InitializeFromConfig(&config);
    Py_RunMain();
    return NULL;
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, runner, NULL);

    int i = 0;

    while (1)
    {
        invoke_cb(i++);
        usleep(1000000);
    }

    return 0;
}
