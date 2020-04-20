#include <iostream>
#include <sqlite3.h>
using namespace std;
class dataBase{
    public:
        sqlite3 *db;
        char exit;
        char hey;
        char *message;
        string sql;
    //create table database
    void createDatabase(){
        exit=0;
        hey =0;
        sql = "create table Student("
        "ID int primary key not null,"
        "NAME text not null,"
        "Salary Real);";
        hey =sqlite3_open("Noway.db",&db);
        exit=sqlite3_exec(db,sql.c_str(),NULL,0,&message);

        //exit=sqlite3_exec(db,sql.c_str(),0,NULL,&message);
        if (hey!=SQLITE_OK)
        {
            cout<<"Error open\n\n";
          
        }else
        {
            cout<<"Successful open\n\n";
        }
        if (exit!=SQLITE_OK)
        {
            cerr<<"Error created table\n\n";
            sqlite3_free(message);
        }else
        {
            cout<<"Create Success\n\n";
        }
        sqlite3_close(db);
    }
    void insertData(string name, float salary){
        exit =0;
        hey=0;
        int id=0;
        id=id+1;
        sql = "insert into Student values('"+to_string(id)+"','"+name+"','"+to_string(salary)+"');";
        exit = sqlite3_exec(db,sql.c_str(),NULL,0,&message);
        if (exit!=SQLITE_OK)
        {
            cerr<<"Record Error!\n\n";
            sqlite3_free(message);
        }else
        {
            cout<<"Record Successful!\n\n";
        }
    }
    
};
class Menu{
    public:
        string menu;
    void menuMain(){
        cout<<"\t\t===========================\n";
        cout<<"\t\tWelcome to Database c++ -_-\n";
        cout<<"\t\t===========================\n\n";
        cout<<"1.Insert data to sqlite(DMS)\n\n";
        cout<<"2.Show data from sqlite(DMS)\n\n";
        cout<<"3.Delete data from database.\n\n";
        cout<<"4.Exit the program.\n\n";
    }
};
int main(){
    dataBase DB;
    Menu Menu;
    int choice;
    string name;
    float salary;
    DB.createDatabase();
    while (1)
    {
        Menu.menuMain();
        cout<<"Choice:";
        cin>>choice;
        
        if (choice==4)
        {
            cout<<"Exit the program.\n";
            break;
        }else if (choice==1)
        {
            cout<<"Input your name:";
            cin>>name;
            cout<<"Input your salary:";
            cin>>salary;
            DB.insertData(name,salary);
        }

    }
}

