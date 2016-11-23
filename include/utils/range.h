#ifndef RANGE_H
#define RANGE_H
#include <cstddef>

namespace Utilities {
  class Range {
  public:
    Range(std::size_t max);
    Range(std::size_t value, std::size_t max);
    Range(std::size_t value, std::size_t max, std::size_t step);
    
    Range& operator++();
    operator bool();
    std::size_t operator*() const;
    
  private:
    std::size_t value = 0U;
    std::size_t max;
    std::size_t step = 1U;
  };
}

#endif
