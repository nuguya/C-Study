#pragma once
#include "CMyString.h"
class CMyStringEx :
	public CMyString
{
public:
	CMyStringEx();
	CMyStringEx(const char* nParam);
	~CMyStringEx();
	using CMyString::CMyString;
public:
	int Find(const char* pszParam);
	int SetString(const char* pszParam);
};

