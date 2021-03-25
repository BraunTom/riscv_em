#ifndef RISCV_CSR_H
#define RISCV_CSR_H

#include <riscv_types.h>

#define CSR_ACCESS_READ (1<<0)
#define CSR_ACCESS_WRITE (1<<1)
#define CSR_ACCESS_RO(_priv_level) (CSR_ACCESS_READ << (_priv_level*2))
#define CSR_ACCESS_WO(_priv_level) (CSR_ACCESS_WRITE << (_priv_level*2))
#define CSR_ACCESS_RW(_priv_level) ((CSR_ACCESS_WRITE | CSR_ACCESS_READ) << (_priv_level*2))
#define CSR_ACCESS_READ_GRANTED(_priv_level, _csr_access_flags) (CSR_ACCESS_RO(_priv_level) & _csr_access_flags)
#define CSR_ACCESS_WRITE_GRANTED(_priv_level, _csr_access_flags) (CSR_ACCESS_WO(_priv_level) & _csr_access_flags)

#define STATUS_REG 0x00
#define EDELEG_REG 0x02
#define IDELEG_REG 0x03
#define TVEC_REG   0x05
#define EPC_REG    0x41
#define CAUSE_REG  0x42

#define CSR_ADDR_MVENDORID 0xF11
#define CSR_ADDR_MARCHID   0xF12
#define CSR_ADDR_MIMPID    0xF13
#define CSR_ADDR_MHARTID   0xF14

#define CSR_ADDR_MSTATUS      0x300
#define CSR_ADDR_MISA         0x301
#define CSR_ADDR_MEDELEG      0x302
#define CSR_ADDR_MIDELEG      0x303
#define CSR_ADDR_MIE          0x304
#define CSR_ADDR_MTVEC        0x305
#define CSR_ADDR_MCOUNTEREN   0x305

#define CSR_ADDR_MSCRATCH     0x340
#define CSR_ADDR_MEPC         0x341
#define CSR_ADDR_MCAUSE       0x342
#define CSR_ADDR_MTVAL        0x343
#define CSR_ADDR_MIP          0x344

#define CSR_PMPCFG0           0x3A0
#define CSR_PMPCFG1           0x3A1
#define CSR_PMPCFG2           0x3A2
#define CSR_PMPCFG3           0x3A3
#define CSR_PMPADDR0          0x3B0
#define CSR_PMPADDR1          0x3B1
#define CSR_PMPADDR2          0x3B2
#define CSR_PMPADDR3          0x3B3
#define CSR_PMPADDR4          0x3B4
#define CSR_PMPADDR5          0x3B5
#define CSR_PMPADDR6          0x3B6
#define CSR_PMPADDR7          0x3B7
#define CSR_PMPADDR8          0x3B8
#define CSR_PMPADDR9          0x3B9
#define CSR_PMPADDR10         0x3BA
#define CSR_PMPADDR11         0x3BB
#define CSR_PMPADDR12         0x3BC
#define CSR_PMPADDR13         0x3BD
#define CSR_PMPADDR14         0x3BE
#define CSR_PMPADDR15         0x3BF

/* Supervisor CSRs */
#define CSR_ADDR_SSTATUS      0x100
#define CSR_ADDR_SEDELEG      0x102
#define CSR_ADDR_SIDELEG      0x103
#define CSR_ADDR_SIE          0x104
#define CSR_ADDR_STVEC        0x105
#define CSR_ADDR_SCOUNTEREN   0x106

#define CSR_ADDR_SSCRATCH     0x140
#define CSR_ADDR_SEPC         0x141
#define CSR_ADDR_SCAUSE       0x142
#define CSR_ADDR_STVAL        0x143
#define CSR_ADDR_SIP          0x144

#define CSR_ADDR_MAX          0xFFF

/* Machine Mode CSR bits and masks */
/* Interrupt MCAUSE */
#define CSR_MCAUSE_MSI 3
#define CSR_MCAUSE_MTI 7
#define CSR_MCAUSE_MEI 11

/* Sync MCAUSE */
#define CSR_MCAUSE_INSTR_ADDR_MISALIGNED 0
#define CSR_MCAUSE_INSTR_ACCESS_FAULT 1
#define CSR_MCAUSE_ILLEGAL_INSTR 2
#define CSR_MCAUSE_LOAD_ACCESS_FAULT 5
#define CSR_MCAUSE_STORE_AMO_ACCESS_FAULT 7
#define CSR_MCAUSE_ECALL_U 8
#define CSR_MCAUSE_ECALL_S 9
#define CSR_MCAUSE_ECALL_RSVD 10
#define CSR_MCAUSE_ECALL_M 11

// /* MSTATUS */
// #define CSR_MSTATUS_MIE_BIT 3
// #define CSR_MSTATUS_MIE_MASK 0x1
// #define CSR_MSTATUS_MPIE_BIT 7
// #define CSR_MSTATUS_SPP_BIT 8
// #define CSR_MSTATUS_MPP_BIT 11 /* and 12 */
// #define CSR_MSTATUS_MPP_MASK 0x3
// #define CSR_MSTATUS_MPRV_BIT 17

#define CSR_MIE_MIP_MSI_BIT 3
#define CSR_MIE_MIP_MTI_BIT 7
#define CSR_MIE_MIP_MEI_BIT 11

// /* Supervisor CSR bits and masks */
// #define CSR_SSTATUS_SPP_BIT 8
// #define CSR_SSTATUS_SPIE_BIT 5
// #define CSR_SSTATUS_SIE_BIT 1
// #define CSR_SSTATUS_SIE_MASK 0x1


/* CSR WRITE MASKS */
#ifdef RV64
    #define CSR_MASK_WR_ALL 0xFFFFFFFFFFFFFFFF
    #define CSR_MSTATUS_WR_MASK 0x8000000F007FF9BB
    #define CSR_MTVEC_WR_MASK 0xFFFFFFFFFFFFFFFC

    #define CSR_SSTATUS_WR_MASK 0x80000003000DE133
#else
    #define CSR_MASK_WR_ALL 0xFFFFFFFF
    #define CSR_MSTATUS_WR_MASK 0x807FF9BB
    #define CSR_MTVEC_WR_MASK 0xFFFFFFFC

    #define CSR_SSTATUS_WR_MASK 0x800DE133
#endif
#define CSR_MASK_ZERO 0
#define CSR_MIP_MIE_WR_MASK 0xBBB
#define CSR_MIDELEG_WR_MASK CSR_MIP_MIE_WR_MASK
/* In particular, medeleg[11] are hardwired to zero. */
#define CSR_MEDELEG_MASK 0xF3FF

#define CSR_STVEC_WR_MASK CSR_MTVEC_WR_MASK
#define CSR_SIP_SIE_WR_MASK 0x333
#define CSR_SIDELEG_WR_MASK CSR_SIP_SIE_WR_MASK
/* In particular, sedeleg[11:9] are all hardwired to zero. */
#define CSR_SEDELEG_WR_MASK 0xF1FF

typedef int (*csr_read_cb)(void *priv, privilege_level curr_priv_mode, uint16_t address, rv_uint_xlen *out_val);
typedef int (*csr_write_cb)(void *priv, privilege_level curr_priv_mode, uint16_t address, rv_uint_xlen val, rv_uint_xlen mask);

typedef struct csr_reg_struct {
    uint16_t access_flags;
    rv_uint_xlen value;
    rv_uint_xlen write_mask;

    /* used if special handling is needed for e.g. pmp */
    void *priv;
    csr_read_cb read_cb;
    csr_write_cb write_cb;
    int internal_reg;

} csr_reg_td;

rv_uint_xlen *csr_get_reg_reference(csr_reg_td *csr_regs, uint16_t address);

void csr_read_reg_internal(csr_reg_td *csr_regs, uint16_t address, rv_uint_xlen *out_val);
void csr_write_reg_internal(csr_reg_td *csr_regs, uint16_t address, rv_uint_xlen val);

int csr_read_reg(csr_reg_td *csr_regs, privilege_level curr_priv_mode, uint16_t address, rv_uint_xlen *out_val);
int csr_write_reg(csr_reg_td *csr_regs, privilege_level curr_priv_mode, uint16_t address, rv_uint_xlen val);

#endif /* RISCV_CSR_H */
