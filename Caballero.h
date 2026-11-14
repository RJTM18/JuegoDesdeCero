#pragma once
#include "Sprite.h"
#include <string>

class Caballero : public Sprite {
public:
	// Caballero(int x, int y) : Sprite(x, y,);
	~Caballero();
	
	void mover() override {

	}

private:
	Direcciones direccion;
	bool EstaLanzando;
};

