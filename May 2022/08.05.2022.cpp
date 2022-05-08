/*
   Question Link - https://leetcode.com/problems/flatten-nested-list-iterator/
   341. Flatten Nested List Iterator 
*/

/*
   APPROACH-1
   Time Complexity - O(N) where N is number of integers in nestedList 
   Space Complexity - O(N) where N is is number of integers in nestedList
*/

class NestedIterator {
public:
    vector<int> flattened_List;
    int ptr=0;
    
    void flatten(vector<NestedInteger> &nestedList){
        for(int i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger()==true){
                flattened_List.push_back(nestedList[i].getInteger());
            }else{
                flatten(nestedList[i].getList());
            }
        }
        return;
    }
    
    NestedIterator(vector<NestedInteger> &nestedList){
        flatten(nestedList);
    }
    
    int next(){
        ptr++;
        if(ptr<=flattened_List.size()){
            return flattened_List[ptr-1];
        }
        return -1;  
    }
    
    bool hasNext(){
        if(ptr<flattened_List.size()){
            return true;
        }
        return false;
    }
};