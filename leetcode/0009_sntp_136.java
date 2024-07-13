/* https://coderun.yandex.ru/problem/sntp */

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

    int[] before =
        Arrays.stream(reader.readLine().split(":")).mapToInt(Integer::parseInt).toArray();
    int[] server =
        Arrays.stream(reader.readLine().split(":")).mapToInt(Integer::parseInt).toArray();
    int[] after = Arrays.stream(reader.readLine().split(":")).mapToInt(Integer::parseInt).toArray();

    int diff_hh = after[0] - before[0];
    int diff_mm = after[1] - before[1];
    int diff_ss = after[2] - before[2];

    if (diff_ss < 0) {
      diff_ss += 60;
      diff_mm -= 1;
    }

    if (diff_mm < 0) {
      diff_mm += 60;
      diff_hh -= 1;
    }

    if (diff_hh < 0) {
      diff_hh += 24;
    }

    int result_ss = server[2] + diff_ss / 2;

    if (diff_ss % 2 != 0) {
      result_ss += 1;
    }

    int result_mm = server[1] + diff_mm / 2;

    if (diff_mm % 2 != 0) {
      result_ss += 30;
    }

    int result_hh = server[0] + diff_hh / 2;

    if (diff_hh % 2 != 0) {
      result_mm += 30;
    }

    result_mm += result_ss / 60;
    result_ss = result_ss % 60;

    result_hh += result_mm / 60;
    result_mm = result_mm % 60;

    result_hh = result_hh % 24;

    writer.write(String.format("%02d:%02d:%02d", result_hh, result_mm, result_ss));

    reader.close();
    writer.close();
  }
}
