/*Elkulator v1.0 by Sarah Walker
  Linux main loop*/
#ifndef WIN32

#include <allegro.h>
#include "elk.h"

char ssname[260];
char scrshotname[260];
char moviename[260];

int tapespeed;
int fullscreen=0;
int gotofullscreen=1;
int videoresize=0;
int wantloadstate=0,wantsavestate=0;
int winsizex=640,winsizey=512;

int plus3=0;
int dfsena=0,adfsena=0;
int turbo=0;
int mrb=0,mrbmode=0;
int ulamode=0;
int drawmode=0;

char discname[260];
char discname2[260];
int quited=0;
int infocus=1;

void startblit()
{
}
void endblit()
{
}

int keylookup[128],keylookup2[128];

int main(int argc, char *argv[])
{
        int ret = allegro_init();
        if (ret != 0)
        {
                fprintf(stderr, "Error %d initializing Allegro.\n", ret);
                exit(-1);
        }
        initelk(argc,argv);
        install_mouse();
        while (!quited)
        {
                runelk();
                if (key[KEY_F11]) entergui();
                if (key[KEY_ESC])
                {
                return D_CLOSE;
                }
                if (gotofullscreen == 1) 
                {
                fullscreen=1;
                gotofullscreen=0;
                enterfullscreen();
                }
        }
        closeelk();
        return 0;
}

END_OF_MAIN();

#endif
