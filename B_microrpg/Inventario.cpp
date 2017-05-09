#include "stdafx.h"
#include "Inventario.h"



Inventario::Inventario(Imagen * _mapa)
{
	mapa = _mapa;

	//items en el mapa
	items[0] = new Item(5, 5, '$', 0);
	items[1] = new Item(2, 10, '$', 1);
	items[2] = new Item(8, 6, 0x03, 2);
	items[3] = new Item(25, 4, 0x0C, 3);
	items[4] = new Item(30, 15, SPRITE_MORTAL, 3);
	items[5] = new Item(27, 8, 0x03, 3);
	items[6] = new Item(12, 11, 0x06, 3);
	items[7] = new Item(15, 15, 0x03, 3);

}


Inventario::~Inventario()
{
}

bool Inventario::recogerItem(int x, int y)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		int px = items[i]->posX;
		int py = items[i]->posY;
		if (x == px && y == py)
		{
			items[i]->sprite = ' ';
			//items[i]->bitoffset;
		}
		else return false;
	}
}

void Inventario::draw()
{
	for (int j = 0; j < mapa->SizeY(); j++)
	{
		for (int i = 0; i < mapa->SizeX(); i++)
		{
			//printf("%c", data[j*sizex + i]);
		}
		printf("\n");
	}
}

Item::Item(int px, int py, char sprt, int offset)
{
	posX = px;
	posY = py;
	sprite = sprt;
	bitoffset = offset;
}

void Item::draw()
{
	std::cout << sprite;
}
