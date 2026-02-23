#include "memory.h"
#include "string.h"

int copy_to_user(void *user_dst, const void *kernel_src, uint n)
{
	// Single address space: treat user memory as directly accessible.
	memmove(user_dst, kernel_src, n);
	return 0;
}

int copy_from_user(void *kernel_dst, const void *user_src, uint n)
{
	// Single address space: treat user memory as directly accessible.
	memmove(kernel_dst, user_src, n);
	return 0;
}
