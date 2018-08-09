#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Todo : Need to find how to return it 
void findAvailableTiming(vector<int> mStart, vector<int> mEnd,int oStart, int oEnd, vector<int>& aStart,  vector<int>& aEnd){
 
  int sizeS = mStart.size();
  int sizeE = mEnd.size();
  
  
  if(sizeS != sizeE){
    return; //Todo
  }
  
  if (oStart < mStart[0]){
    aStart.push_back(oStart);
    aEnd.push_back(mStart[0]);
  }
  
  
  for(int i = 0; i < sizeS-1; i++){
     if(mEnd[i] != mStart[i+1]){ //Check for back to back meetings
       if(mEnd[i] <= mStart[i+1]){ // Avoid overlapping
          aStart.push_back(mEnd[i]);
          aEnd.push_back(mStart[i+1]);
       }
     }
  }
    
  if(oEnd >= mEnd[sizeE-1]){ //Last metting end time
      aStart.push_back(mEnd[sizeE-1]);
      aEnd.push_back(oEnd);
  }
 
}

// To execute C++, please define "int main()"
int main() {
  //Assumes time will be in 24 hour pattern
  int oStart = 9;
  int oEnd = 17;
  
  vector<int> mStart = {9, 11, 14};
  vector<int> mEnd  = {12, 13, 15};
  vector<int> aStart; // Start time of a person's available time
  vector<int> aEnd; // End time of a person's available time
  findAvailableTiming(mStart, mEnd, oStart, oEnd, aStart, aEnd);
  if (aStart.size() == 0)
    cout<<"No time to schedule new meetings"<<endl;
  else{
    int size = aStart.size();
    for (int i = 0; i < size; i++){
       cout<<"Available from "<<aStart[i]<<" to "<<aEnd[i]<<endl;
    }
  }
  
  return 0;
}