#pragma once
#include "Sprite.h"
#include <string>

class Caballero : public Sprite {
public:
	Caballero(int x, int y, int widthSheet, int heightSheet, int columns, int rows) : 
		Sprite(x, y, widthSheet, heightSheet, columns, rows) {
		this->velocidad = 20;
	};

	~Caballero() {};

	//In pixels
	void setWidthSheet(int WidthSheet)		{ WidthSheet = WidthSheet; }
	void setHeightSheet(int heightSheet)	{ heightSheet = heightSheet; }
	void setColumns(int columns)			{ columns = columns; }
	void setRows(int rows)					{ rows = rows; }
	
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
		if (tecla == Arriba)	indexY = 0;
		if (tecla == Abajo)		indexY = 1;
		if (tecla == Izquierda)	indexY = 2;
		if (tecla == Derecha)	indexY = 3;

		if (tecla != Ninguno) {
			if (indexX == 1) indexX = 4;
			indexX = 1;
		} else { indexX = 0; }
	};

private:
	Direcciones direccion;
	bool EstaLanzando;
};

