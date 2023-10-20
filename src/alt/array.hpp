#pragma once

#include "memory.hpp"

#include <initializer_list>
#include <string.h>

namespace alt {
	template <typename T>
	class Array {
	public:
		Allocator* allocator;
		void* mem;
		usize size;
		usize len;

		Array(Allocator& _allocator = Allocator::get_default()) : allocator(&_allocator), len(0), mem(nullptr), size(0) {}

		~Array() {
			if (mem) {
				this->allocator->free(this->mem);
			}
		}

		T& operator[](u64 _idx) {
			return reinterpret_cast<T*>(this->mem)[_idx];
		}

		void append(const T& _elem) {
			if (this->size < this->len + 1) {
				auto mem = this->allocator->alloc(this->len + 2);
				memcpy(mem, this->mem, this->len * sizeof(T));
				this->allocator->free(this->mem);
				this->mem = mem;
			}
			reinterpret_cast<T*>(this->mem)[this->len] = _elem;
			this->len += 1;
		}

		void append(const Array<T>& _rhs) {
			if (this->size < this->len + _rhs.len + 1) {
				auto mem = this->allocator->alloc(this->len + _rhs.len + 2);
				memcpy(mem, this->mem, this->len * sizeof(T));
				this->allocator->free(this->mem);
				this->mem = mem;
			}
			memcpy(&(*this)[this->len], _rhs.mem, _rhs.len * sizeof(T));
			this->len += _rhs.len;
		}

		T pop() {
			if (this->size > this->len * 2) {
				auto mem = this->allocator->alloc(this->len + 2);
				memcpy(mem, this->mem, this->len * sizeof(T));
				this->allocator->free(this->mem);
				this->mem = mem;
			}
			this->len -= 1;
			return (*this)[this->len];
		}

		void resize(usize _len) {
			if (this->len == _len) {
				return;
			}
			if (this->size >= _len) {
				this->len = _len;
			} else {
				auto mem = this->allocator->alloc(_len + 2);
				memcpy(mem, this->mem, this->len * sizeof(T));
				this->allocator->free(this->mem);
				this->mem = mem;
				this->len = _len;
			}
		}

		void clear() {
			this->allocator->free(this->mem);
			this->len = 0;
		}
	};
}