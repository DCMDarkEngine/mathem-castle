//������� ��� ��������� ����������, ��������, ������� � �.�.

#include <iostream>;
#include <Windows.h>;
#include <string>;
#include "graphic.h";
#include <sstream>;

using std::cin;
using std::cout;
using std::endl;
using std::string;

//��� ���������� ����� ���� ������ ��������� ����������
typedef unsigned short int ushort;

//������� �������� ������� � ����������� �����������
void gotoxy(ushort X1, ushort Y1)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = X1;
	coord.Y = Y1;
	SetConsoleCursorPosition(hCon, coord);
}

//������� ��������� ��������������, ������������ ��� ����� ���������
void drawObject(string uravnenie, ushort X1, ushort Y1)
{
	//�������� ����� ��������� ��� �������� ��������������
	const ushort COLLUMN = uravnenie.size() + 4;
	//���������� ������ �������������� ( ����� ��������� ���������� ������ �� �������� )
	const ushort LINE = 5;
	//������� ������������ ���������� ������, �������� � ���� ������� ������ ������� �� �����
	char **obj = new char*[LINE];
	for (ushort i = 0; i < LINE; i++)
	{
		obj[i] = new char[COLLUMN];
	}
	//��������� ������ ������ �������� ����� ������ ���������
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
	//�������� ������������ �������������� ������� ��������� ��� ��������������
	for (ushort i = 1; i < LINE - 1; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			obj[i][j] = ' ';
		}
	}
	//�������� ��������� ������ ��������������
	ushort count = 0;
	for (ushort i = 2; i < COLLUMN - 2; i++)
	{
		obj[2][i] = uravnenie[count];
		count++;
	}
	//����� ����� �������� ����� WinApi
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 12));
	//������� ������� ������ �� ����� �� ���������� �����������
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
	//����������� ������, ���������� ���������� ��������
	for (ushort i = 0; i < LINE; i++)
	{
		delete[] obj[i];
	}
}

//������� ��������� ����� �� ��������� ������ 
void drawTower(ushort X1, ushort Y1)
{
	const ushort LINE = 7;
	const ushort COLLUMN = 15;
	char tower[LINE][COLLUMN];
	//���������� ������� �����
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
	//���������� ������������ ������� ������� ��������� ��� ��������������
	for (ushort i = 1; i < LINE - 1; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			tower[i][j] = ' ';
		}
	}
	//������� ���������� �������� ������ �����
	tower[LINE / 2][COLLUMN / 2 - 1] = '1';
	tower[LINE / 2][COLLUMN / 2] = '/';
	tower[LINE / 2][COLLUMN / 2 + 1] = '1';
	//����� ����� �������� �� ���� ����� ( ����� )
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (WORD)((15 << 4) | 9));
	//�����, ������ ����� �������������� �����
	gotoxy(X1, Y1);
	//����� ����� �� �����
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

//������� ��������� ���� ���������� �� ������ �����������
//�� ��������� ������ ����������
void drawCore(ushort X1, ushort Y1, ushort hp)
{
	//���������� ������� ����
	const ushort COLLUMN = 25;
	const ushort LINE = 12;
	//������� �������, ��������������� �������������
	char yadro[LINE][COLLUMN];
	//���������� ������� ����
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

	//��������� ������������ ���� ������� ��������� ��� ��������������
	for (ushort i = 1; i < LINE - 1; i++)
	{
		for (ushort j = 1; j < COLLUMN - 1; j++)
		{
			yadro[i][j] = ' ';
		}
	}

	//������ ������ ���� ���������� ��������� ��������
	char hp_char[] = "10";		//������� ����� ��������
	yadro[LINE / 2][COLLUMN / 2 - 2] = hp_char[0];
	yadro[LINE / 2][COLLUMN / 2 - 1] = hp_char[1];
	yadro[LINE / 2][COLLUMN / 2] = '/';
	yadro[LINE / 2][COLLUMN / 2 + 1] = '1';
	yadro[LINE / 2][COLLUMN / 2 + 2] = '10';

	//����� ����� �������� �� ���� ���� ( ����� ) � ����� ���
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (WORD)((15 << 4) | 9));
	//�������� �����, ������ �������� ���������� ����
	gotoxy(X1, Y1);
	//������� �� ����� ����
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

//������� ����������(��������� �� ��� �����) ����� � ���� ����� � ������� number
void clearTower(ushort number)
{
	//������� ������� ���� ���������� ������
	const ushort
		LINE_UP = 4,   //������ ������� �������� �����
		LINE_DOWN = 3, //������ ������ �������� �����
		COLLUMN = 15;  //����� ����� �������
	//��� ��������� �������, ��������������� ������� �������� ����� � ������
	char up[LINE_UP][COLLUMN], down[LINE_DOWN][COLLUMN];
	//�������� ����� ����� � ������������ ����� ������� ���������
	up[0][0] = static_cast<char>(201);
	up[0][COLLUMN - 1] = static_cast<char>(187);
	for (ushort i = 1; i < LINE_UP; i++)
	{
		up[i][0] = static_cast<char>(186);
		up[i][COLLUMN - 1] = static_cast<char>(186);
	}
	//�������� ����� ����� � ������������ ����� ������ ���������
	down[LINE_DOWN - 1][0] = static_cast<char>(200);
	down[LINE_DOWN - 1][COLLUMN - 1] = static_cast<char>(188);
	for (ushort i = 0; i < LINE_DOWN - 1; i++)
	{
		down[0][i] = static_cast<char>(186);
		down[COLLUMN - 1][i] = static_cast<char>(186);
	}
	//�������� ����� �� �������������� ����� � ����� ���������
	for (ushort i = 1; i < COLLUMN - 1; i++)
	{
		up[0][i] = static_cast<char>(205);
		down[LINE_DOWN - 1][i] = static_cast<char>(205);
	}
	//�������� ������� ��������� ������������ ������� � ������ ��������� ��� ��������������
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
	//������� ���� �������� �� ���� �����(�����), � ��� �� �����
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (WORD)((15 << 4) | 9));
	//������� ����������, � ������������ � ������� �����
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
	ushort distance = 0;	//������� ����������, ������ ���������� ����� �����������
	//���� ���������� ����� �� ��� ������������� �����
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

//������� ����������(��������� �� ��� �����) ������ � ���� �����
void clearObject(string uravnenie, ushort X1, ushort Y1)
{
	//������ ������� ������� (������� ����������� ��� ����� ���������)
	const ushort 
		COLLUMN = uravnenie.size() + 4,
		LINE_UP = 3,
		LINE_DOWN = 2;
	//������� ��� ���������� �������, ���������� � ���� ������� ����� ������� � ������
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