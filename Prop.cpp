#include"Prop.h"

PropList::PropList()
{

}

PropList::~PropList()
{

}

int PropList::GetLength()
{
	return this->propPool.size();
}

vector<Prop>::iterator PropList::GetHeadNode()
{
	return this->propPool.begin();
}

void PropList::PropListAddNode()
{
	Prop newProp;
	this->GetNewRandomProp(newProp);
	
	this->propPool.push_back(newProp);
}

void PropList::PropListDeleteNode(vector<Prop>::iterator targetNode)
{
	auto scanItr = this->propPool.erase(targetNode);
	for (; scanItr != this->propPool.end(); ++scanItr)
	{
		(*scanItr).id--;
	}
}

void PropList::GetNewRandomProp(Prop& swapValue)
{
	srand(time(0));
	Prop newOne;

	//���λ��
	newOne.postionX = (rand() - 0) % MapHeight;
	newOne.postionY = (rand() - 0) % MapWIdth;

	//���Ч������
	switch ((rand() - 1) % 2)
	{
	case 0:
		newOne.PropT = goodFruit;
		break;
	case 1:
		newOne.PropT = badFruit;
		break;
	default:
		break;
	}

	//���Ч��ֵ
	newOne.effectValue = 1;

	//�������ʱ��
	newOne.duration = 10;

	//��ֵid
	newOne.id = this->propPool.size();

	//������prop
	this->propPool.push_back(newOne);
}
