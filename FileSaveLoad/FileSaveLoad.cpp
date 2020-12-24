// FileSaveLoad.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Header.h"
#include <algorithm>
#include <iostream>
#include <conio.h>
using namespace std;


//предикаты-компараторы
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

	return average1 > average2;
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

bool hasRatingsExcellentMarks(unsigned rating)
{
	return rating >= 5;
}

bool hasStudentExcellentMarks(Student s1)
{	
	return count_if(s1.Ratings.begin(), s1.Ratings.end(), hasRatingsExcellentMarks) == s1.Ratings.size();
}

bool hasStudentExcellentMathMark(Student s1)
{
	for (int i = 0; i < s1.Ratings.size() && i < s1.Subjects.size(); i++)
	{
		if (s1.Ratings[i] >= 5 && s1.Subjects[i].compare("Math") == 0)
			return true;
	}
	return false;
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

size_t CountExcellent(const vector<Student> &vec)
{
	return count_if(vec.begin(), vec.end(), hasStudentExcellentMarks);
}

vector<Student> VectorMathExcellent(const vector<Student> &vec)
{
	vector<Student> excellentMathStudents(count_if(vec.begin(), vec.end(), hasStudentExcellentMathMark));
	copy_if(vec.begin(), vec.end(), excellentMathStudents.begin(), hasStudentExcellentMathMark);
	return excellentMathStudents;
}

vector<string> GroupsId(const vector<Student> &vec)
{
	vector<string> allStudentGroups;
	for (int i = 0; i < vec.size(); i++)
	{
		allStudentGroups.push_back(vec[i].GroupId);
	}	

	auto p = unique(allStudentGroups.begin(), allStudentGroups.end());
	vector<string> result;
	for (vector<string>::iterator v = allStudentGroups.begin(); v != p; v++)
		result.push_back(*v);
	return result;

}

vector<Group> Groups(const vector<Student> &vec)
{
	vector<Group> result;
	vector<string> groupNames = GroupsId(vec);
	for (int i = 0; i < groupNames.size(); i++)
	{
		Group newGroup;
		vector<Student> studentsInOneGroup;
		newGroup.Id = groupNames[i];
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j].GroupId.compare(groupNames[i]) == 0) studentsInOneGroup.push_back(vec[j]);
		}
		newGroup.Students = studentsInOneGroup;
		result.push_back(newGroup);
	}
	return result;
}




//всякие проверки, отладки, по заданию не нужно
int main()
{
	vector<Student> students;

	vector<unsigned> marks1 = { 3,5,5,5 };
	vector<string> subjects = { "Math","Russian","English","Physics" };
	vector<unsigned> marks2 = { 5,4,4,4 };
	vector<unsigned> marks3 = { 5,5,5,5 };

	Student s1;
	s1.Name = "Misyura M.S.";
	s1.GroupId = "IU8_13";
	s1.Ratings = marks1;
	s1.Subjects = subjects;
	Student s2;
	s2.Name = "Ivanov K.K.";
	s2.GroupId = "IU8_15";
	s2.Ratings = marks2;
	s2.Subjects = subjects;
	Student s3;
	s3.Name = "Sidorov G.G.";
	s3.GroupId = "IU8_23";
	s3.Ratings = marks3;
	s3.Subjects = subjects;


	students.push_back(s1);
	students.push_back(s2);
	students.push_back(s3);

	//for (int i = 0; i < students.size(); i++)
	//{
	//	cout << students[i].Name << " ";
	//}
	//cout << endl;

	//SortByName(students);
	//SortByRating(students);
	//cout << "Bad marks students: " << CountTwoness(students) << endl;
	//cout << "Students with excellent marks: " << CountExcellent(students) << endl;
	//vector<Student> v = VectorMathExcellent(students);
	//vector<string> v = GroupsId(students);
	vector<Group> v = Groups(students);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].Id << endl;
		for (int j = 0; j < v[i].Students.size(); j++)
			cout << "\t"<< v[i].Students[j].Name << endl;
	}
	
	//for (int i = 0; i < students.size(); i++)
	//{
	//	cout << students[i].Name << " ";
	//}

	getch();

	return 0;
}

