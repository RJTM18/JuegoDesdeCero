#pragma once
#include "pch.h"

using namespace System::Drawing;
enum Direcciones { Ninguno, Arriba, Abajo, Derecha, Izquierda };

class Sprite {
public:
	Sprite(int x, int y, int widthSheet, int heightSheet, int columns, int rows) :
		x(x), y(y),
		widthFrame(widthSheet / columns), heightFrame(heightSheet / rows),
		columns(columns), rows(rows),
		velocidad(0),
		dx(0), dy(0),
		indexX(0), indexY(0) { ; }
	virtual ~Sprite() { ; };

	virtual void mover(Direcciones tecla, int AnchoPantalla, int AltoPantalla) = 0;

	virtual void dibujar(Graphics^ g, Bitmap^ SpriteSheet) {
		
		Rectangle recorteSpriteSheet = Rectangle(widthFrame * indexX,
												heightFrame * indexY,
												widthFrame, heightFrame);
		Rectangle pegadoEnFormat = Rectangle(x, y, widthFrame, heightFrame);

		g->DrawImage(SpriteSheet, pegadoEnFormat, recorteSpriteSheet, GraphicsUnit::Pixel);
	};

protected:
	//movimiento de las entidades
	int x, y;
	int dx, dy; //(-1, 0, 1)
	int velocidad;

	//impresion de sprites
	int indexX, indexY;
	int columns, rows;
	int widthFrame, heightFrame;
};
