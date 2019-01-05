//*****************************************************************************
// Filename:            actuator_helper.cpp
//
// Revision Record:
//   Author             Date       Description
//   ------------------ ---------- --------------------------------------------
//   Chris Struck       Jan. 2018  Initial design.
//
// Description:
//    This class operates a linear actuator using the FRC Server class.
//    The class has the ability to drive actuator open, closed, and various 
//        positions in between.
// 
// Dependencies:
//    None
//*****************************************************************************

/******************************************************************************
 * Include Files
 *****************************************************************************/
// FIRST Includes
#include <Servo.h>

// Our Includes
#include "actuator_helper.hpp"

/******************************************************************************
 * Variables
 *****************************************************************************/
float actuatorValue = 0.0;
    
/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
Actuator::Actuator(int actuatorChannel)
{
    actuatorMotor = new frc::Servo(actuatorChannel);
    GetValue();
}
    
/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
void Actuator::ExtendMax()
{
    actuatorMotor->Set(EXTEND_MAX);
    GetValue();
}
    
/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
void Actuator::ExtendMin()
{
    actuatorMotor->Set(EXTEND_MIN);
    GetValue();
}
    
/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
void Actuator::ExtendMid()
{
    actuatorMotor->Set(EXTEND_MID);
    GetValue();
}
    
/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
void Actuator::ExtendBlockMax()
{
	//Pinches Block
    actuatorMotor->Set(0.5);		//0.52
    GetValue();
}

/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
void Actuator::ExtendBlockMin()
{
	//Releases Block
    actuatorMotor->Set(0.42);		//0.41
    GetValue();
}
    
/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
void Actuator::ExtendVariable(float extendValue)
{
    if (extendValue >= EXTEND_MIN && extendValue <= EXTEND_MAX)
    {
        actuatorMotor->Set(extendValue);
        GetValue();
    }
}
    
/*-----------------------------------------------------------------------------
 * FUNCTION NAME:    Motor
 *---------------------------------------------------------------------------*/
void Actuator::GetValue()
{
    actuatorValue = actuatorMotor->Get();
}
