#include <iostream>
#include <string>
#include <vector>
//#include <ofstream>     // creates and write files
//#include <ifstream>     // read files
#include <fstream>      // creates, write and read files
#include <ctime>        // work with dates and times

using namespace std;

class Animal {          // base class (parent)
    public:
        string name;

        void breathe() {
            cout << "breath" << endl;
        }
        void sound() {
            cout << "Animal Sound" << endl;
        }
};

class Texture {
    public:
        string material;
        void roughness(int indexRough) {
            cout << indexRough << endl;
    }
};

class Bird: public Animal {         // derived class (child), Inheritance -> reuse of attributes
    public:
        int weight;
        int height;

        void sound() {              // Polymorphism -> reuse of methods
            cout << "Bird sound" << endl;
        }
};

class Raptor: public Bird, public Texture {         // Grandchild
    public:
        double force;
        double eyes;

        void sound() {
            cout << "Raptor sound" << endl;
        }
};

class Car {             // class
    public:             // access identifier
        string brand;   // attribute
        string model;   // attribute
        int year;       // attribute

        // Constructor, always public
        Car(string x, string y, int z) {    // also possible to define it outside
            brand = x;
            model = y;
            year = z;
        }

    private:            // by default
        int nWheels;

        int speed(int maxSpeed) {       // inside method
            cout << maxSpeed << endl;
        };

        int brake(int braking);         // declaration of outside method
};

class Employee {
    private:            // private attributes for encapsulation with public for get/set values
        string contract;    // not inheritable
    protected:
        int salary;         // inheritable, but attributes can still be modified only inside the class

    public:
        void setSalary(int s) {     // Setter
            salary = s;
        }
        int getSalary() {           // Getter
            return salary;
        }
};

int Car::brake(int braking) {           // outside method of class
    cout << braking << endl;
    return braking;
}

int main(){

    Car carObj1("BMW", "Series3", 2021);
    //carObj1.brand = "BMW";
    //carObj1.model = "Series 3";
    //carObj1.year = 2021;

    Car carObj2("Ford", "Mustang", 1969);

    // Files handling
    // create and open file
    ofstream MyFile("testFile.txt");
    // write to file
    MyFile << "Line on file";
    // close the file
    MyFile.close();

    // read from file
    ifstream MyReadFile("testFile.txt");
    string myText;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        cout << myText;
    }
    MyReadFile.close();

    try {
        int age = 15;
        if (age >= 18) {
            cout << "Access granted - age greater or equal than 18" << endl;
        }
        else {
            throw 505;
        }
    }
    catch (...){    // catch (in num)
        cout << "Access denied - age less than 18" << endl;
        //cout << "Error number is  " << num << endl;
    }

    time_t timestamp;
    time(&timestamp);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &timestamp);
    cout << buffer << endl;


    return 0;
}