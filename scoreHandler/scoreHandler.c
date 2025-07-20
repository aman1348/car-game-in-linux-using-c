#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

#include "scoreHandler.h"

#define MAX_SCORES 10
#define SCORE_FILE "score.txt"

void save_score(int score) {
	// try to mentain the scores in Decending Order
	
	int scores[MAX_SCORES + 1]; // +1 for the new score
    	int count = 0;
    	int inserted = 0;
	
    	// Step 1: Read existing scores
    	FILE* file = fopen(SCORE_FILE, "r");
    	if (file != NULL) {
		while (fscanf(file, "%d", &scores[count]) == 1 && count < MAX_SCORES) {
		    // Step 2: Insert new score in correct position
	    	if (!inserted && new_score > scores[count]) {
			for (int j = MAX_SCORES; j > count; --j)
			    scores[j] = scores[j - 1]; // shift
			scores[count] = new_score;
			inserted = 1;
			count++;
		    } else {
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
	
    	// Step 3: Write top scores back to file
    	file = fopen(SCORE_FILE, "w");
    	if (file == NULL) {
		perror("Error writing score file");
	        return;
    	}
	
    	for (int i = 0; i < count && i < MAX_SCORES; ++i) {
		fprintf(file, "%d\n", scores[i]);
    	}
	
    	fclose(file);

	
	// FILE* file = fopen(SCORE_FILE, 'a');
	// int scores[10];
	// int i = 0;
	// if(file == NULL) {
	// 	perror("Error saving your score");
	// 	return;
	// }
	// fprintf(file, "%d\n", score);
	// fclose(file);
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

