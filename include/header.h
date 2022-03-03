/*
** EPITECH PROJECT, 2021
** header
** File description:
** runner
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#ifndef HEADER_H
    #define HEADER_H
    #define SCALE 6
typedef struct {
    sfFont *font;
    sfText *text;
} textstruct;
typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    float speedy;
    float speedx;
    int state;
    int isjumping;
} spritestruct;
typedef struct {
    int state;
    sfVector2f pos;
    int alive;
    int explode;
    int check;
} entitystruct;
typedef struct {
    sfMusic *music;
    sfSound *coin_effect;
    sfSoundBuffer *soundbuffer;
} sound_list;
typedef struct {
    sfClock *bgclock;
    sfClock *skyclock;
    sfClock *cycclock;
    sfClock *gameclock;
    sfClock *viewclock;
    sfClock *jumpclock;
    sfClock *barryclock;
    sfClock *dieclock;
    sfClock *mineclock;
    sfClock *boomclock;
    sfClock *placeclock;
    sfClock *coinclock;
    sfClock *planeclock;
    int timer;
} clock_list;
typedef struct {
    spritestruct background;
    spritestruct sky;
    spritestruct barry;
    spritestruct road;
    spritestruct mine;
    spritestruct global;
    spritestruct coin;
    spritestruct title;
    spritestruct menubutton;
    spritestruct playbutton;
    spritestruct settingsbutton;
    spritestruct returnbutton;
    spritestruct quitbutton;
    spritestruct settingsmenu;
    spritestruct cursor;
    spritestruct musicbarre;
    spritestruct soundbarre;
    spritestruct pausebutton;
    spritestruct restartbutton;
    spritestruct spitfire;
} sprite_list;
typedef struct {
    clock_list clock;
    sprite_list sprite;
    sound_list sound;
    sfView *view;
    sfFloatRect rectview;
    sfColor roadcolor;
    sfVector2f boompos;
    entitystruct *bomblist;
    entitystruct *coinlist;
    textstruct text;
    int health;
    int menuphase;
    int soundswitch;
    int menustate;
    float ymax;
    float xmax;
    char **map;
    float speedview;
    int boomtime;
    int boomswitch;
    int mode;
    int score;
    int highscore;
    int coinscore;
    int mousereleased;
    int pause;
    int win;
    int barryskin;
} gamestruct;
void analyse_event(sfRenderWindow *window, sfEvent event, gamestruct *game);
void actions(sfRenderWindow *window, gamestruct *game);
sfRenderWindow *create_window(int length, int height);
void close_window(sfRenderWindow *window);
void initialize_all(gamestruct *game, sfRenderWindow *window);
void menu_selecter(sfRenderWindow *window, gamestruct *game, sfEvent event);
void handle_main(sfRenderWindow *window, gamestruct *game);
void manage_mouse_click(
sfMouseButtonEvent event, gamestruct *game, sfRenderWindow *window);
void manage_mouse_begin(sfRenderWindow *window, gamestruct *game);
void manage_mouse_settings(sfRenderWindow *window, gamestruct *game);
void manage_mouse_select(sfRenderWindow *window, gamestruct *game);
void manage_mouse_select2(sfRenderWindow *window, gamestruct *game);
void manage_mouse_pause(sfRenderWindow *window, gamestruct *game);
void manage_mouse_end(sfRenderWindow *window, gamestruct *game);
void deinitialize_time(gamestruct *game);
void deinitialize_text(gamestruct *game);
void deinitialize_sprite(gamestruct *game);
void deinitialize_sprite(gamestruct *game);
void deinitialize_sound(gamestruct *game);
void deinitialize_all(gamestruct *game);
void deinitialize_game(gamestruct *game);
void use_time(gamestruct *game, sfRenderWindow *window);
void use_time2(gamestruct *game, sfRenderWindow *window);
void use_time2bis(gamestruct *game, sfRenderWindow *window,
sfVector2f viewsize, sfVector2f vector);
void use_time3(gamestruct *game, sfRenderWindow *window);
void use_time3bis(gamestruct *game, sfRenderWindow *window);
void use_time4(gamestruct *game, sfRenderWindow *window);
void use_time4bis(gamestruct *game, sfRenderWindow *window);
void use_time5(gamestruct *game, sfRenderWindow *window);
void use_time6(gamestruct *game, sfRenderWindow *window);
void use_time7(gamestruct *game, sfRenderWindow *window);
void create_bomblist(gamestruct *game, int mode);
void handle_bomb(gamestruct *game);
void handle_coin(gamestruct *game);
void display_bomb(gamestruct *game, sfRenderWindow *window);
void clignote(gamestruct *game, int flag);
void fill_bomblist(gamestruct *game, char **map);
void bomb_line(gamestruct *game, char *line, int *compt, int i);
void check_explode(gamestruct *game);
void barry_move2(gamestruct *game, int hmax);
void barry_move3(gamestruct *game, int hmax);
void barry_move4(gamestruct *game, int hmax);
void display_score(gamestruct *game, sfRenderWindow *window, int flag);
void display_score1(gamestruct *game, sfRenderWindow *window, int flag);
void display_highscore(gamestruct *game, sfRenderWindow *window, int flag);
void display_coinscore(gamestruct *game, sfRenderWindow *window, int flag);
void display_coinlogo(gamestruct *game, sfRenderWindow *window, int flag);
void plane_cycle(gamestruct *game);
void plane_display(gamestruct *game, sfRenderWindow *window);
void plane_move(gamestruct *game);
void check_road(sfRenderWindow *window, int i, int j, gamestruct *game);
void format_text(sfText *text, sfColor color, int size, char *string);
void print_text(sfRenderWindow *window, sfText *text, sfVector2f position);
void restart(gamestruct *game, sfRenderWindow *window);
void restart_bomb(gamestruct *game);
void restart_coin(gamestruct *game);
void give_skin(gamestruct *game);
int signe(float nb);
int my_itoa_len(int nb);
int check_item(int i, int j, gamestruct *game, int flag);
int check_itemx(float x, int j, int flag);
int check_itemy(float y, int i, int flag);
int place_bomb(gamestruct *game, char **map, entitystruct *bomb);
int place_coin(gamestruct *game, char **map, entitystruct *coin);
int is_hit(sfRenderWindow *window, sfSprite *sprite);
int getnbr(char *str);
int slen(char *str);
int check_pos(gamestruct *game, int i, int j, int flag);
int count_items(char **map, int flags);
int search_items(char *line, int flags);
int get_highscore(gamestruct *game, int mode);
int find_maxlen(char **map);
int find_maxlen2(char *path);
int is_hit(sfRenderWindow *window, sfSprite *sprite);
int is_in(char elem, char *list);
int place_spitfire(gamestruct *game, char **map);
int collide(sfSprite *sprite1, sfSprite *sprite2);
int display_commentary(void);
int get_linenb(char *path);
int tabslen(char **tab);
int nblen(int nb);
int preinitialize(int argc, char **argv, gamestruct *game);
spritestruct create_background(void);
spritestruct create_sky(void);
spritestruct create_barry(void);
spritestruct create_road(void);
spritestruct create_mine(void);
spritestruct create_coin(void);
spritestruct create_title(void);
spritestruct create_menubutton(void);
spritestruct create_playbutton(void);
spritestruct create_settingsbutton(void);
spritestruct create_returnbutton(void);
spritestruct create_settingsmenu(void);
spritestruct create_musicbarre(void);
spritestruct create_soundbarre(void);
spritestruct create_cursor(void);
spritestruct create_quitbutton(void);
spritestruct create_pausebutton(void);
spritestruct create_restartbutton(void);
spritestruct create_spitfire(void);
void background_display(sfRenderWindow *window, gamestruct *game);
void sky_display(sfRenderWindow *window, gamestruct *game);
void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int nb);
void display_tab(char **tab);
void initialize_sprite(gamestruct *game);
void initialize_sprite2(gamestruct *game);
void initialize_time(gamestruct *game);
void initialize_game(gamestruct *game, sfRenderWindow *window);
void initialize_game2(gamestruct *game);
void initialize_sound(gamestruct *game);
void display_barry(sfRenderWindow *window, gamestruct *game);
void barry_cycle(gamestruct *game);
void barry_move(gamestruct *game);
void create_coinlist(gamestruct *game, int mode);
void fill_coinlist(gamestruct *game, char **map);
void coin_line(gamestruct *game, char *line, int *compt, int i);
void display_coin(gamestruct *game, sfRenderWindow *window);
void check_coin(gamestruct *game);
void coin_cycle(gamestruct *game, int flag);
void update_score(gamestruct *game);
void menu_display(sfRenderWindow *window, gamestruct *game);
void display_selection(sfRenderWindow *window, gamestruct *game);
void display_selection2(sfRenderWindow *window, gamestruct *game);
void display_selection3(sfRenderWindow *window, gamestruct *game);
void display_selection4(sfRenderWindow *window, gamestruct *game);
void display_button(sfRenderWindow *window, gamestruct *game);
void display_settings(sfRenderWindow *window, gamestruct *game);
void display_settings2(sfRenderWindow *window, gamestruct *game,
sfVector2f posvec, sfVector2f posvec2);
void display_pause(sfRenderWindow *window, gamestruct *game);
void display_end(sfRenderWindow *window, gamestruct *game);
void plane_move(gamestruct *game);
void check_window_size(sfRenderWindow *window);
sfIntRect create_rect(int width, int height, int state);
sfIntRect define_rect(char **map, int i, int j);
sfIntRect define_rect2(char **map, int i, int j, sfIntRect *rect);
sfIntRect define_rect3(char **map, int i, int j, sfIntRect *rect);
sfIntRect adjust_rect(sfIntRect (*fct)(int), int state);
sfIntRect background_rect(int state);
sfIntRect sky_rect(int state);
sfIntRect road_rect(int state);
sfIntRect mine_rect(int state);
sfIntRect barry_rect(int state);
sfIntRect coin_rect(int state);
sfIntRect title_rect(int state);
sfIntRect menubutton_rect(int state);
sfIntRect playbutton_rect(int state);
sfIntRect settingsbutton_rect(int state);
sfIntRect returnbutton_rect(int state);
sfIntRect settingsmenu_rect(int state);
sfIntRect musicbarre_rect(int state);
sfIntRect soundbarre_rect(int state);
sfIntRect cursor_rect(int state);
sfIntRect quitbutton_rect(int state);
sfIntRect pausebutton_rect(int state);
sfIntRect restartbutton_rect(int state);
sfIntRect spitfire_rect(int state);
sfVector2f find_spawn(char **map);
sfVector2f getvec(float x, float y);
char *scpy(char *dest, char *src);
char *creat_tab(int i);
char *my_itoa(int nb);
char *fill_line(char *mapline, int max_len, char *line);
char **scat_map(char **map, char **mod, int maxlen);
char *my_strcat(char *dest, char *from, int i);
void display_map(sfRenderWindow *window, char **map, gamestruct *game);
void display_road(sfRenderWindow *window, int i, int j, gamestruct *game);
char **create_map(char *path);
char **randmod(char **map, int len);
char **get_infinitemap();
char *get_score(int score, int flag);
char *alloc_res(int score, int flag);
float get_posx(char **map, gamestruct *game);
float get_posy(char **map, gamestruct *game);
float get_seconds(sfClock *clock);
textstruct create_text(void);
#endif
