#ifndef PLAT_VIRT_H
#define PLAT_VIRT_H

// Base addresses for QEMU virt machine
#define VA_START 0xffff000000000000
#define PHY_START 0x40000000

// UART
#define UART_BASE 0x09000000

// GIC (Generic Interrupt Controller)
#define QEMU_GIC_DIST_BASE 0x08000000
#define QEMU_GIC_CPU_BASE 0x08010000

// Timer
#define TIMER_BASE 0x09040000

// Interrupt numbers
#define IRQ_ARM_GENERIC_TIMER 27
#define IRQ_UART_PL011 33
#define IRQ_VIRTIO0 40

#endif
