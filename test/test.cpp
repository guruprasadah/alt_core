#include <alt/memory.hpp>
#include <alt/array.hpp>
#include <alt/string.hpp>
#include <alt/hash.hpp>
#include <alt/hash_table.hpp>
#include <alt/list.hpp>
#include <stdio.h>

int main() {
	alt::DefaultAllocator a;
	
	alt::List<f32> l;

	l.create_node(42);

	printf("%f\n", l.first->value);

	return 0;
}