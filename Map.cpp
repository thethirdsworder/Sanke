#include"Map.h"

int Map::fps = 0;

Map::Map()
{
	this->height = MapHeight;
	this->width = MapWIdth;
	this->map_content = new char* [this->height];
	for (int i = 0; i < this->height; ++i)
	{
		this->map_content[i] = new char[width];
	}
	/*for (int j = 0; j < MapHeight; ++j)
	{
		for (int k = 0; k < MapWIdth; ++k)
		{
			this->map_content[j][k] = 0;
		}
	}*/
	//cout << "default" << endl;
	//this->map_content = { 0 };
}

Map::~Map()
{
	for (int i = 0; i < this->height; ++i)
	{
		delete[]this->map_content[i];

	}
	delete[]this->map_content;
}

Map::Map(int width, int height)
{
	//cout << "diff" << endl;
	this->height = height;
	this->width = width;
	initial_Map();

}

void Map::initial_Map()
{
	//为地图数组申请内存空间
	//如果用vector向量该输入写？？？？？？？？？
	this->map_content = new char* [this->height];
	for (int i = 0; i < this->height; ++i)
	{
		this->map_content[i] = new char[width];
	}

	//初始化地图边界，以#作为墙面的显示
	//初始化上面的墙
	for (int i = 0; i < this->width; ++i)
	{
		this->map_content[0][i] = '#';
	}
	//初始化左面的墙
	for (int i = 1; i < this->height; i++)
	{
		this->map_content[i][0] = '#';
	}
	//初始换右面的墙
	for (int i = 1; i < this->height; ++i)
	{
		this->map_content[i][this->width - 1] = '#';
	}
	//初始换底面的墙
	for (int i = 1; i < this->width - 1; ++i)
	{
		this->map_content[this->height - 1][i] = '#';
	}

	//掏空墙内部
	{
		for (int j = 1; j < this->height - 1; ++j)
		{
			for (int k = 1; k < this->width - 1; ++k)
			{
				this->map_content[j][k] = ' ';
			}
		}
	}
}

void Map::update_Map(SnakeNode* SnakeNodeList, int length)
{
	
	for (int i = 1; i < length; ++i)
	{
		this->map_content[SnakeNodeList[i].x][SnakeNodeList[i].y] = '*';
	}

	switch (SnakeNodeList[length - 1].diect)
	{
		//尾巴向上移动时扫除下方痕迹
	case 0:
		if ((SnakeNodeList[length - 1].x + 1) != this->height)
		{
			this->map_content[SnakeNodeList[length - 1].x+1][SnakeNodeList[length - 1].y] = ' ';
			
		}
		break;
		//尾巴向下移动时扫除上方痕迹
	case 1:
		if ((SnakeNodeList[length - 1].x - 1) != 0)
		{
			this->map_content[SnakeNodeList[length - 1].x-1][SnakeNodeList[length - 1].y] = ' ';
			
		}
		break;
		//尾巴向右移动时扫除左方痕迹
	case 2:
		if ((SnakeNodeList[length - 1].y - 1) != 0)
		{
			this->map_content[SnakeNodeList[length - 1].x][SnakeNodeList[length - 1].y-1] = ' ';
			
		}
		break;
		//尾巴向左移动时扫除右方痕迹
	case 3:
		if ((SnakeNodeList[length - 1].y + 1) != this->width)
		{
			this->map_content[SnakeNodeList[length - 1].x][SnakeNodeList[length - 1].y+1] = ' ';
			
		}
		break;
	default:
		break;
	}
	this->map_content[SnakeNodeList[0].x][SnakeNodeList[0].y] = 'o';
}

void Map::disaplay_Fps()
{
	Map::SetXy(0, 0);
	Map::fps++;
	cout << "FPS: " << Map::fps << endl;
}

void Map::Display_Map()
{
	//清空控制台输出
	system("cls");
	//遍历墙二维数组
	for (int j = 0; j < this->height; ++j)
	{
		for (int k = 0; k < this->width; ++k)
		{
			cout << this->map_content[j][k];
		}
		cout << endl;
	}
}

void Map::checkSnakeLife(vector<SnakeNode> head,int snakeLength)
{
	int x = head[0].x;
	int y = head[0].y;
	if (x == 0 || x == MapHeight-1 || y == 0 || y == MapWIdth-1)
	{
		cout << "You are died" << endl;
		system("pause");
		
	}
	for (int i = 4; i < snakeLength; ++i)
	{
		if (head[i].x == x && head[i].y == y)
		{
			cout << "You are died" << endl;
			system("pause");
			
		}
	}
}

void Map::SetXy(int x, int y)
{
	COORD position = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	//cout << this.fps << endl;
}
