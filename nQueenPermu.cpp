#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> rslt{};
    vector<int> num(n,0);
    for(int i=1;i<n;++i) num[i]=i;
    helper(rslt,num,0);
    return rslt;
    }
private:
    bool isValid(const vector<int> &num, int start)
{
    for(int k=0;k<start;++k)
        if(start-k==abs(num[start]-num[k])) return false;
    return true;
}
void helper(vector<vector<string>> &ret,vector<int> &num, int start)
{
    int len=(int)num.size();
    if(start==len)
    {
        vector<string> item(len,string(len,'.'));
        for(int i=0;i<len;++i) item[i][num[i]]='Q';
        ret.push_back(item);
    }
    else for(int j=start;j<len;++j)
    {
        swap(num[start],num[j]);
        if(isValid(num,start)) helper(ret,num,start+1);
        swap(num[start],num[j]);
    }        
}
};