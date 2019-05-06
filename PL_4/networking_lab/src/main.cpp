#include <vector>
#include <stdio.h>
#include "serialize.h"

using namespace std;

int main() {
  vector<unsigned char> output = serialize_int(0x134A7F01);
  for (int i=0; i < output.size(); i++) {
    printf("%X\n", output[i]);
  }
  int x = deserialize_int(output);
  
  return 0;
}

