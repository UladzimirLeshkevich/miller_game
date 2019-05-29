#include "save_game_time.hxx"
#include <fstream>
#include <iostream>

void save_file(int m2, int m, int s2, int s)
{
    std::ofstream file;
    file.open("save.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cerr << "Cannot open savefile \n";
        // return EXIT_FAILURE;
    }
    // file << "Last game time is " << m2 << m << "." << s2 << s << "\n";
    file << m2 << m << "." << s2 << s << "\n";
    file.close();
}

float read_time_frome_file()
{
    float         time;
    std::ifstream file;
    file.open("save.txt");
    file >> time;
    file.close();
    return time;
}

void write_time(float time)
{
    std::ofstream file;
    file.open("save_float.txt", std::ios::out);
    if (!file.is_open())
    {
        std::cerr << "Cannot open savefile \n";
        // return EXIT_FAILURE;
    }
    file << time;
    file.close();
}
