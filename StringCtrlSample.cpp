// StringCtrlSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CMyString.h"

void TestFunc(const CMyString& param) {
	cout << param << endl;
}

int main()
{
	CMyString strData("Hello");
	::TestFunc("world");
	::TestFunc(strData);
	::TestFunc(CMyString("World"));

    return 0;
}

