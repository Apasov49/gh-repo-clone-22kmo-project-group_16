/****************************************************************************
** Meta object code from reading C++ file 'depositwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../frontend/depositwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'depositwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DepositWindow_t {
    QByteArrayData data[18];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DepositWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DepositWindow_t qt_meta_stringdata_DepositWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DepositWindow"
QT_MOC_LITERAL(1, 14, 11), // "DepositSlot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 42, 5), // "Reply"
QT_MOC_LITERAL(5, 48, 17), // "UpdateBalanceSlot"
QT_MOC_LITERAL(6, 66, 19), // "PostTransactionSlot"
QT_MOC_LITERAL(7, 86, 17), // "on_Btn_Ok_clicked"
QT_MOC_LITERAL(8, 104, 19), // "on_Btn_Exit_clicked"
QT_MOC_LITERAL(9, 124, 18), // "on_Btn_20e_clicked"
QT_MOC_LITERAL(10, 143, 18), // "on_Btn_40e_clicked"
QT_MOC_LITERAL(11, 162, 18), // "on_Btn_60e_clicked"
QT_MOC_LITERAL(12, 181, 18), // "on_Btn_90e_clicked"
QT_MOC_LITERAL(13, 200, 19), // "on_Btn_120e_clicked"
QT_MOC_LITERAL(14, 220, 19), // "on_Btn_140e_clicked"
QT_MOC_LITERAL(15, 240, 19), // "on_Btn_160e_clicked"
QT_MOC_LITERAL(16, 260, 19), // "on_Btn_180e_clicked"
QT_MOC_LITERAL(17, 280, 13) // "HandleTimeOut"

    },
    "DepositWindow\0DepositSlot\0\0QNetworkReply*\0"
    "Reply\0UpdateBalanceSlot\0PostTransactionSlot\0"
    "on_Btn_Ok_clicked\0on_Btn_Exit_clicked\0"
    "on_Btn_20e_clicked\0on_Btn_40e_clicked\0"
    "on_Btn_60e_clicked\0on_Btn_90e_clicked\0"
    "on_Btn_120e_clicked\0on_Btn_140e_clicked\0"
    "on_Btn_160e_clicked\0on_Btn_180e_clicked\0"
    "HandleTimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DepositWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       6,    1,   90,    2, 0x08 /* Private */,
       7,    0,   93,    2, 0x08 /* Private */,
       8,    0,   94,    2, 0x08 /* Private */,
       9,    0,   95,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
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
    QMetaType::Void,

       0        // eod
};

void DepositWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DepositWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DepositSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: _t->UpdateBalanceSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->PostTransactionSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->on_Btn_Ok_clicked(); break;
        case 4: _t->on_Btn_Exit_clicked(); break;
        case 5: _t->on_Btn_20e_clicked(); break;
        case 6: _t->on_Btn_40e_clicked(); break;
        case 7: _t->on_Btn_60e_clicked(); break;
        case 8: _t->on_Btn_90e_clicked(); break;
        case 9: _t->on_Btn_120e_clicked(); break;
        case 10: _t->on_Btn_140e_clicked(); break;
        case 11: _t->on_Btn_160e_clicked(); break;
        case 12: _t->on_Btn_180e_clicked(); break;
        case 13: _t->HandleTimeOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DepositWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DepositWindow.data,
    qt_meta_data_DepositWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DepositWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DepositWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DepositWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DepositWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
