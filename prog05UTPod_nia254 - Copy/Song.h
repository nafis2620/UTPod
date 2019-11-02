#ifndef SONG_H
#define SONG_H

#include <cstdlib>
#include <iostream> 
#include <string>





class Song {

    private:
        std::string artist;
        std::string track;
        int size;

    public:

        //song constructor//
        Song(std::string xartist, std::string xtrack, int MEM);
        //null constructor//
        Song();
   //get and set methods//
        std::string getArtist() const;
        void setArtist(std::string xartist);

        std::string getTrack() const;
        void setTrack(std::string xtrack);

        int getSize() const;
        void setSize(int MEM);

        bool operator == (Song const &rhs);
        bool operator > (Song const &rhs);
        bool operator < (Song const &rhs);

};

#endif