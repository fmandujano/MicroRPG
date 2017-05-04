#include "stdafx.h"

Imagen::Imagen(int x, int y)
{
	data = (char*)calloc(x*y  ,sizeof(char));
	if (data == NULL)
	{
		printf("Error: no se puede alojar la memoria\n");
	}

	sizex = x;
	sizey = y;
}

void Imagen::SetPixel(int x, int y, char valor)
{
	//seguro
	if (x >= sizex || y >= sizey) return;

	data[y * sizey + x] = valor;
}

char Imagen::GetPixel(int x, int y)
{
	//seguro
	if (x >= sizex || y >= sizey) return 0;
	return data[y*sizey + x];
}

void Imagen::Print()
{
	for (int j = 0; j < sizey; j++)
	{
		for (int i = 0; i < sizex; i++)
		{
			printf("%c", data[j*sizey + i]  );
		}
		printf("\n");
	}
}

void Imagen::SaveToDisk(char* filename)
{
	std::ofstream myfile;
	myfile.open(filename, std::ios::binary);

	myfile.write(data, sizex*sizey*sizeof(char));
	myfile.close();
}

Imagen::~Imagen()
{
	free(data);
	data = NULL;
}
