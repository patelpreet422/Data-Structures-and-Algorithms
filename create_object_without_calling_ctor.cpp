#include <iostream>
using namespace std;
struct Base 
{
    //if you remove virtual program will not compile
    virtual void bf()
    {
        cout << "Base\n";
    }
}; 
struct Derived : public Base 
{
    //all the paths through which Derived can be constructed are deleted so in theory you can't create object of Derived
    Derived() = delete;
    Derived(const Derived&) = delete;
    Derived& operator=(const Derived&) = delete;
    Derived& operator=(Derived&&) = delete;
    
    void df()
    {
        cout << "Derived\n";
    }
}; 
int main() 
{ 	
    Base *b = new Base; 
    //even static_cast will do
    Derived *pd = dynamic_cast<Derived*>(b);
    //now b has been casted to Derived so bf is not visible to Derived
    pd->df();
    return 0; 
}
