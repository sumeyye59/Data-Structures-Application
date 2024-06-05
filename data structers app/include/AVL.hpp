#ifndef AVL_HPP
#define AVL_HPP

#include "Dugum.hpp"

class AVL{
	private:
		Dugum *kok;
		
		Dugum* AraVeEkle(Dugum*,Kisi*);
		Dugum* SolCocukIleDegistir(Dugum*);
		Dugum* SagCocukIleDegistir(Dugum*);
		bool DugumSil(Dugum*&);
		
		int Yukseklik(Dugum*);
		int Derinlik(Dugum*,Dugum*);
		void SeviyeyiYazdir(Dugum*,int);
		bool Arama(Dugum*,const Kisi*);
		void yukseklikDerinlikGuncelle(Dugum*);
	public:
		AVL();
		bool Bosmu()const;
		void Ekle(Kisi*);
		
		void levelorder();
		int Yukseklik();
		
		bool Arama(const Kisi*);
		void Temizle();
		~AVL();
	
};




#endif