#ifndef GLS1_FILE_H_
#define GLS1_FILE_H_

#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

namespace gls1 {
class file final {
 public:
  explicit file(const std::string &filepath);

  std::string contents() const;

 private:
  void load(const std::string &filename);

  std::string contents_;
};
}  // namespace gls1

#endif