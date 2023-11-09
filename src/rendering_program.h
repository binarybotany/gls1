#ifndef GLS1_RENDERING_PROGRAM_H_
#define GLS1_RENDERING_PROGRAM_H_

#include <string>
#include <vector>

namespace gls1 {
class rendering_program final {
 public:
  rendering_program();
  ~rendering_program();

  void add_shader(int type, std::string filepath);
  void link();
  void use();

 private:
  unsigned int program_;
  std::vector<unsigned int> shaders_;
};
}  // namespace gls1

#endif