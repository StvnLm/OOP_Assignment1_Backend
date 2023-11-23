// main.cpp
#include "../header/patient.h" // Include the header file
#include "../header/appointment.h" 
#include "../header/inpatient.h"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
    Appointment myAppointments;
    std::vector<Patient> patientList;
    std::vector<MedicalStaff> medicalStaffList;
    int choice;
    do {
        std::cout << std::endl;
        cout << "Menu:" << endl;
        cout << "1. Create Patient" << endl;
        cout << "2. Create Medical Staff" << endl;
        cout << "3. Create Treatment" << endl;
        cout << "4. Create Appointment" << endl;
        cout << "5. Print Appointments" << endl;
        cout << "6. Remove Appointment" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1: {
                string name;
                int age;
                char gender;
                string illness;
                char inpatient = false;
                cout << "Enter patient's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter patient's age: ";
                cin >> age;
                cout << "Enter patient's gender: ";
                cin >> gender;
                cout << "Enter patient's illness: ";
                cin.ignore();
                getline(cin, illness);
                cout << "Is this an Inpatient? (Y/N): ";
                cin >> inpatient;
                if (inpatient == 'Y') {
                    Patient Patient(name, age, gender, illness);
                    patientList.push_back(Patient);
                }
                break;
            }
            case 2: {
                string name;
                string role;
                cout << "Enter staff name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter staff role/title: ";
                cin >> role;
                if (role == "Doctor") {
                    Doctor doctor(name, role);
                    medicalStaffList.push_back(doctor);
                }
                else if (role == "Nurse") {
                    Nurse nurse(name, role);
                    medicalStaffList.push_back(nurse);
                }
                else {
                    MedicalStaff staff(name, role); 
                    medicalStaffList.push_back(staff);
                    }
                break;
            }
            case 3: // Create Treatment 
                break;
            case 4: // Create Appointment
            {
                int patientIndex = 0;
                int staffIndex = 0;
                int month = 0;
                int day = 0;
                int year = 0;
                int hr = 0;
                int min = 0;
                Patient* patientPtr = nullptr;
                MedicalStaff* staffPtr = nullptr;

                cout << "Enter patient # to schedule for the appointment: " << std::endl;
                for (int i = 0; i < patientList.size(); i++) {
                    std::cout << i << ". " << patientList[i].get_name() << std::endl;
                }
                cin >> patientIndex;
                patientPtr = &patientList[patientIndex];

                cout << "Enter staff # to schedule for the appointment: " << std::endl;
                for (int i = 0; i < medicalStaffList.size(); i++) {
                    std::cout << i << ". " << medicalStaffList[i].getName() << std::endl;
                }
                cin >> staffIndex;
                staffPtr = &medicalStaffList[staffIndex];

                cout << "Enter month to schedule for appointment: ";
                cin >> month;
                cout << "Enter day to schedule for appointment: ";
                cin >> day;
                cout << "Enter year to schedule for appointment: ";
                cin >> year;
                cout << "Enter hour to schedule for appointment: ";
                cin >> hr;
                cout << "Enter minutes to schedule for appointment: ";
                cin >> min;
                myAppointments.addAppointment(day, month, year, hr, min, *patientPtr, *staffPtr);
                break;
            }
            case 5:
                myAppointments.printAppointments();
                break;
            case 6: //Remove Appointment
            {
                int patientIndex = 0;
                int staffIndex = 0;
                int month = 0;
                int day = 0;
                int year = 0;
                int hr = 0;
                int min = 0;
                Patient* patientPtr = nullptr;
                MedicalStaff* staffPtr = nullptr;

                cout << "Enter patient # to remove for the appointment: " << std::endl;
                for (int i = 0; i < patientList.size(); i++) {
                    std::cout << i << ". " << patientList[i].get_name() << std::endl;
                }
                cin >> patientIndex;
                patientPtr = &patientList[patientIndex];

                cout << "Enter staff # to remove for the appointment: " << std::endl;
                for (int i = 0; i < medicalStaffList.size(); i++) {
                    std::cout << i << ". " << medicalStaffList[i].getName() << std::endl;
                }
                cin >> staffIndex;
                staffPtr = &medicalStaffList[staffIndex];

                cout << "Enter month to schedule for appointment: ";
                cin >> month;
                cout << "Enter day to schedule for appointment: ";
                cin >> day;
                cout << "Enter year to schedule for appointment: ";
                cin >> year;
                cout << "Enter hour to schedule for appointment: ";
                cin >> hr;
                cout << "Enter minutes to schedule for appointment: ";
                cin >> min;
                myAppointments.removeAppointment(day, month, year, hr, min, *patientPtr, *staffPtr);
                break;
            }
            case 7:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 7);

    return 0;
}

// int main() {
//     Patient patientSteve("Steven", 12, 'M', "Cold");
//     Patient patientBob("Bob", 31, 'M', "Strep throat");
//     Patient patientJoanna("Joanna", 75, 'F', "Coronavirus");

// 	vector<Patient_services> chrisInpatientTreatments;
//     Patient_services allergyTreatment;
//     allergyTreatment.service_name = "Antihistamines";
//     allergyTreatment.dose_schedule = "Twice a day";
//     allergyTreatment.start_date = "2023-02-01";
//     allergyTreatment.end_date = "2023-02-05";
//     chrisInpatientTreatments.push_back(allergyTreatment);
//     Patient_services pinkEyeTreatment;
//     pinkEyeTreatment.service_name = "Moxeza";
//     pinkEyeTreatment.dose_schedule = "Once a day";
//     pinkEyeTreatment.start_date = "2023-02-01";
//     pinkEyeTreatment.end_date = "2023-02-05";
//     chrisInpatientTreatments.push_back(pinkEyeTreatment);

//     Inpatient inpatientChris("Chris", 24, 'M', "Seasonal allergies", 13, chrisInpatientTreatments);
//     Appointment myAppointments;
//     Doctor doctorJohn("John Washington", "Doctor");
//     Nurse nurseJessica("Jessica Corn", "Nurse");
//     MedicalStaff resMike("Mike Pence", "Resident Doctor");

//     myAppointments.addAppointment(12, 12, 2023, 1, 30, patientSteve, doctorJohn);
//     myAppointments.addAppointment(1, 9, 2022, 2, 45, patientBob, doctorJohn);
//     myAppointments.addAppointment(1, 9, 2022, 3, 45, patientSteve, nurseJessica);
//     myAppointments.addAppointment(22, 8, 2019, 14, 15, patientJoanna, resMike);
//     myAppointments.addAppointment(11, 4, 2015, 16, 55, inpatientChris, nurseJessica);
//     myAppointments.printAppointments();
//     std::cout << std::endl << "################################################################ " << std::endl;
//     std::cout << "################################################################ " << std::endl;
//     std::cout << "################################################################ " << std::endl << std::endl;
//     myAppointments.removeAppointment(1, 9, 2022, 3, 45, patientSteve, nurseJessica);
//     myAppointments.printAppointments();
//     return 0;
// }
