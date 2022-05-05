/*
   Question Link - https://leetcode.com/problems/implement-stack-using-queues/
   225. Implement Stack using Queues
*/

/*
   Time Complexity - O(N) for push operation, O(1) for pop(), O(1) for top(), O(1) for empty()
   Space Complexity - O(N)
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x){
        while(q1.empty()==false){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.empty()==false){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop(){
        int temp=q1.front();
        q1.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top(){
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty(){
        if(q1.size()==0){
            return true;
        }
        return false;
    }
};