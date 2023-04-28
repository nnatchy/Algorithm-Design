#include<iostream>
#include<vector>
#include<string>

using namespace std;

// bool recur(vector<vector<char> >& board, string word, int idx, int row, int col) {
//         if (idx == word.length()) return true;
//         int dr[] = {1, -1, 0, 0};
//         int dc[] = {0, 0, 1, -1};
//         int n = board.size();
//         int m = board[0].size();
//         for (int k = 0; k < 4; k++) {
//             int rr = row + dr[k];
//             int cc = col + dc[k];
//             if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
//             if (board[rr][cc] == word[idx]) {
//                 return recur(board, word, idx + 1, rr, cc);
//             }
//         }
//         return false;
// }

    bool exist(vector<vector<char> >& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    // if (recur(board, word, 1, i, j)) {
                    //     return true;
                    // }
                }
            }
        }
        return false;
    }

int main() {
    // int n, m;
    // cin >> n >> m;
    // vector<vector<char> > vl(n, vector<char>(m));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cin >> vl[i][j];
    //     }
    // }
    // string word;
    // cin >> word;
    // cout << exist(vl, word) << "\n";
    cout << to_strin(100) << "\n";
}