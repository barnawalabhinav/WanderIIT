#include <iostream>
#include "map_back.h"
#include <fstream>

using namespace std;

int main()
{
    ofstream(fout);
    fout.open("Gamemap_back.h");
    fout << ("#include <stdint.h>\n\n#define MAP_FRAME_COUNT " + to_string(MAP_FRAME_COUNT) + "\n#define MAP_FRAME_WIDTH " + to_string(MAP_FRAME_WIDTH) + "\n#define MAP_FRAME_HEIGHT " + to_string(MAP_FRAME_HEIGHT) + "\n\nstatic const int map_data[905466] =\n{\n");

    for (long i = 0; i < 905465; i++) {
        if ( map_data[i] == 0xff000000) {
            fout << "1, ";
        }
        else{
            fout << "0, ";
        }
    }
    if ( map_data[905465] == 0xff000000) {
            fout << "1";
    }
    else{
        fout << "0";
    }
    fout << "\n};";

    fout.close();
}