#pragma once
class CMyString
{
public:
	CMyString();
	explicit CMyString(const char*); //explicit 키워드는 헤더에 선언만 해주면 된다. 정의부분에는 쓰지 않는다.
	CMyString(const CMyString &rhs);
	CMyString(CMyString &&rhs);

	~CMyString();
private:
	char* m_pszData; //문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	int m_nLength; //저장된 문자열의 길이
public:
	int SetString(const char*);
	int GetLength() const;
	int Apeend(const char* pszParam);
	const char* GetString() const;
	void Release();
	operator char*() const;
	int operator==(const CMyString &rhs);
	int operator!=(const CMyString &rhs);
	char& operator[](int nIndex);
	char operator[](int nIndex) const;
	CMyString & operator=(const CMyString & rhs);
	CMyString operator+(const CMyString &rhs);
	CMyString& operator+=(const CMyString &rhs);
};


