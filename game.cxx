#include "count_for_timer.hxx"
#include "engine.hxx"
#include "load_texture.hxx"
#include "save_game_time.hxx"

int main(int /*argc*/, char* /*argv*/[])
{
    //заводим движок
    engine obj;

    float time = read_time_frome_file();
    std::cout << "777 " << time << "\n";

    obj.set_window_width(1280);
    obj.set_window_height(720);

    // obj.set_window_width(1920);
    // obj.set_window_height(1080);

    obj.set_resources_path("res/");

    obj.initialize();

    //загружаем текстуры и делаем спрайты
    load_texture(obj);
    std::vector<int> rising_sprite;
    rising_sprite = dead_sprite;
    std::reverse(rising_sprite.begin(), rising_sprite.end());

    //загружаем звуки
    sound_buffer jump         = obj.load_sound("jump1.wav", &jump);
    sound_buffer fire_sound   = obj.load_sound("fire2.wav", &fire_sound);
    sound_buffer bell_sound   = obj.load_sound("bell.wav", &bell_sound);
    sound_buffer bell_sound2  = obj.load_sound("bell.wav", &bell_sound2);
    sound_buffer bell_sound3  = obj.load_sound("bell.wav", &bell_sound3);
    sound_buffer wind_sound   = obj.load_sound("wind.wav", &wind_sound);
    sound_buffer mill_sound   = obj.load_sound("mill.wav", &mill_sound);
    sound_buffer marsh_sound  = obj.load_sound("marsh.wav", &marsh_sound);
    sound_buffer crash_sound  = obj.load_sound("crash.wav", &crash_sound);
    sound_buffer over_sound   = obj.load_sound("over.wav", &over_sound);
    sound_buffer horror_sound = obj.load_sound("horror.wav", &horror_sound);

    //первый запуск игры
    bool first_start = true;

restart:; //рестарт игры после game over!
#include "game_geometry.hxx"

    //назначаем переменные для перемещений в игре
    float speedup            = 0.0f;
    float speeddown          = 0.0f;
    float speedtr            = 0.0f;
    float speedtl            = 0.0f;
    int   jump_flag          = 0;
    int   platform_flag      = 0;
    int   hero_on_the_mill   = 0;
    int   hero_on_the_mill_r = 0;
    int   hero_on_the_mill_c = 0;
    float increment2         = 0.0f;

    //переменные для масштабирования объектов
    float hero_scale      = 0.75f;
    float hero_dead_scale = 1.8f;

    //устанавливаем скорости движения по всем направлениям
    obj.set_speedToRigth(0.015f);
    obj.set_speedToLeft(0.015f);
    obj.set_speedToUp(0.04f);
    obj.set_speedToDown(0.01f);
    float falling_speed_value = -0.025f;
    float jump_speed_value    = 0.05f;
    float cload_speed_value   = 0.01f;
    float fire_speed_1_value  = 0.0008f;
    float fire_speed_2_value  = 0.0008f;
    float fire_speed_3_value  = 0.0008f;

    //платформы вне мельницы
    obj.scale_to_screen(ground);
    obj.scale_to_screen(ground1);
    obj.scale_to_screen(ground2);
    obj.scale_to_screen(ground3);

    //масштабируем колокол над левой мельницей
    obj.trans_matrix(0.65f, 0.5f, bell);
    obj.scale_to_screen(bell);
    obj.trans_matrix(-0.65f, -0.5f, bell);
    obj.trans_matrix(0.65f, 0.5f, bell1);
    obj.scale_to_screen(bell1);
    obj.trans_matrix(-0.65f, -0.5f, bell1);

    //масштабируем колокол над центральной мельницей
    obj.trans_matrix(0.0f, 0.5f, bell4);
    obj.scale_to_screen(bell4);
    obj.trans_matrix(-0.0f, -0.5f, bell4);
    obj.trans_matrix(0.0f, 0.5f, bell5);
    obj.scale_to_screen(bell5);
    obj.trans_matrix(-0.0f, -0.5f, bell5);

    //масштабируем колокол над правой мельницей
    obj.trans_matrix(-0.65f, 0.5f, bell2);
    obj.scale_to_screen(bell2);
    obj.trans_matrix(0.65f, -0.5f, bell2);
    obj.trans_matrix(-0.65f, 0.5f, bell3);
    obj.scale_to_screen(bell3);
    obj.trans_matrix(0.65f, -0.5f, bell3);

    //отмасштабируем главного героя
    obj.trans_matrix(0.65f, 0.3f, hero);
    obj.scale_triangle(hero_scale * obj.get_k_screen(), hero_scale, hero);
    obj.trans_matrix(-0.65f, -0.3f, hero);

    obj.trans_matrix(0.65f, 0.3f, hero1);
    obj.scale_triangle(hero_scale * obj.get_k_screen(), hero_scale, hero1);
    obj.trans_matrix(-0.65f, -0.3f, hero1);

    obj.trans_matrix(0.65f, 0.3f, hero2);
    obj.scale_triangle(hero_scale * obj.get_k_screen(), hero_scale, hero2);
    obj.trans_matrix(-0.65f, -0.3f, hero2);

    obj.trans_matrix(0.65f, 0.3f, hero3);
    obj.scale_triangle(hero_scale * obj.get_k_screen(), hero_scale, hero3);
    obj.trans_matrix(-0.65f, -0.3f, hero3);

    obj.trans_matrix(0.65f, 0.3f, hero4);
    obj.scale_triangle(hero_dead_scale * obj.get_k_screen(), hero_dead_scale,
                       hero4);
    obj.trans_matrix(-0.65f, -0.3f, hero4);

    obj.trans_matrix(0.65f, 0.3f, hero5);
    obj.scale_triangle(hero_dead_scale * obj.get_k_screen(), hero_dead_scale,
                       hero5);
    obj.trans_matrix(-0.65f, -0.3f, hero5);

    obj.trans_matrix(0.65f, 0.3f, hero6);
    obj.scale_triangle(hero_dead_scale * obj.get_k_screen(), hero_dead_scale,
                       hero6);
    obj.trans_matrix(-0.65f, -0.3f, hero6);

    obj.trans_matrix(0.65f, 0.3f, hero7);
    obj.scale_triangle(hero_dead_scale * obj.get_k_screen(), hero_dead_scale,
                       hero7);
    obj.trans_matrix(-0.65f, -0.3f, hero7);

    //подвинем героя в окне game over
    obj.trans_matrix(-0.2f, -0.2f, hero4);
    obj.trans_matrix(-0.2f, -0.2f, hero5);

    //подвинем героя в окне pause
    obj.trans_matrix(0, -0.2f, hero6);
    obj.trans_matrix(0, -0.2f, hero7);

    //подкорректируем положение дождя относительно тучи
    obj.trans_matrix(0.025f, 0.0f, drop);
    obj.trans_matrix(0.025f, 0.0f, drop1);
    obj.trans_matrix(0.025f, 0.0f, drop2);
    obj.trans_matrix(0.025f, 0.0f, drop3);
    obj.trans_matrix(0.025f, 0.0f, drop4);
    obj.trans_matrix(0.025f, 0.0f, drop5);
    obj.trans_matrix(0.025f, 0.0f, drop6);
    obj.trans_matrix(0.025f, 0.0f, drop7);
    obj.trans_matrix(0.025f, 0.0f, drop8);
    obj.trans_matrix(0.025f, 0.0f, drop9);
    obj.trans_matrix(0.025f, 0.0f, drop10);
    obj.trans_matrix(0.025f, 0.0f, drop11);
    obj.trans_matrix(0.025f, 0.0f, drop12);
    obj.trans_matrix(0.025f, 0.0f, drop13);
    obj.trans_matrix(0.025f, 0.0f, drop14);
    obj.trans_matrix(0.025f, 0.0f, drop15);
    obj.trans_matrix(0.025f, 0.0f, drop16);
    obj.trans_matrix(0.025f, 0.0f, drop17);
    obj.trans_matrix(0.025f, 0.0f, drop18);
    obj.trans_matrix(0.025f, 0.0f, drop19);
    obj.trans_matrix(0.025f, 0.0f, drop20);
    obj.trans_matrix(0.025f, 0.0f, drop21);
    obj.trans_matrix(0.025f, 0.0f, drop22);
    obj.trans_matrix(0.025f, 0.0f, drop23);
    obj.trans_matrix(0.025f, 0.0f, drop24);
    obj.trans_matrix(0.025f, 0.0f, drop25);
    obj.trans_matrix(0.025f, 0.0f, drop26);
    obj.trans_matrix(0.025f, 0.0f, drop27);
    obj.trans_matrix(0.025f, 0.0f, drop28);
    obj.trans_matrix(0.025f, 0.0f, drop29);
    obj.trans_matrix(0.025f, 0.0f, drop30);
    obj.trans_matrix(0.025f, 0.0f, drop31);
    obj.trans_matrix(0.025f, 0.0f, drop32);
    obj.trans_matrix(0.025f, 0.0f, drop33);
    obj.trans_matrix(0.025f, 0.0f, drop34);
    obj.trans_matrix(0.025f, 0.0f, drop35);
    obj.trans_matrix(0.025f, 0.0f, drop36);
    obj.trans_matrix(0.025f, 0.0f, drop37);
    obj.trans_matrix(0.025f, 0.0f, drop38);
    obj.trans_matrix(0.025f, 0.0f, drop39);
    obj.trans_matrix(0.025f, 0.0f, drop40);
    obj.trans_matrix(0.025f, 0.0f, drop41);
    obj.trans_matrix(0.025f, 0.0f, drop42);
    obj.trans_matrix(0.025f, 0.0f, drop43);
    obj.trans_matrix(0.025f, 0.0f, drop44);
    obj.trans_matrix(0.025f, 0.0f, drop45);
    obj.trans_matrix(0.025f, 0.0f, drop46);
    obj.trans_matrix(0.025f, 0.0f, drop47);
    obj.trans_matrix(0.025f, 0.0f, drop48);
    obj.trans_matrix(0.025f, 0.0f, drop49);

    //настраиваем вращение мельницы в главном окне
    rotation title_mill;
    title_mill.set_speed_of_rotation(7.0);
    title_mill.set_direction(-1);
    timer title_mill_time;

    int   title_current_angle = 0;
    float title_distant_to_zero_x, title_distant_to_zero_y;
    title_distant_to_zero_x = 0.65f - 0.2f;
    title_distant_to_zero_y = 0.25f - 0.2f;

    //подвинем мельницу в главном окне
    obj.trans_matrix(0.2f, 0.2f, title_millbase1);
    obj.trans_matrix(0.2f, 0.2f, title_millbase2);
    obj.trans_matrix(0.2f, 0.2f, title_blade_up1);
    obj.trans_matrix(0.2f, 0.2f, title_blade_up2);
    obj.trans_matrix(0.2f, 0.2f, title_blade_down1);
    obj.trans_matrix(0.2f, 0.2f, title_blade_down2);
    obj.trans_matrix(0.2f, 0.2f, title_blade_right1);
    obj.trans_matrix(0.2f, 0.2f, title_blade_right2);
    obj.trans_matrix(0.2f, 0.2f, title_blade_left1);
    obj.trans_matrix(0.2f, 0.2f, title_blade_left2);

    //отмасштабируем мельницу в главном окне
    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_millbase1);
    obj.scale_triangle(1.25f, 1.25f, title_millbase1);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_millbase1);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_millbase2);
    obj.scale_triangle(1.25f, 1.25f, title_millbase2);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_millbase2);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_up1);
    obj.scale_triangle(1.25f, 1.25f, title_blade_up1);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_up1);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_up2);
    obj.scale_triangle(1.25f, 1.25f, title_blade_up2);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_up2);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_down1);
    obj.scale_triangle(1.25f, 1.25f, title_blade_down1);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_down1);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_down2);
    obj.scale_triangle(1.25f, 1.25f, title_blade_down2);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_down2);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_right1);
    obj.scale_triangle(1.25f, 1.25f, title_blade_right1);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_right1);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_right2);
    obj.scale_triangle(1.25f, 1.25f, title_blade_right2);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_right2);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_left1);
    obj.scale_triangle(1.25f, 1.25f, title_blade_left1);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_left1);

    obj.trans_matrix(title_distant_to_zero_x, title_distant_to_zero_y,
                     title_blade_left2);
    obj.scale_triangle(1.25f, 1.25f, title_blade_left2);
    obj.trans_matrix(-title_distant_to_zero_x, -title_distant_to_zero_y,
                     title_blade_left2);

    //радиус крыла мельницы, нужен чтобы смещать платформу
    //расчет по координатам лопасти ПОСЛЕ масштабирования
    float mill_radius   = blade_down1.v[1].y - blade_down1.v[0].y;
    float mill_radius_r = blade_down1_r.v[1].y - blade_down1_r.v[0].y;
    float mill_radius_c = blade_down1_c.v[1].y - blade_down1_c.v[0].y;

    //настраиваем вращение мельницы 1 левой
    rotation mill;
    mill.set_speed_of_rotation(10.0);
    mill.set_direction(1);
    timer mill_time;
    float delta_x       = 0.0f;
    float delta_y       = 0.0f;
    int   current_angle = 0;
    float distant_to_zero_x, distant_to_zero_y;
    distant_to_zero_x = 0.65f;
    distant_to_zero_y = 0.25f;

    //переменные для разрушения мельницы №1 (левой)
    bool  crash_of_mill       = false;
    bool  left_blade_crashed  = false;
    bool  right_blade_crashed = false;
    bool  up_blade_crashed    = false;
    bool  down_blade_crashed  = false;
    bool  timer_started       = false;
    timer crashing_mill;

    float time_to_crash_value = 8.0f;

    //настраиваем вращение мельницы 2
    rotation mill_r;
    mill_r.set_speed_of_rotation(15.0);
    mill_r.set_direction(1);
    timer mill_time_r;
    float delta_x_r       = 0.0f;
    float delta_y_r       = 0.0f;
    int   current_angle_r = 0;
    float distant_to_zero_x_r, distant_to_zero_y_r;
    distant_to_zero_x_r = 0.65f;
    distant_to_zero_y_r = 0.25f;

    //переменные для разрушения мельницы №2 (правой)
    bool  crash_of_mill_r       = false;
    bool  left_blade_crashed_r  = false;
    bool  right_blade_crashed_r = false;
    bool  up_blade_crashed_r    = false;
    bool  down_blade_crashed_r  = false;
    bool  timer_started_r       = false;
    timer crashing_mill_r;

    //настраиваем вращение мельницы 3
    rotation mill_c;
    mill_c.set_speed_of_rotation(13.0);
    mill_c.set_direction(-1);
    timer mill_time_c;
    float delta_x_c       = 0.0f;
    float delta_y_c       = 0.0f;
    int   current_angle_c = 0;
    float distant_to_zero_x_c, distant_to_zero_y_c;
    distant_to_zero_x_c = 0.0f;
    distant_to_zero_y_c = 0.25f;

    //переменные для разрушения мельницы №3 (центр)
    bool  crash_of_mill_c       = false;
    bool  left_blade_crashed_c  = false;
    bool  right_blade_crashed_c = false;
    bool  up_blade_crashed_c    = false;
    bool  down_blade_crashed_c  = false;
    bool  timer_started_c       = false;
    timer crashing_mill_c;

    //анимация герой стоит смотрит влево
    bool      look_to_right = true; //герой смотрит вправо
    animation ani;
    ani.set_fps(10);
    ani.set_number_of_frames(10);
    int number = 0;

    //анимация герой бежит
    animation run_ani;
    int       run_ani_number = 0;
    run_ani.set_fps(8);
    run_ani.set_number_of_frames(8);

    //анимация герой прыгает
    animation jump_ani;
    int       jump_ani_number = 0;
    jump_ani.set_fps(10);
    jump_ani.set_number_of_frames(10);

    //анимация герой умирает
    animation ani_dead;
    ani_dead.set_fps(5);
    ani_dead.set_number_of_frames(10);
    int dead_number = 0;

    //анимация ALARM! над мельницей 1
    animation alarm_ani;
    int       alarm_number = 0;
    alarm_ani.set_fps(4);
    alarm_ani.set_number_of_frames(4);

    //анимация ALARM! над мельницей 2
    animation alarm_ani_r;
    alarm_ani_r.set_fps(4);
    alarm_ani_r.set_number_of_frames(4);

    //анимация ALARM! над мельницей 3
    animation alarm_ani_c;
    alarm_ani_c.set_fps(4);
    alarm_ani_c.set_number_of_frames(4);

    //анимация огня под мельницей 1
    animation fire_ani;
    int       fire_number = 0;
    fire_ani.set_fps(8);
    fire_ani.set_number_of_frames(8);

    //анимация огня на всю длину экрана
    animation long_fire_ani;
    int       long_fire_number = 0;
    long_fire_ani.set_fps(8);
    long_fire_ani.set_number_of_frames(5);

    //таймер для анимации персонажа
    timer  t;
    timer  t2;
    double delta_time      = 0;
    double delta_time_move = 0;

    timer  ani_dead_timer;
    double delta_time_dead = 0;

    //таймер для прыжка
    timer  jump_timer;
    double delta_time2 = 0;

    //таймер для времени игры
    timer  game_timer;
    timer  game_timer_full_time;
    double number_for_timer;

    int sec = 0, sec2 = 0;
    int min = 0, min2 = 0;

    float biggest_time   = 0;
    float this_game_time = 0;

    //анимация дождя
    float  rain_speed  = -0.008f;
    float  rain_speed2 = -0.01f;
    timer  rain;
    double delta_time_rain  = 0;
    double delta_time_rain2 = 0;

    bool   cloud_move_to_right = false;
    bool   cloud_move_to_left  = false;
    double delta_time_cloud    = 0;
    float  cloud_speed         = 0.0f;
    bool   cloud_position_1    = false;
    bool   cloud_position_2    = false;
    bool   cloud_position_3    = false;

    float fire_speed_1 = 0.0f;
    float fire_speed_2 = 0.0f;
    float fire_speed_3 = 0.0f;

    bool fire_1_down_pos_limit = false;
    bool fire_1_up_pos_limit   = false;
    bool fire_2_down_pos_limit = false;
    bool fire_2_up_pos_limit   = false;
    bool fire_3_down_pos_limit = false;
    bool fire_3_up_pos_limit   = false;

    bool pause_flag = false;
    int game_over_counter = 0; //счетчик разрушения мельницы 1
    int  game_over_counter2   = 0;
    int  game_over_counter3   = 0;
    bool game_over_flag       = false;
    bool game_over_pause_flag = false;
    bool mill_one_crashed     = false;
    bool mill_two_crashed     = false;
    bool mill_three_crashed   = false;

    //герой движется вместе с платформой 1
    float hero_delta_x        = 0.0f;
    float hero_delta_y        = 0.0f;
    float pl_x_befor_rotation = 0.0f;
    float pl_y_befor_rotation = 0.0f;
    //герой движется вместе с платформой 2
    float hero_delta_x_r        = 0.0f;
    float hero_delta_y_r        = 0.0f;
    float pl_x_befor_rotation_r = 0.0f;
    float pl_y_befor_rotation_r = 0.0f;
    //герой движется вместе с платформой 3
    float hero_delta_x_c        = 0.0f;
    float hero_delta_y_c        = 0.0f;
    float pl_x_befor_rotation_c = 0.0f;
    float pl_y_befor_rotation_c = 0.0f;

    bool  correction       = false;
    float delta_correction = 0.0f;

    // =============== ИГРОВОЙ ЦИКЛ ===================
    bool loop = true;
    while (loop)
    {

        loop = obj.events();

        //====== таймер =====
        number_for_timer = game_timer.elapsed();
        // this_game_time   = game_timer_full_time.elapsed();

        if (number_for_timer >= 1)
        {
            count_for_timer(min, min2, sec, sec2);
            game_timer.reset();
        }
        //====== таймер конец=====

        //====== главное окно! ======
        if (first_start)
        {
            while (first_start)
            {
                first_start = obj.events();

                //фоновый звук ветра
                if (wind_sound.play_or_not == false)
                {
                    obj.play_sound(&wind_sound);
                }

                //фоновый звук мельницы
                if (mill_sound.play_or_not == false)
                {
                    obj.play_sound(&mill_sound);
                }

                if (key_ENTER_flag)
                {
                    first_start = false;
                    obj.stop_sound(&wind_sound);
                    obj.stop_sound(&mill_sound);
                }

                obj.render_textured_triangle(title_window, title_t);
                obj.render_textured_triangle(title_window1, title_t);

                //====== вращение мельницы =======
                while (title_mill_time.elapsed() >=
                       title_mill.one_degree_time())
                {
                    if (title_mill.get_direction() > 0)
                    {
                        title_current_angle++;
                    }
                    else
                    {
                        title_current_angle--;
                    }

                    title_bl_up1 = title_blade_up1;
                    title_bl_up2 = title_blade_up2;

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_up1);
                    obj.rotate_matrix(title_current_angle, title_bl_up1);
                    obj.scale_to_screen(title_bl_up1);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_up1);

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_up2);
                    obj.rotate_matrix(title_current_angle, title_bl_up2);
                    obj.scale_to_screen(title_bl_up2);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_up2);

                    title_bl_left1 = title_blade_left1;
                    title_bl_left2 = title_blade_left2;

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_left1);
                    obj.rotate_matrix(title_current_angle, title_bl_left1);
                    obj.scale_to_screen(title_bl_left1);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_left1);

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_left2);
                    obj.rotate_matrix(title_current_angle, title_bl_left2);
                    obj.scale_to_screen(title_bl_left2);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_left2);

                    title_bl_right1 = title_blade_right1;
                    title_bl_right2 = title_blade_right2;

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_right1);
                    obj.rotate_matrix(title_current_angle, title_bl_right1);
                    obj.scale_to_screen(title_bl_right1);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_right1);

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_right2);
                    obj.rotate_matrix(title_current_angle, title_bl_right2);
                    obj.scale_to_screen(title_bl_right2);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_right2);

                    title_bl_down1 = title_blade_down1;
                    title_bl_down2 = title_blade_down2;

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_down1);
                    obj.rotate_matrix(title_current_angle, title_bl_down1);
                    obj.scale_to_screen(title_bl_down1);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_down1);

                    obj.trans_matrix(title_distant_to_zero_x,
                                     title_distant_to_zero_y, title_bl_down2);
                    obj.rotate_matrix(title_current_angle, title_bl_down2);
                    obj.scale_to_screen(title_bl_down2);
                    obj.trans_matrix(-title_distant_to_zero_x,
                                     -title_distant_to_zero_y, title_bl_down2);

                    title_mill_time.reset();
                } //конец вращения мельницы

                //===== рендер Мельницы =====
                obj.render_textured_triangle(title_millbase1, millbase_0);
                obj.render_textured_triangle(title_millbase2, millbase_0);

                obj.render_textured_triangle(title_bl_down1, down);
                obj.render_textured_triangle(title_bl_down2, down);

                obj.render_textured_triangle(title_bl_up1, up);
                obj.render_textured_triangle(title_bl_up2, up);

                obj.render_textured_triangle(title_bl_right1, left);
                obj.render_textured_triangle(title_bl_right2, left);
                obj.render_textured_triangle(title_bl_left1, right);
                obj.render_textured_triangle(title_bl_left2, right);

                obj.swap_buffers2();
            }
        }
        //====== главное окно конец ======

        //рендерим задний фон в начале, чтобы он был задним :)
        obj.render_textured_triangle(background, background_t);
        obj.render_textured_triangle(background1, background_t);

        //====== пауза! ======
        if (key_LCTRL_flag)
        {
            obj.stop_sound(&bell_sound);
            obj.stop_sound(&bell_sound2);
            obj.stop_sound(&bell_sound3);
            obj.stop_sound(&fire_sound);

            pause_flag = true;
            obj.pause_ms(250);
            obj.play_sound(&marsh_sound);
        }
        while (pause_flag)
        {
            obj.render_textured_triangle(pause_window, pause_t);
            obj.render_textured_triangle(pause_window1, pause_t);

            pause_flag = obj.events();

            delta_time_dead = ani_dead_timer.elapsed();

            //анимация героя в паузе
            ani.restart();
            dead_number = ani.current_frame_number(delta_time_dead);
            obj.render_textured_triangle(hero6, idle_sprite.at(dead_number));
            obj.render_textured_triangle(hero7, idle_sprite.at(dead_number));

            std::cout << "P A U S E ! \n";
            if (key_LCTRL_flag)
            {
                pause_flag = false;
                // obj.stop_sound(&e2);
                obj.stop_sound(&marsh_sound);
                obj.pause_ms(250);
                delta_time_dead = 0;
                dead_number     = 0;
            }
            obj.swap_buffers2();
        }
        //====== конец паузы ! ======

        //====== game over! ======
        if (game_over_flag)
        {
            save_file(min2, min, sec2, sec);
            this_game_time = game_timer_full_time.elapsed();
            std::cout << "this_game_time " << this_game_time << "\n";
            write_time(this_game_time);

            game_over_pause_flag = true;
            obj.stop_sound(&bell_sound);
            obj.stop_sound(&bell_sound2);
            obj.stop_sound(&bell_sound3);
            obj.stop_sound(&fire_sound);
            obj.stop_sound(&crash_sound);
        }
        while (game_over_pause_flag)
        {
            //фоновый звук game over
            if (over_sound.play_or_not == false)
            {
                obj.play_sound(&over_sound);
            }
            //фоновый звук ветра
            if (wind_sound.play_or_not == false)
            {
                obj.play_sound(&wind_sound);
            }

            obj.render_textured_triangle(over_window, over_t);
            obj.render_textured_triangle(over_window1, over_t);

            delta_time_dead      = ani_dead_timer.elapsed();
            game_over_pause_flag = obj.events();

            //анимация герой умирает
            if (dead_number < 9)
            {
                obj.swap_buffers2();

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);

                obj.render_textured_triangle(hero4, dead_sprite.at(0));
                obj.render_textured_triangle(hero5, dead_sprite.at(0));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(1));
                obj.render_textured_triangle(hero5, dead_sprite.at(1));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(2));
                obj.render_textured_triangle(hero5, dead_sprite.at(2));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(3));
                obj.render_textured_triangle(hero5, dead_sprite.at(3));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(4));
                obj.render_textured_triangle(hero5, dead_sprite.at(4));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(5));
                obj.render_textured_triangle(hero5, dead_sprite.at(5));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(6));
                obj.render_textured_triangle(hero5, dead_sprite.at(6));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(7));
                obj.render_textured_triangle(hero5, dead_sprite.at(7));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(8));
                obj.render_textured_triangle(hero5, dead_sprite.at(8));
                obj.swap_buffers2();
                obj.pause_ms(250);
                dead_number++;

                obj.render_textured_triangle(over_window, over_t);
                obj.render_textured_triangle(over_window1, over_t);
                obj.render_textured_triangle(hero4, dead_sprite.at(9));
                obj.render_textured_triangle(hero5, dead_sprite.at(9));
                obj.pause_ms(250);
                dead_number++;
            }
            else
            {
                obj.render_textured_triangle(hero4, dead_sprite.at(9));
                obj.render_textured_triangle(hero5, dead_sprite.at(9));
            }

            if (key_ENTER_flag)
            {
                obj.stop_sound(&over_sound);
                obj.play_sound(&horror_sound);

                obj.render_textured_triangle(hero4, rising_sprite.at(0));
                obj.render_textured_triangle(hero5, rising_sprite.at(0));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(1));
                obj.render_textured_triangle(hero5, rising_sprite.at(1));

                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(2));
                obj.render_textured_triangle(hero5, rising_sprite.at(2));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(3));
                obj.render_textured_triangle(hero5, rising_sprite.at(3));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(4));
                obj.render_textured_triangle(hero5, rising_sprite.at(4));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(5));
                obj.render_textured_triangle(hero5, rising_sprite.at(5));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(6));
                obj.render_textured_triangle(hero5, rising_sprite.at(6));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(7));
                obj.render_textured_triangle(hero5, rising_sprite.at(7));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(8));
                obj.render_textured_triangle(hero5, rising_sprite.at(8));
                obj.swap_buffers2();
                obj.pause_ms(250);

                obj.render_textured_triangle(hero4, rising_sprite.at(9));
                obj.render_textured_triangle(hero5, rising_sprite.at(9));
                obj.swap_buffers2();
                obj.pause_ms(250);

                //возвращаем мир в исходный вид простым хакерским приемом :)
                obj.pause_ms(500);
                obj.stop_sound(&wind_sound);
                goto restart;
            }
            obj.swap_buffers2();
        }
        //====== конец game over!  ======

        delta_time  = t.elapsed();
        delta_time2 = jump_timer.elapsed();

        delta_time_move = t2.elapsed();

        delta_time_rain  = rain.elapsed();
        delta_time_rain2 = rain.elapsed();
        delta_time_cloud = rain.elapsed();

        //фоновый звук огня
        if (fire_sound.play_or_not == false)
        {
            obj.play_sound(&fire_sound);
        }

        // ====== прыжок ======
        //заплатка на баг с бесконечным прышком
        if (jump_flag == 0)
        {
            increment2 = 0;
        }

        if (key_SPACE_flag && jump_flag != 1 && platform_flag == 1)
        {
            jump_flag  = 1;
            increment2 = 0;
            obj.play_sound(&jump);
            delta_time2 = 0;
            jump_timer.reset();
        }

        if (jump_flag == 1)
        {
            delta_time2 = jump_timer.elapsed();
            if (delta_time2 < 0.8)
            {
                increment2 = jump_speed_value;
            }
            else
            {
                increment2 = 0.0;
            }
        }

        //выставляем признаки разрушения мельницы №1
        if (crash_of_mill)
        {
            if (!timer_started)
            {
                timer_started = true;
            }
            if (!left_blade_crashed &&
                crashing_mill.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                left_blade_crashed = true;
                crashing_mill.reset();
                game_over_counter++;
            }

            else if (!right_blade_crashed &&
                     crashing_mill.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                right_blade_crashed = true;
                crashing_mill.reset();
                game_over_counter++;
            }
            else if (!up_blade_crashed &&
                     crashing_mill.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                up_blade_crashed = true;
                crashing_mill.reset();
                game_over_counter++;
            }
            else if (!down_blade_crashed &&
                     crashing_mill.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                down_blade_crashed = true;
                crashing_mill.reset();
                game_over_counter++;
            }
        }

        //выставляем признаки разрушения мельницы №2 (правой)
        if (crash_of_mill_r)
        {
            if (!timer_started_r)
            {
                crashing_mill_r.reset();
                timer_started_r = true;
            }
            if (!left_blade_crashed_r &&
                crashing_mill_r.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                left_blade_crashed_r = true;
                crashing_mill_r.reset();
                game_over_counter2++;
            }

            else if (!right_blade_crashed_r &&
                     crashing_mill_r.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                right_blade_crashed_r = true;
                crashing_mill_r.reset();
                game_over_counter2++;
            }
            else if (!up_blade_crashed_r &&
                     crashing_mill_r.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                up_blade_crashed_r = true;
                crashing_mill_r.reset();
                game_over_counter2++;
            }
            else if (!down_blade_crashed_r &&
                     crashing_mill_r.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                down_blade_crashed_r = true;
                crashing_mill_r.reset();
                game_over_counter2++;
            }
        }

        //выставляем признаки разрушения мельницы №3 (центр)
        if (crash_of_mill_c)
        {
            if (!timer_started_c)
            {
                crashing_mill_c.reset();
                timer_started_c = true;
            }
            if (!left_blade_crashed_c &&
                crashing_mill_c.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                left_blade_crashed_c = true;
                crashing_mill_c.reset();
                game_over_counter3++;
            }

            else if (!right_blade_crashed_c &&
                     crashing_mill_c.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                right_blade_crashed_c = true;
                crashing_mill_c.reset();
                game_over_counter3++;
            }
            else if (!up_blade_crashed_c &&
                     crashing_mill_c.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                up_blade_crashed_c = true;
                crashing_mill_c.reset();
                game_over_counter3++;
            }
            else if (!down_blade_crashed_c &&
                     crashing_mill_c.elapsed() >= time_to_crash_value)
            {
                obj.play_sound(&crash_sound);
                down_blade_crashed_c = true;
                crashing_mill_c.reset();
                game_over_counter3++;
            }
        }

        //====== вращение мельницы № 1 (левая) =======
        while (mill_time.elapsed() >= mill.one_degree_time())
        {
            if (mill.get_direction() > 0)
            {
                current_angle++;
            }
            else
            {
                current_angle--;
            }

            //работаем с копиями треугольников мельницы!
            //чтобы избежать многократного масштабирования в ноль при
            //бесконечном вращении мельницы

            //если нет признака разрушения, вращаем лопасть
            //иначе отрываем лопасть
            if (!up_blade_crashed)
            {
                bl_up1 = blade_up1;
                bl_up2 = blade_up2;

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y, bl_up1);
                obj.rotate_matrix(current_angle, bl_up1);
                obj.scale_to_screen(bl_up1);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_up1);

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y, bl_up2);
                obj.rotate_matrix(current_angle, bl_up2);
                obj.scale_to_screen(bl_up2);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_up2);
            }
            else
            {
                if (bl_up1.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_up1);
                    obj.trans_matrix(0.0f, -0.005f, bl_up2);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_up1);
                    obj.trans_matrix(0.0f, 0.0f, bl_up2);
                }
            }

            if (!left_blade_crashed)
            {
                bl_left1 = blade_left1;
                bl_left2 = blade_left2;

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 bl_left1);
                obj.rotate_matrix(current_angle, bl_left1);
                obj.scale_to_screen(bl_left1);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_left1);

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 bl_left2);
                obj.rotate_matrix(current_angle, bl_left2);
                obj.scale_to_screen(bl_left2);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_left2);
            }
            else
            {
                if (bl_left1.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_left1);
                    obj.trans_matrix(0.0f, -0.005f, bl_left2);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_left1);
                    obj.trans_matrix(0.0f, 0.0f, bl_left2);
                }
            }

            if (!right_blade_crashed)
            {
                bl_right1 = blade_right1;
                bl_right2 = blade_right2;

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 bl_right1);
                obj.rotate_matrix(current_angle, bl_right1);
                obj.scale_to_screen(bl_right1);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_right1);

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 bl_right2);
                obj.rotate_matrix(current_angle, bl_right2);
                obj.scale_to_screen(bl_right2);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_right2);
            }
            else
            {
                if (bl_right1.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_right1);
                    obj.trans_matrix(0.0f, -0.005f, bl_right2);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_right1);
                    obj.trans_matrix(0.0f, 0.0f, bl_right2);
                }
            }

            delta_x = abs(mill_radius * sin(abs(current_angle) * pi / 180));
            delta_y = abs(mill_radius * cos(abs(current_angle) * pi / 180));

            //присвоим смещениям нужный знак в зависимости от текущей
            //четверти вращение по часовой стрелке
            if (mill.get_direction() < 0)
            {
                if (current_angle < 0 && current_angle >= -90)
                {
                    delta_x = 1 * delta_x;
                    delta_y = 1 * delta_y;
                }
                if (current_angle < -90 && current_angle >= -180)
                {
                    delta_x = 1 * delta_x;
                    delta_y = -1 * delta_y;
                }
                if (current_angle < -180 && current_angle >= -270)
                {
                    delta_x = -1 * delta_x;
                    delta_y = -1 * delta_y;
                }
                if (current_angle < -270 && current_angle >= -360)
                {
                    delta_x = -1 * delta_x;
                    delta_y = 1 * delta_y;
                }
                if (current_angle == -360)
                {
                    current_angle = 0;
                }
            }

            //вращение против часовой стрелки
            if (mill.get_direction() > 0)
            {
                if (current_angle > 0 && current_angle <= 90)
                {
                    delta_x = -1 * delta_x;
                    delta_y = 1 * delta_y;
                }
                if (current_angle > 90 && current_angle <= 180)
                {

                    delta_x = -1 * delta_x;
                    delta_y = -1 * delta_y;
                }
                if (current_angle > 180 && current_angle <= 270)
                {
                    delta_x = 1 * delta_x;
                    delta_y = -1 * delta_y;
                }
                if (current_angle > 270 && current_angle <= 360)
                {
                    delta_x = 1 * delta_x;
                    delta_y = 1 * delta_y;
                }
                if (current_angle == 360)
                {
                    current_angle = 0;
                }
            }

            if (!down_blade_crashed)
            {
                bl_down1 = blade_down1;
                bl_down2 = blade_down2;
                pl_down1 = platform_down1;
                pl_down2 = platform_down2;

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 bl_down1);
                obj.rotate_matrix(current_angle, bl_down1);
                obj.scale_to_screen(bl_down1);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_down1);

                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 bl_down2);
                obj.rotate_matrix(current_angle, bl_down2);
                obj.scale_to_screen(bl_down2);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 bl_down2);

                //вращение нижней платформы вместе с лопастью
                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 pl_down1);
                obj.trans_matrix(distant_to_zero_x, distant_to_zero_y,
                                 pl_down2);

                obj.rotate_matrix(current_angle, pl_down1);
                obj.rotate_matrix(current_angle, pl_down2);

                obj.trans_matrix(delta_x, delta_y, pl_down1);
                obj.trans_matrix(delta_x, delta_y, pl_down2);
                obj.rotate_matrix(-current_angle, pl_down1);
                obj.rotate_matrix(-current_angle, pl_down2);

                obj.scale_to_screen(pl_down1);
                obj.scale_to_screen(pl_down2);

                //после поворота и масштабирования платформу возвращаем на
                //место на расстояние по X, умноженное на коэффициент
                //масштабирования
                obj.trans_matrix(-delta_x * obj.get_k_screen(), -delta_y,
                                 pl_down1);
                obj.trans_matrix(-delta_x * obj.get_k_screen(), -delta_y,
                                 pl_down2);

                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 pl_down1);
                obj.trans_matrix(-distant_to_zero_x, -distant_to_zero_y,
                                 pl_down2);
            }
            else
            {
                if (bl_down1.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_down1);
                    obj.trans_matrix(0.0f, -0.005f, bl_down2);
                    obj.trans_matrix(0.0f, -0.005f, pl_down1);
                    obj.trans_matrix(0.0f, -0.005f, pl_down2);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_down1);
                    obj.trans_matrix(0.0f, 0.0f, bl_down2);
                    obj.trans_matrix(0.0f, 0.0f, pl_down1);
                    obj.trans_matrix(0.0f, 0.0f, pl_down2);
                }
            }

            //рассчитываем приращения по X и Y угла платформы за каждый
            //поворот и на эти приращения двигаем героя, если он стоит на
            //платформе
            hero_delta_x = pl_down1.v[0].x - pl_x_befor_rotation;
            hero_delta_y = pl_down1.v[0].y - pl_y_befor_rotation;

            pl_x_befor_rotation = pl_down1.v[0].x;
            pl_y_befor_rotation = pl_down1.v[0].y;

            //прицепим героя к платформе на мельнице
            if (hero_on_the_mill && !down_blade_crashed)
            {
                obj.trans_matrix(hero_delta_x, hero_delta_y, hero);
                obj.trans_matrix(hero_delta_x, hero_delta_y, hero1);
                obj.trans_matrix(hero_delta_x, hero_delta_y, hero2);
                obj.trans_matrix(hero_delta_x, hero_delta_y, hero3);
            }

            mill_time.reset();
        } //конец вращения мельницы 1

        //====== вращение мельницы № 2 (правая) =======
        while (mill_time_r.elapsed() >= mill_r.one_degree_time())
        {
            if (mill_r.get_direction() > 0)
            {
                current_angle_r++;
            }
            else
            {
                current_angle_r--;
            }

            if (!up_blade_crashed_r)
            {
                bl_up1_r = blade_up1_r;
                bl_up2_r = blade_up2_r;

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_up1_r);
                obj.rotate_matrix(current_angle_r, bl_up1_r);
                obj.scale_to_screen(bl_up1_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_up1_r);

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_up2_r);
                obj.rotate_matrix(current_angle_r, bl_up2_r);
                obj.scale_to_screen(bl_up2_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_up2_r);
            }
            else
            {
                if (bl_up1_r.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_up1_r);
                    obj.trans_matrix(0.0f, -0.005f, bl_up2_r);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_up1_r);
                    obj.trans_matrix(0.0f, 0.0f, bl_up2_r);
                }
            }

            if (!left_blade_crashed_r)
            {
                bl_left1_r = blade_left1_r;
                bl_left2_r = blade_left2_r;

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_left1_r);
                obj.rotate_matrix(current_angle_r, bl_left1_r);
                obj.scale_to_screen(bl_left1_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_left1_r);

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_left2_r);
                obj.rotate_matrix(current_angle_r, bl_left2_r);
                obj.scale_to_screen(bl_left2_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_left2_r);
            }
            else
            {
                if (bl_left1_r.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_left1_r);
                    obj.trans_matrix(0.0f, -0.005f, bl_left2_r);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_left1_r);
                    obj.trans_matrix(0.0f, 0.0f, bl_left2_r);
                }
            }

            if (!right_blade_crashed_r)
            {
                bl_right1_r = blade_right1_r;
                bl_right2_r = blade_right2_r;

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_right1_r);
                obj.rotate_matrix(current_angle_r, bl_right1_r);
                obj.scale_to_screen(bl_right1_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_right1_r);

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_right2_r);
                obj.rotate_matrix(current_angle_r, bl_right2_r);
                obj.scale_to_screen(bl_right2_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_right2_r);
            }
            else
            {
                if (bl_right1_r.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_right1_r);
                    obj.trans_matrix(0.0f, -0.005f, bl_right2_r);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_right1_r);
                    obj.trans_matrix(0.0f, 0.0f, bl_right2_r);
                }
            }

            delta_x_r =
                abs(mill_radius_r * sin(abs(current_angle_r) * pi / 180));
            delta_y_r =
                abs(mill_radius_r * cos(abs(current_angle_r) * pi / 180));

            //вращение по часовой стрелке
            if (mill_r.get_direction() < 0)
            {
                if (current_angle_r < 0 && current_angle_r >= -90)
                {
                    delta_x_r = 1 * delta_x_r;
                    delta_y_r = 1 * delta_y_r;
                }
                if (current_angle_r < -90 && current_angle_r >= -180)
                {
                    delta_x_r = 1 * delta_x_r;
                    delta_y_r = -1 * delta_y_r;
                }
                if (current_angle_r < -180 && current_angle_r >= -270)
                {
                    delta_x_r = -1 * delta_x_r;
                    delta_y_r = -1 * delta_y_r;
                }
                if (current_angle_r < -270 && current_angle_r >= -360)
                {
                    delta_x_r = -1 * delta_x_r;
                    delta_y_r = 1 * delta_y_r;
                }
                if (current_angle_r == -360)
                {
                    current_angle_r = 0;
                }
            }

            //вращение против часовой стрелки
            if (mill_r.get_direction() > 0)
            {
                if (current_angle_r > 0 && current_angle_r <= 90)
                {
                    delta_x_r = -1 * delta_x_r;
                    delta_y_r = 1 * delta_y_r;
                }
                if (current_angle_r > 90 && current_angle_r <= 180)
                {
                    delta_x_r = -1 * delta_x_r;
                    delta_y_r = -1 * delta_y_r;
                }
                if (current_angle_r > 180 && current_angle_r <= 270)
                {
                    delta_x_r = 1 * delta_x_r;
                    delta_y_r = -1 * delta_y_r;
                }
                if (current_angle_r > 270 && current_angle_r <= 360)
                {
                    delta_x_r = 1 * delta_x_r;
                    delta_y_r = 1 * delta_y_r;
                }
                if (current_angle_r == 360)
                {
                    current_angle_r = 0;
                }
            }

            if (!down_blade_crashed_r)
            {
                bl_down1_r = blade_down1_r;
                bl_down2_r = blade_down2_r;

                pl_down1_r = platform_down1_r;
                pl_down2_r = platform_down2_r;

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_down1_r);
                obj.rotate_matrix(current_angle_r, bl_down1_r);
                obj.scale_to_screen(bl_down1_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_down1_r);

                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 bl_down2_r);
                obj.rotate_matrix(current_angle_r, bl_down2_r);
                obj.scale_to_screen(bl_down2_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 bl_down2_r);
                //вращение нижней платформы вместе с лопастью
                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 pl_down1_r);
                obj.trans_matrix(-distant_to_zero_x_r, distant_to_zero_y_r,
                                 pl_down2_r);

                obj.rotate_matrix(current_angle_r, pl_down1_r);
                obj.rotate_matrix(current_angle_r, pl_down2_r);

                obj.trans_matrix(delta_x_r, delta_y_r, pl_down1_r);
                obj.trans_matrix(delta_x_r, delta_y_r, pl_down2_r);
                obj.rotate_matrix(-current_angle_r, pl_down1_r);
                obj.rotate_matrix(-current_angle_r, pl_down2_r);

                obj.scale_to_screen(pl_down1_r);
                obj.scale_to_screen(pl_down2_r);

                //после поворота и масштабирования платформу возвращаем на
                //место на расстояние по X, умноженное на коэффициент
                //масштабирования
                obj.trans_matrix(-delta_x_r * obj.get_k_screen(), -delta_y_r,
                                 pl_down1_r);
                obj.trans_matrix(-delta_x_r * obj.get_k_screen(), -delta_y_r,
                                 pl_down2_r);

                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 pl_down1_r);
                obj.trans_matrix(distant_to_zero_x_r, -distant_to_zero_y_r,
                                 pl_down2_r);
            }
            else
            {
                if (bl_down1_r.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_down1_r);
                    obj.trans_matrix(0.0f, -0.005f, bl_down2_r);
                    obj.trans_matrix(0.0f, -0.005f, pl_down1_r);
                    obj.trans_matrix(0.0f, -0.005f, pl_down2_r);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_down1_r);
                    obj.trans_matrix(0.0f, 0.0f, bl_down2_r);
                    obj.trans_matrix(0.0f, 0.0f, pl_down1_r);
                    obj.trans_matrix(0.0f, 0.0f, pl_down2_r);
                }
            }

            //рассчитываем приращения по X и Y угла платформы за каждый
            //поворот и на эти приращения двигаем героя, если он стоит на
            //платформе
            hero_delta_x_r = pl_down1_r.v[0].x - pl_x_befor_rotation_r;
            hero_delta_y_r = pl_down1_r.v[0].y - pl_y_befor_rotation_r;

            pl_x_befor_rotation_r = pl_down1_r.v[0].x;
            pl_y_befor_rotation_r = pl_down1_r.v[0].y;

            //прицепим героя к платформе на мельнице
            if (hero_on_the_mill_r && !down_blade_crashed_r)
            {
                obj.trans_matrix(hero_delta_x_r, hero_delta_y_r, hero);
                obj.trans_matrix(hero_delta_x_r, hero_delta_y_r, hero1);
                obj.trans_matrix(hero_delta_x_r, hero_delta_y_r, hero2);
                obj.trans_matrix(hero_delta_x_r, hero_delta_y_r, hero3);
            }

            mill_time_r.reset();
        } //конец вращения мельницы 2

        //====== вращение мельницы № 3 (центр) =======
        while (mill_time_c.elapsed() >= mill_c.one_degree_time())
        {
            if (mill_c.get_direction() > 0)
            {
                current_angle_c++;
            }
            else
            {
                current_angle_c--;
            }

            if (!up_blade_crashed_c)
            {
                bl_up1_c = blade_up1_c;
                bl_up2_c = blade_up2_c;

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_up1_c);
                obj.rotate_matrix(current_angle_c, bl_up1_c);
                obj.scale_to_screen(bl_up1_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_up1_c);

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_up2_c);
                obj.rotate_matrix(current_angle_c, bl_up2_c);
                obj.scale_to_screen(bl_up2_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_up2_c);
            }
            else
            {
                if (bl_up1_c.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_up1_c);
                    obj.trans_matrix(0.0f, -0.005f, bl_up2_c);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_up1_c);
                    obj.trans_matrix(0.0f, 0.0f, bl_up2_c);
                }
            }

            if (!left_blade_crashed_c)
            {
                bl_left1_c = blade_left1_c;
                bl_left2_c = blade_left2_c;

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_left1_c);
                obj.rotate_matrix(current_angle_c, bl_left1_c);
                obj.scale_to_screen(bl_left1_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_left1_c);

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_left2_c);
                obj.rotate_matrix(current_angle_c, bl_left2_c);
                obj.scale_to_screen(bl_left2_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_left2_c);
            }
            else
            {
                if (bl_left1_c.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_left1_c);
                    obj.trans_matrix(0.0f, -0.005f, bl_left2_c);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_left1_c);
                    obj.trans_matrix(0.0f, 0.0f, bl_left2_c);
                }
            }

            if (!right_blade_crashed_c)
            {
                bl_right1_c = blade_right1_c;
                bl_right2_c = blade_right2_c;

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_right1_c);
                obj.rotate_matrix(current_angle_c, bl_right1_c);
                obj.scale_to_screen(bl_right1_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_right1_c);

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_right2_c);
                obj.rotate_matrix(current_angle_c, bl_right2_c);
                obj.scale_to_screen(bl_right2_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_right2_c);
            }
            else
            {
                if (bl_right1_c.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_right1_c);
                    obj.trans_matrix(0.0f, -0.005f, bl_right2_c);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_right1_c);
                    obj.trans_matrix(0.0f, 0.0f, bl_right2_c);
                }
            }

            delta_x_c =
                abs(mill_radius_c * sin(abs(current_angle_c) * pi / 180));
            delta_y_c =
                abs(mill_radius_c * cos(abs(current_angle_c) * pi / 180));

            //вращение по часовой стрелке
            if (mill_c.get_direction() < 0)
            {
                if (current_angle_c < 0 && current_angle_c >= -90)
                {
                    delta_x_c = 1 * delta_x_c;
                    delta_y_c = 1 * delta_y_c;
                }
                if (current_angle_c < -90 && current_angle_c >= -180)
                {
                    delta_x_c = 1 * delta_x_c;
                    delta_y_c = -1 * delta_y_c;
                }
                if (current_angle_c < -180 && current_angle_c >= -270)
                {
                    delta_x_c = -1 * delta_x_c;
                    delta_y_c = -1 * delta_y_c;
                }
                if (current_angle_c < -270 && current_angle_c >= -360)
                {
                    delta_x_c = -1 * delta_x_c;
                    delta_y_c = 1 * delta_y_c;
                }
                if (current_angle_c == -360)
                {
                    current_angle_c = 0;
                }
            }

            //вращение против часовой стрелки
            if (mill_c.get_direction() > 0)
            {
                if (current_angle_c > 0 && current_angle_c <= 90)
                {
                    delta_x_c = -1 * delta_x_c;
                    delta_y_c = 1 * delta_y_c;
                }
                if (current_angle_c > 90 && current_angle_c <= 180)
                {
                    delta_x_c = -1 * delta_x_c;
                    delta_y_c = -1 * delta_y_c;
                }
                if (current_angle_c > 180 && current_angle_c <= 270)
                {
                    delta_x_c = 1 * delta_x_c;
                    delta_y_c = -1 * delta_y_c;
                }
                if (current_angle_c > 270 && current_angle_c <= 360)
                {
                    delta_x_c = 1 * delta_x_c;
                    delta_y_c = 1 * delta_y_c;
                }
                if (current_angle_c == 360)
                {
                    current_angle_c = 0;
                }
            }

            if (!down_blade_crashed_c)
            {
                bl_down1_c = blade_down1_c;
                bl_down2_c = blade_down2_c;

                pl_down1_c = platform_down1_c;
                pl_down2_c = platform_down2_c;

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_down1_c);
                obj.rotate_matrix(current_angle_c, bl_down1_c);
                obj.scale_to_screen(bl_down1_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_down1_c);

                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 bl_down2_c);
                obj.rotate_matrix(current_angle_c, bl_down2_c);
                obj.scale_to_screen(bl_down2_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 bl_down2_c);
                //вращение нижней платформы вместе с лопастью
                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 pl_down1_c);
                obj.trans_matrix(distant_to_zero_x_c, distant_to_zero_y_c,
                                 pl_down2_c);

                obj.rotate_matrix(current_angle_c, pl_down1_c);
                obj.rotate_matrix(current_angle_c, pl_down2_c);

                obj.trans_matrix(delta_x_c, delta_y_c, pl_down1_c);
                obj.trans_matrix(delta_x_c, delta_y_c, pl_down2_c);
                obj.rotate_matrix(-current_angle_c, pl_down1_c);
                obj.rotate_matrix(-current_angle_c, pl_down2_c);

                obj.scale_to_screen(pl_down1_c);
                obj.scale_to_screen(pl_down2_c);

                //после поворота и масштабирования платформу возвращаем на
                //место на расстояние по X, умноженное на коэффициент
                //масштабирования
                obj.trans_matrix(-delta_x_c * obj.get_k_screen(), -delta_y_c,
                                 pl_down1_c);
                obj.trans_matrix(-delta_x_c * obj.get_k_screen(), -delta_y_c,
                                 pl_down2_c);

                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 pl_down1_c);
                obj.trans_matrix(distant_to_zero_x_c, -distant_to_zero_y_c,
                                 pl_down2_c);
            }
            else
            {
                if (bl_down1_c.v[0].y > -1.35f)
                {
                    obj.trans_matrix(0.0f, -0.005f, bl_down1_c);
                    obj.trans_matrix(0.0f, -0.005f, bl_down2_c);
                    obj.trans_matrix(0.0f, -0.005f, pl_down1_c);
                    obj.trans_matrix(0.0f, -0.005f, pl_down2_c);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, bl_down1_c);
                    obj.trans_matrix(0.0f, 0.0f, bl_down2_c);
                    obj.trans_matrix(0.0f, 0.0f, pl_down1_c);
                    obj.trans_matrix(0.0f, 0.0f, pl_down2_c);
                }
            }

            //рассчитываем приращения по X и Y угла платформы за каждый
            //поворот и на эти приращения двигаем героя, если он стоит на
            //платформе
            hero_delta_x_c = pl_down1_c.v[0].x - pl_x_befor_rotation_c;
            hero_delta_y_c = pl_down1_c.v[0].y - pl_y_befor_rotation_c;

            pl_x_befor_rotation_c = pl_down1_c.v[0].x;
            pl_y_befor_rotation_c = pl_down1_c.v[0].y;

            //прицепим героя к платформе на мельнице
            if (hero_on_the_mill_c && !down_blade_crashed_c)
            {
                obj.trans_matrix(hero_delta_x_c, hero_delta_y_c, hero);
                obj.trans_matrix(hero_delta_x_c, hero_delta_y_c, hero1);
                obj.trans_matrix(hero_delta_x_c, hero_delta_y_c, hero2);
                obj.trans_matrix(hero_delta_x_c, hero_delta_y_c, hero3);
            }

            mill_time_c.reset();
        } //конец вращения мельницы 3

        //======  получаем скорости перемещения по нажатию клавиш ======
        speedtr = obj.get_speedToRigth() * obj.get_k_screen();
        speedtl = obj.get_speedToLeft() * obj.get_k_screen();
        // speedup = obj.get_speedToUp();
        // speeddown = obj.get_speedToDown();

        //отслеживаем границы экрана при перемещении героя
        if (hero.v[0].x <= -1.0f)
        {
            speedtl = 0;
        }
        if (hero.v[2].x >= 1.0f)
        {
            speedtr = 0;
        }
        if (hero.v[1].y >= 1.0f)
        {
            speedup = 0;
        }
        if (hero.v[1].y <= -1.0f)
        {
            // speeddown      = 0.0f;
            game_over_flag = true;
        }

        //====== герой стоит на одной из платформ =======
        if (hero.v[0].y < pl_down2.v[0].y - 0.015f &&
            hero.v[0].y > pl_down2.v[0].y - 0.045f &&
            hero.v[0].x < pl_down2.v[0].x && hero.v[2].x > pl_down2.v[1].x)
        {
            //скомпенсируем неточность приземления на платформу
            if (!correction)
            {
                delta_correction = abs(abs(pl_down2.v[0].y) - abs(hero.v[0].y));
                obj.trans_matrix(0, delta_correction - 0.015, hero);
                obj.trans_matrix(0, delta_correction - 0.015, hero1);
                obj.trans_matrix(0, delta_correction - 0.015, hero2);
                obj.trans_matrix(0, delta_correction - 0.015, hero3);
                correction = true;
            }
            speeddown        = 0.0f;
            jump_flag        = 0;
            platform_flag    = 1;
            hero_on_the_mill = 1;
        }
        else if (hero.v[0].y < pl_down2_r.v[0].y - 0.015f &&
                 hero.v[0].y > pl_down2_r.v[0].y - 0.045f &&
                 hero.v[0].x < pl_down2_r.v[0].x &&
                 hero.v[2].x > pl_down2_r.v[1].x)
        {
            if (!correction)
            {
                delta_correction =
                    abs(abs(pl_down2_r.v[0].y) - abs(hero.v[0].y));
                obj.trans_matrix(0, delta_correction - 0.015, hero);
                obj.trans_matrix(0, delta_correction - 0.015, hero1);
                obj.trans_matrix(0, delta_correction - 0.015, hero2);
                obj.trans_matrix(0, delta_correction - 0.015, hero3);
                correction = true;
            }
            speeddown          = 0.0f;
            jump_flag          = 0;
            platform_flag      = 1;
            hero_on_the_mill_r = 1;
        }
        else if (hero.v[0].y < pl_down2_c.v[0].y - 0.015f &&
                 hero.v[0].y > pl_down2_c.v[0].y - 0.045f &&
                 hero.v[0].x < pl_down2_c.v[0].x &&
                 hero.v[2].x > pl_down2_c.v[1].x)
        {
            if (!correction)
            {
                delta_correction =
                    abs(abs(pl_down2_c.v[0].y) - abs(hero.v[0].y));
                obj.trans_matrix(0, delta_correction - 0.015, hero);
                obj.trans_matrix(0, delta_correction - 0.015, hero1);
                obj.trans_matrix(0, delta_correction - 0.015, hero2);
                obj.trans_matrix(0, delta_correction - 0.015, hero3);
                correction = true;
            }
            speeddown          = 0.0f;
            jump_flag          = 0;
            platform_flag      = 1;
            hero_on_the_mill_c = 1;
        }
        if (!(hero.v[0].x < pl_down2.v[0].x && hero.v[2].x > pl_down2.v[1].x))
        {
            hero_on_the_mill = 0;
        }
        if (!(hero.v[0].x < pl_down2_r.v[0].x &&
              hero.v[2].x > pl_down2_r.v[1].x))
        {
            hero_on_the_mill_r = 0;
        }
        if (!(hero.v[0].x < pl_down2_c.v[0].x &&
              hero.v[2].x > pl_down2_c.v[1].x))
        {
            hero_on_the_mill_c = 0;
        }
        if (!hero_on_the_mill && !hero_on_the_mill_r && !hero_on_the_mill_c)
        {
            speeddown          = falling_speed_value;
            correction         = false;
            delta_correction   = 0.0f;
            platform_flag      = 0;
            hero_on_the_mill   = 0;
            hero_on_the_mill_r = 0;
            hero_on_the_mill_c = 0;
        }
        if (jump_flag)
        {
            correction         = false;
            platform_flag      = 0;
            delta_correction   = 0.0f;
            hero_on_the_mill   = 0;
            hero_on_the_mill_r = 0;
            hero_on_the_mill_c = 0;
        }

        //========== скорость перемещения главного героя =========
        if (delta_time_move >= 0.03)
        {
            delta_time_move = 0;
            t2.reset();

            obj.trans_matrix(speedtr, 0.0f, hero);
            obj.trans_matrix(speedtl, 0.0f, hero);
            obj.trans_matrix(0.0f, speedup, hero);
            obj.trans_matrix(0.0f, speeddown, hero);

            obj.trans_matrix(0.0f, increment2, hero); //прыжок

            obj.trans_matrix(speedtr, 0.0f, hero1);
            obj.trans_matrix(speedtl, 0.0f, hero1);
            obj.trans_matrix(0.0f, speedup, hero1);
            obj.trans_matrix(0.0f, speeddown, hero1);

            obj.trans_matrix(0.0f, increment2, hero1); //прыжок

            obj.trans_matrix(speedtr, 0.0f, hero2);
            obj.trans_matrix(speedtl, 0.0f, hero2);
            obj.trans_matrix(0.0f, speedup, hero2);
            obj.trans_matrix(0.0f, speeddown, hero2);

            obj.trans_matrix(0.0f, increment2, hero2); //прыжок

            obj.trans_matrix(speedtr, 0.0f, hero3);
            obj.trans_matrix(speedtl, 0.0f, hero3);
            obj.trans_matrix(0.0f, speedup, hero3);
            obj.trans_matrix(0.0f, speeddown, hero3);

            obj.trans_matrix(0.0f, increment2, hero3); //прыжок

            //расставляем признаки того, что мельница сгорела, чтобы
            //разрушить основание
            if (left_blade_crashed && right_blade_crashed &&
                left_blade_crashed && down_blade_crashed)
            {
                mill_one_crashed = true;
            }
            if (left_blade_crashed_r && right_blade_crashed_r &&
                left_blade_crashed_r && down_blade_crashed_r)
            {
                mill_two_crashed = true;
            }
            if (left_blade_crashed_c && right_blade_crashed_c &&
                left_blade_crashed_c && down_blade_crashed_c)
            {
                mill_three_crashed = true;
            }

            //основание мельницы 1 сгорело
            if (!mill_one_crashed)
            {
                obj.trans_matrix(0.0f, 0.0f, millbase1);
                obj.trans_matrix(0.0f, 0.0f, millbase2);
            }
            else
            {
                if (millbase1.v[1].y > -0.8f)
                {
                    obj.trans_matrix(0.0f, -0.003f, millbase1);
                    obj.trans_matrix(0.0f, -0.003f, millbase2);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, millbase1);
                    obj.trans_matrix(0.0f, 0.0f, millbase2);
                    game_over_flag = true;
                }
            }

            //основание мельницы 2 сгорело
            if (!mill_two_crashed)
            {
                obj.trans_matrix(0.0f, 0.0f, millbase1_r);
                obj.trans_matrix(0.0f, 0.0f, millbase2_r);
            }
            else
            {
                if (millbase1_r.v[1].y > -0.8f)
                {
                    obj.trans_matrix(0.0f, -0.003f, millbase1_r);
                    obj.trans_matrix(0.0f, -0.003f, millbase2_r);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, millbase1_r);
                    obj.trans_matrix(0.0f, 0.0f, millbase2_r);
                    game_over_flag = true;
                }
            }
            //основание мельницы 3 сгорело
            if (!mill_three_crashed)
            {
                obj.trans_matrix(0.0f, 0.0f, millbase1_c);
                obj.trans_matrix(0.0f, 0.0f, millbase2_c);
            }
            else
            {
                if (millbase1_c.v[1].y > -0.8f)
                {
                    obj.trans_matrix(0.0f, -0.003f, millbase1_c);
                    obj.trans_matrix(0.0f, -0.003f, millbase2_c);
                }
                else
                {
                    obj.trans_matrix(0.0f, 0.0f, millbase1_c);
                    obj.trans_matrix(0.0f, 0.0f, millbase2_c);
                    game_over_flag = true;
                }
            }
        }

        //===== Анимация тревога над мельницей 1 =====
        if (crash_of_mill && !mill_one_crashed)
        {
            alarm_ani.restart();
            alarm_number = alarm_ani.current_frame_number(delta_time);
            obj.render_textured_triangle(bell, bell_sprite.at(alarm_number));
            obj.render_textured_triangle(bell1, bell_sprite.at(alarm_number));
            if (bell_sound.play_or_not == false)
            {
                obj.play_sound(&bell_sound);
            }
        }
        else
        {
            obj.stop_sound(&bell_sound);
        }

        //===== Анимация тревога над мельницей 2 =====
        if (crash_of_mill_r && !mill_two_crashed)
        {
            alarm_ani.restart();
            alarm_number = alarm_ani.current_frame_number(delta_time);
            obj.render_textured_triangle(bell2, bell_sprite.at(alarm_number));
            obj.render_textured_triangle(bell3, bell_sprite.at(alarm_number));
            if (bell_sound2.play_or_not == false)
            {
                obj.play_sound(&bell_sound2);
            }
        }
        else
        {
            obj.stop_sound(&bell_sound2);
        }

        //===== Анимация тревога над мельницей 3 =====
        if (crash_of_mill_c && !mill_three_crashed)
        {
            alarm_ani.restart();
            alarm_number = alarm_ani.current_frame_number(delta_time);
            obj.render_textured_triangle(bell4, bell_sprite.at(alarm_number));
            obj.render_textured_triangle(bell5, bell_sprite.at(alarm_number));
            if (bell_sound3.play_or_not == false)
            {
                obj.play_sound(&bell_sound3);
            }
        }
        else
        {
            obj.stop_sound(&bell_sound3);
        }

        //===== капли дождя за героем =====
        if (delta_time_rain >= 0.03)
        {
            delta_time_rain = 0;
            //капля 1
            obj.trans_matrix(cloud_speed, rain_speed, drop);
            obj.trans_matrix(cloud_speed, rain_speed, drop1);

            //капля 3
            obj.trans_matrix(cloud_speed, rain_speed, drop4);
            obj.trans_matrix(cloud_speed, rain_speed, drop5);

            //капля5
            obj.trans_matrix(cloud_speed, rain_speed, drop8);
            obj.trans_matrix(cloud_speed, rain_speed, drop9);

            //капля7
            obj.trans_matrix(cloud_speed, rain_speed2, drop12);
            obj.trans_matrix(cloud_speed, rain_speed2, drop13);

            //капля9
            obj.trans_matrix(cloud_speed, rain_speed2, drop16);
            obj.trans_matrix(cloud_speed, rain_speed2, drop17);

            //капля11
            obj.trans_matrix(cloud_speed, rain_speed, drop20);
            obj.trans_matrix(cloud_speed, rain_speed, drop21);

            //капля13
            obj.trans_matrix(cloud_speed, rain_speed, drop24);
            obj.trans_matrix(cloud_speed, rain_speed, drop25);

            //капля15
            obj.trans_matrix(cloud_speed, rain_speed, drop28);
            obj.trans_matrix(cloud_speed, rain_speed, drop29);

            //капля17
            obj.trans_matrix(cloud_speed, rain_speed2, drop32);
            obj.trans_matrix(cloud_speed, rain_speed2, drop33);

            //капля19
            obj.trans_matrix(cloud_speed, rain_speed2, drop36);
            obj.trans_matrix(cloud_speed, rain_speed2, drop37);

            //капля21
            obj.trans_matrix(cloud_speed, rain_speed, drop40);
            obj.trans_matrix(cloud_speed, rain_speed, drop41);

            //капля23
            obj.trans_matrix(cloud_speed, rain_speed, drop44);
            obj.trans_matrix(cloud_speed, rain_speed, drop45);

            //капля25
            obj.trans_matrix(cloud_speed, rain_speed, drop48);
            obj.trans_matrix(cloud_speed, rain_speed, drop49);
        }

        if (drop1.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop);
            obj.trans_matrix(0.0f, 1.8f, drop1);
        }
        if (drop5.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop4);
            obj.trans_matrix(0.0f, 1.8f, drop5);
        }
        if (drop9.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop8);
            obj.trans_matrix(0.0f, 1.8f, drop9);
        }
        if (drop13.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop12);
            obj.trans_matrix(0.0f, 1.8f, drop13);
        }
        if (drop17.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop16);
            obj.trans_matrix(0.0f, 1.8f, drop17);
        }
        if (drop21.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop20);
            obj.trans_matrix(0.0f, 1.8f, drop21);
        }
        if (drop25.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop24);
            obj.trans_matrix(0.0f, 1.8f, drop25);
        }
        if (drop29.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop28);
            obj.trans_matrix(0.0f, 1.8f, drop29);
        }
        if (drop33.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop32);
            obj.trans_matrix(0.0f, 1.8f, drop33);
        }
        if (drop37.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop36);
            obj.trans_matrix(0.0f, 1.8f, drop37);
        }
        if (drop41.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop40);
            obj.trans_matrix(0.0f, 1.8f, drop41);
        }
        if (drop45.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop44);
            obj.trans_matrix(0.0f, 1.8f, drop45);
        }
        if (drop49.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop48);
            obj.trans_matrix(0.0f, 1.8f, drop49);
        }

        obj.render_textured_triangle(drop, raindrop);
        obj.render_textured_triangle(drop1, raindrop);

        obj.render_textured_triangle(drop4, raindrop);
        obj.render_textured_triangle(drop5, raindrop);

        obj.render_textured_triangle(drop8, raindrop);
        obj.render_textured_triangle(drop9, raindrop);

        obj.render_textured_triangle(drop12, raindrop);
        obj.render_textured_triangle(drop13, raindrop);

        obj.render_textured_triangle(drop16, raindrop);
        obj.render_textured_triangle(drop17, raindrop);

        obj.render_textured_triangle(drop20, raindrop);
        obj.render_textured_triangle(drop21, raindrop);

        obj.render_textured_triangle(drop24, raindrop);
        obj.render_textured_triangle(drop25, raindrop);

        obj.render_textured_triangle(drop28, raindrop);
        obj.render_textured_triangle(drop29, raindrop);

        obj.render_textured_triangle(drop32, raindrop);
        obj.render_textured_triangle(drop33, raindrop);

        obj.render_textured_triangle(drop36, raindrop);
        obj.render_textured_triangle(drop37, raindrop);

        obj.render_textured_triangle(drop40, raindrop);
        obj.render_textured_triangle(drop41, raindrop);

        obj.render_textured_triangle(drop44, raindrop);
        obj.render_textured_triangle(drop45, raindrop);

        obj.render_textured_triangle(drop48, raindrop);
        obj.render_textured_triangle(drop49, raindrop);

        //===== рендер Мельницы 1 =====
        obj.render_textured_triangle(millbase1, millbase);
        obj.render_textured_triangle(millbase2, millbase);

        obj.render_textured_triangle(bl_down1, down);
        obj.render_textured_triangle(bl_down2, down);

        obj.render_textured_triangle(bl_up1, up);
        obj.render_textured_triangle(bl_up2, up);

        obj.render_textured_triangle(bl_right1, left);
        obj.render_textured_triangle(bl_right2, left);
        obj.render_textured_triangle(bl_left1, right);
        obj.render_textured_triangle(bl_left2, right);

        obj.render_textured_triangle(pl_down1, platform);
        obj.render_textured_triangle(pl_down2, platform);

        //===== рендер Мельницы 2 =====
        obj.render_textured_triangle(millbase1_r, millbase);
        obj.render_textured_triangle(millbase2_r, millbase);
        obj.render_textured_triangle(bl_down1_r, down);
        obj.render_textured_triangle(bl_down2_r, down);

        obj.render_textured_triangle(bl_up1_r, up);
        obj.render_textured_triangle(bl_up2_r, up);

        obj.render_textured_triangle(bl_right1_r, left);
        obj.render_textured_triangle(bl_right2_r, left);
        obj.render_textured_triangle(bl_left1_r, right);
        obj.render_textured_triangle(bl_left2_r, right);

        obj.render_textured_triangle(pl_down1_r, platform);
        obj.render_textured_triangle(pl_down2_r, platform);

        //===== рендер Мельницы 3 =====
        obj.render_textured_triangle(millbase1_c, millbase);
        obj.render_textured_triangle(millbase2_c, millbase);
        obj.render_textured_triangle(bl_down1_c, down);
        obj.render_textured_triangle(bl_down2_c, down);

        obj.render_textured_triangle(bl_up1_c, up);
        obj.render_textured_triangle(bl_up2_c, up);

        obj.render_textured_triangle(bl_right1_c, left);
        obj.render_textured_triangle(bl_right2_c, left);
        obj.render_textured_triangle(bl_left1_c, right);
        obj.render_textured_triangle(bl_left2_c, right);

        obj.render_textured_triangle(pl_down1_c, platform);
        obj.render_textured_triangle(pl_down2_c, platform);

        //===== Анимация герой стоит смотрит вправо =====
        if (look_to_right && !key_A_flag && !key_D_flag && jump_flag == 0)
        {
            ani.restart();
            number = ani.current_frame_number(delta_time);
            obj.render_textured_triangle(hero, idle_sprite.at(number));
            obj.render_textured_triangle(hero1, idle_sprite.at(number));
        }

        //===== Анимация герой стоит смотрит влево =====
        if (!look_to_right && !key_A_flag && !key_D_flag && jump_flag == 0)
        {
            ani.restart();
            number = ani.current_frame_number(delta_time);
            obj.render_textured_triangle(hero2, idle_sprite.at(number));
            obj.render_textured_triangle(hero3, idle_sprite.at(number));
        }

        //===== Анимации герой бежит вправо =====
        if (key_D_flag && !jump_flag && !key_SPACE_flag && !key_A_flag)
        {
            look_to_right = true;

            run_ani.restart();
            run_ani_number = run_ani.current_frame_number(delta_time);
            obj.render_textured_triangle(hero, run_sprite.at(run_ani_number));
            obj.render_textured_triangle(hero1, run_sprite.at(run_ani_number));
        }

        //===== Анимации герой бежит влево =====
        if (key_A_flag && !jump_flag && !key_SPACE_flag && !key_D_flag)
        {
            look_to_right = false;

            run_ani.restart();
            run_ani_number = run_ani.current_frame_number(delta_time);
            obj.render_textured_triangle(hero2, run_sprite.at(run_ani_number));
            obj.render_textured_triangle(hero3, run_sprite.at(run_ani_number));
        }

        //===== Анимация герой ПРЫГАЕТ вправо =====
        if (look_to_right && jump_flag)
        {
            if (!key_D_flag && !key_A_flag)
            {
                jump_ani.restart();
                jump_ani_number = jump_ani.current_frame_number(delta_time);
                obj.render_textured_triangle(hero,
                                             jump_sprite.at(jump_ani_number));
                obj.render_textured_triangle(hero1,
                                             jump_sprite.at(jump_ani_number));
            }
            else if (key_D_flag)
            {
                look_to_right = true;
                jump_ani.restart();
                jump_ani_number = jump_ani.current_frame_number(delta_time);
                obj.render_textured_triangle(hero,
                                             jump_sprite.at(jump_ani_number));
                obj.render_textured_triangle(hero1,
                                             jump_sprite.at(jump_ani_number));
            }
            else if (key_A_flag)
            {
                look_to_right = false;
                jump_ani.restart();
                jump_ani_number = jump_ani.current_frame_number(delta_time);
                obj.render_textured_triangle(hero2,
                                             jump_sprite.at(jump_ani_number));
                obj.render_textured_triangle(hero3,
                                             jump_sprite.at(jump_ani_number));
            }
        }

        //===== Анимация герой прыгает влево  =====
        if (!look_to_right && jump_flag)
        {
            if (!key_D_flag && !key_A_flag)
            {
                jump_ani.restart();
                jump_ani_number = jump_ani.current_frame_number(delta_time);
                obj.render_textured_triangle(hero2,
                                             jump_sprite.at(jump_ani_number));
                obj.render_textured_triangle(hero3,
                                             jump_sprite.at(jump_ani_number));
            }
            else if (key_D_flag)
            {
                look_to_right = true;
                jump_ani.restart();
                jump_ani_number = jump_ani.current_frame_number(delta_time);
                obj.render_textured_triangle(hero,
                                             jump_sprite.at(jump_ani_number));
                obj.render_textured_triangle(hero1,
                                             jump_sprite.at(jump_ani_number));
            }
            else if (key_A_flag)
            {
                look_to_right = false;
                jump_ani.restart();
                jump_ani_number = jump_ani.current_frame_number(delta_time);
                obj.render_textured_triangle(hero2,
                                             jump_sprite.at(jump_ani_number));
                obj.render_textured_triangle(hero3,
                                             jump_sprite.at(jump_ani_number));
            }
        }

        //===== герой подбивает головой облако =====
        if ((hero1.v[0].y >= cloud.v[0].y || hero3.v[0].y >= cloud.v[0].y) &&
            hero1.v[1].x >= cloud.v[0].x && hero1.v[0].x <= cloud.v[2].x &&
            hero3.v[1].x >= cloud.v[0].x && hero3.v[0].x <= cloud.v[2].x &&
            key_E_flag)
        {
            cloud_move_to_right = true;
        }

        if ((hero1.v[0].y >= cloud.v[0].y || hero3.v[0].y >= cloud.v[0].y) &&
            hero1.v[1].x >= cloud.v[0].x && hero1.v[0].x <= cloud.v[2].x &&
            hero3.v[1].x >= cloud.v[0].x && hero3.v[0].x <= cloud.v[2].x &&
            key_Q_flag)
        {
            cloud_move_to_left = true;
        }

        //остановить облако над правой мельницей
        if (cloud.v[2].x >= 0.9f)
        {
            cloud_move_to_right = false;
            cloud_position_3    = true;
            cloud_position_2    = false;
        }
        else
        {
            cloud_position_3 = false;
        }

        //остановить облако над левой мельницей
        if (cloud.v[0].x < -0.899f)
        {
            cloud_move_to_left = false;
            cloud_position_1   = true;
            cloud_position_2   = false;
        }
        else
        {
            cloud_position_1 = false;
        }

        //остановить облако над средней мельницей
        if (cloud_move_to_right && cloud.v[2].x >= 0.25f && !cloud_position_3 &&
            !cloud_position_1)
        {
            if (cloud_position_2)
            {
                cloud_move_to_right = true;
            }
            else
            {
                cloud_position_2    = true;
                cloud_move_to_right = false;
                cloud_move_to_left  = false;
            }
        }

        if (cloud_move_to_left && cloud.v[0].x <= -0.25f)
        {
            if (cloud_position_2)
            {
                cloud_move_to_left = true;
            }
            else
            {
                cloud_position_2    = true;
                cloud_move_to_right = false;
                cloud_move_to_left  = false;
            }
        }

        //===== капли дождя перед героем, движение облака и огня =====
        if (delta_time_rain2 >= 0.03)
        {
            delta_time_rain2 = 0;
            rain.reset();

            if (cloud_move_to_right)
            {
                cloud_speed = cload_speed_value;
            }

            else if (cloud_move_to_left)
            {
                cloud_speed = -cload_speed_value;
            }
            else
            {
                cloud_speed = 0.0f;
            }
            //логика движения огня в зависимости от позиции тучи
            //если огонь достиг верхней отметки, то взводим флаг для
            //разрушения мельницы
            if (cloud_position_1)
            {
                crash_of_mill = false;
                timer_started = false;

                if (!fire_1_down_pos_limit)
                {
                    fire_speed_1 = -fire_speed_1_value * 2.5f;
                }
                else
                {
                    fire_speed_1 = 0.0f;
                }
            }
            else
            {
                if (fire_1_up_pos_limit)
                {
                    fire_speed_1  = 0.0f;
                    crash_of_mill = true;
                }
                else
                {
                    fire_speed_1 = fire_speed_1_value;
                }
            }

            //если облако над мельницей 3 (центр)
            if (cloud_position_2)
            {
                crash_of_mill_c = false;
                timer_started_c = false;

                if (!fire_2_down_pos_limit)
                {
                    fire_speed_2 = -fire_speed_2_value * 2.5f;
                }
                else
                {
                    fire_speed_2 = 0.0f;
                }
            }
            else
            {
                if (fire_2_up_pos_limit)
                {
                    fire_speed_2    = 0.0f;
                    crash_of_mill_c = true;
                }
                else
                {
                    fire_speed_2 = fire_speed_2_value;
                }
            }

            //если облако над мельницей 2 (правой)
            if (cloud_position_3)
            {
                crash_of_mill_r = false;
                timer_started_r = false;

                if (!fire_3_down_pos_limit)
                {
                    fire_speed_3 = -fire_speed_3_value * 2.5f;
                }
                else
                {
                    fire_speed_3 = 0.0f;
                }
            }
            else
            {
                if (fire_3_up_pos_limit)
                {
                    fire_speed_3    = 0.0f;
                    crash_of_mill_r = true;
                }
                else
                {
                    fire_speed_3 = fire_speed_3_value;
                }
            }

            //движение огня под мельницей 1 (левой)
            if (fire.v[0].y <= -1.2f)
            {
                fire_1_down_pos_limit = true;
            }
            else
            {
                fire_1_down_pos_limit = false;
            }
            if (fire.v[0].y >= -0.91f)
            {
                fire_1_up_pos_limit = true;
            }
            else
            {
                fire_1_up_pos_limit = false;
            }

            obj.trans_matrix(0.0, fire_speed_1, fire);
            obj.trans_matrix(0.0, fire_speed_1, fire1);

            //огонь мельница 3 (центр)
            if (fire2.v[0].y <= -1.2f)
            {
                fire_2_down_pos_limit = true;
            }
            else
            {
                fire_2_down_pos_limit = false;
            }
            if (fire2.v[0].y >= -0.91f)
            {
                fire_2_up_pos_limit = true;
            }
            else
            {
                fire_2_up_pos_limit = false;
            }
            obj.trans_matrix(0.0, fire_speed_2, fire2);
            obj.trans_matrix(0.0, fire_speed_2, fire3);

            //огонь мельница 2 (правая)
            if (fire4.v[0].y <= -1.2f)
            {
                fire_3_down_pos_limit = true;
            }
            else
            {
                fire_3_down_pos_limit = false;
            }
            if (fire4.v[0].y >= -0.91f)
            {
                fire_3_up_pos_limit = true;
            }
            else
            {
                fire_3_up_pos_limit = false;
            }
            obj.trans_matrix(0.0, fire_speed_3, fire4);
            obj.trans_matrix(0.0, fire_speed_3, fire5);

            //капля 2
            obj.trans_matrix(cloud_speed, rain_speed2, drop2);
            obj.trans_matrix(cloud_speed, rain_speed2, drop3);

            //капля 4
            obj.trans_matrix(cloud_speed, rain_speed2, drop6);
            obj.trans_matrix(cloud_speed, rain_speed2, drop7);

            //капля 6
            obj.trans_matrix(cloud_speed, rain_speed, drop10);
            obj.trans_matrix(cloud_speed, rain_speed, drop11);

            //капля 8
            obj.trans_matrix(cloud_speed, rain_speed, drop14);
            obj.trans_matrix(cloud_speed, rain_speed, drop15);

            //капля 10
            obj.trans_matrix(cloud_speed, rain_speed, drop18);
            obj.trans_matrix(cloud_speed, rain_speed, drop19);

            //капля 12
            obj.trans_matrix(cloud_speed, rain_speed2, drop22);
            obj.trans_matrix(cloud_speed, rain_speed2, drop23);

            //капля 14
            obj.trans_matrix(cloud_speed, rain_speed2, drop26);
            obj.trans_matrix(cloud_speed, rain_speed2, drop27);

            //капля 16
            obj.trans_matrix(cloud_speed, rain_speed, drop30);
            obj.trans_matrix(cloud_speed, rain_speed, drop31);

            //капля 18
            obj.trans_matrix(cloud_speed, rain_speed, drop34);
            obj.trans_matrix(cloud_speed, rain_speed, drop35);

            //капля 20
            obj.trans_matrix(cloud_speed, rain_speed, drop38);
            obj.trans_matrix(cloud_speed, rain_speed, drop39);

            //капля 22
            obj.trans_matrix(cloud_speed, rain_speed2, drop42);
            obj.trans_matrix(cloud_speed, rain_speed2, drop43);

            //капля 24
            obj.trans_matrix(cloud_speed, rain_speed2, drop46);
            obj.trans_matrix(cloud_speed, rain_speed2, drop47);

            //облако
            obj.trans_matrix(cloud_speed, 0.0, cloud);
            obj.trans_matrix(cloud_speed, 0.0, cloud1);
        }
        if (drop3.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop2);
            obj.trans_matrix(0.0f, 1.8f, drop3);
        }
        if (drop7.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop6);
            obj.trans_matrix(0.0f, 1.8f, drop7);
        }
        if (drop11.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop10);
            obj.trans_matrix(0.0f, 1.8f, drop11);
        }
        if (drop15.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop14);
            obj.trans_matrix(0.0f, 1.8f, drop15);
        }
        if (drop19.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop18);
            obj.trans_matrix(0.0f, 1.8f, drop19);
        }
        if (drop23.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop22);
            obj.trans_matrix(0.0f, 1.8f, drop23);
        }
        if (drop27.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop26);
            obj.trans_matrix(0.0f, 1.8f, drop27);
        }
        if (drop31.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop30);
            obj.trans_matrix(0.0f, 1.8f, drop31);
        }
        if (drop35.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop34);
            obj.trans_matrix(0.0f, 1.8f, drop35);
        }
        if (drop39.v[0].y < -1)
        {
            obj.trans_matrix(0.0f, 1.8f, drop38);
            obj.trans_matrix(0.0f, 1.8f, drop39);
        }
        if (drop43.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop42);
            obj.trans_matrix(0.0f, 1.8f, drop43);
        }
        if (drop47.v[0].y < -1.0f)
        {
            obj.trans_matrix(0.0f, 1.8f, drop46);
            obj.trans_matrix(0.0f, 1.8f, drop47);
        }

        //===== анимация огня под мельницей 1 =====
        fire_ani.restart();
        fire_number = fire_ani.current_frame_number(delta_time);
        obj.render_textured_triangle(fire, fire_sprite.at(fire_number));
        obj.render_textured_triangle(fire1, fire_sprite.at(fire_number));

        //===== анимация огня под мельницей 2 =====
        fire_ani.restart();
        fire_number = fire_ani.current_frame_number(delta_time);
        obj.render_textured_triangle(fire2, fire_sprite.at(fire_number));
        obj.render_textured_triangle(fire3, fire_sprite.at(fire_number));

        //===== анимация огня под мельницей 3 =====
        fire_ani.restart();
        fire_number = fire_ani.current_frame_number(delta_time);
        obj.render_textured_triangle(fire4, fire_sprite.at(fire_number));
        obj.render_textured_triangle(fire5, fire_sprite.at(fire_number));

        //===== анимация огня на всю длину экрана =====
        long_fire_ani.restart();
        long_fire_number = long_fire_ani.current_frame_number(delta_time);
        obj.render_textured_triangle(l_fire,
                                     long_fire_sprite.at(long_fire_number));
        obj.render_textured_triangle(l_fire2,
                                     long_fire_sprite.at(long_fire_number));
        obj.render_textured_triangle(l_fire3,
                                     long_fire_sprite.at(long_fire_number));
        obj.render_textured_triangle(l_fire4,
                                     long_fire_sprite.at(long_fire_number));

        //рендер капель дождя перед героем
        obj.render_textured_triangle(drop2, raindrop);
        obj.render_textured_triangle(drop3, raindrop);

        obj.render_textured_triangle(drop6, raindrop);
        obj.render_textured_triangle(drop7, raindrop);

        obj.render_textured_triangle(drop10, raindrop);
        obj.render_textured_triangle(drop11, raindrop);

        obj.render_textured_triangle(drop14, raindrop);
        obj.render_textured_triangle(drop15, raindrop);

        obj.render_textured_triangle(drop18, raindrop);
        obj.render_textured_triangle(drop19, raindrop);

        obj.render_textured_triangle(drop22, raindrop);
        obj.render_textured_triangle(drop23, raindrop);

        obj.render_textured_triangle(drop26, raindrop);
        obj.render_textured_triangle(drop27, raindrop);

        obj.render_textured_triangle(drop30, raindrop);
        obj.render_textured_triangle(drop31, raindrop);

        obj.render_textured_triangle(drop34, raindrop);
        obj.render_textured_triangle(drop35, raindrop);

        obj.render_textured_triangle(drop38, raindrop);
        obj.render_textured_triangle(drop39, raindrop);

        obj.render_textured_triangle(drop42, raindrop);
        obj.render_textured_triangle(drop43, raindrop);

        obj.render_textured_triangle(drop46, raindrop);
        obj.render_textured_triangle(drop47, raindrop);

        obj.render_textured_triangle(cloud, cloud_t);
        obj.render_textured_triangle(cloud1, cloud_t);

        //рендер таймера
        // timer_render_seconds(obj, sec, sec2);
        obj.render_textured_triangle(seconds, time_sprite.at(sec));
        obj.render_textured_triangle(seconds1, time_sprite.at(sec));
        obj.render_textured_triangle(seconds2, time_sprite.at(sec2));
        obj.render_textured_triangle(seconds3, time_sprite.at(sec2));

        obj.render_textured_triangle(dot, dot_t);
        obj.render_textured_triangle(dot1, dot_t);

        obj.render_textured_triangle(minutes, time_sprite.at(min));
        obj.render_textured_triangle(minutes1, time_sprite.at(min));
        obj.render_textured_triangle(minutes2, time_sprite.at(min2));
        obj.render_textured_triangle(minutes3, time_sprite.at(min2));

        obj.swap_buffers();
    } //КОНЕЦ ИГРОВОГО ЦИКЛА

    return EXIT_SUCCESS;
}
