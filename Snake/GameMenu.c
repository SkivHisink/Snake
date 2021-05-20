#include "Conlib.h"
#include "Menu.h"
#include "Game.h"
#include "GameMenu.h"
#include <stdio.h>
#include <stdlib.h>

void GameMenu(int maxX, int maxY, int *Score, char *Name, double *Time) {
	ClearConsole();
	int flag = 0;
	int key;
	int maxXS, maxYS; // reference
	int X_Pos = 1, Y_Pos = 1;
	int SnakeColor = 0x0010, FoodColor = 0x0040;
	MaxXY(&maxX, &maxY);
	maxXS = maxX;
	maxYS = maxY;
	Y_Pos = maxY / 4;
	frame(maxX, maxY, FOREGROUND_RED);
	SetColor(FOREGROUND_BLUE);
	GotoXY(maxX / 2 - maxX / 20 - 2, Y_Pos);
	printf("->");
	while (!flag) {
		MaxXY(&maxX, &maxY);
		if (maxXS != maxX || maxYS != maxY) {
			maxXS = maxX;
			maxYS = maxY;
			ClearConsole();
			Y_Pos = maxY / 4;
			GotoXY(maxX / 2 - maxX / 20 - 2, Y_Pos);
			printf("->");
			ConShowCursor(0);
		}
		frame(maxX, maxY, FOREGROUND_RED);

		SetColor(FOREGROUND_BLUE);
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 - 1);
		printf("Game Settings");
		SetColor(FOREGROUND_RED);
		GotoXY(maxX / 2 - maxX / 20, maxY / 4);
		printf("Play");
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 2);
		printf("Level");
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 4);
		printf("Color of Snake:");
		GotoXY(maxX / 2 - maxX / 20 + 16, maxY / 4 + 4);
		SetColor(SnakeColor);
		printf("  ");
		SetColor(FOREGROUND_RED);
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 6);
		printf("Color of Food:");
		GotoXY(maxX / 2 - maxX / 20 + 16, maxY / 4 + 6);
		SetColor(FoodColor);
		printf("  ");
		SetColor(FOREGROUND_RED);
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 8);
		printf("Back to Main Menu");
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 10);
		SetColor(FOREGROUND_BLUE);
		printf("!!!WARNING!!!");
		GotoXY(maxX / 2 - maxX / 5, maxY / 4 + 11);
		printf("Only in game settings you can change frame size for game!");

		key = GetKey();

		SetColor(0x0000 | 0x0000);
		if (key == KEY_ESC)
			flag = 1;
		if ((key == KEY_UP) && (Y_Pos == maxY / 4)) {
			GotoXY(maxX / 2 - maxX / 20 - 2, Y_Pos);
			printf("  ");
			Y_Pos = maxY / 4 + 8;

		}
		else if (key == KEY_UP) {
			GotoXY(maxX / 2 - maxX / 20 - 2, Y_Pos);
			printf("  ");
			Y_Pos = Y_Pos - 2;
		}
		if ((key == KEY_DOWN) && (Y_Pos == maxY / 4 + 8)) {
			GotoXY(maxX / 2 - maxX / 20 - 2, Y_Pos);
			printf("  ");
			Y_Pos = maxY / 4;
		}
		else if (key == KEY_DOWN) {
			GotoXY(maxX / 2 - maxX / 20 - 2, Y_Pos);
			printf("  ");
			Y_Pos = Y_Pos + 2;
		}
		if ((key == KEY_LEFT) && (Y_Pos == maxY / 4 + 6)) {
			if (FoodColor > 0) {
				FoodColor -= 20;
				printf("Color of Snake:");
				GotoXY(maxX / 2 - maxX / 20 + 16, maxY / 4 + 4);
				SetColor(SnakeColor);
				printf("  ");
			}
		}
		else if ((key == KEY_LEFT) && (Y_Pos == maxY / 4 + 4)) {
			if (SnakeColor > 0) {
				SnakeColor -= 20;
				GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 4);
				printf("Color of Snake:");
				GotoXY(maxX / 2 - maxX / 20 + 16, maxY / 4 + 4);
				SetColor(SnakeColor);
				printf("  ");
			}
		}
		if ((key == KEY_RIGHT) && (Y_Pos == maxY / 4 + 6)) {
			if (FoodColor < 257) {
				FoodColor += 20;
				printf("Color of Snake:");
				GotoXY(maxX / 2 - maxX / 20 + 16, maxY / 4 + 4);
				SetColor(SnakeColor);
				printf("  ");
			}
		}
		else if ((key == KEY_RIGHT) && (Y_Pos == maxY / 4 + 4)) {
			if (SnakeColor < 257) {
				SnakeColor += 20;
				GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 4);
				printf("Color of Snake:");
				GotoXY(maxX / 2 - maxX / 20 + 16, maxY / 4 + 4);
				SetColor(SnakeColor);
				printf("  ");
			}
		}
		if (key == KEY_ENTER) {
			if (Y_Pos == maxY / 4) /*Game*/ {
				flag = 3;
				GameP(SnakeColor, FoodColor);
				Score = ReturnScore();
				Time = ReturnTime();
				SetColor(FOREGROUND_BLUE);
				GotoXY(maxX / 2 - maxX / 20, maxY / 4 - 1);
				printf("Game Over");
				GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 1);
				printf("Your score:%d", *Score);
				GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 3);
				printf("Your time:%lf", *Time);
				getchar();
				free(Score);
				free(Time);
			}
			else if (Y_Pos == maxY / 4 + 2) /*Records*/ {
				flag = 3;
			}
			else if (Y_Pos == maxY / 4 + 4) /*Map Editor*/ {
				flag = 4;
			}
			else if (Y_Pos == maxY / 4 + 6) /*Developers*/ {
				flag = 5;
			}
			else if (Y_Pos == maxY / 4 + 8) /*Exit*/ {
				flag = 1;
			}
		}
		SetColor(FOREGROUND_BLUE);
		GotoXY(maxX / 2 - maxX / 20 - 2, Y_Pos);
		printf("->");
		GotoXY(X_Pos, Y_Pos);
	}
}
