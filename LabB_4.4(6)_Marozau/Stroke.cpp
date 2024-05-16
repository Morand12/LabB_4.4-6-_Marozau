#include "Stroke.h"
#include <ctime>

int Stroke::GetSizeOfStroke() const
{
	return this->size;
}

void Stroke::SetSizeOfStroke(int newsize)
{
	char* ar = new char[newsize];
	int sizeofoldarr = this->size;

	if (newsize > sizeofoldarr)
	{
		this->size = newsize;
		for (int i = 0; i < sizeofoldarr; i++)
		{
			ar[i] = this->arr[i];
		}

		for (int i = sizeofoldarr; i < newsize; i++)
		{
			ar[i] = 0;
		}

		delete[] this->arr;

		this->arr = ar;

	}
	else if (newsize < sizeofoldarr)
	{
		this->size = newsize;
		for (int i = 0; i < newsize; i++)
		{
			ar[i] = this->arr[i];
		}

		delete[] this->arr;

		this->arr = ar;
	}
	else
	{
		cout << "Stroke have need size" << endl;
	}
}


void Stroke::Print()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->arr[i] << " ";
	}

	cout << endl;
}

char Stroke::GetElement(int index) const
{
	return this->arr[index];
}
void Stroke::SetElement( int index, char symb)
{
	arr[index] = symb;
}

void Stroke::DeleteElement(int index)
{
	char* newMass = new char[this->size-1];
	for (int i = 0; i < index; i++) {
		newMass[i] = arr[i];
	}
	for (int j = index + 1; j < this->size; j++)
	{
		newMass[j - 1] = arr[j];
	}
	delete[] arr;
	this->arr = newMass;
	this->size--;
}
void Stroke::AddElement(int index, char symb) 
{
	this->size++;
	for (int i = this->size; i > index; i--) {
		this->arr[i] = this->arr[i - 1];
	}
	this->arr[index] = symb;
}