/*
   Question Link - https://leetcode.com/problems/peeking-iterator/
   284. Peeking Iterator
*/

/*
   Time Complexity - O(1) for all the functions
   Space Complexity - O(1) 
*/


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums):Iterator(nums){
        has_next=Iterator::hasNext();
	    if(has_next==true){
            nex=Iterator::next(); 
        }     
	}
	
	int peek(){
        return nex;
	}
	
	int next(){
	    int temp=nex;
        has_next=Iterator::hasNext();
        if(has_next)nex=Iterator::next();
        return temp;
	}
	
	bool hasNext()const{
	    return has_next;
	}
    
private:
    int nex;
    bool has_next;
};
