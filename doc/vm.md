## 变量说明
### pte_t
定义： riscv.h:typedef uint64 pte_t

说明：表示一个页表项（PTE）的 64 位值
布局：

### pagetable_t
定义： riscv.h:typedef uint64 *pagetable_t

说明：表示指向页表页的指针

## 函数说明
kvmmake：创建并初始化内核页表，建立内核 text/data 直接映射，并映射 TRAMPOLINE。
kvm_init：初始化全局内核页表 kernel_pagetable，写入 satp 并刷新 TLB，开启分页。
walk：在给定页表中查找虚拟地址 va 对应的 PTE；必要时按层分配中间页表页。
walkaddr：查找用户虚拟地址对应的物理地址（要求 PTE 有效且用户可访问），否则返回 0。
useraddr：返回带页内偏移的完整物理地址（基于 walkaddr）。
kvmmap：内核启动阶段使用的映射函数，调用 mappages 建立映射，失败则 panic。
mappages：为虚拟地址区间建立页映射到物理地址区间，可处理非页对齐的起止，返回 0/-1。
uvmunmap：取消用户页映射，可选择释放物理页；要求 va 页对齐。
uvmcreate：创建空的用户页表，并映射 TRAMPOLINE。
freewalk：递归释放页表页（只允许中间页表；叶子映射必须提前清理）。
uvmfree：释放用户内存页，再释放页表页。
copyout：从内核拷贝到用户虚拟地址空间，跨页处理，失败返回 -1。
copyin：从用户虚拟地址空间拷贝到内核缓冲区，跨页处理，失败返回 -1。
copyinstr：从用户虚拟地址空间拷贝以 \0 结尾的字符串到内核，最多 max 字节，返回已拷贝长度或 -1。
uvmalloc：从 oldsz 扩展到 newsz，为新页分配物理页并映射；失败回滚，返回 0 或新大小。
uvmdealloc：从 oldsz 缩小到 newsz，解除并释放多余页，返回新大小。