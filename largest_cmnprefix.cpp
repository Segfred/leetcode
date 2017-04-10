//
//  main.cpp
//  comsubstr
//
//  Created by Asmita on 2017/03/17.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        
        if (strs.empty()) return "";
        size_t n=strs.size();
        string prefix=strs[0];
        for(size_t i=1;i<n;++i)
        {
            if(prefix.length()==0||strs[i].length()==0)
                return "";
            size_t cursize=prefix.length()<strs[i].length()?prefix.length():strs[i].length();
            size_t j;
            for(j=0;j<cursize;++j)
            {
                if(prefix[j]!=strs[i][j]) break;
            }
            prefix=prefix.substr(0,j);
        }
        return prefix;
    }
};

int main(int argc, const char * argv[]) {
    string sub="sub",sb="sb";
    vector<string> vstr{sub,sb};
    Solution so;
    cout << so.longestCommonPrefix(vstr)<<endl;
    return 0;
}
