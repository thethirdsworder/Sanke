#include"EntireSnake.h"


void EntireSnake::Snake_ChanegDirection(directionTagNode* head)
{

	directionTagNode* p = head->nextTagNode;
	bool flag = 0;
	for (int i = 0; i < head->counter; ++i)
	{
		if (p->counter >= (this->length))
		{
			DirectionTag::TagPop(head);
			flag = 1;
			p = head->nextTagNode;
			continue;
		}
		else if(p->counter>=0)
		{
			this->bodyNodeList[p->counter].diect = p->directionTag;
			p->counter++;
			p = p->nextTagNode;
		}
		
	}
	if (flag)
	{
		head->counter--;
	}

}

EntireSnake::EntireSnake()
{
	//初始化蛇头结点
	this->length = 6;
	this->headNode.x = 1;
	this->headNode.y = this->length;
	this->headNode.diect = Direction::right;
	this->speed = 1;
	bodyNodeList.push_back(headNode);

	//初始化蛇身结点
	SnakeNode temp;
	for (int i = 1; i < length; i++)
	{
		temp.x = bodyNodeList[i - 1].x;
		temp.y = bodyNodeList[i - 1].y - 1;
		temp.diect = bodyNodeList[i - 1].diect;
		this->bodyNodeList.push_back(temp);
	}
}

EntireSnake::~EntireSnake()
{
}





void EntireSnake::Snake_Move()
{
	for (int i = 0; i < length; ++i)
	{
		switch (this->bodyNodeList[i].diect)
		{
		case 0:
			this->bodyNodeList[i].x -= this->speed;
			break;
		case 1:
			this->bodyNodeList[i].x += this->speed;
			break;
		case 2:
			this->bodyNodeList[i].y += this->speed;
			break;
		case 3:
			this->bodyNodeList[i].y -= this->speed;
			break;
		default:
			break;
		}
	}
}

int EntireSnake::GetLength()
{
	return this->length;
}

void EntireSnake::AddSnakeNode(int num)
{
	
}

void EntireSnake::DeleteSnakeNode(int num)
{
}

void EntireSnake::ChangeSpeed(int sp)
{
	this->speed = sp;
}

bool EntireSnake::SniffWall(const SnakeNode& tail)
{
	switch (tail.diect)
	{
	case 0:
		if (tail.x + 1 < MapHeight - 1)   //尾巴向上移动，增殖块默认向下生长
		{
			return true;
		}
		
		break;
	case 1:
		if (tail.x - 1 > 0)  //尾巴向下移动，增殖块默认向上生长
		{
			return true;
		}
		
		break;
	case 2:
		if (tail.y - 1 < MapWIdth - 1)  //尾巴向右移动，增殖块默认向左生长
		{
			return true;
		}
		
		break;
	case 3:
		if (tail.y + 1 > 0)   //尾巴向左移动，增殖块默认向右生长
		{
			return true;
		}
		
		break;
	default:
		return false;
		break;
	}
}

bool EntireSnake::SniffBody(const SnakeNode& tail)
{
	switch (tail.diect)
	{
	case 0:
		for (auto itr = this->bodyNodeList.begin(); itr != this->bodyNodeList.end(); ++itr)
		{
			if (((*itr).x == tail.x + 1) && ((*itr).y == tail.y))
				return false;
		}
		break;
	case 1:
		for (auto itr = this->bodyNodeList.begin(); itr != this->bodyNodeList.end(); ++itr)
		{
			if (((*itr).x == tail.x - 1) && ((*itr).y == tail.y))
			
				return false;
		}
		break;
	case 2:
		for (auto itr = this->bodyNodeList.begin(); itr != this->bodyNodeList.end(); ++itr)
		{
			if (((*itr).x == tail.x) && ((*itr).y == tail.y - 1))
				return false;
		}
		break;
	case 3:
		for (auto itr = this->bodyNodeList.begin(); itr != this->bodyNodeList.end(); ++itr)
		{
			if (((*itr).x == tail.x) && ((*itr).y == tail.y + 1))
			
				return false;
		}
		break;
	default:
		return false;
		break;
	}
	return true;
}


Direction EntireSnake::TailSafe()
{

}


vector <SnakeNode> EntireSnake::GetEntireSnake()
{
	return this->bodyNodeList;
}



