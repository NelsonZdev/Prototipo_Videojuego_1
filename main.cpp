#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <stdlib.h>

int mov = 1;
int dir = 0;
char kinput = '0';

const int gameUpdate = (1000 / 8);
const char punto = '*';
const char espacio = ' ';

const int resolucionX = 100;
const int resolucionY = 20;

char pos[resolucionX][resolucionY];

using namespace std;
void Matrix2x2 (int x = 200,int y = 200);
void UpdatexSecond(int fps = 60);
void Draw(int cordenadaX = 1,int cordenadaY = 1);
void OnDraw();
int Direccion();

int main()
{
	system("clear");
	printf("\n********** Bienvenido a mi primer programa animado en c++ **********\n\n");
	printf("\n********** Desarrollado por Nelson Zapata :) **********\n\n");
	printf ("%c",7);
    cout<<"\n\n** Presiona A o D para mover la nave y luego... **\n"<<endl;
	cout<<"\n\n** Presiona Enter para Comenzar el programa... **\n"<<endl;
	cin.get();

	UpdatexSecond();

	cout<<"\n\n** Presiona Enter para Salir del programa... **\n"<<endl;
	cin.get();
	system("clear");
	return 0;
}

void Matrix2x2 (int x, int y){
	for (int iy = 0; iy < y; iy++)
	{
		for (int ix = 0; ix < x; ix++)
		{
			if ((ix == 0 || ix == (x-1) )|| (iy == 0 || iy == (y-1)))
			{
				pos[ix][iy] = punto;
			}else
			{
				pos[ix][iy] = espacio;
				OnDraw();
			}	
		}
	}
	for (int ay = 0; ay < y; ay++)
	{
		for (int ax = 0; ax < x; ax++)
		{
			cout << pos[ax][ay];
		}
		printf("\n");
	}
}
void Draw(int cordenadaX,int cordenadaY){
	pos[cordenadaX][cordenadaY] = punto;
}
void UpdatexSecond(int Fps){
	int i = 0;
	while (true)
	{
		mov = (mov < (resolucionX - 1) )? mov + Direccion():1;
		i++;
		//cout << "\033[2J\033[1;1H";
		system("clear");
		Matrix2x2(resolucionX,resolucionY);
		this_thread::sleep_for(std::chrono::milliseconds(gameUpdate)); //Espera 1000 ml antes de volver a comenzar
		if (i > 100)
		{
			break;
		}
		
	}
	
}
int Direccion(){
	kinput = cin.get();
	if (kinput == 'a')
	{
		return dir = -1;
	}
	else if (kinput == 'd')
	{
		return dir = 1;
	}else{
		return dir = dir;
	}
	
}
void OnDraw(){
	Draw(mov,10);
	Draw(mov,11);
	Draw(mov+1,11);
	Draw(mov+2,11);
	Draw(mov,9);
	Draw(mov+1,9);
	Draw(mov+2,9);
	Draw((mov-1),10);
}
