#include <zephyr/neorv32/system_restart.h>

void mmu_rst_stack_protection() {
    const uint32_t MMU_BASE = 0xF0000A00; 
    uint32_t* rst_ptr = (uint32_t*) (MMU_BASE + 0x58);
    *rst_ptr = 0xFFFFFFFF;
}

inline void __attribute__ ((always_inline)) neorv32_cpu_csr_clr(const int csr_id, uint32_t mask) {
    uint32_t csr_data = mask;
    __asm__ volatile ("csrc %[input_i], %[input_j]" :  : [input_i] "i" (csr_id), [input_j] "r" (csr_data));
}

void restart_app(){ 
    // Restart the application
    neorv32_cpu_csr_clr(0x300, 1 << 3);
    mmu_rst_stack_protection();
    __asm__ volatile ("jalr zero, zero");
}