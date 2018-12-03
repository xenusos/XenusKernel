#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>

#include "xenus_syscall.h"

asmlinkage size_t  sys_xenuscall(uint8_t id, size_t a, size_t b, size_t c, size_t d)
{
	if (current->group_leader->xenus.syscall_kp_attention_callback)	
		return current->group_leader->xenus.syscall_kp_attention_callback(id, a, b, c, d);
	else if (current->xenus.syscall_kt_attention_callback)	
		return current->xenus.syscall_kt_attention_callback(id, a, b, c, d);
	return 0xDEAD01010101;
}
