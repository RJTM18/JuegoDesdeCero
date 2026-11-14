#pragma once
#include "pch.h"

enum Direcciones { Ninguno, Arriba, Abajo, Derecha, Izquierda };

class Sprite {
public:
	Sprite(int x, int y, int ancho, int largo, int filas, int columnas) :
		x(x), y(y),
		ancho(ancho), largo(largo),
		filas(filas), columnas(columnas),
		velocidad(0),
		dx(0), dy(0),
		indiceX(0), indiceY(0) { ; }
	~Sprite() { ; };

	virtual void mover() = 0;
	virtual void dibujar() = 0;

protected:
	//movimiento de las entidades
	int x, y;
	int dx, dy; //(-1, 0, 1)
	int velocidad;

	//impresion de sprites
	int indiceX, indiceY;
	int columnas, filas;
	int ancho, largo;
};
