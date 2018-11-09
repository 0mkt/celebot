/**
 * @file /include/qtros/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef qtros_QNODE_HPP_
#define qtros_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <map>
#include <iterator>
#include <QThread>
#include <QStringListModel>
#include "std_msgs/Int32.h"
#include "custom_msg_pkg/ChangeNodeStateSrv.h"
#include "custom_msg_pkg/EziServoStatus.h"
#include "custom_msg_pkg/EziServoActualMotion.h"
#include "custom_msg_pkg/EziServoData.h"
#include "custom_msg_pkg/EziServosData.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtros {
/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();

    //Safety Node Commands
    void SafetyArm();
    void SafetyDisarm();
    void SafetyReset();
    void SafetyReinitialize();
    void SafetyShutdown();

    //Servo Control Node Commands
    void ServosMotion();
    void ServosStandby();
    void ServosResetAlarm();
    void ServosReinitialize();
    void ServosShutdown();

Q_SIGNALS:
    void rosShutdown();
    void guiShowMainNodeStateDesc(QString);
    void guiShowSafetyNodeStateDesc(QString);
    void guiShowServosNodeStateDesc(QString);
    void guiShowServosNodeServosData(custom_msg_pkg::EziServosData);

private:
	int init_argc;
	char** init_argv;
    ros::Publisher gui_publisher;

    std::map<int, QString> mainNodeStatesMap;
    std::map<int, QString> safetyNodeStatesMap;
    std::map<int, QString> servosNodeStatesMap;

    int mainNodeState;
    int safetyNodeState;
    int servosNodeState;

    void MainNodeStateTopicSubscriberCallback(const std_msgs::Int32::ConstPtr& msg);
    void SafetyNodeStateTopicSubscriberCallback(const std_msgs::Int32::ConstPtr& msg);
    void ServosNodeStateTopicSubscriberCallback(const std_msgs::Int32::ConstPtr& msg);
    void ServosNodeServosDataTopicSubscriberCallback(const custom_msg_pkg::EziServosData::ConstPtr& msg);

    ros::Subscriber mainNode_state_subscriber;
    ros::Subscriber safetyNode_state_subscriber;
    ros::Subscriber servosNode_state_subscriber;
    ros::Subscriber servosNode_servosData_subscriber;

    ros::ServiceClient safetyNode_changeState_srvclient;
    ros::ServiceClient servosNode_changeState_srvclient;

    void LoadParametersFromServer();
    void CheckWhichNodesAreRunning();

};

}  // namespace qtros

#endif /* qtros_QNODE_HPP_ */
