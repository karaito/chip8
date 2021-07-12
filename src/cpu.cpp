#include "cpu.h"
#include <fstream>
#include <string>
#include <vector>

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

void Cpu::loadROM(std::string filename) {
    std::ifstream file_handle(filename, std::ios::binary | std::ios::ate);
    if (file_handle.is_open()) {
        std::streampos size = file_handle.tellg();
        char* buffer = new char[size];
        file_handle.seekg(0, std::ios::beg);
		file_handle.read(buffer, size);
		file_handle.close();

        for (long i = 0; i < size; ++i)
		{
			setByte(0x200 + i, buffer[i]);
		}

        delete[] buffer;

    }
}


