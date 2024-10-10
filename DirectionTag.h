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

struct directionTagNode  //��Ϊ������������Ľ��
{
	Direction directionTag; //��¼����
	//���ڸ���������ͷ�ڵ��¼δ������ķ���ڵ�����
	//�Լ���������ڵ�����Ѿ������̰���߽ڵ���������
	int counter = 0;        
	directionTagNode* nextTagNode;
};

class DirectionTag
{
public:
	DirectionTag();
	DirectionTag(const DirectionTag& copyDirectionTag);   //�������ԭʼָ���Ա��Ӧ��ʵ�ָ��ƹ��캯��
	~DirectionTag();
	
	void TagPush(Direction dire);
	static void TagPop(directionTagNode* head);
	directionTagNode* GetDirectionTagHeadNode();
	directionTagNode* GetDirectionTagLastNode();

private:
	directionTagNode* directionTagHeadNode;

	directionTagNode* lastDirectionTagNode;
};

