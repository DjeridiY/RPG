/*
** EPITECH PROJECT, 2022
** Paint
** File description:
** paint.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include "list.h"

#ifndef RPG_H_
    #define RPG_H_

typedef struct text {

    sfText *title;
    sfFont *font;
    sfColor color;
    sfVector2f pos;
    sfFloatRect text_rect;
    float size;
    bool visible;

} text_t;

typedef struct cursor {

    sfRectangleShape *box;
    sfRectangleShape *line;
    sfColor color;
    sfVector2f start;
    sfVector2f end;
    sfVector2f box_size;
    text_t *text;
    char *name;
    float value;
    float radius;
    bool visible;

} cursor_t;

typedef struct button {

    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    text_t *text;
    char *name;
    bool pressed;
    bool hovered;
    bool clicked;
    bool visible;

} button_t;

typedef struct music {

    sfMusic *music;
    char *music_name;
    bool play;
    int volume;

} music_t;

typedef struct drop {

    button_t **option;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    text_t *text;
    char *name;
    bool pressed;
    bool hovered;
    bool clicked;
    bool visible;

} drop_t;

typedef struct back {

    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    char *name;
    bool visible;

} back_t;

typedef struct item {

    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfVector2f pos;
    char *utility;
    int lvl;
    int damage;
    int speed;
    char *name;
    bool equiped;
    bool visible;
    bool used;

} item_t;

typedef struct image {

    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    char *name;
    bool visible;

} image_t;

typedef struct rectangle {

    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    bool visibility;
    char *name;

} rectangle_t;

typedef struct stat {

    text_t **print_stat;
    char *name;
    item_t *weapon;
    item_t *utility;
    int lvl;
    int hp;
    int max_hp;
    int strength;
    int speed;
    int defense;
    int raw_strength;
    int raw_speed;
    int raw_defense;
    int xp;

} stat_t;

typedef struct entity_effect {

    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    float time_effect;
    float fps;
    int max_frames;
    sfIntRect textures;
    bool show;

} entity_effect_t;

typedef struct entity {

    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    stat_t *stat;
    sfVector2f texture_pos;
    entity_effect_t *entity_effect;
    sfIntRect *textures;
    float time_pressing;
    int status;
    bool visible;
    bool teleported;

} entity_t;

typedef struct clock_rpg {

    sfClock *clock;
    sfTime time;
    float secondes;
    double time_pressed;
    long unsigned int time_elapsed;

} clock_rpg_t;

typedef struct tile {

    sfVector2f position;
    sfSprite *sprite_tile;
    bool colision;
    bool render;
    int nb_texture;

} tile_t;

typedef struct view_world {

    sfView *camera;
    sfVector2f zoom;

} view_world_t;

typedef struct structure {

    int **tile_placement;
    tile_t **map_tiles;
    sfTexture *map_tileset;

} structure_t;

typedef struct map {

    const int *order;
    list_t *structures;
    sfVector2f scale;
    sfIntRect *textures;
    int **tile_placement;
    tile_t **map_tiles;
    sfTexture *map_tileset;

} map_t;

typedef struct effect {

    sfIntRect textures;
    sfTexture *effect_tileset;
    int max_frames;

} effect_t;

typedef struct sound_effect {

    sfMusic *sound;
    char *sound_name;
    int volume;

} sound_effect_t;

typedef struct rpg {

    sfRenderWindow *window;
    back_t **back;
    drop_t **drop;
    button_t **button;
    music_t **music;
    cursor_t **cursor;
    item_t **item;
    stat_t **stat;
    image_t **image;
    rectangle_t **rect;
    text_t **text;
    entity_t **entity;
    clock_rpg_t *clock;
    view_world_t *view;
    effect_t **effect;
    sound_effect_t **sound;
    map_t *map;
    bool fullscreen;
    bool *rooms;
    int current_room;
    int exit_code;

} rpg_t;

int create(rpg_t *game);
sfRenderWindow *create_window(char *name, int size_x, int size_y);
void malloc_object(rpg_t *game);
void back_object(back_t **back);
void dropdown_object(drop_t **drop);
button_t *create_option(int rank);
void set_droptext(drop_t *drop, int i);
void set_optiontext(button_t *button, int rank);
void highlight_drop(drop_t **drop);
void highlight_bouton(button_t **button);
void button_object(button_t **button);
void set_text(button_t *button, int i);
void menu_interface(rpg_t *game);
void create_music(music_t **music);
void cursor_object(cursor_t **cursor);
void game_print(rpg_t *game);
void item_object(item_t **item);
void stat_object(stat_t **stat, item_t **item);
text_t *create_text(bool visibilty, int size,
sfVector2f position, sfColor color);
void image_object(image_t **image);
void rectangle_object(rectangle_t **rect);
void text_object(text_t **text);
void entity_object(entity_t **entity, stat_t **stat, effect_t **effect);
void view_object(view_world_t *view, rpg_t *game);
void map_object(map_t *map, rpg_t *game);
char **str_to_word_array(char *str, const char *separator);
void effect_object(effect_t **effect);
entity_t *create_entity(int i, stat_t *stat, effect_t **effect);
stat_t *create_stat(int i, item_t **item);

int destroy(rpg_t *game);
void destroy_back(back_t **back);
void destroy_drop(drop_t **drop);
void destroy_music(music_t **music);
void destroy_button(button_t **button);
void destroy_cursor(cursor_t **cursor);
void destroy_item(item_t **item);
void destroy_stat(stat_t **stat);
void destroy_text(text_t *text);
void destroy_image(image_t **image);
void destroy_rectangle(rectangle_t **rect);
void destroy_entire_text(text_t **text);
void destroy_entity(entity_t **entity);
void destroy_effect(effect_t **effect);

int event_handler(rpg_t *game);
void close_window(sfEvent event, rpg_t *game);
int menu(sfEvent event, rpg_t *game);
void open_menu(rpg_t *game, sfEvent event);
void drop_clicked(drop_t **drop, sfVector2f mouse_pos);
void mouse_release(rpg_t *game, sfEvent event);
void option_clicked(drop_t **drop, sfVector2f mouse_pos, rpg_t *game);
void mouse_moved(rpg_t *game, sfEvent event);
void option_hovered(drop_t **drop, sfVector2f mouse_pos);
void change_window_size(drop_t **drop, sfRenderWindow *window, rpg_t *game);
void change_window_mode(drop_t **drop, sfRenderWindow *window, rpg_t *game);
void button_clicked(button_t **button, sfVector2f mouse_pos);
void button_hovered(button_t **button, sfVector2f mouse_pos);
int menu_event_handler(rpg_t *game);
void menu_setting(music_t **music, rpg_t *game);
void drag_cursor(cursor_t **cursor, sfVector2f mouse_pos);
void drag(rpg_t *game, sfEvent event);
void game_setting_management(music_t **music, rpg_t *game);
void play_and_stop_music(music_t **music);
void draw_setting(rpg_t *game);
void item_click(item_t **item, sfVector2f mouse_pos,
entity_t *player, rpg_t *game);
void defensive_item(item_t *item, entity_t *player,
item_t *nothing, rpg_t *game);
float get_wall_pos(rpg_t *game, float speed, int movement, int i);
void attack_item(item_t *item, entity_t *player, item_t *nothing);

sfVector2f get_vector(float x, float y);
sfColor get_color(int red, int green, int blue, int alpha);

void draw_back(back_t **back, sfRenderWindow *window);
void draw(rpg_t *game);
void draw_drop(drop_t **drop, sfRenderWindow *window, rpg_t *game);
void draw_button(button_t **button, sfRenderWindow *window);
void visual_effect(rpg_t *game);
void draw_cursor(cursor_t **cursor, sfRenderWindow *window);
void draw_item(item_t **item, sfRenderWindow *window);
void draw_text(text_t *text, sfRenderWindow *window);
void draw_stat(stat_t **stat, sfRenderWindow *window);
void draw_image(image_t **image, sfRenderWindow *window);
void draw_rectangle(rectangle_t **rect, sfRenderWindow *window);
void draw_entire_text(text_t **text, sfRenderWindow *window);
void draw_entity(entity_t **entity, sfRenderWindow *window);
void game_draw(rpg_t *game);

void update(rpg_t *game);
void update_stat(stat_t **stat, rpg_t *game);
void move_entity(rpg_t *game);
void get_time(clock_rpg_t *clock);
void update_setting(rpg_t *game);
void update_cursor(cursor_t *cursor);
void update_button(button_t *button, int i);
void entity_hitbox(rpg_t *game);
bool collide(entity_t *entity1, entity_t *entity2, rpg_t *game);
float colision_player_wall(rpg_t *game, float speed,
    sfVector2f wall, sfVector2f player);
void effect_player(entity_t *entity, rpg_t *game);
void effect_entity(entity_t *entity, rpg_t *game);

void update_dropdown(drop_t **drop);
void up_set_optiontext(button_t *button, int rank);
void up_set_optiontext_position(button_t *button, text_t *text);
void up_set_droptext(drop_t *drop, int i);
void up_set_droptext_position(drop_t *drop, text_t *text);
void update_option(int rank, button_t *option);
void up_set_option(button_t *option);
void draw_menu(rpg_t *game);
void draw_map(map_t *map, sfRenderWindow *window,
sfVector2f position, int radius);
void update_camera(rpg_t *game);

bool detection_range(sfSprite *player, sfSprite *entity, float range);
void chase_player(entity_t *entity, entity_t *player, rpg_t *game, int i);
void anime_sprite(entity_t *player, rpg_t *game, int i);
void make_map_sprites(map_t *map);
void make_tiles(int ***tile_placement, char *file_str, char *map_info);
char *get_map_info(char *str);

void attack(rpg_t *game, sfEvent event);
void entity_comp(rpg_t *game);
void adapt_back_to_screen(rpg_t *game);
void adapt_item(item_t **item);
void entity_die(entity_t **entity);
text_t **get_printable_stat(int i, stat_t *stat);
void sound_effect_object(sound_effect_t **sound);
void destroy_sound(sound_effect_t **sound);
void collect_item(entity_t *player, item_t *item);
int **get_data_at_index(list_t *liste, int index);
void change_room(entity_t *entity, rpg_t *game);
void spawn_entities(rpg_t *game);
sfVector2f vector_spawn(int **tab, int nb, int len);
int nbr_of_int_tab(int **tab, int nb);
int len_liste(list_t *liste);
bool is_structure_empty(int **structure, int width, int height);
void add_to_list(list_t **liste, void *data);
int **malloc_structure(int x, int y);
bool is_valid(sfVector2f pos, int width, int height);
void make_tiles_structure(map_t *map, rpg_t *game,
    list_t *structure, int size);
list_t *make_structure(map_t *map, rpg_t *game);
int **get_structure(map_t *map, sfVector2f coord,
    int **structure, sfVector2f pos);
sfVector2f tp_next(entity_t *entity, rpg_t *game);
sfVector2f tp_prev(entity_t *entity, rpg_t *game);

#endif /* RPG_H_ */
