/*Planet's Lightning Arrester - 2018*/
/*    Lib based on STM32F103C8      */

#include "nRF24L01.h"
using namespace std;

#define HIGH 1
#define LOW 0

extern TIM_HandleTypeDef htim3;
bool timSet = false;

/*Delay em microsegundos*/
void RF_delay_init(void){
	  TIM_ClockConfigTypeDef sClockSourceConfig;
	  TIM_MasterConfigTypeDef sMasterConfig;
	  htim3.Instance = TIM3;
	  htim3.Init.Prescaler = 1000;
	  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim3.Init.Period = 65535;
	  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  HAL_TIM_Base_Init(&htim3);

	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig);

	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

}

void nRF24::microDelay(int multiplo){
	int i = 0;
	for(i = 1; i <= multiplo; i++){
		TIM3->CNT = 0;
		HAL_TIM_Base_Start(&htim3);
		while(TIM3->CNT == 0);
		HAL_TIM_Base_Stop(&htim3);
		TIM3->CNT = 0;
	}
}
/**/

void digitalWrite(uint8_t pin, bool highLow){
    switch(pin){
        case(2):
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(3):
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(4):
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(5):
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(6):
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(10):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(11):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(12):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(13):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(14):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(15):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(16):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(17):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(18):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(19):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(20):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(21):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(22):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(25):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(26):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(27):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(28):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(29):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(30):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(31):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(32):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(33):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(34):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(37):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(38):
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(39):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(40):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(41):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(42):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(43):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(45):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        case(46):
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, highLow?GPIO_PIN_SET:GPIO_PIN_RESET);
            break;
        default:
            break;

    }
}

uint8_t nRF24::SPIsend(uint8_t data2Send){
  uint8_t buf2Receive;
  HAL_SPI_TransmitReceive(globalHSPI, &data2Send, &buf2Receive, 1, 100);
  return buf2Receive;
}

void nRF24::setRetries(uint8_t retr, uint16_t delay){
	writeRegister(SETUP_RETR, (((delay/250)-1) << ARD) | retr);
}

nRF24::nRF24(SPI_HandleTypeDef *HSPI, int ce, int csn, uint8_t channel) {
  unsigned int aux;
  unsigned int *address;
  unsigned int baudrateOverTheAir = _2Mbps;
  unsigned int transmitPower = _0dBm;
  unsigned int retries = _15retries;
  unsigned int retriesTimeout = _750us;

  RF_delay_init();

  ce_pin = ce;
  csn_pin = csn;
  globalHSPI = HSPI;

  disableChip();
  deselectSlave();

  //Set retries = 15 and timeout = 1500us
  setRetries(retries, retriesTimeout);
  //writeRegister(SETUP_RETR, (retriesTimeout << ARD) | (retries << ARC));
  //writeRegister(SETUP_RETR, 0b11111111);

  //Set tx power = -12dbm (0dBm = 1mW, -12dBm = 1mW*10^-1.2 = 63uW)
  aux = readRegister(RF_SETUP);   //read current value
  aux &= ~(0b11 << RF_PWR);       //reset power values
  aux |= (transmitPower << RF_PWR); //set new value
  writeRegister( RF_SETUP, aux ); //write register

  //set datarate (1Mbps default)
  aux = readRegister(RF_SETUP);
  aux &= ~(1 << RF_DR_HIGH);       //set to 1Mbps
  aux &= ~(1 << RF_DR_LOW);        //
  if(baudrateOverTheAir == _250kbps){
	  aux |= 1<<RF_DR_LOW;
  }
  else if(baudrateOverTheAir == _2Mbps){
	  aux |= (1 << RF_DR_HIGH);
	  aux &= ~(1<<RF_DR_LOW);
  }
  writeRegister( RF_SETUP, aux );

  //set dynamicpayload off
  writeRegister(DYNPD, 0);

  //reset receive, transmit and max retransmits flags
  writeRegister(STATUS, 1 << RX_DR | 1 << TX_DS | 1 << MAX_RT);

  //set IRQ pin to set when receive data
  aux = readRegister(CONFIG) | 1 << MASK_TX_DS | 1 << MASK_MAX_RT | 1 << MASK_RX_DR; // Removed RX data ready interruption
  writeRegister(CONFIG, aux) ;

  //set CRC enabled
  aux = readRegister(CONFIG) | 1 << CRCO | 1 << EN_CRC; //CRCO define 2 bytes of CRC
  writeRegister(CONFIG, aux) ;

  //set channel (76 is the default)
  writeRegister(RF_CH, channel < 125 ? channel : 125);

  //set _pipe active
  pipesActives[0] = true;
  writeRegister(EN_RXADDR, pipesActives[ERX_P0] << ERX_P0 | pipesActives[ERX_P1] << ERX_P1 | pipesActives[ERX_P2] << ERX_P2 | pipesActives[ERX_P3] << ERX_P3 | pipesActives[ERX_P4] << ERX_P4 | pipesActives[ERX_P5] << ERX_P5);

  //set pipes
  writeRegisterManyTimes(TX_ADDR, _defaultAddressPipe0, 5);

  address = _defaultAddressPipe0;
  writeRegisterManyTimes(RX_ADDR_P0, address, 5);
  writeRegister(RX_PW_P0, pipePackageSize[0]);

  address = _defaultAddressPipe1;
  writeRegisterManyTimes(RX_ADDR_P1, address, 5);
  writeRegister(RX_PW_P1, pipePackageSize[1]);

  address = _defaultAddressPipe2;
  writeRegister(RX_ADDR_P2, address[4]);
  writeRegister(RX_PW_P2, pipePackageSize[2]);

  address = _defaultAddressPipe3;
  writeRegister(RX_ADDR_P3, address[4]);
  writeRegister(RX_PW_P3, pipePackageSize[3]);

  address = _defaultAddressPipe4;
  writeRegister(RX_ADDR_P4, address[4]);
  writeRegister(RX_PW_P4, pipePackageSize[4]);

  address = _defaultAddressPipe5;
  writeRegister(RX_ADDR_P5, address[4]);
  writeRegister(RX_PW_P5, pipePackageSize[5]);

  //stop listening
  disableChip();
  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);

  //enable dynamic payload and ack + payload
  writeRegister(FEATURE, readRegister(FEATURE) | 1<<EN_DPL | 1<<EN_ACK_PAY);
  writeRegister(DYNPD, 0x3F);

  enterRXmode();

}

uint8_t nRF24::send(const char* _data, unsigned int _size, unsigned int _pipe) {

  if(_size > 32)
	  _size = 32;

  if(!inTxMode){
	  inTxMode = true;
	  usingPipe = _pipe;
	  enterTXmode(_pipe);
	  //enableChip();
  }
  else{
	  if(usingPipe != _pipe){
		  usingPipe = _pipe;
		  enterTXmode(_pipe);
          //enableChip();
	  }
	  microDelay(6);
    writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );
  }

  selectSlave();

  SPIsend(W_TX_PAYLOAD);
  while (_size--)
	SPIsend(*_data++);

  deselectSlave();

  enableChip();
  microDelay(10);	//	Alterado de 30 para 10
  disableChip();

  return msgSize();

}

/*
*-burstSend: send messages without getting out of TX mode. Only works with ShockBusrts enabled (default).
*Obs: See page 22 for FSM
*/

uint8_t nRF24::burstSend(const char* _data, unsigned int _size, unsigned int _pipe) {

  if(_size > 32)
	  _size = 32;

  if(!inTxMode){
	  inTxMode = true;
	  usingPipe = _pipe;
	  enterTXmode(_pipe);
	  enableChip();
  }
  else{
	  if(usingPipe != _pipe){
		  usingPipe = _pipe;
		  enterTXmode(_pipe);
          enableChip();
	  }
	  microDelay(6);    //Minimum delay for proper operation
      writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );
  }

  selectSlave();

  SPIsend(W_TX_PAYLOAD);
  while (_size--)
	SPIsend(*_data++);

  deselectSlave();

  return msgSize();

}

/*
*-bareSend: send messages without getting out of TX mode. Only works with ShockBusrts enabled (default).
*Obs: See page 22 for FSM
*/

void nRF24::bareSend(const char* _data, unsigned int _size, unsigned int _pipe) {

    enableChip();

    microDelay(6);    //Minimum delay for proper operation
    writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

    selectSlave();

    SPIsend(W_TX_PAYLOAD);
    for(int i = 32; i > 0; i--, _size--){
        if(_size > 0)
            SPIsend(*_data++);
        else
            SPIsend(0);
    }
    deselectSlave();

}

void nRF24::sendInTheNextReceive(const char* _data, unsigned int _size, unsigned int _pipe){
	if(_size >32)
		_size = 32;

	selectSlave();

	SPIsend(W_ACK_PAYLOAD | _pipe);
	while (_size--)
		SPIsend(*_data++);

	deselectSlave();
}

void nRF24::Flush(){
	writeRegister(FLUSH_TX, NOP);
	writeRegister(FLUSH_RX, NOP);
}

void nRF24::read(char* _data) {
  int _size;

  _size = readRegister(R_RX_PL_WID);

  selectSlave();

  SPIsend(R_RX_PAYLOAD);
  for (int i = 0; i < _size; i++)
    _data[i] = SPIsend(NOP);

  deselectSlave();

  resetReceiveFlag();

}

void nRF24::pipe0address(unsigned int* address){
  _defaultAddressPipe0[0] = address[0];
  _defaultAddressPipe0[1] = address[1];
  _defaultAddressPipe0[2] = address[2];
  _defaultAddressPipe0[3] = address[3];
  _defaultAddressPipe0[4] = address[4];
  _defaultAddressPipe0[5] = address[5];

  writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP) | (1<<PRIM_RX));
  writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

  if (!pipesActives[0])
    enablePipe(0);

  writeRegisterManyTimes(TX_ADDR, address, 5);
  writeRegisterManyTimes(RX_ADDR_P0, address, 5);
  writeRegister(RX_PW_P0, pipePackageSize[0]);

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);
  enableChip();
  microDelay(1);
}

void nRF24::pipe1address(unsigned int* address){
  _defaultAddressPipe1[0] = address[0];
  _defaultAddressPipe1[1] = address[1];
  _defaultAddressPipe1[2] = address[2];
  _defaultAddressPipe1[3] = address[3];
  _defaultAddressPipe1[4] = address[4];

  _defaultAddressPipe2[0] = address[0];
  _defaultAddressPipe2[1] = address[1];
  _defaultAddressPipe2[2] = address[2];
  _defaultAddressPipe2[3] = address[3];
  _defaultAddressPipe2[4] = address[4];

  _defaultAddressPipe3[0] = address[0];
  _defaultAddressPipe3[1] = address[1];
  _defaultAddressPipe3[2] = address[2];
  _defaultAddressPipe3[3] = address[3];
  _defaultAddressPipe3[4] = address[4];

  _defaultAddressPipe4[0] = address[0];
  _defaultAddressPipe4[1] = address[1];
  _defaultAddressPipe4[2] = address[2];
  _defaultAddressPipe4[3] = address[3];
  _defaultAddressPipe4[4] = address[4];

  _defaultAddressPipe5[0] = address[0];
  _defaultAddressPipe5[1] = address[1];
  _defaultAddressPipe5[2] = address[2];
  _defaultAddressPipe5[3] = address[3];
  _defaultAddressPipe5[4] = address[4];

  _defaultAddressPipe1[5] = address[5];

  writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP) | (1<<PRIM_RX));
  writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

  if (!pipesActives[1])
    enablePipe(1);

  writeRegisterManyTimes(TX_ADDR, address, 5);
  writeRegisterManyTimes(RX_ADDR_P1, address, 5);
  writeRegister(RX_PW_P1, 32);

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);
  enableChip();
  microDelay(1);
}

void nRF24::pipe2address(unsigned int address){
  _defaultAddressPipe2[4] = address;

  writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP) | (1<<PRIM_RX));
  writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

  if (!pipesActives[2])
    enablePipe(2);

  writeRegisterManyTimes(TX_ADDR, _defaultAddressPipe2, 5);
  writeRegister(RX_ADDR_P2, _defaultAddressPipe2[4]);
  writeRegister(RX_PW_P2, 32);

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);
  enableChip();
  microDelay(1);
}

void nRF24::pipe3address(unsigned int address){
  _defaultAddressPipe3[4] = address;

  writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP) | (1<<PRIM_RX));
  writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

  if (!pipesActives[3])
    enablePipe(3);

  writeRegisterManyTimes(TX_ADDR, _defaultAddressPipe3, 5);
  writeRegister(RX_ADDR_P3, _defaultAddressPipe3[4]);
  writeRegister(RX_PW_P3, 32);

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);
  enableChip();
  microDelay(1);
}

void nRF24::pipe4address(unsigned int address){
  _defaultAddressPipe4[4] = address;

  writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP) | (1<<PRIM_RX));
  writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

  if (!pipesActives[4])
    enablePipe(4);

  writeRegisterManyTimes(TX_ADDR, _defaultAddressPipe4, 5);
  writeRegister(RX_ADDR_P4, _defaultAddressPipe4[4]);
  writeRegister(RX_PW_P4, 32);

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);
  enableChip();
  microDelay(1);
}

void nRF24::pipe5address(unsigned int address){
  _defaultAddressPipe5[4] = address;

  writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP) | (1<<PRIM_RX));
  writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

  if (!pipesActives[5])
    enablePipe(5);

  writeRegisterManyTimes(TX_ADDR, _defaultAddressPipe5, 5);
  writeRegister(RX_ADDR_P5, _defaultAddressPipe5[4]);
  writeRegister(RX_PW_P5, 32);

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);
  enableChip();
  microDelay(1);
}

void nRF24::changeChannel(uint8_t channel) {
	writeRegister(RF_CH, channel < 125 ? channel : 125);
}

void nRF24::changeSpeed(uint8_t speed){
    uint8_t aux;
    //set datarate (1Mbps default)
    aux = readRegister(RF_SETUP);
    aux &= ~(1 << RF_DR_HIGH);       //set to 1Mbps
    aux &= ~(1 << RF_DR_LOW);        //
    if(speed == _250kbps){
        aux |= 1<<RF_DR_LOW;
    }
    else if(speed == _2Mbps){
        aux |= (1 << RF_DR_HIGH);
        aux &= ~(1<<RF_DR_LOW);
    }
    writeRegister( RF_SETUP, aux );
}

void nRF24::powerDown(){
    writeRegister(CONFIG, readRegister(CONFIG) & ~(1<<PWR_UP));
}

void nRF24::powerUp(){
    writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP));
}

void nRF24::enableBareSend(uint8_t pipe){

    unsigned int* address;

    disableChip();

    writeRegister(EN_AA, 0);        //Disable auto ack per pipe
    writeRegister(SETUP_RETR, 0);   //Disable retries
    writeRegister(DYNPD, 0);        //Disable dynamic payload per pipe, cause it requires auto ack
    writeRegister(FEATURE, 0);      //Disable dynamic payload and ack

    //Disable interrupt pins
    //Disable CRC
    //Power up and put it into TX mode
    writeRegister(CONFIG, (1<<MASK_RX_DR) | (1<<MASK_TX_DS) | (1<<MASK_MAX_RT) | (0<<EN_CRC) | (0<<CRCO) | (1<<PWR_UP) | (0<<PRIM_RX));
    microDelay(20);
    resetFlags();

    switch (pipe) {
    case 0:
      cachePipeAddress = 0;
      address = _defaultAddressPipe0;
      break;
    case 1:
      cachePipeAddress = 1;
      address = _defaultAddressPipe1;
      break;
    case 2:
      cachePipeAddress = 2;
      address = _defaultAddressPipe2;
      break;
    case 3:
      cachePipeAddress = 3;
      address = _defaultAddressPipe3;
      break;
    case 4:
      cachePipeAddress = 4;
      address = _defaultAddressPipe4;
      break;
    case 5:
      cachePipeAddress = 5;
      address = _defaultAddressPipe5;
      break;
    default:
      cachePipeAddress = 0;
      address = _defaultAddressPipe0;
      break;
  }

  if (!pipesActives[pipe])
    enablePipe(pipe);

  writeRegisterManyTimes(TX_ADDR, address, 5);
  writeRegisterManyTimes(RX_ADDR_P0, address, 5);
  writeRegister(RX_PW_P0, pipePackageSize[cachePipeAddress]);
  if(pipe ==1){
	  writeRegisterManyTimes(RX_ADDR_P0 + pipe, _defaultAddressPipe0, 5);
	}
	else if(pipe >= 2 && pipe <=5){
	  writeRegister(RX_ADDR_P0 + pipe, _defaultAddressPipe0[4]);
	}

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);


}

void nRF24::enterRXmode() {

    disableChip();

	writeRegister(CONFIG, readRegister(CONFIG) | (1<<PWR_UP) | (1<<PRIM_RX));
	//writeRegister(CONFIG, 0x0F);
	writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );

	writeRegisterManyTimes(TX_ADDR, _defaultAddressPipe0, 5);
	writeRegisterManyTimes(RX_ADDR_P0, _defaultAddressPipe0, 5);
	writeRegister(RX_PW_P0, pipePackageSize[0]);

	writeRegister(FLUSH_TX, NOP);
	writeRegister(FLUSH_RX, NOP);
	enableChip();
	microDelay(1);
}

void nRF24::enterTXmode(unsigned int _pipe) {

  unsigned int* address;

  switch (_pipe) {
    case 0:
      cachePipeAddress = 0;
      address = _defaultAddressPipe0;
      break;
    case 1:
      cachePipeAddress = 1;
      address = _defaultAddressPipe1;
      break;
    case 2:
      cachePipeAddress = 2;
      address = _defaultAddressPipe2;
      break;
    case 3:
      cachePipeAddress = 3;
      address = _defaultAddressPipe3;
      break;
    case 4:
      cachePipeAddress = 4;
      address = _defaultAddressPipe4;
      break;
    case 5:
      cachePipeAddress = 5;
      address = _defaultAddressPipe5;
      break;
    default:
      cachePipeAddress = 0;
      address = _defaultAddressPipe0;
      break;
  }

  disableChip();

  if (!pipesActives[_pipe])
    enablePipe(_pipe);

  writeRegister(CONFIG, 0x0E);
  resetFlags();

  writeRegisterManyTimes(TX_ADDR, address, 5);
  writeRegisterManyTimes(RX_ADDR_P0, address, 5);
  writeRegister(RX_PW_P0, pipePackageSize[cachePipeAddress]);
  if(_pipe ==1){
	  writeRegisterManyTimes(RX_ADDR_P0 + _pipe, _defaultAddressPipe0, 5);
	}
	else if(_pipe >= 2 && _pipe <=5){
	  writeRegister(RX_ADDR_P0 + _pipe, _defaultAddressPipe0[4]);
	}

  writeRegister(FLUSH_TX, NOP);
  writeRegister(FLUSH_RX, NOP);
}

void nRF24::exitTXmode(){

	writeRegisterManyTimes(TX_ADDR, _defaultAddressPipe0, 5);
	writeRegisterManyTimes(RX_ADDR_P0, _defaultAddressPipe0, 5);
	writeRegister(RX_PW_P0, pipePackageSize[0]);

	if(cachePipeAddress != 0){
        if(cachePipeAddress == 1)
            writeRegisterManyTimes(RX_ADDR_P1, _defaultAddressPipe1, 5);
        else if(cachePipeAddress == 2)
            writeRegister(RX_ADDR_P2, _defaultAddressPipe2[4]);
        else if(cachePipeAddress == 3)
            writeRegister(RX_ADDR_P3, _defaultAddressPipe3[4]);
        else if(cachePipeAddress == 4)
            writeRegister(RX_ADDR_P4, _defaultAddressPipe4[4]);
        else
            writeRegister(RX_ADDR_P5, _defaultAddressPipe5[4]);

        writeRegister(RX_PW_P0 + cachePipeAddress, pipePackageSize[cachePipeAddress]);
	}

}

void nRF24::writeRegister(unsigned int reg, unsigned int _data) {

  selectSlave();
  SPIsend(W_REGISTER | reg);
  SPIsend(_data);
  deselectSlave();

}

void nRF24::writeRegisterManyTimes(unsigned int reg, unsigned int* _data, int nBytes) {
	int i;
	selectSlave();
	SPIsend(W_REGISTER | reg);
	for (i = nBytes - 1; i >= 0; i--)
		SPIsend(_data[i]);
	deselectSlave();
}

unsigned int nRF24::readRegister(unsigned int reg) {
  unsigned int _data;

  selectSlave();
  SPIsend(R_REGISTER | reg);
  _data = SPIsend(NOP);
  deselectSlave();

  return _data;
}

void nRF24::readRegisterManyTimes(unsigned int reg, unsigned int* _data, int nBytes) {
  int index = 0;

  selectSlave();
  SPIsend(R_REGISTER | reg);
  while(nBytes--){
    _data[index] = SPIsend(NOP);
    index++;
  }
  deselectSlave();

}

//Returns false if didn't receive anything. Returns (_pipe_n +1) when receive anything from the _pipe number _pipe_n
volatile unsigned int nRF24::available() {
	if(inTxMode){
		inTxMode = false;
		exitTXmode();
		enterRXmode();
	}
    else{
        writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );
    }
	if ((~readRegister(FIFO_STATUS)) & (1<<RX_EMPTY)) {
		unsigned int receivedFromPipe = (readRegister(STATUS) & 0b1110) >> 1;
		return receivedFromPipe + 1;
	}
	else
		return false;
}

volatile unsigned int nRF24::bareAvailable(){
    disableChip();
    if ((~readRegister(FIFO_STATUS)) & (1<<RX_EMPTY)) {
		unsigned int receivedFromPipe = (readRegister(STATUS) & 0b1110) >> 1;
		return receivedFromPipe + 1;
	}
	else
		return false;
}

uint8_t nRF24::checkRetries(){
	return readRegister((STATUS) & (1<<MAX_RT));
}

bool nRF24::isRadioInRange(){
    return readRegister(RPD);
}

void nRF24::enablePipe(unsigned int _pipe) {
  pipesActives[_pipe] = true;
  writeRegister(EN_RXADDR, pipesActives[ERX_P0] << ERX_P0 | pipesActives[ERX_P1] << ERX_P1 | pipesActives[ERX_P2] << ERX_P2 | pipesActives[ERX_P3] << ERX_P3 | pipesActives[ERX_P4] << ERX_P4 | pipesActives[ERX_P5] << ERX_P5);
}

void nRF24::disablePipe(unsigned int _pipe) {
  pipesActives[_pipe] = false;
  writeRegister(EN_RXADDR, pipesActives[ERX_P0] << ERX_P0 | pipesActives[ERX_P1] << ERX_P1 | pipesActives[ERX_P2] << ERX_P2 | pipesActives[ERX_P3] << ERX_P3 | pipesActives[ERX_P4] << ERX_P4 | pipesActives[ERX_P5] << ERX_P5);
}

void nRF24::resetFlags(){
    writeRegister(STATUS, (1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT) );
}

unsigned int nRF24::msgSize() {
	if ((~readRegister(FIFO_STATUS)) & (1<<RX_EMPTY)) {
		return readRegister(R_RX_PL_WID);
	}
	else{
		return 0;
	}
}

void nRF24::resetReceiveFlag() {
  writeRegister(STATUS, 1 << RX_DR);
}

void nRF24::enableChip() {
  digitalWrite(ce_pin, HIGH);
}

void nRF24::disableChip() {
  digitalWrite(ce_pin, LOW);
}

void nRF24::selectSlave(){
	digitalWrite(csn_pin, LOW);
}

void nRF24::deselectSlave(){
	digitalWrite(csn_pin, HIGH);
}
