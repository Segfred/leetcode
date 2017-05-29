typedef int KEY,VALUE,FRE;
class LFUCache {
public:
    LFUCache(int capacity):cap_(capacity) {  }  
  int get(int key) {
if(locator.find(key)==locator.end()) return -1;
auto listIte=locator[key];
freq[elements[key].second++].erase(listIte);
if(freq[minfreq_].empty()) ++minfreq_;//influenced by the last put or erase operation    
freq[elements[key].second].push_front(key);//last put or erase on the minfreq_ key,then minfreq_ becomes the current key
locator[key]=freq[elements[key].second].begin();
return elements[key].first;
    }//input must follow elements, fre,locator order
    //delete is on the contrary
    
    void put(int key, int value) {
if(get(key)!=-1) {
elements[key].first=value;
return;
}   
if(elements.size()==cap_){
KEY temp=freq[minfreq_].back();
locator.erase(temp);
freq[elements[temp].second].pop_back();
elements.erase(temp);
}
elements[key]={value,1};//key has not been found so its freq is 1
freq[1].push_front(key);
locator[key]=freq[1].begin();
minfreq_=1;
    }
private:
int cap_;
int minfreq_;
unordered_map<KEY,pair<VALUE,FRE>> elements;
unordered_map<FRE,list<KEY>> freq;//whose <KEY,VALUE,FRE> 里的FRE全是当前FRE
unordered_map<KEY,list<KEY>::iterator> locator;
};
