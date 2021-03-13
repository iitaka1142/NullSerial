/**
 * \brief NullSerial, a Serial like but no input/output
 * \author Takahiro Ii<iitaka1142@gmail.com>
 * \data 2021
 *
 * Copyright (c) 2021 Takahiro Ii all right reserved.
 * 
 * This file is part of NullSerial.
 *
 * NullSerial is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * NullSerial is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with NullSerial.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * https://github.com/iitaka1142/NullSerial/
 */
#ifndef __NULL_SERIAL_H__
#define __NULL_SERIAL_H__

#include <Arduino.h>

class NullSerial_ : public Stream
{
  protected:
    bool is_listening;

  public:
    NullSerial_() : is_listening(false) {}

    void begin(unsigned long baud) {}
    void begin(unsigned long, uint8_t) {}
    void end() {}
    virtual int available(void) { return 0;}
    virtual int peek(void) { return -1;}
    virtual int read(void) { return -1;}
    virtual int availableForWrite(void) { return INT16_MAX; };
    virtual void flush(void) {}
    virtual size_t write(uint8_t) { return 1;}
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }

    // immitate SoftwareSerial APIs
    bool listen() { bool ret = is_listening; is_listening = true; return ret; }
    bool isListening() { return is_listening; }
    bool stopListening() { bool ret = is_listening; is_listening = false; return ret; }
    bool overflow() { return false;}

    using Print::write; // pull in write(str) and write(buf, size) from Print

    operator bool() { return true; }
};

extern NullSerial_ NullSerial;

#endif
