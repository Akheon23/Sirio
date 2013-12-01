#ifndef SIMAGE_GLOBAL_H
#define SIMAGE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMAGE_LIBRARY)
#  define SIMAGESHARED_EXPORT Q_DECL_EXPORT
#else
#  define SIMAGESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SIMAGE_GLOBAL_H
