//http://www.cnblogs.com/grandyang/p/4587511.html
//http://www.jianshu.com/p/14f6db6ebfc5
//  main.cpp
//  LRU
//forward_list不行，没有splice函数
//  Created by Asmita on 17/5/10.forward.end()也是o(1)复杂度
//  Copyright (c) 2017年 Asmita. All rights reserved.
//
//https://blog.csdn.net/juzihongle1/article/details/77930820 看这个链接比较简洁，不用什么splice函数，直接调用put，怎么记忆呢？
//get也需要调用put函数，因为get也需要修改原来的数据结构，用list存数据或者单独哈希表都可以，但是用哈希表的话还要单独专门删除两次比较麻烦
//首先上一道错误解法
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto iter = pos.find(key);
        if (iter != pos.end()) {//可以直接用pos[key]
            int value = iter->second->second;
            put(key, value);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (lst.size() == _capacity) {//这里有问题，如果存在的话size不用变大，所以最开始需要判断的是里面是否已经存在了
            auto tail = lst.back().first;//key, 非value
            lst.pop_back();
            pos.erase(tail)
        } else {//这里错了，不论是否超过大小限制都需要判断
            auto iter = pos.find(key);
            if (iter != pos.end()) {
                lst.erase(iter->second);//list迭代器位置
                pos.erase(iter);
            }
        }
        lst.push_front({key, value});
        pos[key] = lst.begin();
    }
private:
    int _capacity;
    std::list<std::pair<int, int>> lst;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> pos;
};
正确的如下：
class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto iter = pos.find(key);
        if (iter != pos.end()) {
            int value = iter->second->second;
            put(key, value);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto iter = pos.find(key);
        if (iter != pos.end()) {
            lst.erase(iter->second);//list迭代器位置
            pos.erase(iter);
        }
        if (lst.size() == _capacity) {//判断大小一定要是删除数据之后，否则没满就删了会造成数据不对，该查到的没查到，一定要注意顺序
            auto tail = lst.back().first;//虽然从工程的角度没问题，但是算法的角度要注意各种边界条件
            lst.pop_back();
            pos.erase(tail);
        }         
        lst.push_front({key, value});
        pos[key] = lst.begin();
    }
private:
    int _capacity;
    std::list<std::pair<int, int>> lst;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> pos;
};

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

typedef list<pair<int,int>> LST;
class LRUCache {
public:
    LRUCache(int capacity):cap_(capacity) {
}

int get(int key) {
    auto ite=umap.find(key);
    //auto ite=find(umap.begin(),umap.end(),key);
    if(ite==umap.end()) return -1;
    lst_.splice(lst_.begin(),lst_,ite->second);
    return ite->second->second;
}//把lst_中的ite->second个位置搬到lst_.begin()地方去

void put(int key, int value) {
    auto ite=umap.find(key);
    //auto ite=find(umap.begin(),umap.end(),key);//按照value查找，是错的
    if(ite!=umap.end()){
        lst_.erase(ite->second);
        //umap.erase(ite->first); no need, assignment will happen later to cover the original mapping
    }
    lst_.push_front(make_pair(key,value));//NOT make_pair<key,value>
    umap[key]=lst_.begin();
    if(lst_.size()>cap_) {
        umap.erase(lst_.rbegin()->first);//pay attention to the method of dealing with the last element,lst_.back().first也行
        lst_.pop_back();
    }
}

private:
int cap_;
LST lst_;
unordered_map<int,LST::iterator> umap;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
