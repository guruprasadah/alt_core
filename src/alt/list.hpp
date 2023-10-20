#pragma once

#include "memory.hpp"

namespace alt {
	template <typename T>
	class List {
	public:
		class Node {
		public:
			Node* prev = nullptr, *next = nullptr;
			T value;

			operator T() {
				return value;
			}
		};
		
		Allocator* allocator;
		Node* first;

		List(Allocator& _allocator = Allocator::get_default()) : allocator(&_allocator), first(nullptr) {}

		Node* create_node(const T& _val = {}) {
			auto n = reinterpret_cast<Node*>(this->allocator->alloc(sizeof(Node)));
			if (!this->first) {
				this->first = n;
				*this->first = { nullptr, nullptr, _val };
			} else {
				this->first->next->prev = n;
				this->first->next = n;
			}
			return n;
		}
	};
}