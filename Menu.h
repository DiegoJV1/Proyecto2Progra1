#pragma once
#include"RentACar.h"
class Menu{
private:
	RentACar* negocio;
public:
	Menu();
	Menu(RentACar* aux);
	~Menu();
	void ejecutar();
};

