/*
 * Copyright (c) 2021 Henrik Brix Andersen <henrik@brixandersen.dk>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/irq.h>
#include <soc.h>
#include <stdio.h>

static void __attribute__((__naked__,aligned(4))) rte_handler(void) {
	// intro
	printf("<NEORV32-RTE> ");

	// privilege level of the CPU when the trap occurred
	if (csr_read(mstatus) & (3 << 11)) {
		printf("[M] "); // machine-mode
	}
	else {
		printf("[U] "); // user-mode
	}

	// cause
	uint32_t trap_cause = csr_read(mcause);
	switch (trap_cause) {
		case TRAP_CODE_I_MISALIGNED: printf("Instruction address misaligned"); break;
		case TRAP_CODE_I_ACCESS:     printf("Instruction access fault"); break;
		case TRAP_CODE_I_ILLEGAL:    printf("Illegal instruction"); break;
		case TRAP_CODE_BREAKPOINT:   printf("Breakpoint"); break;
		case TRAP_CODE_L_MISALIGNED: printf("Load address misaligned"); break;
		case TRAP_CODE_L_ACCESS:     printf("Load access fault"); break;
		case TRAP_CODE_S_MISALIGNED: printf("Store address misaligned"); break;
		case TRAP_CODE_S_ACCESS:     printf("Store access fault"); break;
		case TRAP_CODE_UENV_CALL:    printf("Environment call from U-mode"); break;
		case TRAP_CODE_MENV_CALL:    printf("Environment call from M-mode"); break;
		case TRAP_CODE_MSI:          printf("Machine software IRQ"); break;
		case TRAP_CODE_MTI:          printf("Machine timer IRQ"); break;
		case TRAP_CODE_MEI:          printf("Machine external IRQ"); break;
		case TRAP_CODE_FIRQ_0:
		case TRAP_CODE_FIRQ_1:
		case TRAP_CODE_FIRQ_2:
		case TRAP_CODE_FIRQ_3:
		case TRAP_CODE_FIRQ_4:
		case TRAP_CODE_FIRQ_5:
		case TRAP_CODE_FIRQ_6:
		case TRAP_CODE_FIRQ_7:
		case TRAP_CODE_FIRQ_8:
		case TRAP_CODE_FIRQ_9:
		case TRAP_CODE_FIRQ_10:
		case TRAP_CODE_FIRQ_11:
		case TRAP_CODE_FIRQ_12:
		case TRAP_CODE_FIRQ_13:
		case TRAP_CODE_FIRQ_14:
		case TRAP_CODE_FIRQ_15:      printf("Fast IRQ %x", (trap_cause & 0xf)); break;
		default:                     printf("Unknown trap cause %x", (trap_cause)); break;
	}

	//   // check if FIRQ
	//   if ((trap_cause >= TRAP_CODE_FIRQ_0) && (trap_cause <= TRAP_CODE_FIRQ_15)) {
	//     neorv32_cpu_csr_clr(CSR_MIP, 1 << (CSR_MIP_FIRQ0P + (trap_cause & 0xf))); // clear pending FIRQ
	//   }

	// instruction address
	printf(" @ PC=%lx", csr_read(833));

	// trap instruction
	printf(", MTINST=%lx", csr_read(842));

	// trap value
	printf(", MTVAL=%lx", csr_read(835));

	printf(" Halting CPU. </NEORV32-RTE>\n");
	while(1);
}

#if defined(CONFIG_RISCV_SOC_INTERRUPT_INIT)
void soc_interrupt_init(void)
{
	(void)arch_irq_lock();

	csr_write(mie, 0);

	__asm__ volatile("csrw	mtvec, %[input_j]" : : [input_j] "r" ((uint32_t) &rte_handler));
}
#endif
