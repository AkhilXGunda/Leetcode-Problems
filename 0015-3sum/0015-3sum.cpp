class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++){
        if (i > 0 && arr[i-1] == arr[i]){
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        while (left < right){
            if (left != i + 1 && arr[left] == arr[left - 1]){
              left++;
              continue;
            }
            if(right != n - 1 && arr[right] == arr[right + 1]){
              right--;
              continue;
            }
            int curr_sum = arr[i] + arr[left] + arr[right];
            if (curr_sum == 0){
                triplets.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
            } else if (curr_sum < 0){
                left++;
            } else { // curr_sum > 0
                right--;
            }
        }
    }
    return triplets;
    }
};