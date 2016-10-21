#ifndef libraryHeader
#define libraryHeader
#include "linked_list.h"

void add_song(char *name, char *artist);
song_node *search_song(char *name, char* artist);
song_node *search_artist(char* artist);
void print_letter(char c);
void print_artist(char *artist);
void print_library();
void shuffle(int i);
void delete_song(char *name, char *artist);
void delete_all();

#endif