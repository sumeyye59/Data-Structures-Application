/** 
* @description Kisiler.txt'ten kisi bilgilerini okuyup kişi nesnesine yazar ve kişi nesnelerinide boya göre avl ağacına atar.
Ağacı levelorder yazdırıken her düğümün yükseklik ve derinlik yığıtlarının elemanlarını yazdırıp pop edecek.
* @date 19.08.2021
* @author Sümeyye Yaşar 
*/ 
 
 #include "Kisi.hpp" 
	Kisi::Kisi(string isim,int yas,int boy){
			this->isim=isim;
			this->yas=yas;
			this->boy=boy;
			}
		Kisi::~Kisi(){
			
		}