#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
//link user32 lib when compiling

//https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa


#define SPEED_INDEX 1
#define ARGS        2

int main (int argc, char ** argv)
{
    if (argc != ARGS) 
    {
        fprintf(stderr, "Error: mspeed only takes one argument. Try 'mspeed <speed>'. speed must be between 1 and 20.");
        return EXIT_FAILURE;
    }
    
    int new_speed = atoi(argv[SPEED_INDEX]);
    if (new_speed < 1 || new_speed > 20) 
    {
        fprintf(stderr, "Error: invalid mouse speed -- must be between 1 and 20");
        return EXIT_FAILURE;
    }

    if (!SystemParametersInfo(SPI_SETMOUSESPEED, 0, (LPVOID)(intptr_t)new_speed, SPIF_UPDATEINIFILE | 
                                                                       SPIF_SENDCHANGE | 
                                                                       SPIF_SENDWININICHANGE))
    {
        fprintf(stderr, "Error: could not set new mouse speed");
        return EXIT_FAILURE;
    }
}