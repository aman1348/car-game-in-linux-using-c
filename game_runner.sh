#!/bin/bash

FILE="car_game"

# check if the output file for car_game exists or not
if [ ! -f "$FILE" ]; then
	gcc car_game.c \
		libs/menu/menu.a \
		libs/utils/utils.a \
		libs/controls/controls.a \
		libs/scoreHandler/scoreHandler.a \
		libs/gameRunner/gameRunner.a  \
		-o car_game -lm
fi

./car_game

