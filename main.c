#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

//msdn example:
//https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfoa?redirectedfrom=MSDN#examples


#define ARG_SPEED_INDEX 1
#define SYS_SPEED_INDEX 2
#define ARGS            2

int main (int argc, char ** argv)
{
    if (argc != ARGS) 
    {
        printf(stderr, "Error: mspeed only takes one argument. Try 'mspeed <speed>'. speed must be between 0 and 20.");
        return EXIT_FAILURE;
    }
    
    int new_speed = atoi(argv[ARG_SPEED_INDEX]);
    if (new_speed < 0 || new_speed > 20) 
    {
        printf(stderr, "Error: invalid mouse speed -- must be between 0 and 20");
        return EXIT_FAILURE;
    }

    int data[3] = {0};
    if (SystemParametersInfo(SPI_GETMOUSE, 0, &data,0)) 
    {
        data[SYS_SPEED_INDEX] = new_speed;
    }
    else 
    {   
        printf(stderr, "Error: could not get mouse data");
        return EXIT_FAILURE;
    }

    SystemParametersInfo(SPI_SETMOUSE, 0, data, SPIF_SENDCHANGE);
}