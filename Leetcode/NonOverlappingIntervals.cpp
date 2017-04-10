//
// Created by Bing on 17/4/10.
//
#include"leetcode.h"

//  Definition for an interval.

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

bool sortByInterval(Interval& a,Interval& b){
    return a.start < b.start;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        stack<Interval> st;
        sort(intervals.begin(),intervals.end(),sortByInterval);
        int count = 0;
        st.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            Interval back = st.top();
            if(back.end <= intervals[i].start){
                st.push(intervals[i]);
            }else if( intervals[i].end < back.end){
                st.pop();
                st.push(intervals[i]);
                // drop
                count ++;
            }else {
                // drop
                count ++;
            }
        }
        return count;
    }
};