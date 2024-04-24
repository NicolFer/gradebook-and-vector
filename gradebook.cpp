



#include <array>
#include "gradebook.h"
using namespace std;

int main (){

    const array<int,Gradebook:students>grades{
        87, 68, 94,100,83,78,85,91,76,87};
        string courseName{ "Cs101 Introduction to C++ Programming" };

        GradeBook myGradeBook(couseName, grades);
        myGradeBook.displayMessage();
        myGradeBook.processGrades();
    
}