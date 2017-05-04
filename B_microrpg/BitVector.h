#pragma once
#include <cstdio>
#include <fstream>

typedef char byte;
class BitVector
{
public:
	BitVector(int size);
	~BitVector();
	bool get(int index);
	void set(int index, bool val);
	void clearAll();
	void setAll();
	void print();
	void saveToFile(char* filename);

private:
	byte* data;
	int size;
};

