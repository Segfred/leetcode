class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
if(matrix.empty()||matrix[0].empty()) return;
size_t m=matrix.size(),n=matrix[0].size();
bool rowZero=false,colZero=false;
for(size_t i=0;i<m;++i){
if(!matrix[i][0]) {colZero=true;break;}
}      //end of for

for(size_t j=0;j<n;++j)
if(!matrix[0][j]){rowZero=true;break;}

//end of for loop
//wrong rowZero=true,return;
//}
for(size_t i=1;i<m;++i)
  for(size_t j=1;j<n;++j)
  if(!matrix[i][j]) matrix[i][0]=0,matrix[0][j]=0;
 

for(size_t i=1;i<m;++i)
  for(size_t j=1;j<n;++j)
  if(!matrix[i][0]||!matrix[0][j]) matrix[i][j]=0;
  
if(colZero) 
for(size_t i=0;i<m;++i) matrix[i][0]=0;
if(rowZero)
for(size_t j=0;j<n;++j) matrix[0][j]=0;

    }//end of function
};


