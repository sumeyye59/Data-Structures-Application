/** 
* @description Kisiler.txt'ten kisi bilgilerini okuyup kişi nesnesine yazar ve kişi nesnelerinide boya göre avl ağacına atar.
Ağacı levelorder yazdırıken her düğümün yükseklik ve derinlik yığıtlarının elemanlarını yazdırıp pop edecek.
* @date 19.08.2021
* @author Sümeyye Yaşar 
*/ 

#include "Node.hpp"
		
		Node::Node(const int& item,Node *next=NULL){
				this->item=item;
				this->next=next;
		}
		Node::Node(const int& item){
			this->item=item;
			this->next=NULL;
		}
	
