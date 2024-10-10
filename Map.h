#pragma once
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include"EntireSnake.h"
#include"Prop.h"
using namespace std;

class Map
{
public:

	Map();
	~Map();

	Map(int width, int height);
	void initial_Map();									     //初始化地图
	void update_Map(SnakeNode* snakeNodeList,int length);    //更新地图信息
	void static disaplay_Fps();
	void Display_Map();										//向屏幕输出画面
	void checkSnakeLife(vector<SnakeNode> head,int snakeLength);  //每次显示移动前判断是否贪吃蛇还存活


	void static SetXy(int x, int y); //调用win32api设置光标位置
	char** GetMap() { return this->map_content; }

private:
	int width = 0;
	int height = 0;
	static int fps;
	char **map_content;
};

