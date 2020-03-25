#include "MattMovie.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
MattMovie::MattMovie()
{
this->numOfRatings = 0;
this->audience = "Null";
this->rating = 0;
this->Name = "Null";

void InputMeta();
void GetData();
void addRating();
void SaveData(int totalMovies);
void setMovies();
//this->GetData();
}
void MattMovie::GetData(){
    cout<<"Matthew's Test"<<endl;
    cout<<"Name: "<<this->Name<<endl;
    cout<<"Rating: "<<this->audience<<endl;
    cout<<"Reveiws : "<<this->rating<<endl;
    cout<<"Total Reviews: "<<this->numOfRatings<<endl;
    cout<<"___________"<<endl;
    //cout<<  <<endl<<endl;
}
void MattMovie::InputMeta(){;

cout<<"Enter Name For Movie:   ";
cin >> this->Name;
cout<<"\r";
cout<<"Enter Rating for movie: ";
cin >> this->audience;
cout<<"\r";
cout<<"Enter Review for this movie: ";
cin >> this->rating;
cout<<endl;
}
void MattMovie::addRating(){
this->numOfRatings++;
double k=0;
cout<<"Enter Your Review: ";
cin >> k;
cout << "\r";
cout<<"";
this->rating=(k+this->rating)/2;
}
void MattMovie::SaveData(int totalMovies){
    ifstream infile;
    infile.open("afile.txt");
    string data;
    infile >> data;
    cout << data<<endl;
    infile.close();
ofstream outfile;
   outfile.open("afile.txt");
   outfile<<totalMovies<<endl;
  // for (int i=0; i<totalMovies*4;i++){if (i==9){outfile<<"Hello"<<endl;}if (i!=9){outfile<<endl;}}
  for (int i=0; i<totalMovies*4;i++){outfile<<endl;}
   outfile<<this->Name<<endl<<this->audience<<endl<<this->rating<<endl<<this->numOfRatings<<endl;
}
void closeFile(){

}
void setMovies(){
}
