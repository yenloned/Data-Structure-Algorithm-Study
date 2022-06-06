class Solution {
public:
    //the number of unique elements in the array must in range (1,n)
    //i.e O(u) = O(n)
    //k is in the range [1, the number of unique elements in the array]
    //i.e O(k)= O(n)
    //Time Complexity: O(n)+O(k)+O(ulog(2)) = O(n+nlog(2))
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> NumsCount;
        vector<int> ans;
        //This queue is in descending order, i.e top element = minimum in the queue
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Heap;
        // Count the frequency of each number
        //O(n)
        for(auto it:nums){
            NumsCount[it]++;
        }
        //O(the number of unique elements in the array)
        for(auto it:NumsCount){
            int num=it.first;
            int freq = it.second;
            //push element until Heap contains k elements
            //when Heap contains k elements, 
            //push element only when the new element.frequency > element with minimum frequency in Heap
            if(Heap.size()<k||freq>Heap.top().first){
                //Time Complexity: O(log2)
                //priority queue will arrange order by checking the first element 
                //i.e freq must be the first element.
                Heap.push({freq,num});
            }
            //pop element with minimum frequency in Heap when Heap contains element more than needed.
            if(Heap.size()>k){
                Heap.pop();
            }
        }
        //O(k)
        //return answer
        while(!Heap.empty()){
            ans.push_back(Heap.top().second);
            Heap.pop();
        }
        return ans;
    }
};