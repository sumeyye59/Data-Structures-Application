/** 
* @description Kisiler.txt'ten kisi bilgilerini okuyup kişi nesnesine yazar ve kişi nesnelerinide boya göre avl ağacına atar.
Ağacı levelorder yazdırıken her düğümün yükseklik ve derinlik yığıtlarının elemanlarını yazdırıp pop edecek.
* @assignment 2.ödev
* @date 19.08.2021
* @author Sümeyye Yaşar 
*/ 

#include "Yigit.hpp"

        Yigit::Yigit(){
			topOfStack=NULL;
		}
		bool Yigit::isEmpty()const{
			return topOfStack==NULL;
		}
		void Yigit::push(const int& item){
			topOfStack=new Node(item,topOfStack);
		}
		void Yigit::pop(){
			//if(isEmpty()) throw hata
			Node *tmp=topOfStack;
			topOfStack=topOfStack->next;
			delete tmp;
		}
		const int& Yigit::top()const{//cıkmak uzere olan eleman dondurur
		//if(isEmpty()) throw hata
		return topOfStack->item;
		}
		void Yigit::makeEmpty(){//önce elemanı yazdırıp sonra pop yapar
			while(!isEmpty()){ 
			cout<<top()<<" ";
			pop();}
		}
		Yigit::~Yigit(){
			makeEmpty();
		}
		



