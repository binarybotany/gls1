#ifndef GLS1_LOGGER_H_
#define GLS1_LOGGER_H_

#include <fstream>
#include <iostream>
#include <string>

namespace gls1 {
enum class log_level { debug, info, warning, error, fatal };

class logger final {
 public:
  logger(const std::string &filepath)
      : log_file_(filepath, std::ios::out | std::ios::app) {}

  void log(log_level level, const std::string &message);

 private:
  std::ofstream log_file_;

  std::string current_date_time();

  std::string level_to_string(log_level level);
};
}  // namespace gls1

#endif