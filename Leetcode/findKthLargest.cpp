#include"leetcode.h"

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 1)
			return nums[0];
		return heapSort(nums, k);
	}
private:
	//������
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
	//�ѽ���
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
	//�ѵ���
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
	vector<int> data = { 0,1,2};
	for (int i = 1; i <= data.size(); i++){
		cout<<s.findKthLargest(data,i)<<endl;
	}
	return 0;
}