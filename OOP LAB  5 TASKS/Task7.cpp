#include <iostream>
#include <string>
using namespace std;
class ClassSchedule
{
private:
    string day;
    string time;
    string room;
    string instructor;

public:
    ClassSchedule(string d, string t, string r, string i)
        : day(d), time(t), room(r), instructor(i) {}
    void displaySchedule() const
    {
        cout << "Day: " << day << ", Time: " << time
             << ", Room: " << room << ", Instructor: " << instructor << endl;
    }
};

class Student
{
private:
    const int enrollmentID;
    string name;
    string program;
    int semester;

public:
    Student(int id, string n, string p, int s)
        : enrollmentID(id), name(n), program(p), semester(s) {}
    void displayStudent() const
    {
        cout << "ID: " << enrollmentID << ", Name: " << name
             << ", Program: " << program << ", Semester: " << semester << endl;
    }
};

class CourseSection
{
private:
    string sectionCode;
    string courseTitle;
    ClassSchedule schedule; // composition
    Student *students[3];   // aggregation (array of object pointers)
    static int totalSections;

public:
    CourseSection(string code, string title, ClassSchedule s)
        : sectionCode(code), courseTitle(title), schedule(s)
    {
        totalSections++;
    }
    void assignStudents(Student *s1, Student *s2, Student *s3)
    {
        students[0] = s1;
        students[1] = s2;
        students[2] = s3;
    }
    void displaySectionDetails() const
    {
        cout << "\nCourse Section: " << sectionCode
             << " (" << courseTitle << ")\n";
        schedule.displaySchedule();
        cout << "Enrolled Students:\n";
        for (int i = 0; i < 3; i++)
            students[i]->displayStudent();
    }
    static void displayTotalSections()
    {
        cout << "\nTotal course sections offered this semester: "
             << totalSections << endl;
    }
};

int CourseSection::totalSections = 0;

int main()
{
    Student s1(101, "Ali", "BSCS", 3);
    Student s2(102, "Sara", "BSCS", 3);
    Student s3(103, "Ahmed", "BSCS", 3);

    ClassSchedule sched("Mon-Wed", "9:00 AM - 10:30 AM", "Room-12", "Sir Khan");

    CourseSection section1("BCS-A", "Object-Oriented Programming", sched);
    section1.assignStudents(&s1, &s2, &s3);

    section1.displaySectionDetails();

    CourseSection::displayTotalSections();

    return 0;
}
