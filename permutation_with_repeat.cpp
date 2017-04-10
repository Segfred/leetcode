//
//  main.cpp
//  permutation
//
//  Created by Asmita on 2017/03/19.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result{};
        allrange(nums,0,result);
        return result;
    }
private:
    void allrange(vector<int>& nums, size_t start, vector<vector<int>>& tempresult)
        {
            if(nums.empty()) return;
            size_t n= nums.size();
            if(start==n)
                tempresult.push_back(nums);
            else
            {
                for(size_t i=start;i<n;++i)//attention, here must be n-1, INSTEAD of n
                {
                    if(canSwap(nums, start, i))
                    {
                        swap(nums[i],nums[start]);
                        allrange(nums, start+1, tempresult);// end of all the arrangements staring with a char, e.g. bac,bca
                        swap(nums[i],nums[start]);//back tracking, return to the original order before trying the next arrangement
                    }//after recovery, the order is still abc, and the next step is to swap ac, to get the cba,cab arrangement
                    
                }
            }
        }

    bool canSwap(vector<int>& nums, size_t start, size_t cur)
    {
        for (size_t i=start;i<cur;++i)
        {
            if(nums[i]==nums[cur]) return false;
        }
        return true;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> somevec{1,2,2,3};
    Solution sol;
    vector<vector<int>> finresult= sol.permuteUnique(somevec);
    for(auto &elem:finresult)
    {
        for(auto &singlelem:elem)
            cout<<singlelem<<" ";
        cout<<endl;
    }
    return 0;
}
