class Solution {
public:
    int trap(vector<int>& height) {
if(height.empty()||height.size()<=2) return 0;
size_t l=0,r=height.size()-1;
int res=0;
while(l<r)
{
if(height[l]<=height[r]){
int min=height[l];
++l;
while(l<r&&height[l]<min) res+=min-height[l++];
  }
else {
int min=height[r];
--r;
while(l<r&&height[r]<min) res+=min-height[r--];
  }
}   
return res;     
    }
};



