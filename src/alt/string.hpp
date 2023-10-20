#pragma once

#include "array.hpp"

namespace alt {
	class String {
	public:
		Array<u8> data;

		String() : data(Allocator::get_default()) {}

		String(const char* _str) : data(Allocator::get_default()) {
			*this = _str;
		}
		
		void operator=(const char*);

		u8 operator[](usize _idx);
		
		void append(const String& _rhs);

		void* get_memory();
	};
};