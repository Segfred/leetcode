
//http://zxi.mytechroad.com/blog/hashtable/leetcode-460-lfu-cache/
//用两个哈希表就可以，可以把节点的各种key啊value，freq，位置全部封装在一个node中
//神坑是一定要判断capacity是不是> 0 否则 
class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        minfreq = 0;
    }
    int get(int key) {//查找元素需要更新使用次数和迭代器
        if (data.find(key) == data.end()) {
            return -1;
        }
        freqlist[data[key].fre].erase(data[key].iter);//先删除原来的freq再增加新的，打扫干净屋子再清苦
        ++data[key].fre;
        freqlist[data[key].fre].push_front(key);//新的频率表中push进去
        data[key].iter = freqlist[data[key].fre].begin();//新插入的都在头部，老的直接从尾部删除即可
        //如果原来的是最小频率并且空了就应该修改最小频率
        if (data[key].fre == minfreq + 1 && freqlist[minfreq].empty() ) {
            //不加下面一行也没事，加了只是为了优化空间
            //freqlist.erase(minfreq);//原来的链表也一起删除
            minfreq = data[key].fre;
        }
        return data[key].value;
    }
    
    void put(int key, int value) {
        //非常重要，如果为0的话size == _capacity但其实里面并没有数，会抛出异常。。
        //下面的std::cout 也会打印出来，神坑，因为空的化size会是0
        if (_capacity <= 0) return;
        if (data.find(key) != data.end()) {//使用过的话改一下value就行了，get会自动变频率和移动链表
            data[key].value = value;
            get(key);
            return;
        } else if (data.size() == _capacity) {//因为插入采用头插法，删除直接删除末尾，put实际上不能调用get
            std::cout << "data.size() == _capacity" << std::endl;
            int delekey = freqlist[minfreq].back();
            auto deleiter = data[delekey].iter;
            freqlist[minfreq].erase(deleiter);
            data.erase(delekey);//key或者迭代器都可以erase
        }
        //别忘了更新minfreqq
        minfreq = 1;
        freqlist[1].push_front(key);
        data[key] = {value, 1, freqlist[1].begin()};
    }
private:
    int _capacity;//还有个问题怎么确定频率最小的值
    int minfreq;
    typedef int KEY, VALUE, FRE;
    struct Node {//不需要key，key在哈希表的key中存储就够了
        int value;
        int fre;
        std::list<KEY>::iterator iter;//保存指向频率list的指针
    };
    std::unordered_map<KEY, Node> data;
    std::unordered_map<FRE, std::list<KEY>> freqlist;//每个相同频率对应的节点
};
typedef int KEY,VALUE,FRE;
class LFUCache {
public:
    LFUCache(int capacity):cap_(capacity) {  }  
  int get(int key) {
if(locator.find(key)==locator.end()) return -1;
auto listIte=locator[key];
freq[elements[key].second++].erase(listIte);
if(freq[minfreq_].empty()) ++minfreq_;//influenced by the last put or erase operation,后面set还会调用get   
freq[elements[key].second].push_front(key);//last put or erase on the minfreq_ key,then minfreq_ becomes the current key
locator[key]=freq[elements[key].second].begin();
return elements[key].first;
    }//input must follow elements, fre,locator order
    //delete is on the contrary
    
    void put(int key, int value) {
if(get(key)!=-1) {//least frequency is decided by the key appearning times, not <key,value> pairs
elements[key].first=value;//存在的话只需要替换value,size不会增加
return;
}   
if(elements.size()==cap_){//不存在增加之前要判断是否满了
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
