//
//  main.cpp
//  longestIncreStr
//
//  Created by Asmita on 2017/04/15.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp{};
        for(size_t i=0;i<nums.size();++i)
        {
            if(dp.empty()||dp.back()<nums[i]) dp.push_back(nums[i]);
            else *lower_bound(dp.begin(),dp.end(),nums[i])=nums[i];
        }
        return (int)dp.size();
        
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    shared_ptr<Solution> psol(new Solution());
    vector<int> vec{1,3,5,7,5,8,5,9};
    cout << psol->lengthOfLIS(vec)<<endl;
    return 0;
}
