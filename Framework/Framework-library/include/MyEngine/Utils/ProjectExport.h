#ifndef PROJECT_EXPORT_H
#define PROJECT_EXPORT_H

#ifdef LIBRARY_EXPORTS
#define MYENGINEAPI __declspec(dllexport)
#else
#define MYENGINEAPI __declspec(dllimport)
#endif

#endif // !PROJECT_EXPORT_H