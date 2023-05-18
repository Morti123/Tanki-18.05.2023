#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 1500;
const float WINDOW_HEIGHT = 900;
const std::string WINDOW_TITLE = "SFML Asteroids P53122";
const float FPS = 60.f;
const float PI = 3.14159265358;

const std::string Player_1_File_Name = "images\\Player_1.png";
const std::string Player_2_File_Name = "images\\Player_2.png";
const std::string Fon_File_Name = "images\\FonObject.jpg";
const std::string Bullet_1_File_Name = "images\\Bullet_1.png";
const std::string Bullet_2_File_Name = "images\\Bullet_2.png";

const float Bullet_speed = 10.f;
const int Player_max_hp = 100;
const float FRAME_WIDTH = 150;
const float FRAME_HEIGHT = 25;
const sf::Vector2f FonStartPos{ 0, 0 };
const float Fon_offset = 50.f;
const int fire_cooldown = 1000.f;
const int Bullet_damage = 25;
const int CHAR_SIZE = 52;
const sf::Vector2f Game_text_pos(600.f, 410.f);
float Player_Max_Speed = 2.f;
float dv = 1;

const std::string RAGE_FILE_NAME{ "images\\Rage.png" };
const std::string  MEDKIT_FILE_NAME{ "images\\MedKit.png" };
const std::string SPEED_BOOST_FILE_NAME{ "images\\Speed_boost.png" };
