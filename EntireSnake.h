#pragma once

#include<iostream>
#include<vector>
#include"DirectionTag.h"
using namespace std;
#define MaxLength 20




struct SnakeNode
{
	int x, y;
	Direction diect;
};

class EntireSnake
{
public:
	EntireSnake();
	~EntireSnake();
	void Snake_ChanegDirection(directionTagNode* head);
	void Snake_Move();  //所有节点移动一次
	int GetLength();
	vector<SnakeNode> GetEntireSnake();

	void AddSnakeNode(int num);    //增加蛇身长度
	void DeleteSnakeNode(int num);  //减少蛇身长度
	void ChangeSpeed(int sp);       //设置蛇速度

	bool SniffWall(const SnakeNode& tail);   //尾巴拉长是否接触墙
	bool SniffBody(const SnakeNode& tail);  //尾巴拉长是否接触自己
	Direction TailSafe();

private:
	SnakeNode headNode;
	vector<SnakeNode> bodyNodeList;
	int length;
	int speed;
};

