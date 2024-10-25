#pragma once
#include<cstdlib>
#include<ctime>
#include<vector>
#define MapWIdth 41
#define MapHeight 28
using namespace std;

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
	vector<Prop>::iterator GetHeadNode();

	void PropListAddNode();
	void PropListDeleteNode(vector<Prop>::iterator targetNode);

	//随机道具数值初始化，返回道具结构体指针

	void GetNewRandomProp(Prop& swapValue);




private:
	vector<Prop> propPool;   
	
};