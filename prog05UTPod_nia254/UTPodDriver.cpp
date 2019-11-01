/* utPod_driver.cpp
Demo Driver for the UtPod.

Nafis Akbar
EE 312 10/29/19

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Travis Scott", "Goosebumps", 30) ;
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Gun's N Roses", "Paradise City", 20);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
     
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;   

    Song s3("Kid Cudi", "Mr. Rager", 25);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Rihanna", "Disturbia", 17);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("MGMT", "Electric Feel", 44);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    Song s6("Miguel", "Skywalker", 36); 
    result = t.addSong(s6);

    Song s7("Red Hot Chili Peppers", "Californication", 71); 
    result = t.addSong(s7);   
    
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;

    t.shuffle();
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s6);
    cout << "delete result = " << result << endl;
    t.showSongList();
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    t.showSongList();
    
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << " MB" << endl;
    

}