#pragma once
#include "teatr.h"
namespace Func {
	Teatr* Read();
	void Save(Teatr* arr,int n);
	Teatr* Delete(Teatr *arr, int m);
	void Dobavit(Teatr* arr, int n);
	void Find(Teatr* arr,int r);
	void Edit(Teatr* arr, int r);
	int getLengthArr();
}