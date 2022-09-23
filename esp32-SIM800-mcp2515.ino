#include "mcp2515.h"
#include "esp_system.h"
#include "driver/spi_master.h"

struct can_frame frame;
spi_device_handle_t spi;

MCP2515 canbus(&spi);

void setup(void){
  Serial.begin(9600);
  while(!Serial){};

  canbus.setBitrate(CAN_500KBPS);
  canbus.setNormalMode();

  Serial.println("CANBus Configurated");
}

void loop(void){
  if (canbus.readMessage(&frame) == MCP2515::ERROR_OK) {
          // frame contains received message
          Serial.print("ID: ");
          Serial.print(frame.can_id, HEX);
          Serial.print(" DATA: ");
          // Serial.println(frame.data);
  }

  delay(10);
}