// license:BSD-3-Clause
// copyright-holders:<author_name>
/***************************************************************************

	Namco C148 Interrupt Controller

***************************************************************************/
/*
Interrupt Controller C148          1C0000-1FFFFF  R/W  D00-D02
    ????????                       1C0XXX
    ????????                       1C2XXX
    ????????                       1C4XXX
    Master/Slave IRQ level         1C6XXX              D00-D02
    EXIRQ level                    1C8XXX              D00-D02
    POSIRQ level                   1CAXXX              D00-D02
    SCIRQ level                    1CCXXX              D00-D02
    VBLANK IRQ level               1CEXXX              D00-D02
    ????????                       1D0XXX
    ????????                       1D4000 trigger master/slave INT?

    Acknowlegde Master/Slave IRQ   1D6XXX ack master/slave INT
    Acknowledge EXIRQ              1D8XXX
    Acknowledge POSIRQ             1DAXXX
    Acknowledge SCIRQ              1DCXXX
    Acknowledge VBLANK IRQ         1DEXXX

    EEPROM Ready status            1E0XXX         R    D01
    Sound CPU Reset control        1E2XXX           W  D01
    Slave 68000 & IO CPU Reset     1E4XXX           W  D01
    Watchdog reset kicker          1E6XXX           W
 */

#include "emu.h"
#include "namco_c148.h"



//**************************************************************************
//  GLOBAL VARIABLES
//**************************************************************************

// device type definition
const device_type NAMCO_C148 = &device_creator<namco_c148_device>;


//**************************************************************************
//  LIVE DEVICE
//**************************************************************************

//-------------------------------------------------
//  namco_c148_device - constructor
//-------------------------------------------------

namco_c148_device::namco_c148_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock)
	: device_t(mconfig, NAMCO_C148, "Namco C148 Interrupt Controller", tag, owner, clock, "namco_c148", __FILE__)
{
}

// (*) denotes master CPU only
DEVICE_ADDRESS_MAP_START( map, 16, namco_c148_device )
//	AM_RANGE(0x06000, 0x07fff) // CPUIRQ lv
//	AM_RANGE(0x08000, 0x09fff) // EXIRQ lv
//	AM_RANGE(0x0a000, 0x0bfff) // POSIRQ lv
//	AM_RANGE(0x0c000, 0x0dfff) // SCIRQ lv
//	AM_RANGE(0x0e000, 0x0ffff) // VBlank IRQ lv

//	AM_RANGE(0x16000, 0x17fff) // CPUIRQ ack
//	AM_RANGE(0x18000, 0x19fff) // EXIRQ ack
//	AM_RANGE(0x1a000, 0x1bfff) // POSIRQ ack
//	AM_RANGE(0x1c000, 0x1dfff) // SCIRQ ack
//	AM_RANGE(0x1e000, 0x1ffff) // VBlank IRQ ack
//	AM_RANGE(0x20000, 0x21fff) // EEPROM ready status
//	AM_RANGE(0x22000, 0x23fff) // sound CPU reset (*)
//	AM_RANGE(0x24000, 0x25fff) // slave & i/o reset (*)
	AM_RANGE(0x26000, 0x27fff) AM_NOP // watchdog
ADDRESS_MAP_END



//-------------------------------------------------
//  device_start - device-specific startup
//-------------------------------------------------

void namco_c148_device::device_start()
{
}


//-------------------------------------------------
//  device_reset - device-specific reset
//-------------------------------------------------

void namco_c148_device::device_reset()
{
}

//**************************************************************************
//  READ/WRITE HANDLERS
//**************************************************************************

