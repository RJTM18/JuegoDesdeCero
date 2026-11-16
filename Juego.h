#include "pch.h"
#include "Caballero.h"

class Juego {
public:
	Juego(int ScreenHeight, int ScreenWidth) : AltoPantalla(ScreenHeight), AnchoPantalla(ScreenWidth) {};
	~Juego() { delete caballero; };
	
	void moverCaballero(Direcciones tecla, int AnchoPantalla, int AltoPantalla) { caballero->mover(tecla, AnchoPantalla, AltoPantalla); }
	void DibujarCaballero(Graphics^ g, Bitmap^ Caballero) { caballero->dibujar(g, Caballero); }

	//SpriteSheet Caballero Datos
	void setCaballeroWidthSheet(int WidthSheet)		{ caballero->setWidthSheet(WidthSheet); }
	void setCaballeroHeightSheet(int HeightSheet)	{ caballero->setHeightSheet(HeightSheet); }
	void setCaballeroColumns(int columns)			{ caballero->setColumns(columns); }
	void setCaballeroRows(int rows)					{ caballero->setRows(rows); }

private:
	Caballero* caballero;
	int AltoPantalla;
	int AnchoPantalla;
};


