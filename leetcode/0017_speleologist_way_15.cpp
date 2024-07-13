/* https://coderun.yandex.ru/problem/speleologist-way */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> cave(N * N * N);
  unordered_set<int> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      string line;
      cin >> line;

      for (int k = 0; k < N; k++) {
        int c = i * N * N + j * N + k;

        switch (line[k]) {
          case '#':
            cave[c] = -1;
            break;

          case 'S':
            q.insert(c);
            // fallthrough

          case '.':
            cave[c] = 0;
            break;
        }
      }
    }
  }

  int l = 0;

  while (!q.empty()) {
    l += 1;
    unordered_set<int> next_q;

    for (auto c : q) {
      if (c < N * N) {
        cout << l - 1 << endl;
        return 0;
      }
      cave[c] = l;
    }

    for (auto c : q) {
      int i = c / (N * N);

      int j = (c % (N * N)) / N;

      int k = c % N;

      if (i > 0 && cave[c - N * N] == 0) {
        next_q.insert(c - N * N);
      }

      if (i < N - 1 && cave[c + N * N] == 0) {
        next_q.insert(c + N * N);
      }

      if (j > 0 && cave[c - N] == 0) {
        next_q.insert(c - N);
      }

      if (j < N - 1 && cave[c + N] == 0) {
        next_q.insert(c + N);
      }

      if (k > 0 && cave[c - 1] == 0) {
        next_q.insert(c - 1);
      }

      if (k < N - 1 && cave[c + 1] == 0) {
        next_q.insert(c + 1);
      }
    }

    q = next_q;
  }

  return 0;
}
