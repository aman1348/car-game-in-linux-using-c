#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

#include "scoreHandler.h"
#include "../utils/utils.h"

#define MAX_SCORES 10
#define SCORE_FILE "resources/data/score.txt"

void save_score(int new_score) {
	// try to mentain the scores in Decending Order
	
	int scores[MAX_SCORES + 1]; 
    	int count = 0;
    	int inserted = 0;
	
    	// Read existing scores
    	FILE* file = fopen(SCORE_FILE, "r");
    	if (file != NULL) {
		while (fscanf(file, "%d", &scores[count]) == 1 && count < MAX_SCORES) {

		    // Insert new score in correct position
	    		if (!inserted && new_score >= scores[count]) {
				scores[count+1] = scores[count];
				scores[count] = new_score;
				inserted = 1;
				count += 2;
			    } 
			else {	
				count++;
				}
		}
		fclose(file);
    	}
	
    	// If new score wasn't inserted and there's still space, add it at end
    	if (!inserted && count < MAX_SCORES) {
		scores[count++] = new_score;
		inserted = 1;
    	}
	
    	// Write top scores back to file
    	file = fopen(SCORE_FILE, "w");
    	if (file == NULL) {
		perror("Error writing score file");
	        return;
    	}
	
    	for (int i = 0; i < count && i < MAX_SCORES; ++i) {
		fprintf(file, "%d\n", scores[i]);
    	}
	
    	fclose(file);

	
}

void print_score_padded(int score) {
	int temp = score;
	int digits = 0;
	while(temp > 0) {
		digits++;
		temp /= 10;
	}
	if(score == 0) digits = 1;
	printf("%d", score);
	for(int i = 0; i < 6-digits; i++) {
		printf(" ");
	}
}

void draw_scores(int rows) {
	FILE* file = fopen(SCORE_FILE, "r");
	int i = 1;
	int score;
	// Clear Screen
	system("clear");
	printf("-----------CAR-GAME-----------\n");
	printf("==============================\n");
	printf("=           Top Scores       =\n");
	// Print Scores
	while(file != NULL && fscanf(file, "%d", &score) != EOF) {		
		if(i == 10) {
			printf("=    %d.     ", i);
		}
		else {
			printf("=    %d.      ", i);
		}
		print_score_padded(score);
		printf("          =\n");
		i++;
	}
	
	// print empty rows
	for( ; i<rows; i++) {	
		printf("=                            =\n");
	}
	printf("==============================\n");
}

int input_scores()
{
	char key;
	if(kbhit()==1) {
                key = getch();
                if(key=='x' || key=='\n')
                {
			// back
			return 1;
                }
        }
	return 0;	
}

void loop_scores(int rows) {
	int back = 0;
	draw_scores(rows);
	while(1) {
		back = input_scores();
		if(back) break;
		delay(10);
	}
}

