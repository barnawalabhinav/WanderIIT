#include <iostream>
#include "map.h"
#include <fstream>

using namespace std;

int main()
{
    ofstream(fout);
    fout.open("GameMap.h");
    fout << ("#include <stdint.h>\n\n#define MAP_FRAME_COUNT " + to_string(MAP_FRAME_COUNT) + "\n#define MAP_FRAME_WIDTH " + to_string(MAP_FRAME_WIDTH) + "\n#define MAP_FRAME_HEIGHT " + to_string(MAP_FRAME_HEIGHT) + "\n\nstatic const int map_data[845697] =\n{\n");

    for (long i = 0; i < 845696; i++) {
        switch (map_data[i]) {
            case 0xff000000 : fout << "1, "; break; //Black
            case 0xfffc005e : fout << "2, "; break; //Himadri
            case 0xfffb00ff : fout << "3, "; break; //Kailash
            case 0xff0000ff : fout << "4, "; break; //Main Building
            case 0xff39ff00 : fout << "5, "; break; //LHC
            case 0xff0084ff : fout << "6, "; break; //Library
            case 0xffe500ff : fout << "7, "; break; //Amul
            case 0xff970035 : fout << "8, "; break; //Bharti School
            case 0xff4900d7 : fout << "9, "; break; //Ground
            case 0xff002bd3 : fout << "10, "; break; //Masala Mix
            case 0xffc30040 : fout << "11, "; break; //Rajhdhani
            case 0xffe731d4 : fout << "12, "; break; //Hospital
            case 0xff15009b : fout << "13, "; break; //Udaigiri
            case 0xff2b00d0 : fout << "14, "; break; //Girnar
            case 0xff5050c3 : fout << "15, "; break; //Satpura
            case 0xfff4006f : fout << "16, "; break; //Vidhyanchal
            case 0xffba006a : fout << "17, "; break; //Shivalik
            case 0xff860045 : fout << "18, "; break; //Zanskar
            case 0xff25b100 : fout << "19, "; break; //SAC
            case 0xff43d8bb : fout << "20, "; break; //Kumaon
            case 0xff940ba3 : fout << "21, "; break; //Jwala
            case 0xffb600df : fout << "22, "; break; //Aravali
            case 0xff2400dd : fout << "23, "; break; //Karakoram
            case 0xff3ab79f : fout << "24, "; break; //Nilgiri
            default : fout << "0, "; break; //White
        }
    }
    switch (map_data[845696]) {
        case 0xff000000 : fout << "1"; break; //Black
        case 0xfffc005e : fout << "2"; break; //Himadri
        case 0xfffb00ff : fout << "3"; break; //Kailash
        case 0xff0000ff : fout << "4"; break; //Main Building
        case 0xff39ff00 : fout << "5"; break; //LHC
        case 0xff0084ff : fout << "6"; break; //Library
        case 0xffe500ff : fout << "7"; break; //Amul
        case 0xff970035 : fout << "8"; break; //Bharti School
        case 0xff4900d7 : fout << "9"; break; //Ground
        case 0xff002bd3 : fout << "10"; break; //Masala Mix
        case 0xffc30040 : fout << "11"; break; //Rajhdhani
        case 0xffe731d4 : fout << "12"; break; //Hospital
        case 0xff15009b : fout << "13"; break; //Udaigiri
        case 0xff2b00d0 : fout << "14"; break; //Girnar
        case 0xff5050c3 : fout << "15"; break; //Satpura
        case 0xfff4006f : fout << "16"; break; //Vidhyanchal
        case 0xffba006a : fout << "17"; break; //Shivalik
        case 0xff860045 : fout << "18"; break; //Zanskar
        case 0xff25b100 : fout << "19"; break; //SAC
        case 0xff43d8bb : fout << "20"; break; //Kumaon
        case 0xff940ba3 : fout << "21"; break; //Jwala
        case 0xffb600df : fout << "22"; break; //Aravali
        case 0xff2400dd : fout << "23"; break; //Karakoram
        case 0xff3ab79f : fout << "24"; break; //Nilgiri
        default : fout << "0"; break; //White
    }
    fout << "\n};";

    fout.close();
}