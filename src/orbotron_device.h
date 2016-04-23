#ifndef ORBOTRON_DEVICE_H
#define ORBOTRON_DEVICE_H

#include <arduino.h>
#include "orbotron_hid.h"

class Orbotron_device 
{
 public:
  bool init_string_sent;
  unsigned long millis_at_init;
  JoyState_t joy_state;

  Orbotron_device(void);

  void send_joystick_report( unsigned short x, 
			     unsigned short y, 
			     unsigned short z,
			     unsigned short rx, 
			     unsigned short ry, 
			     unsigned short rz, 
			     unsigned short btn );

  void send_keyboard_report( unsigned char modifiers, int count, unsigned char * buttons );
  void send_single_keyboard_report( unsigned char keyStroke, unsigned char modifiers );
  void send_mouse_report( unsigned char buttons,
			  char x,
			  char y,
			  char wheel );

};

#endif
