#include <iostream>;
#include <Windows.h>;
#include <string>;
#include "graphic.h";

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef unsigned int short ushort;

void main(void)
{	
	const ushort 
		//Объявляем Х-координаты башен и ядра
		xT1 = 50, 
		xT2 = xT1 + 17, 
		xM = xT2 + 20,
		//Объявляем Y-координаты башен и ядра
		yT = 6,
		yM = 3;
		
	ushort xObj = 1;			//Объявляем переменную X-координаты объекта
	const ushort yObj = 7;		//Объявляем константу Y-координаты объекта
	
	system("color F0");			//Изменяем цвет фона на белый, цвет символов на черный
	
	string task = "x^2+4x+4=0"; //Пример задачи
	
	//Готовим поле битвы
	drawTower(xT1 ,yT);			
	drawTower(xT2, yT);
	drawCore(xM, yM, 10);

	ushort xEndObj = xObj + task.size() + 3;
	//Движения объекта к первой башне
	while (xEndObj != xT1)
	{
		drawObject(task, xObj, yObj);
		Sleep(150);
		for (ushort i = yObj; i <= yObj + 5; i++)
		{
			gotoxy(xObj, i);
			cout << ' ';
		}
		xObj++;
		xEndObj = xObj + task.size() + 3;
	}
	clearTower(1);
	drawObject(task, xObj, yObj);
	cin.get();
}