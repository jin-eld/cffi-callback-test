#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "cbtest.h"

/* implemented in ffibibuilder.set_source(), see build.py */
extern int start_python_wrapper();

int main()
{
    /* can't call cffi_start_python() directly, because it's being generated
     * as a static function, see cffi-bindings.c */
    start_python_wrapper();

    int i = 0;

    while (1)
    {
        printf("Invoking python callback...\n");
        invoke_cb(i++);
        usleep(1000000);
    }

    return 0;
}
