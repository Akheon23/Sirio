/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Sep 2 12:01:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      61,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      84,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     222,   11,   11,   11, 0x08,
     248,   11,   11,   11, 0x08,
     282,   11,   11,   11, 0x08,
     311,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0stop()\0on_process_clicked()\0"
    "on_options_clicked()\0playFinish()\0"
    "options()\0play_clean_signal()\0"
    "play_clean_segment()\0stopbutton()\0"
    "play_signal()\0play_segment()\0"
    "on_actionProcess_triggered()\0"
    "on_actionLoad_triggered()\0"
    "on_actionSave_triggered()\0"
    "on_actionSave_segment_triggered()\0"
    "on_actionOptions_triggered()\0"
    "on_actionQuit_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->stop(); break;
        case 1: _t->on_process_clicked(); break;
        case 2: _t->on_options_clicked(); break;
        case 3: _t->playFinish(); break;
        case 4: _t->options(); break;
        case 5: _t->play_clean_signal(); break;
        case 6: _t->play_clean_segment(); break;
        case 7: _t->stopbutton(); break;
        case 8: _t->play_signal(); break;
        case 9: _t->play_segment(); break;
        case 10: _t->on_actionProcess_triggered(); break;
        case 11: _t->on_actionLoad_triggered(); break;
        case 12: _t->on_actionSave_triggered(); break;
        case 13: _t->on_actionSave_segment_triggered(); break;
        case 14: _t->on_actionOptions_triggered(); break;
        case 15: _t->on_actionQuit_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
