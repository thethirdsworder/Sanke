#pragma once
#include<cstdlib>
#include<ctime>
#define MapWIdth 41
#define MapHeight 28

enum PropType
{
	goodFruit,
	badFruit
};

typedef struct Prop
{
	int id;
	int postionX;
	int postionY;
	PropType  PropT;
	int effectValue;
	int duration;   //持续时间

};

class PropList
{
public:
	PropList();
	~PropList();

	int GetLength();
	PropNode GetHeadNode();

	void PropListAddNode();
	void ProPListDeleteNode(PropNode prePropNode);

	//随机道具数值初始化，返回道具结构体指针

	PropNode GetNewRandomProp();




private:
	PropNode PropListHeadNode;
	int length;    //记录地图上的道具个数
	
};