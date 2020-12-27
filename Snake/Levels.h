#pragma once
//void ff()
//{
//	while (!bExit)
//	{
//		for (int i = 0; i < maxX / 2; i++)
//		{
//			for (int j = 0; j < maxY; j++)
//			{
//				if (((i == 0) || (j == 0)) || ((i == maxX / 2 - 1) || (j == maxY - 1)))
//				{
//					GotoXY(i, j);
//					SetColor(BACKGROUND_GREEN | FOREGROUND_RED);
//					printf(" ");
//				}
//			}
//
//		}
//		key = GetKey();
//
//		if (key == KEY_ESC)
//			bExit = 1;
//		else if (key == KEY_UP)
//			Y_Pos--;
//
//		else if (key == KEY_DOWN)
//			Y_Pos++;
//		else if (key == KEY_LEFT)
//			X_Pos--;
//		else if (key == KEY_RIGHT)
//			X_Pos++;
//
//
//		ClearConsole();
//		GotoXY(X_Pos, Y_Pos);
//		printf("Y");
//	}
//}