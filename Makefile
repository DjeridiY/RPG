##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SOURCE	=	src/

OBJECT	=	src/object/

DESTROY	=	src/destroy/

EVENT	=	src/event/

UTILS	=	src/utils/

DRAW	=	src/draw/

UPDATE	=	src/update/

SRC	=	$(OBJECT)create.c	\
		$(OBJECT)malloc_object.c	\
		$(OBJECT)back/back_object.c	\
		$(OBJECT)window/create_window.c	\
		$(OBJECT)drop/drop.c	\
		$(OBJECT)drop/option.c	\
		$(OBJECT)drop/set_droptext.c	\
		$(OBJECT)drop/set_optiontext.c	\
		$(OBJECT)drop/highlight_drop.c	\
		$(OBJECT)button/button.c	\
		$(OBJECT)button/button_text.c	\
		$(OBJECT)button/highlight_button.c	\
		$(OBJECT)menu_interface/menu_interface.c	\
		$(OBJECT)music/music_object.c	\
		$(OBJECT)cursor/cursor.c	\
		$(OBJECT)game_print.c	\
		$(OBJECT)item/item_object.c	\
		$(OBJECT)stat/stat_object.c	\
		$(OBJECT)stat/get_printable_stat.c	\
		$(OBJECT)text/text_object.c	\
		$(OBJECT)text/text_create.c	\
		$(OBJECT)image/image_object.c	\
		$(OBJECT)rectangle/rectangle_object.c	\
		$(OBJECT)entity/entity_object.c	\
		$(OBJECT)view/view_object.c	\
		$(OBJECT)map/map_object.c	\
		$(OBJECT)map/str_to_word_array.c	\
		$(OBJECT)map/map_sprite.c	\
		$(OBJECT)map/map_tiles.c	\
		$(OBJECT)map/structure_map_utils.c	\
		$(OBJECT)map/structure_map.c	\
		$(OBJECT)map/structure_map_utils_more.c	\
		$(OBJECT)effect/effect_object.c	\
		$(OBJECT)back/adapt_to_window.c	\
		$(OBJECT)sound_effect/sound_effect_object.c	\
		$(DRAW)draw.c	\
		$(DRAW)draw_back.c	\
		$(DRAW)draw_drop.c	\
		$(DRAW)draw_button.c	\
		$(DRAW)visual_effect.c	\
		$(DRAW)draw_cursor.c	\
		$(DRAW)draw_item.c	\
		$(DRAW)draw_text.c	\
		$(DRAW)draw_stat.c	\
		$(DRAW)draw_image.c	\
		$(DRAW)draw_rectangle.c	\
		$(DRAW)draw_entire_text.c	\
		$(DRAW)draw_entity.c	\
		$(DRAW)draw_map.c	\
		$(DRAW)draw_game.c	\
		$(DESTROY)destroy.c	\
		$(DESTROY)destroy_back.c	\
		$(DESTROY)destroy_drop.c	\
		$(DESTROY)destroy_music.c	\
		$(DESTROY)destroy_button.c	\
		$(DESTROY)destroy_cursor.c	\
		$(DESTROY)destroy_item.c	\
		$(DESTROY)destroy_stat.c	\
		$(DESTROY)destroy_text.c	\
		$(DESTROY)destroy_image.c	\
		$(DESTROY)destroy_rectangle.c	\
		$(DESTROY)destroy_entire_text.c	\
		$(DESTROY)destroy_entity.c	\
		$(DESTROY)destroy_effect.c	\
		$(DESTROY)destroy_sound.c	\
		$(EVENT)event_handler.c	\
		$(EVENT)window/close_window.c	\
		$(EVENT)menu/menu.c	\
		$(EVENT)menu/open_menu.c	\
		$(EVENT)menu/game_menu.c	\
		$(EVENT)menu/change_window_size.c	\
		$(EVENT)menu/change_window_mode.c	\
		$(EVENT)menu/draw_menu.c	\
		$(EVENT)click/drop_clicked.c	\
		$(EVENT)click/mouse_clicked.c	\
		$(EVENT)click/option_clicked.c	\
		$(EVENT)click/button_clicked.c	\
		$(EVENT)click/attack_item.c	\
		$(EVENT)click/collect_item.c	\
		$(EVENT)hovered/mouse_hovered.c	\
		$(EVENT)hovered/option_hovered.c	\
		$(EVENT)hovered/button_hovered.c	\
		$(EVENT)menu_event_handler.c	\
		$(EVENT)menu/menu_setting.c	\
		$(EVENT)drag/drag.c	\
		$(EVENT)drag/drag_cursor.c	\
		$(EVENT)menu/play_and_stop_music.c	\
		$(EVENT)click/item_clicked.c	\
		$(EVENT)click/defensive_item.c	\
		$(EVENT)colision/colision.c	\
		$(EVENT)entity/detection_range.c	\
		$(EVENT)entity/chase_player.c	\
		$(EVENT)attack/attack.c	\
		$(UTILS)get_vector.c	\
		$(UTILS)get_color.c	\
		$(UPDATE)update.c	\
		$(UPDATE)update_stat.c	\
		$(UPDATE)move_entity.c	\
		$(UPDATE)get_time.c	\
		$(UPDATE)update_setting.c	\
		$(UPDATE)update_cursor.c	\
		$(UPDATE)update_button.c	\
		$(UPDATE)update_drop/up_option.c	\
		$(UPDATE)update_drop/up_set_droptext.c	\
		$(UPDATE)update_drop/up_set_optiontext.c	\
		$(UPDATE)update_drop/update_drop.c	\
		$(UPDATE)update_camera.c	\
		$(UPDATE)anime_player.c	\
		$(UPDATE)update_hitbox.c	\
		$(UPDATE)update_colide.c	\
		$(UPDATE)update_effect_player.c		\
		$(UPDATE)update_effect_entity.c		\
		$(UPDATE)entity_comp.c	\
		$(UPDATE)adapt_item.c	\
		$(UPDATE)entity_die.c	\
		$(UPDATE)room_tp.c	\
		$(UPDATE)room_tp_next.c	\
		$(UPDATE)spawn_entities.c	\
		$(UPDATE)spawn_entities_utils.c	\
		$(SOURCE)main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-I./include/ -lcsfml-graphics -lcsfml-window -g3 -lm -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lcsfml-system -L lib/my -lmy -Wall -Wextra
clean :
	make -C lib/my/ clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/my/ fclean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
