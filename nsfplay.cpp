#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" {
#include "nosefart/nsf.h"
};

int main(int argc, char* argv[])
{
    if (nsf_init()) {
        puts("nsf_init failed");
        return -1;
    }

    if (argc < 2) {
        puts("usage: nsfplay /path/to/file.nsf");
        return 1;
    }

    auto nsf = nsf_load(argv[1], nullptr, 0);
    if (!nsf) {
        puts("load failed");
        return -1;
    }

    nsf_free(&nsf);
    return 0;
}
