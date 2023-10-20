#include "string.hpp"
#include <string.h>

namespace alt {
	void String::operator=(const char* _rhs) {
		usize l = strlen(_rhs);
		this->data.resize(l + 1);
		strcpy(static_cast<char*>(this->data.mem), _rhs);
	}

	u8 String::operator[](usize _idx) {
		return this->data[_idx];
	}
	
	void String::append(const String& _rhs) {
		this->data.pop();
		this->data.append(_rhs.data);
	}

	void* String::get_memory() {
		return this->data.mem;
	}
}