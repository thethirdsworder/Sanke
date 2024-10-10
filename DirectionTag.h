#pragma once

#define MapWIdth 41
#define MapHeight 28

enum Direction
{
	up,
	down,
	right,
	left
};

struct directionTagNode  //作为方向标记类链表的结点
{
	Direction directionTag; //记录方向
	//用于给方向标记类头节点记录未处理完的方向节点数，
	//以及给给方向节点计数已经处理的贪吃蛇节点数方便标记
	int counter = 0;        
	directionTagNode* nextTagNode;
};

class DirectionTag
{
public:
	DirectionTag();
	DirectionTag(const DirectionTag& copyDirectionTag);   //该类带有原始指针成员，应该实现复制构造函数
	~DirectionTag();
	
	void TagPush(Direction dire);
	static void TagPop(directionTagNode* head);
	directionTagNode* GetDirectionTagHeadNode();
	directionTagNode* GetDirectionTagLastNode();

private:
	directionTagNode* directionTagHeadNode;

	directionTagNode* lastDirectionTagNode;
};

