#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
#include <cmath>
#include<stdlib.h>
#include "Kisi.hpp"
#include "Yigit.hpp"

class Dugum{
	public:
		Kisi *kisi;
		Dugum *sol;
		Dugum *sag;
		Yigit *yukseklikY;
		Yigit *derinlikY;
	    
	    
	Dugum(Kisi*,Dugum*,Dugum*);
	Dugum(Kisi*);
	~Dugum();
};


#endif