#include<iostream>
#include"Stroke.h"
using namespace std;

//6. ���������� ����� ��� ������ � �������� ������� ��������.�����������:
//������� � ������ ���������� ������� � �������� �������, �������� ������� ��������.
//�������� � �������� ������ ������������� ������� �� ������ ��������
//������, �� ������� � ������ �� ��������.

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