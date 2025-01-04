class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_set<int> us;
        for (int i = 0; i < size; i++){
            us.insert(nums[i]);
        }
        if (us.size() == size){
            return false;
        }
        return true;
    }
};