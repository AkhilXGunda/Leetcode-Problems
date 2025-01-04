class Solution {
public:
//the below solution isn't that great, the one given in the solution is better. 
// each time we find repeated elements, we add new_freq - 1 to pairCount. I did factorial. 
// still same O(n) solution to both though...
    int numIdenticalPairs(vector<int>& nums) {
      int pairCount = 0;
      // TODO: Write your code here
      unordered_map<int, int> freqMap;
      unsigned long long len = nums.size();
      for (int i = 0; i < len; i++){
          if(freqMap.find(nums[i]) == freqMap.end()){
              freqMap[nums[i]] = 1;
          }else{
              freqMap[nums[i]]++;
          }
      }
      for (pair <int, int> p: freqMap){
          if (p.second >= 2){
              pairCount += (p.second * (p.second - 1)) / 2;
          }
      }
      return pairCount;
    }
};