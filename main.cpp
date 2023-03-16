#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>


using namespace std;


class Student {

public:

    Student (){
        name_ = "Max";
        surname_ = "Babak";
        index_ = 153908;
        grades_ = {4.5, 4.0, 3.5, 5.0, 4.5};
    }

    Student (string name, string surname, float index){
        name_ = name;
        surname_ = surname;
        index_ = index;
    }

    void add_grades (float grade){
        if (grade >= 2.0 && grade <= 5.0){
            grades_.push_back(grade);
        }
    }

    void add_grades (vector<float> grades){
        for (auto grade : grades){
            if (grade >= 2.0 && grade <= 5.0){
                grades_.push_back(grade);
            }
        }
    }

    void set_name_surname (string name1, string surname1, float index1){
        name_ = name1;
        surname_ = surname1;
        index_ = index1;
    }

    void display_info (){
        cout << name_ << " " << surname_ << " - ";
        for (auto grade : grades_){
            cout << grade << " ";
        }
        cout << endl;
    }

    float mean_grade (){
        float sum = std::accumulate(grades_.begin(), grades_.end(), 0.0f);
        return sum / size(grades_);
    }

    bool check_student (){
        int check = 0;
        for (auto grade : grades_){
            if (grade == 2.0){
                check++;
            }
        }
        if (check > 1){
            cout << name_ << " " << "you are a bad student" << endl;
            return true;
        }
        cout << name_ << " " << "you are a good student" << endl;
        return false;
    }

private:

    string name_;
    string surname_;
    int index_;
    vector<float> grades_;
};

int main()
{
    Student student_1;
    Student student_2("Bohdan", "Smyrnov", 153920);
    vector<float> grades_2 = {4.0, 3.5, 2.0, 6.5, 2.0};

    student_1.add_grades(4.5);
    student_2.add_grades(grades_2);

    student_1.display_info();
    student_2.display_info();

    student_1.check_student();
    student_2.check_student();
}
