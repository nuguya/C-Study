#include "stdafx.h"
#include "CMyString.h"


CMyString::CMyString() :m_pszData(NULL),m_nLength(0)
{
}

CMyString::CMyString(const CMyString &rhs) : m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString& CMyString::operator=(const CMyString &rhs)
{
	this->m_nLength = rhs.m_nLength;
	this->SetString(rhs.GetString());

	return *this;
}


CMyString::~CMyString()
{
	Release();
}


int CMyString::SetString(const char* pszParam)
{
	Release();
	if (pszParam == NULL) {
		return 0;
	}
	m_nLength=strlen(pszParam);
	if (m_nLength == 0) {
		return 0;
	}
	CMyString::m_pszData = new char[m_nLength+1];
	strcpy_s(m_pszData,sizeof(char)*(m_nLength+1),pszParam);
	return m_nLength;
}


const char* CMyString::GetString() const //상수형 메서드로 선언 읽기는 가능하지만 쓸 수 없음.
{
	// TODO: 여기에 구현 코드 추가
	return m_pszData;
}


void CMyString::Release()
{
	if(m_pszData!=NULL)
		delete[] m_pszData;
	m_pszData = NULL;
	m_nLength = 0;
}
