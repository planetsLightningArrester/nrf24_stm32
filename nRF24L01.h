/*Planet's Lightning Arrester - 2018*/
/*    Lib based on STM32F103C8      */

#ifndef NRF24_H_
#define NRF24_H_

#include "stm32f1xx_hal.h"
#include "string.h"
//#include "stdbool.h"

/* #region Defines*/

/*Commands*/
#define R_REGISTER 0x00
#define W_REGISTER 0x20
#define R_RX_PAYLOAD 0x61
#define W_TX_PAYLOAD 0xA0
#define FLUSH_TX 0xE1
#define FLUSH_RX 0xE2
#define REUSE_TX_PL 0xE3
#define R_RX_PL_WID 0x60
#define W_ACK_PAYLOAD 0xA8
#define W_TX_PAYLOAD_NO_ACK 0xB0
#define NOP 0xFF

/*Memory Map*/
//Configuration Register
#define CONFIG 0x00
#define MASK_RX_DR 6
#define MASK_TX_DS 5
#define MASK_MAX_RT 4
#define EN_CRC 3
#define CRCO 2
#define PWR_UP 1
#define PRIM_RX 0

//Enhanced ShockBurst
#define EN_AA 0x01
#define ENAA_P5 5
#define ENAA_P4 4
#define ENAA_P3 3
#define ENAA_P2 2
#define ENAA_P1 1
#define ENAA_P0 0

//Enabled RX Address
#define EN_RXADDR 0x02
#define ERX_P5 5
#define ERX_P4 4
#define ERX_P3 3
#define ERX_P2 2
#define ERX_P1 1
#define ERX_P0 0

//Setup Address Widths
#define SETUP_AW 0x03
#define AW 0

//Setup Automatic Retransmission
#define SETUP_RETR 0x04
#define ARD 4
#define ARC 0

//RF Channel
#define RF_CH 0x05

//RF Setup Register
#define RF_SETUP 0x06
#define CONT_WAVE 7
#define RF_DR_LOW 5
#define PLL_LOCK 4
#define RF_DR_HIGH 3
#define RF_PWR 1

//Status Register
#define STATUS 0x07
#define RX_DR 6
#define TX_DS 5
#define MAX_RT 4
#define RX_P_NO 1
#define TX_FULL 0

//Transmit Observe Register
#define OBSERVE_TX 0x08
#define PLOS_CNT 4
#define ARC_CNT 0

//Received Power Detector
#define RPD 0x09

//Receive Addresses Data Pipes
#define RX_ADDR_P0 0x0A
#define RX_ADDR_P1 0x0B
#define RX_ADDR_P2 0x0C
#define RX_ADDR_P3 0x0D
#define RX_ADDR_P4 0x0E
#define RX_ADDR_P5 0x0F

//Transmit Address
#define TX_ADDR 0x10

//Widths of RX Payloads
#define RX_PW_P0 0x11
#define RX_PW_P1 0x12
#define RX_PW_P2 0x13
#define RX_PW_P3 0x14
#define RX_PW_P4 0x15
#define RX_PW_P5 0x16

//FIFO Status Register
#define FIFO_STATUS 0x17
#define TX_REUSE 6
#define TX__FIFO_FULL 5
#define TX_EMPTY 4
#define RX_FULL 1
#define RX_EMPTY 0

//Enable Dynamic Payload Length
#define DYNPD 0x1C
#define DPL_P5 5
#define DPL_P4 4
#define DPL_P3 3
#define DPL_P2 2
#define DPL_P1 1
#define DPL_P0 0

//Feature Register
#define FEATURE 0x1D
#define EN_DPL 2
#define EN_ACK_PAY 1
#define EN_DYN_ACK 0

/*End of Memory Map*/
/**/

/*Defines*/
#define _1Mbps 0
#define _2Mbps 1
#define _250kbps 2

#define _18dBm 0
#define _12dBm 1
#define _6dBm 2
#define _0dBm 3

#define _250us 0
#define _500us 1
#define _750us 2
#define _1000us 3
#define _1250us 4
#define _1500us 5
#define _1750us 6
#define _2000us 7
#define _2250us 8
#define _2500us 9
#define _2750us 10
#define _3000us 11
#define _3250us 12
#define _3500us 13
#define _3750us 14
#define _4000us 15

#define noRetries 0
#define _1retry 1
#define _2retries 2
#define _3retries 3
#define _4retries 4
#define _5retries 5
#define _6retries 6
#define _7retries 7
#define _8retries 8
#define _9retries 9
#define _10retries 10
#define _11retries 11
#define _12retries 12
#define _13retries 13
#define _14retries 14
#define _15retries 15

/* #endregion */

class nRF24 {

	/*Library global variables*/
	int ce_pin;
	int csn_pin;
	unsigned int _defaultAddressPipe0[6] = { 0x10, 0x10, 0x10, 0x10, 0x10 };
	unsigned int _defaultAddressPipe1[6] = { 0x11, 0x10, 0x10, 0x10, 0x11 };
	unsigned int _defaultAddressPipe2[6] = { 0x11, 0x10, 0x10, 0x10, 0x12 };
	unsigned int _defaultAddressPipe3[6] = { 0x11, 0x10, 0x10, 0x10, 0x13 };
	unsigned int _defaultAddressPipe4[6] = { 0x11, 0x10, 0x10, 0x10, 0x14 };
	unsigned int _defaultAddressPipe5[6] = { 0x11, 0x10, 0x10, 0x10, 0x15 };
	unsigned int cachePipeAddress;
	bool pipesActives[6] = { true, true, false, false, false, false };

	bool inTxMode = false;
	uint8_t usingPipe = -1;
	uint8_t pipePackageSize[6] = { 32, 32, 32, 32, 32 , 32};

	SPI_HandleTypeDef *globalHSPI;

	private:
		uint8_t SPIsend(uint8_t data2Send);
		void enterRXmode();
		void enterTXmode(unsigned int _pipe);
		void exitTXmode();
		void writeRegister(unsigned int reg, unsigned int _data);
		void writeRegisterManyTimes(unsigned int reg, unsigned int* _data, int nBytes);
		void readRegisterManyTimes(unsigned int reg, unsigned int* _data, int nBytes);
		void resetReceiveFlag();
		void enableChip();
		void disableChip();
		void selectSlave();
		void deselectSlave();
		void resetFlags();

	public:
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

};

#endif
