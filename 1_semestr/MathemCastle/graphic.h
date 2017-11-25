#pragma once
#include <string>;

using std::string;
typedef short unsigned int ushort;

//Функция перехода к соответствующим координатам
void gotoxy(ushort X1, ushort Y1);

//Функция отрисовки задачи
void drawObject(string uravnenie, ushort X1, ushort Y1);

//Функция отрисовки башни
void drawTower(ushort X2, ushort Y2);

//Функция отрисовки ядра
void drawCore(ushort X3, ushort Y3, ushort hp);

//Функция уничтожения башни с номером number
void clearTower(ushort number);
