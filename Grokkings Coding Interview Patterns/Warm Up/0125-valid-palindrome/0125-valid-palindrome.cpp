class Solution {
public:
  //isalnum() returns true or false if alphanumeric
  //need to do string_name.resize(size); to resize <string>
bool isPalindrome(string s) {
    // TODO: Write your code here
    int i = 0, j = 0, n = s.size();
    for (int k = 0; k < n; k++){
        if (isalnum(s[k])){
            s[i] = tolower(s[k]);
            i++;
        }
    }
    s[i] = '\0';
    s.resize(i);
//    cout << s << endl;
    for (int k = 0; k < i/2; k++){
        if (s[k] != s[i-k-1]){
            cout << s[k] << " " << s[i-k-1] << endl;
            return false;
        }
        swap(s[k], s[i-k-1]);
    }
//    cout << s << endl;
    return true;
}
};