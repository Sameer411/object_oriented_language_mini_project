#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<cstdlib>
#include<stdio.h>
#include<unistd.h>
using namespace std;
class Person
{

	public:
		char name[50],add[50];
		long int PhNo;
		void input_data()
		{
			cout<<"\n Enter Name:";
			cin>>name;
			cout<<"\n Enter Phone Number:";
			cin>>PhNo;
			cout<<"\n Enter address:";
			cin>>add;
		}
		int put_data()
		{
			cout<<setw(10)<<name<<"\t"<<setw(10)<<PhNo<<"\t"<<setw(10)<<add<<"\t"<<endl;
		}
		void pass()
		{
			int s;
			Person rec;
			char pas[10];
			char pas1[10];
			long int phone;
			int pos,choice,offset,i;
			fstream f;
			ifstream fin;
			ofstream fout;
			char nm[20];
			do
			{
				cout<<"\n\n\t*+-*+-+*-+*-+*-+*-+*-+*-\n\t   Telephone Directory \n\t*+-*+-+*-+*-+*-+*-+*-+*-	"<<endl;
				cout<<"\n Main Menu";
				cout<<"\n1. Write file";
				cout<<"\n2. Read file.";
				cout<<"\n3. Search by number.";
				cout<<"\n4. Search by names.";
				cout<<"\n5. Update telephone number";
				cout<<"\n6. Delete telephone number";
				cout<<"\n7.Exit.";
				cout<<"\n Enter your choice:";
				cin>>choice;
				switch(choice)
				{
					case 1:
						rec.input_data();
						char ch;
						cin.get(ch);
						fout.open("d:\\test.dat",ios::out|ios::app|ios::binary);
						fout.write((char*)&rec,sizeof(rec));
						fout.close();
					break;
					case 2:
						fin.open("d:\\test.dat",ios::in|ios::binary);
						cout<<"\n The contents of file are...\n";
						while(fin.read((char*)&rec,sizeof(rec)))
						{
							rec.put_data();
						}
						fin.close();
					break;
					case 3:
						cout<<"\n Enter the phone number:";
						cin>>phone;
						f.open("d:\\test.dat",ios::ate|ios::in|ios::out|ios::binary);
						f.seekg(0,ios::beg);
						pos=-1;
						i=0;
						while(f.read((char*)&rec,sizeof(rec)))
						{
							if(phone == rec.PhNo)
							{
								pos=i;
								break;
							}
							i++;
						}
						offset = pos*sizeof(rec);
						f.seekp(offset);
						f.read((char*)&rec,sizeof(rec));
						cout<<"\n Name:"<<rec.name;
						f.close();
					break;
					case 4:
						cout<<"\n Enter the Name:";
						cin>>nm;
						f.open("d:\\test.dat",ios::ate|ios::in|ios::out|ios::binary);
						f.seekg(0,ios::beg);
						pos=-1;
						i=0;
						while(f.read((char*)&rec,sizeof(rec)))
						{
							if((strcmp(nm,rec.name))==0)
							{
								pos=i;
								break;
							}
							i++;
						}
						offset = pos*sizeof(rec);
						f.seekp(offset);
						f.read((char*)&rec,sizeof(rec));
						cout<<"\n Telephone Number:"<<rec.PhNo;
						f.close();
					break;
					case 5:
						cout<<"\n Enter the Name:";
						cin>>nm;
						f.open("d:\\test.dat",ios::ate|ios::in|ios::out|ios::binary);
						f.seekg(0,ios::beg);
						pos=-1;
						i=0;
						while(f.read((char*)&rec,sizeof(rec)))
						{
							if((strcmp(nm,rec.name))==0)
							{
								pos=i;
								break;
							}
							i++;
						}
						offset = (pos)*sizeof(rec);
						f.seekp(offset);
						cout<<"Current Phone:"<<rec.PhNo;
						cout<<"\n Enter new Telephone Number:";
						cin>>phone;
						rec.PhNo=phone;
						f.write((char*)&rec,sizeof(rec))<<flush;
						cout<<"\n Record updated!!!\n";
						f.seekg(0);
						while(f.read((char*)&rec,sizeof(rec)))
						{
							rec.put_data();
						}
						f.close();
					break;
					case 6:
						int n;
						f.open("d:\\test.dat", ios::binary);
						if (!f)
						{
							cin.ignore();
							cin.get();
						}
						fout.open("Temp.dat", ios::out);
						f.seekg(0, ios::beg);
						while (f.read(reinterpret_cast<char *> (&rec), sizeof(Person)))
						{
							if (rec.put_data() != n)
							{
								fout.write(reinterpret_cast<char *> (&rec), sizeof(Person));
							}
						}
						fout.close();
						f.close();
						remove("d:\\test.dat");
						rename("Temp.dat", "d:\\test.dat");
						cout << "\n\n\tRecord Deleted ..";
						cin.ignore();
						cin.get();
					break;
					case 7:
						exit(1);
						break;
				}
			}while(1);
		}
};
int main()
{
	Person rec;
	const char* pas="geqnhh#3759";
	const char* pas1;
	pas1= getpass("\nEnter your password to access the directory : ");
	int p,i;
	if(!strcmp(pas,pas1))
		rec.pass();
	else if(strcmp(pas,pas1))
	{
		cout<<"\nInvalid password!!!\nProgram terminated!!!!"<<endl;
		return -1;
	}
	return 0;
}
