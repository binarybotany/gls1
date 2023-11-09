#ifndef GLS1_RENDERING_PROGRAM_H_
#define GLS1_RENDERING_PROGRAM_H_

#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>
#include <string>
#include <vector>

namespace gls1 {
class rendering_program final {
 public:
  rendering_program();
  ~rendering_program();

  void add_shader(int type, std::string filepath);
  void link() const;
  void use() const;

  void set_mat4fv(const std::string &location, glm::mat4 matrix) const;

 private:
  unsigned int program_;
  std::vector<unsigned int> shaders_;
};
}  // namespace gls1

#endif