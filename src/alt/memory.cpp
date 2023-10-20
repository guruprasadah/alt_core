#include "memory.hpp"

#include <stdlib.h>

namespace alt {
	DefaultAllocator default_alloc;

	Allocator& Allocator::get_default() {
		return default_alloc;
	}
	
	void* DefaultAllocator::alloc(usize _size, usize _align) {
		return _aligned_malloc(_size, _align);
	}

	usize DefaultAllocator::get_size(void* _mem, usize _align) {
		return _aligned_msize(_mem, _align, 0);
	}

	void DefaultAllocator::free(void* _mem) {
		_aligned_free(_mem);
	}
}