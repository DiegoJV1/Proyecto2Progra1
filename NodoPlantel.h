#pragma once
#include"Plantel.h"
class NodoPlantel{
private:
	Plantel* obj;
	NodoPlantel* sig;
public:
	NodoPlantel();
	NodoPlantel(Plantel* aux);
	~NodoPlantel();
	void setObj(Plantel* aux);
	void setSig(NodoPlantel* aux);
	Plantel* getObj();
	NodoPlantel* getSig();
};

