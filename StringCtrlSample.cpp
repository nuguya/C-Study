// StringCtrlSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CMyStringEx.h"

int main()
{
	CMyStringEx strLeft("Hello"), strRight("World");
	cout << strLeft + strRight << endl;

    return 0;
}

