#include <bits/stdc++.h>
using namespace std;

int minMachines(int start[], int ending[], int n)
{
    vector<pair<int, int> > Time;

    for (int i = 0; i < n; i++) {
        Time.push_back({ start[i], 1 });
        Time.push_back({ ending[i] + 1, -1 });
    }

    // Sort the vector
    sort(Time.begin(), Time.end());

    int answer = 0, sum = 0;

    for (int i = 0; i < Time.size(); i++) {
        sum += Time[i].second;
        answer = max(answer, sum);
    }

    return answer;
}

int main()
{
    int start[] = {1, 8, 3, 9, 6};
    int ending[] = {7, 9, 6, 14, 7};
    int n = sizeof(start) / sizeof(start[0]);

    cout << minMachines(start, ending, n);

    return 0;
}
