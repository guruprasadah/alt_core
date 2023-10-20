#pragma once

#include "util.hpp"
#include "array.hpp"
#include "hash.hpp"

namespace alt {
	template <typename K, typename V, u64 Size>
	class HashTable {
	public:
		class Bucket {
		public:
			K key;
			V value;
		};

		Array<Bucket> data;

		HashTable(Allocator& _allocator = Allocator::get_default()) : data(_allocator) {
			data.resize(Size);
		}

		void insert(const Bucket& _val) {
			this->data[hash(_val.key) % Size] = _val;
		}

		V& operator[](const K& _key) {
			return this->data[hash(_key) % Size].value;
		}
	};
}