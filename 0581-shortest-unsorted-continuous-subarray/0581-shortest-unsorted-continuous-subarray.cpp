class Solution {
public:
    // O(n) time, O(1) space.
    int findUnsortedSubarray(vector<int>& arr) {
        // TODO: Write your code here
        int n = arr.size();
        int num_of_valid_ord = 0;
        int first_mis = -1, second_mis = -1;
        for (int i = 0; i < n - 1; i++){
            if (arr[i] > arr[i+1]){
                first_mis = i;
                break;
            }
            num_of_valid_ord++;
        }
        if (first_mis == -1){
            return 0;
        }
        for (int i = n - 1; i >= 0; i--){
            if (arr[i-1] > arr[i]){
                second_mis = i;
                break;
            }
            num_of_valid_ord++;
        }
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for (int i = first_mis; i <= second_mis; i++){
            smallest = min(smallest, arr[i]);
            largest = max(largest, arr[i]);
        }
        for (int i = first_mis - 1; i >= 0; i--){
            if (smallest < arr[i]){
                num_of_valid_ord--;
            } else{
                break;
            }
        }
        for (int i = second_mis + 1; i < n; i++){
            if (largest > arr[i]){
                num_of_valid_ord--;
            } else{
                break;
            }
        }

        return n - num_of_valid_ord;
    }
};
