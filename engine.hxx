#pragma once

// turn off the specific warning. Can also use "-Wall"
#define STB_IMAGE_IMPLEMENTATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "stb_image.h"
#pragma GCC diagnostic pop

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_opengl_glext.h>
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>

PFNGLCREATESHADERPROC             glCreateShader             = nullptr;
PFNGLSHADERSOURCEPROC             glShaderSource             = nullptr;
PFNGLCOMPILESHADERPROC            glCompileShader            = nullptr;
PFNGLGETSHADERIVPROC              glGetShaderiv              = nullptr;
PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog         = nullptr;
PFNGLDELETESHADERPROC             glDeleteShader             = nullptr;
PFNGLCREATEPROGRAMPROC            glCreateProgram            = nullptr;
PFNGLATTACHSHADERPROC             glAttachShader             = nullptr;
PFNGLBINDATTRIBLOCATIONPROC       glBindAttribLocation       = nullptr;
PFNGLLINKPROGRAMPROC              glLinkProgram              = nullptr;
PFNGLGETPROGRAMIVPROC             glGetProgramiv             = nullptr;
PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog        = nullptr;
PFNGLDELETEPROGRAMPROC            glDeleteProgram            = nullptr;
PFNGLUSEPROGRAMPROC               glUseProgram               = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer      = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray  = nullptr;
PFNGLVALIDATEPROGRAMPROC          glValidateProgram          = nullptr;
PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation       = nullptr;
PFNGLUNIFORM1IPROC                glUniform1i                = nullptr;
PFNGLACTIVETEXTUREPROC            glActiveTexture_           = nullptr;
PFNGLUNIFORM4FVPROC               glUniform4fv               = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;

template <typename T>
static void load_gl_func(const char* func_name, T& result)
{
    void* gl_pointer = SDL_GL_GetProcAddress(func_name);
    result           = reinterpret_cast<T>(gl_pointer);
    std::cout << result << "\n";
    if (nullptr == gl_pointer)
    {
        throw std::runtime_error(std::string("can't load GL function") +
                                 func_name);
    }
    result = reinterpret_cast<T>(gl_pointer);
}

struct vertex
{
    float x = 0.f;
    float y = 0.f;

    float tx = 0.f; //для текстур
    float ty = 0.f;
};

struct triangle
{
    triangle()
    {
        v[0] = vertex();
        v[1] = vertex();
        v[2] = vertex();
    }
    vertex v[3];
};

std::istream& operator>>(std::istream& is, vertex& v)
{
    is >> v.x;
    is >> v.y;

    is >> v.tx;
    is >> v.ty;
    return is;
}

struct sound_buffer
{
    Uint8* start;
    Uint32 size;
    int    current_pos;
    bool   play_or_not = false;
};

std::vector<sound_buffer*> sound;
void                       callback(void* userdata, Uint8* stream, int len);

//флаги для общения игры с движком
bool key_W_flag     = false;
bool key_S_flag     = false;
bool key_A_flag     = false;
bool key_D_flag     = false;
bool key_SPACE_flag = false;
bool key_LCTRL_flag = false;
bool key_ENTER_flag = false;
bool key_Esc_flag   = false;
bool key_Q_flag     = false;
bool key_E_flag     = false;

const float pi = 3.1415926f;

class rotation
{
public:
    rotation(){};
    ~rotation(){};

    void set_speed_of_rotation(double s) { speed_of_rotation = s; }

    double one_degree_time()
    {
        // time_for_one_degree = 1 / ((speed_of_rotation*360) / 60);
        time_for_one_degree = 1 / (speed_of_rotation * 6);
        return time_for_one_degree;
    }
    void set_direction(int d) { direction_of_rotation = d; }
    int  get_direction() { return direction_of_rotation; }

private:
    //скорость вращения в об / мин
    double speed_of_rotation;
    //время для поворота на 1 градус в секундах
    double time_for_one_degree;
    //направление вращения: пр.ч.с == 1; по.ч.с == -1;
    int direction_of_rotation = 1;
};

class animation
{
public:
    animation(){};
    ~animation(){};

    // float fps()const {return fps_;}
    void set_fps(float fps_value) { fps = fps_value; }
    void set_number_of_frames(float f) { number_of_frames = f; }

    void restart() { current_time = 0.f; }

    int current_frame_number(float delta_time)
    {
        current_time += delta_time;

        float one_frame_delta = 1.f / fps;

        size_t how_may_frames_from_start =
            static_cast<size_t>(current_time / one_frame_delta);

        size_t current_frame_index =
            how_may_frames_from_start % number_of_frames;

        return current_frame_index;
    }

    void set_last_frame(int lf) { last_frame = lf; }
    int  get_last_frame() { return last_frame; }

private:
    int number_of_frames; //число спрайтов в одной анимации
    float fps;
    float current_time = 0.f;
    int   last_frame   = 0;
};

//============= Класс работы со временем ==============
class timer
{
public:
    timer()
        : m_beg(clock_t::now())
    {
    }

    void reset() { m_beg = clock_t::now(); }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg)
            .count();
    }

private:
    using clock_t  = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> m_beg;
};

//============= Класс engine ==================================================
class engine
{

public:
    //================== установить путь к папке с текстурами и звуками ========
    void set_resources_path(std::string str) { resources = str; };

    //================== установить параметры окна ==========================
    void set_window_width(int w) { width = w; }
    void set_window_height(int h) { height = h; }

    //================== инициализация SDL2 ==========================
    bool initialize()
    {
        if ((SDL_Init(SDL_INIT_EVERYTHING)) != 0)
        {
            const char* err_message = SDL_GetError();
            std::cerr << "error: failed call SDL_Init: " << err_message
                      << std::endl;
            return EXIT_FAILURE;
        }

        window = SDL_CreateWindow("Miller in the Fire", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, width, height,
                                  ::SDL_WINDOW_OPENGL);
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
        SDL_ShowCursor(SDL_DISABLE);

        if (window == nullptr)
        {
            std::cerr << "error: failed call SDL_CreateWindow: " << std::endl;
            SDL_Quit();
            return EXIT_FAILURE;
        }

        SDL_GLContext gl_context = SDL_GL_CreateContext(window);
        SDL_assert(gl_context != nullptr);

        //==========================================================================
        load_gl_func("glCreateShader", glCreateShader);
        load_gl_func("glShaderSource", glShaderSource);
        load_gl_func("glCompileShader", glCompileShader);
        load_gl_func("glGetShaderiv", glGetShaderiv);
        load_gl_func("glGetShaderInfoLog", glGetShaderInfoLog);
        load_gl_func("glDeleteShader", glDeleteShader);
        load_gl_func("glCreateProgram", glCreateProgram);
        load_gl_func("glAttachShader", glAttachShader);
        load_gl_func("glBindAttribLocation", glBindAttribLocation);
        load_gl_func("glLinkProgram", glLinkProgram);
        load_gl_func("glGetProgramiv", glGetProgramiv);
        load_gl_func("glGetProgramInfoLog", glGetProgramInfoLog);
        load_gl_func("glDeleteProgram", glDeleteProgram);
        load_gl_func("glUseProgram", glUseProgram);
        load_gl_func("glVertexAttribPointer", glVertexAttribPointer);
        load_gl_func("glEnableVertexAttribArray", glEnableVertexAttribArray);
        load_gl_func("glValidateProgram", glValidateProgram);
        load_gl_func("glGetUniformLocation", glGetUniformLocation);
        load_gl_func("glUniform1i", glUniform1i);
        load_gl_func("glActiveTexture", glActiveTexture_);
        load_gl_func("glUniform4fv", glUniform4fv);
        load_gl_func("glDisableVertexAttribArray", glDisableVertexAttribArray);

        create_shader();

        // ===== инициализация звука =====
        wavSpec.freq     = 48000;
        wavSpec.format   = AUDIO_S16LSB;
        wavSpec.channels = 2;
        wavSpec.silence  = 0;
        wavSpec.samples  = 4096;
        wavSpec.callback = callback;
        wavSpec.userdata = NULL;

        deviceId = SDL_OpenAudioDevice(device_name, 0, &wavSpec, NULL, 0);
        SDL_PauseAudioDevice(deviceId, 0);
    }

    //===== загрузка звукового файла  =====
    sound_buffer load_sound(std::string filename, sound_buffer* e)
    {
        std::string sound_parth_and_name = resources + filename;
        SDL_LoadWAV(sound_parth_and_name.data(), &wavSpec, &wavBuffer,
                    &wavLength);

        if (wavLength == 0)
        {
            std::cerr << "sound file " << filename << " not loaded !!"
                      << "\n";
            exit;
        }

        e->start       = wavBuffer;
        e->size        = wavLength;
        e->current_pos = 0;
        e->play_or_not = false;

        SDL_LockAudioDevice(deviceId);
        sound.push_back(e);
        SDL_UnlockAudioDevice(deviceId);

        wavLength = 0;

        return *e;
    }

    //====== воспроизведение загруженного звукового файла =====
    void play_sound(sound_buffer* e)
    {
        SDL_LockAudioDevice(deviceId);
        e->play_or_not = true;
        e->current_pos = 0;
        SDL_UnlockAudioDevice(deviceId);
    }

    //====== останов воспроизведения =====
    void stop_sound(sound_buffer* e)
    {
        SDL_LockAudioDevice(deviceId);
        e->play_or_not = false;
        e->current_pos = 0;
        SDL_UnlockAudioDevice(deviceId);
    }

    //===== пауза в милисекундах ====
    void pause_ms(int ms) { SDL_Delay(ms); }

    //=== получить из игры скорости по осям ====
    void set_speedToRigth(float vlr) { speed_to_right_value = vlr; }
    void set_speedToLeft(float vll) { speed_to_left_value = vll; }
    void set_speedToUp(float vlu) { speed_to_up_value = vlu; }
    void set_speedToDown(float vld) { speed_to_down_value = vld; }

    //отдать в игру скорости по осям (и признак прыжка)
    float get_speedToRigth() { return speed_to_right; }
    float get_speedToLeft() { return speed_to_left; }
    float get_speedToUp() { return speed_to_up; }
    float get_speedToDown() { return speed_to_down; }

    //================== метод обработки клавиатуры ===========================
    bool events()
    {
        SDL_PollEvent(&test_event);

        if (test_event.type == SDL_QUIT)
        {
            return false;
        }
        if (test_event.type == SDL_KEYDOWN)
        {
            switch (test_event.key.keysym.sym)
            {
                case (SDLK_w):
                    key_W_flag  = true;
                    speed_to_up = speed_to_up_value;
                    break;
                case SDLK_s:
                    key_S_flag    = true;
                    speed_to_down = -speed_to_down_value;
                    break;
                case SDLK_a:
                    key_A_flag    = true;
                    speed_to_left = -speed_to_left_value;
                    break;
                case SDLK_d:
                    key_D_flag     = true;
                    speed_to_right = speed_to_right_value;
                    break;
                case SDLK_LCTRL:
                    key_LCTRL_flag = true;
                    break;
                case SDLK_SPACE:
                    key_SPACE_flag = true;
                    break;
                case SDLK_RETURN:
                    key_ENTER_flag = true;
                    break;
                case SDLK_ESCAPE:
                    key_Esc_flag = true;
                    return false;
                    break;
                case (SDLK_q):
                    key_Q_flag = true;
                    break;
                case (SDLK_e):
                    key_E_flag = true;
                    break;
                default:
                    break;
            }
        }

        if (test_event.type == SDL_KEYUP)
        {
            switch (test_event.key.keysym.sym)
            {
                case SDLK_w:
                    // std::cout << " W is released " << '\n';
                    key_W_flag  = false;
                    speed_to_up = 0.0f;
                    break;
                case SDLK_s:
                    // std::cout << " S is released " << '\n';
                    key_S_flag    = false;
                    speed_to_down = 0.0f;
                    break;
                case SDLK_a:
                    // std::cout << " A is released " << '\n';
                    key_A_flag    = false;
                    speed_to_left = 0.0f;
                    break;
                case SDLK_d:
                    // std::cout << " D is released " << '\n';
                    key_D_flag     = false;
                    speed_to_right = 0.0f;
                    break;
                case SDLK_LCTRL:
                    // std::cout << " BUTTON_ONE is released " << '\n';
                    key_LCTRL_flag = false;
                    break;
                case SDLK_SPACE:
                    // std::cout << " BUTTON_TWO is released " << '\n';
                    key_SPACE_flag = false;
                    // jump           = 0;
                    break;
                case SDLK_RETURN:
                    // std::cout << " START is released " << '\n';
                    key_ENTER_flag = false;
                    break;
                case (SDLK_q):
                    // std::cout << " Q is released " << '\n';
                    key_Q_flag = false;
                    break;
                case (SDLK_e):
                    // std::cout << " E is released " << '\n';
                    key_E_flag = false;
                    break;
                default:
                    break;
            }
        }
        return true;
    }

    //================ рисование треугольника =========================

    void render_triangle(const triangle& t)
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex),
                              &t.v[0]);
        glEnableVertexAttribArray(0);
        glValidateProgram(program);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    //================ рисование треугольника c текстурой ================
    void render_textured_triangle(const triangle& t, GLint texture_number)
    {
        glUniform1i(location, 0 + texture_number);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex),
                              &t.v[0]);
        glEnableVertexAttribArray(0);

        // texture coordinates
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex),
                              &t.v[0].tx);
        glEnableVertexAttribArray(1);

        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    //================== матрица переноса ==============================
    void trans_matrix(float fdeltaX, float fdeltaY, triangle& t)
    {

        t.v[0].x = (1 * t.v[0].x + 0 * t.v[0].y + fdeltaX * 1);
        t.v[0].y = (0 * t.v[0].x + 1 * t.v[0].y + fdeltaY * 1);

        t.v[1].x = (1 * t.v[1].x + 0 * t.v[1].y + fdeltaX * 1);
        t.v[1].y = (0 * t.v[1].x + 1 * t.v[1].y + fdeltaY * 1);

        t.v[2].x = (1 * t.v[2].x + 0 * t.v[2].y + fdeltaX * 1);
        t.v[2].y = (0 * t.v[2].x + 1 * t.v[2].y + fdeltaY * 1);
    }

    //================== матрица поворота ==============================
    void rotate_matrix(float frotate_angle, triangle& t)
    {
        float x0 = t.v[0].x;
        float y0 = t.v[0].y;

        float x1 = t.v[1].x;
        float y1 = t.v[1].y;

        float x2 = t.v[2].x;
        float y2 = t.v[2].y;

        t.v[0].x = (cos(frotate_angle * pi / 180) * x0 -
                    sin(frotate_angle * pi / 180) * y0 + 0 * 1);
        t.v[0].y = (sin(frotate_angle * pi / 180) * x0 +
                    cos(frotate_angle * pi / 180) * y0 + 0 * 1);

        t.v[1].x = (cos(frotate_angle * pi / 180) * x1 -
                    sin(frotate_angle * pi / 180) * y1 + 0 * 1);
        t.v[1].y = (sin(frotate_angle * pi / 180) * x1 +
                    cos(frotate_angle * pi / 180) * y1 + 0 * 1);

        t.v[2].x = (cos(frotate_angle * pi / 180) * x2 -
                    sin(frotate_angle * pi / 180) * y2 + 0 * 1);
        t.v[2].y = (sin(frotate_angle * pi / 180) * x2 +
                    cos(frotate_angle * pi / 180) * y2 + 0 * 1);
    }

    //================== матрица масштабирования ==============================
    void scale_triangle(float fscale_valueX, float fscale_valueY, triangle& t)
    {

        float x0 = t.v[0].x;
        float y0 = t.v[0].y;

        float x1 = t.v[1].x;
        float y1 = t.v[1].y;

        float x2 = t.v[2].x;
        float y2 = t.v[2].y;

        t.v[0].x = (fscale_valueX * x0 + 0 * y0 + 0 * 1);
        t.v[0].y = (0 * x0 + fscale_valueY * y0 + 0 * 1);

        t.v[1].x = (fscale_valueX * x1 + 0 * y1 + 0 * 1);
        t.v[1].y = (0 * x1 + fscale_valueY * y1 + 0 * 1);

        t.v[2].x = (fscale_valueX * x2 + 0 * y2 + 0 * 1);
        t.v[2].y = (0 * x2 + fscale_valueY * y2 + 0 * 1);
    }

    //===== подогнать треугольник под пропорции экрана =====
    void scale_to_screen(triangle& t)
    {
        t.v[0].x = t.v[0].x * get_k_screen();
        t.v[1].x = t.v[1].x * get_k_screen();
        t.v[2].x = t.v[2].x * get_k_screen();
    }

    //рассчитать и передать коээфициент масштабирования к экрану
    float get_k_screen() { return k_screen = height / width; }

    //================== матрица поворота с масштабированием================
    // НЕ ПРОВЕРЕНО !!
    void rotation(float frotate_angle, float fscale_valueX, float fscale_valueY,
                  triangle& t)
    {

        float x0 = t.v[0].x;
        float y0 = t.v[0].y;

        float x1 = t.v[1].x;
        float y1 = t.v[1].y;

        float x2 = t.v[2].x;
        float y2 = t.v[2].y;

        t.v[0].x = cos(frotate_angle * pi / 180) * fscale_valueX * x0 -
                   sin(frotate_angle * pi / 180) * fscale_valueY * y0;
        t.v[0].y = sin(frotate_angle * pi / 180) * fscale_valueX * x0 +
                   cos(frotate_angle * pi / 180) * fscale_valueY * y0;

        t.v[1].x = cos(frotate_angle * pi / 180) * fscale_valueX * x1 -
                   sin(frotate_angle * pi / 180) * fscale_valueY * y1;
        t.v[1].y = sin(frotate_angle * pi / 180) * fscale_valueX * x1 +
                   cos(frotate_angle * pi / 180) * fscale_valueY * y1;

        t.v[2].x = cos(frotate_angle * pi / 180) * fscale_valueX * x2 -
                   sin(frotate_angle * pi / 180) * fscale_valueY * y2;
        t.v[2].y = sin(frotate_angle * pi / 180) * fscale_valueX * x2 +
                   cos(frotate_angle * pi / 180) * fscale_valueY * y2;
    }

    //========== взять время через SDL2 =======================
    float get_time()
    {
        std::uint32_t ms_from_library = SDL_GetTicks();
        float         seconds         = ms_from_library * 0.001f;
        return seconds;
    }

    //========== таймер SDL2 =======================
    bool timer(float seconds)
    {
        if (SDL_TICKS_PASSED(SDL_GetTicks(), seconds * 1000))
            return true;
    }

    //=========== смешать два треугольника и время  ===========================
    triangle mix_triangles(const triangle& tr1, const triangle& tr2,
                           const float time)
    {
        triangle result;

        result.v[0].x = (1.0f - time) * tr1.v[0].x + time * tr2.v[0].x;
        result.v[0].y = (1.0f - time) * tr1.v[0].y + time * tr2.v[0].y;

        result.v[1].x = (1.0f - time) * tr1.v[1].x + time * tr2.v[1].x;
        result.v[1].y = (1.0f - time) * tr1.v[1].y + time * tr2.v[1].y;

        result.v[2].x = (1.0f - time) * tr1.v[2].x + time * tr2.v[2].x;
        result.v[2].y = (1.0f - time) * tr1.v[2].y + time * tr2.v[2].y;

        return result;
    }

    //================== загрузка png файла =============================
    int load_png(std::string file_name)
    {
        //        //найдем длину png файла
        //        std::ifstream myFile;
        //        myFile.open(file_name, std::ios::binary);
        //        if (!myFile)
        //        {
        //            std::cerr << "Cannot open file " << file_name << "\n";
        //            return EXIT_FAILURE;
        //        }
        //        myFile.seekg(0, myFile.end);
        //        int length = myFile.tellg();
        //        myFile.close();

        //        //пишем png в массив
        //        std::vector<unsigned char> png_file;
        //        std::ifstream              ifile(file_name, std::ios::binary);
        //        if (!ifile)
        //        {
        //            std::cerr << "Cannot open ifile " << file_name << "\n";
        //            return EXIT_FAILURE;
        //        }
        //        int j = length;
        //        int i = 0;
        //        while (j)
        //        {
        //            png_file.push_back(ifile.get());
        //            j--;
        //        }
        //        ifile.close();

        //        std::vector<unsigned char> image;
        //        unsigned long              w = 0;
        //        unsigned long              h = 0;
        //        int                        error =
        //            decodePNG(image, w, h, &png_file[0], png_file.size(),
        //            false);
        //        if (error != 0)
        //        {
        //            std::cerr << "error: " << error << std::endl;
        //            return false;
        //        }

        //=== загрузка как выше не подходит под андроид ====

        std::string texture_name_and_pass = resources + file_name;
        // std::string texture_name_and_pass = "sources/" + file_name;

        //=== загрузка изображения под андроид начало ===
        //функция ниже переворачивает текстуру под opengl... но я уже перевернул
        //руками :) stbi_set_flip_vertically_on_load(true);
        int            width       = 0;
        int            height      = 0;
        int            components  = 0;
        unsigned char* decoded_img = stbi_load(texture_name_and_pass.data(),
                                               &width, &height, &components, 4);

        //        unsigned char* decoded_img =
        //            stbi_load(file_name.data(), &width, &height, &components,
        //            4);
        if (decoded_img == nullptr)
        {
            std::cerr << "error: can't load file: " << texture_name_and_pass
                      << std::endl;
            // std::cerr << "error: can't load file: " << file_name <<
            // std::endl;
            throw std::runtime_error("can't load texture");
        }
        //=== загрузка изображения под андроид конец ===

        texture_id++;
        glActiveTexture_(GL_TEXTURE0 + texture_id);

        glGenTextures(1, &texture_id);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        GLint mipmap_level = 0;
        GLint border       = 0;
        //        glTexImage2D(GL_TEXTURE_2D, mipmap_level, GL_RGBA, w, h,
        //        border,
        //                     GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
        glTexImage2D(GL_TEXTURE_2D, mipmap_level, GL_RGBA, width, height,
                     border, GL_RGBA, GL_UNSIGNED_BYTE, decoded_img);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // png_file.clear();
        // image.clear();
        // n++;
        // std::cout << "picture loaded number = " << n << std::endl;

        return texture_id;
    }

    //================== переключение буферов ============================
    void swap_buffers()
    {
        SDL_GL_SwapWindow(window);
        glClearColor(0.95f, 0.95f, 1.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    //============= переключение буферов в паузе =============
    void swap_buffers2()
    {
        SDL_GL_SwapWindow(window);
        glClearColor(0.95f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    //================== очистить экран ============================
    void clear()
    {
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    //================== конструктор ===============================
    engine() {}

    //================== деструктор ===============================
    ~engine() { SDL_Quit(); }

private:
    SDL_Window* window  = nullptr;
    GLuint      program = 0;

    std::string resources;

    float width  = 1;
    float height = 1;

    //коэффициэнт искажения от пропорций экрана
    float k_screen; //= height / width;

    SDL_Event test_event;

    //==== скорости перемещения по осям X Y ====
    float speed_to_right       = 0.0f;
    float speed_to_left        = 0.0f;
    float speed_to_up          = 0.0f;
    float speed_to_down        = 0.0f;
    float speed_to_right_value = 0.0f;
    float speed_to_left_value  = 0.0f;
    float speed_to_up_value    = 0.0f;
    float speed_to_down_value  = 0.0f;
    // int   jump                 = 0.0f;
    // int n = 0;

    //==== звук ====
    SDL_AudioSpec     wavSpec;
    Uint32            wavLength;
    Uint8*            wavBuffer;
    SDL_AudioDeviceID deviceId;
    const char*       device_name = nullptr;

    //для текстур
    GLuint texture_id = 0;
    int    location;

    //создание шейдерной программы
    void create_shader()
    {
        GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);

        std::string vertex_shader_src =
            "attribute vec2 a_position;"
            "attribute vec2 a_tex_coord;"
            "varying vec2 v_tex_coord;"
            "void         main()"
            "{v_tex_coord = a_tex_coord;"
            "gl_Position = vec4(a_position, 0.0, 1.0);}";

        const char* source = vertex_shader_src.data();
        glShaderSource(vert_shader, 1, &source, nullptr);

        glCompileShader(vert_shader);

        GLint compiled_status = 0;
        glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &compiled_status);

        if (compiled_status == 0)
        {
            std::cerr << "vertex shader compilation faild !!"
                      << "\n";
            glDeleteShader(vert_shader);
        }

        // create fragment shader
        GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

        std::string fragment_shader_src =
            "varying vec2 v_tex_coord;"
            "uniform sampler2D s_texture;"
            "void main()"
            "{gl_FragColor = texture2D(s_texture, v_tex_coord);}";
        source = fragment_shader_src.data();
        glShaderSource(fragment_shader, 1, &source, nullptr);

        glCompileShader(fragment_shader);

        compiled_status = 0;
        glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &compiled_status);

        if (compiled_status == 0)
        {
            std::cerr << "fragment shader compilation faild !!"
                      << "\n";
            glDeleteShader(fragment_shader);
        }

        program = glCreateProgram();

        glAttachShader(program, vert_shader);
        glAttachShader(program, fragment_shader);

        glBindAttribLocation(program, 0, "a_position");
        glLinkProgram(program);
        glUseProgram(program);
        location = glGetUniformLocation(program, "s_texture");
        if (location < 0)
        {
            std::cerr << "unuform problem !!"
                      << "\n";
        }
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

}; //====== конец класса engine ======

void callback(void* userdata, Uint8* stream, int len)
{
    //тишина по умолчанию
    std::memset(stream, 0, len);

    for (sound_buffer* n : sound)
    {
        if (n->play_or_not == true)
        {
            uint8_t* current_buff = &n->start[n->current_pos];
            int      rest         = n->size - n->current_pos;

            if (rest <= len)
            {
                SDL_MixAudioFormat(stream, current_buff, AUDIO_S16LSB, rest,
                                   SDL_MIX_MAXVOLUME);
                n->current_pos += rest;
            }
            else
            {
                SDL_MixAudioFormat(stream, current_buff, AUDIO_S16LSB, len,
                                   SDL_MIX_MAXVOLUME);
                n->current_pos += len;
            }
            if (n->current_pos == n->size)
            {
                n->play_or_not = false;
            }
        }
    }
}
