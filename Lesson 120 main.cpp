#include <iostream> 
class A
{
public:
	A(int) { std::cout << "A:: A(int)\n"; }
	A(int, int) { std::cout << "A:: A(int, int)\n"; }
	A(const A&) { std::cout << "A:: A(const A&))\n"; }
	operator bool() const { std::cout << "A:: bool()\n"; return true; }
};
class B
{
public:
	explicit B(int) { std::cout << "B::B(int)\n"; }
	explicit B(int, int) { std::cout << "B::B(int, int)\n"; }
	B(const B&) { std::cout << "B::B(const B&)\n"; }
	explicit operator bool() const { std::cout << "B:: bool()\n"; return true; }
};

int main()
{
	A a1 = 1;     //OK: copy - initialization selects A::A(Ent)
	A a2(2);      //OK: direct-initialization selects A::A(int) 
	A a3{ 4, 5 }; //OK: direct-list-initialization selects A::A(int. int) 
	A a4 = 4.5;   //OK: copy-list-initialization selects A::A(int. int) 
	A a5=(A)1;    //OK: explicit cast performs static_cast 
	
	if (a1);                          // OK: A::operator bool() 
	bool na1 = a1;                    // OK: copy-initialization selects A::operator bool()
	bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization simsm 
	
	//B b1 = 1;    // error: copy-initialization does not consider B::B(int) 
	B b2(2);     // OK: direct-initialization selects B::B(int) 		
	//B b3 4, 5);  // OK: direct-list-initialization selects B::B(int, int) 
	//B b4 [4.5);   // error: copy-list-initialization does not consider B::B(int.int) 
	B b5=static_cast<B>(1);   // OK: explicit cast performs, static_cast 
	if (b2);     // OK: B::operator bool()
	//bool nb1 b2; // error: copy-initialization does not consider B::operator bool() 	
	bool nb2=static_cast<bool>(b2); // OK: static_cast performs direct-initialization
}