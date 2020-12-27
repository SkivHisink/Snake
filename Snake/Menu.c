#include "Conlib.h"
#include "Menu.h"
#include <stdio.h>

int Menu(int maxX, int maxY) {
	int X_Pos = 1, Y_Pos = 1; // Can be changed
	int maxXS, maxYS; // reference  
	int key;
	int flag = 0; /*1-exit, 2-game, 3-records, 4-map editor, 5-developers*/
	MaxXY(&maxX, &maxY);
	maxXS = maxX;
	maxYS = maxY;
	Y_Pos = maxY / 4;
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
		printf("Menu");
		SetColor(FOREGROUND_RED);
		GotoXY(maxX / 2 - maxX / 20, maxY / 4);
		printf("Play");
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 2);
		printf("Records");
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 4);
		printf("Map Editor");
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 6);
		printf("Developers");
		GotoXY(maxX / 2 - maxX / 20, maxY / 4 + 8);
		printf("Exit");

		key = GetKey();

		SetColor(0x0000 | 0x0000);
		if (key == KEY_ESC) {
			flag = 1;
		}
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
		if (key == KEY_ENTER) {
			if (Y_Pos == maxY / 4) /*Game*/ {
				flag = 2;
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
	return flag;
}
int ExitGame(int maxX, int maxY) {
	ClearConsole();
	int exit = 0;
	int X_Pos = 1, Y_Pos = 1; // Can be changed
	int maxXS, maxYS; // reference  
	int key;
	int flag = 0;
	MaxXY(&maxX, &maxY);
	maxXS = maxX;
	maxYS = maxY;
	X_Pos = maxX / 2 - 3;
	GotoXY(maxX / 2 - 3, maxY / 4 + 1);
	SetColor(BACKGROUND_RED | FOREGROUND_BLUE);
	printf("Yes");
	SetColor(0x0000 | 0x0001);
	GotoXY(maxX / 2 + 3, maxY / 4 + 1);
	printf("No");
	while (!flag) {
		MaxXY(&maxX, &maxY);
		if (maxXS != maxX || maxYS != maxY) {
			maxXS = maxX;
			maxYS = maxY;
			ClearConsole();
			X_Pos = maxX / 2 - 3;
			ConShowCursor(0);
			GotoXY(maxX / 2 - 3, maxY / 4 + 1);
			printf("Yes");
			SetColor(0x0000 | 0x0001);
			GotoXY(maxX / 2 + 3, maxY / 4 + 1);
			printf("No");
		}
		frame(maxX, maxY, FOREGROUND_RED);
		SetColor(0x0000 | FOREGROUND_RED);
		GotoXY(maxX / 2 - maxX / 8, maxY / 4);
		printf("Are you sure want to exit?");

		key = GetKey();

		if ((key == KEY_LEFT) && (X_Pos == maxX / 2 - 3)) {
			X_Pos = maxX / 2 + 3;
			SetColor(0x0000 | FOREGROUND_BLUE);
			GotoXY(maxX / 2 + 3, maxY / 4 + 1);
			printf("No");
			SetColor(BACKGROUND_RED | 0x0001);
			GotoXY(maxX / 2 - 3, maxY / 4 + 1);
			printf("Yes");
		}
		else if (key == KEY_LEFT) {
			X_Pos = maxX / 2 - 3;
			SetColor(BACKGROUND_RED | FOREGROUND_BLUE);
			GotoXY(maxX / 2 - 3, maxY / 4 + 1);
			printf("Yes");
			SetColor(0x0000 | 0x0001);
			GotoXY(maxX / 2 + 3, maxY / 4 + 1);
			printf("No");
		}
		if ((key == KEY_RIGHT) && (X_Pos == maxX / 2 + 3)) {
			X_Pos = maxX / 2 - 3;
			SetColor(BACKGROUND_RED | FOREGROUND_BLUE);
			GotoXY(maxX / 2 - 3, maxY / 4 + 1);
			printf("Yes");
			SetColor(0x0000 | 0x0001);
			GotoXY(maxX / 2 + 3, maxY / 4 + 1);
			printf("No");
		}
		else if (key == KEY_RIGHT) {
			X_Pos = maxX / 2 + 3;
			SetColor(0x0000 | FOREGROUND_BLUE);
			GotoXY(maxX / 2 + 3, maxY / 4 + 1);
			printf("No");
			SetColor(BACKGROUND_RED | 0x0001);
			GotoXY(maxX / 2 - 3, maxY / 4 + 1);
			printf("Yes");
		}
		if (key == KEY_ENTER) {
			if (X_Pos == maxX / 2 - 3) /*Yes*/ {
				exit = 1;
				flag = 1;
			}
			else if (X_Pos == maxX / 2 + 3) /*No*/ {
				flag = 2;
			}
		}
	}
	return exit;
}