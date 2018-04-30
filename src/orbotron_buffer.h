#ifndef ORBOTRON_BUFFER_H
#define ORBOTRON_BUFFER_H

#define BUFFER_SIZE 30
#define PACKET_UNKNOWN -1
#include <avr/pgmspace.h>
#include "string.h"

enum OrbType
{
  SpaceOrb360,
  SpaceBall4000,
  SpaceBall5000
};

inline short mshl( unsigned short b, unsigned short mask, unsigned short shift )
{
  return (b & mask) << shift;
}

inline short mshr( unsigned short b, unsigned short mask, unsigned short shift )
{
  return (b & mask) >> shift;
}

inline short resign( unsigned short b )
{
  const short schar = (0x0200); //512; finding the sign bit of a 10-bit signed number
  const short smask = (0xfe00);
  if (b & schar) {
    return (b | smask);
    //    return ((short)b - 1023); //this is probably not the correct conversion but it'll be only off by 1
  } else {
    return b;
  }
}

inline short spaceball_ballaxis( unsigned short b1, unsigned short b2 )
{
  short result;
  result = (b1 << 8) | (b2);
  return result;
}

inline short escaped_char( unsigned char b )
{
  switch (b)
  {
  case '^' :
    break;
  case 'Q' :
  case 'S' :
  case 'M' :
    b &= 0x1F;
    break;
  default :
    // signal error?
    break;
  }
  return b;
}

// this has to be straight C++, darn you arduino
class Logical_orbotron //: public Logical_device
{
public:
  unsigned char buffer[BUFFER_SIZE];
  unsigned short cursor;
  short physical_axes[6];
  bool spaceorb_reset_button;
  unsigned short physical_buttons;
  short expected_packet_length;
  bool awaiting_escape;
  OrbType orb_type;
  bool _has_changed;
  Logical_orbotron( OrbType new_orb_type )
  {
    reset();
    orb_type = new_orb_type;
    memset( physical_axes, 0, sizeof( physical_axes ) );
    physical_buttons = 0;
    spaceorb_reset_button = false;
    awaiting_escape = false;
    expected_packet_length = PACKET_UNKNOWN;
  }

  virtual short axis( int index )
  {
    if ( index < 6 )
      {
	return physical_axes[index];
      }
    return -1;
  }

  void reset( void )
  {
    cursor = 0;
  }

  virtual bool has_changed( void )
  {
    return _has_changed;
  }
  // call this once you have taken note of the changed internal state of the
  // orb and sent the data out
  virtual void log_change( void )
  {
    _has_changed = false;
  }

  unsigned short switchval( short orb_val, short ball_val )
  {
    return ( orb_type == SpaceOrb360 ) ? orb_val : ball_val;
  }

  unsigned short packet_length( char packet_type )  // includes terminating \r
  {
    unsigned short result = PACKET_UNKNOWN;
    switch( packet_type )
    {
    case 'D' : //displacement
      result = switchval( 13, 16 );
      break;
    case 'K' : //button
      result = switchval( 6, 4 );
      break;
    case '.' : //4000 button
      result = 4;
      break;
    case 'C' : //comm mode
      result = 4;
      break;
    case 'F' : //sensitization mode
      result = 4;
      break;
    case 'M' : //movement mode
      result = 5;
      break;
    case 'N' : //null region
      result = switchval( 4, 3 );
      break;
    case 'P' : //update rate
      result = 6;
      break;
    case '\v' : //xon at poweron
      result = 1;
      break;
    case '\n' : //CR at poweron
    case '\r' :
      result = 1;
      break;
    case '@' : //reset packet
      result = 62;
      break;
    case 'E' : //error
      result = switchval( 5, 8 ); //sball packets are shorter?
      break;
    case 'Z' : //zero packet (??)
      result = 14;
      break;
    case 'd' : // Magellan/5k ball data packet
      result = 26;
      break;
    case 'k' : // Magellan/5k button packet
      result = 5;
      break;
    }
    return result;
  }

  bool in_packet( void )
  {
    return (expected_packet_length != PACKET_UNKNOWN );
  }

  void process_spaceorb_buttondata( void )
  {
    // buffer[2] now has data in the form 1<rezero><F><E><D><C><B><A>
    physical_buttons = buffer[2] & 63;
    spaceorb_reset_button = (buffer[2] & 64) != 0;
    // add magellan
  }

  void process_spaceball_buttondata( void )
  {
    // boggle--according to notes, lowest 5 bits of first byte are 5-9;
    // lowest 4 bits of second byte are 1-4; we aren't really concerned about
    // pick bit for gaming
    // our physical buttons are just 16 bits, lowest is button 1
    // so really we should be able to just say ...
    //if ( orb_type == SpaceBall )
    //{
    //  physical_buttons = buffer[2];
    //}
  }

  void process_spaceorb_balldata( void )
  {
    // D<button status><D1><D2><D3><D4><D5><D6><D7><D8><D9><xor>
    // from elsewhere:
    // <D1> to <D9> are data bytes containing the force and torque components. 
    // These values are generated by first packing the six 10 bit values then 
    // xoring them with the characters "SpaceWare". Packed data has the form: 
    // 1XXX XXXX 1XXX YYYY 1YYY YYYZ 1ZZZ ZZZZ1ZZx 
    // xxxx 1xxx xxyy 1yyy yyyy 1yzz zzzz1zzz z000 
    // where XXXXXXXXXX , YYYYYYYYYY , ZZZZZZZZZZ are the components of force. 
    // xxxxxxxxxx , yyyyyyyyyy , zzzzzzzzzz are the components of torque.
    // ...
    // Note the "at rest" packet, the packet with all force and torque components at zero, 
    // will contain the word "SpaceWare".

    // great; so first let's xor with "D.SpaceWare"
    unsigned short i;
    char const* string_to_xor = "SpaceWare";
    for ( i = 0; i < 9; ++i )
    {
      buffer[i+2] ^= string_to_xor[i];
    }
    // now process button char
    physical_buttons = buffer[1] & 63;
    // now process ball components
    physical_axes[0] = mshl( buffer[2], 0x7F, 3) | mshr( buffer[3], 0x70, 4 ); //(((buffer[2] & 0x7F) << 3) | ((buffer[3] & 0x70) >> 4));
    physical_axes[1] = mshl( buffer[3], 0x0F, 6) | mshr( buffer[4], 0x7E, 1 ); //(((buffer[3] & 0x0F) << 6) | ((buffer[4] & 0x7E) >> 1));
    physical_axes[2] = mshl( buffer[4], 0x01, 9) | mshl( buffer[5], 0x7F, 2 ) | mshr( buffer[6], 0x60, 5 );    //(((buffer[4] & 0x01) << 9) | ((buffer[5] & 0x7F) << 2) | ((buffer[6] & 0x60) >> 5));
    physical_axes[3] = mshl( buffer[6], 0x1F, 5) | mshr( buffer[7], 0x7C, 2 ); //(((buffer[6] & 0x1F) << 5) | ((buffer[7] & 0x7C) >> 2));
    physical_axes[4] = mshl( buffer[7], 0x03, 8) | mshl( buffer[8], 0x7F, 1 ) | mshr(buffer[9], 0x40, 6);    //(((buffer[7] & 0x03) << 8) | ((buffer[8] & 0x7F) << 1) | ((buffer[9] & 0x40) >> 6));
    physical_axes[5] = mshl( buffer[9], 0x3f, 4) | mshr( buffer[10], 0x78, 3 ); //(((buffer[9]  & 0x3F) << 4) | ((buffer[10] & 0x78) >> 3));

    //ok, now we have a bunch of signed 10-bit integers.  That means bit 10 is our sign bit
    //and we need to move it to bit 16
    for ( int i = 0; i < 6; ++i )
    {
      physical_axes[i] = resign( physical_axes[i] );
    }

  }

  void process_4000_buttondata( void )
  {
    if ( orb_type == SpaceBall4000 )
    {
      physical_buttons = //(((~buffer[1]) ^ 0x20) << 10 ) | // LH mode
      ((buffer[1] & 0x1F) << 7 ) | // 8-12
      ((buffer[2] & 0x3F)) | // 1-6 (4k)
      ((buffer[2] & 0x80) >> 1); // 7

    }
  }

  void process_spaceball_balldata( void )
  {
    // first clean things up a bit
    if ( buffer[ cursor-1 ] == 13 )
    {
      buffer[cursor-1] = 0;
    }
    if ( cursor < expected_packet_length )
    {
      for (unsigned short i = cursor; i < expected_packet_length; ++i )
      {
        buffer[i] = 0;
      }
    }
    physical_axes[0] = spaceball_ballaxis( buffer[3], buffer[4] );
    physical_axes[1] = spaceball_ballaxis( buffer[5], buffer[6] );
    physical_axes[2] = spaceball_ballaxis( buffer[7], buffer[8] );
    physical_axes[3] = spaceball_ballaxis( buffer[9], buffer[10] );
    physical_axes[4] = spaceball_ballaxis( buffer[11], buffer[12] );
    physical_axes[5] = spaceball_ballaxis( buffer[13], buffer[14] );
  }

  bool crunch_magellan_nibbles(void)
    // copied from the Linux magellan.c driver; this 
    // verifies that the bytes (discounting the initial data)
    // contain the correct upper nibbles for the lower ones.
    // if not, returns false; also strips upper halves to simplify
    // further processing
    {
      static unsigned char nibbles[17]="0AB3D56GH9:K<MN?";
      // process only the middle (not the initial character or the 
      // terminating cr)
      for ( unsigned short i = 1; i < (cursor-1); ++i )
	{
	  if  (buffer[i] == nibbles[buffer[i] & 0xf])
	    {
	      buffer[i] = buffer[i] & 0xf;
	    }
	  else
	    {
	      return false;
	    }
	}
      return true;
    }

  void process_magellan_balldata( void )
    {
      short axis;
      if ( crunch_magellan_nibbles() )
	{
	  for ( int i = 0; i < 6; ++i )
	    {
	      axis = buffer[( i << 2 ) + 1];
	      axis <<= 4;
	      axis |= buffer[(i << 2) + 2];
	      axis <<= 4;
	      axis |= buffer[(i << 2) + 3];
	      axis <<= 4;
	      axis |= buffer[(i << 2) + 4];
	      axis -= 32768;
/* 	      physical_axes[i] = ((buffer[(i << 2) + 1] << 12)  */
/* 		| (buffer[(i << 2 ) + 2] << 8)  */
/* 		| (buffer[(i << 2 ) + 3] << 4)  */
/* 		| (buffer[(i << 2 ) + 4])) - 32768; */
	      physical_axes[i] = axis;
	      buffer[1] = 0;
	    }
	}
      else
	{
	  for ( int i = 0; i < 6; ++i )
	    {
	      buffer[1] = 1;
	      physical_axes[i] = 666;
	    }
	}
    }

  void process_magellan_buttondata( void )
    {
      if ( crunch_magellan_nibbles() )
	{
	  physical_buttons = (buffer[1] << 1)
	    | (buffer[2] << 5)
	    | buffer[3];
	}
      
    }

  void finalize_packet( void )
  {
    switch (buffer[0])
    {
    case 'K' :
      switch (orb_type) 
      {
      case SpaceOrb360 :
        process_spaceorb_buttondata();
        break;
/*       case SpaceBall : */
/*         process_spaceball_buttondata(); */
/*         break; */
      default :
        break;
      }
      break;
    case 'D' :
      switch (orb_type) 
      {
      case SpaceOrb360 :
        process_spaceorb_balldata();
        break;
      case SpaceBall4000 :
        process_spaceball_balldata();
        break;
      default:
        break; 
      }
      break;

    case '.' :
      if (orb_type == SpaceBall4000)
	{
	  process_4000_buttondata();
	}
      break;

    case 'd' :
      if ( orb_type == SpaceBall5000)
	{
	  process_magellan_balldata();
	}
      break;

    case 'k' :
      if ( orb_type == SpaceBall5000)
	{
	  process_magellan_buttondata();
	}
      break;
    }
    _has_changed = true;
    expected_packet_length = PACKET_UNKNOWN;
  }

  void start_new_packet( char b )
  {
    buffer[0] = b;
    buffer[1] = 0;
    cursor = 1;
    expected_packet_length = packet_length( b );
  }

  void add_byte( unsigned char b )
  {
    // first off, if we have a signal to escape the next character, do that
    //if ((orb_type != SpaceOrb360) && (b=='^'))
    //{
    //  awaiting_escape = true;
    //  return;
    //}

    //okay, we actually have a character to add
    if ( awaiting_escape ) 
    {
      b = escaped_char( b );
      awaiting_escape = false;
    }
    else if ( !in_packet() )
    {
      start_new_packet( b );
    }
    else if (in_packet() && (cursor < BUFFER_SIZE-1))
    {
      buffer[cursor] = b;
      buffer[cursor+1] = 0;
      cursor++;
    }

    if ( (cursor == expected_packet_length) && (b == 13) )
    {
      finalize_packet();
    }
    else if ( b == 13 )
    {
      //invalid packet--we ended early
      _has_changed = false;
      expected_packet_length = PACKET_UNKNOWN;
    }
  }

};

#endif
