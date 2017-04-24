//  main.cpp
//  retriveLongestIncreSequ
//
//  Created by Asmita on 2017/04/15.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> printLongestIncreasStr(const vector<int> &nums) //return the assiatance dp
{
    vector<int> dp(nums.size());// dp[i] denotes the length of the longest increasing string indexed by i
    if(nums.empty()) return dp;
    vector<int> help{};//current array with the biggest potential to compose the LIS
    help.push_back(nums[0]),dp[0]=1;//help[0]=nums[0] is wrong, since help is uninitialized
    for(size_t i=1;i<nums.size();++i)
    {
        if(help.back()<nums[i])//current value is the maximum so dp[i]=help.size()
        {
            help.push_back(nums[i]);
            dp[i]=(int)help.size();
        }
        else {
            auto ite=lower_bound(help.begin(),help.end(),nums[i]);
            *ite=nums[i],dp[i]=int(ite-help.begin()+1);
        }
        
    }//end of for loop
    return dp;
}

vector<int> retriTheString(const vector<int> &dp, const vector<int> &nums)
{
    int maxlen=0;
    size_t index=0;
    for(size_t j=0;j<dp.size();++j)
        if(dp[j]>maxlen) {maxlen=dp[j],index=j;}
    vector<int> rslt(maxlen);
    rslt[--maxlen]=nums[index];
    for(size_t k=index-1;(k+1)>0;--k)// the second number to push_back must be in the front
    {//track from back to front so that the sequence can be in order
        if(nums[k]<nums[index]&&dp[k]==dp[index]-1){
            rslt[--maxlen]=nums[k];
            index=k;}
    }
    return rslt;
}

int main(int argc, const char * argv[]) {
    vector<int>n = {4,2,4,5,3,7};
    vector<int>dp = printLongestIncreasStr(n);
    vector<int>result = retriTheString(dp, n);
    //for(auto &dpel:dp) cout<<dpel<<" ";
    //cout<<endl;
    for (auto &c:result) cout<<c<<",";
    cout<<endl;
    return 0;
}
