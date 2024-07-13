/* https://coderun.yandex.ru/problem/sntp */

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string local_start;
  std::string local_end;
  std::string remote;
  std::cin >> local_start >> remote >> local_end;

  int local_start_hh = std::stoi(local_start.substr(0, 2));
  int local_start_mm = std::stoi(local_start.substr(3, 2));
  int local_start_ss = std::stoi(local_start.substr(6, 2));

  int local_end_hh = std::stoi(local_end.substr(0, 2));
  int local_end_mm = std::stoi(local_end.substr(3, 2));
  int local_end_ss = std::stoi(local_end.substr(6, 2));

  int remote_hh = std::stoi(remote.substr(0, 2));
  int remote_mm = std::stoi(remote.substr(3, 2));
  int remote_ss = std::stoi(remote.substr(6, 2));

  int diff_hh = local_end_hh - local_start_hh;
  int diff_mm = local_end_mm - local_start_mm;
  int diff_ss = local_end_ss - local_start_ss;

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

  remote_ss += diff_ss / 2;
  if (diff_ss % 2) remote_ss += 1;

  remote_mm += diff_mm / 2;
  if (diff_mm % 2) remote_ss += 30;

  remote_hh += diff_hh / 2;
  if (diff_hh % 2) remote_mm += 30;

  remote_mm += remote_ss / 60;
  remote_ss = remote_ss % 60;

  remote_hh += remote_mm / 60;
  remote_mm = remote_mm % 60;

  remote_hh = remote_hh % 24;

  std::cout << std::setfill('0') << std::setw(2) << remote_hh << ":"
            << std::setfill('0') << std::setw(2) << remote_mm << ":"
            << std::setfill('0') << std::setw(2) << remote_ss << std::endl;

  return 0;
}
