//got this wrong. I was being retarded. could just do binary search. I did O(sqrt(x))
// iterating from 0 to sqrt of x, to find first number squared that would be greater than x. 
//this takes O(sqrt(x))
class Solution {
public:
    int mySqrt(int x) {
    if (x < 2){
        return x;
    }
    int l = 0;
    int r = x/2;
    int mid;
    unsigned long long value;
    int ans = -1;
    while (l <= r){
        mid = l + (r - l) / 2; //avoid overflow! int + int > INT_MAX
        value = (unsigned long long)mid * mid; //without cast, would do int * int multiplication! resulting in overflow
        if (value == x){
            return mid;
        }
        else if (value < x){
            l = mid + 1;
            ans = mid;
        }
        else if (value > x){
            r = mid - 1;
        }
    }
    return ans;
    }
};