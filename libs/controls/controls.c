#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

#include "controls.h"
#include "../utils/utils.h"

void draw_controls(int rows) {

        system("clear");
        printf("-----------CAR-GAME-----------\n");
        printf("==============================\n");

        printf("=         Controls:          =\n");
        printf("=  Navigation:               =\n");
        printf("=    up:              %c      =\n", 'w');
        printf("=    down:            %c      =\n", 's');
        printf("=    select:          Enter  =\n");
        printf("=    back:            %c      =\n", 'x');
        printf("=  Game Play:                =\n");
        printf("=    move right:      %c      =\n", 'd');
        printf("=    move left:       %c      =\n", 'a');
        printf("=    back:            %c      =\n", 'x');

	// print empty rows
	for(int i = 10; i<rows; i++) {
        	printf("=                            =\n");
        }

        printf("==============================\n");

}

bool input_controls() {
        char key;
        if(kbhit()==1)
        {

                key = getch();
                if(key=='x' || key=='\n')
                {
                        // false = break control loop
                        return false;
                }
        }
        return true;

}

void loop_controls(int rows) {
        bool back = true;
        // draw once (to avoid printing at every itteration)
        draw_controls(rows);
        while(back) {
                back = input_controls();
                delay(100);
        }
}

