class MedianFinder {
public:
    /** initialize your data structure here. */
    int n;
    double med;
    multiset<int> l , r;
    MedianFinder() {
        n = 0;
        med = 0;
    }
    
    void balance() {
        
        while(l.size() > 0 && r.size()>0 && (*l.rbegin() > (*r.begin()))) {
            int u = *l.rbegin();
            int v = *r.begin();
            l.erase(l.find(u));
            r.erase(r.find(v));
            l.insert(v);
            r.insert(u);
        }
        while(l.size() > (n+1)/2) {
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }
        while(r.size() > n/2) {
            l.insert(*r.begin());
            r.erase(r.find(*r.begin()));
        }
        
        if(n & 1) med = *l.rbegin();
        else {
            med = (*l.rbegin() + *r.begin());
            med /=2;
        }
    }
    void addNum(int num) {
        l.insert(num);
        ++n;
        
        balance();
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
