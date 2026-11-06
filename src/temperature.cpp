#include "repo1/temperature.hpp"
#include <format>

namespace repo1 {

Status classify(CentiCelsius value, CentiCelsius low, CentiCelsius high) noexcept {
    if (value < low)  return Status::TooCold;
    if (value > high) return Status::TooWarm;
    return Status::Ok;
}

std::string format(CentiCelsius value) {
    const bool negative = value < 0;
    const std::int64_t abs = negative ? -static_cast<std::int64_t>(value) : value;
    return std::format("{}{}.{:02} C", negative ? "-" : "", abs / 100, abs % 100);
}

std::string_view to_string(Status status) noexcept {
    switch (status) {
    case Status::Ok:      return "ok";
    case Status::TooCold: return "too cold";
    case Status::TooWarm: return "too warm";
    }
    return "unknown";
}

}  // namespace repo1