#include "logger.h"

#include <ctime>

namespace gls1 {
void logger::log(log_level level, const std::string &message) {
  if (log_file_.is_open()) {
    log_file_ << "[" << current_date_time() << "] " << level_to_string(level)
              << ": " << message << std::endl;
  }
  std::cout << "[" << current_date_time() << "] " << level_to_string(level)
            << ": " << message << std::endl;
}

std::string logger::current_date_time() {
  time_t now = time(0);
  struct tm tstruct;
  char buffer[80];
  localtime_s(&tstruct, &now);
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", &tstruct);
  return buffer;
}

std::string logger::level_to_string(log_level level) {
  switch (level) {
    case log_level::debug:
      return "DEBUG";
    case log_level::info:
      return "INFO";
    case log_level::warning:
      return "WARNING";
    case log_level::error:
      return "ERROR";
    case log_level::fatal:
      return "FATAL";
    default:
      return "UNKNOWN";
  }
}
}  // namespace gls1