#include <ctype.h>

byte SWval;

#define orbSerial Serial1
#define dbgSerial Serial

void setup() {
  orbSerial.begin(9600);
  dbgSerial.begin(9600);
  dbgSerial.println("This sketch simply takes input from the OrbShield's serial port");
  dbgSerial.println("and sends it out the serial port.  DIP switches should be set with");
  dbgSerial.println("switch 1 (nearest to the serial port) ON, switch 2 OFF");
  dbgSerial.println("Serial dump follows:\n");
}

const char spaceball_setup_string[] ="\rCB\rNT\rFT?\rFR?\rP@r@r\rMSSV\rZ\rBcCcCcC\r";
const char magellan_setup_string[] = "\rm3\rpBB\rz\r";

byte has_sent=0;

void loop()
{
  delay(500);
  if (has_sent == 0) {
    //Serial.print( magellan_setup_string );
    has_sent = 1;
  }

  dbgSerial.print(".");
  while ( orbSerial.available() > 0 )
  {
     {
      SWval = orbSerial.read();
      dbgSerial.print( SWval );
      dbgSerial.print( "(" );
      dbgSerial.print( SWval, DEC );
      dbgSerial.print( ")\n" );     
     }
  }
}
