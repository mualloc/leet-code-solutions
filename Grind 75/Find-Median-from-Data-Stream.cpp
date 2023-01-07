// NOTE: https://leetcode.com/problems/find-median-from-data-stream/discuss/286238/Java-Simple-Code-Follow-Up
class MedianFinder {
public:
    /*void addNum(int num) {
        startToMid.push(num);
        midToEnd.push(startToMid.top()); startToMid.pop();
        if(startToMid.size() < midToEnd.size()) { startToMid.push(midToEnd.top()); midToEnd.pop(); }
    }
    double findMedian() {
        if(startToMid.size() == midToEnd.size()) return startToMid.top() + (midToEnd.top() - startToMid.top()) / 2.0;
        else return startToMid.top();
    }*/
      
    void addNum(int num) {
        if(0 == startToMid.size() || num < startToMid.top()){
            startToMid.push(num);
            if(2 == startToMid.size() - midToEnd.size()){
                midToEnd.push(startToMid.top()); startToMid.pop();  
            }
        }else{
            midToEnd.push(num);
            if(midToEnd.size() > startToMid.size()){
                startToMid.push(midToEnd.top()); midToEnd.pop();
            }
        }            
    }
    
    double findMedian() {     
        if(startToMid.size() == midToEnd.size()) return startToMid.top() + (midToEnd.top() - startToMid.top()) / 2.0;
        else return startToMid.top();
    }
    
    // size of startToMid is equal to or greater by one than size of midToEnd.
    priority_queue<int, vector<int>, std::less<int>> startToMid;   // Max heap
    priority_queue<int, vector<int>, std::greater<int>> midToEnd;  // Min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */