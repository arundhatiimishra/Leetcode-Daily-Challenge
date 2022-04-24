/*
   Question Link - https://leetcode.com/problems/design-underground-system/
   1396. Design Underground System
*/

/*
   Time Complexity - O(1) for all the functions
   Space Complexity - O(N) 
*/

class UndergroundSystem {
public:
    map<pair<string,string>,pair<int,int>> xyz; //from_station,to_station::sum_of_time,frequency
    map<int,pair<string,int>> ids_in_out_time; //id::from_station,time
    
    UndergroundSystem(){
        
    }
    
    void checkIn(int id, string stationName, int t){
        ids_in_out_time[id]=make_pair(stationName,t);  
    }
    
    void checkOut(int id, string stationName, int t){
        if(xyz.count(make_pair(ids_in_out_time[id].first,stationName))==true){
            xyz[make_pair(ids_in_out_time[id].first,stationName)].first+=(t-ids_in_out_time[id].second);
            xyz[make_pair(ids_in_out_time[id].first,stationName)].second++;   
        }else{
            xyz[make_pair(ids_in_out_time[id].first,stationName)]=make_pair(t-ids_in_out_time[id].second,1);
        }
        ids_in_out_time.erase(id);  
    }
    
    double getAverageTime(string startStation, string endStation){
        double sum=(float)xyz[make_pair(startStation,endStation)].first;
        double freq=(float)xyz[make_pair(startStation,endStation)].second;
        return sum/freq;
    }
};