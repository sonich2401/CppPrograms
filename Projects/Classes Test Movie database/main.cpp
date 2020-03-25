#include <iostream>
#include "MattMovie.h"
#include <time.h>
#include <fstream>
using namespace std;
//int getMovies()
int totalMovies=-1;
void newMovie(MattMovie Movie[]){
    totalMovies++;
    Movie[totalMovies].InputMeta();
}
int closeData(MattMovie Movie[]){
//    Movie[0].SaveData();
    return 0;
}
int main()
{
   MattMovie Movie[3];
   newMovie(Movie);
   Movie[0].GetData();
  // closeData(Movie);
   Movie[0].SaveData(3);
return 0;
}
