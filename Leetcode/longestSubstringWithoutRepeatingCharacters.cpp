//
// Created by Bing on 17/4/10.
//
#include "leetcode.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //   if(s.size()==0) return 0;
        int mins = 0;
        int start,end,ptr;
        for(start=0;start<s.size();start++){
            end = start + 1;
            bool find=false;
            while(!find && end < s.size()){
                ptr = end -1;
                while( ptr >= start){
                    if( s[end] != s[ptr]){
                        ptr --;
                    }else{
                        find = true;
                        break;
                    }
                }
                if(!find){
                    end ++;
                }else{
                    //   cout << start << " "<<end<< endl;
                    if((end-start + 1) > mins){
                        mins = end-start ;
                    }
                    start = ptr;
                    break;
                }
            }
            if( end == s.size()){
                if((end-start +1) > mins){
                    mins = end-start;
                }
            }
        }

        // cout<< endl;
        return mins;
    }
};