/****************************************************************************
** Meta object code from reading C++ file 'lettersegmentation.h'
**
** Created: Sun Dec 8 13:18:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LetterSegmentation/lettersegmentation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lettersegmentation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LetterSegmentation[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      44,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LetterSegmentation[] = {
    "LetterSegmentation\0\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

void LetterSegmentation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LetterSegmentation *_t = static_cast<LetterSegmentation *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LetterSegmentation::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LetterSegmentation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LetterSegmentation,
      qt_meta_data_LetterSegmentation, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LetterSegmentation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LetterSegmentation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LetterSegmentation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LetterSegmentation))
        return static_cast<void*>(const_cast< LetterSegmentation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LetterSegmentation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
