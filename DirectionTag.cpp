#include "DirectionTag.h"


DirectionTag::DirectionTag()
{
	//��ʼ��ָ���һ������ͷָ�뼰��ָ��Ľ��
	this->directionTagHeadNode = new directionTagNode;
	this->directionTagHeadNode->counter = 0;
	this->directionTagHeadNode->nextTagNode = nullptr;
	//��ʼ��ָ�����һ������βָ�룬��ʱ�޽��
	this->lastDirectionTagNode = new directionTagNode;
	this->lastDirectionTagNode->counter = this->directionTagHeadNode->counter;
	this->lastDirectionTagNode->directionTag = this->directionTagHeadNode->directionTag;
	this->lastDirectionTagNode->nextTagNode = this->directionTagHeadNode->nextTagNode;
}

DirectionTag::DirectionTag(const DirectionTag& copyDirectionTag)
{
	this->directionTagHeadNode = nullptr;
	this->lastDirectionTagNode = nullptr;
	if (copyDirectionTag.directionTagHeadNode != nullptr)
	{
		//��ʼ��ָ���һ������ͷָ�뼰��ָ��Ľ��
		this->directionTagHeadNode = new directionTagNode;
		this->directionTagHeadNode->counter = 0;
		this->directionTagHeadNode->nextTagNode = copyDirectionTag.directionTagHeadNode->nextTagNode;
		this->directionTagHeadNode->directionTag = copyDirectionTag.directionTagHeadNode->directionTag;
		//��ʼ��ָ�����һ������βָ�룬��ʱ�޽��
		this->lastDirectionTagNode = new directionTagNode;
		this->lastDirectionTagNode->counter = copyDirectionTag.lastDirectionTagNode->counter;
		this->lastDirectionTagNode->directionTag = copyDirectionTag.lastDirectionTagNode->directionTag;
		this->lastDirectionTagNode->nextTagNode = copyDirectionTag.lastDirectionTagNode->nextTagNode;
	}
	
	directionTagNode* index = copyDirectionTag.directionTagHeadNode->nextTagNode;
	
	for (int i = 0; i<copyDirectionTag.directionTagHeadNode->counter; ++i)
	{
		directionTagNode* newDirectionTagNode = new directionTagNode;
		newDirectionTagNode->counter = 0;
		newDirectionTagNode->nextTagNode = nullptr;
		newDirectionTagNode->directionTag = index->directionTag;
		if (this->directionTagHeadNode->counter == 0)
		{
			this->directionTagHeadNode->nextTagNode = newDirectionTagNode;
			this->lastDirectionTagNode->nextTagNode = newDirectionTagNode;
			this->directionTagHeadNode->counter++;
		}
		else
		{
			this->lastDirectionTagNode->nextTagNode->nextTagNode = newDirectionTagNode;
			this->lastDirectionTagNode->nextTagNode = newDirectionTagNode;
		}
		index = index->nextTagNode;
	}
}

DirectionTag::~DirectionTag()
{
	directionTagNode* p = this->directionTagHeadNode->nextTagNode;
	directionTagNode* index;
	while (p != nullptr)
	{
		index = p->nextTagNode;
		delete p;
		p = index;
	}
	delete this->directionTagHeadNode;
	delete this->lastDirectionTagNode;
}

void DirectionTag::TagPush(Direction dire)
{
	directionTagNode* newDirectionTagNode = new directionTagNode;
	newDirectionTagNode->counter = 0;
	newDirectionTagNode->nextTagNode = nullptr;
	newDirectionTagNode->directionTag = dire;
	if (this->directionTagHeadNode->counter == 0)
	{
		this->directionTagHeadNode->nextTagNode = newDirectionTagNode;
		this->lastDirectionTagNode->nextTagNode = newDirectionTagNode;
	}
	else
	{
		this->lastDirectionTagNode->nextTagNode->nextTagNode = newDirectionTagNode;
		this->lastDirectionTagNode->nextTagNode = newDirectionTagNode;
	}
	this->directionTagHeadNode->counter++;
	
}

void DirectionTag::TagPop(directionTagNode* head)
{
	directionTagNode* p = head->nextTagNode;
	head->nextTagNode = p->nextTagNode;
	delete p;
	//head->counter--;
}

directionTagNode* DirectionTag::GetDirectionTagHeadNode()
{
	return this->directionTagHeadNode;
}

directionTagNode* DirectionTag::GetDirectionTagLastNode()
{
	return this->lastDirectionTagNode;
}
