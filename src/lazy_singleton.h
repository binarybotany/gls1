#ifndef GLS1_LAZY_SINGLETON_H_
#define GLS1_LAZY_SINGLETON_H_

namespace gls1 {
template <typename T>
class lazy_singleton {
 public:
  static T &get() noexcept {
    static T instance{};
    return instance;
  }

  lazy_singleton(const lazy_singleton &) = delete;
  lazy_singleton(lazy_singleton &&) = delete;
  lazy_singleton &operator=(const lazy_singleton &) = delete;
  lazy_singleton &operator=(lazy_singleton &&) = delete;
};
}  // namespace gls1

#endif