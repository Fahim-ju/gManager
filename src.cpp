#include<bits/stdc++.h>
#include <dos.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
void clrscr( )
{
    system("@cls||clear");
}
void animation();
void delay();
void loganimation(string s);

class adminloginmanager
{
private:
    string username,password;
    public:
    adminloginmanager()
    {
        username = "admin";
        password = "adminpassword";
    }
    bool check(string a, string b)
    {
    	loganimation("Logging");
        if(username == a && password == b)
        {
            cout<<"Log in successful\n\n";
            return true;
        }
        else
        {
            cout<<"Incorrect username or password\n";
            return false;
        }
    }
};

class customerloginmanager
{
private:
    string username,password;
public:
    void signup()
    {
        cout<<"Username: ";
        cin>>username;
        cout<<"Password: ";
        cin>>password;
        ofstream myfile;
        myfile.open("customerdata.txt",ios::app);
        myfile<<username<<" "<<password<<endl;
        myfile.close();
        clrscr();
        cout<<"You signed up successfully! "<<endl;
    }
    void scan()
    {
        cout<<"Username: ";
        cin>>username;
        cout<<"Password: ";
        cin>>password;
    }
    bool scancustomerdataandcheck()
    {
        string tempuser,temppass;
        ifstream myfile;
        myfile.open("customerdata.txt");
        while(myfile>>tempuser>>temppass)
        {
//            cout<<tempuser<<temppass<<endl;
            if(tempuser == username && temppass == password)
            {
                myfile.close();
                return true;
            }
        }
        return false;
    }
    string getuser()
    {
    	return username;
    }
};

class product
{
	private:
	string productname,code,color;
	int sz;
	public:
	void setproduct()
	{
		cout<<"Productname: ";cin>>productname;
		cout<<"Code: ";cin>>code;
		cout<<"Color: ";cin>>color;
		cout<<"Size: ";cin>>sz;
	}
	void showproductdetail()
	{
		cout<<setw(8)<<left<<productname<<"  "<<setw(5)<<left<<code<<" "<<setw(6)<<left<<color<<" "<<setw(3)<<left<<sz<<endl;
	}
	string getcode();
	string getproductname();
	string getcolor();
	int getsz();
	bool operator < (product b) const
	{
		if(productname < b.productname)
		{
			return true;
		}
		else return false;
	}
};

string product :: getproductname()
{
	return productname;
}
string product::getcolor()
{
	return color;
}
int product :: getsz()
{
	return sz;
}
string product::getcode()
{
	return code;
}

product productaddition()
{
	product productobj;
	productobj.setproduct();
	return productobj;
}

struct pendingorder
{
	product p;
	string cusname;
};

vector< pendingorder > ordered;

bool cmp(pendingorder a,pendingorder b)
{
	return a.p < b.p;
}

void menu();

void menuforcustomer()
{
	cout<<"1. View product\n";
	cout<<"2. Order product\n";
	cout<<"3. Report/Feedback\n";
	cout<<"4. Log out\n";
}

void menuforadmin()
{
	cout<<"1. Add product\n";
	cout<<"2. View order\n";
	cout<<"3. View feedback\n";
	cout<<"4. View Worker\n";
	cout<<"5. Add Worker\n";
	cout<<"6. View job application\n";
	cout<<"7. Log out\n";
}

class person
{
private:
    string name,id;
    int age;
public:
    virtual void setdata()
    {
        cout<<"Name: ";
        cin>>name;
        cout<<"ID: ";
        cin>>id;
        cout<<"Age: ";
        cin>>age;
    }
    virtual void show() const
    {
        cout<<setw(6)<<left<<name<<" "<<setw(5)<<left<<id<<" "<<setw(6)<<left<<age;
    }
    string getname()
    {
        return name;
    }
    string getid() { return id;}
    int getage() {return age;}
};

class worker : public person
{
private:
    string designation,shift;
    int salary;
public:
	worker()
	{
		shift = "Day";
		salary = 20000;
	}
    void setdata()
    {
        person::setdata();
        cout<<"Designation: ";
        cin>>designation;
        cout<<"Shift: ";
        cin>>shift;
        cout<<"Salary: ";
        cin>>salary;
    }
    void show() const
    {
        person::show();
        cout<<setw(12)<<left<<designation<<" "<<shift<<endl;
    }
    void updatedata()
    {
    	cout<<"Designation: "; cin>>designation;
    	cout<<"Shift: "; cin>>shift;
    	cout<<"Salary: "; cin>>salary;
    }
    string getname()
    {
        return person::getname();
    }
    string getid() { return person:: getid();}
    int getage() { return person :: getage();}
    string getdesignation () { return designation;}
    string getshift() { return shift;}
    int getsalary() { return salary;}
};

template < class T>
class serial
{
    T ara[50000];
    int sz,frnt,rear;
public:
    serial()
    {
        sz = 0;
        frnt = 0;
        rear = 0;
    }
    void pop()
    {
        if(sz==0) cout<<"\nUnderflow\n";
        sz--;
        rear--;
    }
    T frontelement()
    {
        return ara[sz-1];
    }
    void push(T a)
    {
        ara[sz++] = a;
    }
    int getsz()
    {
        return sz;
    }
};

serial< worker > jobapplication;

int main()
{
    animation();
    mainmenu:
    menu();
    int option;
    cout<<"\nEnter Option: ";
    cin>>option;
    customerloginmanager customerloginmanagerobj;
    if(option == 1)
    {
        clrscr();
        string admin,adminpassword;
        bool success;
        adminloginmanager adminloginmanagerobj;
        cout<<"Username: ";
        cin>>admin;
        cout<<"Password: ";
        cin>>adminpassword;
        clrscr();
        success = adminloginmanagerobj.check(admin,adminpassword);
        if(success)
        {
            cout<<"Logged in as Admin\n";
            adminmenu:
            menuforadmin();
            int admincommand;
            cout<<"\nEnter option: ";
            cin>>admincommand;
            if(admincommand == 1)
			{
				clrscr();
				product productobj;
				productobj = productaddition();
				ofstream myfile;
				myfile.open("product.txt",ios::app);
				string temp;
				temp = productobj.getproductname();
				myfile<<setw(8)<<left<<temp;
				temp = productobj.getcode();
				myfile<<" "<<setw(6)<<left<<temp;
				temp = productobj.getcolor();
				myfile<<" "<<setw(6)<<temp<<endl;
				myfile.close();
				clrscr();
				cout<<"Product Added successfully.\n\n";
				goto adminmenu;
			}
			else if(admincommand == 2)
			{
				clrscr();
				admincommand2:
				//view order
				int com;
				cout<<"1. View order\n";
				cout<<"2. Sort Ordered product\n";
				cout<<"3. previous menu\n";
				cout<<"\nOption: "; cin>>com;
				if(com==1)
				{
					clrscr();
					cout<<"Customer  Product  Code  Color Size\n";
					cout<<"--------  -------  ----  ----- ----\n";
					//view
					for(int i=0; i<ordered.size(); i++)
					{
						cout<<setw(8)<<left<<ordered[i].cusname<<" ";
						ordered[i].p.showproductdetail();
					}
					cout<<"\nEnter any key to back to previous menu\n";
					getchar();
					getchar();
					clrscr();
					goto admincommand2;
				}
				else if(com==2)
				{
					sort(ordered.begin(),ordered.end(),cmp);
					clrscr();
					loganimation("Sorting");
					cout<<"Sorting successful\n\n";
					goto admincommand2;
				}
				else
				{
				    clrscr();
					goto adminmenu;
				}
			}
			else if(admincommand == 3)
			{
			    clrscr();
				ifstream myfile;
				myfile.open("report.txt");
				string s;
				while(getline(myfile,s))
				{
					cout<<s<<endl;
				}
				myfile.close();
				cout<<"\nEnter key to back to previous menu\n\n";
				getchar();
				getchar();
				clrscr();
				goto adminmenu;
			}
			else if(admincommand == 4)
			{
			    clrscr();
				ifstream myfile;
				myfile.open("worker.txt");
				string s;
				while(getline(myfile,s))
				{
					cout<<s<<endl;
				}
				myfile.close();
				cout<<"\nEnter key to back to previous menu\n";
				getchar();
				getchar();
				clrscr();
				goto adminmenu;
			}
			else if(admincommand == 5)
			{
			clrscr();
			worker workerobj;
			workerobj.setdata();
			ofstream myfile;
			myfile.open("worker.txt",ios::app);
			string t = workerobj.getname();
			myfile<<setw(10)<<left<<t;
			t = workerobj.getid();
			myfile<<setw(5)<<left<<t;
			int n = workerobj.getage();
			myfile<<setw(5)<<left<<n;
			t = workerobj.getdesignation();
			myfile<<setw(12)<<left<<t;
			t = workerobj.getshift();
			myfile<<setw(7)<<left<<t;
			n = workerobj.getsalary();
			myfile<<setw(5)<<left<<n<<endl;
			myfile.close();
			clrscr();
			cout<<"Worker added successfully\n\n";
			goto adminmenu;
			}
			else if(admincommand == 6)
            {
                clrscr();
                cout<<setw(6)<<left<<"name"<<" "<<setw(5)<<left<<"id"<<" "<<setw(6)<<left<<"age "<<setw(7)<<left<<"designation"<<" "<<"shift"<<endl;
                cout<<setw(6)<<left<<"----"<<" "<<setw(5)<<left<<"--"<<" "<<setw(6)<<left<<"--- "<<setw(7)<<left<<"-----------"<<" "<<"-----"<<endl;
                int sz = jobapplication.getsz();
                for(int i=0; i<sz; i++)
                {
                    jobapplication.frontelement().show();
                    jobapplication.pop();
                }
                cout<<"\nEnter key to back to previous menu\n";
                getchar();
                getchar();
                clrscr();
                goto adminmenu;
            }
            else if(admincommand==7)
			{
				clrscr();
				loganimation("Logging out");
				clrscr();
				cout<<"Logged out successful\n";
				goto mainmenu;
			}
        }
        else
        {
            clrscr();
            goto mainmenu;
        }
    }
    else if(option == 2)
    {
        clrscr();
        customerloginmanagerobj.scan();
        bool success = customerloginmanagerobj.scancustomerdataandcheck();
        if(success)
        {
        	loganimation("Logging");
        	clrscr();
            cout<<"Logged in successfully\n\n";
            cusmenu:
            menuforcustomer();
            int cuscommand;
			cout<<"\nEnter option: ";
            cin>>cuscommand;
            if(cuscommand == 1)
			{
				clrscr();
				string s;
				ifstream myfile;
				myfile.open("product.txt");
				while(getline(myfile,s))
				{
					cout<<s<<endl;
				}
				cout<<"\nEnter any key to back to menu\n";
				getchar();
				getchar();
				clrscr();
				goto cusmenu;
			}
            else if(cuscommand == 2)
			{
				clrscr();
				pendingorder obj;
				obj.p.setproduct();
				obj.cusname = customerloginmanagerobj.getuser();
				ordered.push_back(obj);
				string t = obj.p.getcode(); int temp = obj.p.getsz();
				ofstream myfile;
				myfile.open("orderedproduct.txt",ios::app);
				myfile<<setw(8)<<left<<obj.cusname<<" "<<setw(6)<<left<<t<<" "<<setw(5)<<temp<<endl;
				myfile.close();
				clrscr();
				cout<<"Ordered successful\n\n";
				goto cusmenu;
			}
			else if(cuscommand == 3)
			{
				getchar();
				string s;
				clrscr();
				cout<<"Enter your opinion: ";
				getline(cin,s);
				ofstream myfile;
				myfile.open("report.txt");
				myfile<<s<<endl;
				myfile.close();
				clrscr();
				cout<<"\nReport submitted.\n\n";
				goto cusmenu;
			}
			else if(cuscommand == 4)
			{
				clrscr();
				loganimation("Logging out");
				clrscr();
				cout<<"Logged out successfully\n\n";
				goto mainmenu;
			}
        }
        else
        {
            clrscr();
            cout<<"Incorrect username or password\n";
            goto mainmenu;
        }
    }
    else if(option == 3)
    {
        clrscr();
        customerloginmanagerobj.signup();
        goto mainmenu;
    }
    else if(option == 4)
    {
        clrscr();
        bool f = 1;
        string s;
        cout<<"Enter username: ";
        cin>>s;
        ifstream myfile;
        myfile.open("customerdata.txt");
        string u,p;
        loganimation("Checking");
        while(myfile>>u>>p)
        {
            if(u==s)
            {
            f = 0;
            clrscr();
            cout<<"Your password: "<<p<<endl<<endl;
            cout<<"Enter key to back to previous menu\n";
            getchar();
            getchar();
            clrscr();
            goto mainmenu;
            }
        }
        myfile.close();
        if(f)
        {
            clrscr();
            cout<<"Sorry. Username doesn't match\n\n";
            cout<<"Enter key to back to previous menu.\n";
            getchar();
            getchar();
            clrscr();
            goto mainmenu;
        }
    }
    else if(option == 5)
    {
        clrscr();
        worker obj;
        obj.setdata();
        jobapplication.push(obj);
        clrscr();
        loganimation("Submitting");
        cout<<"Application submitted successfully\n\n";
        goto mainmenu;
    }
    else
    {
        clrscr();
        cout<<"Invalid input\n\n";
        goto mainmenu;
    }
    return 0;
}

void delay()
{
	for(int i=0; i<150000000; )
	{
		i++;
	}
}
void loganimation(string s)
{
	clrscr();
	for(int k=0; k<3; k++)
	{
	cout<<"Please Wait while "<<s<<" ";
	delay();
	for(int i=0; i<4; i++)
	{
		cout<<". ";
		delay();
	}
	clrscr();
	}
	clrscr();
}
void menu()
{
    cout<<endl;
    cout<<"Menu: "<<endl;
    cout<<"1. Log in as Admin\n";
    cout<<"2. Log in as Customer\n";
    cout<<"3. Sign Up as Customer\n";
    cout<<"4. Forgotten password\n";
    cout<<"5. Apply for Job\n";  //use queue //template
}

void animation()
{
    cout<<"\t\tWELCOME TO THE GARMENTS MANAGEMENT SYSTEM WITH C++\n\n\n";
    cout<<"\t\tEnter any key to continue...\n";
    getchar();
    clrscr();

}


