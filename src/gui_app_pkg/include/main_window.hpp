/**
 * @file /include/qtros/main_window.hpp
 *
 * @brief Qt based gui for qtros.
 *
 * @date November 2010
 **/
#ifndef qtros_MAIN_WINDOW_H
#define qtros_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace qtros {

//Q_DECLARE_METATYPE()

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/


private slots:
    void on_pushButton_safety_arm_clicked();

    void on_pushButton_safety_disarm_clicked();

    void on_pushButton_safety_shutdown_clicked();

    void on_pushButton_safety_reset_clicked();

    void on_pushButton_safety_reinitialize_clicked();

    void on_pushButton_servos_motion_clicked();

    void on_pushButton_servos_standby_clicked();

    void on_pushButton_servos_alrm_reset_clicked();

    void on_pushButton_servos_reinitialize_clicked();

    void on_pushButton_servos_shutdown_clicked();

    void ShowServosNodeServosData(custom_msg_pkg::EziServosData);

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace qtros

#endif // qtros_MAIN_WINDOW_H
