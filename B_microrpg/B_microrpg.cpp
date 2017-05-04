// B_microrpg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char** argv)
{
	Imagen *mapa = new Imagen(16, 16);

	//crear borde

	for (int i = 0; i < mapa->SizeY(); i++)
	{
		mapa->SetPixel(0, i, 'X');
		mapa->SetPixel(mapa->SizeX()-1, i, 'X');
	}
	for (int i = 0; i < mapa->SizeX(); i++)
	{
		mapa->SetPixel(i, 0, 'X');
		mapa->SetPixel(i, mapa->SizeY()-1, 'X');
	}

	//items del jugador
	BitVector *inventario = new BitVector(3);
	
	//ciclo del juego

	char comando = 0;
	while (comando != 59)
	{

		mapa->Print();
		std::cout << "INVENTORY: " << std::endl;
		comando = _getchar_nolock();
	}

	std::cout << "guardadno partida..." << std::endl;
	mapa->SaveToDisk("level0.map");
	system("PAUSE");
    return 0;
}

