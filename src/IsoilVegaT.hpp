#ifndef ISOILVEGATV10_H
#define ISOILVEGATV10_H

#include "Dispencer.hpp"

class IsoilVegaT : public Dispencer 
{
public: 
  IsoilVegaT(HardwareSerial *serial);

  int readDispencerStatus();
  /**
   * read totalizer reading
   */
  int readTotalizer();
  /**
   * authorize the sale and start dispencing
   */
  int authorizeSale();
  /**
   * sets the quantity to be dispencend
   * [dispencer specific]
   */
  int sendPreset(float quantity);
  /**
   * gets the quantity to be dispencend
   * [dispencer specific]
   */
  int readPreset();
  /**
   * cancel preset
   * [dispencer specific]
   */
  int cancelPreset();
  /**
   * suspendDispencer, clearSale, pumpStop
   */
  int stopDispencer();
  /**
   * suspend Dispencer
   */
  int suspendDispencer();
  /**
   * resume the dispencer
   */
  int resumeDispencer();
  /**
   * clear sale
   */
  int clearSale();
  /**
   * read sale
   */
  int readSale();
  /**
   * read sale
   */
  int readAuth();
  /**
   * stop the external pump
   */
  int pumpStop();
  /**
   * start the external pump
   */
  int pumpStart();

  /**
   * print reciept
   */
  int printReciept(char *printText, int BCC_SIZE);

  /**
   * switch dispencer mode to online.
   */
  int switchMode(bool online = true);

  std::string getType();
  
  std::string getExternalPump();
  

private:
  const uint8_t totalizer[17] =                     {0x02, 0x30, 0x30, 0x31, 0x30, 0x33, 0x30, 0x30, 0x30, 0x30, 0x20, 0x20, 0x20, 0x20, 0x36, 0x33, 0x0D};
  const uint8_t read_sale[17] =                     {0x02, 0x30, 0x30, 0x31, 0x30, 0x33, 0x30, 0x30, 0x30, 0x30, 0x20, 0x20, 0x20, 0x20, 0x36, 0x33, 0x0D};
  const uint8_t transaction_enable[143] =           {0x02, 0x30, 0x30, 0x31, 0x30, 0x34, 0x31, 0x31, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x39, 0x20, 0x20, 0x20, 0x20, 0x39, 0x35, 0x0D};
  const uint8_t read_preset[17] =                   {0x02, 0x30, 0x30, 0x31, 0x30, 0x33, 0x30, 0x30, 0x30, 0x30, 0x20, 0x20, 0x20, 0x20, 0x36, 0x33, 0x0D};
  const uint8_t start[14] =                         {0x02, 0x30, 0x30, 0x31, 0x31, 0x34, 0x34, 0x20, 0x20, 0x20, 0x20, 0x43, 0x41, 0x0D};
  const uint8_t preset_dummy[23] =                  {0x02, 0x30, 0x30, 0x31, 0x31, 0x34, 0x32, 0x31, 0x30, 0x30, 0x31, 0x32, 0x33, 0x34, 0x31, 0x31, 0x20, 0x20, 0x20, 0x20, 0x37, 0x36, 0x0D};
  const uint8_t stop[15] =                          {0x02, 0x30, 0x30, 0x31, 0x31, 0x34, 0x35, 0x31, 0x20, 0x20, 0x20, 0x20, 0x45, 0x44, 0x0D};
  const uint8_t terminate[15] =                     {0x02, 0x30, 0x30, 0x31, 0x31, 0x34, 0x35, 0x30, 0x20, 0x20, 0x20, 0x20, 0x44, 0x44, 0x0D};
  const uint8_t inbetween_close[14] =               {0x02, 0x30, 0x30, 0x31, 0x31, 0x34, 0x36, 0x20, 0x20, 0x20, 0x20, 0x45, 0x41, 0x0D};
  const uint8_t transaction_close[14] =             {0x02, 0x30, 0x30, 0x31, 0x30, 0x34, 0x37, 0x20, 0x20, 0x20, 0x20, 0x45, 0x41, 0x0D};
  const uint8_t check_nozzle_totalizer[17] =        {0x02, 0x30, 0x30, 0x31, 0x30, 0x33, 0x30, 0x30, 0x30, 0x30, 0x20, 0x20, 0x20, 0x20, 0x36, 0x33, 0x0D};
};

#endif