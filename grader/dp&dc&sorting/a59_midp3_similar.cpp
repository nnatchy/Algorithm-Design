#include<iostream>
#include<string>
#define ll long long int
using namespace std;

bool DC(string &first, string &sec, int fStart, int fStop, int sStart, int sStop) {
    string compareOne = first.substr(fStart, fStop - fStart);
    string compareTwo = sec.substr(sStart, sStop - sStart);
    if (fStop - fStart == 1) return compareOne == compareTwo;
    else if (compareOne == compareTwo) return true;
    int midOne = (fStart + fStop) / 2; 
    int midTwo = (sStart + sStop) / 2;
    return (DC(first, sec, fStart, midOne, sStart, midTwo) && DC(first, sec, midOne, fStop, midTwo, sStop)) || \
    (DC(first, sec, fStart, midOne, midTwo, sStop) && DC(first, sec, midOne, fStop, sStart, midTwo));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string first, sec;
    cin >> first >> sec;
    bool res = DC(first, sec, 0, first.size(), 0, sec.size());
    if (res) cout << "YES\n";
    else cout << "NO\n";
}