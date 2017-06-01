
class Solution {
public:
typedef size_t START, STEP, LEFT, SIZE;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
SIZE s1=nums1.size(), s2=nums2.size(), sum=s1+s2;
if(sum&0x1) return getK(nums1,nums2,0,0,s1,s2,sum/2+1);
else   return (getK(nums1,nums2,0,0,s1,s2,sum/2)+getK(nums1,nums2,0,0,s1,s2,sum/2+1))/2;      
    }
private:
double getK(const vector<int> &vec1, const vector<int> &vec2, START st1, START st2, int left1, int left2, int k){//k是第几，不是下标
if(left1>left2) return getK(vec2, vec1, st2, st1, left2, left1, k);
if(left1==0) return vec2[st2+k-1];
if(k==1) return min(vec1[st1], vec2[st2]);
STEP pa=min(k/2,left1), pb=k-pa;//拿出pa个数来比较，实际上前进了pa-1，新的起点才跳了pa，注意下标
if(vec1[st1+pa-1]<vec2[st2+pb-1]) return getK(vec1, vec2, st1+pa, st2, left1-pa, left2, k-pa);
else if (vec1[st1+pa-1]>vec2[st2+pb-1]) return getK(vec1,vec2,st1,st2+pb,left1,left2-pb,k-pb);
else return vec1[st1+pa-1];
}
};


class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }
    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findKth(nums2, nums1, k);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int i = min(m, k / 2), j = k-i;
        if (nums1[i - 1] > nums2[j - 1]) {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        } else {
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
        }
        return 0;
    }
};