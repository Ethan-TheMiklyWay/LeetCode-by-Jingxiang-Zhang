Maximum Frequency Stack - Hard

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
 

Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].


class FreqStack {
public:
    int maxfreq = 0;
    map<int,int> freq; // number->frequency
    map<int,stack<int>> group; // frequency->number_list
    
    FreqStack() {
        
    }
    
    void push(int val) {
        auto iter = freq.find(val);
        int f;
        if(iter==freq.end()){
            freq[val] = 1;
            f=1;
        }
        else{
            f = iter->second+1;
            iter->second = f;
        }
        if(f>maxfreq)
            maxfreq = f;
        auto it = group.find(f);
        if(it==group.end()){
            stack<int> st;
            st.push(val);
            group[f] = st;
        }
        else{
            it->second.push(val);
        }
    }
    
    int pop() {
        auto it = group.find(maxfreq);
        int x = it->second.top();
        it->second.pop();
        freq[x] -= 1;
        if(it->second.empty())
            maxfreq -= 1;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */