class Solution{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k==0||nums.size()<2) return false;
        long long low=0;
        set<long long> windows;
        for(int i=0;i<nums.size();i++){
            if(i-low>k){
                windows.erase(nums[low]);
                low++;
            }
            
            auto it=windows.lower_bound((long long)nums[i]-(long long)t);
            if(it!=windows.end()&&abs((long long)nums[i]-*it)<=(long long)t){
                return true;
            }
            windows.insert(nums[i]);
        }
        return false;
	}
};
