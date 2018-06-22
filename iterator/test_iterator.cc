#include<iostream>
#include<vector>
#include<list>
using namespace std;

/*
 *  迭代器失效的几种情况
 *  1.关联式容器(vector)
 *     a)当进行扩容操作时，所有迭代器都会失效
 *     b)当进行erase(iterator)时,会时当前节点的迭代器失效
 *       采用it=erase(it)的操作,保存返回的迭代器
 *
 *  2.链表
 *     a)因为erase会返回待删除节点的迭代器，所以可以采用保存
 *     b)由于每个节点间互不影响,所以可以采用erase(it++),在删除之前进行++
 *  3.关联式容器(红黑树)
 *     a)erase返回void，所以只能采用erase(it++)
 */

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    list<int>::iterator lt = l.begin();
    vector<int>::iterator vt = v.begin();

#ifdef __LIST__
    while(lt != l.end()){
        if(*lt % 2 == 0)
        {
            l.erase(lt++);
        }
        ++lt;
    }

    lt = l.begin();
    while(lt != l.end()){
        cout<<*lt <<" ";
        ++lt;
    }
#endif 

#ifdef __VECTOR__    
    while(vt != v.end()){
        if(*vt % 2 == 0)
        {
            v.erase(lt++);
        }
        ++vt;
    }
    vt = v.begin();
    while(vt != v.end()){
        cout<<*vt<<" ";
    }
#endif

    return 0;
}
