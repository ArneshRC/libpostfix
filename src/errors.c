#include "errors.h"

void abort_if_not(bool condition, const char* message) {
    if(condition) return;
    fprintf(stderr, "\n%s\n", message);
    abort();
}

