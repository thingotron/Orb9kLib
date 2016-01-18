
#ifndef ORBOTRON_HID_H
#define ORBOTRON_HID_H

#include "HID.h"

#if !defined(_USING_HID)
#warning "Using legacy HID core (non-pluggable)"
#else
#endif

typedef struct JoyState 		// Pretty self explanitory. Simple state to store all the joystick parameters
{
	uint16_t		xAxis;
	uint16_t		yAxis;
	uint16_t		zAxis;

	uint16_t		xRotAxis;
	uint16_t		yRotAxis;
	uint16_t		zRotAxis;

	uint16_t	buttons;		// 32 general buttons

} JoyState_t;

class OrbJoystick_
{
public:
	OrbJoystick_(void);

	void setState(JoyState_t *joySt);

};
extern OrbJoystick_ OrbJoystick;

#endif

