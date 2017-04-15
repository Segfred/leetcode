//
//  main.cpp
//  editDistance
//
//  Created by Asmita on 17/4/15.
//  Copyright (c) 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
typedef string::size_type ssize;

class Solution {
public:
    int minDistance(const string &word1,const string &word2) {
        const ssize length1=word1.length(),length2=word2.length();//suppose l1>l2
        int *pdp=new int[length2+1];
        
        for(ssize i=0;i<=length2;++i) pdp[i]=(int)i;//dp[i][0]=i
        
        for(ssize i=1;i<=length1;++i){
            pnewdp=new int[length2+1];
            pnewdp[0]=(int)i;
            for(ssize j=1;j<=length2;++j)
            {
                if(word1[i-1]==word2[j-1]) pnewdp[j]=pdp[j-1];
                else{
                    pnewdp[j]=min(min(pdp[j-1],pdp[j]),pnewdp[j-1])+1;
                }
            }
            swap(pdp,pnewdp);
        }
        return pdp[length2];
    }
    ~Solution()
    {
        delete pdp;
        delete pnewdp;
    }
private:
    int *pdp;
    int *pnewdp;
};



int main(int argc, const char * argv[]) {
    // insert code here...
    shared_ptr<Solution> psol(new Solution());
    string str1="word",str2="woi";
    cout << psol->minDistance(str1, str2)<<endl;
    return 0;
}