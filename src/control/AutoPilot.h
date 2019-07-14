#pragma once

class CVehicle;

enum eCarMission : uint8
{
	MISSION_NONE,
	MISSION_CRUISE,
	MISSION_RAMPLAYER_FARAWAY,
	MISSION_RAMPLAYER_CLOSE,
	MISSION_BLOCKPLAYER_FARAWAY,
	MISSION_BLOCKPLAYER_CLOSE,
	MISSION_BLOCKPLAYER_HANDBRAKESTOP,
	MISSION_WAITFORDELETION,
	MISSION_GOTOCOORDS,
	MISSION_GOTOCOORDS_STRAIGHT,
	MISSION_EMERGENCYVEHICLE_STOP,
	MISSION_STOP_FOREVER,
	MISSION_GOTOCOORDS_ACCURATE,
	MISSION_GOTO_COORDS_STRAIGHT_ACCURATE,
	MISSION_GOTOCOORDS_ASTHECROWSWIMS,
	MISSION_RAMCAR_FARAWAY,
	MISSION_RAMCAR_CLOSE,
	MISSION_BLOCKCAR_FARAWAY,
	MISSION_BLOCKCAR_CLOSE,
	MISSION_BLOCKCAR_HANDBRAKESTOP,
	MISSION_HELI_FLYTOCOORS,
	MISSION_ATTACKPLAYER,
	MISSION_PLANE_FLYTOCOORS,
	MISSION_HELI_LAND,
	MISSION_SLOWLY_DRIVE_TOWARDS_PLAYER_1,
	MISSION_SLOWLY_DRIVE_TOWARDS_PLAYER_2,
	MISSION_BLOCKPLAYER_FORWARDANDBACK
};

enum eCarTempAction : uint8
{
	TEMPACT_NONE,
	TEMPACT_WAIT,
	TEMPACT_REVERSE,
	TEMPACT_HANDBRAKETURNLEFT,
	TEMPACT_HANDBRAKETURNRIGHT,
	TEMPACT_HANDBRAKESTRAIGHT,
	TEMPACT_TURNLEFT,
	TEMPACT_TURNRIGHT,
	TEMPACT_GOFORWARD,
	TEMPACT_SWERVELEFT,
	TEMPACT_SWERVERIGHT
};

enum eCarDrivingStyle : uint8
{
	DRIVINGSTYLE_STOP_FOR_CARS,
	DRIVINGSTYLE_SLOW_DOWN_FOR_CARS,
	DRIVINGSTYLE_AVOID_CARS,
	DRIVINGSTYLE_PLOUGH_THROUGH,
	DRIVINGSTYLE_STOP_FOR_CARS_IGNORE_LIGHTS
};

class CAutoPilot {
public:
	uint32 m_nCurrentRouteNode;
	uint32 m_nNextRouteNode;
	uint32 m_nPrevRouteNode;
	uint32 m_nTotalSpeedScaleFactor;
	uint32 m_nSpeedScaleFactor;
	uint32 m_nCurrentPathNodeInfo;
	uint32 m_nNextPathNodeInfo;
	uint32 m_nPreviousPathNodeInfo;
	uint32 m_nTimeToStartMission;
	uint32 m_nTimeSwitchedToRealPhysics;
	int8 m_nPreviousDirection;
	int8 m_nCurrentDirecton;
	int8 m_nNextDirection;
	int8 m_nPreviousLane;
	int8 m_nCurrentLane;
	eCarDrivingStyle m_nDrivingStyle;
	eCarMission m_nCarMission;
	eCarTempAction m_nAnimationId;
	uint8 m_nAnimationTime;
	float m_fMaxTrafficSpeed;
	uint8 m_nCruiseSpeed;
	uint8 m_flag1 : 1;
	uint8 m_flag2 : 1;
	uint8 m_flag4 : 1;
	uint8 m_flag8 : 1;
	uint8 m_flag10 : 1;
	CVector m_vecDestinationCoors;
	void *m_aPathFindNodesInfo[8];
	uint16 m_nPathFindNodesCount;
	CVehicle *m_pTargetCar;

	CAutoPilot(void) {
		m_nPrevRouteNode = 0;
		m_nNextRouteNode = m_nPrevRouteNode;
		m_nCurrentRouteNode = m_nNextRouteNode;
		m_nTotalSpeedScaleFactor = 0;
		m_nSpeedScaleFactor = 1000;
		m_nPreviousPathNodeInfo = 0;
		m_nNextPathNodeInfo = m_nPreviousPathNodeInfo;
		m_nCurrentPathNodeInfo = m_nNextPathNodeInfo;
		m_nNextDirection = 1;
		m_nCurrentDirecton = m_nNextDirection;
		m_nCurrentLane = 0;
		m_nPreviousLane = m_nPreviousLane;
		m_nDrivingStyle = DRIVINGSTYLE_STOP_FOR_CARS;
		m_nCarMission = MISSION_NONE;
		m_nAnimationId = TEMPACT_NONE;
		m_nCruiseSpeed = 10;
		m_fMaxTrafficSpeed = 10.0f;
		m_flag2 = false;
		m_flag1 = false;
		m_nPathFindNodesCount = 0;
		m_pTargetCar = 0;
		m_nTimeToStartMission = CTimer::GetTimeInMilliseconds();
		m_nTimeSwitchedToRealPhysics = m_nTimeToStartMission;
		m_flag8 = false;
	}
};
static_assert(sizeof(CAutoPilot) == 0x70, "CAutoPilot: error");
