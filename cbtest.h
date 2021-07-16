#ifndef __CBTEST_H__
#define __CBTEST_H__

typedef void (*cb_t)(int data);

extern void register_cb(cb_t func);
extern void invoke_cb(int data);

#endif
