#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

// Copy data from kernel buffer to user buffer.
// Returns 0 on success.
int copy_to_user(void *user_dst, const void *kernel_src, uint n);
// Copy data from user buffer to kernel buffer.
// Returns 0 on success.
int copy_from_user(void *kernel_dst, const void *user_src, uint n);

#endif // MEMORY_H
