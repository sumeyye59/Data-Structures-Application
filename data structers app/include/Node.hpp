#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <cmath>
#include<stdlib.h>
using namespace std;
//yığıtın düğüm sınıfı
class Node{
	public:
		int item;
		Node *next;
		
		Node(const int&,Node*);
		Node(const int&);
	
};
#endif