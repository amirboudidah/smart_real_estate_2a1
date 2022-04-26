/****************************************************************************
** Meta object code from reading C++ file 'immobilier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../HomePad-Copie/immobilier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'immobilier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_immobilier_t {
    QByteArrayData data[12];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_immobilier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_immobilier_t qt_meta_stringdata_immobilier = {
    {
QT_MOC_LITERAL(0, 0, 10), // "immobilier"
QT_MOC_LITERAL(1, 11, 20), // "on_ajoutprod_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "on_suppprod_clicked"
QT_MOC_LITERAL(4, 53, 20), // "on_Modifprod_clicked"
QT_MOC_LITERAL(5, 74, 30), // "on_triprod_currentIndexChanged"
QT_MOC_LITERAL(6, 105, 5), // "index"
QT_MOC_LITERAL(7, 111, 18), // "on_pdfprod_clicked"
QT_MOC_LITERAL(8, 130, 25), // "on_inserimageprod_clicked"
QT_MOC_LITERAL(9, 156, 38), // "on_rechercheprod_cursorPositi..."
QT_MOC_LITERAL(10, 195, 4), // "arg1"
QT_MOC_LITERAL(11, 200, 4) // "arg2"

    },
    "immobilier\0on_ajoutprod_clicked\0\0"
    "on_suppprod_clicked\0on_Modifprod_clicked\0"
    "on_triprod_currentIndexChanged\0index\0"
    "on_pdfprod_clicked\0on_inserimageprod_clicked\0"
    "on_rechercheprod_cursorPositionChanged\0"
    "arg1\0arg2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_immobilier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    2,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,

       0        // eod
};

void immobilier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        immobilier *_t = static_cast<immobilier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajoutprod_clicked(); break;
        case 1: _t->on_suppprod_clicked(); break;
        case 2: _t->on_Modifprod_clicked(); break;
        case 3: _t->on_triprod_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pdfprod_clicked(); break;
        case 5: _t->on_inserimageprod_clicked(); break;
        case 6: _t->on_rechercheprod_cursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject immobilier::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_immobilier.data,
      qt_meta_data_immobilier,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *immobilier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *immobilier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_immobilier.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int immobilier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
