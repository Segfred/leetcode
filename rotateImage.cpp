class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
if(matrix.empty()||matrix.size()==1) return;
const size_t len=matrix.size();
for(size_t i=0;i<len;++i){
for(size_t j=i+1;j<len;++j) swap(matrix[i][j],matrix[j][i]);//先转置
reverse(matrix[i].begin(),matrix[i].end());//再左右翻转
}        
    }
};