//
//  main.cpp
//  combiRecur
//
//  Created by Zhao Tianqi on 2017/04/12.
//  Copyright © 2017年 Zhao Tianqi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void helper(int start, int end, int k, vector<int> &temp, vector<vector<int>> &ret)
{
    if(k==0) ret.push_back(temp);
    else for(int i=start;i<=end-k+1;++i)//表示以1i开始，长度为k的序列
        {
            temp.push_back(i);
            helper(i+1,end,k-1,temp,ret);
            temp.pop_back();
        }
    
}

vector<vector<int> > combine(int n, int k)
{
    vector<vector<int>> rslt{};
    vector<int> item{};
    helper(1,n,k,item,rslt);
    return rslt;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> ret=combine(5,3);
    for(auto &vec:ret)
    {
        for(auto &elem:vec)
            cout<<elem<<" ";
        cout<<endl;
    }

    //std::cout << "Hello, World!\n";
    return 0;
}
