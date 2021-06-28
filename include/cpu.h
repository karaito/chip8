#pragma once

#include <array>
#include <cstdint>


class Cpu{
    public:
        Cpu();
        ~Cpu();

        void setByte(uint8_t value, uint16_t addr);
        uint8_t readByte(uint16_t addr);

        void setReg(uint8_t value, uint8_t reg);
        uint8_t readReg(uint8_t reg);

        void setAddrReg(uint16_t value);
        uint16_t readAddrReg();

        void setPC(uint16_t value);
        uint16_t readPC();


    private:
        std::array <uint8_t, 0x1000> ram;
        std::array <uint8_t, 16> regs;
        uint16_t addr_reg;
        uint16_t prog_counter;

        const int SCREEN_WIDTH = 64;
        const int SCREEN_HEIGHT = 32;

        const int SCREEN_RES = SCREEN_WIDTH * SCREEN_HEIGHT;



    
};