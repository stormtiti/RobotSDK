#ifndef OBSTACLE
#define OBSTACLE

//=================================================
//Please add headers here:
#include<sensor_msgs/LaserScan.h>
#include<rosinterface.h>

//=================================================
#include<RobotSDK.h>
namespace RobotSDK_Module
{

//=================================================
//Node configuration

#undef NODE_CLASS
#define NODE_CLASS Obstacle

#undef INPUT_PORT_NUM
#define INPUT_PORT_NUM 0

#undef OUTPUT_PORT_NUM
#define OUTPUT_PORT_NUM 1

//=================================================
//Params types configuration

//If you need to refer params type of other node class, please uncomment below and comment its own params type.
//NODE_PARAMS_TYPE_REF(RefNodeClassName)
class NODE_PARAMS_TYPE : public NODE_PARAMS_BASE_TYPE
{
public:
    ADD_PARAM(double, width, 1)
    ADD_PARAM(double, height, 1)
};

//=================================================
//Vars types configuration

//If you need to refer vars type of other node class, please uncomment below and comment its own vars type.
//NODE_VARS_TYPE_REF(RefNodeClassName)
class NODE_VARS_TYPE : public NODE_VARS_BASE_TYPE
{
public:
    ADD_VAR(QString, topic, "/scan")
    ADD_VAR(u_int32_t, queuesize, 1000)
    ADD_VAR(int, queryinterval, 10)
public:
    typedef ROSSub<sensor_msgs::LaserScanConstPtr> rossub;
    ADD_INTERNAL_QOBJECT_TRIGGER(rossub, urgsub, 1, topic, queuesize, queryinterval)
    ADD_INTERNAL_DEFAULT_CONNECTION(urgsub, receiveMessageSignal)
};

//=================================================
//Data types configuration

//If you need to refer data type of other node class, please uncomment below and comment its own data type.
//NODE_DATA_TYPE_REF(RefNodeClassName)
class NODE_DATA_TYPE : public NODE_DATA_BASE_TYPE
{
public:
    bool obstacleflag;
};

//=================================================
//You can declare functions here


//=================================================
}

#endif
