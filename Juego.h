#pragma once
#include "pch.h"
#include "Man.h"

class Juego {
public:
	Juego(int ScreenHeight, int ScreenWidth) : AltoPantalla(ScreenHeight), AnchoPantalla(ScreenWidth) {};
	~Juego() { delete man; };
	
	//MAN
	void crearMan(int x, int y, int widthSheet, int heightSheet, int columns, int rows, int velocidad, int escala) { man = new Man(x, y, widthSheet, heightSheet, columns, rows, velocidad, escala); }
	void moverMan(Direcciones tecla, int AnchoPantalla, int AltoPantalla) { man->mover(tecla, AnchoPantalla, AltoPantalla); }
	void dibujarMan(Graphics^ g, Bitmap^ ManImage) { man->dibujar(g, ManImage); }

private:
	Man* man;
	int AltoPantalla;
	int AnchoPantalla;
};


