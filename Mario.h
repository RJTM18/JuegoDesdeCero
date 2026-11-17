#pragma once
#include "Sprite.h"
#include <math.h>

class Mario : public Sprite{
public:
	Mario(int x, int y, int widthSheet, int heightSheet, int columns, int rows, int velocidad, int escala) :
		Sprite(x, y, widthSheet, heightSheet, columns, rows, velocidad, escala) {
		this->heightFrame = heightFrame - 5;
		this->indexX = 5;
		this->estaSaltando = false;
	}
	~Mario() { ; }

	void mover(Direcciones tecla, int WidthScreen, int HeightScreen) override {
		//movimiento
		dx = 0;

		if (tecla == Derecha)	dx = 1;
		if (tecla == Izquierda) dx = -1;

		x += velocidad * dx;

		//limites
		if (x < 0) x = 0;
		if (x > WidthScreen - (widthFrame * escala)) x = WidthScreen - (widthFrame * escala);

		animar(tecla);
		
	};

	void Saltar(Direcciones tecla, int WidthScreen, int HeightScreen) {
		estaSaltando = true;
		indexY = 3;


	}

	void calcularPosicionSalto() {
		int z = range();
	}

	void animar(Direcciones tecla) {
		if (tecla == Izquierda || tecla == Derecha) {
			indexY = 2;

			if (tecla == Izquierda) {
				if (indexX == 0)		{ indexX = 1; return; }
				else if (indexX == 1)	{ indexX = 4; return; }
				else if (indexX == 4)	{ indexX = 0; return; }
				indexX = 4;
			}
			if (tecla == Derecha) {
				if (indexX == 8)		{ indexX = 9; return; }
				else if (indexX == 9)	{ indexX = 5; return; }
				else if (indexX == 5)	{ indexX = 8; return; }
				indexX = 5;
			}
		}

		if (tecla == Ninguno) {
			indexY = 2;
			if (indexX == 0 || indexX == 1) indexX = 4;
			if (indexX == 8 || indexX == 9) indexX = 5;
		}
	};
private:
	bool estaSaltando;
	
};

