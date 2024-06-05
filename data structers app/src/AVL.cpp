/** 
* @description Kisiler.txt'ten kisi bilgilerini okuyup kişi nesnesine yazar ve kişi nesnelerinide boya göre avl ağacına atar.
Ağacı levelorder yazdırıken her düğümün yükseklik ve derinlik yığıtlarının elemanlarını yazdırıp pop edecek.
* @date 19.08.2021
* @author Sümeyye Yaşar 
*/ 

#include "AVL.hpp"

		
		Dugum* AVL::AraVeEkle(Dugum *altDugum,Kisi *yeni){
			
			if(altDugum==NULL) {altDugum=new Dugum(yeni);}
			else if(yeni->boy<=altDugum->kisi->boy){
				altDugum->sol=AraVeEkle(altDugum->sol,yeni);
				if(Yukseklik(altDugum->sol)==Yukseklik(altDugum->sag)+2){
					if(yeni->boy<=altDugum->sol->kisi->boy)
						altDugum=SolCocukIleDegistir(altDugum);
					else{
						altDugum->sol=SagCocukIleDegistir(altDugum->sol);
						altDugum=SolCocukIleDegistir(altDugum);
					}	
				}
			}
			else if(yeni->boy>altDugum->kisi->boy){
				altDugum->sag=AraVeEkle(altDugum->sag,yeni);
				
				if(Yukseklik(altDugum->sag)==Yukseklik(altDugum->sol)+2){
					if(yeni->boy>altDugum->sag->kisi->boy)
						altDugum=SagCocukIleDegistir(altDugum);
					else{
						altDugum->sag=SolCocukIleDegistir(altDugum->sag);
						altDugum=SagCocukIleDegistir(altDugum);
					}
					}
				}
			else;
			
			return altDugum;
		}
		
		Dugum* AVL::SolCocukIleDegistir(Dugum *altDugum){
			Dugum *tmp=altDugum->sol;
			altDugum->sol=tmp->sag;
			tmp->sag=altDugum;
			
			
		return tmp;
		}
		Dugum* AVL::SagCocukIleDegistir(Dugum *altDugum){
			Dugum *tmp=altDugum->sag;
			altDugum->sag=tmp->sol;
			tmp->sol=altDugum;
			
		   return tmp;
		}
		bool AVL::DugumSil(Dugum *&altDugum){
			Dugum *silinecekDugum=altDugum;
			
			if(altDugum->sag==NULL) altDugum=altDugum->sol;
			else if(altDugum->sol==NULL)altDugum=altDugum->sag;
			else{
				silinecekDugum=altDugum->sol;
				Dugum *ebeveynDugum=altDugum;
				while(silinecekDugum->sag!=NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->sag;
				}
				altDugum->kisi->boy=silinecekDugum->kisi->boy;
				if(ebeveynDugum==altDugum) altDugum->sol=silinecekDugum->sol;
				else ebeveynDugum->sag=silinecekDugum->sol;
				
			}
			
			delete silinecekDugum;
			return true;
		}
		int AVL::Yukseklik(Dugum *altDugum){
			
			if(altDugum==NULL) return -1;
			
			return 1+max(Yukseklik(altDugum->sol),Yukseklik(altDugum->sag));
			
		}
		int AVL::Derinlik(Dugum *altDugum,Dugum *gecici){
			if(gecici==altDugum) return 0;
			else if(altDugum->kisi->boy>gecici->kisi->boy) return 1+Derinlik(altDugum,gecici->sag);
			else return 1+Derinlik(altDugum,gecici->sol);
		}
		void AVL::SeviyeyiYazdir(Dugum *altDugum,int seviye){
			if(altDugum==NULL) return;
			if(seviye==0) {cout<<endl<<altDugum->kisi->isim<<" "<<altDugum->kisi->yas<<" "<<altDugum->kisi->boy<<" Y(";altDugum->yukseklikY->makeEmpty();cout<<")"<<"D(";altDugum->derinlikY->makeEmpty();cout<<") ";}
			else{
				SeviyeyiYazdir(altDugum->sol,seviye-1);
				SeviyeyiYazdir(altDugum->sag,seviye-1);
			}
		}
		bool AVL::Arama(Dugum *altDugum,const Kisi* aranan){
			if(altDugum==NULL) return false;
			if(altDugum->kisi->boy==aranan->boy) return true;
			if(aranan->boy<altDugum->kisi->boy) return Arama(altDugum->sol,aranan);
			else return Arama(altDugum->sag,aranan);
		}
	void AVL::yukseklikDerinlikGuncelle(Dugum *altDugum ){//her düğümün yükseklik ve derinliğini güncelleyen fonksiyon
			if(altDugum!=NULL){
				altDugum->yukseklikY->push(Yukseklik(altDugum));
				altDugum->derinlikY->push(Derinlik(altDugum,kok));
				yukseklikDerinlikGuncelle(altDugum->sol);
				yukseklikDerinlikGuncelle(altDugum->sag);
			}
		}
		AVL::AVL(){
			kok=NULL;
		}
		bool AVL::Bosmu()const{
			return kok==NULL;
		}
		void AVL::Ekle(Kisi *yeni){
			kok=AraVeEkle(kok,yeni);
			yukseklikDerinlikGuncelle(kok);
		}
		
		void AVL::levelorder(){
			int h=Yukseklik();
			for(int seviye=0;seviye<=h;seviye++){
				SeviyeyiYazdir(kok,seviye);
				
			}
		}
		int AVL::Yukseklik(){
			return Yukseklik(kok);
		}
		bool AVL::Arama(const Kisi* aranan){
			return Arama(kok,aranan);
		}
		void AVL::Temizle(){
			while(!Bosmu()) DugumSil(kok);
		}
		AVL::~AVL(){
			Temizle();
		}