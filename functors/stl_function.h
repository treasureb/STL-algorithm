#ifndef __STL__FUNCTION_H__
#define __STL__FUNCTION_H__

//一元函数都应该继承此基类
template <class Arg,class Result>
struct unary_function{
    typedef Arg     argument_type;
    typedef Result  result_type;
};

//每一个二元函数都应该继承此基类
template <class Arg1,class Arg2,class Result>
struct binary_function{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argumen_type;
    typedef Result result_type;
};

//类似的，STL内建了加、减、乘、除、模、否定
template <class T>
struct negate:public unary_function<T,T>{
    T operator()(const T& x)const{
        return -x;
    }
};

template<class T>
struct plus:public binary_function<T,T,T>{
    T operator()(const T& x,const T& y)const{
        return x+y;
    }
};

#endif  //end of __STL__FUNCTION_H__
