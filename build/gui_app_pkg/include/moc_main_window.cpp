/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/gui_app_pkg/include/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qtros__MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[555];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtros__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtros__MainWindow_t qt_meta_stringdata_qtros__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "qtros::MainWindow"
QT_MOC_LITERAL(1, 18, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 25), // "on_button_connect_clicked"
QT_MOC_LITERAL(4, 70, 5), // "check"
QT_MOC_LITERAL(5, 76, 40), // "on_checkbox_use_environment_s..."
QT_MOC_LITERAL(6, 117, 5), // "state"
QT_MOC_LITERAL(7, 123, 32), // "on_pushButton_safety_arm_clicked"
QT_MOC_LITERAL(8, 156, 35), // "on_pushButton_safety_disarm_c..."
QT_MOC_LITERAL(9, 192, 37), // "on_pushButton_safety_shutdown..."
QT_MOC_LITERAL(10, 230, 34), // "on_pushButton_safety_reset_cl..."
QT_MOC_LITERAL(11, 265, 41), // "on_pushButton_safety_reinitia..."
QT_MOC_LITERAL(12, 307, 35), // "on_pushButton_servos_motion_c..."
QT_MOC_LITERAL(13, 343, 36), // "on_pushButton_servos_standby_..."
QT_MOC_LITERAL(14, 380, 39), // "on_pushButton_servos_alrm_res..."
QT_MOC_LITERAL(15, 420, 41), // "on_pushButton_servos_reinitia..."
QT_MOC_LITERAL(16, 462, 37), // "on_pushButton_servos_shutdown..."
QT_MOC_LITERAL(17, 500, 24), // "ShowServosNodeServosData"
QT_MOC_LITERAL(18, 525, 29) // "custom_msg_pkg::EziServosData"

    },
    "qtros::MainWindow\0on_actionAbout_triggered\0"
    "\0on_button_connect_clicked\0check\0"
    "on_checkbox_use_environment_stateChanged\0"
    "state\0on_pushButton_safety_arm_clicked\0"
    "on_pushButton_safety_disarm_clicked\0"
    "on_pushButton_safety_shutdown_clicked\0"
    "on_pushButton_safety_reset_clicked\0"
    "on_pushButton_safety_reinitialize_clicked\0"
    "on_pushButton_servos_motion_clicked\0"
    "on_pushButton_servos_standby_clicked\0"
    "on_pushButton_servos_alrm_reset_clicked\0"
    "on_pushButton_servos_reinitialize_clicked\0"
    "on_pushButton_servos_shutdown_clicked\0"
    "ShowServosNodeServosData\0"
    "custom_msg_pkg::EziServosData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtros__MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    1,   85,    2, 0x0a /* Public */,
       5,    1,   88,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,    2,

       0        // eod
};

void qtros::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAbout_triggered(); break;
        case 1: _t->on_button_connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_checkbox_use_environment_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_safety_arm_clicked(); break;
        case 4: _t->on_pushButton_safety_disarm_clicked(); break;
        case 5: _t->on_pushButton_safety_shutdown_clicked(); break;
        case 6: _t->on_pushButton_safety_reset_clicked(); break;
        case 7: _t->on_pushButton_safety_reinitialize_clicked(); break;
        case 8: _t->on_pushButton_servos_motion_clicked(); break;
        case 9: _t->on_pushButton_servos_standby_clicked(); break;
        case 10: _t->on_pushButton_servos_alrm_reset_clicked(); break;
        case 11: _t->on_pushButton_servos_reinitialize_clicked(); break;
        case 12: _t->on_pushButton_servos_shutdown_clicked(); break;
        case 13: _t->ShowServosNodeServosData((*reinterpret_cast< custom_msg_pkg::EziServosData(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject qtros::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qtros__MainWindow.data,
      qt_meta_data_qtros__MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qtros::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtros::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtros__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int qtros::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
