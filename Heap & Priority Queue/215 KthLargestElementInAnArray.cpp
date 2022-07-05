/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

class Solution {
    //MinHeap Solution, Time Complexity of O(nlogk), Space Complexity of O(k)
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        for(int num : nums){
            minheap.push(num);          //Insert all elements into Min Heap
            if(minheap.size() > k){
                minheap.pop();          //Pop out the root (smallest element) k times
            }
        }
        //Now the root (smallest element) is the kth largest element since it pop size-k times of smallest element
        return minheap.top();
    }
    //It has a very short code implementation. However, it is not the best solution for Time Complexity
    //The next solution could achieve a slightly performance in general, but much longer implementation
};


class Solution {
    //Quick Select Solution, Time Complexity of average O(n) / worst O(n^2), Space Complexity of O(1)
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        
        while(1) {      //Partite the given list (run quick select) until answer is found
            int pos = partition(nums, left, right);

            //Since index position start from 0, we need to check with k-1 instead of k
            if(pos == k-1){         //Check if the returned number (pivot) is k
                return nums[pos];
            }
            if(pos < k-1){          //If the returned number (pivot) is smaller than k, that means we do not need to check the right side in next partition
                left = pos+1;
            }else right = pos-1;    //If the returned number (pivot) is bigger than k, that means we do not need to check the left side in next partition
        }
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left+1, r = right;  //Choose the most left element as pivot
        
        //Because we are looking for kth *Largest* element, we should assign the left as greater and right as smaller
        while(l<=r) {
            if(nums[l]<pivot && nums[r]>pivot){
                swap(nums[l++],nums[r--]);
            }
            if(nums[l]>=pivot){
                l++;
            }
            if(nums[r]<=pivot){
                r--;
            }
        }

        //Edge Case
        if(pivot < nums[r]){
            swap(nums[left],nums[r]);
        }

        //Now, all elements in the left is bigger than pivot and all elements in the right is smaller
        //In other words, pivot is now the index th Largest element
        return r;
    }
};