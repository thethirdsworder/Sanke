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
	int duration;   //����ʱ��

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

	//���������ֵ��ʼ�������ص��߽ṹ��ָ��

	PropNode GetNewRandomProp();




private:
	PropNode PropListHeadNode;
	int length;    //��¼��ͼ�ϵĵ��߸���
	
};