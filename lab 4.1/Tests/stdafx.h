// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <math.h>
using namespace std;

#define BOOST_TEST_MODULE TheApplicationTestModule
#define BOOST_TEST_INCLUDED
#pragma warning(disable:4702)
#include <boost\test\unit_test.hpp>
// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
double GetPi();