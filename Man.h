#pragma once
#include "Sprite.h"

class Man : public Sprite {
public:
	Man(int x, int y, int widthsheet, int heightsheet, int columns, int rows, int velocidad, int escala) : 
		Sprite(x, y, widthsheet, heightsheet, columns, rows, velocidad, escala) { };
	~Man() {};

	void mover(Direcciones tecla, int WidthScreen, int HeightScreen) override {
		//movimiento
		dx = dy = 0;

		if (tecla == Derecha)	dx = 1;
		if (tecla == Izquierda) dx = -1;
		if (tecla == Arriba)	dy = -1;
		if (tecla == Abajo)		dy = 1;

		x += velocidad * dx;
		y += velocidad * dy;

		//limites
		if (x < 0) x = 0;
		if (y < 0) y = 0;
		if (x > WidthScreen - (widthFrame * escala)) x = WidthScreen - (widthFrame * escala);
		if (y > HeightScreen - (heightFrame * escala)) y = HeightScreen - (heightFrame * escala);

		animar(tecla);
	}

	void animar(Direcciones tecla) {
		if (tecla == Abajo)		indexY = 0;
		if (tecla == Izquierda)	indexY = 1;
		if (tecla == Derecha)	indexY = 2;
		if (tecla == Arriba)	indexY = 3;

		if (tecla != Ninguno) {
			indexX++;
			if (indexX >= columns) { indexX = 1; return; }
		}
		else { indexX = 0; }
	};

private:

};

