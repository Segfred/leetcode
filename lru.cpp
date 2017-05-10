//http://www.cnblogs.com/grandyang/p/4587511.html
//http://www.jianshu.com/p/14f6db6ebfc5
//  main.cpp
//  LRU
//
//  Created by Asmita on 17/5/10.
//  Copyright (c) 2017年 Asmita. All rights reserved.
//

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
}

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
        umap.erase(lst_.rbegin()->first);//pay attention to the method of dealing with the last element
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
