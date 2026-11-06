#pragma once
#include <cstdint>
#include <string>
#include <string_view>

namespace repo1 {

// Hundredths of a degree Celsius: 512 = 5.12 C
using CentiCelsius = std::int32_t;

enum class Status { Ok, TooCold, TooWarm };

Status classify(CentiCelsius value, CentiCelsius low, CentiCelsius high) noexcept;
std::string format(CentiCelsius value);
std::string_view to_string(Status status) noexcept;

}  // namespace repo1