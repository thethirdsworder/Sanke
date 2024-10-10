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
	void Snake_Move();  //���нڵ��ƶ�һ��
	int GetLength();
	vector<SnakeNode> GetEntireSnake();

	void AddSnakeNode(int num);    //����������
	void DeleteSnakeNode(int num);  //����������
	void ChangeSpeed(int sp);       //�������ٶ�

	bool SniffWall(const SnakeNode& tail);   //β�������Ƿ�Ӵ�ǽ
	bool SniffBody(const SnakeNode& tail);  //β�������Ƿ�Ӵ��Լ�
	Direction TailSafe();

private:
	SnakeNode headNode;
	vector<SnakeNode> bodyNodeList;
	int length;
	int speed;
};

