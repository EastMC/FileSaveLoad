#ifndef H_HEADER
#define H_HEADER
#include <string>
#include <vector>
using namespace std;

struct Student
{
	string Name;
	string GroupId;
	vector<unsigned> Ratings;
	vector<string> Subjects;
};

struct Group
{
	string Id;
	vector<Student> Students;
};

//прототипы
void SortByName(vector<Student>&);
void SortByRating(vector<Student>&);
size_t CountTwoness(const vector<Student>&);
size_t CountExcellent(const vector<Student>&);
vector<Student> VectorMathExcellent(const vector<Student>&);
vector<string> GroupsId(const vector<Student>&);
vector<Group> Groups(const vector<Student>&);

#endif