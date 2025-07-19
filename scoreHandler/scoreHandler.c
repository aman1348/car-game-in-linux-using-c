#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

#include "scoreHandler.h"

#define SCORE_FILE "score.txt"

void save_score(int score) {
	// try to mentain the scores in Decending Order
	FILE* file = fopen(SCORE_FILE, 'a');
	int scores[10];
	int i = 0;
	if(file == NULL) {
		perror("Error saving your score");
		return;
	}
	fprintf(file, "%d\n", score);
	fclose(file);
}

void draw_scores(int rows) {
	FILE* file = fopen(SCORE_FILE, 'r');
        if(file == NULL) {
                perror("Scores Not Available.\n");
                return;
        }
	int i = 1;
	int score;
	select("clear");
	printf("-----------CAR-GAME-----------\n");
	printf("==============================\n");
	printf("=           Top Scores       =\n");
	// Print Scores
	while(fscanf(file, "%d", &score) != EOF) {		
	printf("=    %d.      %d               =\n", i, score);
	i++;
	}
	
	// print empty rows
	for( ; i<rows; i++) {	
	printf("=                            =\n");
	}
	printf("==============================\n");
}

