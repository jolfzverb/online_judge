/* https://coderun.yandex.ru/problem/cheapest-way */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int N, M;

    int[] parts = Arrays.stream(reader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

    N = parts[0];
    M = parts[1];

    int[][] values = new int[N][M];

    for (int i = 0; i < N; i++) {
      parts = Arrays.stream(reader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

      for (int j = 0; j < M; j++) {
        int val = parts[j];

        if (i == 0) {
          if (j == 0) {
            values[i][j] = val;
          } else {
            values[i][j] = val + values[i][j - 1];
          }
        } else {
          if (j == 0) {
            values[i][j] = val + values[i - 1][j];
          } else {
            values[i][j] = val + Math.min(values[i - 1][j], values[i][j - 1]);
          }
        }
      }
    }

    writer.write(String.valueOf(values[N - 1][M - 1]));

    reader.close();
    writer.close();
  }
}
