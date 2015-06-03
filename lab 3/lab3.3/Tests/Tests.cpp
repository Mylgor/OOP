// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\lab 3.3\CFile.h"

BOOST_AUTO_TEST_CASE(OpenFileAndClose)
{
	CCFile file;
	BOOST_CHECK_EQUAL(file.IsOpened(), false);
	BOOST_CHECK_EQUAL(file.Open("sadfdsf.txt", "r"), false);
	BOOST_CHECK_EQUAL(file.Open("input1.txt", "r"), true);
	BOOST_CHECK_EQUAL(file.IsOpened(), true);
	file.Close();
	BOOST_CHECK_EQUAL(file.IsOpened(), false);
}

BOOST_AUTO_TEST_CASE(Test1)
{
	CCFile file;
	BOOST_CHECK_EQUAL(file.Open("input1.txt", "r"), true);
	char symbol;
	BOOST_CHECK_EQUAL(file.GetPosition(), 0);
	BOOST_CHECK(file.GetLenght() == 3);
	BOOST_CHECK((symbol = file.GetChar()) == 'a');
	BOOST_CHECK(file.GetPosition() == 1);
	BOOST_CHECK_EQUAL(file.Open("input1.txt", "r"), true);
	char *str = new char[3];
	BOOST_CHECK(file.Read(str) > 0);
	BOOST_CHECK(strcmp(str, "abc") > 0);
	file.Close();
	delete[] str;
	str = nullptr;

	BOOST_CHECK_EQUAL(file.Open("input2.txt", "w"), true);
	BOOST_CHECK(file.Write("QWERTY") == 6);
	file.Close();
}

BOOST_AUTO_TEST_CASE(Test2)
{
	CCFile file;
	BOOST_CHECK_EQUAL(file.Open("input2.txt", "w"), true);
	int symbol;
	BOOST_CHECK_EQUAL(file.PutChar('a'), true);
	BOOST_CHECK_EQUAL(file.PutChar('b'), true);
	BOOST_CHECK_EQUAL(file.PutChar('c'), true);
	file.Close();
	BOOST_CHECK_EQUAL(file.Open("input2.txt", "r"), true);
	BOOST_CHECK((symbol = file.GetChar()) == 'a');
	BOOST_CHECK((symbol = file.GetChar()) == 'b');
	BOOST_CHECK((symbol = file.GetChar()) == 'c');
	file.Close();
}