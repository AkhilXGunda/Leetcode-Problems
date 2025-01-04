class Solution {
public:
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