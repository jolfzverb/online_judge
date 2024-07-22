import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main(args: Array<String>) {
  val reader = BufferedReader(InputStreamReader(System.`in`))
  val writer = BufferedWriter(OutputStreamWriter(System.out))

  val n = reader.readLine().toInt()
  val n2 = n * n
  val n3 = n * n * n

  val cave = Array<Int>(n3) { 0 }
  var s = HashSet<Int>()

  for (i in 0..<n) {
    reader.readLine()

    for (j in 0..<n) {
      val line = reader.readLine().toCharArray()

      for (k in 0..<n) {
        val c = i * n2 + j * n + k

        when (line[k]) {
          '#' -> cave[c] = -1
          '.' -> cave[c] = 0
          'S' -> {
            cave[c] = 0
            s.add(c)
          }
        }
      }
    }
  }

  var l = 0

  while (!s.isEmpty()) {
    l += 1
    var next_s = HashSet<Int>()

    for (c in s) {
      if (c < n2) {
        writer.write((l - 1).toString())

        reader.close()
        writer.close()

        return
      }

      cave[c] = 1
    }

    for (c in s) {
      val i = c / n2
      val j = (c % n2) / n
      val k = c % n

      if (i > 0 && cave[c - n2] == 0) {
        next_s.add(c - n2)
      }

      if (i < n - 1 && cave[c + n2] == 0) {
        next_s.add(c + n2)
      }

      if (j > 0 && cave[c - n] == 0) {
        next_s.add(c - n)
      }

      if (j < n - 1 && cave[c + n] == 0) {
        next_s.add(c + n)
      }

      if (k > 0 && cave[c - 1] == 0) {
        next_s.add(c - 1)
      }

      if (k < n - 1 && cave[c + 1] == 0) {
        next_s.add(c + 1)
      }
    }

    s = next_s
  }

  writer.write((-1).toString())
  reader.close()
  writer.close()
}
