#include "load_texture.hxx"

//#include "engine.hxx"

// int              dot_t;
// std::vector<int> time_sprite;

void load_texture(engine& object)
{
    object.set_resources_path("res/");
    dot_t = object.load_png("dot.png");
    std::cout << "!\n";
    time_sprite.push_back(object.load_png("0.png"));
    time_sprite.push_back(object.load_png("1.png"));
    time_sprite.push_back(object.load_png("2.png"));
    time_sprite.push_back(object.load_png("3.png"));
    time_sprite.push_back(object.load_png("4.png"));
    time_sprite.push_back(object.load_png("5.png"));
    time_sprite.push_back(object.load_png("6.png"));
    time_sprite.push_back(object.load_png("7.png"));
    time_sprite.push_back(object.load_png("8.png"));
    time_sprite.push_back(object.load_png("9.png"));
}
