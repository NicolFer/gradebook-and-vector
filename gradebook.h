#include <string>
#include <array>
#include <iostream>
#include <iomanip>

class GradeBook {
public:
    static const size_t students{10};

    GradeBook(const std::string& name,
        const std::array<int, students>& gradesArray)
        : courseName{name}, grades{gradesArray}{
    }

    void setCouseName(const std::string& name){
        courseName = name;
    }

    const std::string& getCourseName() const{
        return courseName;
    }

    void displayMessage() const {
        std::cout<<"Welcome to the grade book for\n"<< getCourseName()
            <<"!"<<std::endl;
    }

    void processGrades()const {
        outputGrades();
        std::cout<< std::setprecision(2)<<std::fixed;
        std::cout<<"\nClass average is " << getAverage()<<std::endl;

        std::cout<<"Lowest grade is "<<getMinimum()
            <<"\nHighest grade is " << getMaximum()<<std::endl;

            outputBarChart();
    }

    int getMinimum() const {
        int lowGrade{100};

        for(int grade:grades){
            if (grade<lowGrade){
                lowGrade = grade;
            }
        }
        return lowGrade;
    }

    int getMaximum() const {
        int highGrade{0};

        for(int grade : grades){
            if(grade>highGrade){
                highGrade = grade;
            }
        }
        return highGrade;
    }

    double getAverage()cont{
        int total{0};

        for(int grade:grades){
            total+=grade;
        }
        return static_cast<double>(total)/grades.size();
    }

    void outputBarChart()const{
        std::cout << "\n Grade distribution:"<<std::endl;

        const size_t frequencySize{11};
        std::array<unsigned int, frequencySize> frequency{};

        for(int grade : grades) {
            ++frequency[grade/10];
        }

        for (size_t count{0}; count < frequencySize; ++count){
            if(0==count) {
                std::cout <<" 0-9";
            }
            else if(10==count){
                std::cout<<"100:";
            }
            else { 
                std::cout << count * 10 << "-" <<(count*10)+9<<": ";
            }

            for(insigned int stars{0}; stars < frequency[count]; ++stars){
            std::cout<<"*";
            }

            std::cout<<std::endl;
        }
    }
    void outputGrades() const {
        std::cout << "\nThe grades are:\n\n";

        for (size:t student{0}; student < grades.size(); ++student){
            std::cout <<"Student "<<std::setw(2)<<student + 1 << ": "
                << std::setw(3)<<grades[student]<<std::endl;
        }
    }
private: 
    std::string courseName;
    std::array<int, students>grades;
};