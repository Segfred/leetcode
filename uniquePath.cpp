class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
if(grid.empty()||grid[0].empty()||grid[0][0]) return 0;
const int m=grid.size(), n=grid[0].size();
int dp[n]={1};
for(int i=1;i<n;++i) {if(grid[0][i]) dp[i]=0;else dp[i]=dp[i-1];}//not i<m
for(int i=1;i<m;++i){
if(grid[i][0]) dp[0]=0;
for(int j=1;j<n;++j) dp[j]=grid[i][j]? 0:dp[j-1]+dp[j];
}
return dp[n-1];
    }
};