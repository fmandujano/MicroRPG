#include "stdafx.h"



//Dar el tamaño en bits
BitVector::BitVector(int _size)
{
	if (_size % 8 > 0)
	{
		size = (_size / 8) + 1;
	}
	else
	{
		size = (_size / 8);
	}
	printf("bitvector size: %i \n", size);
	data = new byte[size];

	clearAll();
}

bool BitVector::get(int index)
{
	int bloque = index / 8;
	int bit = index % 8;
	printf("get bloque %i, bit: %i\n", bloque, bit);
	byte B = data[bloque];
	bool bitret = (B >> bit) & 1;
	return bitret;
}

void BitVector::set(int index, bool val)
{
	int bloque = index / 8;
	int bit = index % 8;
	byte B = data[bloque];
	if (val)
	{
		B = B | 1 << bit;
	}
	else
	{
		B = B & ~(1 << bit);
	}
	data[bloque] = B;
}

void BitVector::print()
{
	printf("Bitvector:\n");
	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			printf("%i",  (data[i] >> j) & 1  );
		}
	}
	printf("..\n");
}

void BitVector::clearAll()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

void BitVector::setAll()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0xFF;
	}
}

void BitVector::saveToFile(char* filename)
{
	std::ofstream file;

	file.open(filename, std::ios::binary);
	file.write( (const char*) data, size);
	file.close();
}

BitVector::~BitVector()
{
	delete[] data;
	data = NULL;
}
