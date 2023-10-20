#pragma once

#include "util.hpp"

namespace alt {
	class Allocator {
	public:
		virtual void* alloc(usize _size, usize _align = 1) = 0;
		virtual usize get_size(void* _mem, usize _align) = 0;
		virtual void free(void* _mem) = 0;

		static Allocator& get_default();
	};

	class DefaultAllocator : public Allocator {
	public:
		void* alloc(usize _size, usize _align = 1) override;
		usize get_size(void* _mem, usize align);
		void free(void* _mem) override;
	};
}