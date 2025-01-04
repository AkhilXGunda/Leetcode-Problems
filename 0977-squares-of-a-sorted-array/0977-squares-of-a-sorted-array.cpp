class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int> squares(n);

        // Find the position where abs(arr[i]) is closest to 0.
        int i = 0;
        while (i < n - 1 && abs(arr[i]) >= abs(arr[i+1])) {
            i++;
        }

        int ptr1 = i;
        int ptr2 = i + 1;
        for (int j = 0; j < n; j++) {
            if (ptr2 >= n || (ptr1 >= 0 && abs(arr[ptr1]) <= abs(arr[ptr2]))) {
                squares[j] = abs(arr[ptr1]) * abs(arr[ptr1]);
                ptr1--;
            } else if (ptr1 < 0 || (ptr2 < n && abs(arr[ptr2]) < abs(arr[ptr1]))) {
                squares[j] = abs(arr[ptr2]) * abs(arr[ptr2]);
                ptr2++;
            }
        }
        return squares;
    }
};
