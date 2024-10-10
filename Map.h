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
	void initial_Map();									     //��ʼ����ͼ
	void update_Map(SnakeNode* snakeNodeList,int length);    //���µ�ͼ��Ϣ
	void static disaplay_Fps();
	void Display_Map();										//����Ļ�������
	void checkSnakeLife(vector<SnakeNode> head,int snakeLength);  //ÿ����ʾ�ƶ�ǰ�ж��Ƿ�̰���߻����


	void static SetXy(int x, int y); //����win32api���ù��λ��
	char** GetMap() { return this->map_content; }

private:
	int width = 0;
	int height = 0;
	static int fps;
	char **map_content;
};

