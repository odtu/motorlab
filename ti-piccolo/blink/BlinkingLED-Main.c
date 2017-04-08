//----------------------------------------------------------------------------------
//	FILE:			BlinkingLED-Main.C
//
//	Description:	This program blinks LD2 on the Piccolo controlSTICK at a 
//					frequency given by the CPU timer period register.  Change the 
//					register/bits CpuTimer0Regs.PRD.all to change the frequency of 
//					the LED (LD2).
//
//  Target:  		TMS320F2802x or TMS320F2803x families (Piccolo)
//
//----------------------------------------------------------------------------------
//  $TI Release:$ 	V1.1
//  $Release Date:$ 26 Oct 2009 - BRL
//----------------------------------------------------------------------------------
//
// PLEASE READ - Useful notes about this Project

// Although this project is made up of several files, the most important ones are:
//	 "BlinkingLED-Main.c"	- this file
//		- Application Initialization, Peripheral config
//		- Application management
//		- Slower background code loops and Task scheduling
//	 "BlinkingLED-DevInit_F28xxx.c"
//		- Device Initialization, e.g. Clock, PLL, WD, GPIO mapping
//		- Peripheral clock enables
// The other files are generally used for support and defining the registers as C
// structs. In general these files will not need to be changed.
//   "F28027_RAM_BlinkingLED.CMD" or "F28027_FLASH_BlinkingLED.CMD"
//		- Allocates the program and data spaces into the device's memory map.
//   "DSP2802x_Headers_nonBIOS.cmd" and "DSP2802x_GlobalVariableDefs.c"
//		- Allocate the register structs into data memory.  These register structs are
//		  defined in the peripheral header includes (DSP2802x_Adc.h, ...) 
//
//----------------------------------------------------------------------------------

#include "DSP2802x_Device.h"
																		 

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// FUNCTION PROTOTYPES
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void DeviceInit(void);
void InitFlash(void);
void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DECLARATIONS - GENERAL
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// Used for running BackGround in flash and the ISR in RAM
extern Uint16 RamfuncsLoadStart, RamfuncsLoadEnd, RamfuncsRunStart;


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// MAIN CODE - starts here
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void main(void)
{

//=================================
//	INITIALISATION - General
//=================================

	DeviceInit();	// Device Life support & GPIO mux settings

// Only used if running from FLASH
// Note that the variable FLASH is defined by the compiler (-d FLASH)
#ifdef FLASH		
// Copy time critical code and Flash setup code to RAM
// The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
// symbols are created by the linker. Refer to the linker files. 
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

// Call Flash Initialization to setup flash waitstates
// This function must reside in RAM
	InitFlash();	// Call the flash wrapper init function
#endif //(FLASH)

// Initialise Period of Cpu Timers
// Timer period definitions found in PeripheralHeaderIncludes.h
	CpuTimer0Regs.PRD.all =  mSec500;	// 500ms * 2(# of LED states) = 1s blink rate
//	CpuTimer1Regs.PRD.all =  mSec1000;	
//	CpuTimer2Regs.PRD.all =  mSec5000;	


//=================================
//	INTERRUPT INITIALISATION (not needed in this example)
//  (best to run this section after other initialisation)
//=================================

// Enable Peripheral, global Ints and higher priority real-time debug events:
//	IER |= M_INT3; 
//	EINT;   // Enable Global interrupt INTM
//	ERTM;   // Enable Global realtime interrupt DBGM


//=================================
//	Forever LOOP
//=================================

	for(;;)  //infinite loop
	{
		if(CpuTimer0Regs.TCR.bit.TIF == 1)
		{
			CpuTimer0Regs.TCR.bit.TIF = 1;	// clear flag

			//-----------------------------------------------------------
			GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;	//Toggle GPIO34 (LD2)
			//-----------------------------------------------------------
		}

	}
} //END MAIN CODE


