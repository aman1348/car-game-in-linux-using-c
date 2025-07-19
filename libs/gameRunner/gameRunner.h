#ifndef GAME_RUNNER
#define GAME_RUNNER

void make_enemy();
void draw_game(int rows);
void update_game(int rows);
void check_gameover();
int input_game();
void setup_game(int rows);
int appropriate_speed();
void loop_game(int rows);

#endif
