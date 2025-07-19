#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <math.h>

#include "gameRunner.h"
#include "../utils/utils.h"
#include "../scoreHandler/scoreHandler.h"

#define initial_delay 200

int readyEnemy  = 0;
int position = 0;
int row = 20 , col = 30;
int enemyArray[20][2];
int gameover = 0;
int score = 0;
int out0 = 0 , out1 = 0;
int speed;

void make_enemy()
{
	if(readyEnemy==0)
	{
		int t = rand()%2;
		enemyArray[0][t] = 1;
		readyEnemy = rand()%3+rand()%2+7;
	}

}

void draw_game()
{
	system("clear");

	int kx = 0 , ky = 0 ;
	printf("-----------CAR-GAME-----------\n");
	printf("==============================\n");
	for(int i = 0; i<row ; i++)
	{
		printf("=");
		if(i>=row-3)
		{
			if(position==0)
                        {
                                printf("     ###      ");
                                
                        }
                        else
                        {
                                printf("              ");
                        }

		}
		else
		{
			if(enemyArray[i][0]==1)
			{
				kx = 3;
			}
			if(kx>0)
			{
				printf("     ###      ");
				kx--;
			}
			else
			{
				printf("              ");
			}
		}

		printf("=");	

		
		if(i>=row-3)
		{
			if(position==1)
                        {
                                printf("     ###     ");
                        }
                        else
                        {
                                printf("             ");
                        }

		}
		else
		{	
			if(enemyArray[i][1]==1)
			{
				ky = 3;
			}
			if(ky>0)
			{       
			printf("     ###     ");
				ky--;
			}
	                else                    
			{
				printf("             ");
		        }
		}
		printf("=");
		printf("\n");
	}	

	printf("==============================\n");

	printf("\nyour Score : %d \n",score);
	printf("\t\t\t\t\t\tmade by: Aman Chuphal\n");


}



void update_game()
{
	// increament enemy position +1
	for(int i = row-1 ; i>=0 ; i--)
	{
		if(enemyArray[i][0]==1)
		{
			enemyArray[i][0] = 0;
			if(i!=row-1)
			{
				enemyArray[i+1][0] = 1;

			}
		}
		if(enemyArray[i][1]==1)
		{
			enemyArray[i][1] = 0;
			if(i!=row-1)
			{
				enemyArray[i+1][1] = 1;
			}
		}
	}

	// variable to check enemy can be made or not
	if(readyEnemy>0) readyEnemy--;
	
	// variable to check game over condition
	if(enemyArray[row-4][0]==1) out0 = 3;
	else if(out0>0) out0--;
	
	if(enemyArray[row-4][1]==1) out1 = 3;
	else if(out1>0) out1--;
	
	// calculate score
	if(enemyArray[row-1][0]==1 || enemyArray[row-1][1]==1) score+=10;

}


void check_gameover()
{
	if(out0>0 && position==0) gameover = 1;
        if(out1>0 && position==1) gameover = 1;

}

int input_game()
{
	char key;
	if(kbhit()==1)
        {

                key = getch();
                if(key=='x')
                {
			gameover = 1;	
                        return 1;
                }
		if(key=='a')
		{
			position = 0;
		}
		if(key=='d')
		{
			position = 1;
		}

        }

	return 0;	
}


void setup_game()
{
	for(int i = 0;i<30;i++)
	{
		enemyArray[i][0]=0;
		enemyArray[i][1]=0;
	}
	score = 0;
}

int appropriate_speed() {
	int min_delay = 40;
	double decay_constant = 0.00536;
	double delay = initial_delay * exp(-decay_constant * score);
	return delay < min_delay ? min_delay : (int)delay;	
}

void loop_game()
{
	// speed_controler = delay time || less value of variable speed the faster the speed.
	int speed_controler = initial_delay;
        int back = 0;
	while(1)
        {
		if(gameover==1)
                {
                        save_score(score);
			break;
                }
		make_enemy();
		back = back | input_game();
                draw_game();
		update_game();
		check_gameover();
        	back = back | input_game();
		if(back) break;
		speed_controler = appropriate_speed();
		delay(speed_controler);
        }
}
