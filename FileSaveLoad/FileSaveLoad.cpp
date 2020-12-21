// FileSaveLoad.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

struct Student
{
	string Name;
	string GroupId;
	vector<unsigned> Ratings;
	vector<string> Subjects;
};

//прототипы
void SortByName(vector<Student>&);
void SortByRating(vector<Student>&);
size_t CountTwoness(const vector<Student>&);


//компараторы
bool greaterString(Student s1, Student s2)
{
	return s1.Name.compare(s2.Name) < 0;
}

bool greaterAverageRating(Student s1, Student s2)
{
	double average1 = 0;
	int i;
	for (i = 0; i < s1.Ratings.size(); i++)
	{
		average1 += s1.Ratings[i];
	}
	average1 /= i;

	double average2 = 0;
	for (i = 0; i < s2.Ratings.size(); i++)
	{
		average2 += s2.Ratings[i];
	}
	average2 /= i;

	return average1>average2;
}

bool hasRatingsBadMark(unsigned rating)
{
	return rating <= 2;
}

bool hasStudentBadMark(Student s1)
{	
	auto p = find_if(s1.Ratings.begin(), s1.Ratings.end(), hasRatingsBadMark);	
	return p!=s1.Ratings.end();
}



//функции по заданию
void SortByName(vector<Student> &vec)
{
	sort(vec.begin(), vec.end(), greaterString);
}

void SortByRating(vector<Student> &vec)
{
	sort(vec.begin(), vec.end(), greaterAverageRating);
}

size_t CountTwoness(const vector<Student> &vec)
{	
	return count_if(vec.begin(), vec.end(), hasStudentBadMark);
}


//основа
int main()
{
	vector<Student> students;

	vector<unsigned> marks1 = { 4,3,3,4 };
	vector<unsigned> marks2 = { 4,4,4,4 };
	vector<unsigned> marks3 = { 4,5,5,5 };

	Student s1;
	s1.Name = "AIvan";
	s1.GroupId = "IU813";
	s1.Ratings = marks1;
	Student s2;
	s2.Name = "Ivan2";
	s2.GroupId = "IU8132";
	s2.Ratings = marks2;
	Student s3;
	s3.Name = "BIvan2";
	s3.GroupId = "IU8132";
	s3.Ratings = marks3;


	students.push_back(s1);
	students.push_back(s2);
	students.push_back(s3);

	for (int i = 0; i < students.size(); i++)
	{
		cout << students[i].Name << " ";
	}
	cout << endl;

	//SortByName(students);
	//SortByRating(students);
	cout << "Bad marks students: " << CountTwoness(students) << endl;

	for (int i = 0; i < students.size(); i++)
	{
		cout << students[i].Name << " ";
	}


	getch();


	return 0;
}

