#include<iostream>

#define ll long long int

using namespace std;

ll DC(ll &num, ll start, ll cnt) {
    if (num <= 11) {
        // 11 -> 2, 10 -> 3, 9 -> 4, 8 -> 5, 7 -> 6
        if (num <= 6) return num;
        else return 11 - num + 2;
    }
    int k = num / start;
	if ((num % start) == 0) {
		return cnt*k;
	}
    return 1;
}

int main() {
    ll num;
    cin >> num;
    ll k = num < 11 ? 1 : 2;
    ll start = 11;
    while (start < num) {
        start = (start * 10) + 1;
        k++;
    }
    cout << DC(num, start, k) << "\n";
}