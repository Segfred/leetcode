//http://bangbingsyb.blogspot.jp/2014/11/leetcode-4sum.html
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> solutions{};
        vector<int> item{};
        size_t l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());// do NOT foeget to sort
        kSum(nums,item,solutions,l,r,target,4);
        return solutions;
    }
private:
    void kSum(vector<int> &nums, vector<int> &sol, vector<vector<int>> &allSol, size_t start, size_t end, int target, int k){
        if(k==2) {
            twoSum(nums,sol,allSol,start,end,target);
            return;
        }
        
        for(size_t i=start;i<=nums.size()-k;++i){//NOT nums.size()-1，下面是选开头元素，开头元素不能重复
            if(i>start&&nums[i]==nums[i-1]) continue;//do NOT forget depulicate handling，虽然可以1，1，2，3但因为在同一组，比如选第3个数2
            sol.push_back(nums[i]);//出现了一次2，下次就是一样的了，比如1，1，2，2，3最后只有1，1，2，3是组内同一index不能重复，组内不同index
            kSum(nums,sol,allSol,i+1,end,target-nums[i],k-1);//可以重复
            sol.pop_back();
        }
    }
        void twoSum(vector<int> &nums, vector<int> &sol, vector<vector<int>> &allSol, size_t start, size_t end, int target){
            size_t left=start,right=end;//no need for coping indexes
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum==target){
                    sol.push_back(nums[left]);
                    sol.push_back(nums[right]);
                    allSol.push_back(sol);
                    sol.pop_back();//腾出位置让sol加别的
                    sol.pop_back();
                    ++left;// another equal sums must be within the original之前两边和想等了已经，新的相等必//须至少同时往内部进一步，只进一边肯定不相等
                    --right;//
                    while(left<right&&nums[left]==nums[left-1]) ++left;
                    while(left<right&&nums[right]==nums[right+1]) --right;
                }//end of if
                else if(sum<target) ++left;//必须要缩小范围，只能往里面走，不能往外(++right)
                else --right;
            }// end of while        
        }// end of twoSum
        
    };
