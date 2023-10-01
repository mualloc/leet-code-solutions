class FreqStack {
public:
    // TC: O(1)
    void push(int val) {
        history[++freqs[val]].push(val);
        max_freq = max(max_freq, freqs[val]);
    }
    // TC: O(1)
    int pop() {
        int val = history[max_freq].top();
        history[max_freq].pop();
        --freqs[val];
        if(0 == history[max_freq].size()) --max_freq;
        return val;
    }
private:
    int max_freq{0};
    unordered_map<int, int> freqs;
    unordered_map<int, stack<int>> history;    // freq, corresponding values
};


class FreqStack2 {
public:
    // TC: O(logN)
    void push(int val) {
        history.push({++freqs[val], ++time_stamp, val});
    }
    // TC: O(logN)
    int pop() {
        const auto [freq, time_stamp, val] = history.top(); history.pop();
        --freqs[val];
        return val;
    }
private:
    int time_stamp{0};
    unordered_map<int, int> freqs;
    priority_queue<tuple<int, int, int>> history;    // freq, push order, value
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
