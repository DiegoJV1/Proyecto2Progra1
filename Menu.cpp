#include "Menu.h"
Menu::Menu(): negocio(nullptr){}
Menu::Menu(RentACar* aux) :negocio(aux) {}
Menu::~Menu() { delete negocio; }
void Menu::ejecutar() {







}
