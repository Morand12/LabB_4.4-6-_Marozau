#pragma once

#include <iostream>
#include <array>

using namespace std;

class Stroke
{
	char* arr;
	int size;

public:
	
	void Print();

	int GetSizeOfStroke() const;

	void SetSizeOfStroke(int newsize);

	char GetElement(int index) const;

	void SetElement( int index, char symb);

	void DeleteElement(int index);
	
	void AddElement(int index, char symb);
	Stroke()
	{
		arr = nullptr;
		this->size = 0;
	}

	Stroke(int size)
	{
		arr = new char[size];
		this->size = size;

		cout << "Enter the stroke" << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}

	Stroke(Stroke& str)
	{
		this->size = str.size;

		this->arr = new char[this->size];

		for (auto i = 0; i < this->size; i++)
		{
			this->arr[i] = str.arr[i];
		}
	}

	
	Stroke(Stroke& str, int nothing)
	{
		this->size = str.size;
		this->arr = new char[this->size];

		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = str.arr[i];
			str.arr[i] = 0;
		}
		str.~Stroke();
	}

	Stroke& operator = (Stroke& str)
	{

		this->size = str.size;

		this->arr = new char[this->size];

		for (auto i = 0; i < this->size; i++)
		{
			this->arr[i] = str.arr[i];
		}
		return *this;
	}

	Stroke& operator >>(Stroke& str)
	{
		this->size = str.size;
		this->arr = new char[this->size];

		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = str.arr[i];
			str.arr[i] = 0;
		}
		str.~Stroke();
	}
	~Stroke()
	{
		cout << "destr" << endl;
		delete[] arr;
		arr = nullptr;
	}

	char& operator [] (const int index) 
	{
		return arr[index];
	}

	void operator & () 
	{
		while (arr[0] == ' ')
		{
			DeleteElement(0);
		}
	}
	void operator + (Stroke& Second)
	{
		for (int i = 0; i < Second.size; i++)
		{
			bool searchFlag = false;
			for (int j = 0; j < this->size; j++)
			{
				if (this->arr[j]==Second.arr[i])
				{
					searchFlag = true;
				}
			}
			if (searchFlag == false)
			{
				if (i>this->size)
				{
					AddElement(size+1, Second.arr[i]);
					this->size++;
				}
				else 
				{
					AddElement(i, Second.arr[i]);
					this->size++;
				}
				
			}
		}
	}
};

inline ostream& operator<<(ostream& os,Stroke& str)
{
	for (int i = 0; i < str.GetSizeOfStroke(); i++)
	{
		os << str.GetElement(i) << " ";
	}

	return os;
}

inline ifstream& operator>>(ifstream& is, Stroke str)
{
	int a;
	for (int i = 0; i < str.GetSizeOfStroke(); i++)
	{
		cin >> a;
		str.SetElement( i, a);
	}
	return is;
	
}
