#ifndef YIGIT_HPP
#define YIGIT_HPP

#include "Node.hpp"
class Yigit{
	private:
		Node *topOfStack;
		
		
	public:
		Yigit();
		bool isEmpty()const;
		void push(const int& );
		void pop();
		const int& top()const;
		void makeEmpty();
		~Yigit();
		//makeEmpty yığıt yapısını yok etmez ama yıkıcıyı çağırınca yıgı nesnesi ortadan kalkar
};




#endif