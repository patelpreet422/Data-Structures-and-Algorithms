#include <iostream>
#include <cmath>
#include <iterator>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>

using namespace std;

namespace mnp {
    template <typename Itr, typename T>
    auto rank(Itr begin, Itr end, T k) -> size_t {
        return std::lower_bound(begin, end, k) - begin;
    }
    
    template <typename InputItr1, typename InputItr2, typename OutputItr>
    void cross(InputItr1 i1begin, InputItr1 i1end, InputItr2 i2begin, InputItr2 i2end, OutputItr outputItr)
    {
        while(i1begin != i1end) {
            InputItr2 i = i2begin;

            while (i != i2end) {
                *outputItr = {*i1begin, *i};
                ++i;
                ++outputItr;
            }
            advance(i1begin, 1);
        }
    }

    template <typename InputItr1, typename InputItr2, typename OutputItr>
    void zip(InputItr1 i1begin, InputItr1 i1end, InputItr2 i2begin, InputItr2 i2end, OutputItr outputItr)
    {
        while((i1begin != i1end) && (i2begin != i2end)) {
            *outputItr = {*i1begin, *i2begin};
            ++i1begin;
            ++i2begin;
            ++outputItr;
        }
    }

    template <typename InputItr, typename T>
    constexpr T sum(InputItr begin, InputItr end, T accumulator)
    {
        return accumulate(begin, end, accumulator);
    }

    template <typename InputItr, typename T>
    constexpr T product(InputItr begin, InputItr end, T accumulator)
    {
        return accumulate(begin, end, accumulator, std::multiplies{});
    }
}

namespace mnp {
    constexpr auto lt = [](auto a, auto b){ return a < b; };
    constexpr auto lteq = [](auto a, auto b){ return (a < b) || (a == b); };
    constexpr auto gt = [](auto a, auto b){ return !(a < b) && !(a == b); };
    constexpr auto gteq = [](auto a, auto b){ return !(a < b); };
    constexpr auto eq = [](auto a, auto b){ return a == b; };
    constexpr auto nteq = [](auto a, auto b){ return !(a == b); };

    constexpr auto lt_value = [](auto a) { return [a](auto b){ return b < a; };};
    constexpr auto lteq_value = [](auto a) { return [a](auto b){ return (b < a) || (b == a); };};
    constexpr auto gt_value = [](auto a) { return [a](auto b){ return !(b < a) && !(b == a); };};
    constexpr auto gteq_value = [](auto a) { return [a](auto b){ return !(b < a); };};
    constexpr auto eq_value = [](auto a) { return [a](auto b){ return b == a; };};
    constexpr auto nteq_value = [](auto a) { return [a](auto b){ return !(b == a); };};

    constexpr auto min = [](auto a, auto b){ return std::min(a, b); };
    constexpr auto max = [](auto a, auto b){ return std::max(a, b); };

    constexpr auto logical_or = [](auto a, auto b){ return a || b; };
    constexpr auto logical_and = [](auto a, auto b){ return a && b; };
    constexpr auto logical_xor = [](auto a, auto b){ return a ^ b; };
    constexpr auto logical_not = [](auto a){ return ~a; };

    constexpr auto logical_or_value = [](auto a){ return [a](auto b){ return a || b; };};
    constexpr auto logical_and_value = [](auto a){ return [a](auto b){ return a && b; };};
    constexpr auto logical_xor_value = [](auto a){ return [a](auto b){ return a ^ b; };};

    constexpr auto sin = [](auto a){ return std::sin(a); };
    constexpr auto cos = [](auto a){ return std::cos(a); };
    constexpr auto tan = [](auto a){ return std::tan(a); };
    constexpr auto pow = [](auto a, auto b){ return std::pow(a, b); };
    constexpr auto log = [](auto a, auto b){ return std::log(a, b); };
    constexpr auto log2 = [](auto a, auto b){ return std::log2(a, b); };
    constexpr auto log2f = [](auto a, auto b){ return std::log2f(a, b); };
    constexpr auto log2l = [](auto a, auto b){ return std::log2l(a, b); };
}
