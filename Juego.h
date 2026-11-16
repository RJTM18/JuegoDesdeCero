#pragma once
#include "pch.h"
#include "Caballero.h"
#include "OldMan.h"
#include "Young.h"

class Juego {
public:
	Juego(int ScreenHeight, int ScreenWidth) : AltoPantalla(ScreenHeight), AnchoPantalla(ScreenWidth) {};
	~Juego() { delete caballero; };
	
	//caballero
	void crearCaballero(int x, int y, int widthSheet, int heightSheet, int columns, int rows) { caballero = new Caballero(x, y, widthSheet, heightSheet, columns, rows); 	}
	void moverCaballero(Direcciones tecla, int AnchoPantalla, int AltoPantalla) { caballero->mover(tecla, AnchoPantalla, AltoPantalla); }
	void DibujarCaballero(Graphics^ g, Bitmap^ Caballero) { caballero->dibujar(g, Caballero); }

	//old man
	void crearOldMan(int x, int y, int widthSheet, int heightSheet, int columns, int rows) { oldMan = new OldMan(x, y, widthSheet, heightSheet, columns, rows); }
	void moverOldMan(Direcciones tecla, int AnchoPantalla, int AltoPantalla) { oldMan->mover(tecla, AnchoPantalla, AltoPantalla); }
	void dibujarOldMan(Graphics^ g, Bitmap^ Caballero) { oldMan->dibujar(g, Caballero); }

	//young
	void crearYoung(int x, int y, int widthSheet, int heightSheet, int columns, int rows) { young = new Young(x, y, widthSheet, heightSheet, columns, rows); }
	void moverYoung(Direcciones tecla, int AnchoPantalla, int AltoPantalla) { young->mover(tecla, AnchoPantalla, AltoPantalla); }
	void dibujarYoung(Graphics^ g, Bitmap^ Young) { young->dibujar(g, Young); }
private:
	Caballero* caballero;
	OldMan* oldMan;
	Young* young;
	int AltoPantalla;
	int AnchoPantalla;
};


