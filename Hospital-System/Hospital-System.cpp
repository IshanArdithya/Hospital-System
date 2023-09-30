#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h> 
#include <map>

using namespace std;

void title();
//void accessProgram();
void adminLogin();
void adminInterface();
void changeDoctorDetails();
void exitMessage();
void changeDoctorAppointments();
void deleteDoctorAppointments();
void searchDoctorAppointments();
void viewAllDoctorAppointments();
void searchDoctorsProfiles();
void viewAllDoctorsProfiles();
void help();
void hospitalDetails();



class doctor {
public:
    string doc_fn, doc_ln, doc_city;
    int doc_docid, doc_age, doc_xp;
    string docSpecs();
    friend void addDoc();
    friend void changeDoc(doctor& docspecedit);
    friend void deleteDoc();
    friend void showDoc();
    friend void changeDoctorDetails();
};

string doctor::docSpecs() {
    string spec;
    int inputs;
loopspecs:
    cout << "\n1. Cardiologist\n"
        << "2. Dermatologist\n"
        << "3. Endocrinologist\n"
        << "4. Gastroenterologist\n"
        << "5. Gynaecologist\n"
        << "6. Nephrologist\n"
        << "7. Obstetrician\n"
        << "8. Pathologist\n"
        << "9. Psychologist\n"
        << "10. Rheumatologist\n"
        << "11. Venereologist\n"
        << "\nChoose Doctor Specialization: ";
    cin >> inputs;
    switch (inputs) {
    case 1: {
        spec = "Cardiologist";
        break;
    }
    case 2: {
        spec = "Dermatologist";
        break;
    }
    case 3: {
        spec = "Endocrinologist";
        break;
    }
    case 4: {
        spec = "Gastroenterologist";
        break;
    }
    case 5: {
        spec = "Gynaecologist";
        break;
    }
    case 6: {
        spec = "Nephrologist";
        break;
    }
    case 7: {
        spec = "Obstetrician";
        break;
    }
    case 8: {
        spec = "Pathologist";
        break;
    }
    case 9: {
        spec = "Psychologist";
        break;
    }
    case 10: {
        spec = "Rheumatologist";
        break;
    }
    case 11: {
        spec = "Venereologist";
        break;
    }
    default: {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto loopspecs;
    }
    }
    return spec;
}

class appointments {
public:
    int appYear, appDay, appID;
    string patientfn, patientln, docidApp, docNameApp, docfirstName, doclastName, appMonth, appTime;
    string appTimeSelection();
    //string doctorApp();
    friend void addAppointments();
    friend void changeAppointments(appointments& appointmentsedit);
};

string appointments::appTimeSelection() {
    string apptimeselect;
    int option;
loopapptimeselect:
    cout << "\n1. Morning\n"
        << "2. Evening\n"
        << "\nChoose Appointment Time: ";
    cin >> option;
    switch (option) {
    case 1: {
        apptimeselect = "Morning";
        break;
    }
    case 2: {
        apptimeselect = "Evening";
        break;
    }
    default: {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto loopapptimeselect;
    }
    }
    return apptimeselect;
}

int opt;

void title() {
    system("cls");

    printf("\x1B[31m\n--------------------------------------------------------------------\n\033[0m");
    printf("\x1B[31m--------------- <<<< \033[0m");
    cout << "Spire Health Care Hospital";
    printf("\x1B[31m >>>> ---------------\n\033[0m");
    printf("\x1B[31m--------------------------------------------------------------------\n\n\033[0m");

    /*cout << "\n--------------------------------------------------------------------" << endl;
    cout << "--------------- <<<< Spire Health Care Hospital >>>> ---------------" << endl;
    cout << "--------------------------------------------------------------------\n\n" << endl;*/
}

void adminLogin() {
    int password;
    string username;
    title();
    cout << "--------------------------- << Login >> ---------------------------\n" << endl;
    cout << "Enter Username [eg: username] : ";
    cin >> username;
    cout << "\nEnter Password [eg: 123456789] : ";
    cin >> password;

    if (username == "admin" && password == 1234) {
        cout << "\n-------------------------------------------------------------------\n" << endl;
        cout << "\t\t -----------------------------------" << endl;
        cout << "\t\t|         Login Authorized!         |" << endl;
        cout << "\t\t -----------------------------------" << endl;
        cout << "\n-------------------------------------------------------------------\n" << endl;
        system("pause");
        adminInterface();
    }
    else {
        cout << "\n-------------------------------------------------------------------" << endl;
        cout << "\n ------------------------------ " << endl;
        cout << "| Invalid Username or Password | " << endl;
        cout << " ------------------------------\n" << endl;
        cout << "-------------------------------------------------------------------" << endl;
    loop:
        cout << "\nSelect an Option\n" << endl;
        cout << "1. Retry\n"
            << "2. Exit\n" << endl;
        cout << "Option: ";
        cin >> opt;
        if (opt == 1) {
            system("cls");
            adminLogin();
        }
        else if (opt == 2) {
            exitMessage();
        }
        else {
            cout << "\n\n--------------------------------------------------------------------" << endl;
            cout << "\n ---------------" << endl;
            cout << "| Invalid Input |" << endl;
            cout << " ---------------\n" << endl;
            cout << "--------------------------------------------------------------------\n" << endl;
            system("pause");
            goto loop;
        }


    }

}

void adminInterface() {
    system("cls");
    title();
    cout << "------------------------- << Main Menu >> -------------------------\n" << endl;
    cout << "1. Manage Doctor Details\n"
        << "2. Manage Appointment Details\n"
        << "3. Hospital Details\n"
        << "4. Help\n"
        << "5. Logout\n"
        << "6. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        changeDoctorDetails();
    }
    else if (opt == 2) {
        changeDoctorAppointments();
    }
    else if (opt == 3) {
        hospitalDetails();
    }
    else if (opt == 4) {
        help();
    }
    else if (opt == 5) {
        cout << "\n--------------------------------------------------------------------\n" << endl;
    loop: //goto function
        cout << "Are you sure you want to logout?\n\n"
            << "1. Yes\n"
            << "2. No\n" << endl;
        cout << "Option: ";
        cin >> opt;
        if (opt == 1) {
            adminLogin();
        }
        else if (opt == 2) {
            adminInterface();
        }
        else {
            cout << "\n--------------------------------------------------------------------" << endl;
            cout << "\n ---------------" << endl;
            cout << "| Invalid Input |" << endl;
            cout << " ---------------\n" << endl;
            cout << "--------------------------------------------------------------------\n" << endl;
            goto loop;
        }
    }
    else if (opt == 6) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        system("pause");
        adminInterface();
    }
}
void exitMessage() {
    cout << "\n--------------------------------------------------------------------\n" << endl;
    cout << " --------------------------------" << endl;
    cout << "| Thanks for using this service! |" << endl;
    cout << " --------------------------------\n" << endl;
    system("pause");
    exit(0);

}

void showDoctorsbefore() {
    fstream fileDoc("doctorinfo.txt");
    fileDoc.seekg(0);
    int age, xp, count = 0;
    string docid, fn, ln, city, specialization;
    while (fileDoc >> docid >> fn >> ln >> age >> city >> specialization >> xp) {
        count++;
        cout << " - Doctor ID: " << docid << endl
            << "    - Doctor Name: " << fn << " " << ln << endl
            << "    - Specialization: " << specialization << endl;
        cout << "\n----------------------------------\n" << endl;
    }
    if (count == 0) {
        cout << "\nNo Doctor Profiles Found!\n" << endl;
    }
    fileDoc.close();

}

void addDoc() {
    doctor dclass;
addDocLoop:
    system("cls");
    title();
    cout << "-------------------- << Add Doctors Profiles >> --------------------\n" << endl;
    cout << "\n\t\t-----------------------------------\n" << endl;
    cout << "\t\t  Fill all the below information!" << endl;
    cout << "\n\t\t-----------------------------------\n" << endl;
    cout << "\nDoctor ID: ";
    cin >> dclass.doc_docid;
    cout << "---" << endl;
    cout << "\nFirst Name: ";
    cin >> dclass.doc_fn;
    cout << "---" << endl;
    cout << "\nLast Name: ";
    cin >> dclass.doc_ln;
    cout << "---" << endl;
    cout << "\nAge: ";
    cin >> dclass.doc_age;
    cout << "---" << endl;
    cout << "\nCity: ";
    cin >> dclass.doc_city;
    cout << "---" << endl;
    string docspecs = dclass.docSpecs(); //calling doctor specialization
    cout << "---" << endl;
    cout << "\nExperience (Years): ";
    cin >> dclass.doc_xp;

    //addingprocess
    fstream fileDoc;
    fileDoc.open("doctorinfo.txt", ios::app);
    fileDoc.seekp(0, ios::end);
    fileDoc << dclass.doc_docid << endl << dclass.doc_fn << endl << dclass.doc_ln << endl << dclass.doc_age << endl << dclass.doc_city << endl << docspecs << endl << dclass.doc_xp << endl;
    fileDoc.close();
    //doneprocessing
    cout << "\n--------------------------------------------------------------------\n" << endl;
    cout << " --------------------------------------" << endl;
    cout << "| Doctor Profile Created Successfully! |" << endl;
    cout << " --------------------------------------\n" << endl;
wrongInputLoop:
    system("pause");
    title();
    cout << "--------------------- << Add Appointments >> ---------------------\n" << endl;
    //return or
    cout << "1. Add another doctor profile\n"
        << "2. Return to 'Manage Doctor Details'\n"
        << "3. Return to 'Main Menu'\n"
        << "4. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        goto addDocLoop;
    }
    else if (opt == 2) {
        changeDoctorDetails();
    }
    else if (opt == 3) {
        adminInterface();
    }
    else if (opt == 4) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        goto wrongInputLoop;
    }
}

void changeDoc(doctor& docspecedit) {
    string id;
enterdocid: //goto loop
    system("cls");
    title();
    cout << "------------------ << Change Doctors Profiles >> ------------------\n" << endl;
    showDoctorsbefore();
    cout << "Enter the Doctor Profile ID you want to edit: ";
    cin >> id;
    cout << "\n--------------------------------------------------------------------\n" << endl;
    fstream fileDoc("doctorinfo.txt");
    fileDoc.seekg(0);

    int age, xp, count = 0;
    string docid, fn, ln, city, specialization;
    while (fileDoc >> docid >> fn >> ln >> age >> city >> specialization >> xp)
    {
        if (docid == id) {
            cout << "1. ID:" << docid << endl
                << "2. First Name: " << fn << endl
                << "3. Last Name: " << ln << endl
                << "4. Age: " << age << endl
                << "5. City: " << city << endl
                << "6. Specialization: " << specialization << endl
                << "7. Experience: " << xp << endl;
            cout << "\n--------------------------------------------------------------------\n" << endl;
            count++;
            break;
        }
    }
    fileDoc.close();
    if (count == 0) {
        cout << " ----------------------------" << endl;
        cout << "| No Matching Records Found! |" << endl;
        cout << " ----------------------------\n" << endl;
    wrongInputLoop:
        system("pause");
        title();
        cout << "------------------ << Change Doctors Profiles >> ------------------\n" << endl;
        cout << "1. Re-Enter the Doctor Profile ID you want to edit\n"
            << "2. Return to 'Manage Doctor Details'\n"
            << "3. Return to 'Main Menu'\n"
            << "4. Exit\n"
            << "\nOption: ";
        cin >> opt;
        if (opt == 1) {
            goto enterdocid;
        }
        else if (opt == 2) {
            changeDoctorDetails();
        }
        else if (opt == 3) {
            adminInterface();
        }
        else if (opt == 4) {
            exitMessage();
        }
        else {
            cout << "\n--------------------------------------------------------------------" << endl;
            cout << "\n ---------------------------------------------" << endl;
            cout << "| Invalid Input, Please input a valid number! |" << endl;
            cout << " ---------------------------------------------\n" << endl;
            goto wrongInputLoop;
        }
    }
    //edited data transfer
    fstream doctxts("doctorinfo.txt");
    doctxts.seekg(0, ios::beg);
    doctxts.seekg(0);
    string docLine;
    ofstream docTemp;
    docTemp.open("doctemp.txt");
    docTemp._Seekbeg(0, ios::in | ios::out);
    docTemp.seekp(0);
    int docs = 0;
    int tage, txp;
    string tfn, tln, tcity, tspecialization;
    doctxts.seekg(0);
    doctxts.seekg(0, ios::cur);
    while (doctxts >> docLine >> tfn >> tln >> tage >> tcity >> tspecialization >> txp)
    {
        if (docLine != id) {
            docTemp << docLine << endl << tfn << endl << tln << endl << tage << endl << tcity << endl << tspecialization << endl << txp << endl;
        }
    }
    doctxts.close();
    docTemp.close();
    remove("doctorinfo.txt");
    int replacetxt;
    char temp[] = "doctemp.txt";
    char newtxt[] = "doctorinfo.txt";
    replacetxt = rename(temp, newtxt);

    int editdoc;
    cout << "Enter the field you want to edit: ";
    cin >> editdoc;
    cout << "\n--------------------------------------------------------------------\n" << endl;
    switch (editdoc) {
    case 1: {
        cout << "Change ID to: ";
        cin >> docid;
        break;
    }
    case 2: {
        cout << "Change First Name to: ";
        cin >> fn;
        break;
    }
    case 3: {
        cout << "Change Last Name to: ";
        cin >> ln;
        break;
    }
    case 4: {
        cout << "Change Age to: ";
        cin >> age;
        break;
    }
    case 5: {
        cout << "Change City to: ";
        cin >> city;
        break;
    }
    case 6: {
        specialization = docspecedit.docSpecs();
        break;
    }
    case 7: {
        cout << "Experience: ";
        cin >> xp;
        break;
    }
    default: {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        exit(0);
        //goto docswitch;
    }
    }
    cout << "\n--------------------------------------------------------------------\n" << endl;
    cout << "\n -------------------------------" << endl;
    cout << "| Profile Updated Successfully! |" << endl;
    cout << " -------------------------------\n" << endl;
    system("pause");
    title();
    cout << "------------------ << Change Doctors Profiles >> ------------------\n" << endl;
    cout << "1. Doctor ID: " << docid << endl << "2. First Name: " << fn << endl << "3. Last Name: " << ln << endl << "4. Age: " << age << endl << "5. City: " << city << endl << "6. Specialization: " << specialization << endl << "7. Experience: " << xp << endl << endl;
    cout << "--------------------------------------------------------------------\n" << endl;
    //updated
    fstream updatedoctxts;
    updatedoctxts.open("doctorinfo.txt", ios::app);
    updatedoctxts.seekp(0, ios::end);
    updatedoctxts << docid << endl << fn << endl << ln << endl << age << endl << city << endl << specialization << endl << xp << endl;
    updatedoctxts.close();

    //return to
wrongInputLoop2:
    cout << "1. Edit a Doctor Profile\n"
        << "2. Return to 'Manage Doctor Details'\n"
        << "3. Return to 'Main Menu'\n"
        << "4. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        //changeDoc();
        goto enterdocid;
    }
    else if (opt == 2) {
        changeDoctorDetails();
    }
    else if (opt == 3) {
        adminInterface();
    }
    else if (opt == 4) {
        exitMessage();
    }
    else {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto wrongInputLoop2; //looping 4 options again.
    }
}

void showAppointmentsbefore() {
    fstream appDoc("doctorappointments.txt");
    appDoc.seekg(0);
    int appyear, appday, count = 0;
    string appid, pfn, pln, appdocid, appdocfn, appdocln, appmonth, apptime;
    while (appDoc >> appid >> pfn >> pln >> appdocid >> appdocfn >> appdocln >> appyear >> appmonth >> appday >> apptime) {
        count++;
        cout << " - Appointment ID: " << appid << endl
            << "    - Patient Name: " << pfn << " " << pln << endl
            << "    - Doctor Name: " << appdocfn << " " << appdocln << endl;
        cout << "\n----------------------------------\n" << endl;
    }
    if (count == 0) {
        cout << "\nNo Doctor Profiles Found!\n" << endl;
    }
    appDoc.close();
}

void deleteDoc() {
    system("cls");
    title();
    cout << "------------------ << Delete Doctors Profiles >> ------------------\n" << endl;
    showDoctorsbefore();
    string idinput;
    cout << "Enter the Doctor ID you want to delete: ";
    cin >> idinput;
    cout << "\n--------------------------------------------------------------------" << endl;
    fstream fileDoc("doctorinfo.txt");
    fileDoc.seekg(0);
    int age, xp, count = 0;
    string docid, fn, ln, city, specialization;
    while (fileDoc >> docid >> fn >> ln >> age >> city >> specialization >> xp) {
        if (docid == idinput) {
            cout << "\n1. ID: " << docid << endl << "2. First Name: " << fn << endl << "3. Last Name: " << ln << endl << "4. Age: " << age << endl << "5. City: " << city << endl << "6. Specialization: " << specialization << endl << "7. Experience: " << xp << endl;
            cout << "\n-------------------------------------\n" << endl;
            count++;
            break;
        }
    }
    fileDoc.close();
    if (count == 0) {
        cout << "\n ----------------------------" << endl;
        cout << "| No Matching Records Found! |" << endl;
        cout << " ----------------------------\n" << endl;
    reenter: //goto function
        system("pause");
        title();
        cout << "------------------ << Delete Doctors Profiles >> ------------------\n" << endl;
        cout << "1. Enter the Doctor Profile ID you want to delete\n"
            << "2. Return to 'Manage Doctor Details'\n"
            << "3. Return to 'Main Menu'\n"
            << "4. Exit\n"
            << "\nOption: ";
        cin >> opt;
        if (opt == 1) {
            deleteDoc();
        }
        else if (opt == 2) {
            changeDoctorDetails();
        }
        else if (opt == 3) {
            adminInterface();
        }
        else if (opt == 4) {
            exitMessage();
        }
        else {
            cout << "\n--------------------------------------------------------------------" << endl;
            cout << "\n ---------------------------------------------" << endl;
            cout << "| Invalid Input, Please input a valid number! |" << endl;
            cout << " ---------------------------------------------\n" << endl;
            goto reenter; //goto function to loop the re-enter part
        }
    }
confirmdelete: //goto function
    cout << "Confirm you want to delete this profile\n\n"
        << "1. Yes\n"
        << "2. No\n\n"
        << "Option: ";
    cin >> opt;
    if (opt == 1) {
        fstream doctxts("doctorinfo.txt");
        doctxts.seekg(0, ios::beg);
        doctxts.seekg(0);
        string docLine;
        ofstream docTemp;
        docTemp.open("doctemp.txt");
        docTemp._Seekbeg(0, ios::in | ios::out);
        docTemp.seekp(0);
        int skip = 0;
        int tage, txp;
        string tfn, tln, tcity, tspecialization;
        doctxts.seekg(0);
        doctxts.seekg(0, ios::cur);//What is cur? it sets the pointer to the beginning of the text file
        while (doctxts >> docLine >> tfn >> tln >> tage >> tcity >> tspecialization >> txp) {
            if (docLine != idinput) {
                docTemp << docLine << endl << tfn << endl << tln << endl << tage << endl << tcity << endl << tspecialization << endl << txp << endl;
            }
        }
        //delete current doctorinfo.txt and replaces it with the temp file.
        doctxts.close();
        docTemp.close();
        remove("doctorinfo.txt");
        int replacetxt;
        char temp[] = "doctemp.txt";
        char newtxt[] = "doctorinfo.txt";
        replacetxt = rename(temp, newtxt);

        cout << "\n--------------------------------------------------------------------\n" << endl;
        cout << " --------------------------------------" << endl;
        cout << "| Doctor Profile Deleted Successfully! |" << endl;
        cout << " --------------------------------------\n" << endl;
        goto reenter; //goto function to loop the re-enter.


    }
    else if (opt == 2) {
        cout << "\n--------------------------------------------------------------------\n" << endl;
        goto reenter; //goto function to loop the re-enter part
    }
    else {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto confirmdelete; //goto function to loop the confirm part.
    }
}

void showDoc() {
    system("cls");
    title();
    cout << "------------------ << View Doctors Profiles >> ------------------\n" << endl;
    fstream fileDoc("doctorinfo.txt");
    fileDoc.seekg(0);
    int age, xp, count = 0;
    string docid, fn, ln, city, specialization;
    while (fileDoc >> docid >> fn >> ln >> age >> city >> specialization >> xp) {
        count++;
        cout << " - Doctor ID: " << docid << endl
            << "    - Doctor Name: " << fn << " " << ln << endl
            << "    - Specialization: " << specialization << endl;
        cout << "\n----------------------------------\n" << endl;
    }
    if (count == 0)
    {
        cout << "\nNo Doctor Profiles Found!" << endl;
    }
    fileDoc.close();
retryloop2:
    cout << "1. Search Doctor Profile by ID\n"
        << "2. View All Doctors Profiles - Extended\n"
        << "3. Return to 'Manage Doctor Details'\n"
        << "4. Return to 'Main Menu'\n"
        << "5. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        searchDoctorsProfiles();
    }
    else if (opt == 2) {
        viewAllDoctorsProfiles();
    }
    else if (opt == 3) {
        changeDoctorDetails();
    }
    else if (opt == 4) {
        adminInterface();
    }
    else if (opt == 5) {
        exitMessage();
    }
    else {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto retryloop2; //goto function to loop the re-enter part
    }
}
void searchDoctorsProfiles() {
    string inputid;
    cout << "\n-------------------- << Find Doctor Profile >> --------------------" << endl;
    cout << "\nEnter the Doctor Profile ID you want to find: ";
    cin >> inputid;
    system("cls");
    title();
    cout << "\n-------------------- << Find Doctor Profile >> --------------------" << endl;
    ifstream doctxts;
    doctxts.open("doctorinfo.txt", ios::out | ios::in);
    doctxts.seekg(0);
    int age, xp, count = 0;
    string docid, fn, ln, city, specialization;
    while (doctxts >> docid >> fn >> ln >> age >> city >> specialization >> xp) {
        if (docid == inputid) {
            cout << " - Doctor ID: " << docid
                << "\n    - Doctor First Name: " << fn
                << "\n    - Doctor Last Name: " << ln
                << "\n    - Doctor Age: " << age
                << "\n    - Doctor City: " << city
                << "\n    - Doctor Specialization: " << specialization
                << "\n    - Doctor Experience: " << xp << endl;
            cout << "\n--------------------------------------------------------------------\n" << endl;
            count++;
        }
    }
    doctxts.close();
    if (count == 0) {
        cout << "\n ----------------------------" << endl;
        cout << "| No Matching Records Found! |" << endl;
        cout << " ----------------------------\n" << endl;
    }
retryloop3:
    cout << "1. View All Doctor Profiles - Extended\n"
        << "2. Return to 'View Doctor Profiles'\n"
        << "3. Return to 'Manage Doctor Details'\n"
        << "4. Return to 'Main Menu'\n"
        << "5. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        viewAllDoctorsProfiles();
    }
    else if (opt == 2) {
        showDoc();
    }
    else if (opt == 3) {
        changeDoctorDetails();
    }
    else if (opt == 4) {
        adminInterface();
    }
    else if (opt == 5) {
        exitMessage();
    }
    else {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto retryloop3;
    }
}

void viewAllDoctorsProfiles() {
    system("cls");
    title();
    cout << "------------------ << View All Doctor Profiles >> ------------------\n" << endl;
    fstream fileDoc("doctorinfo.txt");
    fileDoc.seekg(0);
    int age, xp, count = 0;
    string docid, fn, ln, city, specialization;
    while (fileDoc >> docid >> fn >> ln >> age >> city >> specialization >> xp) {
        count++;
        cout << " - Doctor ID: " << docid
            << "\n    - Doctor First Name: " << fn
            << "\n    - Doctor Last Name: " << ln
            << "\n    - Doctor Age: " << age
            << "\n    - Doctor City: " << city
            << "\n    - Doctor Specialization: " << specialization
            << "\n    - Doctor Experience: " << xp << endl;
        cout << "\n-------------------------------------\n" << endl;
    }
    if (count == 0) {
        cout << "\nNo Doctor Profiles Found!\n" << endl;
    }
    fileDoc.close();
retryloop1:
    cout << "1. Return to 'View Doctor Profiles'\n"
        << "2. Return to 'Main Menu'\n"
        << "3. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        showDoc();
    }
    else if (opt == 2) {
        adminInterface();
    }
    else if (opt == 3) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        goto retryloop1;
    }
}

void addAppointments() {
    appointments aclass;
addAppLoop:
    system("cls");
    title();
    cout << "--------------------- << Add Appointments >> ---------------------\n" << endl;
    cout << "\n\t\t-----------------------------------\n" << endl;
    cout << "\t\t  Fill all the below information!" << endl;
    cout << "\n\t\t-----------------------------------\n" << endl;
    cout << "\nAppointment ID: ";
    cin >> aclass.appID;
    cout << "---" << endl;
    cout << "\nPatient First Name: ";
    cin >> aclass.patientfn;
    cout << "---" << endl;
    cout << "\nPatient Last Name: ";
    cin >> aclass.patientln;
    cout << "---" << endl;
    cout << "\nDoctor ID: ";
    cin >> aclass.docidApp;
    cout << "---" << endl;
    cout << "\nDoctor First Name: ";
    cin >> aclass.docfirstName;
    cout << "---" << endl;
    cout << "\nDoctor Last Name: ";
    cin >> aclass.doclastName;
    cout << "---" << endl;
    cout << "\nAppointment Year: ";
    cin >> aclass.appYear;
    cout << "---" << endl;
    cout << "\nAppointment Month: ";
    cin >> aclass.appMonth;
    cout << "---" << endl;
    cout << "\nAppointment Day: ";
    cin >> aclass.appDay;
    cout << "---" << endl;
    string apptimeselectt = aclass.appTimeSelection();

    // importing to txt
    fstream appDoc;
    appDoc.open("doctorappointments.txt", ios::app);
    appDoc.seekp(0, ios::end);
    appDoc << aclass.appID << endl << aclass.patientfn << endl << aclass.patientln << endl << aclass.docidApp << endl << aclass.docfirstName << endl << aclass.doclastName << endl << aclass.appYear << endl << aclass.appMonth << endl << aclass.appDay << endl << apptimeselectt << endl;
    appDoc.close();
    //imported to txt
    cout << "\n--------------------------------------------------------------------\n" << endl;
    cout << " ---------------------------------" << endl;
    cout << "| Appointment Added Successfully! |" << endl;
    cout << " ---------------------------------\n" << endl;
wrongAddAppLoop:
    system("pause");
    title();
    cout << "--------------------- << Add Appointments >> ---------------------\n" << endl;
    cout << "1. Add another appointment\n"
        << "2. Return to 'Manage Appointment Details'\n"
        << "3. Return to 'Main Menu'\n"
        << "4. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        goto addAppLoop;
    }
    else if (opt == 2) {
        changeDoctorAppointments();
    }
    else if (opt == 3) {
        adminInterface();
    }
    else if (opt == 4) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        goto wrongAddAppLoop;
    }
}

void changeAppointments(appointments& appointmentsedit) {
    string inputid;
enterappid:
    system("cls");
    title();
    cout << "----------------- << Change Appointment Details >> -----------------\n" << endl;
    showAppointmentsbefore();
    cout << "Enter the Appointment ID you want to edit: ";
    cin >> inputid;
    cout << "\n--------------------------------------------------------------------\n" << endl;
    fstream appDoc("doctorappointments.txt");
    appDoc.seekg(0);

    int appyear, appday, count = 0;
    string appid, pfn, pln, appdocid, appdocfn, appdocln, appmonth, apptime;
    while (appDoc >> appid >> pfn >> pln >> appdocid >> appdocfn >> appdocln >> appyear >> appmonth >> appday >> apptime) {
        if (appid == inputid) {
            cout << "1. Appointment ID: " << appid << endl
                << "2. Patient First Name: " << pfn << endl
                << "3. Patient Last Name: " << pln << endl
                << "4. Doctor ID: " << appdocid << endl
                << "5. Doctor First Name: " << appdocfn << endl
                << "6. Doctor Last Name: " << appdocln << endl
                << "7. Appointment Year: " << appyear << endl
                << "8. Appointment Month: " << appmonth << endl
                << "9. Appointment Day: " << appday << endl
                << "10. Appointment Time [Morning / Evening]: " << apptime << endl;
            cout << "\n--------------------------------------------------------------------\n" << endl;
            count++;
            break;
        }
    }
    appDoc.close();
    if (count == 0) {
        cout << " ----------------------------" << endl;
        cout << "| No Matching Records Found! |" << endl;
        cout << " ----------------------------\n" << endl;
    wrongInputALoop:
        system("pause");
        title();
        cout << "----------------- << Change Appointment Details >> -----------------\n" << endl;
        cout << "1. Re-Enter the Appointment ID you want to edit\n"
            << "2. Return to Manage Appointment Details\n"
            << "3. Return to Main Menu\n"
            << "4. Exit\n"
            << "\nOption: ";
        cin >> opt;
        if (opt == 1) {
            goto enterappid;
        }
        else if (opt == 2) {
            changeDoctorAppointments();
        }
        else if (opt == 3) {
            adminInterface();
        }
        else if (opt == 4) {
            exitMessage();
        }
        else {
            cout << "\n--------------------------------------------------------------------" << endl;
            cout << "\n ---------------------------------------------" << endl;
            cout << "| Invalid Input, Please input a valid number! |" << endl;
            cout << " ---------------------------------------------\n" << endl;
            goto wrongInputALoop;
        }
    }
    //transfering edited data
    fstream apptxts("doctorappointments.txt");
    apptxts.seekg(0, ios::beg);
    apptxts.seekg(0);
    string docLine;
    ofstream appTemp;
    appTemp.open("apptemp.txt");
    appTemp._Seekbeg(0, ios::in | ios::out);
    appTemp.seekp(0);
    int docs = 0;
    int tappyear, tappday;
    string tpfn, tpln, tappdocid, tappdocfn, tappdocln, tappmonth, tapptime;
    apptxts.seekg(0);
    apptxts.seekg(0, ios::cur);
    while (apptxts >> docLine >> tpfn >> tpln >> tappdocid >> tappdocfn >> tappdocln >> tappyear >> tappmonth >> tappday >> tapptime) {
        if (docLine != inputid) {
            appTemp << docLine << endl << tpfn << endl << tpln << endl << tappdocid << endl << tappdocfn << endl << tappdocln << endl << tappyear << endl << tappmonth << endl << tappday << endl << tapptime << endl;
        }
    }
    apptxts.close();
    appTemp.close();
    remove("doctorappointments.txt");
    int replaceapptxt;
    char apptemp[] = "apptemp.txt";
    char newapptxt[] = "doctorappointments.txt";
    replaceapptxt = rename(apptemp, newapptxt);

changeapploop:
    int editapp;
    cout << "Enter the Field you want to edit: ";
    cin >> editapp;
    cout << "\n--------------------------------------------------------------------\n" << endl;
    switch (editapp) {
    case 1: {
        cout << "Change Appointment ID to: ";
        cin >> appid;
        break;
    }
    case 2: {
        cout << "Change Patient First Name to: ";
        cin >> pfn;
        break;
    }
    case 3: {
        cout << "Change Patient Last Name to: ";
        cin >> pln;
        break;
    }
    case 4: {
        cout << "Change Doctor ID to: ";
        cin >> appdocid;
        break;
    }
    case 5: {
        cout << "Change Doctor First Name to: ";
        cin >> appdocfn;
        break;
    }
    case 6: {
        cout << "Change Doctor Last Name to: ";
        cin >> appdocln;
        break;
    }
    case 7: {
        cout << "Change Appointment Year to: ";
        cin >> appyear;
        break;
    }
    case 8: {
        cout << "Change Appointment Month to: ";
        cin >> appmonth;
        break;
    }
    case 9: {
        cout << "Change Appointment Day to: ";
        cin >> appday;
        break;
    }
    case 10: {
        apptime = appointmentsedit.appTimeSelection();
        break;
    }
    default: {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto changeapploop;
    }
    }
    cout << "\n--------------------------------------------------------------------\n" << endl;
    cout << " -------------------------------" << endl;
    cout << "| Profile Updated Successfully! |" << endl;
    cout << " -------------------------------\n" << endl;
    system("pause");
    title();
    cout << "----------------- << Updated Appointment Details >> -----------------\n" << endl;
    cout << "1. Appointment ID: " << appid << endl << "2. Patient First Name: " << pfn << endl << "3. Patient Last Name: " << pln << endl << "4. Doctor ID: " << appdocid << endl << "5. Doctor First Name: " << appdocfn << endl << "6. Doctor Last Name: " << appdocln << endl << "7. Appointment Year: " << appyear << endl << "8. Appointment Month: " << appmonth << endl << "9. Appintment Day: " << appday << endl << "10. Appointment Time [Morning / Evening]: " << apptime << endl << endl;
    cout << "--------------------------------------------------------------------\n" << endl;
    //updated
    fstream updateapptxts;
    updateapptxts.open("doctorappointments.txt", ios::app);
    updateapptxts.seekp(0, ios::end);
    updateapptxts << appid << endl << pfn << endl << pln << endl << appdocid << endl << appdocfn << endl << appdocln << endl << appyear << endl << appmonth << endl << appday << endl << apptime << endl;
    updateapptxts.close();

    //return to
wrongInputALoop2:
    cout << "1. Enter the Appointment ID you want to edit\n"
        << "2. Return to Manage Appointment Details\n"
        << "3. Return to Main Menu\n"
        << "4. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        goto enterappid;
    }
    else if (opt == 2) {
        changeDoctorAppointments();
    }
    else if (opt == 3) {
        adminInterface();
    }
    else if (opt == 4) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        goto wrongInputALoop2; //looping 4 options again.
    }
}

void deleteDoctorAppointments() {
    system("cls");
    title();
    cout << "-------------------- << Delete Appointments >> --------------------\n\n" << endl;
    showAppointmentsbefore();
    string idinput;
    cout << "Enter the Appointment ID you want to delete: ";
    cin >> idinput;
    cout << "\n--------------------------------------------------------------------" << endl;
    fstream appDoc("doctorappointments.txt");
    appDoc.seekg(0);
    int appyear, appday, count = 0;
    string appid, pfn, pln, appdocid, appdocfn, appdocln, appmonth, apptime;
    while (appDoc >> appid >> pfn >> pln >> appdocid >> appdocfn >> appdocln >> appyear >> appmonth >> appday >> apptime) {
        if (appid == idinput) {
            cout << "\n1. Appointment ID: " << appid << endl << "2. Patient First Name: " << pfn << endl << "3. Patient Last Name: " << pln << endl << "4. Doctor ID: " << appdocid << endl << "5. Doctor First Name: " << appdocfn << endl << "6. Doctor Last Name: " << appdocln << endl << "7. Appointment Year: " << appyear << endl << "8. Appointment Month: " << appmonth << endl << "9. Appointment Day: " << appday << endl << "10. Appointment Time [Morning / Evening]: " << apptime << endl;
            cout << "\n-------------------------------------\n" << endl;
            count++;
            break;
        }
    }
    appDoc.close();
    if (count == 0) {
        cout << " ----------------------------" << endl;
        cout << "| No Matching Records Found! |" << endl;
        cout << " ----------------------------\n" << endl;
    reenterapp:
        system("pause");
        title();
        cout << "-------------------- << Delete Appointments >> --------------------\n" << endl;
        cout << "1. Enter the Appointment ID you want to delete\n"
            << "2. Return to Manage Appointment Details\n"
            << "3. Return to Main Menu\n"
            << "4. Exit\n"
            << "\nOption: ";
        cin >> opt;
        if (opt == 1) {
            deleteDoctorAppointments();
        }
        else if (opt == 2) {
            changeDoctorAppointments();
        }
        else if (opt == 3) {
            adminInterface();
        }
        else if (opt == 4) {
            exitMessage();
        }
        else {
            cout << "\n--------------------------------------------------------------------" << endl;
            cout << "\n ---------------------------------------------" << endl;
            cout << "| Invalid Input, Please input a valid number! |" << endl;
            cout << " ---------------------------------------------\n" << endl;
            goto reenterapp; //goto function to loop the re-enter part
        }
    }
confirmAppDelete:
    cout << "Confirm you want to delete this appointment\n\n"
        << "1. Yes\n"
        << "2. No\n\n"
        << "Option: ";
    cin >> opt;
    if (opt == 1) {
        fstream apptxts("doctorappointments.txt");
        apptxts.seekg(0, ios::beg);
        apptxts.seekg(0);
        string docLine;
        ofstream appTemp;
        appTemp.open("apptemp.txt");
        appTemp._Seekbeg(0, ios::in | ios::out);
        appTemp.seekp(0);
        int skip = 0;
        int tappyear, tappday;
        string tpfn, tpln, tappdocid, tappdocfn, tappdocln, tappmonth, tapptime;
        apptxts.seekg(0);
        apptxts.seekg(0, ios::cur);
        while (apptxts >> docLine >> tpfn >> tpln >> tappdocid >> tappdocfn >> tappdocln >> tappyear >> tappmonth >> tappday >> tapptime) {
            if (docLine != idinput) {
                appTemp << docLine << endl << tpfn << endl << tpln << endl << tappdocid << endl << tappdocfn << endl << tappdocln << endl << tappyear << endl << tappmonth << endl << tappday << endl << tapptime << endl;
            }
        }
        apptxts.close();
        appTemp.close();
        remove("doctorappointments.txt");
        int replaceapptxt;
        char apptemp[] = "apptemp.txt";
        char newapptxt[] = "doctorappointments.txt";
        replaceapptxt = rename(apptemp, newapptxt);

        cout << "\n--------------------------------------------------------------------\n" << endl;
        cout << " -----------------------------------" << endl;
        cout << "| Appointment Deleted Successfully! |" << endl;
        cout << " -----------------------------------\n" << endl;
        goto reenterapp;
    }
    else if (opt == 2) {
        cout << "\n--------------------------------------------------------------------\n" << endl;
        goto reenterapp;
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        goto confirmAppDelete;
    }
}

void showDoctorAppointments() {
    system("cls");
    title();
    cout << "------------------ << View Appointment Details >> ------------------\n\n" << endl;
    fstream appDoc("doctorappointments.txt");
    appDoc.seekg(0);
    int appyear, appday, count = 0;
    string appid, pfn, pln, appdocid, appdocfn, appdocln, appmonth, apptime;
    while (appDoc >> appid >> pfn >> pln >> appdocid >> appdocfn >> appdocln >> appyear >> appmonth >> appday >> apptime) {
        count++;
        cout << " - Appointment ID: " << appid << endl
            << "    - Patient Name: " << pfn << " " << pln << endl
            << "    - Doctor Name: " << appdocfn << " " << appdocln << endl
            << "    - Appointment Date: " << appday << " " << appmonth << " " << appyear << endl
            << "    - Appointment Time: " << apptime << endl;
        cout << "\n----------------------------------\n" << endl;
    }
    if (count == 0) {
        cout << "\nNo Doctor Profiles Found!\n" << endl;
    }
    appDoc.close();
retryloop1:
    cout << "1. Search Doctor Appointments by ID\n"
        << "2. View All Appointments (Extended Information)\n"
        << "3. Return to Manage Appointment Details\n"
        << "4. Return to Main Menu\n"
        << "5. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        searchDoctorAppointments();
    }
    else if (opt == 2) {
        viewAllDoctorAppointments();
    }
    else if (opt == 3) {
        changeDoctorAppointments();
    }
    else if (opt == 4) {
        adminInterface();
    }
    else if (opt == 5) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        system("pause");
        showDoctorAppointments();
    }
}

void viewAllDoctorAppointments() {
    system("cls");
    title();
    cout << "---------------- << View All Appointment Details >> ----------------\n" << endl;
    fstream appDoc("doctorappointments.txt");
    appDoc.seekg(0);
    int appyear, appday, count = 0;
    string appid, pfn, pln, appdocid, appdocfn, appdocln, appmonth, apptime;
    while (appDoc >> appid >> pfn >> pln >> appdocid >> appdocfn >> appdocln >> appyear >> appmonth >> appday >> apptime) {
        count++;
        cout << " - Appointment ID: " << appid << endl
            << "    - Patient First Name: " << pfn << endl
            << "    - Patient Last Name: " << pln << endl
            << "    - Doctor ID: " << appdocid << endl
            << "    - Doctor First Name: " << appdocfn << endl
            << "    - Doctor Last Name: " << appdocln << endl
            << "    - Appointment Year: " << appyear << endl
            << "    - Appointment Month: " << appmonth << endl
            << "    - Appointment Day: " << appday << endl
            << "    - Appointment Time [Morning / Evening]: " << apptime << endl;
        cout << "\n-------------------------------------\n" << endl;
    }
    if (count == 0) {
        cout << "\nNo Doctor Profiles Found!\n" << endl;
    }
    appDoc.close();
retryloop1:
    cout << "1. Return to Manage Appointment Details\n"
        << "2. Return to Main Menu\n"
        << "3. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        changeDoctorAppointments();
    }
    else if (opt == 2) {
        adminInterface();
    }
    else if (opt == 3) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        goto retryloop1;
    }
}

void searchDoctorAppointments() {
    string inputid;
    cout << "\n---------------------- << Find Appointment >> ----------------------" << endl;
    cout << "\nEnter the Appointment ID you want to find: ";
    cin >> inputid;
    system("cls");
    title();
    cout << "---------------------- << Find Appointment >> ----------------------\n\n" << endl;
    ifstream apptxts;
    apptxts.open("doctorappointments.txt", ios::out | ios::in);
    apptxts.seekg(0);
    int appyear, appday, count = 0;
    string appid, pfn, pln, appdocid, appdocfn, appdocln, appmonth, apptime;
    while (apptxts >> appid >> pfn >> pln >> appdocid >> appdocfn >> appdocln >> appyear >> appmonth >> appday >> apptime) {
        if (appid == inputid) {
            cout << " - Appointment ID: " << appid
                << "\n    - Patient First Name: " << pfn
                << "\n    - Patient Last Name: " << pln
                << "\n    - Doctor ID: " << appdocid
                << "\n    - Doctor First Name: " << appdocfn
                << "\n    - Doctor Last Name: " << appdocln
                << "\n    - Appointment Year: " << appyear
                << "\n    - Appointment Month: " << appmonth
                << "\n    - Appointment Day: " << appday
                << "\n    - Appointment Time [Morning / Evening]: " << apptime << endl;
            cout << "\n--------------------------------------------------------------------\n" << endl;
            count++;
        }
    }
    apptxts.close();
    if (count == 0) {
        cout << "\n ----------------------------" << endl;
        cout << "| No Matching Records Found! |" << endl;
        cout << " ----------------------------\n" << endl;
    }
retryloop2:
    cout << "1. View All Appointments (Extended Information)\n"
        << "2. Return to Show All Appointments\n"
        << "3. Return to Manage Appointment Details\n"
        << "4. Return to Main Menu\n"
        << "5. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        viewAllDoctorAppointments();
    }
    else if (opt == 2) {
        showDoctorAppointments();
    }
    else if (opt == 3) {
        changeDoctorAppointments();
    }
    else if (opt == 4) {
        adminInterface();
    }
    else if (opt == 5) {
        exitMessage();
    }
    else {
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        goto retryloop2;
    }
}

void changeDoctorDetails() {
    system("cls");
    title();
    cout << "------------------- << Manage Doctor Details >> -------------------\n" << endl;
    cout << "1. Add Doctor Profile\n"
        << "2. Change Doctor Profile\n"
        << "3. Delete Doctor Profile\n"
        << "4. Show All Doctors Profiles\n"
        << "5. Return to Main Menu\n"
        << "6. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        addDoc();
    }
    else if (opt == 2) {
        doctor doccls;
        changeDoc(doccls);
    }
    else if (opt == 3) {
        deleteDoc();
    }
    else if (opt == 4) {
        showDoc();
    }
    else if (opt == 5) {
        adminInterface();
    }
    else if (opt == 6) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        system("pause");
        changeDoctorDetails();
    }
}
void changeDoctorAppointments() {
    system("cls");
    title();
    cout << "---------------- << Manage Appointments Details >> ----------------\n" << endl;
cddloop:
    cout << "1. Add Appointments\n"
        << "2. Change Appointments\n"
        << "3. Delete Appointments\n"
        << "4. View All Appointments\n"
        << "5. Return to Main Menu\n"
        << "6. Exit\n"
        << "\nOption: ";
    cin >> opt;
    if (opt == 1) {
        addAppointments();
    }
    else if (opt == 2) {
        appointments appscls;
        changeAppointments(appscls);
    }
    else if (opt == 3) {
        deleteDoctorAppointments();
    }
    else if (opt == 4) {
        showDoctorAppointments();
    }
    else if (opt == 5) {
        adminInterface();
    }
    else if (opt == 6) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        system("pause");
        changeDoctorAppointments();
    }
}

void help() {
    system("cls");
    title();
    cout << "-------------------------- << Purpose >> --------------------------\n" << endl;
    cout << "+ What's the purpose of this system?" << endl;
    cout << "  - This system is created to automate the business operations of\n    'Spire Health Care Hospital' & reduce the workload of the staff." << endl;
    cout << "\n------------------------ << Navigations >> ------------------------\n" << endl;
    cout << "+ Change Available Doctor's Details" << endl;
    cout << "  - In that menu, you can add, view, edit or delete any doctor\n    profile.\n" << endl;
    cout << "+ Change Doctor Appointments" << endl;
    cout << "  - In that menu, you can add, view, edit or delete any doctor\n    appointment.\n" << endl;
    cout << "+ Hospital Details" << endl;
    cout << "  - In that menu, you can view information of the\n    'Spire Health Care Hospital'.\n" << endl;
    cout << "+ Help" << endl;
    cout << "  - In that menu, you can find instructions for how to use this\n    system.'.\n" << endl;
    cout << "+ Logout" << endl;
    cout << "  - Logout of the system.\n" << endl;
    cout << "+ Exit" << endl;
    cout << "  - Exit from the the system.\n";
    cout << "\n--------------------------------------------------------------------\n" << endl;
    cout << "1. Return to 'Main Menu'\n"
        << "2. Exit\n\n"
        << "Option: ";
    cin >> opt;
    if (opt == 1) {
        adminInterface();
    }
    else if (opt == 2) {
        exitMessage();
    }
    else {
        cout << "\n\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        system("pause");
        help();
    }
}

void hospitalDetails() {
    system("cls");
    title();
    cout << "-------------------- << Hospital Information >> --------------------" << endl;
    std::cout << R"(
                    ----------------------------
                   | Spire Health Care Hospital |
                    ----------------------------
      
 Spire Healthcare is a private hospital located in London, UK,
 that offers a wide range of medical and surgical treatments across
 various specialties.

                          ----------------
                         |   Contact us   |
                          ----------------

 Location         : London, UK
 Email            : spirehc@gmail.com
 Telephone Number : +44 0000000000
 Visit Us         : www.spirehealth.com

--------------------------------------------------------------------

1. Return to 'Main Menu'
2. Exit

Option: )";
    cin >> opt;
    if (opt == 1) {
        adminInterface();
    }
    else if (opt == 2) {
        exitMessage();
    }
    else {
        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "\n ---------------" << endl;
        cout << "| Invalid Input |" << endl;
        cout << " ---------------\n" << endl;
        cout << "--------------------------------------------------------------------\n" << endl;
        system("pause");
        hospitalDetails();
    }
}

int main() {
    title();
    adminLogin();
}

