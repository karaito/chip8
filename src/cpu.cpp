#include "cpu.h"

Cpu::Cpu() {
    setPC(0x200);
    
}

void Cpu::setByte(uint8_t value, uint16_t addr) {
    ram.at(addr) = value;
}

uint8_t Cpu::readByte(uint16_t addr) {
    return ram.at(addr);
}

void Cpu::setReg(uint8_t value, uint8_t addr) {
    regs.at(addr) = value;
}

uint8_t Cpu::readReg(uint8_t addr) {
    return regs.at(addr);
}

void Cpu::setAddrReg(uint16_t value) {
    addr_reg = value;
}

uint16_t Cpu::readAddrReg() {
    return addr_reg;
}

void Cpu::setPC(uint16_t value) {
    prog_counter = value;
}

uint16_t Cpu::readPC() {
    return prog_counter;
}


