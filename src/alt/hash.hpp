#pragma once

#include "util.hpp"

namespace alt {
	class String;
	
	// Impl of murmurhash, stolen from https://github.com/niklas-ourmachinery/bitsquid-foundation/blob/master/murmur_hash.cpp, modified by Guruprasad AH
	u64 hash(const void* _ptr, usize _size);
	
	u64 hash(const String& _str);
};