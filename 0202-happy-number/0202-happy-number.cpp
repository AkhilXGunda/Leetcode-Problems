class Solution {
public:
    bool isHappy(int num) {
        // TODO: Write your code here
        // O(log(n)) time! O(1) space
        // I initialliy said O(n) time, but actually it's O(log(n)) time because we have log_10 digits. Each digit squared can be atmost 81 (9 * 9). So num or n transforms to 81M (m = number of digits). basically num is reduced to 81M which is logarithmic. So O(log(n)) time ..super tricky!
        unsigned long long s = num;
        unsigned long long f = num;
        while(f != 1){
            unsigned long long new_s = 0;
            while(s > 0){
                new_s += pow((s % 10), 2);
                s /= 10;
            }
            s = new_s;
            for (int i = 0; i < 2; i++){
                unsigned long long new_f = 0;
                while (f > 0){
                    new_f += pow((f % 10), 2);
                    f /= 10;
                }
                f = new_f;
            }
            if (s == f && s != 1){
                return false;
            }
        }
        return true;
    }
};