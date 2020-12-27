#include "GameMenu.h"
#include "Conlib.h"
#include "Menu.h"
#include <stdio.h>
#include <malloc.h>

int main() {
	int flag, exit = 0;
	int maxX = 0, maxY = 0;
	char Name[25] = "Player";
	while (!exit) {
		ClearConsole();
		flag = 0;
		flag = Menu(*&maxX, *&maxY);
		switch (flag) {
		case 1: {
			exit = ExitGame(*&maxX, *&maxY);
			flag = 2;
			break;
		}
		case 2: {
			int *Score = (int*)malloc(sizeof(int));
			Score = NULL;
			double *Time = (double*)malloc(sizeof(double));
			Time = NULL;
			GameMenu(*&maxX, *&maxY, Score, Name, Time);
			//WriteRecord(Score, Time);
			//
			break;
		}
		case 3: {
			ClearConsole();
			GotoXY(maxX / 2 - maxX / 8, maxY / 4);
			printf("Records");
			getchar();
			break;
		}
		case 4: {
			ClearConsole();
			GotoXY(maxX / 2 - maxX / 8, maxY / 4);
			printf("Map Editor");
			getchar();
			break;
		}
		case 5: {
			ClearConsole();
			GotoXY(maxX / 2 - maxX / 8, maxY / 4);
			printf("Developers");
			getchar();
			break;
		}
		default:
			break;
		}
	}
	return 0;
}