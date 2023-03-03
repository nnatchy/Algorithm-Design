#include<iostream>
#include<vector>

#define ll long long int

using namespace std;

vector<ll> matrix_multiply(vector<ll> M, vector<ll> N, int k) {
    vector<ll> tmp;
    ll firstVal = (((M[0] * N[0]) % k) + ((M[1] * N[2]) % k)) % k; tmp.push_back(firstVal);
    ll secondVal = (((M[0] * N[1]) % k) + ((M[1] * N[3]) % k)) % k; tmp.push_back(secondVal);
    ll thirdVal = (((M[2] * N[0]) % k) + ((M[3] * N[2]) % k)) % k; tmp.push_back(thirdVal);
    ll fourthVal = (((M[2] * N[1]) % k) + ((M[3] * N[3]) % k)) % k; tmp.push_back(fourthVal);
    return tmp;
}

vector<ll> DC(ll n, ll k, vector<ll> &vl) {
    if (n == 1) return vl;
    if (n == 2) return matrix_multiply(vl, vl, k);
    vector<ll> tmp = DC(n / 2, k, vl);
    if (n % 2 == 0) return matrix_multiply(tmp, tmp, k);
    else return matrix_multiply(matrix_multiply(tmp, tmp, k), vl, k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    vector<ll> vl(4);
    cin >> n >> k;
    for (int i = 0; i < 4; i++) cin >> vl[i];
    vector<ll> fin = DC(n, k, vl);
    for (auto &x : fin) {
        cout << x << " ";
    }
    cout << "\n";
}