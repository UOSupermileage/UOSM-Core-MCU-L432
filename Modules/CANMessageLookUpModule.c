/*
 * CANMessageLookUpModule.c
 *
 *  Created on: Dec 4, 2022
 *      Author: mingy
 */

#include "CANMessageLookUpModule.h"
#include "CANDriver.h"

// Callbacks
extern void ThrottleDataCallback(iCommsMessage_t *msg);
extern void ErrorDataCallback(iCommsMessage_t *msg);
extern void SpeedDataCallback(iCommsMessage_t *msg);
extern void EventDataCallback(iCommsMessage_t *msg);
extern void MotorRPMDataCallback(iCommsMessage_t *msg);
extern void VoltageDataCallback(iCommsMessage_t *msg);

/*********************************************************************************
 *
 * 		Look up table for CAN ID and meta data about its payload
 *
 **********************************************************************************/
const ICommsMessageInfo CANMessageLookUpTable[NUMBER_CAN_MESSAGE_IDS] = {
    // Message Index			CAN ID		Num of Bytes		Callback
    {THROTTLE_DATA_ID, 0x0001, 2, &ThrottleDataCallback},
    {SPEED_DATA_ID, 0x0002, 4, &SpeedDataCallback},
	{MOTOR_RPM_DATA_ID, 0x0003, 4, &MotorRPMDataCallback},
    {EVENT_DATA_ID, 0x0400, 2, &EventDataCallback},
    {ERROR_DATA_ID, 0x0401, 2, &ErrorDataCallback},
	{VOLTAGE_DATA_ID, 0x0004, 2, &VoltageDataCallback},
};

__weak void ThrottleDataCallback(iCommsMessage_t *msg) { DebugPrint("ThrottleDataCallback not implemented! %d", msg->standardMessageID); }
__weak void ErrorDataCallback(iCommsMessage_t *msg) { DebugPrint("ErrorDataCallback not implemented! %d", msg->standardMessageID); }
__weak void SpeedDataCallback(iCommsMessage_t *msg) { DebugPrint("SpeedDataCallback not implemented! %d", msg->standardMessageID); }
__weak void EventDataCallback(iCommsMessage_t *msg) { DebugPrint("EventDataCallback not implemented! %d", msg->standardMessageID); }
__weak void MotorRPMDataCallback(iCommsMessage_t *msg) { DebugPrint("MotorRPMDataCallback not implemented! %d", msg->standardMessageID); }
__weak void VoltageDataCallback(iCommsMessage_t *msg) { DebugPrint("VoltageDataCallback not implemented! %d", msg->standardMessageID); }

PUBLIC const ICommsMessageInfo *CANMessageLookUpGetInfo(ICommsMessageLookUpIndex id) { return &CANMessageLookUpTable[id]; }
