class Solution {
public:
    int threeSumClosest(vector<int>& arr, int targetSum) {
        // TODO: Write your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int lowest_diff = INT_MAX;
        int lowest_sum = INT_MAX;

        for (int i = 0; i < n - 2; i++){
            int l = i + 1;
            int r = n - 1;
            while (l < r){
                int curr_sum = arr[i] + arr[l] + arr[r];
                if (curr_sum == targetSum){ //if target sum found return it. done. 
                    return curr_sum;
                }

                int curr_diff = abs(curr_sum - targetSum); 
                if (curr_diff < lowest_diff){ //otherwise see if closest to targetsum
                    lowest_sum = curr_sum;
                    lowest_diff = curr_diff;
                } else if (curr_diff == lowest_diff){ //if equally close
                    lowest_sum = min(lowest_sum, curr_sum);
                }

                if (curr_sum < targetSum){ //update l or r index to get closer to targetSum
                    l++;
                } else{ //curr_sum > targetSum
                    r--;
                }
            }
        }
        return lowest_sum;  
    }
};