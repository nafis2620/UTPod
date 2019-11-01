#include <cstdlib>
#include <iostream>
#include "Song.h"
#include <string>

using namespace std;

//Song constructor//

Song::Song(string xartist, string xtrack, int MEM){

    artist = xartist;
    track = xtrack;
    size = MEM;
}

//null constructor//

Song::Song(){
    artist = "";
    track = "";
    size = 0;

}


//get and set methods//

string Song::getArtist() const{
    return artist;
}

void Song::setArtist( string xartist) {
    artist = xartist;
}

string Song::getTrack() const{
    return track;
}

void Song::setTrack( string xtrack) {
    track = xtrack;
}

int Song::getSize() const{
    return size;
}

void Song::setSize( int MEM) {
    size = MEM;
}

//operator if duplicate song or not///

bool Song::operator == (Song const &rhs){
    return ((this->artist == rhs.getArtist()) &&(this->track == rhs.getTrack()) && (this->size == rhs.getSize()));
}

//overload operators//

bool Song::operator > (Song const &rhs){

    if (this->artist > rhs.getArtist()){
        return true;
    }
    else if (this->artist < rhs.getArtist()) {
        return false;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track > rhs.getTrack())) {
        return true;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track < rhs.getTrack())) {
        return false;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track == rhs.getTrack()) && (this->size > rhs.getSize())){
        return true;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track == rhs.getTrack()) && (this->size < rhs.getSize())){
        return false;
    }
}

bool Song::operator < (Song const &rhs){

    if (this->artist < rhs.getArtist()){
        return true;
    }
    else if (this->artist > rhs.getArtist()) {
        return false;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track < rhs.getTrack())) {
        return true;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track > rhs.getTrack())) {
        return false;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track == rhs.getTrack()) && (this->size < rhs.getSize())){
        return true;
    }

    else if ((this->artist == rhs.getArtist()) && (this->track == rhs.getTrack()) && (this->size > rhs.getSize())){
        return false;
    }
}