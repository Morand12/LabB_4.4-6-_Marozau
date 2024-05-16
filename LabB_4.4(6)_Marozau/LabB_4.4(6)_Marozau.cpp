#include<iostream>
#include"Stroke.h"
using namespace std;

//6. Определить класс для работы с объектом «строка символов».Реализовать:
//вставку в строку указанного символа в заданную позицию, удаление ведущих пробелов.
//Добавить в заданную строку отсутствующие символы из второй заданной
//строки, на позиции с такими же номерами.

int main()
{
	int sizeFirst;
	cout << "enter the size: ";
	cin >> sizeFirst;
	cout << "enter the stroke: ";
	Stroke First(sizeFirst);
	int sizeSecond;
	cout << "enter the size: ";
	cin >> sizeSecond;
	cout << "enter the stroke: ";
	Stroke Second(sizeSecond);

	First.SetElement(0, ' ');
	First.SetElement(1, ' ');
	First.Print();
	&First;

	First.AddElement(2, 't');
	First.Print();
}