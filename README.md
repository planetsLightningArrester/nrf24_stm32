# NRF24L01 for STM32 - C++ version
**Important:** It uses Timer 3! Don't need to configure it, just enable it on CubeMX.

## Usage
```

#include "nRF24L01.h"

// Init the radio on channel 5
// Using SPI1 and pins 31 and 30 as CE and CSN, resp.
nRF24 radio = nRF24(&hspi1, 31, 30, 5);

// radio.send(message, size, pipe);
radio.send("Hi pipe 0!\r\n", 12, 0);
radio.send("Hello pipe 1!\r\n", 15, 1);
radio.enablePipe(2);    // Only pipes 0 and 1 are enable by default
radio.send("Hey pipe 2!\r\n", 13, 2);

// radio.available() returns the pipe number + 1
uint8_t receivedFromPipe = radio.available() - 1;   
char dataReceived[32];

switch (receivedFromPipe) {
    case 0:
        // Data from pipe 0
        radio.read(dataReceived);
        break;
    case 1:
        // Data from pipe 1
        radio.read(dataReceived);
        // I don't wanna hear you anymore
        radio.sendInTheNextReceive("SHUT UP MAN", 11, 1);
        break;
    ...
};

```

## API
```

//main methods
nRF24(SPI_HandleTypeDef *HSPI, int ce, int csn, uint8_t channel);
uint8_t send(const char* _data, unsigned int _size, unsigned int _pipe);
void read(char* _data);
volatile unsigned int available();
unsigned int msgSize();

//parameters change
void setRetries(uint8_t retr, uint16_t delay);
void changeChannel(uint8_t channel);
void changeSpeed(uint8_t speed);
void enablePipe(unsigned int _pipe);
void disablePipe(unsigned int _pipe);
void pipe0address(unsigned int* address);
void pipe1address(unsigned int* address);
void pipe2address(unsigned int address);
void pipe3address(unsigned int address);
void pipe4address(unsigned int address);
void pipe5address(unsigned int address);

//radio status check
bool isRadioInRange();
unsigned int readRegister(unsigned int reg);
uint8_t checkRetries();
bool activePipes[6] = { true, false, false, false, false, false };

//auxiliary methods
uint8_t burstSend(const char* _data, unsigned int _size, unsigned int _pipe);
void sendInTheNextReceive(const char* _data, unsigned int _size, unsigned int _pipe);
void microDelay(int multiplo);
void Flush();
void powerDown();
void powerUp();

//not reliable extremely fast send methods
void enableBareSend(uint8_t pipe);
void bareSend(const char* _data, unsigned int _size, unsigned int _pipe);
volatile unsigned int bareAvailable();

```

# LICENSE
MIT License

Copyright (c) 2021 planet's lightning arrester

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
