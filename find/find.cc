#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool if_odd(int i ){
    return ((i % 3) == 0);
}

void test_binary_search(vector<int>& v){
    sort(v.begin(),v.end());
    vector<int>::iterator low,up;
    bool is_exist = false;
    /* 第一个不小于给定元素的下标 */
    low = lower_bound(v.begin(),v.end(),20);

    /* 第一个大于给定元素的位置 */
    up  = upper_bound(v.begin(),v.end(),20);

    /* 二分查找,返回值为bool */
    is_exist = binary_search(v.begin(),v.end(),20);

    cout<<"lower_bound at positon:"<<(low-v.begin())<<endl;
    cout<<"upper_bound at positon:"<<(up-v.begin())<<endl;
    cout<<"binary_search result:"<<is_exist<<endl;

}

void test_find(vector<int>& v){

    /* find_if可以自定义比较函数 */
    vector<int>::iterator it = find_if(v.begin(),v.end(),if_odd);
    cout<<"The first odd value is :"<<*it<<endl;


}

void test_count(vector<int>& v){

    /* count可以统计单个数据在集合中出现的次数 */
    int c = count(v.begin(),v.end(),4);
    cout<<"The 4 count is : "<<c<<endl;

    /* count可以自定义比较函数 */
    c = count_if(v.begin(),v.end(),if_odd);
    cout<<"The odd count is : "<<c<<endl;

}

void test_search(vector<int>& v){
    /* 4连续出现2次的位置 */
    vector<int>::iterator it = search_n(v.begin(),v.end(),2,4);
    cout<<"The 4s found is position : "<<it - v.begin()<<endl;

}


void test_max_min(vector<int>& v){
    vector<int>::iterator max,min;
    max = max_element(v.begin(),v.end());
    min = min_element(v.begin(),v.end());

    cout<<"The max is : "<<*max<<endl;
    cout<<"The min is : "<<*min<<endl;

}
/***************************************************************************************/
/* 区间查找 */

bool my_predict(int i ,int j){
    return i == j;

}

void test_section(vector<int>& v){
    vector<int> section = {1,2};
    vector<int>::iterator first,end;

    /* 子区间第一次出现的地方 */
    first = search(v.begin(),v.end(),section.begin(),section.end());
    cout<<"The section first is : "<<first-v.begin()<<endl;

    /* 子区间最后一次出现的地方 */
    end = find_end(v.begin(),v.end(),section.begin(),section.end());
    cout<<"The section end is : "<<end-v.begin()<<endl;

    /* 判断两个区间是否相等 */
    bool result = false;

    /* 判断两个区间是否相等 */
    result = equal(v.begin(),v.end(),section.begin());
    cout<<"The expect is false : "<<result<<endl;

    vector<int> vec = {1,2};
    /* 可以自定义比较函数 */
    result = equal(vec.begin(),vec.end(),section.begin(),my_predict);
    cout<<"The expect is true : "<<result<<endl;


    /* 两个区间第一个不同的位置及数字，返回值是pair,支持自定义比较 */
    vector<int> diff = {1,2,3,5,6,7};
    pair<vector<int>::iterator,vector<int>::iterator> my_pair;
    my_pair = mismatch(v.begin(),v.end(),diff.begin());
    cout<<"The two section first diff position is : "<<*my_pair.first<<endl;
    cout<<"The two section first diff num is : "<<*my_pair.second<<endl;

}

/*************************************************************************************/
/* 集合查找 */

void test_assemble(){
    vector<char> vec = {'a','b','c','d','A','B','f'};
    vector<char> section = {'A','B','C'};

    /* 查找一个区间内任一数据第一次出现的位置 */
    vector<char>::iterator it = find_first_of(vec.begin(),vec.end(),section.begin(),section.end());
    cout<<"The section anyone postion is : "<<it-vec.begin()<<endl;

}

int main(){
    vector<int> v = {1,2,3,4,4,5,5,6,7,1,2};
    /* test_binary_search(v); */
    /* test_find(v); */
    /* test_count(v); */
    /* test_search(v); */
    /* test_max_min(v); */
    /* test_section(v); */
    test_assemble();
    return 0;

}
