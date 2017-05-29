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
//换i元一定是和前面某一种i-k+k组合起来的，如果前面都知道的话，至于和前面哪个组合起来遍历可用钱币就行了