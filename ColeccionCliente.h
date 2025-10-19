#pragma once
#include"NodoCliente.h"
class ColeccionCliente{
private:
	NodoCliente* inicio;
	NodoCliente* actual;
public:
	ColeccionCliente();
	~ColeccionCliente();
	void insertarCliente(Cliente* aux);
	void eliminarCliente(string id);
	bool buscarCliente(string id);
	string toString();
};

