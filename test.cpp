#include<iostream>
#include<vector>
#include<string>
using namespace std;

class A{
    public:
    A(){}
    A(int a){
        this->a = a;
        cout << "A constructor" << endl;
    }
    virtual void fun(){

    }
    int a;
};

class B: public A{
    public:
        B(int a,int b): A(a){
            this->b = b;
            cout << "B constructor" << endl;
        }
        int b;
};

class C{
    public:
        C(){
            this->c = 1;
        }
        int c;
        virtual void fun(){

    }
};


int main()
{
    A * a = new A(0);
    B * b;
    C * c = new C();
    b = static_cast< B *>(c);
    if(b){
        cout << b->b << endl;
    }
    return 0;
}