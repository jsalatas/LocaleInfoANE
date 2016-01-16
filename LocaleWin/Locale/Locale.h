#ifndef LOCALE_H_
#define LOCALE_H_


#include "FlashRuntimeExtensions.h"

extern "C"
{
	__declspec(dllexport) void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
	__declspec(dllexport) void finalizer(void* extData);
}

#endif /* LOCALE_H_ */
