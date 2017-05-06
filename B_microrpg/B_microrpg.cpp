// B_microrpg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char** argv)
{
	//mapa de tamaño arbitrario
	Imagen *mapa = new Imagen(13, 21);

	//crear borde superior e inferior
	for (int i = 0; i < mapa->SizeX(); i++)
	{
		mapa->SetPixel(i, 0, 'X');
		mapa->SetPixel(i, mapa->SizeY() -1, 'X');
	}
	//bordes derecho e izquierdo
	for (int i = 0; i < mapa->SizeY(); i++)
	{
		mapa->SetPixel(0, i, 'X');
		mapa->SetPixel(mapa->SizeX()-1, i, 'X');
	}

	//items del jugador
	BitVector *inventario = new BitVector(3);

	//posicion inicial del personaje
	int playerX = 2;
	int playerY = 2;

	//posicion anterior del personaje
	int prevPlayerX = playerX;
	int prevPlayerY = playerY;

	//buffer de mensaje
	char* log = new char[128];
	
	//ciclo del juego
	char comando = 0;

	//dibujar el primer cuadro
	mapa->SetPixel(playerX, playerY, 0x02);
	mapa->Print();
	while (comando != 27)
	{
		if (_kbhit())
		{
			system("cls");
			comando = _getch();

			prevPlayerX = playerX;
			prevPlayerY = playerY;
			
			//leer movimientos
			if (comando == 119) //subir
			{
				char pix = mapa->GetPixel(playerX, playerY - 1);
				//sprintf(log, "pixel (%i,%i) = %i", playerX, playerY - 1, pix);
				//si la celda es mayor a 0 y diferente de X
				if (pix >= 0 && pix != 'X')
				{
					playerY = playerY - 1;
				}
			}

			else if (comando == 115) //bajar
			{
				char pix = mapa->GetPixel(playerX, playerY + 1);
				//si la celda es mayor a 0 y diferente de X
				if (pix >= 0 && pix != 'X')
				{
					playerY = playerY + 1;
				}
			}
			else if (comando == 97) //izquierda
			{
				char pix = mapa->GetPixel(playerX -1, playerY);
				//si la celda es mayor a 0 y diferente de X
				if (pix >= 0 && pix != 'X')
				{
					playerX = playerX - 1;
				}
			}
			else if (comando == 100) //derecha
			{
				char pix = mapa->GetPixel(playerX + 1, playerY);
				//si la celda es mayor a 0 y diferente de X
				if (pix >= 0 && pix != 'X')
				{
					playerX = playerX + 1;
				}
			}
			else if (comando == 'e')
			{
				//sonido
				std::cout << (char)0x07;
			}

			
			mapa->SetPixel(prevPlayerX, prevPlayerY, 0);
			mapa->SetPixel( playerX, playerY, 0x02);
			mapa->Print();
			std::cout << log << std::endl;
		}
	}

	std::cout << "guardadno partida..." << std::endl;
	mapa->SaveToDisk("level0.map");
	system("PAUSE");
    return 0;
}

