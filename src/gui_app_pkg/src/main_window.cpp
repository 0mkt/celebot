/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "main_window.hpp"

Q_DECLARE_METATYPE(custom_msg_pkg::EziServosData);

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtros {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    // Register custom datatypes for signal/slot communication
    qRegisterMetaType<custom_msg_pkg::EziServosData>("custom_msg_pkg::EziServosData");

    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
    setWindowIcon(QIcon("images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    //MKT
    //QPixmap pic("images/dickbutt.jpg");
    //ui.imagelbl_main->setPixmap(pic);

    //MKT
    //QObject::connect(&qnode, SIGNAL(guiShowMainNodeStateDesc(QString)), ui.label_main_node_state, SLOT(setText(QString)));
    //QObject::connect(&qnode, SIGNAL(guiSetMainNodeStateDesc(QString)), ui.label_main_node_state_t, SLOT(setText(QString)));
    QObject::connect(&qnode, SIGNAL(guiShowSafetyNodeStateDesc(QString)), ui.label_safety_node_state, SLOT(setText(QString)));
    QObject::connect(&qnode, SIGNAL(guiShowSafetyNodeStateDesc(QString)), ui.label_safety_node_state_t, SLOT(setText(QString)));
    QObject::connect(&qnode, SIGNAL(guiShowServosNodeStateDesc(QString)), ui.label_servos_node_state, SLOT(setText(QString)));
    QObject::connect(&qnode, SIGNAL(guiShowServosNodeStateDesc(QString)), ui.label_servos_node_state_t, SLOT(setText(QString)));

    QObject::connect(&qnode, SIGNAL(guiShowServosNodeServosData(custom_msg_pkg::EziServosData)), this, SLOT(ShowServosNodeServosData(custom_msg_pkg::EziServosData)));

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/



/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "qtros");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "qtros");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}


void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace qtros


/*****************************************************************************
** GUI Events [SAFETY NODE]
*****************************************************************************/
void qtros::MainWindow::on_pushButton_safety_arm_clicked()
{
    qnode.SafetyArm();
}

void qtros::MainWindow::on_pushButton_safety_disarm_clicked()
{
    qnode.SafetyDisarm();
}

void qtros::MainWindow::on_pushButton_safety_reset_clicked()
{
    qnode.SafetyReset();
}

void qtros::MainWindow::on_pushButton_safety_reinitialize_clicked()
{
    qnode.SafetyReinitialize();
}

void qtros::MainWindow::on_pushButton_safety_shutdown_clicked()
{
    qnode.SafetyShutdown();
}

/*****************************************************************************
** GUI Events [SERVO CONTROL NODE]
*****************************************************************************/
void qtros::MainWindow::on_pushButton_servos_motion_clicked()
{
    qnode.ServosMotion();
}

void qtros::MainWindow::on_pushButton_servos_standby_clicked()
{
    qnode.ServosStandby();
}

void qtros::MainWindow::on_pushButton_servos_alrm_reset_clicked()
{
    qnode.ServosResetAlarm();
}

void qtros::MainWindow::on_pushButton_servos_reinitialize_clicked()
{
    qnode.ServosReinitialize();
}

void qtros::MainWindow::on_pushButton_servos_shutdown_clicked()
{
    qnode.ServosShutdown();
}

/*****************************************************************************
** Showing Data on GUI [SERVO CONTROL NODE]
*****************************************************************************/
void qtros::MainWindow::ShowServosNodeServosData(custom_msg_pkg::EziServosData data)
{
    ui.label_servo_1_ip->setText(QString::fromStdString(data.eziServoData[0].ipAddress));

    QString connected = "no";
    if (data.eziServoData[0].status.connected) connected = "yes";
    ui.label_servo_1_connected->setText(connected);

    QString enabled = "no";
    if (data.eziServoData[0].status.enabled) enabled = "yes";
    ui.label_servo_1_enabled->setText(connected);

    QString alarm = "no";
    if (data.eziServoData[0].status.alarm) alarm = "yes";
    ui.label_servo_1_alarm->setText(alarm);

    QString moving = "no";
    if (data.eziServoData[0].status.moving) moving = "yes";
    ui.label_servo_1_moving->setText(moving);

    QString position = QString::number(data.eziServoData[0].actualMotion.position);
    ui.label_servo_1_pos->setText(position);

    QString velocity = QString::number(data.eziServoData[0].actualMotion.velocity);
    ui.label_servo_1_vel->setText(velocity);
}
