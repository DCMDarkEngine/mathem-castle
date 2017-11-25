//Функции для отрисовки интерфейса, движений, графики и т.п.

#include <iostream>;
#include <Windows.h>;
#include <string>;
#include "graphic.h";
#include <sstream>;

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Для сокращения длины кода введем следующее сокращение
typedef unsigned short int ushort;

//Функция переноса курсора к необходимым координатам
void gotoxy(ushort X1, ushort Y1)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = X1;
	coord.Y = Y1;
	SetConsoleCursorPosition(hCon, coord);
}

//Функция отрисовки прямоугольника, подогнанного под длину уравнение
void drawObject(string uravnenie, ushort X1, ushort Y1)
{
	//Выясняем длину уравнения для подгонки прямоугольника
	const ushort COLLUMN = uravnenie.size() + 4;
	//Выставляем ширину прямоугольника ( чтобы уравнение находилось строго по середине )
	const ushort LINE = 5;
	//Создаем динамический символьный массив, хранящий в себе символы вывода объекта на экран
	char **obj = new char*[LINE];
	for (ushort i = 0; i < LINE; i++)
	{
		obj[i] = new char[COLLUMN];
	}
	//Заполняем массив рамкой согласно длине нашего уравнения
	obj[0][0] = static_cast<char>(201);
	obj[0][COLLUMN - 1] = static_cast<char>(187);
	obj[LINE - 1][0] = static_cast<char>(200);
	obj[LINE - 1][COLLUMN - 1] = static_cast<char>(188);
	for (ushort i = 1; i < COLLUMN - 1; i++)
	{
		obj[0][i] = static_cast<char>(205);
		obj[LINE - 1][i] = static_cast<char>(205);
	}
	for (ushort i = 1; i < LINE - 1; i++)
	{
		obj[i][0] = static_cast<char>(186);
		obj[i][COLLUMN - 1] = static_cast<char>(186);
	}
	//Заполним внутренность прямоугольника пустыми символами для определенности
	for (ushort i = 1; i < LINE - 1; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			obj[i][j] = ' ';
		}
	}
	//Поместим уравнение внутрь прямоугольника
	ushort count = 0;
	for (ushort i = 2; i < COLLUMN - 2; i++)
	{
		obj[2][i] = uravnenie[count];
		count++;
	}
	//Смена цвета символов через WinApi
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 12));
	//Выводим готовый объект на экран по неоходимым координатам
	gotoxy(X1, Y1);
	for (ushort i = 0; i < LINE; i++)
	{
		for (ushort j = 0; j < COLLUMN; j++)
		{
			cout << obj[i][j];
		}
		Y1++;
		gotoxy(X1, Y1);
	}
	//Освобождаем память, занимаемую символьной матрицей
	for (ushort i = 0; i < LINE; i++)
	{
		delete[] obj[i];
	}
}

//Функция отрисовки башен со здоровьем внутри 
void drawTower(ushort X1, ushort Y1)
{
	const ushort LINE = 7;
	const ushort COLLUMN = 15;
	char tower[LINE][COLLUMN];
	//Заполнение контура башни
	tower[0][0] = static_cast<char>(201);
	tower[0][COLLUMN - 1] = static_cast<char>(187);
	tower[LINE - 1][0] = static_cast<char>(200);
	tower[LINE - 1][COLLUMN - 1] = static_cast<char>(188);
	for (ushort i = 1; i < COLLUMN - 1; i++)
	{
		tower[0][i] = static_cast<char>(205);
		tower[LINE - 1][i] = static_cast<char>(205);
	}
	for (ushort i = 1; i < LINE - 1; i++)
	{
		tower[i][0] = static_cast<char>(186);
		tower[i][COLLUMN - 1] = static_cast<char>(186);
	}
	//Заполнение внутренности матрицы пустыми символами для определенности
	for (ushort i = 1; i < LINE - 1; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			tower[i][j] = ' ';
		}
	}
	//Вставим показатель здоровья внутрь башни
	tower[LINE / 2][COLLUMN / 2 - 1] = '1';
	tower[LINE / 2][COLLUMN / 2] = '/';
	tower[LINE / 2][COLLUMN / 2 + 1] = '1';
	//Смена цвета символов на цвет башен ( синий )
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (WORD)((15 << 4) | 9));
	//Место, откуда будет отрисовываться башня
	gotoxy(X1, Y1);
	//Вывод башни на экран
	for (ushort i = 0; i <= LINE - 1; i++)
	{
		for (ushort j = 0; j <= COLLUMN - 1; j++)
		{
			cout << tower[i][j];
		}
		Y1++;
		gotoxy(X1, Y1);
	}
}

//Функция отрисовки ядра математики по данным координатам
//со здоровьем внутри посередине
void drawCore(ushort X1, ushort Y1, ushort hp)
{
	//Определяем размеры ядра
	const ushort COLLUMN = 25;
	const ushort LINE = 12;
	//Создаем матрицу, отождествляющую прямоугольник
	char yadro[LINE][COLLUMN];
	//Заполнение контура ядра
	yadro[0][0] = static_cast<char>(201);
	yadro[0][COLLUMN - 1] = static_cast<char>(187);
	yadro[LINE - 1][0] = static_cast<char>(200);
	yadro[LINE - 1][COLLUMN - 1] = static_cast<char>(188);

	for (ushort i = 1; i < COLLUMN - 1; i++)
	{
		yadro[0][i] = static_cast<char>(205);
		yadro[LINE - 1][i] = static_cast<char>(205);
	}

	for (ushort i = 1; i < LINE - 1; i++)
	{
		yadro[i][0] = static_cast<char>(186);
		yadro[i][COLLUMN - 1] = static_cast<char>(186);
	}

	//Заполняем внутренность ядра пустыми символами для определенности
	for (ushort i = 1; i < LINE - 1; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			yadro[i][j] = ' ';
		}
	}

	//Внесем внутрь ядря посередине состояние здоровья
	char hp_char[] = "10";		//Перевод числа здоровья
	yadro[LINE / 2][COLLUMN / 2 - 2] = hp_char[0];
	yadro[LINE / 2][COLLUMN / 2 - 1] = hp_char[1];
	yadro[LINE / 2][COLLUMN / 2] = '/';
	yadro[LINE / 2][COLLUMN / 2 + 1] = '1';
	yadro[LINE / 2][COLLUMN / 2 + 2] = '10';

	//Смена цвета символов на цвет ядра ( синий ) и белый фон
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (WORD)((15 << 4) | 9));
	//Выбираем место, откуда начнется рисоваться ядро
	gotoxy(X1, Y1);
	//Выводим на экран ядро
	for (ushort i = 0; i < LINE; i++)
	{
		for (ushort j = 0; j < COLLUMN; j++)
		{
			cout << yadro[i][j];
		}
		Y1++;
		gotoxy(X1, Y1);
	}
}

//Функция уничтожает(разбивает на две части) башню с поля битвы с номером number
void clearTower(ushort number)
{
	//Зададим размеры двух символьных матриц
	const ushort
		LINE_UP = 4,   //Ширина верхней половины башни
		LINE_DOWN = 3, //Ширина нижней половины башни
		COLLUMN = 15;  //Длина обеих половин
	//Две сивольные матрицы, отождествляющие верхнюю половину башни и нижнюю
	char up[LINE_UP][COLLUMN], down[LINE_DOWN][COLLUMN];
	//Заполним рамку углов и вертикальных линий верхней половинки
	up[0][0] = static_cast<char>(201);
	up[0][COLLUMN - 1] = static_cast<char>(187);
	for (ushort i = 1; i < LINE_UP; i++)
	{
		up[i][0] = static_cast<char>(186);
		up[i][COLLUMN - 1] = static_cast<char>(186);
	}
	//Заполним рамку углов и вертикальных линий нижней половинки
	down[LINE_DOWN - 1][0] = static_cast<char>(200);
	down[LINE_DOWN - 1][COLLUMN - 1] = static_cast<char>(188);
	for (ushort i = 0; i < LINE_DOWN - 1; i++)
	{
		down[0][i] = static_cast<char>(186);
		down[COLLUMN - 1][i] = static_cast<char>(186);
	}
	//Заполним рамку из горизонтальных линий у обеих половинок
	for (ushort i = 1; i < COLLUMN - 1; i++)
	{
		up[0][i] = static_cast<char>(205);
		down[LINE_DOWN - 1][i] = static_cast<char>(205);
	}
	//Заполним пустыми символами внутренности верхней и нижней половинки для определенности
	for (ushort i = 1; i < LINE_UP; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			up[i][j] = ' ';
		}
	}
	for (ushort i = 0; i < LINE_DOWN - 1; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			down[i][j] = ' ';
		}
	}
	//Изменим цвет символов на цвет башни(синий), а фон на белый
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (WORD)((15 << 4) | 9));
	//Зададим координаты, в соответствии с номером башни
	ushort xT=50, yT_Up = 6, yT_Down = yT_Up + 4;
	switch (number)
	{
	case 1:
		xT = 50;
		yT_Up = 6;
		yT_Down = yT_Up + 4;
		break;
	case 2:
		xT += 17;
		yT_Up = 6;
		yT_Down = yT_Up + 4;
		break; 
	}
	ushort distance = 0;	//Зададим переменную, равную расстоянию между половинками
	//Цикл разделения башни на две разлетающиеся части
	while (distance != 4)	
	{
		gotoxy(xT, yT_Up);
		ushort yT_Up_for = yT_Up;
		for (ushort i = 0; i < LINE_UP; i++)
		{
			for (ushort j = 0; j < COLLUMN; j++)
			{
				cout << up[i][j];
			}
			yT_Up_for++;
			gotoxy(xT, yT_Up_for);
		}
		gotoxy(xT, yT_Down);
		ushort yT_Down_for = yT_Down;
		for (ushort i = 0; i < LINE_DOWN; i++)
		{
			for (ushort j = 0; j < COLLUMN; j++)
			{
				cout << down[i][j];
			}
			yT_Down_for++;
			gotoxy(xT, yT_Down_for);
		}
		Sleep(100);
		for (ushort i = xT; i < xT + COLLUMN; i++)
		{
			gotoxy(i, yT_Up + 3);
			cout << ' ';
			gotoxy(i, yT_Down);
			cout << ' ';
		}
		yT_Up--;
		yT_Down++;
		distance++;
	}
}

//Функция уничтожает(разбивает на две части) объект с поля битвы
void clearObject(string uravnenie, ushort X1, ushort Y1)
{
	//Задаем размеры объекта (столбцы подгоняются под длину уравнения)
	const ushort 
		COLLUMN = uravnenie.size() + 4,
		LINE_UP = 3,
		LINE_DOWN = 2;
	//Создаем две символьные матрицы, содержащие в себе верхнюю часть объекта и нижнюю
	char **obj_up = new char* [LINE_UP];
	char **obj_down = new char*[LINE_DOWN];
	for (ushort i = 0; i < LINE_UP; i++)
	{
		obj_up[i] = new char[COLLUMN];
	}
	for (ushort i = 0; i < LINE_DOWN; i++)
	{
		obj_down[i] = new char[COLLUMN];
	}
}