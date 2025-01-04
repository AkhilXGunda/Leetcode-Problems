class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26] = {0};
        size_t size = sentence.length();
        for (int i = 0; i < size; i++){
            if (sentence[i] >= 65 && sentence[i] <= 90){
                arr[sentence[i] - 65] = 1;
            }
            else if (sentence[i] >= 97 && sentence[i] <= 122){
                arr[sentence[i] - 97] = 1;
            }
        }
        for (int i : arr){
            if (i != 1){
                return false;
            }
        }
        return true;  
    }
};