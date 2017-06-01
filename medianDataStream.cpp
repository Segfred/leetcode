class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {       
    }
    
    void addNum(int num) {
if(maxheap.empty()) {maxheap.push(num); return;}
if(num<=maxheap.top()) maxheap.push(num);
else minheap.push(num);

if(minheap.size()+2==maxheap.size()){
minheap.push(maxheap.top());
maxheap.pop();
}        
else if(minheap.size()==maxheap.size()+1){
maxheap.push(minheap.top());
minheap.pop();
}
    }
    
    double findMedian() {
if(maxheap.empty()) return 0;
if(minheap.size()<maxheap.size()) return maxheap.top();
else return (double)(minheap.top()+maxheap.top())/2;       
    }

private:
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
};