/* https://coderun.yandex.ru/problem/sntp */

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
  val reader = BufferedReader(InputStreamReader(System.`in`))
  val writer = BufferedWriter(OutputStreamWriter(System.out))

  val before = reader.readLine().split(":").asSequence().map { it.toInt() }.toList()
  val server = reader.readLine().split(":").asSequence().map { it.toInt() }.toList()
  val after = reader.readLine().split(":").asSequence().map { it.toInt() }.toList()

  var diff_hh = after[0] - before[0]
  var diff_mm = after[1] - before[1]
  var diff_ss = after[2] - before[2]

  if (diff_ss < 0) {
    diff_ss += 60
    diff_mm -= 1
  }

  if (diff_mm < 0) {
    diff_mm += 60
    diff_hh -= 1
  }

  if (diff_hh < 0) {
    diff_hh += 24
  }

  var result_ss = server[2] + diff_ss / 2

  if (diff_ss % 2 != 0) {
    result_ss += 1
  }

  var result_mm = server[1] + diff_mm / 2

  if (diff_mm % 2 != 0) {
    result_ss += 30
  }

  var result_hh = server[0] + diff_hh / 2

  if (diff_hh % 2 != 0) {
    result_mm += 30
  }

  result_mm += result_ss / 60
  result_ss = result_ss % 60

  result_hh += result_mm / 60
  result_mm = result_mm % 60

  result_hh = result_hh % 24

  writer.write("%02d:%02d:%02d".format(result_hh, result_mm, result_ss))

  reader.close()
  writer.close()
}
