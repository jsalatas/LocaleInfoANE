/**
* Copyright (C) 2015 John Salatas (jsalatas@gmail.com)
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License v3 (LGPL-3)
* as published by the Free Software Foundation.
*
*/

#include <SDKDDKVer.h>
#include <string>
#include <Windows.h>
#include <iostream>
#include <sstream>

std::wstring getLocaleInfo() {
	WCHAR szISOLang[5] = { 0 };
	WCHAR szISOCountry[5] = { 0 };

	std::wstringstream wstr;

	::GetLocaleInfo(LOCALE_USER_DEFAULT,
		LOCALE_SISO639LANGNAME,
		szISOLang,
		sizeof(szISOLang) / sizeof(WCHAR));

	::GetLocaleInfo(LOCALE_USER_DEFAULT,
		LOCALE_SISO3166CTRYNAME,
		szISOCountry,
		sizeof(szISOCountry) / sizeof(WCHAR));

	wstr << szISOLang << "-" << szISOCountry;

	return wstr.str();
}