/****************************************************************************
** Meta object code from reading C++ file 'tile.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/tile.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tile.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN4TileE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN4TileE = QtMocHelpers::stringData(
    "Tile",
    "typeChanged",
    "",
    "valueChanged",
    "faceUpChanged",
    "rowChanged",
    "columnChanged",
    "selectedChanged",
    "openChanged",
    "layerChanged",
    "type",
    "value",
    "faceUp",
    "row",
    "column",
    "selected",
    "open",
    "layer"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN4TileE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       8,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    9 /* Public */,
       3,    0,   63,    2, 0x06,   10 /* Public */,
       4,    0,   64,    2, 0x06,   11 /* Public */,
       5,    0,   65,    2, 0x06,   12 /* Public */,
       6,    0,   66,    2, 0x06,   13 /* Public */,
       7,    0,   67,    2, 0x06,   14 /* Public */,
       8,    0,   68,    2, 0x06,   15 /* Public */,
       9,    0,   69,    2, 0x06,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags, notifyId, revision
      10, QMetaType::QString, 0x00015103, uint(0), 0,
      11, QMetaType::Int, 0x00015103, uint(1), 0,
      12, QMetaType::Bool, 0x00015103, uint(2), 0,
      13, QMetaType::Int, 0x00015103, uint(3), 0,
      14, QMetaType::Int, 0x00015103, uint(4), 0,
      15, QMetaType::Bool, 0x00015103, uint(5), 0,
      16, QMetaType::Bool, 0x00015103, uint(6), 0,
      17, QMetaType::Int, 0x00015103, uint(7), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Tile::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN4TileE.offsetsAndSizes,
    qt_meta_data_ZN4TileE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN4TileE_t,
        // property 'type'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'value'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'faceUp'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'row'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'column'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'selected'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'open'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'layer'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Tile, std::true_type>,
        // method 'typeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'faceUpChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rowChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'columnChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'layerChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Tile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Tile *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->typeChanged(); break;
        case 1: _t->valueChanged(); break;
        case 2: _t->faceUpChanged(); break;
        case 3: _t->rowChanged(); break;
        case 4: _t->columnChanged(); break;
        case 5: _t->selectedChanged(); break;
        case 6: _t->openChanged(); break;
        case 7: _t->layerChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::typeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::valueChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::faceUpChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::rowChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::columnChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::selectedChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::openChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (Tile::*)();
            if (_q_method_type _q_method = &Tile::layerChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->type(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->value(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->faceUp(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->row(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->column(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->selected(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->open(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->layer(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setType(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setValue(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setFaceUp(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setRow(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setColumn(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setSelected(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setOpen(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setLayer(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Tile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN4TileE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Tile::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tile::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Tile::faceUpChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Tile::rowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Tile::columnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Tile::selectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Tile::openChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Tile::layerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
