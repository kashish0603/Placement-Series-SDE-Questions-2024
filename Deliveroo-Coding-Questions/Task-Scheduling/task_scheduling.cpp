// C++ implementation of the approach
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int min(int start[], int end[], int n)
{

    int prefix_sum[MAX] = { 0 };

    for (int i = 0; i < n; i++) {
        prefix_sum[start[i]]++;
        prefix_sum[end[i] + 1]--;
    }

    int ans = prefix_sum[0];

    for (int i = 1; i < MAX; i++) {
        prefix_sum[i] += prefix_sum[i - 1];
        ans = max(ans, prefix_sum[i]);
    }

    return ans;
}

int main()
{
    int start[] = {1, 8, 3, 9, 6};
    int end[] = {7, 9, 6, 14, 7};
    int n = sizeof(start) / sizeof(start[0]);

    cout << min(start, end, n);

    return 0;
}
