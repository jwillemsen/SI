#pragma once

#include <chrono>
#include <ratio>

#include "detail/unit.h"
namespace SI {
/// @todo see how to get rid of duplicate typedefs
template <char _Exponent, typename _Type, typename _Ratio>
using time_t = detail::unit_t<'T', _Exponent, _Type, _Ratio>;

template <typename _Type, typename _Ratio>
using time_single_t = detail::unit_t<'T', 1, _Type, _Ratio>;

template <typename _Type> using seconds_t = time_single_t<_Type, std::ratio<1>>;
template <typename _Type>
using milli_seconds_t = time_single_t<_Type, std::chrono::milliseconds::period>;
template <typename _Type>
using micro_seconds_t = time_single_t<_Type, std::chrono::microseconds::period>;
template <typename _Type>
using minutes_t = time_single_t<_Type, std::chrono::minutes::period>;
template <typename _Type>
using hours_t = time_single_t<_Type, std::chrono::hours::period>;

template <typename _Type, typename _Ratio>
using time_squared_t = detail::unit_t<'T', 2, _Type, _Ratio>;

inline namespace literals {

template <char... _Digits> constexpr auto operator"" _us() {
  return SI::detail::check_overflow<SI::micro_seconds_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator"" _ms() {
  return SI::detail::check_overflow<SI::milli_seconds_t<int64_t>, _Digits...>();
}
template <char... _Digits> constexpr auto operator"" _s() {
  return SI::detail::check_overflow<SI::seconds_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator"" _min() {
  return SI::detail::check_overflow<SI::minutes_t<int64_t>, _Digits...>();
}

template <char... _Digits> constexpr auto operator"" _h() {
  return SI::detail::check_overflow<hours_t<int64_t>, _Digits...>();
}

constexpr auto operator"" _us(long double us) {
  return SI::micro_seconds_t<long double>{us};
}

constexpr auto operator"" _ms(long double ms) {
  return SI::milli_seconds_t<long double>{ms};
}

constexpr auto operator"" _s(long double s) {
  return SI::seconds_t<long double>{s};
}

constexpr auto operator"" _min(long double min) {
  return SI::minutes_t<long double>{min};
}

constexpr auto operator"" _h(long double h) {
  return SI::hours_t<long double>{h};
}

} // namespace literals
} // namespace SI