// StringCtrlSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CMyString.h"

void TestFunc(const CMyString& param) {
	cout << param.GetString() << endl;
}

int main()
{
	CMyString strData,b;
	strData.SetString("Hello");
	b = strData;
	TestFunc(b);
    return 0;
}

