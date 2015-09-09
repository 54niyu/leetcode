#include"leetcode.h"

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 1)
			return nums[0];
		return qSort(nums, k,0,nums.size()-1);
	}
private:
	//快速排序
		
	int qSort(vector<int>& nums, int k, int begin, int end){
		int wait = begin;
		for (int i = begin+1; i <= end; i++){
			if (nums[i] < nums[begin]){
				swap(nums[++wait], nums[i]);
			}
		}
		if (wait == k){
			return nums[0];
		}
		else if (wait < k){
			qSort(nums, k, wait + 1, end);
		}
		else{
			qSort(nums, k, begin + 1, wait);
		}
	}
	//堆排序
	int heapSort(vector<int>& nums,int k){
		int i = nums.size();
		while (true){
			heap(nums, i);
			swap(nums[0], nums[i-1]);
			i--;
			if (i == nums.size()-k)
				return nums[i];
		}
	}
	//堆建立
	int heap(vector<int>& nums, int length){
		if (length < 2)
			return 0;
		int rootNumber = (length- 2) / 2;
		for (int i = rootNumber; i >= 0; i--){
			int left = i * 2 + 1;
			int right = left + 1;
			int max = left;
			if (right < length){
				max = nums[left] > nums[right] ? left : right;
			}
			if (nums[max] > nums[i]){
				swap(nums[i], nums[max]);
				heapShift(nums, max,length);
			}
		}
		return 0;
	}
	//堆调整
	void heapShift(vector<int>& nums, int start,int length){
		int k = start;
		while (2*k+1 < length){
		int left = 2 * k + 1;
		int right = left + 1;
		int max = left;
			if (right < length){
				max = nums[left]>nums[right] ? left : right;
			}
			if (nums[max]>nums[k])
				swap(nums[max], nums[k]);

			k = max;
		}
	}
};
int main(){
	Solution s;
	vector<int> data = { 222,23,1,233,21,23,45,65,1,96,2,4,5,7};
	for (int i = 1; i <= data.size(); i++){
		cout<<s.findKthLargest(data,i)<<endl;
	}
	return 0;
}