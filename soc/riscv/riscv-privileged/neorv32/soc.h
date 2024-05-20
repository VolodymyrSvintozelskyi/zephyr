/*
 * Copyright (c) 2021 Henrik Brix Andersen <henrik@brixandersen.dk>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RISCV_NEORV32_SOC_H
#define RISCV_NEORV32_SOC_H

#include <soc_common.h>

/* System information (SYSINFO) register offsets */
#define NEORV32_SYSINFO_CLK         0x00U
#define NEORV32_SYSINFO_CPU         0x1c0U
#define NEORV32_SYSINFO_FEATURES    0x08U
#define NEORV32_SYSINFO_CACHE       0x0cU
#define NEORV32_SYSINFO_IMEM_SIZE   0x04U
#define NEORV32_SYSINFO_DMEM_SIZE   0x05U

/* System information (SYSINFO) CPU register bits */
#define NEORV32_SYSINFO_CPU_ZICSR     BIT(0)
#define NEORV32_SYSINFO_CPU_ZIFENCEI  BIT(1)
#define NEORV32_SYSINFO_CPU_ZMMUL     BIT(2)
#define NEORV32_SYSINFO_CPU_ZXCFU     BIT(3)
#define NEORV32_SYSINFO_CPU_SMCNTRPMF BIT(4)
#define NEORV32_SYSINFO_CPU_ZFINX     BIT(5)
#define NEORV32_SYSINFO_CPU_ZICOND    BIT(6)
#define NEORV32_SYSINFO_CPU_ZICNTR    BIT(7)
#define NEORV32_SYSINFO_CPU_PMP       BIT(8)
#define NEORV32_SYSINFO_CPU_ZIHPM     BIT(9)
#define NEORV32_SYSINFO_CPU_SDEXT     BIT(10)
#define NEORV32_SYSINFO_CPU_SDTRIG    BIT(11)
#define NEORV32_SYSINFO_CPU_IS_SIM    BIT(20)
#define NEORV32_SYSINFO_CPU_RFHWRST   BIT(29)
#define NEORV32_SYSINFO_CPU_FASTMUL   BIT(30)
#define NEORV32_SYSINFO_CPU_FASTSHIFT BIT(31)

/* System information (SYSINFO) FEATURES register bits */
#define NEORV32_SYSINFO_FEATURES_BOOTLOADER     BIT(0)
#define NEORV32_SYSINFO_FEATURES_MEM_EXT        BIT(1)
#define NEORV32_SYSINFO_FEATURES_MEM_INT_IMEM   BIT(2)
#define NEORV32_SYSINFO_FEATURES_MEM_INT_DMEM   BIT(3)
#define NEORV32_SYSINFO_FEATURES_MEM_EXT_ENDIAN BIT(4)
#define NEORV32_SYSINFO_FEATURES_ICACHE         BIT(5)
#define NEORV32_SYSINFO_FEATURES_DCACHE         BIT(6)
#define NEORV32_SYSINFO_FEATURES_IO_CRC         BIT(12)
#define NEORV32_SYSINFO_FEATURES_IO_SLINK       BIT(13)
#define NEORV32_SYSINFO_FEATURES_IO_DMA         BIT(14)
#define NEORV32_SYSINFO_FEATURES_IO_GPIO        BIT(15)
#define NEORV32_SYSINFO_FEATURES_IO_MTIME       BIT(16)
#define NEORV32_SYSINFO_FEATURES_IO_UART0       BIT(17)
#define NEORV32_SYSINFO_FEATURES_IO_SPI         BIT(18)
#define NEORV32_SYSINFO_FEATURES_IO_TWI         BIT(19)
#define NEORV32_SYSINFO_FEATURES_IO_PWM         BIT(20)
#define NEORV32_SYSINFO_FEATURES_IO_WDT         BIT(21)
#define NEORV32_SYSINFO_FEATURES_IO_CFS         BIT(22)
#define NEORV32_SYSINFO_FEATURES_IO_TRNG        BIT(23)
#define NEORV32_SYSINFO_FEATURES_IO_SDI         BIT(24)
#define NEORV32_SYSINFO_FEATURES_IO_UART1       BIT(25)
#define NEORV32_SYSINFO_FEATURES_IO_NEOLED      BIT(26)
#define NEORV32_SYSINFO_FEATURES_IO_XIRQ        BIT(27)
#define NEORV32_SYSINFO_FEATURES_IO_GPTMR       BIT(28)
#define NEORV32_SYSINFO_FEATURES_IO_XIP         BIT(29)
#define NEORV32_SYSINFO_FEATURES_IO_ONEWIRE     BIT(30)
#define NEORV32_SYSINFO_FEATURES_OCD            BIT(31)

#define TRAP_CODE_I_MISALIGNED 0x00000000U /**< 0.0:  Instruction address misaligned */
#define TRAP_CODE_I_ACCESS     0x00000001U /**< 0.1:  Instruction (bus) access fault */
#define TRAP_CODE_I_ILLEGAL    0x00000002U /**< 0.2:  Illegal instruction */
#define TRAP_CODE_BREAKPOINT   0x00000003U /**< 0.3:  Breakpoint (EBREAK instruction) */
#define TRAP_CODE_L_MISALIGNED 0x00000004U /**< 0.4:  Load address misaligned */
#define TRAP_CODE_L_ACCESS     0x00000005U /**< 0.5:  Load (bus) access fault */
#define TRAP_CODE_S_MISALIGNED 0x00000006U /**< 0.6:  Store address misaligned */
#define TRAP_CODE_S_ACCESS     0x00000007U /**< 0.7:  Store (bus) access fault */
#define TRAP_CODE_UENV_CALL    0x00000008U /**< 0.8:  Environment call from user mode (ECALL instruction) */
#define TRAP_CODE_MENV_CALL    0x0000000bU /**< 0.11: Environment call from machine mode (ECALL instruction) */
#define TRAP_CODE_MSI          0x80000003U /**< 1.3:  Machine software interrupt */
#define TRAP_CODE_MTI          0x80000007U /**< 1.7:  Machine timer interrupt */
#define TRAP_CODE_MEI          0x8000000bU /**< 1.11: Machine external interrupt */
#define TRAP_CODE_FIRQ_0       0x80000010U /**< 1.16: Fast interrupt channel 0 */
#define TRAP_CODE_FIRQ_1       0x80000011U /**< 1.17: Fast interrupt channel 1 */
#define TRAP_CODE_FIRQ_2       0x80000012U /**< 1.18: Fast interrupt channel 2 */
#define TRAP_CODE_FIRQ_3       0x80000013U /**< 1.19: Fast interrupt channel 3 */
#define TRAP_CODE_FIRQ_4       0x80000014U /**< 1.20: Fast interrupt channel 4 */
#define TRAP_CODE_FIRQ_5       0x80000015U /**< 1.21: Fast interrupt channel 5 */
#define TRAP_CODE_FIRQ_6       0x80000016U /**< 1.22: Fast interrupt channel 6 */
#define TRAP_CODE_FIRQ_7       0x80000017U /**< 1.23: Fast interrupt channel 7 */
#define TRAP_CODE_FIRQ_8       0x80000018U /**< 1.24: Fast interrupt channel 8 */
#define TRAP_CODE_FIRQ_9       0x80000019U /**< 1.25: Fast interrupt channel 9 */
#define TRAP_CODE_FIRQ_10      0x8000001aU /**< 1.26: Fast interrupt channel 10 */
#define TRAP_CODE_FIRQ_11      0x8000001bU /**< 1.27: Fast interrupt channel 11 */
#define TRAP_CODE_FIRQ_12      0x8000001cU /**< 1.28: Fast interrupt channel 12 */
#define TRAP_CODE_FIRQ_13      0x8000001dU /**< 1.29: Fast interrupt channel 13 */
#define TRAP_CODE_FIRQ_14      0x8000001eU /**< 1.30: Fast interrupt channel 14 */
#define TRAP_CODE_FIRQ_15      0x8000001fU  /**< 1.31: Fast interrupt channel 15 */

#endif /* RISCV_NEORV32_SOC_H */
