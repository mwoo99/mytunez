#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

song_node *table[26];

void add_song(char *name, char *artist){
  table[artist[0]-'a'] = insert_front(table[artist[0]-'a'], name, artist);
  printf("Added Song: %s - %s \n", artist, name);
}

song_node *search_song(char *name, char* artist){
  song_node *letterHead = table[artist[0] - 'a'];
  song_node *song = find_song(letterHead, name);
  return song; //would be 0 if not found
}

song_node *search_artist(char* artist) {
  song_node *letterHead = table[artist[0] - 'a'];
  song_node *song = find_artist(letterHead, artist);
  return song; // 0 if not found
}

// Print out all the entries under a certain letter.
void print_letter(char c) {
  song_node *letterHead = table[c - 'a'];
  printf("Printing songs under %c: \n", c);
  print_list(letterHead);
  printf("\n");
}

//Print out all the songs of a certain artist
void print_artist(char *artist){
  printf("Looking for *%s*\n:", artist);
  song_node *song = search_artist(artist);
  if(song){
   while (song) {
      if (strcmp(artist, song->artist) == 0) printf("%s - %s \n", song->artist, song->name);
      song = song->next;
    }
  }
  else
    printf("No songs\n");
}

// Print out the entire library.
void print_library(){
  int i = 0;
  while (i<26){
    if(table[i]) print_letter('a' + i);
    i++;
  }
}


void shuffle(int n) {
  srand(time(NULL));
  printf("Shuffled Playlist:\n"); 
  while (n--){
    int randLetter = rand()%26;
    while(!table[randLetter]) randLetter = rand()%26;
    song_node *randomSong = find_random(table[randLetter]);
    printf("%s - %s\n",randomSong->artist, randomSong->name);
  }
}

void delete_song(char *name, char *artist){
  table[artist[0]-'a'] = remove_song(table[artist[0]-'a'], name, artist);
  printf("Removed Song: %s - %s \n", artist, name);
}

void delete_all() {
  int i = 0;
  for (; i < 26; i++)
    table[i] = free_list(table[i]);
  printf("Emptied Playlist.\n");
}
