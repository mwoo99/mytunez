#include <stdio.h>
#include <stdlib.h>
#include "library.h"

song_node *table[26];

int main() {
  srand(time(NULL));
  printf("Testing add_song:\n");
  add_song("cravings","vokes");
  add_song("illusory","ben hammersley");
  add_song("movements","pham");
  add_song("nikes","frank ocean");
  add_song("pink + white", "frank ocean");
  add_song("ivy","frank ocean");
  add_song("dirty Water", "marc E. Bassy");
  add_song("subway Car", "marc E. Bassy");
  printf("\n");
  
  printf("Testing print_library\n");
  print_library();
  printf("\n");

  printf("Testing print_letter\n");
  print_letter('f');
  print_letter('b');
  printf("\n");

  printf("Testing print_artist\n");
  print_artist("marc E. Bassy");
  print_artist("frank ocean");
  printf("\n");
  
  printf("Testing shuffle\n");
  shuffle(4);
  printf("\n");
  
  printf("Testing delete_song\n");
  delete_song("cravings","vokes");
  delete_song("ivy","frank ocean");
  delete_song("nikes","frank ocean");
  printf("\nPrinting Library:\n");
  print_library();
  printf("\n");
  
  printf("Testing delete_all\n");
  delete_all();
  print_library();

}