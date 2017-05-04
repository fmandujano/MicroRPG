#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>

class Imagen
{
public:
	Imagen(int x,  int y);
	~Imagen();

	void SetPixel(int x, int y, char valor);
	char GetPixel(int x, int y);

	void Print();
	void SaveToDisk(char* filename);

	int SizeX()
	{
		return sizex;
	}//getter y setters
	int SizeY()
	{
		return sizey;
	}

private:
	char * data;
	int sizex;
	int sizey;
};

