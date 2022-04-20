#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int n) {
    vector<int> p;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            p.push_back(i);
        }
        if (p.size() > 2) {
            return p;
        }
    }
    return p;
}

int main() {
    int l = 174457, r = 174505;
    vector<tuple<long long,int,int>> answer;
    for (int i = l; i <= r; i++) {
        vector<int> p = divisors(i);
        if (p.size() == 2) {
            if (p[0] > p[1]) {
                swap(p[0], p[1]);
            }
            answer.push_back({1LL * p[0] * p[1], p[0], p[1]});
        }
    }
    sort(answer.begin(), answer.end());
    for (auto [a, b, c] : answer) {
        cout << b << " " << c << "\n";
    }
    return 0;
}
