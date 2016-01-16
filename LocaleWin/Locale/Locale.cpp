// LocaleWin.cpp : Defines the exported functions for the DLL application.
//

#include "Locale.h"
#include <string>
#include <vector>
#include "GetLocaleInfo.h"
#include "FlashRuntimeExtensions.h"

extern "C" {

	FREObject getLocale(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
		FREObject result;

		std::wstring locale = getLocaleInfo();
		std::vector<uint8_t> localeVector(locale.begin(), locale.end());
		uint8_t *pVector = &localeVector[0];
		FRENewObjectFromUTF8(locale.size(), pVector, &result);

		return result;
	}

	FREObject isSupported(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]) {
		FREObject result;

		uint32_t isSupportedByWin = 1;
		FRENewObjectFromBool(isSupportedByWin, &result);

		return result;
	}

	void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions) {
		*numFunctions = 2;
		FRENamedFunction* func = (FRENamedFunction*)malloc(sizeof(FRENamedFunction) * (*numFunctions));

		func[0].name = (const uint8_t*) "isSupported";
		func[0].functionData = NULL;
		func[0].function = &isSupported;
		*functions = func;

		func[1].name = (const uint8_t*) "getLocale";
		func[1].functionData = NULL;
		func[1].function = &getLocale;
		*functions = func;
	}

	void contextFinalizer(FREContext ctx) {
		return;
	}

	void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
		*ctxInitializer = &contextInitializer;
		*ctxFinalizer = &contextFinalizer;
	}

	void finalizer(void* extData) {
		return;
	}

}

