#pragma once
#include "pch.h"
#include "Mario.h"

class Juego {
public:
	Juego(int ScreenHeight, int ScreenWidth) : AltoPantalla(ScreenHeight), AnchoPantalla(ScreenWidth) {};
	~Juego() { delete mario; };
	
	//Mario
	void crearMario(int x, int y, int widthSheet, int heightSheet, int columns, int rows, int velocidad, int escala) { mario = new Mario(x, y, widthSheet, heightSheet, columns, rows, velocidad, escala); }
	void moverMario(Direcciones tecla, int AnchoPantalla, int AltoPantalla) { mario->mover(tecla, AnchoPantalla, AltoPantalla); }
	void dibujarMario(Graphics^ g, Bitmap^ MarioImage) { mario->dibujar(g, MarioImage); }

	void saltarMario(Direcciones tecla, int AnchoPantalla, int AltoPantalla) { mario->Saltar(tecla, AnchoPantalla, AltoPantalla); }

private:
	Mario* mario;
	
	int AltoPantalla;
	int AnchoPantalla;
};


