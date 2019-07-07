#include "stdafx.h"
#include "CMyString.h"


CMyString::CMyString() :m_pszData(NULL),m_nLength(0)
{
}

CMyString::CMyString(const char *param): m_pszData(NULL), m_nLength(0)
{
	this->SetString(param);
}

CMyString::CMyString(const CMyString &rhs) : m_pszData(NULL), m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString::CMyString(CMyString &&rhs) : m_pszData(NULL), m_nLength(0)
{
	cout << "이동 생성자 호출" << endl;
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}

CMyString::operator char*() const
{
	return m_pszData;
}

int CMyString::operator==(const CMyString & rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;
	return 0;
}

int CMyString::operator!=(const CMyString & rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;
	return 1;
}

char & CMyString::operator[](int nIndex)
{
	if (nIndex > m_nLength || nIndex < 0) {
		cout << "배열의 범위를 벗어납니다." << endl;
		char err = '0';
		return err;
	}
	return m_pszData[nIndex];
}

char CMyString::operator[](int nIndex) const
{
	cout << "상수형 참조" << endl;
	if (nIndex > m_nLength || nIndex < 0) {
		cout << "배열의 범위를 벗어납니다." << endl;
		return '0';
	}
	return m_pszData[nIndex];
}


CMyString& CMyString::operator=(const CMyString &rhs)
{
	this->m_nLength = rhs.m_nLength;
	this->SetString(rhs.GetString());

	return *this;
}

CMyString CMyString::operator+(const CMyString & rhs)
{
	CMyString result;
	result = *this;
	result.Apeend(rhs.m_pszData);

	return result;
}

CMyString & CMyString::operator+=(const CMyString & rhs)
{
	this->Apeend(rhs.m_pszData);

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

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Apeend(const char* pszParam)
{
	if(pszParam==NULL)
		return 0;
	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	if (m_pszData == NULL) {
		SetString(pszParam);

		return m_nLength;
	}

	int nLenCur = m_nLength;

	char* pszResult = new char[nLenCur + nLenParam + 1];

	strcpy_s(pszResult, sizeof(char)*(nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char)*nLenCur), sizeof(char)*(nLenParam + 1), pszParam);

	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}


void CMyString::Release()
{
	if(m_pszData!=NULL)
		delete[] m_pszData;
	m_pszData = NULL;
	m_nLength = 0;
}
