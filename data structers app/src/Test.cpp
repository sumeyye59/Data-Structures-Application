/** 
* @description Kisiler.txt'ten kisi bilgilerini okuyup kişi nesnesine yazar ve kişi nesnelerinide boya göre avl ağacına atar.
Ağacı levelorder yazdırıken her düğümün yükseklik ve derinlik yığıtlarının elemanlarını yazdırıp pop edecek

* @date 19.08.2021
* @author Sümeyye Yaşar 
*/ 

#include <fstream>
#include "AVL.hpp"
void dosyaOkuma(AVL*,string);
int main(){
	
	AVL *agac=new AVL();
	dosyaOkuma(agac,"doc/Kisiler.txt");
	
	agac->levelorder();
	delete agac;
}
void dosyaOkuma(AVL *agac,string dosya){
	
	char kar;
	string isim="";
	int boy=0;
	int x;//int'e çevrilen karakter için
	int kacinci=1;//isim ,yaş ve boydan hangisini okuduğunu anlamak için
	int yas=0;
	bool ks=false;//bir kişinin isim.yaş ve boyu okunudğunda true olur. 
	Kisi *kisi;
	ifstream dosyaOkuma(dosya);
	if(dosyaOkuma.is_open()){
		int j=0;
		
		while(dosyaOkuma.get(kar)){
			if(kar!='#'&& kacinci==1){
				
				isim=isim+kar;
				
		}
		
		if(kar!='#'&& kacinci==2){
			x=kar-'0';
			if(j==0){yas=yas+x*10;}
				if(j==1)yas=yas+x;
				j++;
				if(j==2){
			  j=0;
		}
		}
		if(kar!='#'&& kacinci==3 ){
			
			x=kar-'0';
			if(x==1&&j==0){
				boy=boy+x*100;
			}
			if(j==1){
			boy=boy+x*10;
			}
			if(j==2){
				
				kacinci=1;
				ks=true;
				boy=boy+x;}
				
		
		 j++;
		
		if(ks==true){
			    j=0;
				kisi=new Kisi(isim,yas,boy);
				agac->Ekle(kisi);
				yas=0;boy=0;
				isim="";
				ks=false;
		}}
		if(kar=='#')
		{
			kacinci++;
		}
		
		
		}
	dosyaOkuma.close();
	}
	
	
}