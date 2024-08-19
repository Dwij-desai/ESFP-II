#include <iostream>
#include <fstream>
#include <string>
#include <cstring> //for using string type from C
#include <limits>

using namespace std;

void userinfo()  //User information (using string type)
{
    string age="";
    string name="";
    string address="";
    string email="";


    cout<<"Enter your info here:-(Age,Name,Address,Email)"<<endl;
    redo:
    cin>>age>>name>>address>>email;     cout<<endl;

    /////append()/////
    string tinfo="";
    tinfo = age + name + address + email;


    /////empty()/////
    //age="";

    if(age.empty() || name.empty() || address.empty() || email.empty())
    {
        cout<<"Error:Data not stored\n\n";
        cout<<"Enter your info again here:-(Age,Name,Address,Email)"<<endl;
        goto redo;
    }

}

class elearning //only for b.tech
{
private:
    int expression;
    string selectedCourse;
    string courseLevel;
    string preferredWayOfLearning;
    string durationForEachDay;

public:
    // Default constructor
    elearning()
    {
        // General initialization
        expression = 0; // Default value
    }

    // Parameterized constructor
    elearning(int exp)
    {
        // Initialization based on user input
        expression = exp;
        switch (expression)
        {
        case 1:
            cout << endl << "You chose Business" << endl << endl;
            selectedCourse = "Business";
            selectComputerCourse();
            break;
        case 2:
            cout << endl << "You chose Computer course" << endl << endl;
            selectedCourse = "Computer course";
            selectComputerCourse();
            break;
        case 3:
            cout << endl << "You chose Data science" << endl << endl;
            selectedCourse = "Data science";
            selectComputerCourse();
            break;
        case 4:
            cout << endl << "You chose ICT" << endl << endl;
            selectedCourse = "ICT";
            selectComputerCourse();
            break;
        default:
            break;
        }
    }

    void selectCourse()
    {
        cout << ">>>Course Selection<<<" << endl;
        cout << "<1> Business" << endl;
        cout << "<2> Computer course" << endl;
        cout << "<3> Data science" << endl;
        cout << "<4> ICT" << endl;
    }

    void selectComputerCourse()
    {
        int totalDuration = 0; // Initialize total duration
        int innerExpression = 0;
        while (true)
        {
            cout << endl << ">>>Enter choice for Computer course:<<<" << endl;
            cout << "<1> Course Level" << endl;
            cout << "<2> Preferred Way of Learning" << endl;
            cout << "<3> Duration for Each Day" << endl;
            cout << "<4> Exit" << endl;
            cin >> innerExpression;

            switch (innerExpression)
            {
            case 1: // Course Level
            {
                int level = 0;
                cout << "Course Level:" << endl;
                cout << "<1> 1-2 weeks (basic)" << endl;
                cout << "<2> 2-5 weeks (intermediate)" << endl;
                cout << "<3> 6-7 weeks (advance)" << endl;
                cin >> level;
                switch (level)
                {
                case 1:
                    cout << "1-2 weeks (basic)" << endl;
                    courseLevel = "1-2 weeks (basic)";
                    totalDuration += 2; // Add 2 weeks to total duration
                    break;
                case 2:
                    cout << "2-5 weeks (intermediate)" << endl;
                    courseLevel = "2-5 weeks (intermediate)";
                    totalDuration += 5; // Add 5 weeks to total duration
                    break;
                case 3:
                    cout << "6-7 weeks (advance)" << endl;
                    courseLevel = "6-7 weeks (advance)";
                    totalDuration += 7; // Add 7 weeks to total duration
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
                break;
            }
            case 2: // Preferred Way of Learning
            {
                int preferredWay = 0;
                cout << "Preferred Way of Learning:" << endl;
                cout << "<1> Guided project" << endl;
                cout << "<2> Personal practical" << endl;
                cout << "<3> Notes and concept learning" << endl;
                cin >> preferredWay;
                switch (preferredWay)
                {
                case 1:
                    cout << "Guided project" << endl;
                    preferredWayOfLearning = "Guided project";
                    break;
                case 2:
                    cout << "Personal practical" << endl;
                    preferredWayOfLearning = "Personal practical";
                    break;
                case 3:
                    cout << "Notes and concept learning" << endl;
                    preferredWayOfLearning = "Notes and concept learning";
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
                break;
            }
            case 3: // Duration for Each Day
            {
                int duration = 0;
                cout << "Duration for Each Day:" << endl;
                cout << "<1> 2 hours" << endl;
                cout << "<2> 4 hours" << endl;
                cout << "<3> 6 hours" << endl;
                cin >> duration;
                switch (duration)
                {
                case 1:
                    cout << "2 hours" << endl;
                    durationForEachDay = "2 hours";
                    break;
                case 2:
                    cout << "4 hours" << endl;
                    durationForEachDay = "4 hours";
                    break;
                case 3:
                    cout << "6 hours" << endl;
                    durationForEachDay = "6 hours";
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
                break;
            }
            case 4: // Exit
                cout << "Exiting..." << endl;
                cout << "Total duration to complete the course: " << totalDuration << " weeks" << endl;
                storeDataToFile(); // Store data to file
                return; // Exit the function and terminate the loop
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }

    void storeDataToFile()
    {
        ofstream file("elearning_data.txt", ios_base::app);
        file.is_open();
        if (file.is_open())
        {
            file << "Selected Course: " << selectedCourse << endl;
            file << "Course Level: " << courseLevel << endl;
            file << "Preferred Way of Learning: " << preferredWayOfLearning << endl;
            file << "Duration for Each Day: " << durationForEachDay << endl;
            file << "---------------------------------------" << endl;
            file.close();
            cout << "Data saved to elearning_data.txt" << endl;
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }
};

int main()
{
    userinfo();

    elearning obj1; // Calls default constructor
    obj1.selectCourse();
    int userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    cin.ignore(); // remove buffer

    elearning obj2(userChoice); // sends data to 'exp'

    return 0;
}
