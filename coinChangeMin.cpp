class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
if(amount==0) return 0;
if(coins.empty()) return -1;
vector<int> dp(amount+1,amount+1);
dp[0]=0;//换0元最小需要0种硬币
for(int i=1;i<=amount;++i){
for(size_t j=0;j<coins.size();++j)//遍历可用钱币，看和谁组合起来
if(coins[j]<=i) dp[i]=min(dp[i],dp[i-coins[j]]+1);
}       
return dp[amount]==amount+1? -1:dp[amount];
    }
};