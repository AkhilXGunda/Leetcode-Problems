class Solution {
public:
    //O(1) space & O(n) time complexity
    bool isAnagram(string s, string t) {
    // TODO: Write your code here

    // if size of two strings aren't same can't be anagram. Base case ish.
    if (s.size() != t.size()){
        return false;
    }

    //check if same character + frequency
    unordered_map<char, int> um;
    unordered_map<char, int> um2;
    int s_len = s.size();
    //insert all chars(keys) and how many times they occur(value) into unordered map
    for (int i = 0; i < s_len; i++){
        um[s[i]]++;
    }
    int r_len = t.size();
    //do same for string t
    for (int i = 0; i < r_len; i++){
        um2[t[i]]++;
    }
    //see if same key and values
    return um == um2;
    }
};