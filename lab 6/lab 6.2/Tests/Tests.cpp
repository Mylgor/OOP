// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\lab 6.2\Student.h"

BOOST_AUTO_TEST_CASE(MainWorkClass)
{
	BOOST_CHECK_NO_THROW(CStudent stud("aaa", "bbb", "ccc", 14));

	CStudent stud1("Vladimer", "Vasenev", "Vladimirovich", 21);
	BOOST_CHECK(stud1.GetAge() == 21);
	BOOST_CHECK(stud1.GetName() == "Vladimer");
	BOOST_CHECK(stud1.GetSurname() == "Vasenev");
	BOOST_CHECK(stud1.GetPatronymic() == "Vladimirovich");

	CStudent stud2("Dima", "WaitWait", "Vasuykov", 20);
	BOOST_CHECK(stud2.GetAge() == 20);
	BOOST_CHECK(stud2.GetName() == "Dima");
	BOOST_CHECK(stud2.GetSurname() == "WaitWait");
	BOOST_CHECK(stud2.GetPatronymic() == "Vasuykov");

	stud2.Rename("Dima", "Vasuykov", "Valentinovich");
	BOOST_CHECK(stud2.GetName() == "Dima");
	BOOST_CHECK(stud2.GetSurname() == "Vasuykov");
	BOOST_CHECK(stud2.GetPatronymic() == "Valentinovich");

	stud2.SetAge(21);
	BOOST_CHECK(stud1.GetAge() == 21);
}

BOOST_AUTO_TEST_CASE(Exclusion)
{
	// Create
	BOOST_CHECK_NO_THROW(CStudent stud("Dima", "Vasuykov", "Valentinovich", 20));
	BOOST_CHECK_NO_THROW(CStudent stud("Dima", "Vasuykov", "", 20));
	BOOST_CHECK_THROW(CStudent stud("", "Vasuykov", "Valentinovich", 20), std::invalid_argument);
	BOOST_CHECK_THROW(CStudent stud("Dima", "", "Valentinovich", 20), std::invalid_argument);
	BOOST_CHECK_THROW(CStudent stud("D8i1m2a", "Vasuykov", "Valentinovich", 20), std::invalid_argument);
	BOOST_CHECK_THROW(CStudent stud("Dima", "Vasuykov", "Val2123123entinovich", 20), std::invalid_argument);

	//Rename
	CStudent stud("Dima", "Vasuykov", "Valentinovich", 20);
	BOOST_CHECK_THROW(stud.Rename("", "Vasuykov", "Valentinovich"), std::invalid_argument);
	BOOST_CHECK_THROW(stud.Rename("Dima", "", "Valentinovich"), std::invalid_argument);
	BOOST_CHECK_NO_THROW(stud.Rename("Dima", "Vasuykov", ""));
	BOOST_CHECK(stud.GetName() == "Dima");
	BOOST_CHECK(stud.GetSurname() == "Vasuykov");
	BOOST_CHECK(stud.GetPatronymic() == "");

	//Set age
	BOOST_CHECK_THROW(stud.SetAge(18), std::domain_error);
	BOOST_CHECK_THROW(stud.SetAge(10), std::out_of_range);
	BOOST_CHECK_THROW(stud.SetAge(70), std::out_of_range);
	BOOST_CHECK(stud.GetAge() == 20);
}