#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const char *INPUT = "01011110001";

int polynom_count = 2;

char *G[] = {
  "1",
  "11"
};

const char *G1 = "1"; // g1 = 1
const char *G2 = "11";// g2 = x + 1

int max_val(int a, int b) {
  if ( a > b ) return a;
    else
    return b;
}

void move_buffer(char *buffer){
  for ( int j = strlen(buffer); j > 0; j-- ) {
    buffer[j] = buffer[j-1];
  }
  buffer[0] = '0';
}

int main() {
  char *mem_buffer = NULL;
  int mem_buffer_length = 0;

  //Generate memory buffer
  mem_buffer_length = max_val(strlen(G1),strlen(G2));
  printf("Input: %s\n", INPUT);
  printf("Memory cells count reserved: %d\n", mem_buffer_length);
  mem_buffer = realloc(mem_buffer, (mem_buffer_length + 1) * sizeof(char));
  mem_buffer[mem_buffer_length] = '\0';
  for ( int i = 0; i < mem_buffer_length; i++ ) {
    mem_buffer[i] = '0';
  }

  //Main cycle
  for ( int i = 0; i < strlen(INPUT); i++ ) {
    move_buffer(mem_buffer);
    mem_buffer[0] = INPUT[i];
    for ( int g = 0; g < polynom_count; g++) {
      int b = 0;
      for ( int j = 0; j < strlen(G[g]); j++ ) {
        if (G[g][j] == '1') {
          b = b ^ (mem_buffer[j] - '0');
        }
      }
      printf("%d", b);
    }
    printf(" ");

  }
  printf("\n");

  return 0;
}
