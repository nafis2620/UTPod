#include <cstdlib>
#include <iostream>
#include <fstream>
#include "UTPod.h"
#include "Song.h"

using namespace std;

//constructor//


UtPod::UtPod() {

    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size) {

    if ((size <= 0) || (size >= MAX_MEMORY)){
        memSize = MAX_MEMORY;
    }

    else{
        memSize = size;
    }
    
    songs = NULL;

}
    
int UtPod::addSong(Song const &s) {

    if (getRemainingMemory() < s.getSize()){
        return NO_MEMORY;
    }

    else {
        SongNode *tempx = new SongNode;
        tempx->s.setArtist(s.getArtist());
        tempx->s.setTrack(s.getTrack());
        tempx->s.setSize(s.getSize());
        tempx->next = songs;
        songs = tempx;
        return SUCCESS;

    }

}
int UtPod::removeSong(Song const &s) {
    SongNode *tempx = songs;
    //if song in first node///
    if (songs->s == s){
        if(songs->next == NULL){
            songs = NULL;
        }
        else{
            SongNode *xPtr = songs;
            songs = songs->next;
            delete xPtr;
        
        }
    return SUCCESS;
    }
    //if nodes other than head contain song to delete//
    else {
        while(tempx->next != NULL){
            if(tempx->next->s==s){
                SongNode *xPtr = tempx->next;
                tempx->next = tempx->next->next;
                delete xPtr;
                return SUCCESS;
            }
            else{
                tempx = tempx->next;
            }
        }
    }
// if song not in playlist//
        return NOT_FOUND;
    
}


int UtPod::playlistLength() {
    int playlist = 0;
    if (songs != NULL){
        SongNode *tempx = songs;
        while (tempx != NULL){
            playlist++;
            tempx = tempx->next;
        }
        return playlist;
    }

    else{
        return 0;
    }
}
void UtPod::switchSongs(SongNode* x1, SongNode* x2){
    Song tempx;
    tempx = x1->s;
    x1->s = x2->s;
    x2->s = tempx;
}

//randomize playlist of songs//
void UtPod::shuffle(){

    int playlist = playlistLength();
    if (playlist >= 2) {
        srand(time(NULL));
        int x1, x2;
        SongNode *tempx1, *tempx2;
        for(int i = 0; i < playlist*2; i++){
            tempx1 = songs;
            tempx2 = songs;
            x1 = rand() % playlist;
            x2 = rand() % playlist;
            for (int j = 0; j < x1; j++){
                tempx1 = tempx1->next;
            }
            for (int k = 0; k < x2; k++){
                tempx2 = tempx2->next;
            }
            switchSongs(tempx1, tempx2);
        }
    }
}
//show tracks on playlist
void UtPod::showSongList(){
        SongNode *tempx = songs;
        while (tempx != NULL){
            cout << tempx->s.getArtist() << ", " << tempx->s.getTrack() << ", " << tempx->s.getSize() << "MB" << endl;
            tempx = tempx->next;
        }
}


// bubble sort ///
void UtPod::sortSongList(){
    int playlist = playlistLength();
    SongNode* xPtr = songs;
    SongNode* bottom;
    SongNode* cmpX; // compare with current bottom node//

// check if more than one song//
    if (playlist < 2) {

    }

    else{
        while(xPtr != NULL){
            bottom = xPtr;
            cmpX = xPtr->next;
            while(cmpX != NULL){
                if(cmpX->s < bottom->s){
                    bottom = cmpX;
                }
            cmpX = cmpX->next;
            }
            switchSongs(xPtr, bottom);
            xPtr = xPtr->next;
        }
    }
}

void UtPod::clearMemory(){
    while(songs->next != NULL) {
        removeSong(songs->next->s);
    }
    removeSong(songs->s);
}

int UtPod::getTotalMemory() {
    memSize = 0;
    SongNode* tempx;
    tempx = songs;
    while ( tempx != NULL){
        memSize = memSize + tempx->s.getSize();
        tempx = tempx->next;
    }

    return memSize;
}

int UtPod::getRemainingMemory() {
   int usedMEM = getTotalMemory();
  int freeMEM = MAX_MEMORY - usedMEM;
   return freeMEM;
}

//destructor//
    UtPod::~UtPod(){
        clearMemory();
    }