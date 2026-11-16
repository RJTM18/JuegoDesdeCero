#pragma once
#include "Sprite.h"

class OldMan : public Sprite {
public:
	OldMan(int x, int y, int widthSheet, int heightSheet, int columns, int rows) :
		Sprite(x, y, widthSheet, heightSheet, columns, rows) {
		this->velocidad = 20;
	};
	~OldMan() {};

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
		if (x > WidthScreen - widthFrame) x = WidthScreen - widthFrame;
		if (y > HeightScreen - heightFrame) y = HeightScreen - heightFrame;

		animar(tecla);
	}

	void animar(Direcciones tecla) {
		if (tecla == Arriba)	indexY = 3;
		if (tecla == Abajo)		indexY = 0;
		if (tecla == Izquierda)	indexY = 1;
		if (tecla == Derecha)	indexY = 2;

		if (tecla != Ninguno) {
			indexX++;
			if (indexX >= columns) { indexX = 1; return; }
		} else { indexX = 0; }
	};

private:
	Direcciones direccion;
	bool EstaLanzando;


};