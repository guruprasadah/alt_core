#pragma once

#include <stdint.h>
#include <string.h>

// Convenience typedefs
using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
	
using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using usize = size_t;
using ssize = intmax_t;

using f32 = float;
using f64 = double;

namespace alt {
	template <typename T>
    concept IntegralType = requires (T t, T * p, void (*f)(T)) // T* parameter excludes reference types
    {
        reinterpret_cast<T>(t); // Exclude class types
        f(0); // Exclude enumeration types
        p + t; // Exclude everything not yet excluded but integral types
    };
}