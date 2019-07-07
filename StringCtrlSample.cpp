// StringCtrlSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CMyString.h"

void TestFunc(const CMyString& param) {
	cout << param[0] << endl;
	cout << param[param.GetLength() - 1] << endl;
}

int main()
{
	CMyString strLeft("Test"), strRight("String");

	if (strLeft == strRight)
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
	strLeft = CMyString("String");

	if (strLeft != strRight)
		cout << "Different" << endl;
	else
		cout << "Same" << endl;


    return 0;
}

