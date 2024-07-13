/* https://coderun.yandex.ru/problem/cheapest-way */

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.min

fun main(args: Array<String>) {
  val reader = BufferedReader(InputStreamReader(System.`in`))
  val writer = BufferedWriter(OutputStreamWriter(System.out))

  val p = reader.readLine().split(" ").map { it.toInt() }.toList()

  val N = p[0]
  val M = p[1]

  var values: Array<IntArray> = Array(N) { IntArray(M) }

  for (i in 0 until N) {
    val l = reader.readLine().split(" ").map { it.toInt() }.toList()

    for (j in 0 until M) {
      val c = l[j]

      if (j == 0) {
        if (i == 0) {
          values[i][j] = c
        } else {
          values[i][j] = c + values[i - 1][j]
        }
      } else {
        if (i == 0) {
          values[i][j] = c + values[i][j - 1]
        } else {
          values[i][j] = c + min(values[i][j - 1], values[i - 1][j])
        }
      }
    }
  }

  writer.write(values[N - 1][M - 1].toString())

  reader.close()
  writer.close()
}
