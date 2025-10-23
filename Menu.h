#pragma once
#include"RentACar.h"
using namespace std;
class Menu{
private:
	RentACar* negocio;
public:
	Menu();
	Menu(RentACar* aux);
	~Menu();
	void ejecutar();
};

