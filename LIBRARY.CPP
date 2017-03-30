#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
struct date
{
	int day;
	int month;
	int year;
};
int check_leap(int);
date incr_date(date);
int count=1,count1=1;
struct serial_no
{
	char department[3];
	char rack[3];
	char row;
	char book[5];
	char copy_no[3];
};
int struct_cmp(serial_no s1,serial_no s2);
class stdid
{
	private:
	char name[80];
	char year;
	char sno[9];
	int no_issues;
	serial_no book_issued[4];
	date issue_date[4];
	date retrieval[4];
	char username[14];
	char password[14];
	public:
	void stud_entry()
	{
		cout<<"Enter year between 1 to 4 or /'p/' for professor:";
		cin>>year;
		while(!((year=='p')||(year>='1'&&year<='4')))
		{
			cout<<"Enter year between 1 to 4 or /'p/' for professor and nothing else:";
			cin>>year;
		}
		if(year=='p')
		{
			cout<<"Enter name of professor:";
			gets(name);
		}
		else if(year>='1'&&year<='4')
		{
			cout<<"Enter name of student:";
			gets(name);
		}
		cout<<"Enter identity number:";
		scanf("%[^\n]",sno);
		no_issues=0;
		username[0]='\0';
		password[0]='\0';
	}
	void user_information()
	{
		char temp_password[14];
		cout<<"Enter username(max. 13 characters):";
		gets(username);
		cout<<"Enter password(max. 13 characters):";
		gets(password);
		cout<<"Enter password again to confirm:";
		gets(temp_password);
		while((strcmp(password,temp_password)))
		{
			cout<<"Passwords did not match.Enter password again:";
			gets(password);
			cout<<"Enter password again to confirm:";
			gets(temp_password);
		}
	}
	char *get_name()
	{
		return name;
	}
	char get_year()
	{
		return year;
	}
	char *get_serial()
	{
		return sno;
	}
	date get_issue(int i)
	{
		return issue_date[i];
	}
	date get_retrieval(int i)
	{
		return retrieval[i];
	}
	char *get_user()
	{
		return username;
	}
	char  *get_pass()
	{
		return password;
	}
	int get_no_issued()
	{
		return no_issues;
	}
	void prnt_stdid()
	{
		cout<<"\nName:";
		puts(name);
		cout<<"Student id:";
		puts(sno);
		cout<<"Year:"<<year<<"\n";
	}
	void chg_pass()
	{
		char old_pass[14],temp_password[14];
		cout<<"Enter the old password:";
		gets(old_pass);
		if(strcmp(old_pass,password))
		{
			cout<<"Incorrect old password. You can\'t change your password";
		}
		else
		{
			cout<<"Enter new password:";
			gets(password);
			cout<<"Enter new password again to confirm:";
			gets(temp_password);
			while((strcmp(password,temp_password)))
			{
				cout<<"Passwords did not match.Enter new password again:";
				gets(password);
				cout<<"Enter new password again to confirm:";
				gets(temp_password);
			}
		}
	}
	void change_issue(date temp)
	{
		issue_date[no_issues].day=temp.day;
		issue_date[no_issues].month=temp.month;
		issue_date[no_issues].year=temp.year;
		change_retrieval(issue_date[no_issues]);
	}
	void change_retrieval(date temp)
	{
		temp=incr_date(temp);
		retrieval[no_issues].day=temp.day;
		retrieval[no_issues].month=temp.month;
		retrieval[no_issues].year=temp.year;
		no_issues++;
	}
	void modify_record()
	{
		char ans='y';
		int ch;
		while(ans=='Y'||ans=='y')
		{
			clrscr();
			cout<<"Present Record is:";
			prnt_stdid();
			cout<<"1.Name";
			cout<<"\n2.Admission number";
			cout<<"\n3.Year";
			cout<<"\n4.No change in details";
			cout<<"Enter the corresponding number of the information you want to change:";
			cin>>ch;
			switch(ch)
			{
				case 1: cout<<"Enter New name:";
					gets(name);
					break;
				case 2:	cout<<"Enter new admission number:";
					gets(sno);
					break;
				case 3:	cout<<"Enter the year:";
					cin>>year;
					break;
				case 4: break;
			       default: cout<<"Wrong choice!!!!!!\n";
					break;
			}
			cout<<"Want to change more details???(y/n)";
			cin>>ans;
		}
		cout<<"Finally Record is:";
		prnt_stdid();
	}
	void stud_modify()
	{
		char ans='y';
		int ch;
		while(ans=='Y'||ans=='y')
		{
			clrscr();
			cout<<"Username:";
			puts(username);
			cout<<"Change Menu";
			cout<<"\n1.Username";
			cout<<"\n2.Password";
			cout<<"\n3.No changing";
			cout<<"\nEnter corresponding number of the desired change:";
			cin>>ch;
			switch(ch)
			{
				case 1: cout<<"Enter new username(max. 13 characters):";
					gets(username);
					break;
				case 2: chg_pass();
					break;
				case 3: break;
				case 4: cout<<"Wrong Choice!!!!!";
					break;
			}
			cout<<"Want more change in data?(y/n)";
			cin>>ans;
		}
	}
	void stdid::issue(serial_no obj);
	int stdid::deposit(serial_no obj);
};
class book
{
	private:
	char book_name[80];
	serial_no sno;
	char author[80];
	char publisher[80];
	char issued_ind;
	char iss_serial[9];
	public:
	void book_entry()
	{
		int i=2;
		cout<<"Enter the book name:";
		gets(book_name);
		cout<<"Enter the first two character of Department to which book belongs:";
		scanf("%[^\n]",sno.department);
		cout<<"Enter the rack number:";
		scanf("%[^\n]",sno.rack);
		cout<<"Enter the row in the rack:";
		cin>>sno.row;
		cout<<"Enter the copy number:";
		scanf("[^\n]",sno.copy_no);
		sno.book[0]=book_name[0];
		sno.book[1]=book_name[1];
		while(book_name[i]!='\0')
		{
			if(book_name[i]==' '&&book_name[i+1]!=' ')
			{
				sno.book[3]=book_name[i+1];
				sno.book[4]=book_name[i+2];
				break;
			}
			i++;
		}
		sno.book[5]='\0';
		cout<<"Enter Author name:";
		gets(author);
		cout<<"Enter publisher name:";
		gets(publisher);
		issued_ind='n';
	}
       void put_entry()
       {
		cout<<"\nName:";
		puts(book_name);
		cout<<"Author:";
		puts(author);
		cout<<"Publisher:";
		puts(publisher);
		cout<<"First two characters of Department:";
		puts(sno.department);
		cout<<"Rack number:";
		puts(sno.rack);
		cout<<"Row:"<<sno.row<<"\n";
		cout<<"Copy Number:";
		puts(sno.copy_no);
       }
       char *get_name()
       {
		return book_name;
       }
       char *get_author()
       {
		return author;
       }
       char *get_publisher()
       {
		return publisher;
       }
       char check_issued()
       {
		return issued_ind;
       }
       serial_no get_sno()
       {
		return sno;
       }
       char *get_issuer()
       {
		return iss_serial;
       }
       void modify()
       {
		int ans='y';
		int ch,i;
		while(ans=='y'||ans=='Y')
		{
			clrscr();
			cout<<"Present Record is:";
			put_entry();
			cout<<"1.Name";
			cout<<"\n2.Author";
			cout<<"\n3.Publisher";
			cout<<"\n4.Department";
			cout<<"\n5.Rack number";
			cout<<"\n6.Row";
			cout<<"\n7.Copy number";
			cout<<"\n8.No Record change";
			cout<<"\nEnter the corresponding number of the information youy want to change:";
			cin>>ch;
			switch(ch)
			{
				case 1: cout<<"Enter new name:";
					gets(book_name);
					sno.book[0]=book_name[0];
					sno.book[1]=book_name[1];
					while(book_name[i]!='\0')
					{
						if(book_name[i]==' '&&book_name[i+1]!=' ')
						{
							sno.book[3]=book_name[i+1];
							sno.book[4]=book_name[i+2];
							break;
						}
						i++;
					}
					break;
				case 2: cout<<"Enter the author/'s new information:";
					gets(author);
					break;
				case 3: cout<<"Enter the publisher/'s new information:";
					gets(publisher);
					break;
				case 4: cout<<"Enter the changed Department's first two characters:";
					gets(sno.department);
					break;
				case 5: cout<<"Enter the changed rack number:";
					gets(sno.rack);
					break;
				case 6: cout<<"Enter the chaged row number:";
					cin>>sno.row;
					break;
				case 7: cout<<"Enter changed copy number:";
					gets(sno.copy_no);
					break;
				case 8: break;
				case 9: cout<<"Wrong choice!!!!!\n";
					break;
			}
			cout<<"Want to change more information???(y/n)";
			cin>>ans;
		}
		cout<<"\nFinally Record is:";
		put_entry();
       }
       void issue(stdid obj)
       {
		strcpy(iss_serial,obj.get_serial());
		issued_ind='y';
       }
       void deposit()
       {
		iss_serial[0]='\0';
		issued_ind='n';
       }
};
void stdid::issue(serial_no obj)
{
	date temp;
	cout<<"Enter date in  dd/mm/yyyy format";
	scanf("%d/",&temp.day);
	scanf("%d/",&temp.month);
	scanf("%d/",&temp.year);
	change_issue(temp);
	book_issued[no_issues]=obj;
}
int stdid::deposit(serial_no obj)
{
	int flag=0;
	for(int i=0;i<no_issues;i++)
	{
		if(struct_cmp(book_issued[i],obj))
		{
			flag=1;
			for(int j=i;j<no_issues-1;j++)
			{
				book_issued[i]=book_issued[i+1];
				issue_date[i]=issue_date[i+1];
				retrieval[i]=retrieval[i+1];
			}
			no_issues--;
			break;
		}
	}
	if(flag==0)
		cout<<"No book issued with this specifications";
	return flag;
}
class librarian
{
	private:
	char name[80];
	char username[15];
	char password[15];
	public:
	void enter_data()
	{
		char temp_pass[15];
		cout<<"Enter librarian name:";
		gets(name);
		cout<<"Enter Username:";
		gets(username);
		cout<<"Enter Password:";
		gets(password);
		cout<<"Enter Password again to confirm:";
		gets(temp_pass);
		while((strcmp(password,temp_pass)))
		{
			clrscr();
			cout<<"Passwords do not match.Enter Password again:";
			gets(password);
			cout<<"Enter password again to confirm:";
			gets(temp_pass);
		}
	}
	void put_data()
	{
		cout<<"\nName:";
		puts(name);
	}
	char *get_name()
	{
		return name;
	}
	char *get_pass()
	{
		return password;
	}
	char *get_user()
	{
		return username;
	}
	void modify()
	{
		int ch;
		char ans='y',old_pass[14],temp_password[14];
		cout<<"Name of Librarian:";
		puts(name);
		while(ans=='y'||ans=='Y')
		{
			clrscr();
			cout<<"Change Menu";
			cout<<"\n1.Username";
			cout<<"\n2.Password";
			cout<<"\n3.No changes";
			switch(ch)
			{
				case 1:	cout<<"Enter username(max. 13 characters):";
					gets(username);
					break;
				case 2: cout<<"Enter the old password:";
					gets(old_pass);
					if(strcmp(old_pass,password))
					{
						cout<<"Incorrect old password. You can\'t change your password";
					}
					else
					{
						cout<<"Enter new password:";
						gets(password);
						cout<<"Enter new password again to confirm:";
						gets(temp_password);
						while((strcmp(password,temp_password)))
						{
							cout<<"Passwords did not match.Enter new password again:";
							gets(password);
							cout<<"Enter new password again to confirm:";
							gets(temp_password);
						}
					}
					break;
				case 3: break;
				case 4: cout<<"Wrong choice!!!!";
					break;
			}
			cout<<"Want more change?(y/n)";
			cin>>ans;
		}
	}
};
date incr_date(date to_inc)
{
      date increased;
      int flag;
      flag=check_leap(to_inc.year);
      if((to_inc.month==4)||(to_inc.month==6)||(to_inc.month==9)||(to_inc.month==11))
      {
		increased.day=to_inc.day+14;
		if(increased.day>30)
		{
			increased.day=increased.day%30;
			increased.month=to_inc.month+1;
			increased.year=to_inc.year;
		}
		else
		{
			increased.month=to_inc.month;
			increased.year=to_inc.year;
		}
      }
      else if(to_inc.month==2)
      {
		increased.day=to_inc.day+14;
		if(flag==0)
		{
			if(increased.day>28)
			{
				increased.day=increased.day%28;
				increased.month=to_inc.month+1;
				increased.year=to_inc.year;
			}
			else
			{
				increased.month=to_inc.month;
				increased.year=to_inc.year;
			}
		}
		else
		{
			if(increased.day>29)
			{
				increased.day=increased.day%29;
				increased.month=to_inc.month+1;
				increased.year=to_inc.year;
			}
			else
			{
				increased.month=to_inc.month;
				increased.year=to_inc.year;
			}
		}
      }
      else if((to_inc.month==1)||(to_inc.month==3)||(to_inc.month==5)||(to_inc.month==7)||(to_inc.month==8)|| (to_inc.month==10))
      {
		increased.day=to_inc.day+14;
		if(increased.day>31)
		{
			increased.day=increased.day%31;
			increased.month=to_inc.month+1;
			increased.year=to_inc.year;
		}
		else
		{
			increased.month=to_inc.month;
			increased.year=to_inc.year;
		}
      }
      else if(to_inc.month==12)
      {
		increased.day=to_inc.day+14;
		if(increased.day>31)
		{
			increased.day=increased.day%31;
			increased.month=1;
			increased.year=to_inc.year+1;
		}
		else
		{
			increased.month=to_inc.month;
			increased.year=to_inc.year;
		}
      }
      return increased;
}
int check_leap(int year)
{
	int flag=0;
	if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0)
				flag=1;
		}
		else
			flag=1;
	}
	return flag;
}
int date_check(date depo,date retr)
{
	int flag=0;
	if(depo.year>retr.year)
		flag=1;
	else
	{
		if(depo.month>retr.month)
			flag=1;
		else if(depo.day>retr.day)
			flag=1;
	}
	return flag;
}
void student_record()
{
	fstream fout("Student.txt",ios::out);
	char ans='y';
	stdid obj;
	while(ans=='y'||ans=='Y')
	{
		cout<<"Enter the record of next student:\n";
		obj.stud_entry();
		fout.write((char*)&obj,sizeof(obj));
		cout<<"Want to enter more records?(Enter y for more records,any other key to terminate entry):";
		cin>>ans;
		clrscr();
	}
	fout.close();
}
void book_record()
{
	fstream fout("Book.txt",ios::out);
	char ans='y';
	book obj1;
	while(ans=='y'||ans=='Y')
	{
		cout<<"Enter the record of next book:\n";
		obj1.book_entry();
		fout.write((char*)&obj1,sizeof(obj1));
		cout<<"Want to enter more records?(Enter y for more records,any other key to terminate entry):";
		cin>>ans;
		clrscr();
	}
	fout.close();
}
void lib_record()
{
	fstream fout("Librarian.txt",ios::out);
	char ans='y';
	librarian obj2;
	while(ans=='y'||ans=='Y')
	{
		cout<<"Enter the record of next librarian:\n";
		obj2.enter_data();
		fout.write((char*)&obj2,sizeof(obj2));
		cout<<"Are there more librarians?(Enter y for yes,any other key for no):";
		cin>>ans;
		clrscr();
	}
	fout.close();
}
void student_append()
{
	fstream fout("Student.txt",ios::app);
	char ans='y';
	stdid obj;
	while(ans=='y'||ans=='Y')
	{
		cout<<"Enter the record of next student:";
		obj.stud_entry();
		fout.write((char*)&obj,sizeof(obj));
		cout<<"Want to enter more records?(Enter y for more records,any other key to terminate entry):";
		cin>>ans;
		clrscr();
	}
	fout.close();
}
void book_append()
{
	fstream fout("Book.txt",ios::app);
	char ans='y';
	book obj1;
	while(ans=='y'||ans=='Y')
	{
		cout<<"Enter the record of next book:";
		obj1.book_entry();
		fout.write((char*)&obj1,sizeof(obj1));
		cout<<"Want to enter more records?(Enter y for more records,any other key to terminate entry):";
		cin>>ans;
		clrscr();
	}
	fout.close();
}
void lib_append()
{
	fstream fout("Librarian.txt",ios::app);
	char ans='y';
	librarian obj2;
	while(ans=='y'||ans=='Y')
	{
		cout<<"Enter the record of next librarian:";
		obj2.enter_data();
		fout.write((char*)&obj2,sizeof(obj2));
		cout<<"Are there more librarians?(Enter y for yes,any other key for no):";
		cin>>ans;
		clrscr();
	}
	fout.close();
}
void search_book_name(char name[80])
{
	fstream fin("Book.txt",ios::in);
	book obj3;
	ios::beg;
	while(!(fin.eof()))
	{
		fin.read((char*)&obj3,sizeof(obj3));
		if(!(strcmp(obj3.get_name(),name)))
		{
			obj3.put_entry();
			break;
		}
	}
	fin.close();
}
void search_book_author(char name[80])
{
	fstream fin("Book.txt",ios::in);
	book obj3;
	ios::beg;
	while(!(fin.eof()))
	{
		fin.read((char*)&obj3,sizeof(obj3));
		if(!(strcmp(obj3.get_author(),name)))
		{
			obj3.put_entry();
			break;
		}
	}
	fin.close();
}
void search_book_publisher(char name[80])
{
	fstream fin("Book.txt",ios::in);
	book obj3;
	ios::beg;
	while(!(fin.eof()))
	{
		fin.read((char*)&obj3,sizeof(obj3));
		if(!(strcmp(obj3.get_publisher(),name)))
		{
			obj3.put_entry();
			break;
		}
	}
	fin.close();
}
void search_student(char name[80])
{
	fstream fin("Student.txt",ios::in);
	stdid obj4;
	ios::beg;
	while(!(fin.eof()))
	{
		fin.read((char*)&obj4,sizeof(obj4));
		if(!(strcmp(obj4.get_name(),name)))
		{
			obj4.prnt_stdid();
			break;
		}
	}
	fin.close();
}
void search_student_id(char name[80])
{
	fstream fin("Student.txt",ios::in);
	stdid obj4;
	ios::beg;
	while(!(fin.eof()))
	{
		fin.read((char*)&obj4,sizeof(obj4));
		if(!(strcmp(obj4.get_serial(),name)))
		{
			obj4.prnt_stdid();
			break;
		}
	}
	fin.close();
}
int struct_cmp(serial_no s1,serial_no s2)
{
	if((!(strcmp(s1.department,s2.department)))&&(!(strcmp(s1.rack,s2.rack)))&&(s1.row==s2.row)&&(!(strcmp(s1.book,s2.book)))&&(!(strcmp(s1.copy_no,s2.copy_no))))
		return 1;
	else
		return 0;
}
void book_deletion()
{
	serial_no s1;
	book obj;
	int flag=0;
	char ans;
	fstream fin("Book.txt",ios::in);
	fstream fout("Temp.txt",ios::out);
	ios::beg;
	cout<<"Enter the first two letters of the Department to which book belongs:";
	gets(s1.department);
	cout<<"Enter the rack in which the book is in:";
	gets(s1.rack);
	cout<<"Enter the row in which book is kept:";
	cin>>s1.row;
	cout<<"Enter the first two letters of first name and second word of name of book(write first two letters of first word only for one word name book)";
	gets(s1.book);
	cout<<"Enter the copy number of book:";
	gets(s1.copy_no);
	while(!fin.eof())
	{
		fin.read((char*)&obj,sizeof(obj));
		if(struct_cmp(s1,obj.get_sno()))
		{
			cout<<"Record found";
			cout<<"Details of record is:";
			obj.put_entry();
			flag=1;
			cout<<"Are you sure you want to delete this record?(y/n)";
			cin>>ans;
			if(ans=='n'||ans=='N')
			{
				fout.write((char*)&obj,sizeof(obj));
			}
			break;
		}
		else
			fout.write((char*)&obj,sizeof(obj));
	}
	if(flag==1)
	{
		while(!fin.eof())
		{
			fin.read((char*)&obj,sizeof(obj));
			fout.write((char*)&obj,sizeof(obj));
		}
	}
	else
		cout<<"Record not found";
	fin.close();
	fout.close();
	remove("Book.txt");
	rename("Temp.txt","Book.txt");
}
void stud_delete()
{
	stdid obj;
	char s1[9],ans;
	int flag;
	cout<<"Enter the admission number of student whose record is to be deleted";
	gets(s1);
	fstream fin("Student.txt",ios::in);
	fstream fout("Temp.txt",ios::out);
	ios::beg;
	while(!fin.eof())
	{
		fin.read((char*)&obj,sizeof(obj));
		if(!strcmp(obj.get_serial(),s1))
		{
			cout<<"Record found";
			cout<<"Details of record is:";
			obj.prnt_stdid();
			flag=1;
			cout<<"Are you sure you want to delete this record?(y/n)";
			cin>>ans;
			if(ans=='n'||ans=='N')
			{
				fout.write((char*)&obj,sizeof(obj));
			}
			break;
		}
		else
			fout.write((char*)&obj,sizeof(obj));
	}
	if(flag==1)
	{
		while(!fin.eof())
		{
			fin.read((char*)&obj,sizeof(obj));
			fout.write((char*)&obj,sizeof(obj));
		}
	}
	else
		cout<<"Record not found";
	fin.close();
	fout.close();
	remove("Student.txt");
	rename("Temp.txt","Student.txt");
}
void lib_delete()
{
	librarian obj;
	char user[14],pass[14],ans;
	int flag=0;
	cout<<"\nEnter username of librarian:";
	gets(user);
	fstream fin("Librarian.txt",ios::in);
	fstream fout("Temp.txt",ios::out);
	ios::beg;
	while(!fin.eof())
	{
		fin.read((char*)&obj,sizeof(obj));
		if(!strcmp(obj.get_user(),user))
		{
			cout<<"Record found";
			cout<<"Details of record is:";
			obj.put_data();
			flag=1;
			cout<<"Enter the password:";
			gets(pass);
			if(strcmp(pass,obj.get_pass()))
			{
				cout<<"Wrong Password!!!!Unable to delete";
				fout.write((char*)&obj,sizeof(obj));
			}
			else
			{
				cout<<"Are you sure you want to delete this record?(y/n)";
				cin>>ans;
				if(ans=='n'||ans=='N')
				{
					fout.write((char*)&obj,sizeof(obj));
				}
			}
			break;
		}
		else
			fout.write((char*)&obj,sizeof(obj));
	}
	if(flag==1)
	{
		while(!fin.eof())
		{
			fin.read((char*)&obj,sizeof(obj));
			fout.write((char*)&obj,sizeof(obj));
		}
	}
	else
		cout<<"Record not found";
	fin.close();
	fout.close();
	remove("Librarian.txt");
	rename("Temp.txt","Librarian.txt");
}
void stud_modify(int ch)
{
	char sno[9];
	int flag=0;
	stdid obj;
	fstream fin("Student.txt",ios::in|ios::out);
	ios::beg;
	cout<<"Enter the admission number of student whose record is to be modified:";
	gets(sno);
	while(!(fin.eof()))
	{
		fin.read((char*)&obj,sizeof(obj));
		if(!(strcmp(obj.get_serial(),sno)))
		{
			if(!ch)
				obj.modify_record();
			else
				obj.stud_modify();
			fin.seekp(-1*sizeof(obj),ios::cur);
			fin.write((char*)&obj,sizeof(obj));
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"No record found";
	fin.close();
}
void book_modify()
{
	serial_no s1;
	int flag=0;
	book obj;
	cout<<"Enter the first two letters of the Department to which book belongs:";
	gets(s1.department);
	cout<<"Enter the rack in which the book is in:";
	gets(s1.rack);
	cout<<"Enter the row in which book is kept:";
	cin>>s1.row;
	cout<<"Enter the first two letters of first name and second word of name of book(write first two letters of first word only for one word name book)";
	gets(s1.book);
	cout<<"Enter the copy number of book:";
	gets(s1.copy_no);
	fstream fin("Book.txt",ios::in|ios::out);
	while(!(fin.eof()))
	{
		fin.read((char*)&obj,sizeof(obj));
		if((struct_cmp(obj.get_sno(),s1)))
		{
			obj.modify();
			fin.seekp(-1*sizeof(obj),ios::cur);
			fin.write((char*)&obj,sizeof(obj));
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"No record found";
	fin.close();
}
void lib_modify()
{
	int flag=1;
	char username[14];
	librarian obj;
	fstream fin("Librarian.txt",ios::in|ios::out);
	cout<<"Enter librarian username whose record you want to modify";
	gets(username);
	while(fin.read((char *)&obj,sizeof(obj)))
	{
		if(!(strcmp(obj.get_user(),username)))
		{
			obj.modify();
			fin.seekp(-1*sizeof(obj),ios::cur);
			fin.write((char*)&obj,sizeof(obj));
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"No record found";
	fin.close();
}
void stud_show()
{
	fstream fin("Student.txt",ios::in);
	stdid obj;
	cout<<"\nAll students Record";
	while(fin.read((char*)&obj,sizeof(obj)))
		obj.prnt_stdid();
	fin.close();
}
void book_show()
{
	fstream fin("Book.txt",ios::in);
	book obj;
	cout<<"\nAll Books Record";
	while(fin.read((char*)&obj,sizeof(obj)))
		obj.put_entry();
	fin.close();
}
void lib_show()
{
	fstream fin("Librarian.txt",ios::in);
	librarian obj;
	cout<<"\nAll librarians Record";
	while(fin.read((char*)&obj,sizeof(obj)))
		obj.put_data();
	fin.close();
}
void issue(char sn[9])
{
	fstream fin1("Book.txt",ios::in|ios::out);
	fstream fin2("Student.txt",ios::in|ios::out);
	serial_no sno;
	book obj1;
	stdid obj2;
	char book_name[80];
	int flag1=0,flag2=0,flag3=0,i=2;
	cout<<"Enter the book name:";
	gets(book_name);
	cout<<"Enter the first two character of Department to which book belongs:";
	scanf("%[^\n]",sno.department);
	cout<<"Enter the rack number:";
	scanf("%[^\n]",sno.rack);
	cout<<"Enter the row in the rack:";
	cin>>sno.row;
	cout<<"Enter the copy number:";
	scanf("[^\n]",sno.copy_no);
	sno.book[0]=book_name[0];
	sno.book[1]=book_name[1];
	while(book_name[i]!='\0')
	{
		if(book_name[i]==' '&&book_name[i+1]!=' ')
		{
			sno.book[3]=book_name[i+1];
			sno.book[4]=book_name[i+2];
			break;
		}
		i++;
	}
	sno.book[5]='\0';
	ios::beg;
	while(!fin1.eof())
	{
		fin1.read((char *)&obj1,sizeof(obj1));
		if(struct_cmp(obj1.get_sno(),sno))
		{
			flag1=1;
			if(obj1.check_issued()=='n')
			{
				while(fin2.read((char *)&obj2,sizeof(obj2)))
				{
				if(!strcmp(obj2.get_serial(),sn))
				{
					if(obj2.get_no_issued()<3)
					{
						obj2.issue(sno);
						obj1.issue(obj2);
						flag2=1;
					}
					fin1.seekp(-1*sizeof(obj1),ios::cur);
					fin1.write((char *)&obj1,sizeof(obj1));
					fin2.seekp(-1*sizeof(obj2),ios::cur);
					fin2.write((char *)&obj2,sizeof(obj2));
					break;
				}
				}
			}
			else
				flag3=1;
			break;
		}
	}
	if(flag1==0)
		cout<<"Book not found";
	else if(flag3==1)
		cout<<"Book already issued";
	else if(flag2==0)
		cout<<"You have already issued a maximum of 4 books";
	fin1.close();
	fin2.close();
}
void deposit(char sn[9])
{
	fstream fin1("Book.txt",ios::in|ios::out);
	fstream fin2("Student.txt",ios::in|ios::out);
	serial_no sno;
	book obj1;
	stdid obj2;
	char book_name[80];
	int flag1=0,i=2;
	cout<<"Enter the book name:";
	gets(book_name);
	cout<<"Enter the first two character of Department to which book belongs:";
	scanf("%[^\n]",sno.department);
	cout<<"Enter the rack number:";
	scanf("%[^\n]",sno.rack);
	cout<<"Enter the row in the rack:";
	cin>>sno.row;
	cout<<"Enter the copy number:";
	scanf("[^\n]",sno.copy_no);
	sno.book[0]=book_name[0];
	sno.book[1]=book_name[1];
	while(book_name[i]!='\0')
	{
		if(book_name[i]==' '&&book_name[i+1]!=' ')
		{
			sno.book[3]=book_name[i+1];
			sno.book[4]=book_name[i+2];
			break;
		}
		i++;
	}
	sno.book[5]='\0';
	ios::beg;
	while(fin2.read((char *)&obj2,sizeof(obj2)))
	{
		if(!strcmp(obj2.get_serial(),sn))
		{
			flag1=obj2.deposit(sno);
			if(flag1==1)
			{
				while(fin1.read((char *)&obj1,sizeof(obj1)))
				{
					if(struct_cmp(obj1.get_sno(),sno))
					{
						obj1.deposit();
						break;
					}
				}
				cout<<"Book deposited";
				fin1.seekp(-1*sizeof(obj1),ios::cur);
				fin1.write((char *)&obj1,sizeof(obj1));
				fin2.seekp(-1*sizeof(obj2),ios::cur);
				fin2.write((char *)&obj2,sizeof(obj2));
				break;
			}
			else
				cout<<"Book not issued under your name";
		}
	}
	fin1.close();
	fin2.close();
}
void lib_menu()
{
	int ch,flag=0;
	librarian obj;
	fstream fin("Librarian.txt",ios::in);
	char user[14],pass[14],name[80],id[9];
	cout<<"Enter the username:";
	gets(user);
	ios::beg;
	while(fin.read((char *)&obj,sizeof(obj)))
	{
		if(!strcmp(obj.get_user(),user))
		{
			flag=1;
			do
			{
				cout<<"Enter the password:";
				gets(pass);
				if(strcmp(pass,obj.get_pass()))
				{
					cout<<"Wrong password!!!";
				}
			}while(strcmp(pass,obj.get_pass()));
			break;
		}
	}
	if(flag==0)
		cout<<"Incorrect username";
	else
	{
		while(1)
		{
			cout<<"\nLibrarian Menu";
			cout<<"\n1.Add Student data";
			cout<<"\n2.Add Books data";
			cout<<"\n3.Add Librarian data";
			cout<<"\n4.Delete Student data";
			cout<<"\n5.Delete Books data";
			cout<<"\n6.Delete Librarian data";
			cout<<"\n7.Modify Student data";
			cout<<"\n8.Modify Books data";
			cout<<"\n9.Modify Librarian data";
			cout<<"\n10.Show Student Record";
			cout<<"\n11.Show Book Record";
			cout<<"\n12.Show Librarian Record";
			cout<<"\n13.Search student Record by name";
			cout<<"\n14.Search student record by admission number";
			cout<<"\n15.Exit";
			cout<<"Enter the number corresponding to your choice";
			cin>>ch;
			switch(ch)
			{
				case 1: if(count==1)
						student_record();
					else
						student_append();
					count++;
					break;
				 case 2: if(count1==1)
						book_record();
					 else
						book_append();
					 count1++;
					 break;
				 case 3: lib_append();
					 break;
				 case 4: stud_delete();
					 break;
				 case 5: book_deletion();
					 break;
				 case 6: lib_delete();
					 break;
				 case 7: stud_modify(0);
					 break;
				 case 8: book_modify();
					 break;
				 case 9: lib_modify();
					 break;
				case 10: stud_show();
					 break;
				case 11: book_show();
					 break;
				case 12: lib_show();
					 break;
				case 13: cout<<"\nEnter the Student name:";
					 gets(name);
					 search_student(name);
					 break;
				case 14: cout<<"\nEnter the student id:";
					 gets(id);
					 search_student_id(id);
					 break;
				case 15: break;
				default: cout<<"\nWrong choice!!!!";
					 break;
			}
			if(ch==15)
				break;
		}
	}
}
void stud_menu()
{
	stdid obj;
	int ch,flag=0;
	fstream fin("Student.txt",ios::in);
	char name[80],user[14],pass[14],book[80],author[80],publisher[80];
	cout<<"Enter your registered name:";
	gets(name);
	ios::beg;
	while(fin.read((char *)&obj,sizeof(obj)))
	{
		if(!strcmp(obj.get_name(),name))
		{
			flag=1;
			if(obj.get_user()=="\0")
				obj.user_information();
			else
			{
				cout<<"Enter the username:";
				gets(user);
				if(!strcmp(obj.get_user(),user))
				{
					do
					{
						cout<<"Enter the password:";
						gets(pass);
						if(strcmp(pass,obj.get_pass()))
						{
							cout<<"Wrong password!!!";
						}
					}while(strcmp(pass,obj.get_pass()));
				}
				else
					cout<<"\nWrong username!!!";
			}
		}
		break;
	}
	if(flag==0)
	{
		cout<<"No Record found";
	}
	else
	{
		while(1)
		{
			cout<<"\nStudent Menu";
			cout<<"\n1.Issue/Renew Books";
			cout<<"\n2.Deposit Books";
			cout<<"\n3.Search Book by name";
			cout<<"\n4.Search Book by author name";
			cout<<"\n5.Search Book by publisher name";
			cout<<"\n6.Change Username or Password";
			cout<<"\n7.Exit";
			cout<<"Enter the number corresponding to your choice:";
			cin>>ch;
			switch(ch)
			{
				case 1: issue(obj.get_serial());
					break;
				case 2: deposit(obj.get_serial());
					break;
				case 3: cout<<"Enter the book name:";
					gets(book);
					search_book_name(book);
					break;
				case 4: cout<<"Enter the author name:";
					gets(author);
					search_book_author(author);
					break;
				case 5: cout<<"Enter the publisher name:";
					gets(publisher);
					search_book_publisher(publisher);
					break;
				case 6: stud_modify(1);
					break;
				case 7: break;
			       default: cout<<"\nWrong choice";
					break;
			}
			if(ch==7)
				break;
		}
	}
}
void main()
{
	clrscr();
	librarian obj;
	int ch;
	cout<<"Enter information about librarians:\n";
	lib_record();
	while(1)
	{
		cout<<"\nInput the number corresponding to group you belong:";
		cout<<"\n1.Librarian";
		cout<<"\n2.Student\n";
		cin>>ch;
		switch(ch)
		{
			case 1: lib_menu();
				break;
			case 2: stud_menu();
				break;
		       default: cout<<"\nWrong choice!!!";
				break;
		}
	}
}