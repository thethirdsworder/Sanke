#include"Prop.h"

PropList::PropList()
{
	this->PropListHeadNode = NULL;
	//this->PropListHeadNode->nextPropNode = NULL;
	this->length = 0;
}

PropList::~PropList()
{

}

int PropList::GetLength()
{
	return this->length;
}

PropNode PropList::GetHeadNode()
{
	return this->PropListHeadNode;
}

void PropList::PropListAddNode()
{
	PropNode newNode= this->GetNewRandomProp();
	
	if (this->length == 0)
	{
		this->PropListHeadNode = newNode;
		this->PropListHeadNode->nextPropNode = NULL;
	}
	else
	{
		newNode->nextPropNode = this->PropListHeadNode;
		this->PropListHeadNode = newNode;
	}
	this->length++;
}

void PropList::ProPListDeleteNode(PropNode prePropNode)
{
	PropNode temp = prePropNode->nextPropNode;
	prePropNode->nextPropNode = temp->nextPropNode;
	delete temp;
}

PropNode PropList::GetNewRandomProp()
{
	srand(time(0));
	PropNode newProp = new Prop;
	newProp->nextPropNode = NULL;

	//���λ��
	newProp->postionX = (rand() - 0) % MapHeight;
	newProp->postionY = (rand() - 0) % MapWIdth;

	//���Ч������
	switch ((rand() - 1) % 2)
	{
	case 0:
		newProp->PropT = goodFruit;
		break;
	case 1:
		newProp->PropT = badFruit;
		break;
	default:
		break;
	}

	//���Ч��ֵ
	newProp->effectValue = 1;

	//�������ʱ��

	return newProp;
}
