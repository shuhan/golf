#ifndef SOUNDPLAYER_H_INCLUDED
#define SOUNDPLAYER_H_INCLUDED

#include "amio_lib.h"

typedef struct
{
    PaError err;
    AUDIOSTREAM outStream;
    SIGNAL background;
    long int background_ridx;
    SIGNAL ballHit;
    long int ballHit_ridx;
    SIGNAL ballLost;
    long int ballLost_ridx;
    SIGNAL levelWin;
    long int levelWin_ridx;
    char message[32];
    //-------------------------------
    //  Flags
    //-------------------------------
    int play_ballHit;
    int play_ballLost;
    int play_levelWin;
} SOUNDPLAYER;

void soundplayer_init(SOUNDPLAYER *player);

static int soundplayer_processingCallback(const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData);

static void soundplayer_audioStreamFinished(void* userData);

void soundplayer_destroy(SOUNDPLAYER *player);

#endif // SOUNDPLAYER_H_INCLUDED
