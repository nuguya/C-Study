#pragma once
#include "CMyString.h"
class CMyStringEx :
	public CMyString
{
public:
	CMyStringEx();
	~CMyStringEx();
	using CMyString::CMyString;
public:
	int Find(const char* pszParam);
	void OnSetString(char *, int);
};

