#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

// length of linked list
int len(song_node *list) {
  int ans = 0;
  while (list) {
    ans++;
    list = list->next;
  }
  return ans;
}

void print_list(song_node *list) {
  if (list) {
    while(list) {
      printf("%s - %s ; ", list->artist, list->name);
      list = list->next;
    }
  }  
}

// takes input of song name+artist and adds song to linked list
// returns new head of list
song_node * insert_front(song_node *list, char *name, char *artist) {
  song_node *new = (song_node *)malloc(sizeof(song_node));
  (*new).next = list;
  strcpy((*new).name, name);
  strcpy((*new).artist, artist);
  return new;
}

// insert node in order (returns first node)
song_node * insert_order(song_node *list, char *name, char *artist) {

    int artistComp = strcmp(artist, list->artist);
    int nameComp = strcmp(name, list->name);


    //belongs in front of linked list
  if (list || artistComp < 0 || (artistComp == 0 && nameComp < 0))
    return insert_front(list,name,artist);

     

  // belongs in middle of linked list
  song_node *head = list;
  while (list->next) {
    int next_artistComp = strcmp(artist, (list->next)->artist);
  int next_nameComp = strcmp(name, (list->next)->name);
  printf("next_artistComp: %d\n", next_artistComp);
  printf("next_nameComp: %d\n", next_nameComp); 
    if (next_artistComp < 0 || (next_artistComp == 0 && next_nameComp < 0)) { 
      list->next = insert_front(list->next,name,artist);
      return head;
    }
    list = (*list).next;
  }

  // create song node and add to end
  song_node *new = (song_node *)malloc(sizeof(song_node));
  list->next = new;
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  return head;
}

song_node * find_song(song_node *list, char *name) {
  while (list) {
    if (!strcmp(name, list->name))
      return list;
    list=list->next;
  }
  return 0;
}

song_node * find_artist(song_node *list, char *artist) {
  while (list) {
    if (!strcmp(artist, list->artist))
      return list;
    list=list->next;
  }
  return 0;
}

song_node * find_random(song_node *list) {
  srand(time(NULL));
  int r = rand()%len(list);
  while (r--) {
    list = list->next;
  }
  return list;
}

song_node * remove_song(song_node *list, char *name, char *artist){
  // front
  if (!strcmp(name, list->name) && !strcmp(artist, list->artist)){
    song_node *nextSong = list->next;
    free(list);
    return nextSong;
  }

  // middle or end
  song_node *head = list; 
  while (list->next) {
    //if name and artist of next song match
    if (!strcmp(name, (list->next)->name) && !strcmp(artist, (list->next)->artist)) { 
      //remove next song and link curr and next next song
      song_node *nextSong = (list->next)->next;
      free(list->next);
      list->next = nextSong;
      return head;
    }
    list=list->next;
  }
}

song_node * free_list(song_node *list) {
  song_node *temp = list;
  while (list) {
    list = list->next;
    free(temp);
    temp = list;    
  }
  return list;
}




