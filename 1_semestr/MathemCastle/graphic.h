#pragma once
#include <string>;

using std::string;
typedef short unsigned int ushort;

//������� �������� � ��������������� �����������
void gotoxy(ushort X1, ushort Y1);

//������� ��������� ������
void drawObject(string uravnenie, ushort X1, ushort Y1);

//������� ��������� �����
void drawTower(ushort X2, ushort Y2);

//������� ��������� ����
void drawCore(ushort X3, ushort Y3, ushort hp);

//������� ����������� ����� � ������� number
void clearTower(ushort number);
