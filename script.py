from cb_test import ffi, lib
import time

# set to True to provoke the crash
#DO_CRASH = False
DO_CRASH = True

if __name__ == "__main__":
    lib.register_cb(lib.my_event_callback)
    # allows to get a few callbacks triggered without crashing
    time.sleep(2) 

    # if the loop is enabled, nothing will crash, if the loop and thus the
    # program exits, we'll get a coredump
    while not DO_CRASH:
        time.sleep(1)
