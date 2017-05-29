//同时找到最小值和最大值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
if(prices.empty()||prices.size()==1) return 0;
int res=0, minEle=prices[0];
for(size_t i=1;i<prices.size();++i){
if(prices[i]<minEle) minEle=prices[i];
if(prices[i]-minEle>res) res=prices[i]-minEle;//max=prices[i]
} 
return res;       
    }
};

//global[i][j]=max(local[i][j],global[i-1][j]);//last transc is today or not，从左往右的话g[i-1][j]就被g[i][j]覆盖了,此时下面的g[i-1][j-1]实际上就变成了g[i-1][j]，因为g[i][j]算的时候前面的都已经知道,g[j-1]是g[i][j]1]
//local[i][j]=max(global[i-1][j-1]+max(dif,0),local[i-1][j]+dif);local[j]=global[j-1],local[j]//要想还是g[i-1][j-1]依旧未知只能从右往左走
//global[j]=local[j],global[j]

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
if(prices.empty()||prices.size()==1) return 0;
if(k>=prices.size()) return stockTwo(prices);
int dif, global[k+1]={0}, local[k+1]={0};//local[prices.size()] wrong size is k

for(int i=1;i<(int)prices.size();++i){
dif=prices[i]-prices[i-1];
for(int j=k;j>=1;--j){//必须倒序,否则global[j-1]是global[i][j-1]而非global[i-1][j-1]
local[j]=max(global[j-1]+max(dif,0),local[j]+dif);// the order cannot be altered//g[i][j-1]
global[j]=max(local[j],global[j]);
}//end of k loop
}// end of prices loop       
return global[k];
    }
private:
int stockTwo(vector<int> &prices){//greedy, unlimited number of trans times
int res=0;
for(size_t i=1;i<prices.size();++i){
if(prices[i]-prices[i-1]>0) res+=prices[i]-prices[i-1];
}
return res;
}
};