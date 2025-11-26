#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ---------------------- Base Class ----------------------
class Person {
protected:
    string name;
    string fatherName;
    string gender;

public:
    void setName(const string& n) { name = n; }
    void setFatherName(const string& f) { fatherName = f; }
    void setGender(const string& g) { gender = g; }

    string getName() const { return name; }
    string getFatherName() const { return fatherName; }
    string getGender() const { return gender; }
};

// ---------------------- Derived Class 1 ----------------------
class Employee : public Person {
private:
    string department;
    int experience;

public:
    void setDepartment(const string& d) { department = d; }
    void setExperience(int e) { experience = e; }

    string getDepartment() const { return department; }
    int getExperience() const { return experience; }
};

// ---------------------- Derived Class 2 ----------------------
class Manager : public Person {
private:
    string project;
    int teamSize;

public:
    void setProject(const string& p) { project = p; }
    void setTeamSize(int t) { teamSize = t; }

    string getProject() const { return project; }
    int getTeamSize() const { return teamSize; }
};

// ---------------------- Add Employee ----------------------
void addEmployee() {
    Employee emp;
    string name, father, gender, dept;
    int exp;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    emp.setName(name);

    cout << "Enter Father Name: ";
    getline(cin, father);
    emp.setFatherName(father);

    cout << "Enter Gender: ";
    getline(cin, gender);
    emp.setGender(gender);

    cout << "Enter Department: ";
    getline(cin, dept);
    emp.setDepartment(dept);

    cout << "Enter Experience (years): ";
    cin >> exp;
    emp.setExperience(exp);

    ofstream file("employee.txt", ios::app);
    file << "Employee Record:\n";
    file << "Name: " << emp.getName() << "\n";
    file << "Father Name: " << emp.getFatherName() << "\n";
    file << "Gender: " << emp.getGender() << "\n";
    file << "Department: " << emp.getDepartment() << "\n";
    file << "Experience: " << emp.getExperience() << " years\n\n";
    file.close();

    cout << "\nEmployee Record Saved Successfully!\n";
}

// ---------------------- Add Manager ----------------------
void addManager() {
    Manager mgr;
    string name, father, gender, project;
    int team;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    mgr.setName(name);

    cout << "Enter Father Name: ";
    getline(cin, father);
    mgr.setFatherName(father);

    cout << "Enter Gender: ";
    getline(cin, gender);
    mgr.setGender(gender);

    cout << "Enter Project: ";
    getline(cin, project);
    mgr.setProject(project);

    cout << "Enter Team Size: ";
    cin >> team;
    mgr.setTeamSize(team);

    ofstream file("manager.txt", ios::app);
    file << "Manager Record:\n";
    file << "Name: " << mgr.getName() << "\n";
    file << "Father Name: " << mgr.getFatherName() << "\n";
    file << "Gender: " << mgr.getGender() << "\n";
    file << "Project: " << mgr.getProject() << "\n";
    file << "Team Size: " << mgr.getTeamSize() << "\n\n";
    file.close();

    cout << "\nManager Record Saved Successfully!\n";
}

// ---------------------- View Files ----------------------
void viewEmployeeFile() {
    ifstream file("employee.txt");
    if (!file) {
        cout << "No Employee Record Found.\n";
        return;
    }

    cout << "\n---- Employee Records ----\n\n";
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void viewManagerFile() {
    ifstream file("manager.txt");
    if (!file) {
        cout << "No Manager Record Found.\n";
        return;
    }

    cout << "\n---- Manager Records ----\n\n";
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

// ---------------------- Main Function ----------------------
int main() {
    int choice;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Add Manager\n";
        cout << "3. View Employee Records\n";
        cout << "4. View Manager Records\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: addManager(); break;
            case 3: viewEmployeeFile(); break;
            case 4: viewManagerFile(); break;
            case 5: 
                cout << "Exiting Program...\n"; 
                return 0;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    }

    return 0;
}

