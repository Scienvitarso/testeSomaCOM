// testeSomaCOM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <atlbase.h>
#include "SomaCOM_i.h"
#include "SomaCOM_i.c"
#include <iostream>

int main()
{
	HRESULT hr;

	hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	CComPtr<ISoma> pSoma;

	hr = pSoma.CoCreateInstance(CLSID_Soma);

	if (FAILED(hr)) {
		return 1;
	}

	hr = pSoma->setPrimeiroValor(2);

	hr = pSoma->setSegundoValor(2);

	int ret;

	hr = pSoma->getSoma(&ret);
	std::cout << ret << std::endl;
    return 0;
}

