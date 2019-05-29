#pragma once
#include "engine.hxx"

int              dot_t;
std::vector<int> time_sprite;
std::vector<int> idle_sprite;
std::vector<int> jump_sprite;
std::vector<int> run_sprite;
std::vector<int> dead_sprite;
std::vector<int> fire_sprite;
std::vector<int> long_fire_sprite;
std::vector<int> bell_sprite;

int platform;
int raindrop;
int cloud_t;
int background_t;
int millbase_0;
int millbase;
int down;
int up;
int right;
int left;
int over_t;
int title_t;
int pause_t;

void load_texture(engine& obj)
{
    obj.set_resources_path("res/");
    dot_t = obj.load_png("dot.png");
    std::cout << "!\n";
    time_sprite.push_back(obj.load_png("0.png"));
    time_sprite.push_back(obj.load_png("1.png"));
    time_sprite.push_back(obj.load_png("2.png"));
    time_sprite.push_back(obj.load_png("3.png"));
    time_sprite.push_back(obj.load_png("4.png"));
    time_sprite.push_back(obj.load_png("5.png"));
    time_sprite.push_back(obj.load_png("6.png"));
    time_sprite.push_back(obj.load_png("7.png"));
    time_sprite.push_back(obj.load_png("8.png"));
    time_sprite.push_back(obj.load_png("9.png"));

    platform     = obj.load_png("platform.png");
    raindrop     = obj.load_png("raindrop.png");
    cloud_t      = obj.load_png("cloud.png");
    background_t = obj.load_png("background.png");
    millbase_0   = obj.load_png("millbase.png");
    millbase     = obj.load_png("millbase2.png");
    down         = obj.load_png("down.png");
    up           = obj.load_png("up.png");
    right        = obj.load_png("right.png");
    left         = obj.load_png("left.png");
    over_t       = obj.load_png("over.png");
    title_t      = obj.load_png("title.png");
    pause_t      = obj.load_png("pause.png");

    idle_sprite.push_back(obj.load_png("Idle (1).png"));
    idle_sprite.push_back(obj.load_png("Idle (2).png"));
    idle_sprite.push_back(obj.load_png("Idle (3).png"));
    idle_sprite.push_back(obj.load_png("Idle (4).png"));
    idle_sprite.push_back(obj.load_png("Idle (5).png"));
    idle_sprite.push_back(obj.load_png("Idle (6).png"));
    idle_sprite.push_back(obj.load_png("Idle (7).png"));
    idle_sprite.push_back(obj.load_png("Idle (8).png"));
    idle_sprite.push_back(obj.load_png("Idle (9).png"));
    idle_sprite.push_back(obj.load_png("Idle (10).png"));

    run_sprite.push_back(obj.load_png("Run (1).png"));
    run_sprite.push_back(obj.load_png("Run (2).png"));
    run_sprite.push_back(obj.load_png("Run (3).png"));
    run_sprite.push_back(obj.load_png("Run (4).png"));
    run_sprite.push_back(obj.load_png("Run (5).png"));
    run_sprite.push_back(obj.load_png("Run (6).png"));
    run_sprite.push_back(obj.load_png("Run (7).png"));
    run_sprite.push_back(obj.load_png("Run (8).png"));

    jump_sprite.push_back(obj.load_png("Jump (1).png"));
    jump_sprite.push_back(obj.load_png("Jump (2).png"));
    jump_sprite.push_back(obj.load_png("Jump (3).png"));
    jump_sprite.push_back(obj.load_png("Jump (4).png"));
    jump_sprite.push_back(obj.load_png("Jump (5).png"));
    jump_sprite.push_back(obj.load_png("Jump (6).png"));
    jump_sprite.push_back(obj.load_png("Jump (7).png"));
    jump_sprite.push_back(obj.load_png("Jump (8).png"));
    jump_sprite.push_back(obj.load_png("Jump (9).png"));
    jump_sprite.push_back(obj.load_png("Jump (10).png"));

    dead_sprite.push_back(obj.load_png("Dead (1).png"));
    dead_sprite.push_back(obj.load_png("Dead (2).png"));
    dead_sprite.push_back(obj.load_png("Dead (3).png"));
    dead_sprite.push_back(obj.load_png("Dead (4).png"));
    dead_sprite.push_back(obj.load_png("Dead (5).png"));
    dead_sprite.push_back(obj.load_png("Dead (6).png"));
    dead_sprite.push_back(obj.load_png("Dead (7).png"));
    dead_sprite.push_back(obj.load_png("Dead (8).png"));
    dead_sprite.push_back(obj.load_png("Dead (9).png"));
    dead_sprite.push_back(obj.load_png("Dead (10).png"));

    fire_sprite.push_back(obj.load_png("fire_ani.png"));
    fire_sprite.push_back(obj.load_png("fire_ani2.png"));
    fire_sprite.push_back(obj.load_png("fire_ani3.png"));
    fire_sprite.push_back(obj.load_png("fire_ani4.png"));
    fire_sprite.push_back(obj.load_png("fire_ani5.png"));
    fire_sprite.push_back(obj.load_png("fire_ani4.png"));
    fire_sprite.push_back(obj.load_png("fire_ani3.png"));
    fire_sprite.push_back(obj.load_png("fire_ani2.png"));

    long_fire_sprite.push_back(obj.load_png("long_fire.png"));
    long_fire_sprite.push_back(obj.load_png("long_fire2.png"));
    long_fire_sprite.push_back(obj.load_png("long_fire3.png"));
    long_fire_sprite.push_back(obj.load_png("long_fire4.png"));
    long_fire_sprite.push_back(obj.load_png("long_fire5.png"));

    bell_sprite.push_back(obj.load_png("bell.png"));
    bell_sprite.push_back(obj.load_png("bell2.png"));
    bell_sprite.push_back(obj.load_png("bell3.png"));
    bell_sprite.push_back(obj.load_png("bell2.png"));
}
