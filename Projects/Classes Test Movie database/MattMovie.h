#ifndef MATTMOVIE_H
#define MATTMOVIE_H
#include <string>
class MattMovie
{
    public:
        MattMovie();
        void InputMeta();
        void GetData();
        void addRating();
        void SaveData(int totalMovies);
        protected:

    private:
        double rating;
        int numOfRatings;
        std::string audience;
        std::string Name;


};

#endif // MATTMOVIE_H
