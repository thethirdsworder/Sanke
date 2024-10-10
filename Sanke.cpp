// Sanke.cpp: 定义应用程序的入口点。
//
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include"Map.h"
#include "Sanke.h"

//void Key_Messege_Control(EntireSnake& newSnake,DirectionTag newDirectionTag);
//函数中读取键盘输入无法读取，应该需要使用多线程
void Double_Display(char** newMap, char** oldMap, int& mapFlag);


int main()
{
	Map newMap(MapWIdth, MapHeight);
	Map oldMap;
	EntireSnake newSnake;
	DirectionTag newDirectionTag;


	int message;    //记录键盘消息
	int mapFlag = 0;   //标记front-map和back-map，保证双缓冲显示时的替换
	int timeOne, timeTwo;




	//int test = 0;
	
	while (1)
	{
		
		if (_kbhit())
		{

			message = _getch();
			//cout << message << endl;
			//system("pause");
			switch (message)
			{
			case 65:
				if (newSnake.GetEntireSnake()[0].diect != Direction::left && newSnake.GetEntireSnake()[0].diect != Direction::right)
				{
					newDirectionTag.TagPush(Direction::left);
					break;
				}
				break;
			case 87:
				if (newSnake.GetEntireSnake()[0].diect != Direction::up && newSnake.GetEntireSnake()[0].diect != Direction::down)
				{
					newDirectionTag.TagPush(Direction::up);
					break;
				}
				break;
			case 68:
				if (newSnake.GetEntireSnake()[0].diect != Direction::left && newSnake.GetEntireSnake()[0].diect != Direction::right)
				{
					newDirectionTag.TagPush(Direction::right);
					break;
				}
				break;
			case 83:
				if (newSnake.GetEntireSnake()[0].diect != Direction::up && newSnake.GetEntireSnake()[0].diect != Direction::down)
				{
					newDirectionTag.TagPush(Direction::down);
					break;
				}
				break;
			default:
				break;
			}
		}
		//Key_Messege_Control(newSnake, newDirectionTag);
		
		newSnake.Snake_ChanegDirection(newDirectionTag.GetDirectionTagHeadNode());
		newSnake.Snake_Move();
		newMap.checkSnakeLife(newSnake.GetEntireSnake(), newSnake.GetLength());
		if (mapFlag == 0)
		{
			newMap.update_Map(&(newSnake.GetEntireSnake()[0]), newSnake.GetLength());
			//newMap.Display_Map();
			Double_Display(newMap.GetMap(), oldMap.GetMap(), mapFlag);
		}
		else if (mapFlag == 1)
		{
			oldMap.update_Map(&(newSnake.GetEntireSnake()[0]), newSnake.GetLength());
			//oldMap.Display_Map();
			Double_Display(newMap.GetMap(), oldMap.GetMap(), mapFlag);
		}
		
		Map::disaplay_Fps();
		Sleep(500);
	}
	return 0;
}

//void Key_Messege_Control(EntireSnake& newSnake,DirectionTag newDirectionTag)
//{
//	
//}
void Double_Display(char** newMap, char** oldMap,int &mapFlag)
{
	char** frontMap;
	char** backMap;
	if (mapFlag == 0)
	{
		frontMap = oldMap;
		backMap = newMap;
	}
	else if (mapFlag == 1)
	{
		frontMap = newMap;
		backMap = oldMap;
	}
	
	for (int j = 0; j < MapHeight; ++j)
	{
		for (int k = 0; k < MapWIdth; ++k)
		{
			if (backMap[j][k] != frontMap[j][k])
			{
				Map::SetXy(k, j);
				cout << backMap[j][k];
				frontMap[j][k] = backMap[j][k];
			}
		}
	}
	mapFlag = (mapFlag++) % 2;
}