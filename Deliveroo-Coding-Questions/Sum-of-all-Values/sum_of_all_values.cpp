#include <iostream>
#include <string>
#include <cmath>

const int MOD = 1000000007;

using namespace std;

long long sumOfAllValues(const string& s) {
    int n = s.size();
    long long totalSum = 0;

    // Iterate over each position where we could place a '+'
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        long long currentSum = 0;
        long long multiplier = 1;
        long long number = 0;

        for (int j = 0; j < n; ++j) {
            number = number * 10 + (s[j] - '0'); // Build the current number

            // If this position is a '+' position (i.e., if (i & (1 << j)) != 0)
            if (j == n - 1 || (i & (1 << j)) != 0) {
                currentSum = (currentSum + number) % MOD; // Add the number to the current sum
                number = 0; // Reset the number
            }
        }

        totalSum = (totalSum + currentSum) % MOD; // Add the current sum to the total sum
    }

    return totalSum;
}

int main() {
    string s = "123"; // Example input
    cout << sumOfAllValues(s) << endl; // Output the result
    return 0;
}
