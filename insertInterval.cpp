/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
 if(intervals.empty()) return {newInterval};
auto it=intervals.begin();
int overlap=0;
while(it!=intervals.end()){
if(newInterval.end<it->start) break;
else if(newInterval.start>it->end) {}
else {
if(newInterval.start>it->start) newInterval.start=it->start;
if(newInterval.end<it->end) newInterval.end=it->end;
++overlap;
}
++it;
}//end while
if(overlap) it=intervals.erase(it-overlap, it);//删除之后原来迭代器失效，返回值要重新赋值
intervals.insert(it,newInterval);
return intervals;       
    }
};