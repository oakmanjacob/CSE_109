# Bitwise Operators

* Left Shift: <<
* Right Shift: >>
* And: &
* Or: |
* Exclusive Or (XOR): ^

```CPP
// Shift the bit over 4 spots
1 << 4
//Evaluates to "10000"(BINARY) "16" (DEC)

1 << 33
//If 32 bit, Shifts the bit off the end of the number
//Evaluates to zero

//If the int is 64 bit this will evaluate to
//2^33

11 << 4
//[1011]0000 ===> 208

96 >> 3
//1100000 -> 1100 ==> 12

102 >> 3
//1100110 -> 1100 ==> 12
//We lose digits when we shift right
//This appears to be similar to division with rounding down

//-------------AND OR XOR--------------//
  11011010 // ==> 218
& 10010100 // ==> 148
= 10010000 // ==> 144

  11011010 // ==> 218
| 10010100 // ==> 148
= 11011110 // ==> 222

  11011010 // ==> 218
^ 10010100 // ==> 148
= 01001110 // ==> 78
```

# Protocol
* Header ( 4 BITS --> 16 types )
	1. int
	2. str
	3. field
	4. struct
* Data
	1. INT 
```CPP
// Send the int 13 which is 1101 BIN
// Sends [0001][0...01101]

data = 13;
int_header = 1;
str_header = 2;
field_header = 3;
struct_header = 4;

(int_header << 32) | data
// gives 00010...0 <-- 32 zeros
// then OR with 13 to get 00010...01101
```