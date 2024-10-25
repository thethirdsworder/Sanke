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
	int duration;   //����ʱ��

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

	//���������ֵ��ʼ�������ص��߽ṹ��ָ��

	void GetNewRandomProp(Prop& swapValue);




private:
	vector<Prop> propPool;   
	
};