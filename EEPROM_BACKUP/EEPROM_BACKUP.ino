#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("int eeprom_data[] = {");
}

void loop() {

  value = EEPROM.read(address);
  Serial.print(value, DEC);

  if (address < (EEPROM.length()-1) ) {
    Serial.print(",");
  }

  address = address + 1;
  if (address == EEPROM.length()) {
    // We are done
    Serial.print("};");
    delay(5000);
    exit(0);
  }

  delay(10);
}
