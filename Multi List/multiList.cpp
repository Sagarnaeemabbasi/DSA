#include <iostream>
using namespace std;
struct Course
{
    int courseNo;
    struct Student *firstStudent;
    struct Course *next;
} *courseHead = NULL;

struct Student
{
    int id;
    int courseNo;
    struct Student *next;
} *studentHead = NULL;

struct Course *findCourseByNumber(int courseNo)
{
    struct Course *currentCourse = courseHead;
    while (currentCourse != NULL)
    {
        if (currentCourse->courseNo == courseNo)
        {
            return currentCourse;
        }
        currentCourse = currentCourse->next;
    }
    return NULL; // Course not found
}

void insertCourse()
{
    if (courseHead == NULL)
    {
        struct Course *temp = new Course();
        temp->next = NULL;
        temp->firstStudent = NULL;
        cout << "Enter Course No : " << endl;
        cin >> temp->courseNo;
        courseHead = temp;
    }
    else
    {
        cout << "Else of insert course" << endl;
        struct Course *curr = courseHead;
        struct Course *temp = new Course();
        temp->next = NULL;
        temp->firstStudent = NULL;
        cout << "Enter Course No: " << endl;
        cin >> temp->courseNo;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void insertStudent()

{
    int inputCourseNo;
    int searchFlag = 0;
    cout << "Enter Course No: " << endl;
    cin >> inputCourseNo;

    struct Course *temp1 = courseHead;
    while (temp1 != NULL)
    {
        if (temp1->courseNo == inputCourseNo)
        {
            searchFlag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if (searchFlag == 1)
    {
        if (temp1->firstStudent == NULL)
        {
            struct Student *temp = new Student();
            temp->next = NULL;
            cout << "Enter Student Id : " << endl;
            cin >> temp->id;
            temp->courseNo = inputCourseNo;
            temp1->firstStudent = temp;
        }
        else
        {
            struct Student *curr = temp1->firstStudent;
            struct Student *temp = new Student();
            temp->next = NULL;
            temp->courseNo = inputCourseNo;
            cout << "Enter Student Id: " << endl;
            cin >> temp->id;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    else
    {
        cout << "Course is not available this semester" << endl;
    }
}

void print()
{
    struct Course *temp = courseHead;
    while (temp != NULL)
    {
        cout << "Course No : " << temp->courseNo << endl
             << "Students Enrolled In This Course  " << endl;
        struct Student *tempStudent = temp->firstStudent;
        while (tempStudent != NULL)
        {
            cout << "Student Id : " << tempStudent->id << endl;
            tempStudent = tempStudent->next;
        }
        temp = temp->next;
    }
}

void deleteAllStudents()
{

    // 1. create a temp node
    struct Student *temp = new Student();
    int inputCourseNo;
    int searchFlag = 0;
    cout << "Enter Course No: " << endl;
    cin >> inputCourseNo;

    struct Course *temp1 = courseHead;
    while (temp1 != NULL)
    {
        if (temp1->courseNo == inputCourseNo)
        {
            searchFlag = 1;
            break;
        }
        temp1 = temp1->next;
    }
    if (searchFlag == 1)
    {
        // temp = temp1->firstStudent;
        while (temp1->firstStudent = NULL)
        {
            temp = temp1->firstStudent;
            temp1->firstStudent = temp1->firstStudent->next;
            free(temp);
        }
    }

    cout << "All nodes are deleted successfully.\n";
}

void deleteAStudent()
{
    int searchId;
    cout << "Enter the ID of student you want to delete" << endl;
    cin >> searchId;

    struct Course *c1 = courseHead;
    while (c1 != NULL)
    {
        struct Student *currStudent = c1->firstStudent;
        struct Student *prevStudent = NULL;

        while (currStudent != NULL)
        {
            if (currStudent->id == searchId)
            {
                if (prevStudent == NULL)
                {
                    // Deleting the first student in the list
                    c1->firstStudent = currStudent->next;
                }
                else
                {
                    prevStudent->next = currStudent->next;
                }

                struct Student *temp = currStudent;
                currStudent = currStudent->next;
                free(temp);
            }
            else
            {
                prevStudent = currStudent;
                currStudent = currStudent->next;
            }
        }
        c1 = c1->next;
    }
}

void deleteACourse()

{
    struct Student *temp = new Student();
    int inputCourseNo;
    int searchFlag = 0;
    cout << "Enter Course No: " << endl;
    cin >> inputCourseNo;

    struct Course *temp1 = courseHead;
    struct Course *prev = NULL;

    while (temp1 != NULL)
    {
        if (temp1->courseNo == inputCourseNo)
        {
            searchFlag = 1;
            break;
        }
        prev = temp1;
        temp1 = temp1->next;
    }
    if (searchFlag == 1)
    {
        // temp = temp1->firstStudent;
        while (temp1->firstStudent = NULL)
        {
            temp = temp1->firstStudent;
            temp1->firstStudent = temp1->firstStudent->next;
            free(temp);
        }
    }
    temp1->firstStudent = NULL;
    cout << "All nodes are deleted successfully.\n";
    if (temp1 == courseHead)
    {
        struct Course *curr = temp1;
        courseHead = temp1->next;
        free(curr);
    }
    else
    {
        prev->next = temp1->next;
        free(temp1);
    }
}

void printStudent()
{
    int searchId;
    cout << "Enter the ID of student you want to search : " << endl;
    cin >> searchId;

    struct Course *c1 = courseHead;
    cout << "Student ID : " << searchId << endl;
    cout << "Courses Enrolled : ";
    while (c1 != NULL)
    {
        struct Student *currStudent = c1->firstStudent;
        while (currStudent != NULL)
        {
            if (currStudent->id == searchId)
            {
                cout << c1->courseNo << " | ";
                break;
            }
            currStudent = currStudent->next;
        }
        c1 = c1->next;
    }
    cout << endl;
}

int main()
{
    int input;
    do
    {
        cout << "1.Insert Course" << endl;
        cout << "2.Insert Student" << endl;
        cout << "3.Print List" << endl;
        cout << "4.Delete All Students" << endl;
        cout << "5.Delete A Student From All Courses" << endl;
        cout << "6.Delete A Course" << endl;
        cout << "7.Print Student Data" << endl;
        cout << "8.Exit" << endl;
        cout << "Enter Your Choice : " << endl;
        cin >> input;
        if (input == 1)
        {
            insertCourse();
        }
        else if (input == 2)
        {
            insertStudent();
        }
        else if (input == 3)
        {
            print();
        }
        else if (input == 4)
        {
            deleteAllStudents();
        }
        else if (input == 5)
        {
            deleteAStudent();
        }
        else if (input == 6)
        {
            deleteACourse();
        }
        else if (input == 7)
        {
            printStudent();
        }
        else if (input == 8)
        {
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    } while (input != 8);

    return 0;
}