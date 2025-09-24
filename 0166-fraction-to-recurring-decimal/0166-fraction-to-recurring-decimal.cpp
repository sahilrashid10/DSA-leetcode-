class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string fraction;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) {
            fraction += "-";
        }

        // Convert to positive long long
        long long dividend = 1LL * numerator;
        long long divisor  = 1LL * denominator;
        dividend = abs(dividend);
        divisor  = abs(divisor);

        // Integer part
        fraction += to_string(dividend / divisor);
        long long remainder = dividend % divisor;

        if (remainder == 0) return fraction;

        // Fractional part
        fraction += ".";
        unordered_map<long long, int> map; // remainder -> index in string

        while (remainder != 0) {
            if (map.count(remainder)) {
                fraction.insert(map[remainder], "(");
                fraction += ")";
                break;
            }

            map[remainder] = fraction.size();
            remainder *= 10;
            fraction += to_string(remainder / divisor);
            remainder %= divisor;
        }

        return fraction;
    }
};
