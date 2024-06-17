#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" {
#include "nosefart/nsf.h"
};

static void audioCallback(void* userdata, Uint8* stream, int len)
{
    nsf_t* nsf = (nsf_t*)userdata;
    nsf_frame(nsf);
    nsf->process(stream, len / 2);
}

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

    // load .nsf
    auto nsf = nsf_load(argv[1], nullptr, 0);
    if (!nsf) {
        puts("load failed");
        return -1;
    }

    // play track 0
    nsf_playtrack(nsf, 0, 44100, 16, false);

    // initialize SDL sound system
    if (SDL_Init(SDL_INIT_AUDIO)) {
        puts("SDL_Init failed");
        return -1;
    }

    SDL_AudioSpec desired;
    SDL_AudioSpec obtained;
    desired.freq = 44100;
    desired.format = AUDIO_S16LSB;
    desired.channels = 1;
    desired.samples = 735; // desired.freq * 20 / 1000;
    desired.callback = audioCallback;
    desired.userdata = nsf;
    auto audioDeviceId = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0);
    if (0 == audioDeviceId) {
        puts("SDL_OpenAudioDevice failed");
        return -1;
    }
    SDL_PauseAudioDevice(audioDeviceId, 0);

    printf("Press enter to exit...");
    fgetc(stdin);

    SDL_CloseAudioDevice(audioDeviceId);
    SDL_Quit();
    nsf_free(&nsf);
    return 0;
}
