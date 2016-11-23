#include "utils/range.h"

namespace Utilities {

  Range::Range(std::size_t _max) : max(_max) {
  }

  Range::Range(std::size_t _value, std::size_t _max) : value(_value), max(_max) {
  }

  Range::Range(std::size_t _value, std::size_t _max, std::size_t _step) :
    value(_value), max(_max), step(_step)  {
  }

  Range& Range::operator++() {
    value += step;
    return *this;
  }

  Range::operator bool() {
    return value < max;
  }

  std::size_t Range::operator*() const {
    return value;
  }

}

