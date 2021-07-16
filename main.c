#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "cbtest.h"

//extern PyMODINIT_FUNC PyInit_cb_test();

extern void my_mod_init();

int main()
{
    /*
    pthread_t t;
    pthread_create(&t, NULL, runner, NULL);
*/

    my_mod_init();

    int i = 0;

    while (1)
    {
        printf("Invoking python callback...\n");
        invoke_cb(i++);
        usleep(1000000);
    }

    return 0;
}
