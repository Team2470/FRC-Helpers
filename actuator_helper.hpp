//*****************************************************************************
// Filename:            actuator_helper.hpp
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

#ifndef ACTUATOR_HELPER_HPP
#define ACTUATOR_HELPER_HPP

/******************************************************************************
 * Include Files
 *****************************************************************************/
// FIRST Includes
#include <Servo.h>

/******************************************************************************
 * Constants
 *****************************************************************************/

/******************************************************************************
 * Types
 *****************************************************************************/
 
/******************************************************************************
 * CLASS      : Actuator
 *
 * DESCRIPTION: This class is to operate a Linear Actuator.
 *
 * RETURNS    : A Servo object
 *****************************************************************************/
class Actuator
{
public:
    /**************************************************************************
     * Variables
     *************************************************************************/
	float actuatorValue = 0.0;

    /**************************************************************************
     * FUNCTION   : Actuator
     *
     * DESCRIPTION: Constructs the Actuator object with the specified 
     *              <actuatorChannel>.
     *
     * RETURNS    : A actuator object
     *************************************************************************/
	Actuator(int actuatorChannel);

    /**************************************************************************
     * FUNCTION   : ExtendMax
     *
     * DESCRIPTION: Extends the actuator to the maximum position.
     *
     * RETURNS    : Void
     *************************************************************************/	
	void ExtendMax();

    /**************************************************************************
     * FUNCTION   : ExtendMin
     *
     * DESCRIPTION: Extends the actuator to the minimum position.
     *
     * RETURNS    : Void
     *************************************************************************/
	void ExtendMin();

    /**************************************************************************
     * FUNCTION   : ExtendMid
     *
     * DESCRIPTION: Extends the actuator to the mid position.
     *
     * RETURNS    : Void
     *************************************************************************/
	void ExtendMid();

	/**************************************************************************
	 * FUNCTION   : ExtendBlockMax
	 *
	 * DESCRIPTION: Extends the actuator large enough to grab a 2018 game
	 *                  piece, a milk crate.
	 *
	 * RETURNS    : Void
	 *************************************************************************/
	void ExtendBlockMax();

    /**************************************************************************
     * FUNCTION   : ExtendBlockMin
     *
     * DESCRIPTION: Extends the actuator large enough to grab a 2018 game
     *                  piece, a milk crate.
     *
     * RETURNS    : Void
     *************************************************************************/
	void ExtendBlockMin();

    /**************************************************************************
     * FUNCTION   : ExtendVariable
     *
     * DESCRIPTION: Extends the actuator to the <extendValue> position.
     *                  <extendValue> should be between the min and max
     *                  position.
     *
     * RETURNS    : Void
     *************************************************************************/
	void ExtendVariable(float extendValue);

    /**************************************************************************
     * FUNCTION   : GetValue
     *
     * DESCRIPTION: Sets <actuatorValue> to the current actuator position.
     *
     * RETURNS    : Void
     *************************************************************************/
	void GetValue();

private:
	frc::Servo *actuatorMotor;

	static constexpr float EXTEND_MAX = 0.82;
	static constexpr float EXTEND_MID = 0.5;
	static constexpr float EXTEND_MIN = 0.17;

};

#endif /* ACTUATOR_HELPER_HPP */
