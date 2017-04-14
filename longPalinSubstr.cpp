
//  main.cpp
//  longestPalinSunstr
//
//  Created by ASMITA on 2017/04/14.
//  Copyright © 2017年 Asmita. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string longestPalindrome(const string &str)
    {
        rslt_="";
        if(str.empty()) return rslt_;
        //if(str.length()==1) return str;
        const size_t len=str.length();
        for(int i=0;i<len-1;++i)//IMPLIES LEN>1,so consider when
        {
            sprdFromMid(str,i,i);
            sprdFromMid(str,i,i+1);//i cannot be len-1
        }
        return rslt_;        
    }
    
private:
    string rslt_;
    void sprdFromMid(const string &str, size_t left, size_t right)
    {//must pass all the string, not ONLY a char
        while((left+1)>0&&right<=str.length()-1&&str[left]==str[right])
            //check not surpass the border
        {  //from left+1 to right -1,count=(right-1)-(left+1)+1=right-left-1
            --left;
            ++right;
        }
        if (rslt_.length()<=right-left-1) rslt_=str.substr(left+1,right-left-1);
        
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    string str{"A"};
    cout <<sol.longestPalindrome(str)<<endl;
    return 0;
}
