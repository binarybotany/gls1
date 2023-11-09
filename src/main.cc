#include <memory>

#include "engine.h"

using gls1::engine;

int main(int argc, char **argv) {
  std::unique_ptr<engine> e = std::make_unique<engine>();

  e->start_up();
  e->run();
  e->shut_down();

  return 0;
}