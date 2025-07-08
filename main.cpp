#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> content;
vector<string> toupdate;

// To store the data. (Database part) Taken reference : https://java2blog.com/read-csv-file-in-cpp/

void readfile(string fname){ 
    vector<string> row;
    string line, word;

    fstream file (fname,ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
            stringstream str(line);
            while(getline(str, word, ',')) row.push_back(word);
            content.push_back(row);
        }
    }
}

void writefile(vector<vector<string>> par, string fname){  
    fstream fout(fname,ios::out);
    for(auto x:par){
        for(auto y:x){
            fout<<y;
            if(y!=x.back()) fout<<",";
        }
        fout<<"\n";
    }

}

void writefileappend(vector<string> par, string fname){  
    fstream fout(fname,ios::out | ios::app);
    for(auto x:par){
        fout<<x;
        if(x!=par.back()) fout<<",";
    }
    fout<<"\n";
}

void printdata(vector<vector<string>> par){
    int c=1;
    for(auto x:par){
        cout<<c<<". ";
        for(auto y:x){
            cout<<y;
            if(y!=x.back()) cout<<" | ";
        }
        c++;
        cout<<"\n";
    }
}

void printdata_notpassword(vector<vector<string>> par){
    int c=1;
    for(auto x:par){
        cout<<c<<". ";
        cout<<x[0]<<" | "<<x[1]<<" | "<<x[3]<< " | "<<x[4]<< '\n';
        c++;
    }
}

// Classes to be defined.

class user {

    private:
    string password;

    public:
    string name;
    string ID;
    string credit_score;
    void enter();
    void login();
    void enter_new_user();
    void see_all_cars(string ID);
    void see_issued_cars(string ID);
    void check_available(string ID,string car_name);
    int get_fine(string ID,string user_type);
    void logout();
    void clear_fine_amount(string ID,string user_type);
    void user_add(string ID);
    void user_update(string ID);
    void user_delete(string ID);
    void rent_car(string ID,string car_name,string type_user);
    void return_car(string ID,string model_num,string user_type);
    void update_credit(string ID,string condition,string user_type,int flag);
};

class Car {

    public:
    string name;
    string color;
    string model_num;
    int is_rented;

    void car_request(string ID,string car_name,string type_user);
    void show_due_date(string model_num);
    void car_add(string ID);
    void car_update(string ID);
    void car_delete(string ID);

};

class Customer: public user {
    public:
    int fine;
    void enter_customer_page(string ID);
};

class Employee: public user {
    public:
    int fine;
    void enter_employee_page(string ID);   
};

class Manager: public user {
     public:
        void enter_manager_page(string ID);
        void see_all_customers(string ID);
        void see_all_managers(string ID);
        void see_all_employees(string ID);
        void see_all_cars(string ID);
        void add_user(string ID);
        void update_user(string ID);
        void delete_user(string ID);
        void add_car(string ID);
        void update_car(string ID);
        void delete_car(string ID);
        void see_issued_to_user(string ID,string user_ID);
        void see_issued_cars(string ID,string model_num);
        void credit_update(string ID,string pmt,string user_type,int flag);
};

void Customer :: enter_customer_page(string ID){

    cout << "\n\n***************************************\n";
    cout << "\nWelcome Customer!\n\n";
    cout << "Press 1 to see all the cars.\n";
    cout << "Press 2 to view the cars issued by you.\n";
    cout << "Press 3 to check if a car is available for issue or not.\n";
    cout << "Press 4 to view the fine.\n";
    cout << "Press 5 to rent a car.\n";
    cout << "Press 6 to return a car.\n";
    cout << "Press 7 to clear your fine.\n";
    cout << "Press 8 to logout.\n\n";
    cout << "***************************************\n";

    int x;
    cin >> x;
    string car_name,model_num;
    Customer cs;
    Car c;
        switch(x){
            case 1:
                cs.see_all_cars(ID);
                cs.enter_customer_page(ID);
                break;
            case 2:
                cs.see_issued_cars(ID);
                cs.enter_customer_page(ID);
                break;
            case 3:
                cout << "Enter the name of the car, you want to check: ";
                cin.ignore();
                getline(cin,car_name);
                cs.check_available(ID,car_name);
                cs.enter_customer_page(ID);
                break;
            case 4:
                cs.get_fine(ID,"1");
                cs.enter_customer_page(ID);
                break;
            case 5:
                cout << "Enter the name of the car, you want to issue: ";
                cin.ignore();
                getline(cin,car_name);
                c.car_request(ID,car_name,"1");
                cs.enter_customer_page(ID);
                break;
            case 6:
                cout << "Enter the model number of the car, you want to return: ";
                cin >> model_num;
                cs.return_car(ID,model_num,"1");
                cs.enter_customer_page(ID);
                break;
            case 7:
                cs.clear_fine_amount(ID,"1");
                cs.enter_customer_page(ID);
                break;
            case 8:
                logout();
                break;
        }

}  

void Employee :: enter_employee_page(string ID){

    cout << "\n\n***************************************\n";
    cout << "\nWelcome our valuable Employee!\n\n";
    cout << "Press 1 to see all the cars.\n";
    cout << "Press 2 to view the cars issued by you.\n";
    cout << "Press 3 to check if a car is available for issue or not.\n";
    cout << "Press 4 to view the fine.\n";
    cout << "Press 5 to rent a car.\n";
    cout << "Press 6 to return a car.\n";
    cout << "Press 7 to clear your fine.\n";
    cout << "Press 8 to logout.\n\n";
    cout << "***************************************\n";

    int x;
    cin >> x;
    string car_name,model_num;
    Employee e;
    Car c;
        switch(x){
            case 1:
                e.see_all_cars(ID);
                e.enter_employee_page(ID);
                break;
            case 2:
                e.see_issued_cars(ID);
                e.enter_employee_page(ID);
                break;
            case 3:
                cout << "Enter the name of the car, you want to check: ";
                cin.ignore();
                getline(cin,car_name);
                e.check_available(ID,car_name);
                e.enter_employee_page(ID);
                break;
            case 4:
                e.get_fine(ID,"2");
                e.enter_employee_page(ID);
                break;
            case 5:
                cout << "Enter the name of the car, you want to issue: ";
                cin.ignore();
                getline(cin,car_name);
                c.car_request(ID,car_name,"2");
                e.enter_employee_page(ID);
                break;
            case 6:
                cout << "Enter the model number of the car, you want to return: ";
                cin >> model_num;
                e.return_car(ID,model_num,"2");
                e.enter_employee_page(ID);
                break;
            case 7:
                e.clear_fine_amount(ID,"2");
                e.enter_employee_page(ID);
                break;
            case 8:
                logout();
                break;
        }
    
} 

void Manager :: enter_manager_page(string ID){

    cout << "\n\n***************************************\n";
    cout << "\nWelcome Manager!\n\n";
    cout << "Press 1 to add a user.\n";
    cout << "Press 2 to update a user.\n";
    cout << "Press 3 to delete a user.\n";
    cout << "Press 4 to add a car.\n";
    cout << "Press 5 to update a car.\n";
    cout << "Press 6 to delete a car.\n";
    cout << "Press 7 to see all cars issued to a particular user.\n";
    cout << "Press 8 to see which car is issued to which user.\n";
    cout << "Press 9 to view all customers.\n";
    cout << "Press 10 to view all employees.\n";
    cout << "Press 11 to view all managers.\n";
    cout << "Press 12 to view all cars.\n";
    cout << "Press 13 to show due date of a car.\n";
    cout << "Press 14 to logout.\n\n";
    cout << "***************************************\n\n";

    int x;
    cin >> x;
    Manager m;
    Car c;
    user u;
    string model_num,user_ID;
    switch(x){
        case 1:
            u.user_add(ID);
            m.enter_manager_page(ID);
            break;
        case 2:
            u.user_update(ID);
            m.enter_manager_page(ID);
            break;
        case 3:
            u.user_delete(ID);
            m.enter_manager_page(ID);
            break;
        case 4:
            c.car_add(ID);
            m.enter_manager_page(ID);
            break;
        case 5:
            c.car_update(ID);
            m.enter_manager_page(ID);
            break;
        case 6:
            c.car_delete(ID);
            m.enter_manager_page(ID);
            break;
        case 7:
            cout << "Enter the ID of the user: ";
            cin >> user_ID;
            m.see_issued_to_user(ID,user_ID);
            m.enter_manager_page(ID);
            break;
        case 8:
            cout << "Enter the model number of the car: ";
            cin >> model_num;
            m.see_issued_cars(ID,model_num);
            m.enter_manager_page(ID);
            break;
        case 9:
            m.see_all_customers(ID);
            m.enter_manager_page(ID);
            break;
        case 10:
            m.see_all_employees(ID);
            m.enter_manager_page(ID);
            break;
        case 11:
            m.see_all_managers(ID);
            m.enter_manager_page(ID);
            break;
        case 12:
            m.see_all_cars(ID);
            m.enter_manager_page(ID);
            break;
        case 13:
            cout << "Enter the model number of the car: ";
            cin >> model_num;
            c.show_due_date(model_num);
            m.enter_manager_page(ID);
            break;
        case 14:
            logout();
            break;
    }

} 

void user :: enter(){
    int x;
    cout << "***************************************\n";
    cout << "\nWelcome to the Car Rental Store!\n\n";
    cout << "1. Press 1 to Sign up. \n";
    cout << "2. Press 2 to log in.\n";
    cout << "3. Press 3 to exit\n\n";
    cout << "***************************************\n";
    cin >> x;
    if(x==2){
        user a;
        a.login();
    }
    else if(x==1){
        user u;
        u.enter_new_user();
        u.login();
    }
    else if(x==3){
        cout << "Exiting...";
        exit(1);
    }
    else{
        if(x==2){
            cout << "Thank You. Visit Again!\n";
        }
        else{
            cout << "Please enter a valid response.\n";
        }
        exit(1);
    }
}

void user :: enter_new_user(){

    cout << "Please enter your details - \n";
    string name,user_id,password,type;
    string credit_score="100";
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Create your user_ID : ";
    cin >> user_id;
    cout << "Create a strong Password : ";
    cin >> password;
    cout << "Specify the user_type for our reference:)\n\n";
    cout << "For Example- Enter 1 if you are our customer, Enter 2 if your are our employee, Enter 3 if you are our manager.\n";
    cin >> type;
    if(type=="1"){
        fstream fout("all_customers_data.csv",ios::out | ios::app);
        fout << name << ","<< user_id << "," << password << "," << type << "," << credit_score << '\n';
    }
    else if(type=="2"){
        fstream fout("all_employees_data.csv",ios::out | ios::app);
        fout << name << ","<< user_id << "," << password << "," << type << "," << credit_score << '\n';
    }
    else{
        fstream fout("all_managers_data.csv",ios::out | ios::app);
        fout << name << ","<< user_id << "," << password << "," << type << "," << credit_score << '\n';
    }
    cout << "\n\nWelcome to the family:)\n";

}

void user :: login(){

    string ID,password,user_type;
    cout << "Enter your user_ID : ";
    cin >> ID;
    cout << "Enter the password : ";
    cin >> password;
    cout << "User Type entered initially :\n Type 1 if you are customer,\n\t 2 if you are an employee,\n\t 3 if you are the manager \n";
    cin >> user_type;

    if(user_type == "1"){
        vector<string> words_in_a_row;
        string line_in_csv,word;
        fstream file("all_customers_data.csv",ios::in);

        int count=0;
        if(file.is_open()){
            while(getline(file,line_in_csv)){
                words_in_a_row.clear();
                stringstream str(line_in_csv);
                while(getline(str,word,',')) words_in_a_row.push_back(word);
                if(words_in_a_row[1]==ID){
                    count=1;
                    if(words_in_a_row[2]==password){
                        count++;
                        break;
                    }
                    else{
                        while(password!=words_in_a_row[2]){
                            cout<<"Wrong Password Entered.\n Press 1 to re-enter the password.\n Press 2 to exit.\n";
                            int x;
                            cin >> x;
                            if(x==1){
                                cout << "Enter the password : ";
                                cin >> password;
                                if(password==words_in_a_row[2]){
                                    count++;
                                }
                            }
                            else if(x==2){
                                cout << "Exiting...";
                                return;
                            }
                            else{
                                cout << "Please enter a valid input.\n";
                            }
                        }
                        if(count==2){
                            break;
                        }
                    }
                }
                if(count==2){
                    break;
                }            
            }
            if(count==0){
                cout << "User not found\n";
                user u;
                u.enter();
            }
            if(count==2){
                Customer c;
                c.enter_customer_page(words_in_a_row[1]);
            }
        }
    }
    else if(user_type == "2"){
        vector<string> words_in_a_row;
        string line_in_csv,word;
        fstream file("all_employees_data.csv",ios::in);

        int count=0;
        if(file.is_open()){
            while(getline(file,line_in_csv)){
                words_in_a_row.clear();
                stringstream str(line_in_csv);
                while(getline(str,word,',')) words_in_a_row.push_back(word);
                if(words_in_a_row[1]==ID){
                    count=1;
                    if(words_in_a_row[2]==password){
                        count++;
                        break;
                    }
                    else{
                        while(password!=words_in_a_row[2]){
                            cout<<"Wrong Password Entered.\n Press 1 to re-enter the password.\n Press 2 to exit.\n";
                            int x;
                            cin >> x;
                            if(x==1){
                                cout << "Enter the password : ";
                                cin >> password;
                                if(password==words_in_a_row[2]){
                                    count++;
                                }
                            }
                            else if(x==2){
                                cout << "Exiting...";
                                return;
                            }
                            else{
                                cout << "Please enter a valid input.\n";
                            }
                        }
                        if(count==2){
                            break;
                        }
                    }
                }
                if(count==2){
                    break;
                }            
            }
            if(count==0){
                cout << "User not found\n";
                user u;
                u.enter();
            }
            if(count==2){
                Employee e;
                e.enter_employee_page(words_in_a_row[1]);
            }
        }
    }
    else if(user_type == "3"){
        vector<string> words_in_a_row;
        string line_in_csv,word;
        fstream file("all_managers_data.csv",ios::in);

        int count=0;
        if(file.is_open()){
            while(getline(file,line_in_csv)){
                words_in_a_row.clear();
                stringstream str(line_in_csv);
                while(getline(str,word,',')) words_in_a_row.push_back(word);
                if(words_in_a_row[1]==ID){
                    count=1;
                    if(words_in_a_row[2]==password){
                        count++;
                        break;
                    }
                    else{
                        while(password!=words_in_a_row[2]){
                            cout<<"Wrong Password Entered.\n Press 1 to re-enter the password.\n Press 2 to exit.\n";
                            int x;
                            cin >> x;
                            if(x==1){
                                cout << "Enter the password : ";
                                cin >> password;
                                if(password==words_in_a_row[2]){
                                    count++;
                                }
                            }
                            else if(x==2){
                                cout << "Exiting...";
                                return;
                            }
                            else{
                                cout << "Please enter a valid input.\n";
                            }
                        }
                        if(count==2){
                            break;
                        }
                    }
                }
                if(count==2){
                    break;
                }            
            }
            if(count==0){
                cout << "User not found\n";
                user u;
                u.enter();
            }
            if(count==2){
                Manager m;
                m.enter_manager_page(words_in_a_row[1]);
            }
        }
    }
    else{
        cout << "Wrong User Type entered.\n";
        user u;
        u.enter();
    }
}

void user :: logout(){
    cout << "Logging out...\n";
    user u;
    u.enter();
}

void user :: see_all_cars(string ID){
    content.clear();
    cout << "It is presented in the order of Car name, Rental Price, Model Number, Issued or not issued already.\n";
    cout << "where, 0 signifies that the car is not issued and 1 states that the car is issued.\n";
    readfile("all_cars_data.csv");
    printdata(content);
    content.clear();
}

void user :: see_issued_cars(string ID){

    int count=1;
    content.clear();
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][0]==ID){
            cout << count << ". ";
            count++;
            for(int k=0;k<content[i].size()-1;k++)
                cout << content[i][k] << " | ";
            time_t stamp = stoi(content[i][3]);
            tm *dateformat = localtime(&stamp);  
            cout << dateformat->tm_mday << "/" << 1 + dateformat->tm_mon << "/" << 1900 + dateformat->tm_year << "\n";
        }
    }
    if(count==1){
        cout << "You haven't issued any cars as of now.\n\n";
    }
    content.clear();

}

void user :: rent_car(string ID,string car_name,string type_user){
    content.clear();
    int x=0;
    if(type_user=="1"){
        int cnt=0;
        if(get_fine(ID,type_user)<=40){
            cnt++;
        }
        if(cnt==0){
            cout << "You can't rent a car, since your credit score is low.\n";  
        }
        else{
            content.clear();
            readfile("all_cars_data.csv");
            for(int i=0;i<content.size();i++){
                if(content[i][0]==car_name && content[i][3]=="0"){
                    x=1;
                    cout << "Car is available!\n";
                    content[i][3] = "1";
                    toupdate.clear();
                    toupdate.push_back(ID);
                    toupdate.push_back(car_name);
                    toupdate.push_back(content[i][2]);
                    toupdate.push_back(to_string(time(0)));
                    writefileappend(toupdate,"issued_cars_data.csv");
                    cout << "Car succesfully rented for 12 days at the cost of "<< content[i][1] << ".\n";
                    break;
                }
            }
            if(x==0){
                cout << "Car is not available!\n";
            }
            writefile(content,"all_cars_data.csv");
            content.clear();
        }
    }
    if(type_user=="2"){
        int cnt=0;
        if(get_fine(ID,type_user)<=40){
            cnt++;
        }
        if(cnt==0){
            cout << "You can't rent a car, since your credit score is low.\n";  
        }
        else{
            readfile("all_cars_data.csv");
            for(int i=0;i<content.size();i++){
                if(content[i][0]==car_name && content[i][3]=="0"){
                    x=1;
                    cout << "Car is available!\n";
                    content[i][3]="1";
                    toupdate.clear();
                    toupdate.push_back(ID);
                    toupdate.push_back(car_name);
                    toupdate.push_back(content[i][2]);
                    toupdate.push_back(to_string(time(0)));
                    writefileappend(toupdate,"issued_cars_data.csv");

                    cout << "Car succesfully rented for 12 days at the cost of "<< (75*(stoi(content[i][1])))/100 << ".\n";
                    break;
                }
            }
            if(x==0){
                cout<< "Car is not available.\n";
            }
            writefile(content,"all_cars_data.csv");
            content.clear();
        }
    }
}

void user :: check_available(string ID,string car_name){

    content.clear();
    int fl=0;
    readfile("all_cars_data.csv");
    int count=1;
    for(int i=0;i<content.size();i++){
        if(content[i][0]==car_name && content[i][3]=="0"){
            fl=1;
            cout << count << ". ";
            count++;
            cout << "Car is available!\n";
            for(auto j:content[i])
                cout << j << " | ";
            cout << "\n";
            break;
        }
    }
    if(fl==0){
        cout << "Car is not available!\n";
    }
    content.clear();

}

int user :: get_fine(string ID,string user_type){
    int fine=0;
    content.clear();
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][0]==ID){
            int curtime = time(0);
            int isstime = stoi(content[i][3]);
            if((curtime-isstime)/86400>12){
                fine+=50*((curtime-isstime)/86400 - 12);
            }
        }
    }
    content.clear();
    if(user_type == "1"){
        content.clear();
        readfile("all_customers_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1]==ID){
                int a = stoi(content[i][4]);
                fine+=(100-a);
                break;
            }
        }
        content.clear();
    }
    else if(user_type == "2"){
        content.clear();
        readfile("all_employees_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1]==ID){
                int a = stoi(content[i][4]);
                fine+=(100-a);
                break;
            }
        }
        content.clear();
    }
    cout << "Your fine is : " << fine << ".\n";
    return fine;
}

void user :: clear_fine_amount(string ID,string user_type){

    int x = get_fine(ID,user_type);
    if(x==0){
        cout << "You've no pending dues.\n";
    }
    else{
        cout << "Your fine of Rupees " << x << " is being cleared.\n";
        update_credit(ID,"2",user_type,1);
    }

}

void user :: return_car(string ID,string model_num,string user_type){

    cout << "\nEnter the returning condition of the car(verified by the Manager) : \n";
    cout << "\nPress 1 if it is good.\n";
    cout << "Press 2 if it is bad.\n\n";

    string condition;
    cin >> condition;

    content.clear();
    int x=0;
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][2]==model_num && content[i][0]==ID){
            x=1;
            content.erase(content.begin()+i,content.begin()+i+1);
            cout << "Car that was rented by you, is now being returned..\n";
            writefile(content,"issued_cars_data.csv");
            content.clear();
            readfile("all_cars_data.csv");
            for(int i=0;i<content.size();i++){
                if(content[i][2]==model_num){
                    content[i][3]="0";
                }
            }
            writefile(content,"all_cars_data.csv");
            break;
        }
    }
    if(x==0){
        cout << "Invalid details!\n";
    }
    else{
        cout << "Your credit score is lowered by 10.\n";
        update_credit(ID,condition,user_type,0);
    }

    content.clear();

}

void user :: user_add(string ID){

    Manager m;
    m.add_user(ID);

}

void user :: user_delete(string ID){

    Manager m;
    m.delete_user(ID);

}

void user :: user_update(string ID){

    Manager m;
    m.update_user(ID);

}

void user :: update_credit(string ID, string condition,string user_type,int flag){

    Manager m;
    m.credit_update(ID,condition,user_type,flag);

}

void Car :: car_request(string ID,string car_name,string type_user){

    user u;
    u.rent_car(ID,car_name,type_user);

}

void Car :: show_due_date(string model_num){
    content.clear();
    time_t stamp;
    readfile("issued_cars_data.csv");
    int x=0;
    for(int i=0;i<content.size();i++){
        if(content[i][2]==model_num){
            x=1;
            stamp = stoi(content[i][3]);
            break;
        }
    }
    content.clear();
    stamp+=12*86400;
    tm *due_time = localtime(&stamp);  
    if(x==0){
        cout << "Car is not issued!\n";
    }
    else{
        cout << "Due date of the car is : ";
        cout << due_time->tm_mday << "/" << 1 + due_time->tm_mon << "/" << 1900 + due_time->tm_year << "\n";
    }
    content.clear();
}

void Car :: car_add(string ID){

    Manager m;
    m.add_car(ID);

}

void Car :: car_delete(string ID){

    Manager m;
    m.delete_car(ID);

}

void Car :: car_update(string ID){

    Manager m;
    m.update_car(ID);

}

void Manager :: see_all_customers(string ID){

    content.clear();
    readfile("all_customers_data.csv");
    cout << "The data is given in the form of user, user_ID, type of user, credit score.\n";
    printdata_notpassword(content);
    content.clear();

}

void Manager :: see_all_managers(string ID){

    content.clear();
    readfile("all_managers_data.csv");
    cout << "The data is given in the form of user, username, type of user, credit score.\n";
    printdata_notpassword(content);
    content.clear();

}

void Manager :: see_all_employees(string ID){

    content.clear();
    readfile("all_employees_data.csv");
    cout << "The data is given in the form of user, username, type of user, credit score.\n";
    printdata_notpassword(content);
    content.clear();

}

void Manager :: see_all_cars(string ID){

    content.clear();
    readfile("all_cars_data.csv");
    cout<<"Below are all the cars: \n\n";
    cout<<"\nThe data is given in the form of car name, rental-price, model number, and is_issued(1 if the car is issued).\n\n\n";
    printdata(content);
    content.clear();

}

void Manager :: add_user(string ID){

    cout << "Please enter the details of the new user : \n";
    string name,user_id,password,type,credit_score="100";
    cout << "Enter name: ";
    cin.ignore();
    getline(cin,name);
    cout << "Enter user_ID : ";
    cin >> user_id;
    cout << "Enter Password : ";
    cin >> password;
    cout << "Enter the type of the user : 1 if Customer, 2 if Employee, 3 if Manager : ";
    cin >> type;
    if(type == "1"){
        fstream fout("all_customers_data.csv",ios::out | ios::app);
        fout << name << ","<< user_id << "," << password << "," << type << "," << credit_score << '\n';
    }
    else if(type == "2"){
        fstream fout("all_employees_data.csv",ios::out | ios::app);
        fout << name << ","<< user_id << "," << password << "," << type << "," << credit_score << '\n';
    }
    else if(type == "3"){
        fstream fout("all_managers_data.csv",ios::out | ios::app);
        fout << name << ","<< user_id << "," << password << "," << type << "," << credit_score << '\n';
    }
    else{
        cout << "Invalid User type entered.\n";
    }
    cout << "New user has been added successfully.\n";

}

void Manager :: add_car(string ID){

    cout << "Please enter the details of the new car : \n";
    string car_name,model_num,price;
    cout << "Enter Car's Name (Model's Name) : ";
    cin.ignore();
    getline(cin,car_name);
    cout << "Enter Car's Rental Price : ";
    cin >> price;
    cout << "Enter the model number : ";
    cin >> model_num;
    
    fstream fout("all_cars_data.csv",ios::out | ios::app);

    fout << car_name << "," << price << "," << model_num << ",0" << '\n';
    cout<<"New car has been successfully added.\n";

}

void Manager :: delete_car(string ID){

    string model_num;
    cout << "Enter the model number of the car : ";

    cin >> model_num; 
    content.clear();
    int found=0;
    readfile("all_cars_data.csv");

    for(int i=0;i<content.size();i++){
        if(content[i][2]==model_num){
            found=1;
            content.erase(content.begin()+i,content.begin()+i+1);
            break;
        }
    }

    writefile(content,"all_cars_data.csv");
    content.clear();
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][2]==model_num){
            content.erase(content.begin()+i,content.begin()+i+1);
            break;
        }
    }
    writefile(content,"issued_cars_data.csv");
    content.clear();
    if(found==0){
        cout<<"Car does not exist.\n";
    }
    else{
        cout << "Delete Successful.\n";
    }

}

void Manager :: delete_user(string ID){

    string user_ID;
    cout << "Enter the user ID of the user : ";
    cin >> user_ID;
    cout << "\nEnter 1 if user is a customer.\n";
    cout << "Enter 2 if user is an employee.\n";
    cout << "Enter 3 if user is a manager.\n\n";
    string x;
    cin >> x;
    int found = 0;
    if(x=="1"){
        content.clear();
        readfile("all_customers_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1]==user_ID){
                found=1;
                content.erase(content.begin()+i,content.begin()+i+1);
                break;
            }
        }
        writefile(content,"all_customers_data.csv");
        content.clear();
    }
    else if(x=="2"){
        content.clear();
        readfile("all_employees_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1]==user_ID){
                found=1;
                content.erase(content.begin()+i,content.begin()+i+1);
                break;
            }
        }
        writefile(content,"all_employees_data.csv");
        content.clear();
    }
    else if(x=="3"){
        content.clear();
        readfile("all_managers_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1]==user_ID){
                found=1;
                content.erase(content.begin()+i,content.begin()+i+1);
                break;
            }
        }
        writefile(content,"all_managers_data.csv");
        content.clear();
    }
    content.clear();
    vector<string> model_num;
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][0]==user_ID){
            model_num.push_back(content[i][2]);
            content.erase(content.begin()+i,content.begin()+i+1);
            break;
        }
    }
    writefile(content,"issued_cars_data.csv");
    content.clear();

    readfile("all_cars_data.csv");
    for(int i=0;i<content.size();i++){
        for(int j=0;j<model_num.size();j++){
            if(model_num[j]==content[i][2]){
                content[i][3]="0";
            }
        }
    }
    writefile(content,"all_cars_data.csv");
    if(found==0){
        cout << "User does not exist.\n";
    }
    else{
        cout << "Delete successful.\n";
    }

}

void Manager :: update_user(string ID){

    string user_ID, user_type;
    cout << "Enter the ID of the user you want to update : ";
    cin >> user_ID;
    cout << "\n\nEnter 1 if user is a customer.\n";
    cout << "Enter 2 if user is an employee.\n";
    cout << "Enter 3 if user is a manager.\n\n";
    cin >> user_type;
    cout << "Enter the serial number of the field you want to update : \n";
    cout << "1. Password\n";
    cout << "2. Name of the User\n";
    cout << "3. Credit Score.\n";
    int c;
    cin >> c;
    if(user_type=="1"){
        content.clear();
        int fl=0;
        readfile("all_customers_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1] == user_ID){
                fl=1;
                string new_field;
                cout << "Enter the new value of the field : ";
                cin.ignore();
                getline(cin,new_field);
                if(c==1){
                    content[i][2]=new_field;
                }
                else if(c==2){
                    content[i][0]=new_field;
                }
                else if(c==3){
                    content[i][4]=new_field;
                }
                else{
                    cout << "Invalid input!\n\n";
                }
                break;
            }
        }
        cout << "Customer updated.\n";
        writefile(content,"all_customers_data.csv");
        content.clear();
        if(fl==0){
        cout<<"User was not found.\n\n";
        }
    }
    else if(user_type=="2"){
        content.clear();
        int fl=0;
        readfile("all_employees_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1] == user_ID){
                fl=1;
                string new_field;
                cout << "Enter the new value of the field : ";
                cin.ignore();
                getline(cin,new_field);
                if(c==1){
                    content[i][2]=new_field;
                }
                else if(c==2){
                    content[i][0]=new_field;
                }
                else if(c==3){
                    content[i][4]=new_field;
                }
                else{
                    cout << "Invalid input!\n\n";
                }
                break;
            }
        }
        cout << "Employee updated.\n";
        writefile(content,"all_employees_data.csv");
        content.clear();
        if(fl==0){
        cout<<"User was not found.\n\n";
        }
    }
    else if(user_type=="3"){
        content.clear();
        int fl=0;
        readfile("all_managers_data.csv");
        for(int i=0;i<content.size();i++){
            if(content[i][1] == user_ID){
                fl=1;
                string new_field;
                cout << "Enter the new value of the field : ";
                cin.ignore();
                getline(cin,new_field);
                if(c==1){
                    content[i][2]=new_field;
                }
                else if(c==2){
                    content[i][0]=new_field;
                }
                else if(c==3){
                    content[i][4]=new_field;
                }
                else{
                    cout << "Invalid input!\n\n";
                }
                break;
            }
        }
        cout << "Manager updated.\n";
        writefile(content,"all_managers_data.csv");
        content.clear();
        if(fl==0){
        cout<<"User was not found.\n\n";
        }
    }
    else{
        cout << "Invalid User Type.\n";
    }
}

void Manager :: update_car(string ID){

    string model_num;
    cout << "Enter the model number of the car you want to update : ";
    cin >> model_num;
    cout << "\nEnter the serial number of the field you want to update : \n";
    cout << "1. Name of the Car.\n";
    cout << "2. It's Rental Price.\n";
    int c;
    cin >> c;
    content.clear();
    int fl=0;
    string new_field;
    readfile("all_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][2]==model_num){
            fl=1;
            cout << "Enter the new value of the field : ";
            cin.ignore();
            getline(cin,new_field);
            if(c==1){
                content[i][0]=new_field;
            }
            else if(c==2){
                content[i][1]=new_field;
            }
            else{
                cout<<"Invalid input!\n\n";
            }
            break;
        }
    }
    writefile(content,"all_cars_data.csv");
    content.clear();
    
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][2]==model_num){
            fl=1;
            if(c==1){
                content[i][0]=new_field;
            }
            break;
        }
    }
    cout << "Car updated.\n";
    writefile(content,"issued_cars_data.csv");

    if(fl==0){
        cout<<"Car was not found.\n\n";
    }
}

void Manager :: credit_update(string ID,string condition,string user_type,int flag){
    if(condition == "1"){
        cout << "Thank You for keeping the car safe.\n";
    }
    else if(condition == "2"){
        if(flag==0){
            if(user_type == "1"){
                content.clear();
                readfile("all_customers_data.csv");
                for(int i=0;i<content.size();i++){
                    if(content[i][1]==ID){
                        int a = stoi(content[i][4]);
                        a = a-10;
                        content[i][4]=to_string(a);
                        break;
                    }
                }
                writefile(content,"all_customers_data.csv");
                content.clear();
            }
            else if(user_type == "2"){
                content.clear();
                readfile("all_employees_data.csv");
                for(int i=0;i<content.size();i++){
                    if(content[i][1]==ID){
                        int a = stoi(content[i][4]);
                        a = a-10;
                        content[i][4]=to_string(a);
                        break;
                    }
                }
                writefile(content,"all_employees_data.csv");
                content.clear();
            }
        }
        else{
            if(user_type == "1"){
                content.clear();
                readfile("all_customers_data.csv");
                for(int i=0;i<content.size();i++){
                    if(content[i][1]==ID){
                        content[i][4]="100";
                        break;
                    }
                }
                writefile(content,"all_customers_data.csv");
                content.clear();
            }
            else if(user_type == "2"){
                content.clear();
                readfile("all_employees_data.csv");
                for(int i=0;i<content.size();i++){
                    if(content[i][1]==ID){
                        content[i][4]="100";
                        break;
                    }
                }
                writefile(content,"all_employees_data.csv");
                content.clear();
            }
        }
    }
    else{
        cout << "Invalid Input.\n";
    }
}

void Manager :: see_issued_to_user(string ID,string user_ID){
    vector <string> temp;
    content.clear();
    int count=1;
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][0]==user_ID){
            temp.push_back(content[i][2]);
        }
    }
    content.clear();
    if(temp.size()==0){
        cout<<"No car is issued to this user.\n\n";
    }
    else{
        readfile("all_cars_data.csv");
        for(int d=0;d<temp.size();d++){
            for(int i=0;i<content.size();i++){
                if(content[i][2]==temp[d]){
                    cout << count << ". ";
                    count++;
                    for(auto y:content[i]){
                        if(y!=content[i].back())
                            cout << y << " | ";
                        else{
                            cout << y <<"\n";
                        }
                    }
                }
            }
        }
        content.clear();
    }
}

void Manager :: see_issued_cars(string ID,string model_num){
    content.clear();
    int cnt=0;
    readfile("issued_cars_data.csv");
    for(int i=0;i<content.size();i++){
        if(content[i][2]==model_num){
            cout << "Car with id "<< model_num << " and name " << content[i][1] << " is issued to user with id : "<< content[i][0] <<"\n";
            cnt=1;
        }
    }
    if(cnt==0){
        cout << "Car has not been issued to anyone.\n\n";
    }
}

int main(){
    user temp;
    temp.enter();

    return 0;
}
