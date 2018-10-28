#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Name{
    string givenName;
    string middleName;
    string familyName;
};

struct Date{
    int day;
    int month;
    int year;
};

struct Address{
    string country;
    string region;
    string city;
    string street;
    string houseNumber;
};

struct PhoneNumber{
    int codeOfCountry;
    int codeOfOperator;
    int individualNumber;
};

struct History{
    vector<string> someList;
};

class Person{
protected:
    Name nameOfPerson;
    Date birthDate;
    bool gender;
    Address addressOfPerson;
    PhoneNumber phoneNumberOfPerson;
protected:
    Person(){};

    void setPerson(Name nameOfSomePerson, Date birthDateOfSomePerson, bool someGenderOfPerson, Address addressOfSomePerson, PhoneNumber phoneNumberOfSomePerson){
        nameOfPerson = nameOfSomePerson;
        birthDate = birthDateOfSomePerson;
        gender = someGenderOfPerson;
        addressOfPerson = addressOfSomePerson;
        phoneNumberOfPerson = phoneNumberOfSomePerson;
    }

    void setPerson(Person somePerson){
        nameOfPerson = somePerson.nameOfPerson;
        birthDate = somePerson.birthDate;
        gender = somePerson.gender;
        addressOfPerson = somePerson.addressOfPerson;
        phoneNumberOfPerson = somePerson.phoneNumberOfPerson;
    };

    void dynamicSetPerson(){
        
        cout << "\n\tInput name of person" << endl;
        cout << "\nGiven name of Person:\t";
        cin >> nameOfPerson.givenName;
        cout << "Middle name of Person:\t";
        cin >> nameOfPerson.middleName;
        cout << "Family name of Person:\t";
        cin >> nameOfPerson.familyName;

        cout << "\n\tBirth date of Person" << endl;
        cout << "Day:\t";
        cin >> birthDate.day;
        cout << "Month:\t";
        cin >> birthDate.month;
        cout << "Year";
        cin >> birthDate.year;

        cout << "\n\tIs it man or woman (man = 0; woman = 1)?\t";
        cin >> gender;

        cout << "\n\tAddress of Person" << endl;
        cout << "Country:\t";
        cin >> addressOfPerson.country;
        cout << "Region:\t";
        cin >> addressOfPerson.region;
        cout << "City:\t";
        cin >> addressOfPerson.city;
        cout << "Street:\t";
        cin >> addressOfPerson.street;
        cout << "Number of house:\t";
        cin >> addressOfPerson.houseNumber;

        cout << "\n\tPhone Number Of Person" << endl;
        cout << "Country code:\t";
        cin >> phoneNumberOfPerson.codeOfCountry;
        cout << "Operator code:\t";
        cin >> phoneNumberOfPerson.codeOfOperator;
        cout << "Individual code:\t";
        cin >> phoneNumberOfPerson.individualNumber;
    }

    void showPerson(){
        cout << "\n\tName of Person:\t" << nameOfPerson.givenName << " " << nameOfPerson.middleName << " " << nameOfPerson.familyName << ";" << endl;
        cout << "\tBirth date of " << nameOfPerson.givenName << ":\t" << birthDate.day << "-" << birthDate.month << "-" << birthDate.year << ";" << endl;
        if(!gender)
            cout << "\tGender:\tMan" << endl;
        else
            cout << "\tGender:\tWoman" << endl;
        cout << "\tAddress of living of " << nameOfPerson.givenName << ":\t" << addressOfPerson.country << ", " << addressOfPerson.region << ", " << addressOfPerson.city << ", " << addressOfPerson.street << ", " << addressOfPerson.houseNumber << endl;
    }
public:
    Name getNameOfPerson(){
        return nameOfPerson;
    };

    Date getBirthDateOfPerson(){
        return birthDate;
    };

    bool getGenderOfPerson(){
        return gender;
    };

    Address getAddressOfPerson(){
        return addressOfPerson;
    };

    PhoneNumber getPhoneNumberOfPerson(){
        return phoneNumberOfPerson;
    };
};

class Patient : public Person{
    string id;
    int age;
    Date dateWhenWasAccepted;
    History sickness;
    string prescriptions;
    string allergies;
    string specialReqs;
public:
    Patient(){
        nameOfPerson.givenName = nameOfPerson.middleName = nameOfPerson.familyName = "None";
        birthDate.day = birthDate.month = birthDate.year = 0;
        gender = 0;
        addressOfPerson.country = addressOfPerson.region = addressOfPerson.city = addressOfPerson.street = addressOfPerson.houseNumber = "None";
        phoneNumberOfPerson.codeOfCountry = phoneNumberOfPerson.codeOfOperator = phoneNumberOfPerson.individualNumber = 0;
        id = "None";
        age = 0;
        dateWhenWasAccepted.day = dateWhenWasAccepted.month = dateWhenWasAccepted.year = 0;
        prescriptions = allergies = specialReqs = "None";
    };

    void setPatient(Name nameOfSomePerson, Date birthDateOfSomePerson, bool someGenderOfPerson, Address addressOfSomePerson, PhoneNumber phoneNumberOfSomePerson, string someID, Date whenWasAccepted, History someSickness, string somePrescriptions = "None", string someAllergies = "None", string someSpecialReqs = "None"){
        setPerson(nameOfSomePerson, birthDateOfSomePerson, someGenderOfPerson, addressOfSomePerson, phoneNumberOfSomePerson);

        id = someID;
        age = birthDate.year - whenWasAccepted.year;
        dateWhenWasAccepted = whenWasAccepted;
        sickness = someSickness;
        prescriptions = somePrescriptions;
        allergies = someAllergies;
        specialReqs = someSpecialReqs;
    };

    void dynamicSetPatient(){
        string temp;
        bool choice;
        cout << "//////////////////////////////////////////////////////////////////////////" << endl;
        
        dynamicSetPerson();

        cout << "\n\tData for hospital" << endl;
        cout << "Id of " << nameOfPerson.givenName << ":\t";
        cin >> id;

        cout << "\tWhen patient was accepted" << endl;
        cout << "Day:\t";
        cin >> dateWhenWasAccepted.day;
        cout << "Month:\t";
        cin >> dateWhenWasAccepted.month;
        cout << "Year:\t";
        cin >> dateWhenWasAccepted.year;

        age = birthDate.year - dateWhenWasAccepted.year;

        cout << "\tList of patient's sicknesses" << endl;
        while(choice){
            cout << "What sickness does he/she have?" << endl;
            cin >> temp;
            sickness.someList.push_back(temp);
            cout << "There is any more sickness (1 = yes, 0 = no)?" << endl;
            cin >> choice;
        }

        cout << "There are any prescriptions (1 = yes, 0 = no)?" << endl;
        if(choice){
            cout << "Input prescriptions:" << endl;
            cin >> prescriptions;
        }

        cout << "There are any allergies (1 = yes, 0 = no)?" << endl;
        if(choice){
            cout << "Input allergies:" << endl;
            cin >> allergies;
        }

        cout << "There are any special requirements (1 = yes, 0 = no)?" << endl;
        if(choice){
            cout << "Input special requirements:" << endl;
            cin >> specialReqs;
        }

        cout << "\n//////////////////////////////////////////////////////////////////////////" << endl;
    }

    void showPatient(){
        cout << "----------------------------------------------------------------------------------" << endl;

        showPerson();

        cout << "\tID:\t" << id << ";" << endl;
        cout << "\tAge:\t" << age << ";" << endl;
        cout << "\tDate when was accepted:\t" << dateWhenWasAccepted.day << "-" << dateWhenWasAccepted.month << "-" << dateWhenWasAccepted.year << ";" << endl;
        cout << "\tSicknesses:\t";
        for(vector<string>::size_type i = 0; i != sickness.someList.size(); i++){
            cout << sickness.someList[i] << endl;
        }

        cout << "\tPrescriptions: " << prescriptions << ";" << endl;
        cout << "\tAllergies: " << allergies << ";" << endl;
        cout << "\tSpecial requirements: " << specialReqs<< "." << endl;

        cout << "\n----------------------------------------------------------------------------------" << endl;
    }
};

class Staff : public Person{
protected:
    Date whenPersonJoined;
    string education;
    string certification;
    string languages;

public:
    Staff(){
        nameOfPerson.givenName = nameOfPerson.middleName = nameOfPerson.familyName = "None";
        birthDate.day = birthDate.month = birthDate.year = 0;
        gender = 0;
        addressOfPerson.country = addressOfPerson.region = addressOfPerson.city = addressOfPerson.street = addressOfPerson.houseNumber = "None";
        phoneNumberOfPerson.codeOfCountry = phoneNumberOfPerson.codeOfOperator = phoneNumberOfPerson.individualNumber = 0;
        whenPersonJoined.day = whenPersonJoined.month = whenPersonJoined.year = 0;
        education = certification = languages = "None";
    };

    void setStaff(Name nameOfSomePerson, Date birthDateOfSomePerson, bool someGenderOfPerson, Address addressOfSomePerson, PhoneNumber phoneNumberOfSomePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setPerson(nameOfSomePerson, birthDateOfSomePerson, someGenderOfPerson, addressOfSomePerson, phoneNumberOfSomePerson);

        whenPersonJoined.day = someWhenPersonJoined.day;
        whenPersonJoined.month = someWhenPersonJoined.month;
        whenPersonJoined.year = someWhenPersonJoined.year;

        education = someEducation;
        certification = someCertification;
        languages = someLanguages;
    };

    void setStaff(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setPerson(somePerson);

        whenPersonJoined.day = someWhenPersonJoined.day;
        whenPersonJoined.month = someWhenPersonJoined.month;
        whenPersonJoined.year = someWhenPersonJoined.year;

        education = someEducation;
        certification = someCertification;
        languages = someLanguages;        
    }

    void dynamicSetStaff(){
        cout << "//////////////////////////////////////////////////////////////////////////" << endl;
        
        dynamicSetPerson();

        cout << "\n\tWhen Person joined to Staff" << endl;
        cout << "\tDay:\t";
        cin >> whenPersonJoined.day;
        cout << "\tMonth:\t";
        cin >> whenPersonJoined.month;
        cout << "\tYear:\t";
        cin >> whenPersonJoined.year;

        cout << "\n\tEducation of Person:\t";
        cin >> education;

        cout << "\n\tCertification of Person:\t";
        cin >> certification;

        cout << "\n\tLanguages:\t";
        cin >> languages;

        cout << "\n//////////////////////////////////////////////////////////////////////////" << endl;
    };

    void showStaff(){
        cout << "----------------------------------------------------------------------------------" << endl;

        showPerson();

        cout << "\tDate when " << nameOfPerson.givenName << " joined to Staff:\t" << whenPersonJoined.day << "-" << whenPersonJoined.month << "-" << whenPersonJoined.year << ";" << endl;
        cout << "\tCertification of " << nameOfPerson.givenName << ":\t" << certification;
        cout << "\tEducation of " << nameOfPerson.givenName << ":\t" << education;
        cout << "\tLanguages that " << nameOfPerson.givenName << " knows:\t" << languages;

        cout << "\n----------------------------------------------------------------------------------" << endl;
    };
};

class Department{
    vector<Staff> listOfStaff;
};

class Hospital{
    string nameOfHosp;
    Address addressOfHosp;
    PhoneNumber phoneOfHosp;
    vector<Department> departments;
};

class OperationsStaff : public Staff{
    vector<Staff> listOfStaffOperations;

    void addNewStaffToOperations(Staff someStaff){
        listOfStaffOperations.push_back(someStaff);
    };

    void showOperationsStaff(){
        cout << "----------------------------------------------------------------------------------" << endl;

        cout << "\n\tList of all staff:" << endl;

        for(vector<Staff>::size_type i = 0; i != listOfStaffOperations.size(); i++){
            cout << listOfStaffOperations[i].getNameOfPerson().givenName << listOfStaffOperations[i].getNameOfPerson().middleName << listOfStaffOperations[i].getNameOfPerson().familyName << endl;
        }
    };
};

class Doctor : public OperationsStaff{
    string speciality;
    string locations;
public:
    Doctor(){
        Staff();
        speciality = "None";
        locations = "None";
    }
    void setDoctor(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages, string someSpeciality, string someLocations){
        setStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);

        speciality = someSpeciality;
        locations = someLocations;
    };
};

class Nurse : public OperationsStaff{
public:
    Nurse(){
        Staff();
    };
    void setNurse(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    };
};

class Surgeon : public Doctor{
public:
    Surgeon(){
        Doctor();
    };
    void setSurgeon(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages, string someSpeciality, string someLocations){
        setDoctor(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages, someSpeciality, someLanguages);
    };
};

class AdministrativeStaff : public Staff{
public:
    AdministrativeStaff(){
        Staff();
    };
    void setAdministrativeStaff(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    };
};

class FrontDeskStaff : public AdministrativeStaff{
public:
    FrontDeskStaff(){
        AdministrativeStaff();
    };
    void setFrontDeskStaff(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setAdministrativeStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    };
};

class Receptionist : public FrontDeskStaff{
public:
    Receptionist(){
        FrontDeskStaff();
    }
    void setReceptionist(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setFrontDeskStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    };
};

class TechnicalStaff : public Staff{
public:
    TechnicalStaff(){
        Staff();
    }
    void setTechnicalStaff(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    };
};

class Technician : public TechnicalStaff{
public:
    Technician(){
        TechnicalStaff();
    };
    void setTechnician(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setTechnicalStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    }
};

class Technologist : public TechnicalStaff{
public:
    Technologist(){
        TechnicalStaff();
    };
    void setTechnologist(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setTechnicalStaff(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    };
};

class SurgicalTechnologist : public Technologist{
public:
    SurgicalTechnologist(){
        Technologist();
    };
    void setSurgicalTechnologist(Person somePerson, Date someWhenPersonJoined, string someEducation, string someCertification, string someLanguages){
        setTechnologist(somePerson, someWhenPersonJoined, someEducation, someCertification, someLanguages);
    };
};
