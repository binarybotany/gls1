#ifndef GLS1_TEXTURE_H_
#define GLS1_TEXTURE_H_

#include <string>

namespace gls1 {
class texture final {
 public:
  texture(const std::string &imagepath);
  ~texture();

  void bind() const;
  void unbind() const;

 private:
  unsigned int texture_;
};
}  // namespace gls1

#endif