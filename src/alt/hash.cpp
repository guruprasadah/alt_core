#include "hash.hpp"
#include "memory.hpp"
#include "string.hpp"

namespace alt {
	u64 hash(const String& _str) {
		return hash(_str.data.mem, _str.data.len);
	}
	
	u64 hash(const void* _ptr, usize _size)
	{
		const u64 m = 0xc6a4a7935bd1e995ULL;
		const u32 r = 47;

		u64 h = 42 ^ (_size * m);

		const u64* data = (const u64*)_ptr;
		const u64* end = data + (_size / 8);

		while (data != end)
		{
#ifdef PLATFORM_BIG_ENDIAN
			u64 k = *data++;
			char* p = (char*)&k;
			char c;
			c = p[0]; p[0] = p[7]; p[7] = c;
			c = p[1]; p[1] = p[6]; p[6] = c;
			c = p[2]; p[2] = p[5]; p[5] = c;
			c = p[3]; p[3] = p[4]; p[4] = c;
#else
			u64 k = *data++;
#endif

			k *= m;
			k ^= k >> r;
			k *= m;

			h ^= k;
			h *= m;
		}

		const unsigned char* data2 = (const unsigned char*)data;

		switch (_size & 7)
		{
		case 7: h ^= u64(data2[6]) << 48;
		case 6: h ^= u64(data2[5]) << 40;
		case 5: h ^= u64(data2[4]) << 32;
		case 4: h ^= u64(data2[3]) << 24;
		case 3: h ^= u64(data2[2]) << 16;
		case 2: h ^= u64(data2[1]) << 8;
		case 1: h ^= u64(data2[0]);
			h *= m;
		};

		h ^= h >> r;
		h *= m;
		h ^= h >> r;

		return h;
	}
}