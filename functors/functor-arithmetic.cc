#include<iostream>
#include<functional>
using namespace std;

int main( void ){
    //先生成一个仿函数对象
    plus<int> plusobj;
    minus<int> minusobj;
    multiplies<int> multipliesobj;
    divides<int> dividesobj;
    modulus<int> modulusobj;
    negate<int> negateobj;

    //使用对象,执行函数功能
    cout<<plusobj(3,5) <<endl;
    cout<<minusobj(3,5) <<endl;
    cout<<multipliesobj(3,5) <<endl;
    cout<<dividesobj(3,5) <<endl;
    cout<<modulusobj(3,5) <<endl;
    cout<<negateobj(3) <<endl;

    //直接生成一个临时对象，然后执行函数功能
    //语法:functor<T>()是一个临时对象，然后后面再跟个()
    cout<<plus<int>()(3,5)<<endl;
    cout<<minus<int>()(3,5)<<endl;
    cout<<multiplies<int>()(3,5)<<endl;
    cout<<divides<int>()(3,5)<<endl;
    cout<<modulus<int>()(3,5)<<endl;
    cout<<negate<int>()(3)<<endl;
}
