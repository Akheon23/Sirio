/****************************************************************************
** Meta object code from reading C++ file 'option.h'
**
** Created: Tue Apr 9 14:40:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "option.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'option.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_option[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      32,    7,    7,    7, 0x08,
      56,    7,    7,    7, 0x08,
      81,    7,    7,    7, 0x08,
     106,    7,    7,    7, 0x08,
     131,    7,    7,    7, 0x08,
     156,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_option[] = {
    "option\0\0on_buttonBox_accepted()\0"
    "on_buttonBox_rejected()\0"
    "on_type1Button_clicked()\0"
    "on_type2Button_clicked()\0"
    "on_type3Button_clicked()\0"
    "on_type4Button_clicked()\0"
    "on_type5Button_clicked()\0"
};

void option::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        option *_t = static_cast<option *>(_o);
        switch (_id) {
        case 0: _t->on_buttonBox_accepted(); break;
        case 1: _t->on_buttonBox_rejected(); break;
        case 2: _t->on_type1Button_clicked(); break;
        case 3: _t->on_type2Button_clicked(); break;
        case 4: _t->on_type3Button_clicked(); break;
        case 5: _t->on_type4Button_clicked(); break;
        case 6: _t->on_type5Button_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData option::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject option::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_option,
      qt_meta_data_option, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &option::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *option::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *option::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_option))
        return static_cast<void*>(const_cast< option*>(this));
    return QDialog::qt_metacast(_clname);
}

int option::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
