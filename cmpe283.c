/**
 * @file	cmpe283.c
 * @author	Mike Larkin
 * @date	04 May 2017
 * @version	0.1
 * @brief	Test module for the CMPE283 bonus lab assignment
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("BSD");
MODULE_AUTHOR("Mike Larkin");
MODULE_DESCRIPTION("Test module for the CMPE283 bonus lab assignment");
MODULE_VERSION("0.1");

#define NEWCPUID(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F3B, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "c" (subfunc))

#define NEWCPUID2(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F3C, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "c" (subfunc))

#define GETCTR(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F3D, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "c" (subfunc))

#define GETCTR2(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F3E, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "c" (subfunc))

#define LOADCTR(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F3F, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "c" (subfunc))

#define LOADCTR2(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F24, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "b" (subfunc))

#define LOADCTR3(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F25, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "c" (subfunc))

#define LOADCTR4(func, subfunc, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F26, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "d" (subfunc))

#define LOADCTR5(func, rsi, eax, ebx, ecx, edx) \
	asm __volatile("rolq $0x20, %%rax\norq $0x0F27, %%rax\nvmcall" : \
	    "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx) : \
	    "a" (func), "S" (rsi))




/** @brief Test function for "NEWCPUID" hypercall
 */
static void test_newcpuid(void)
{
	uint32_t eax, ebx, ecx, edx;
	printk(KERN_INFO "%s: ----Testing NEWCPUID\n", __func__);
	
	/* Test function 0 */
	NEWCPUID(0x0D, 0x0, eax, ebx, ecx, edx);
	NEWCPUID(0x0D, 0x1, eax, ebx, ecx, edx);
	NEWCPUID(0x0D, 0x2, eax, ebx, ecx, edx);
}

/** @brief Test function for "NEWCPUID2" hypercall
 */
static void test_newcpuid2(void)
{
	uint32_t eax, ebx, ecx, edx;
	printk(KERN_INFO "%s: ----Testing NEWCPUID2\n", __func__);
	
	/* Test function 0 */
	NEWCPUID2(0xA0000000, 0, eax, ebx, ecx, edx);
}


/** @brief Test function for "GETCTR" hypercall
 */
static void test_getctr(void)
{
	uint32_t eax, ebx, ecx, edx;
	printk(KERN_INFO "%s: ----Testing GETCTR\n", __func__);
	
	/* Test function 0 */
	GETCTR(0, 0, eax, ebx, ecx, edx);
	printk(KERN_INFO "%s:  Function 0:\n", __func__);
	printk(KERN_INFO "%s:   %%eax=0x%x\n", __func__, eax);
	//printk(KERN_INFO "%s:   %%ebx=0x%x\n", __func__, ebx);
	//printk(KERN_INFO "%s:   %%ecx=0x%x\n", __func__, ecx);
	//printk(KERN_INFO "%s:   %%edx=0x%x\n", __func__, edx);
}

/** @brief Test function for "GETCTR" hypercall
 */
static void test_getctr2(void)
{
	uint32_t eax, ebx, ecx, edx;
	printk(KERN_INFO "%s: ----Testing GETCTR\n", __func__);
	
	//GETCTR2(0xFFFFFFFF, 0, eax, ebx, ecx, edx);

	/* Test function 0 */
	long i;
	for(i = 0; i <2; i++){
	GETCTR2(0, 0, eax, ebx, ecx, edx);
	}
	
	
	//GETCTR2(0xFFFFFFFF, 0, eax, ebx, ecx, edx);
	//printk(KERN_INFO "%s:   %%eax=0x%x\n", __func__, eax);
	
	GETCTR2(0, 0, eax, ebx, ecx, edx);
	printk(KERN_INFO "%s:   %%eax=0x%x\n", __func__, eax);

}

/** @brief Test function for "LOADCTR" hypercall
 */
static void test_loadctr(void)
{
	uint32_t eax, ebx, ecx, edx;
	uint64_t value = 0xABCDEFAB;
	printk(KERN_INFO "%s: ----Testing LOADCTR\n", __func__);
	printk(KERN_INFO "value %lx\n",value);
	printk(KERN_INFO "address %lx\n",&value);
	printk(KERN_INFO "addressvalue %lx\n",*(&value));


	//LOADCTR(0x12345, 0, eax, ebx, ecx, edx);
	//LOADCTR2(0, 0x23456, eax, ebx, ecx, edx);
	//LOADCTR3(0, 0x34567, eax, ebx, ecx, edx);
	//LOADCTR4(0, 0x45678, eax, ebx, ecx, edx);
	LOADCTR5(0, &value, eax, ebx, ecx, edx);

	
	GETCTR2(0, 0, eax, ebx, ecx, edx);
	GETCTR2(0, 0, eax, ebx, ecx, edx);

	//printk(KERN_INFO "%s:   %%eax=0x%x\n", __func__, eax);
	
	//GETCTR2(0, 0, eax, ebx, ecx, edx);
	printk(KERN_INFO "%s:   %%eax=0x%x\n", __func__, eax);

}



/** @brief Module initialization function
 *  @return 0 if successful
 */
static int __init cmpe283_init(void)
{
	printk(KERN_INFO "%s: Entering CMPE283 bonus lab test module\n",
	    __func__);

	//test_newcpuid();
	//test_newcpuid2();
	//test_getctr();
	//test_getctr2();
	test_loadctr();
	return 0;
}

/** @brief Module cleanup function
 */
static void __exit cmpe283_exit(void)
{
	printk(KERN_INFO "%s: Exiting CMPE283 bonus lab test module\n",
	    __func__);
}

/** @brief Identification of the module init and exit routines
 */
module_init(cmpe283_init);
module_exit(cmpe283_exit);
