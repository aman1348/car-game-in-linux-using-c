#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/select.h>

#include "utils/utils.h"


int rows = 20;
int cols = 30;
int selected_item = 1;
char menu_items[4][20] = {"Start Game ", "Controls   ", "Exit       ", "High Scores"};


void draw_menu(int blink) {

	system("clear");
	printf("-----------CAR-GAME-----------\n");
	printf("==============================\n");
	int i = 0;
	// print menu
	for( ; i<4; i++) {
		if((i+1) == selected_item && blink%2 == 1) {
			printf("= %d.                         =\n", i+1, menu_items[i]);
			continue;
		}
		
		printf("= %d. %s             =\n", i+1, menu_items[i]);
		
	}
	// print empty rows
	for( ; i<rows; i++) {
		printf("=                            =\n");
	}
	printf("==============================\n");
	
}

void draw_controls() {

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
                if(key=='x')
                {
                        // false = break control loop
                        return false;
                }
        }
        return true;

}

void controls_loop() {
        bool back = true;
        // draw once (to avoid printing at every itteration)
        draw_controls();
        while(back) {
                back = input_controls();
                delay(100);
        }
}


void input_menu()
{
	char key;
	if(kbhit()==1)
        {

                key = getch();
                if(key=='\n')
                {
			switch(selected_item) {
				case 1: //start game
					break;
				case 2: controls_loop();  // controls
					break;
				case 3: exit(0);  // exit
					break;
				case 4: // scores
					break;
			}
                        
                }
		else if(key=='w')
		{
			printf("a\n");
			selected_item = (selected_item > 1) ? selected_item - 1 : 1;
		}
		else if(key=='s')
		{
			printf("s \n");
			selected_item = (selected_item < 4) ? selected_item + 1 : 4;
		}
		else if(key=='x')
                {
                        exit(0);
                }


        }

	
}


void menu_loop() {
	int blink = 0;
	while(1) {
		input_menu();
		draw_menu(blink);

		blink = (blink + 1) % 1000;
		delay(200);
	}
}

void main() {
	menu_loop();
}
