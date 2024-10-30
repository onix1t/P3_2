#include "ex2.h"

int recursionCounter = 0;

string addStrings(const string& num1, const string& num2) {
    string result;
    int carry = 0, sum;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string subtractStrings(const string& num1, const string& num2) {
    string result;
    int borrow = 0, diff;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        diff = (num1[i] - '0') - (j >= 0 ? (num2[j] - '0') : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += diff + '0';
        i--;
        j--;
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

string shiftString(const string& num, int n) {
    return num + string(n, '0');
}

string removeLeadingZeros(const string& str) {
    size_t firstNonZero = str.find_first_not_of('0');
    if (firstNonZero != string::npos) {
        return str.substr(firstNonZero);
    }
    return "0";
}

string karatsubaMultiply(const string& num1, const string& num2) {
    recursionCounter++;

    int n = max(num1.size(), num2.size());
    if (n == 1) {
        int product = (num1[0] - '0') * (num2[0] - '0');
        return to_string(product);
    }

    string x = string(n - num1.size(), '0') + num1;
    string y = string(n - num2.size(), '0') + num2;

    int half = n / 2;
    string x1 = x.substr(0, half);
    string x0 = x.substr(half);
    string y1 = y.substr(0, half);
    string y0 = y.substr(half);

    string z2 = karatsubaMultiply(x1, y1);
    string z0 = karatsubaMultiply(x0, y0);
    string z1 = karatsubaMultiply(addStrings(x1, x0), addStrings(y1, y0));
    z1 = subtractStrings(z1, addStrings(z2, z0));

    string result = addStrings(addStrings(shiftString(z2, 2 * (n - half)), shiftString(z1, n - half)), z0);

    return removeLeadingZeros(result);
}

