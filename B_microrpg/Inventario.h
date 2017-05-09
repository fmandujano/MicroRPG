#pragma once
#define INVENTORY_SIZE 8

#define SPRITE_MORTAL 0x15

class Item
{
public:
	int bitoffset;
	char sprite;
	int posX;
	int posY;

	Item(int px, int py, char sprt, int offset);
	~Item();

	void draw();
};

class Inventario
{
public:
	Item *items[INVENTORY_SIZE];
	Imagen * mapa;

	Inventario(Imagen * _mapa );
	~Inventario();

	void draw();
	bool recogerItem(int x, int y);
};


