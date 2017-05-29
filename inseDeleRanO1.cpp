typedef int VAL;
typedef size_t INDEX;
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
nums.clear();
hmap.clear();        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
hmap[val].insert(nums.size());
nums.emplace_back(val);
return hmap[val].size()==1;        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
if(hmap[val].empty()) return false;//hmap.count(val)错误，需要遍历map,线性，非O(1)
INDEX pos=*hmap[val].begin();
hmap[val].erase(pos);
if(val!=nums.back()){
//VAL last=nums.back();
nums[pos]=nums.back();// do NOt forget this step
hmap[nums[pos]].erase(nums.size()-1);
hmap[nums[pos]].insert(pos);
}
nums.pop_back();
return true;       
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
if(nums.empty()) return 0;
return nums[rand()%nums.size()];        
    }
private:
vector<VAL> nums;
unordered_map<VAL,unordered_set<INDEX>> hmap;
};




/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */