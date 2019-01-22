#include "soundplayer.h"
#include "common.h"

/**
 *  Initialize audio and start playing immediately
 ***************************************************************/
void soundplayer_init(SOUNDPLAYER *player) {
    //Set up AUDIOSTREM structure
    player->outStream.stream            = NULL;
    player->outStream.sampleRate        = 44100;
    player->outStream.sampleFormat      = paFloat32;
    player->outStream.inChannels        = 0;
    player->outStream.outChannels       = 2;
    player->outStream.framesPerBuffer   = 512;

    //Read audio file into memory (Background)
    player->err = wavread(BACKGROUND_SOUND_PATH, &player->background);
    checkErr(player->err, kSndFileSystem, "Failed to read background sound into memory.");
    //Read audio file into memory (Ball Hit)
    player->err = wavread(BALL_HIT_SOUND_PATH, &player->ballHit);
    checkErr(player->err, kSndFileSystem, "Failed to read Ball Hit sound into memory.");
    //Read audio file into memory (Ball Lost)
    player->err = wavread(BALL_LOST_SOUND_PATH, &player->ballLost);
    checkErr(player->err, kSndFileSystem, "Failed to read Ball Lost sound into memory.");
    //Read audio file into memory (Level Win)
    player->err = wavread(LEVEL_WIN_SOUND_PATH, &player->levelWin);
    checkErr(player->err, kSndFileSystem, "Failed to read Level Win sound into memory.");

    //Reset read index
    player->background_ridx = 0;
    player->ballHit_ridx    = 0;
    player->ballLost_ridx   = 0;
    player->levelWin_ridx   = 0;

    //Reset play flags
    player->play_ballHit    = 0;
    player->play_ballLost   = 0;
    player->play_levelWin   = 0;

    //Initialize Audio Stream
    player->err = initialiseAudioSystem();
    player->err = checkErr(player->err, kAudioSystem, "Failed to initialize audio system.");
    if(player->err != 0)
    {
        printf("Application will exit.");
        exit(EXIT_FAILURE);
    }

    //Open default audio stream with callback function to blend audio signals
    player->err = openDefaultAudioStream(&player->outStream, soundplayer_processingCallback, player);
    checkErr(player->err, kAudioSystem, "Failed to open default audio stream.");

    //This callback will be called as soon as the audio stream is stopped.
    player->err = setAudioStreamFinishedCallback(&player->outStream, &soundplayer_audioStreamFinished);

    //Begin playing audio stream immediately
    player->err = startAudioStream(&player->outStream);
    checkErr(player->err, kAudioSystem, "Failed to start audio stream.");
}

/**
 *  Main audio playing routine
 *  Adding Signals: https://www.allaboutcircuits.com/technical-articles/basic-operations-in-signals-overview/
 *  Some of the code about setting signal using a callback function is inherited from audio07.c file in Lab exercise
 ********************************************************************************************************************/
static int soundplayer_processingCallback(  const void *inputBuffer,
                                            void *outputBuffer,
                                            unsigned long framesPerBuffer,
                                            const PaStreamCallbackTimeInfo* timeInfo,
                                            PaStreamCallbackFlags statusFlags,
                                            void *userData) {
    SOUNDPLAYER *player = (SOUNDPLAYER*)userData;
    float *out = (float*)outputBuffer;
    unsigned long i;
    float aS;               //Audio Signal & Signal Count
    (void) timeInfo;        //Prevent unused variable warnings.
    (void) statusFlags;
    (void) inputBuffer;

    for( i=0; i<framesPerBuffer; i++ )
    {
        aS = player->background.data[player->background_ridx];

        //Increment and reset read counter as required for background music
        player->background_ridx++;
        if(player->background_ridx >= player->background.frames) player->background_ridx = 0;

        //If ball hit shall be played
        if(player->play_ballHit) {

            aS += player->ballHit.data[player->ballHit_ridx];

            player->ballHit_ridx++;
            if(player->ballHit_ridx >= player->ballHit.frames) {
                player->ballHit_ridx = 0;
                player->play_ballHit = 0;
            }
        }

        if(player->play_ballLost) {

            aS += player->ballLost.data[player->ballLost_ridx];

            player->ballLost_ridx++;
            if(player->ballLost_ridx >= player->ballLost.frames) {
                player->ballLost_ridx = 0;
                player->play_ballLost = 0;
            }
        }

        if(player->play_levelWin) {

            aS += player->levelWin.data[player->levelWin_ridx];

            player->levelWin_ridx++;
            if(player->levelWin_ridx >= player->levelWin.frames) {
                player->levelWin_ridx = 0;
                player->play_levelWin = 0;
            }
        }

        *out++ = aS;  //Set the same signal to both channels
        *out++ = aS;
    }

    return paContinue;
}

/**
 *  Not really required for our purpose,
 *  will be helpful for log message.
 ***************************************************************/
static void soundplayer_audioStreamFinished(void* userData) {
    SOUNDPLAYER *player = (SOUNDPLAYER *) userData;
    printf("Stream Completed: %s\n", player->message );
}

/**
 *  Terminate audio and clean up resources
 ***************************************************************/
void soundplayer_destroy(SOUNDPLAYER *player) {
    //Stop audio steam
    player->err = stopAudioStream(&player->outStream);
    checkErr(player->err, kAudioSystem, "Failed to stop audio stream.");

    //Stop audio system
    player->err = closeAudioStream(&player->outStream);
    checkErr(player->err, kAudioSystem, "Failed to close audio stream.");

    //Clean up
    player->err = terminateAudioSystem();
    checkErr(player->err, kAudioSystem, "Failed to terminate audio system.");
}
