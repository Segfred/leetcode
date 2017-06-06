class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
if(matrix.empty()||matrix[0].empty()) return false;
const size_t m=matrix.size(), n=matrix[0].size();
if(target<matrix[0][0]||target>matrix[m-1][n-1]) return false;//先和边角比较，不行直接返回
size_t left=0,right=m-1, mid;
while(left<=right){
mid=(left+right)/2;
//if(matrix[mid][0]==target) return true;
if(target==matrix[left][0]||target==matrix[right][0]||matrix[mid][0]==target) return true;
else if(target<matrix[mid][0]) right=mid-1;
else left=mid+1;
}    
size_t curRow=right;//not left
left=0, right=n-1;
while(left<=right){
mid=(left+right)/2;
if(target==matrix[curRow][mid]||target==matrix[curRow][left]||target==matrix[curRow][right]) return true;
else if(target<matrix[curRow][mid]) right=mid-1;
else left=mid+1;
}
return false;
    }
};
