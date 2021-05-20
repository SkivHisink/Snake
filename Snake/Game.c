#pragma once
#include "Conlib.h"
#include "Menu.h"
#include "Game.h"
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <wtypes.h>
#include <conio.h>
#include <stdbool.h>

//Difficults
#define EASY 100
#define NORMAL 50
#define HARD 35
#define GOOD 10
//
typedef struct Snake {
	int  x, y;
	struct Snake *next, *prev;
} Snake;
typedef struct Food {
	int x, y;
	bool condition;
} Food;
typedef struct gamestate {
	Snake *head, *tail;
	Food *food;
	int *maxX, *maxY;
	int col, row;
	int score;
} gamestate;
/*--------------------------------------------------------*/
void CreatePartSnake(gamestate *action) {
	Snake *add = (Snake*)malloc(sizeof(Snake));
	add->prev = action->tail;
	add->next = NULL;
	add->x = add->prev->x;
	add->y = add->prev->y;
	action->tail->next = add;
	action->tail = add;
	action->score = action->score + 1;
}
/*--------------------------------------------------------*/
void CreateFood(gamestate *action) {
	action->food->x = rand() % (*(action->maxX) - 1);
	action->food->y = rand() % (*(action->maxY) - 1);
	Snake *check = action->head;
	while (check != action->tail) {
		if ((action->food->x == check->x) && (action->food->y == check->y)) {
			CreateFood(action);
			break;
		}
		check = check->next;
	}
	action->food->condition = true;
}
/*--------------------------------------------------------*/
bool CrashTest(gamestate *action) {
	Snake *check = action->head->next;
	if (action->score > 4)
	{
		while (check != action->tail) {
			if ((action->head->x == check->x) && (action->head->y == check->y)) {
				return true;
			}
			check = check->next;
		}
	}
	return false;
}
/*--------------------------------------------------------*/
void CreateSnake(gamestate *action) {
	/*--------------------------------------------------------*/
	action->maxX = (int*)malloc(sizeof(int));
	action->maxY = (int*)malloc(sizeof(int));
	MaxXY(action->maxX, action->maxY);
	/*--------------------------------------------------------*/
	action->head = (Snake*)malloc(sizeof(Snake));
	action->head->next = NULL;
	action->head->prev = NULL;
	action->tail = action->head;
	/*--------------------------------------------------------*/
	action->food = (Food*)malloc(sizeof(Food));
	CreateFood(action);
	/*--------------------------------------------------------*/
	action->head->x = *(action->maxX) / 2;
	action->head->y = *(action->maxY) / 2;
	action->col = 0;
	action->row = 0;
	action->food->condition = false;
	action->score = 0;
	CreatePartSnake(action);
}
/*--------------------------------------------------------*/
void DeleteSnake(gamestate *action)
{
	free(action->maxX);
	free(action->maxY);
	free(action->food);
	Snake* for_del = action->tail;
	while(for_del!=NULL)
	{
		Snake* tmp = for_del->prev;
		free(for_del);
		for_del = tmp;
	}
}
/*--------------------------------------------------------*/
void Game(gamestate *action, int *move) {
	Snake *trace = action->tail;
	int FoodCord = 0;

	while (trace != action->head) {
		FoodCord = GotoXY(trace->x, trace->y);
		SetColor(BACKGROUND_BLACK);
		printf(" ");
		trace->x = trace->prev->x;
		trace->y = trace->prev->y;
		trace = trace->prev;
	}
	FoodCord = GotoXY(action->tail->x, action->tail->y);
	printf(" ");
	if (KeyPressed()== 1) {
		*move = GetKey();
	}
	int b = action->row;
	int c = action->col;
	switch (*move) {
	case KEY_LEFT: {
		action->row = -1; action->col = 0;
		break;
	}
	case KEY_RIGHT: {
		action->row = 1;
		action->col = 0;
		break;
	}
	case KEY_UP: {
		action->row = 0;
		action->col = -1;
		break;
	}
	case KEY_DOWN: {
		action->row = 0;
		action->col = 1;
		break;
	}
	}
	if (((action->row != b) && (action->col != c)) || ((c == 0) && (b == 0))) {}
	else {
		action->row = b;
		action->col = c;
	}
	action->head->x = action->head->x + action->row;
	action->head->y = action->head->y + action->col;
}
/*--------------------------------------------------------*/
void DrawGame(gamestate *action, int SC, int FC) {
	SetColor(SC);
	int FoodCord;
	if (action->head->x == *(action->maxX)) {
		action->head->x = 0;
	}
	if (action->head->y == *(action->maxY)) {
		action->head->y = 0;
	}
	if (action->head->x == -1) {
		action->head->x = *(action->maxX);
	}
	if (action->head->y == -1) {
		action->head->y = *(action->maxY);
	}
	Snake *draw = action->head;
	if (action->score == 0) {
		FoodCord = GotoXY((draw->x), (draw->y));
		printf(" ");
	}
	else {
		while (draw != action->tail) {
			FoodCord = GotoXY((draw->x), (draw->y));
			printf(" ");
			draw = draw->next;
		}
	}
	FoodCord = GotoXY((action->food->x), (action->food->y));
	SetColor(FC);
	printf(" ");
	SetColor(BACKGROUND_BLACK);
}
/*--------------------------------------------------------*/
void WindowConfig() {
	ClearConsole();
	/*Other configs has been deleted*/
}
/*--------------------------------------------------------*/
int *score;
double *t_time;
/*--------------------------------------------------------*/
void GameP(int SC, int FC) {
	score = (int*)malloc(sizeof(int));
	t_time = (double*)malloc(sizeof(double));
	WindowConfig();
	srand(time(NULL));
	int *move = (int*)malloc(sizeof(int));
	*move = KEY_UP;
	gamestate *action = (gamestate*)malloc(sizeof(gamestate));
	int FoodCord = ConShowCursor(0);
	CreateSnake(action);
	clock_t start, stop;
	start = clock();
	while (!CrashTest(action)) {
		MaxXY(action->maxX, action->maxY);
		Game(action, move);
		if ((action->food->x == action->head->x) && (action->food->y == action->head->y)) {
			CreatePartSnake(action);
			FoodCord = GotoXY(action->food->x, action->food->y);
			printf(" ");
			CreateFood(action);
		}
		DrawGame(action, SC, FC);
		Sleep(50);
	}
	stop = clock();
	ClearConsole();
	*score = action->score;
	*t_time = (stop - start) / CLK_TCK;
	DeleteSnake(action);
	free(action);
}
/*--------------------------------------------------------*/
int *ReturnScore() {
	return score;
}
/*--------------------------------------------------------*/
double *ReturnTime() {
	return t_time;
}
/*--------------------------------------------------------*/