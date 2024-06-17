#include <stdio.h>
#include <stdlib.h>

extern "C" {
#include "nosefart/nsf.h"
};

int main(int argc, char* argv[])
{
    if (nsf_init()) {
        puts("nsf_init failed");
        exit(-1);
    }
    return 0;
}