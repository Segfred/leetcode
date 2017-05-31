class Solution {
public:
    vector<int> grayCode(int n) {
vector<int> rslt{0};
for(int i=0;i<n;++i)  
for(int j=rslt.size()-1;j>=0;--j) rslt.push_back(rslt[j]|(1<<i));//rslt.size(9会变，正向的话就是错的，这题巧了倒着不影响结果，但要注意
return rslt;      
    }
};
