/** 
* @description Kisiler.txt'ten kisi bilgilerini okuyup kişi nesnesine yazar ve kişi nesnelerinide boya göre avl ağacına atar.
Ağacı levelorder yazdırıken her düğümün yükseklik ve derinlik yığıtlarının elemanlarını yazdırıp pop edecek.
* @date 19.08.2021
* @author Sümeyye Yaşar 
*/ 

#include "Dugum.hpp"
#include "Yigit.hpp"
	Dugum::Dugum(Kisi* ks,Dugum *sl=NULL,Dugum *sg=NULL){
			kisi=ks;
			sol=sl;
			sag=sg;
			
			yukseklikY=new Yigit();
			derinlikY=new Yigit();
		}
	Dugum::Dugum(Kisi* ks){
			kisi=ks;
			sol=NULL;
			sag=NULL;
			
			yukseklikY=new Yigit();
			derinlikY=new Yigit();
		}	
		Dugum::~Dugum(){
		delete kisi;	
			delete yukseklikY;
			delete derinlikY;
		}