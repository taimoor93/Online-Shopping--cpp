#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
void admin();
void menu();
void deletestock();
void viewstock();

struct library {
string book;
};


void addtock(library b[]);
void mem(library b[]);

void admin()
{
string name;
string pass;
char f;
cout << "Welcome to Library managment system" << endl;
cout << "Press f to continue: "; cin >> f;
system("CLS");
if (f == 'f' || f == 'F')
{
cout << "Welcome admin!" << endl << endl;
cout << "Username: "; cin >> name; cout << endl;
cout << "Password: "; cin >> pass; cout << endl;
if (name == "alyan" && pass == "alyan12")
{
system("CLS");
menu();
}
else
{
cout << "Invalid username or password" << endl;
system("CLS");
admin();
}
}

}

void menu()
{
system("CLS");
library b[10];
int choice;
cout << "Welcome user!" << endl << endl;
cout << "Select any option to proceed" << endl;
cout << "1) add a book " << endl;
cout << "2) view stock" << endl;
cout << "3) delete stock" << endl;
cout << "4) members data" << endl;
cout << "Enter choice in numeric: "; cin >> choice; cout << endl;
switch (choice)
{
case 1: addtock(b);
break;
case 2: viewstock();
break;
case 3: deletestock();
break;
case 4: mem(b);
break;

}
system("CLS");
}

void addtock(struct library b[])
{
system("CLS");
int a;
    b[10].book;
ofstream stock("stock.txt");
cout << "Enter quantity of books to add : "; cin >> a;
for (int i = 0; i < a; i++) {
cout << "Enter " << i + 1 <<" book name to add in stock : ";
   cin >> b[i].book ;
stock << b[i].book;
}
stock.close();
cout << "UPDATED STOCK" << endl;
viewstock();
}

void viewstock()
{
system("CLS");
char a;
string line;

ifstream view("stock.txt");
while (getline(view, line))
{
cout << endl;
cout << line << endl << endl;
}
view.close();

cout << "press m to go main menu and y to proceed to login: "; cin >> a;
if (a == 'm' || a == 'M')
{
system("CLS");
menu();
}
else if (a == 'y' || a == 'Y')
{
system("CLS");
admin();
}
}

void deletestock()
{
system("CLS");
char a;
char del[100];

struct library lib;

cout<<"\n\t Enter stock name ";
cin>>del;

ifstream view("stock.txt");
ofstream write("delete.txt");

view>>lib.book;

while(!view.eof())
{
   if(lib.book != del)
   {
       write <<endl;
       write <<lib.book;
   
   }
   else
   {
       cout<<endl<<endl<<"\tRecord Deleted...";
   }
   
   view >> lib.book;
 
}

write.close();
view.close();

remove("stock.txt");
rename("delete.txt","stock.txt");

getchar();


cout << "press m to go main menu and y to proceed to login: "; cin >> a;
if (a == 'm' || a == 'M')
{
system("CLS");
menu();
}
else if (a == 'y' || a == 'Y')
{
system("CLS");
admin();
}
}



void mem(struct library b[])
{
system("CLS");
int choice, c;
char a;
char i;
//char name[20];
b[0].book; string line;
string xbook;
cout << "Welcome to members data" << endl;
cout << "Select option to check in numeric" << endl;
cout << "1) Penalty" << endl;
cout << "2) Issue book" << endl;
cout << "3) Recieve book" << endl;
cout << "Enter your choice: "; cin >> choice;
if (choice == 2)
{
ifstream st("stock.txt");
ofstream st1("upstock.txt");
st.open("stock.txt");

st1.open("upstock.txt");

while (st.eof() == true)
{
st >> xbook;
st1 << xbook;

}
st.close();
st1.close();
cout << endl;
cout << "Enter i to confirm issuance of book and to view updated stock: "; cin >> i;

if (i == 'i' || i == 'I')
{
ifstream st1;
st1.open("upstock");
cout << "Enter amount of books issue: "; cin >> c;
cout << "Enter book name to issue: "; cin >> line;

for (int j = 0; j < 9; j++)
{
while (!st1.eof() && line != b[j].book)
{
getline(st1, line);
cout << line << endl;
}
}
ofstream st("stock.txt");

st1.open("upstock.txt");
st.open("stock.txt");

while (st1.eof() == true)
{
st1 >> xbook;
st << xbook;

}
}
viewstock();
st.close();
st1.close();
}
}
/*if (st.is_open() == true)
{ cout << "File not open" << endl;*/
/////*ofstream st1;
////cout << "Enter Member data with name and extension to save in file : "; cin >> name; cout << endl;*/
// int j = 0;
// j <= 10;
// cout << "Enter book name to issue: "; cin >> b[j].book;
//    while (!st.eof() && line != b[j].book);
// {
// getline(st, line);
// cout << line << endl;
// }

//}
//st.close();
//viewstock();
///*cout << "press m to go main menu and y to proceed to login: "; cin >> a;
//if (a == 'm' || a == 'M')
//{
// system("CLS");
// menu();
//}
//else if (a == 'y' || a == 'Y')
//{
// system("CLS");
// admin();
//}*/

//void penalty()
//{
// char name[20];
// string book;
// string xbook;
// ifstream st1;
// if (book == xbook)
// {
// }
//}


int main()
{
admin();
}
