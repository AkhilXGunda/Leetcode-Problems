class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
    vector<vector<int>> quadruplets;
    // TODO: Write your code here
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n - 3; i++){
        if (i != 0 && arr[i - 1] == arr[i]){ // skip duplicate value in first val of quadruplet
            continue;
        }
        for (int j = i + 1; j < n - 2; j++){
            if (j != i + 1 && arr[j - 1] == arr[j]){ // skip duplicate value in 2nd val of quadruplet
                continue;
            }
            int ptr1 = j + 1;
            int ptr2 = n - 1;
            while (ptr1 < ptr2){
                if (ptr1 != j + 1 && arr[ptr1 - 1] == arr[ptr1]){ // skip duplicate value in 3rd val of quadruplet
                    ptr1++;
                    continue;
                }
                if (ptr2 != n - 1 && arr[ptr2 + 1] == arr[ptr2]){ // skip duplicate value in 4th val of quadruplet
                    ptr2--;
                    continue;
                }
                long long int curr_sum = (long long)arr[i] + arr[j] + arr[ptr1] + arr[ptr2];
                if (curr_sum == target){
                    vector<int> quad = {arr[i], arr[j], arr[ptr1], arr[ptr2]};
                    quadruplets.push_back(quad);
                    ptr1++;
                    ptr2--;
                } else if (curr_sum < target){
                    ptr1++;
                } else { // curr_sum > target
                    ptr2--;
                }
            }
        }
    }
    return quadruplets;
    }
};