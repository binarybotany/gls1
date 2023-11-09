#include "file.h"

#include "lazy_singleton.h"
#include "logger.h"

namespace gls1 {
file::file(const std::string &filepath) { load(filepath); }

std::string file::contents() const { return contents_; }

void file::load(const std::string &filepath) {
  std::ifstream stream(filepath);

  if (!stream.is_open()) {
    std::string message = "Unable to open file: " + filepath;
    lazy_singleton<logger>::get().log(log_level::error, message);
  }

  std::stringstream buffer;
  buffer << stream.rdbuf();
  std::string contents = buffer.str();

  std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
  std::wstring wcontents = converter.from_bytes(contents);

  contents_ = std::string(wcontents.begin(), wcontents.end());
}
}  // namespace gls1