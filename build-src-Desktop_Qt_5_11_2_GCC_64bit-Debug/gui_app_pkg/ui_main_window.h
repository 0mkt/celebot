/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QTabWidget *tab_manager;
    QWidget *tab;
    QGroupBox *groupBox_nodes;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_node_states;
    QLabel *label_safety_node_state_;
    QLabel *label_safety_node_state;
    QLabel *label_node_states_state_;
    QLabel *label_servos_node_state_;
    QLabel *label_servos_node_state;
    QLabel *label_node_states_node_;
    QWidget *tab_safety;
    QGroupBox *groupBox_safety_state_control;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_safety_arm;
    QPushButton *pushButton_safety_disarm;
    QPushButton *pushButton_safety_reset;
    QPushButton *pushButton_safety_reinitialize;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_safety_node_state_t_;
    QLabel *label_safety_node_state_t;
    QWidget *tab_servo_control;
    QGroupBox *groupBox_servo_state_control;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_servos_motion;
    QPushButton *pushButton_servos_standby;
    QPushButton *pushButton_servos_alrm_reset;
    QPushButton *pushButton_servos_reinitialize;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_servos_node_state_t_;
    QLabel *label_servos_node_state_t;
    QGroupBox *groupBox_servo_1;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_servo_1;
    QLabel *label_servo_1_pos_;
    QLabel *label_servo_1_vel_;
    QLabel *label_servo_1_pos;
    QLabel *label_servo_1_vel;
    QLabel *label_servo_1_enabled_;
    QLabel *label_servo_1_enabled;
    QLabel *label_servo_1_connected_;
    QLabel *label_servo_1_connected;
    QLabel *label_servo_1_ip_;
    QLabel *label_servo_1_ip;
    QLabel *label_servo_1_alarm_;
    QLabel *label_servo1_alarm;
    QLabel *label_servo_1_moving_;
    QLabel *label_servo_1_moving;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    QDockWidget *dock_status;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *line_edit_master;
    QLabel *label_2;
    QLineEdit *line_edit_host;
    QLabel *label_3;
    QLineEdit *line_edit_topic;
    QCheckBox *checkbox_use_environment;
    QCheckBox *checkbox_remember_settings;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_connect;
    QSpacerItem *verticalSpacer_3;
    QPushButton *quit_button;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QStringLiteral("MainWindowDesign"));
        MainWindowDesign->resize(944, 704);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QStringLiteral("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        tab_manager = new QTabWidget(centralwidget);
        tab_manager->setObjectName(QStringLiteral("tab_manager"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab_manager->sizePolicy().hasHeightForWidth());
        tab_manager->setSizePolicy(sizePolicy);
        tab_manager->setMinimumSize(QSize(100, 0));
        tab_manager->setLocale(QLocale(QLocale::English, QLocale::Australia));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_nodes = new QGroupBox(tab);
        groupBox_nodes->setObjectName(QStringLiteral("groupBox_nodes"));
        groupBox_nodes->setGeometry(QRect(10, 10, 571, 191));
        gridLayoutWidget = new QWidget(groupBox_nodes);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 551, 127));
        gridLayout_node_states = new QGridLayout(gridLayoutWidget);
        gridLayout_node_states->setObjectName(QStringLiteral("gridLayout_node_states"));
        gridLayout_node_states->setContentsMargins(0, 0, 0, 0);
        label_safety_node_state_ = new QLabel(gridLayoutWidget);
        label_safety_node_state_->setObjectName(QStringLiteral("label_safety_node_state_"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setBold(false);
        font.setWeight(50);
        label_safety_node_state_->setFont(font);
        label_safety_node_state_->setAlignment(Qt::AlignCenter);

        gridLayout_node_states->addWidget(label_safety_node_state_, 1, 0, 1, 1);

        label_safety_node_state = new QLabel(gridLayoutWidget);
        label_safety_node_state->setObjectName(QStringLiteral("label_safety_node_state"));
        label_safety_node_state->setAlignment(Qt::AlignCenter);

        gridLayout_node_states->addWidget(label_safety_node_state, 1, 1, 1, 1);

        label_node_states_state_ = new QLabel(gridLayoutWidget);
        label_node_states_state_->setObjectName(QStringLiteral("label_node_states_state_"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_node_states_state_->setFont(font1);
        label_node_states_state_->setAlignment(Qt::AlignCenter);

        gridLayout_node_states->addWidget(label_node_states_state_, 0, 1, 1, 1);

        label_servos_node_state_ = new QLabel(gridLayoutWidget);
        label_servos_node_state_->setObjectName(QStringLiteral("label_servos_node_state_"));
        label_servos_node_state_->setFont(font);
        label_servos_node_state_->setAlignment(Qt::AlignCenter);

        gridLayout_node_states->addWidget(label_servos_node_state_, 2, 0, 1, 1);

        label_servos_node_state = new QLabel(gridLayoutWidget);
        label_servos_node_state->setObjectName(QStringLiteral("label_servos_node_state"));
        label_servos_node_state->setAlignment(Qt::AlignCenter);

        gridLayout_node_states->addWidget(label_servos_node_state, 2, 1, 1, 1);

        label_node_states_node_ = new QLabel(gridLayoutWidget);
        label_node_states_node_->setObjectName(QStringLiteral("label_node_states_node_"));
        label_node_states_node_->setFont(font1);
        label_node_states_node_->setAlignment(Qt::AlignCenter);

        gridLayout_node_states->addWidget(label_node_states_node_, 0, 0, 1, 1);

        tab_manager->addTab(tab, QString());
        tab_safety = new QWidget();
        tab_safety->setObjectName(QStringLiteral("tab_safety"));
        groupBox_safety_state_control = new QGroupBox(tab_safety);
        groupBox_safety_state_control->setObjectName(QStringLiteral("groupBox_safety_state_control"));
        groupBox_safety_state_control->setGeometry(QRect(10, 10, 571, 201));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_safety_state_control->sizePolicy().hasHeightForWidth());
        groupBox_safety_state_control->setSizePolicy(sizePolicy1);
        groupBox_safety_state_control->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayoutWidget_2 = new QWidget(groupBox_safety_state_control);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 110, 511, 81));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_safety_arm = new QPushButton(gridLayoutWidget_2);
        pushButton_safety_arm->setObjectName(QStringLiteral("pushButton_safety_arm"));
        pushButton_safety_arm->setLayoutDirection(Qt::LeftToRight);
        pushButton_safety_arm->setAutoFillBackground(false);
        pushButton_safety_arm->setFlat(false);

        gridLayout_2->addWidget(pushButton_safety_arm, 0, 0, 1, 1);

        pushButton_safety_disarm = new QPushButton(gridLayoutWidget_2);
        pushButton_safety_disarm->setObjectName(QStringLiteral("pushButton_safety_disarm"));
        pushButton_safety_disarm->setLayoutDirection(Qt::LeftToRight);
        pushButton_safety_disarm->setAutoFillBackground(false);
        pushButton_safety_disarm->setFlat(false);

        gridLayout_2->addWidget(pushButton_safety_disarm, 1, 0, 1, 1);

        pushButton_safety_reset = new QPushButton(gridLayoutWidget_2);
        pushButton_safety_reset->setObjectName(QStringLiteral("pushButton_safety_reset"));
        pushButton_safety_reset->setLayoutDirection(Qt::LeftToRight);
        pushButton_safety_reset->setAutoFillBackground(false);
        pushButton_safety_reset->setFlat(false);

        gridLayout_2->addWidget(pushButton_safety_reset, 0, 1, 1, 1);

        pushButton_safety_reinitialize = new QPushButton(gridLayoutWidget_2);
        pushButton_safety_reinitialize->setObjectName(QStringLiteral("pushButton_safety_reinitialize"));
        pushButton_safety_reinitialize->setLayoutDirection(Qt::LeftToRight);
        pushButton_safety_reinitialize->setAutoFillBackground(false);
        pushButton_safety_reinitialize->setFlat(false);

        gridLayout_2->addWidget(pushButton_safety_reinitialize, 1, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(groupBox_safety_state_control);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(140, 40, 291, 51));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_safety_node_state_t_ = new QLabel(gridLayoutWidget_3);
        label_safety_node_state_t_->setObjectName(QStringLiteral("label_safety_node_state_t_"));
        label_safety_node_state_t_->setFont(font);
        label_safety_node_state_t_->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_safety_node_state_t_, 0, 0, 1, 1);

        label_safety_node_state_t = new QLabel(gridLayoutWidget_3);
        label_safety_node_state_t->setObjectName(QStringLiteral("label_safety_node_state_t"));
        label_safety_node_state_t->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_safety_node_state_t, 0, 1, 1, 1);

        tab_manager->addTab(tab_safety, QString());
        tab_servo_control = new QWidget();
        tab_servo_control->setObjectName(QStringLiteral("tab_servo_control"));
        groupBox_servo_state_control = new QGroupBox(tab_servo_control);
        groupBox_servo_state_control->setObjectName(QStringLiteral("groupBox_servo_state_control"));
        groupBox_servo_state_control->setGeometry(QRect(10, 10, 571, 201));
        sizePolicy1.setHeightForWidth(groupBox_servo_state_control->sizePolicy().hasHeightForWidth());
        groupBox_servo_state_control->setSizePolicy(sizePolicy1);
        groupBox_servo_state_control->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayoutWidget_4 = new QWidget(groupBox_servo_state_control);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(30, 110, 511, 81));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(6);
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_servos_motion = new QPushButton(gridLayoutWidget_4);
        pushButton_servos_motion->setObjectName(QStringLiteral("pushButton_servos_motion"));
        pushButton_servos_motion->setLayoutDirection(Qt::LeftToRight);
        pushButton_servos_motion->setAutoFillBackground(false);
        pushButton_servos_motion->setFlat(false);

        gridLayout_4->addWidget(pushButton_servos_motion, 0, 0, 1, 1);

        pushButton_servos_standby = new QPushButton(gridLayoutWidget_4);
        pushButton_servos_standby->setObjectName(QStringLiteral("pushButton_servos_standby"));
        pushButton_servos_standby->setLayoutDirection(Qt::LeftToRight);
        pushButton_servos_standby->setAutoFillBackground(false);
        pushButton_servos_standby->setFlat(false);

        gridLayout_4->addWidget(pushButton_servos_standby, 1, 0, 1, 1);

        pushButton_servos_alrm_reset = new QPushButton(gridLayoutWidget_4);
        pushButton_servos_alrm_reset->setObjectName(QStringLiteral("pushButton_servos_alrm_reset"));
        pushButton_servos_alrm_reset->setLayoutDirection(Qt::LeftToRight);
        pushButton_servos_alrm_reset->setAutoFillBackground(false);
        pushButton_servos_alrm_reset->setFlat(false);

        gridLayout_4->addWidget(pushButton_servos_alrm_reset, 0, 1, 1, 1);

        pushButton_servos_reinitialize = new QPushButton(gridLayoutWidget_4);
        pushButton_servos_reinitialize->setObjectName(QStringLiteral("pushButton_servos_reinitialize"));
        pushButton_servos_reinitialize->setLayoutDirection(Qt::LeftToRight);
        pushButton_servos_reinitialize->setAutoFillBackground(false);
        pushButton_servos_reinitialize->setFlat(false);

        gridLayout_4->addWidget(pushButton_servos_reinitialize, 1, 1, 1, 1);

        gridLayoutWidget_5 = new QWidget(groupBox_servo_state_control);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(130, 40, 301, 51));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_servos_node_state_t_ = new QLabel(gridLayoutWidget_5);
        label_servos_node_state_t_->setObjectName(QStringLiteral("label_servos_node_state_t_"));
        label_servos_node_state_t_->setFont(font);
        label_servos_node_state_t_->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_servos_node_state_t_, 0, 0, 1, 1);

        label_servos_node_state_t = new QLabel(gridLayoutWidget_5);
        label_servos_node_state_t->setObjectName(QStringLiteral("label_servos_node_state_t"));
        label_servos_node_state_t->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_servos_node_state_t, 0, 1, 1, 1);

        groupBox_servo_1 = new QGroupBox(tab_servo_control);
        groupBox_servo_1->setObjectName(QStringLiteral("groupBox_servo_1"));
        groupBox_servo_1->setGeometry(QRect(10, 230, 191, 201));
        formLayoutWidget = new QWidget(groupBox_servo_1);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 171, 161));
        formLayout_servo_1 = new QFormLayout(formLayoutWidget);
        formLayout_servo_1->setObjectName(QStringLiteral("formLayout_servo_1"));
        formLayout_servo_1->setContentsMargins(0, 0, 0, 0);
        label_servo_1_pos_ = new QLabel(formLayoutWidget);
        label_servo_1_pos_->setObjectName(QStringLiteral("label_servo_1_pos_"));
        label_servo_1_pos_->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(5, QFormLayout::LabelRole, label_servo_1_pos_);

        label_servo_1_vel_ = new QLabel(formLayoutWidget);
        label_servo_1_vel_->setObjectName(QStringLiteral("label_servo_1_vel_"));
        label_servo_1_vel_->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(6, QFormLayout::LabelRole, label_servo_1_vel_);

        label_servo_1_pos = new QLabel(formLayoutWidget);
        label_servo_1_pos->setObjectName(QStringLiteral("label_servo_1_pos"));
        label_servo_1_pos->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(5, QFormLayout::FieldRole, label_servo_1_pos);

        label_servo_1_vel = new QLabel(formLayoutWidget);
        label_servo_1_vel->setObjectName(QStringLiteral("label_servo_1_vel"));
        label_servo_1_vel->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(6, QFormLayout::FieldRole, label_servo_1_vel);

        label_servo_1_enabled_ = new QLabel(formLayoutWidget);
        label_servo_1_enabled_->setObjectName(QStringLiteral("label_servo_1_enabled_"));
        label_servo_1_enabled_->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(2, QFormLayout::LabelRole, label_servo_1_enabled_);

        label_servo_1_enabled = new QLabel(formLayoutWidget);
        label_servo_1_enabled->setObjectName(QStringLiteral("label_servo_1_enabled"));
        label_servo_1_enabled->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(2, QFormLayout::FieldRole, label_servo_1_enabled);

        label_servo_1_connected_ = new QLabel(formLayoutWidget);
        label_servo_1_connected_->setObjectName(QStringLiteral("label_servo_1_connected_"));
        label_servo_1_connected_->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(1, QFormLayout::LabelRole, label_servo_1_connected_);

        label_servo_1_connected = new QLabel(formLayoutWidget);
        label_servo_1_connected->setObjectName(QStringLiteral("label_servo_1_connected"));
        label_servo_1_connected->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(1, QFormLayout::FieldRole, label_servo_1_connected);

        label_servo_1_ip_ = new QLabel(formLayoutWidget);
        label_servo_1_ip_->setObjectName(QStringLiteral("label_servo_1_ip_"));
        label_servo_1_ip_->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(0, QFormLayout::LabelRole, label_servo_1_ip_);

        label_servo_1_ip = new QLabel(formLayoutWidget);
        label_servo_1_ip->setObjectName(QStringLiteral("label_servo_1_ip"));
        label_servo_1_ip->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(0, QFormLayout::FieldRole, label_servo_1_ip);

        label_servo_1_alarm_ = new QLabel(formLayoutWidget);
        label_servo_1_alarm_->setObjectName(QStringLiteral("label_servo_1_alarm_"));
        label_servo_1_alarm_->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(3, QFormLayout::LabelRole, label_servo_1_alarm_);

        label_servo1_alarm = new QLabel(formLayoutWidget);
        label_servo1_alarm->setObjectName(QStringLiteral("label_servo1_alarm"));
        label_servo1_alarm->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(3, QFormLayout::FieldRole, label_servo1_alarm);

        label_servo_1_moving_ = new QLabel(formLayoutWidget);
        label_servo_1_moving_->setObjectName(QStringLiteral("label_servo_1_moving_"));
        label_servo_1_moving_->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(4, QFormLayout::LabelRole, label_servo_1_moving_);

        label_servo_1_moving = new QLabel(formLayoutWidget);
        label_servo_1_moving->setObjectName(QStringLiteral("label_servo_1_moving"));
        label_servo_1_moving->setAlignment(Qt::AlignCenter);

        formLayout_servo_1->setWidget(4, QFormLayout::FieldRole, label_servo_1_moving);

        tab_manager->addTab(tab_servo_control, QString());

        hboxLayout->addWidget(tab_manager);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 22));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);
        dock_status = new QDockWidget(MainWindowDesign);
        dock_status->setObjectName(QStringLiteral("dock_status"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dock_status->sizePolicy().hasHeightForWidth());
        dock_status->setSizePolicy(sizePolicy2);
        dock_status->setMinimumSize(QSize(325, 389));
        dock_status->setAllowedAreas(Qt::RightDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(dockWidgetContents_2);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line_edit_master = new QLineEdit(groupBox);
        line_edit_master->setObjectName(QStringLiteral("line_edit_master"));

        gridLayout->addWidget(line_edit_master, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        line_edit_host = new QLineEdit(groupBox);
        line_edit_host->setObjectName(QStringLiteral("line_edit_host"));

        gridLayout->addWidget(line_edit_host, 3, 0, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::StyledPanel);
        label_3->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        line_edit_topic = new QLineEdit(groupBox);
        line_edit_topic->setObjectName(QStringLiteral("line_edit_topic"));
        line_edit_topic->setEnabled(false);

        gridLayout->addWidget(line_edit_topic, 5, 0, 1, 2);

        checkbox_use_environment = new QCheckBox(groupBox);
        checkbox_use_environment->setObjectName(QStringLiteral("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_use_environment, 6, 0, 1, 2);

        checkbox_remember_settings = new QCheckBox(groupBox);
        checkbox_remember_settings->setObjectName(QStringLiteral("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkbox_remember_settings, 7, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(170, 21, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 8, 0, 1, 1);

        button_connect = new QPushButton(groupBox);
        button_connect->setObjectName(QStringLiteral("button_connect"));
        button_connect->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(button_connect, 8, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 233, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        verticalLayout->addWidget(frame);

        quit_button = new QPushButton(dockWidgetContents_2);
        quit_button->setObjectName(QStringLiteral("quit_button"));
        sizePolicy3.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(quit_button);

        dock_status->setWidget(dockWidgetContents_2);
        MainWindowDesign->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dock_status);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));
        QObject::connect(quit_button, SIGNAL(clicked()), MainWindowDesign, SLOT(close()));

        tab_manager->setCurrentIndex(0);
        pushButton_safety_arm->setDefault(false);
        pushButton_safety_disarm->setDefault(false);
        pushButton_safety_reset->setDefault(false);
        pushButton_safety_reinitialize->setDefault(false);
        pushButton_servos_motion->setDefault(false);
        pushButton_servos_standby->setDefault(false);
        pushButton_servos_alrm_reset->setDefault(false);
        pushButton_servos_reinitialize->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", Q_NULLPTR));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", Q_NULLPTR));
        groupBox_nodes->setTitle(QApplication::translate("MainWindowDesign", "Nodes", Q_NULLPTR));
        label_safety_node_state_->setText(QApplication::translate("MainWindowDesign", "Safety", Q_NULLPTR));
        label_safety_node_state->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_node_states_state_->setText(QApplication::translate("MainWindowDesign", "STATE", Q_NULLPTR));
        label_servos_node_state_->setText(QApplication::translate("MainWindowDesign", "Servo Control", Q_NULLPTR));
        label_servos_node_state->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_node_states_node_->setText(QApplication::translate("MainWindowDesign", "NODE ", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab), QApplication::translate("MainWindowDesign", "Overview", Q_NULLPTR));
        groupBox_safety_state_control->setTitle(QApplication::translate("MainWindowDesign", "State Control", Q_NULLPTR));
        pushButton_safety_arm->setText(QApplication::translate("MainWindowDesign", "ARM", Q_NULLPTR));
        pushButton_safety_disarm->setText(QApplication::translate("MainWindowDesign", "DISARM", Q_NULLPTR));
        pushButton_safety_reset->setText(QApplication::translate("MainWindowDesign", "SAFETY RESET", Q_NULLPTR));
        pushButton_safety_reinitialize->setText(QApplication::translate("MainWindowDesign", "REINITIALIZE", Q_NULLPTR));
        label_safety_node_state_t_->setText(QApplication::translate("MainWindowDesign", "Safety Node state:", Q_NULLPTR));
        label_safety_node_state_t->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_safety), QApplication::translate("MainWindowDesign", "Safety", Q_NULLPTR));
        groupBox_servo_state_control->setTitle(QApplication::translate("MainWindowDesign", "State Control", Q_NULLPTR));
        pushButton_servos_motion->setText(QApplication::translate("MainWindowDesign", "MOTION", Q_NULLPTR));
        pushButton_servos_standby->setText(QApplication::translate("MainWindowDesign", "STANDBY", Q_NULLPTR));
        pushButton_servos_alrm_reset->setText(QApplication::translate("MainWindowDesign", "ALARM RESET", Q_NULLPTR));
        pushButton_servos_reinitialize->setText(QApplication::translate("MainWindowDesign", "REINITIALIZE", Q_NULLPTR));
        label_servos_node_state_t_->setText(QApplication::translate("MainWindowDesign", "Servo Control Node state:", Q_NULLPTR));
        label_servos_node_state_t->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        groupBox_servo_1->setTitle(QApplication::translate("MainWindowDesign", "Servo 1 (Base)", Q_NULLPTR));
        label_servo_1_pos_->setText(QApplication::translate("MainWindowDesign", "position", Q_NULLPTR));
        label_servo_1_vel_->setText(QApplication::translate("MainWindowDesign", "velocity", Q_NULLPTR));
        label_servo_1_pos->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_servo_1_vel->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_servo_1_enabled_->setText(QApplication::translate("MainWindowDesign", "enabled", Q_NULLPTR));
        label_servo_1_enabled->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_servo_1_connected_->setText(QApplication::translate("MainWindowDesign", "connected", Q_NULLPTR));
        label_servo_1_connected->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_servo_1_ip_->setText(QApplication::translate("MainWindowDesign", "ip address", Q_NULLPTR));
        label_servo_1_ip->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_servo_1_alarm_->setText(QApplication::translate("MainWindowDesign", "in alarm", Q_NULLPTR));
        label_servo1_alarm->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        label_servo_1_moving_->setText(QApplication::translate("MainWindowDesign", "is moving", Q_NULLPTR));
        label_servo_1_moving->setText(QApplication::translate("MainWindowDesign", "n/a", Q_NULLPTR));
        tab_manager->setTabText(tab_manager->indexOf(tab_servo_control), QApplication::translate("MainWindowDesign", "Servo Control", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", Q_NULLPTR));
        dock_status->setWindowTitle(QApplication::translate("MainWindowDesign", "ROS Connection", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindowDesign", "Ros Master", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowDesign", "Ros Master Url", Q_NULLPTR));
        line_edit_master->setText(QApplication::translate("MainWindowDesign", "http://192.168.1.2:11311/", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowDesign", "Ros IP", Q_NULLPTR));
        line_edit_host->setText(QApplication::translate("MainWindowDesign", "192.168.1.67", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindowDesign", "Ros Hostname", Q_NULLPTR));
        line_edit_topic->setText(QApplication::translate("MainWindowDesign", "unused", Q_NULLPTR));
        checkbox_use_environment->setText(QApplication::translate("MainWindowDesign", "Use environment variables", Q_NULLPTR));
        checkbox_remember_settings->setText(QApplication::translate("MainWindowDesign", "Remember settings on startup", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        button_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        button_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        button_connect->setText(QApplication::translate("MainWindowDesign", "Connect", Q_NULLPTR));
        quit_button->setText(QApplication::translate("MainWindowDesign", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
