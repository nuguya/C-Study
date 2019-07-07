#pragma once
class CMyString
{
public:
	CMyString();
	explicit CMyString(const char*); //explicit Ű����� ����� ���� ���ָ� �ȴ�. ���Ǻκп��� ���� �ʴ´�.
	CMyString(const CMyString &rhs);
	CMyString(CMyString &&rhs);

	~CMyString();
private:
	char* m_pszData; //���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	int m_nLength; //����� ���ڿ��� ����
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


