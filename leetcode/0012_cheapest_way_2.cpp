/* https://coderun.yandex.ru/problem/cheapest-way */

#include <iostream>
#include <string>
#include <vector>

int main() {
  int N, M;

  std::cin >> N >> M;

  std::vector<std::vector<int>> values;

  for (int i = 0; i < N; i++) {
    values.emplace_back(std::vector<int>(M, 0));

    for (int j = 0; j < M; j++) {
      int value;
      std::cin >> value;

      if (i == 0) {
        if (j == 0) {
          values[i][j] = value;
        } else {
          values[i][j] = value + values[i][j - 1];
        }
      } else {
        if (j == 0) {
          values[i][j] = value + values[i - 1][j];
        } else {
          int mv = std::min(values[i][j - 1], values[i - 1][j]);
          values[i][j] = value + mv;
        }
      }
    }
  }

  std::cout << values[N - 1][M - 1] << std::endl;

  return 0;
}
