// B_microrpg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//buffer de mensajes
char* dlog;
//mapa de tamaño arbitrario
Imagen *mapa;

Inventario *inventario;

//posicion inicial del personaje
int playerX = 2;
int playerY = 2;

//dineros del jugador
int dineros = 0;

//posicion anterior del personaje
int prevPlayerX = playerX;
int prevPlayerY = playerY;

void drawWorld()
{
	//borrar buffer de mensajes
	sprintf(dlog, "");

	//asigna los caracteres del inventario
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (inventario->items[i] != NULL)
		{
			mapa->SetPixel( inventario->items[i]->posX ,
				inventario->items[i]->posY,
				inventario->items[i]->sprite);
		}
	}

	//dibujar jugador y ver si toca algun item
	if (mapa->GetPixel(playerX, playerY) == '$')
	{
		dineros += 100;
		sprintf(dlog, "Recogiste 100 dineros, ahora tienes %i", dineros);
		inventario->recogerItem(playerX, playerY);
		mapa->SetPixel(playerX, playerY, 0x02);
	}
	else if (mapa->GetPixel(playerX, playerY) == SPRITE_MORTAL)
	{
		sprintf(dlog, "GAME OVER. Estas muerto");
		mapa->SetPixel(playerX, playerY, 0xF1);
	}
	else
	{
		mapa->SetPixel(playerX, playerY, 0x02);
	}

	mapa->SetPixel(prevPlayerX, prevPlayerY, 0);
	


	//imprime los caracteres del mundo
	for (int j = 0; j < mapa->SizeY(); j++)
	{
		for (int i = 0; i < mapa->SizeX(); i++)
		{
			printf("%c", mapa->data[j*mapa->SizeX() + i]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	mapa = new Imagen(35, 22);
	inventario = new Inventario(mapa);

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

	//buffer de mensaje
	dlog = new char[128];
	
	//ciclo del juego
	char comando = 0;

	//dibujar el primer cuadro

	drawWorld();
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

			drawWorld();
			std::cout << dlog << std::endl;
		}
	}

	std::cout << "guardadno partida..." << std::endl;
	mapa->SaveToDisk("level0.map");
	system("PAUSE");
    return 0;
}

