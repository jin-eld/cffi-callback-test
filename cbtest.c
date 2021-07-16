#include <stdio.h>

#include "cbtest.h"

static cb_t callback = NULL;

void register_cb(cb_t func)
{
    callback = func;
}

void invoke_cb(int data)
{
    if (callback)
    {
        callback(data);
    }
}
