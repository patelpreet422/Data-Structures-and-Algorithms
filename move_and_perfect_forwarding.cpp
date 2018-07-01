#include <iostream>
#include <type_traits>
using namespace std;

template<class T>
void process(T&& t)
{
	cout << "template: Process says" << '\n';
	cout << "is lvalue: " << boolalpha << is_lvalue_reference_v<T> << '\n';
}

template<class T>
void func(T&& t)
{
	cout << "template: Func says" << '\n';
	cout << "is lvalue: " << boolalpha << is_lvalue_reference_v<T> << '\n';
	process(forward<T>(t));
	//process(t);
}


void process_auto(auto&& t)
{
	cout << "auto: Process says" << '\n';
	cout << "is lvalue: " << boolalpha << is_lvalue_reference_v<decltype(t)> << '\n';
}

void func_auto(auto&& t)
{
	cout << "auto: Func says" << '\n';
	cout << "is lvalue: " << boolalpha << is_lvalue_reference_v<decltype(t)> << '\n';
	process_auto(forward<decltype(t)>(t));
	//process_auto(t);
}

int main()
{
	/*
		move doesn't move 
		and 
		forward doesn't forward
		They are basically rvalue_casts so to say.
		forward is a conditional cast 
		and
		move will cast lvalue to rvalue
		but to leverage the benefits of move
		class whose object needs to be moved must have implementation
		of move assignment operator and
		move ctor
		
		NOTE: auto type deduction is same as template type deduction except some special cases
	*/
	int x = 36;
	func_auto(move(x));
	//func_auto(x);
	func(move(x));
	//func(x);
	
	return 0;
}
