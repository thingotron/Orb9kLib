#include "orbotron_hid.h"

OrbJoystick_ OrbJoystick;

// some from https://github.com/arduino/Arduino/wiki/PluggableUSB-and-PluggableHID-howto

static const byte _orbJoystickReportDescriptor[] PROGMEM = {
  
  // 32 buttons (and a throttle - just in case the game doesn't recognise a joystick with no analog axis)

  0x05, 0x01,			// USAGE_PAGE (Generic Desktop)
  0x09, 0x04,			// USAGE (Joystick)
  0xa1, 0x01,			// COLLECTION (Application)
  0x85, 0x03,			// REPORT_ID (3)  (This is important when HID_SendReport() is called)

  //Buttons:
  0x05, 0x09,			// USAGE_PAGE (Button)
  0x19, 0x01,			// USAGE_MINIMUM (Button 1)
  0x29, 0x10,			// USAGE_MAXIMUM (Button 16)
  0x15, 0x00,			// LOGICAL_MINIMUM (0)
  0x25, 0x01,			// LOGICAL_MAXIMUM (1)
  0x75, 0x01,			// REPORT_SIZE (1)
  0x95, 0x10,			// REPORT_COUNT (16)
  0x55, 0x00,			// UNIT_EXPONENT (0)
  0x65, 0x00,			// UNIT (None)
  0x81, 0x02,			// INPUT (Data,Var,Abs)

  0x05, 0x01,			// USAGE_PAGE (Generic Desktop)

  0x15, 0x00,			// LOGICAL_MINIMUM (0)
  0x26, 0xff, 0x03,		// LOGICAL_MAXIMUM (1023)
  0x75, 0x0a,			// REPORT_SIZE (10)

  0x09, 0x04,			// USAGE (Pointer)
  0xA1, 0x00,			// COLLECTION (Physical)
  0x09, 0x30,		// USAGE (x)
  0x09, 0x31,		// USAGE (y)
  0x09, 0x32,		// USAGE (z)
  0x09, 0x33,		// USAGE (rx)
  0x09, 0x36,		// USAGE (slider)
  0x09, 0x35,		// USAGE (rz)
  0x95, 0x06,		// REPORT_COUNT (6)
  0x81, 0x02,		// INPUT (Data,Var,Abs)
  0xc0,				// END_COLLECTION
  0x75, 0x04,                    //   REPORT_SIZE (8)
  0x95, 0x01,                    //   REPORT_COUNT (1)
  0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)

  0xc0					// END_COLLECTION
};


//================================================================================
//	Joystick
//  Usage: Joystick.move(inputs go here)
//
//  The report data format must match the one defined in the descriptor exactly
//  or it either won't work, or the pc will make a mess of unpacking the data
//

OrbJoystick_::OrbJoystick_(void)
{
  static HIDSubDescriptor node(_orbJoystickReportDescriptor,
			       sizeof(_orbJoystickReportDescriptor));
  HID().AppendDescriptor(&node);
}


#define joyBytes 10 		// should be equivalent to sizeof(JoyState_t)

void OrbJoystick_::setState(JoyState_t *joySt)
{
	uint8_t data[joyBytes];
	uint32_t buttonTmp;
	buttonTmp = joySt->buttons;

	data[0] = buttonTmp & 0xFF;		// Break 32 bit button-state out into 4 bytes, to send over USB
	buttonTmp >>= 8;
	data[1] = buttonTmp & 0xFF;
	buttonTmp >>= 8;
	
	// unpacking the orb data is trickier
	byte high;
	byte low;
	byte temp;

	high = joySt->xAxis >> 8;
	low = joySt->xAxis & 255;
	data[2] = low;
	temp = high;

	high = joySt->yAxis >> 6;
	low = joySt->yAxis & 63;
	data[3] = (low << 2) + temp;
	temp = high;
	
	high = joySt->zAxis >> 4;
	low = joySt->zAxis & 15;
	data[4] = (low << 4) + temp;
	temp = high;

	high = joySt->xRotAxis >> 2;
	low = joySt->xRotAxis & 3;
	data[5] = (low << 6) + temp;
	temp = high;

	high = 0;
	low = 0;
	data[6] = temp;
	temp = high;

	high = joySt->yRotAxis >> 8;
	low = joySt->yRotAxis & 255;
	data[7] = low;
	temp = high;

	high = joySt->zRotAxis >> 6;
	low = joySt->zRotAxis & 63;
	data[8] = (low << 2) + temp;
	temp = high;

	high = 0;
	low = 0;
	data[9] = (low << 4) + temp;

	//HID_SendReport(Report number, array of values in same order as HID descriptor, length)
	HID().SendReport(3, data, joyBytes);
	// The joystick is specified as using report 3 in the descriptor. That's where the "3" comes from
}

