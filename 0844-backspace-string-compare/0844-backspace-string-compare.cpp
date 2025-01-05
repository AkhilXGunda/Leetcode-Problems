class Solution {
public:
    bool backspaceCompare(string str1, string str2) {
      // TODO: Write your code here
    int n = str1.size();
    int n2 = str2.size();
    int ptr1 = n - 1;
    int ptr2 = n2 - 1;
    while (ptr1 >= 0 || ptr2 >= 0){
      char c1 = next_char(str1, ptr1);
      char c2 = next_char(str2, ptr2);
      if (c1 == -1 && c2 == -1){
          return true;
      } else if (c1 != c2){
          return false;
      } //if they equal just continue loop iteration.
      ptr1--;
      ptr2--;
    }
    return true;
    }

    static char next_char(const string &str1, int &ptr1){
      int num_to_skip = 0;
      while (ptr1 >= 0 && (num_to_skip > 0 || str1[ptr1] == '#')){
        if (str1[ptr1] == '#'){
            num_to_skip++;
        } else if (num_to_skip > 0){
            num_to_skip--;
        }
        ptr1--;
      }
      return ptr1 >= 0 ? str1[ptr1] : -1;  
    }
};