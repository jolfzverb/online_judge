/* https://coderun.yandex.ru/problem/speleologist-way */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    int n = Integer.parseInt(reader.readLine());
    int n2 = n * n;
    int n3 = n * n * n;

    int[] cave = new int[n3];
    Set<Integer> s = new HashSet<>();

    for (int i = 0; i < n; i++) {
      reader.readLine();

      for (int j = 0; j < n; j++) {
        char[] line = reader.readLine().toCharArray();

        for (int k = 0; k < n; k++) {
          int index = i * n2 + j * n + k;

          switch (line[k]) {
            case '#':
              cave[index] = -1;
              break;
            case '.':
              cave[index] = 0;
              break;
            case 'S':
              cave[index] = 0;
              s.add(index);
              break;
          }
        }
      }
    }

    int l = 0;

    while (!s.isEmpty()) {
      l += 1;
      Set<Integer> next_s = new HashSet<>();

      for (Integer c : s) {
        if (c < n2) {
          writer.write(String.valueOf(l - 1));
          reader.close();
          writer.close();

          return;
        }

        cave[c] = l;
      }

      for (Integer c : s) {
        int i = c / n2;
        int j = (c % n2) / n;
        int k = c % n;

        if (i > 0 && cave[c - n2] == 0) {
          next_s.add(c - n2);
        }

        if (i < n - 1 && cave[c + n2] == 0) {
          next_s.add(c + n2);
        }

        if (j > 0 && cave[c - n] == 0) {
          next_s.add(c - n);
        }

        if (j < n - 1 && cave[c + n] == 0) {
          next_s.add(c + n);
        }

        if (k > 0 && cave[c - 1] == 0) {
          next_s.add(c - 1);
        }

        if (k < n - 1 && cave[c + 1] == 0) {
          next_s.add(c + 1);
        }
      }

      s = next_s;
    }

    writer.write(String.valueOf(-1));
    reader.close();
    writer.close();
  }
}
