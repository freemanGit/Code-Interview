#include <iostream>

class Base1 {
	public:
	void display(){ std :: cout <<"Base1 display()|"; };
	~Base1() { std::cout <<"Base1 destructor()\n"; }
};
class Derived1 : public Base1 {  //if use 'private': Base1 is an inaccessible base of 'Derived1'
	public:
	void display(){ std :: cout <<"Derived1 display()|"; };
	~Derived1() { std::cout <<"Derived1 destructor()\n"; }
};

class Base2 {
	public:
	virtual void display(){ std :: cout <<"Base2 display()|"; };;
	virtual ~Base2() { std::cout <<"Base2 destructor()\n"; }
};
class Derived2 : public Base2 {
	public:
	void display(){ std :: cout <<"Derived2 display()|"; };;
	~Derived2() { std::cout <<"Derived2 destructor()\n"; }
};



int main() {
	Base1* bs1 = new Base1;
	bs1 -> display();
	delete bs1;
	
	Base2* bs2 = new Base2;
	bs2 -> display();
	delete bs2;
	
	Base1* bp = new Derived1;
	bp->display();
	delete bp; //base1 not virtual destructor, derived class not deallocated..
	
	Base2* b2p = new Derived2;
	b2p->display();
	delete b2p;
} 

/* Out put:
 Base1 display()|Base1 destructor()
 Base2 display()|Base2 destructor()
 Base1 display()|Base1 destructor()
 Derived2 display()|Derived2 destructor()
 Base2 destructor() 

*/