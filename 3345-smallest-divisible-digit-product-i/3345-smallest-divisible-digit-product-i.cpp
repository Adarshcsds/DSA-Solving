class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {

            int temp = n;
            int prod = 1;

            // Calculate product of digits
            while (temp > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }

            // If product is divisible by t, return n
            if (prod % t == 0)
                return n;

            // Otherwise try the next number
            n++;
        }
    }
};