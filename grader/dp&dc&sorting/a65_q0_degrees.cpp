#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  string buf;
  getline(cin,buf);
  vector<int> arr(n);
  int MAX = -1;
  for (int i=0; i<n; ++i){
    int Temp = 0;
    string Temp2;
    getline(cin,Temp2);
    for (int i=0; i<n; ++i){
      //cin>>Temp2;
      Temp += Temp2[i*2] - '0';
    }
    MAX = max(Temp,MAX);
    arr[Temp]++;
  }
  while (arr.back() == 0){
    arr.pop_back();
  }
  for (int i=0; i<=MAX; ++i){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
  return 0;
}

// #include<iostream>
// #include<vector>

// #define ll long long int
// #define pii pair<ll,ll>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     ll n;
//     cin >> n;
//     ll arr[n][n];
//     vector<pii> vp;
//     int max = 0;
//     for (int i = 0; i < n; i++) {
//         int cnt = 0;
//         for (int j = 0; j < n; j++) {
//             cin >> arr[i][j];
//             if (arr[i][j]) cnt++;
//         }
//         if (cnt >= max) max = cnt;
//         vp.push_back(make_pair(cnt, i));
//     }
//     sort(vp.begin(), vp.end(), greater<>());

//     for (int i = 0; i <= max; i++) {
//         if (vp[vp.size() - 1].first != i) {
//             cout << 0 << "\n";
//             vp.pop_back();
//         } else {
//             cout << vp[vp.size() - 1].second << '\n';
//             vp.pop_back();
//         }
//     }
// }