// StringCtrlSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	CMyStringEx strTest;
	strTest.SetString("멍멍이아들");
	cout << strTest << endl;

    return 0;
}

