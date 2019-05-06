# CSE 109 Serialization Lab

Jacob Oakman
jco222
05/06/2019
SECTION 011

## Requirements

You will write a conversation over a chat system between two people that follows the above 7-step protocol. Note that the conversation isn’t necessarily 7 statements long, as several of the stages can be multiple messages. This conversation should be at least 10 messages long.

Encode your conversation in a program and demonstrate that each message can be serialized and deserialized. 

Your program should be in the standard project structure we have been using:

* include - your serialize and deserialize functions
* src - where your main.cpp is. This is where you will write your conversation and serialize/deserialize it.
* Makefile – builds your program
* readme.md – your write up

In your readme, answer the following questions

* What is the length of the int message in bytes
* What is the length of the average serialized message in your conversation, in bytes
* Choose a single message in your conversation and compress it(by hand)using recursive byte pair encoding. Indicate the compression ratio (compressed bytes / original bytes)
* With the required decompression lookup table, is the compressed version a net gain?

## Writeup

The length of a serialized integer is 5 bytes, 1 for the type (1) and 4 for the actual integer (32 bits). The average length of the serialized messages in my conversation is 86.4 bytes.

### Compression

Message 1 as HEX:  
04 03 03 02 09 74 69 6D 65 73 74 61 6D 70 01 00 00 00 01 03 02 08 75 73 65 72 6E 61 6D 65 02 06 6A 63 6F 32 32 32 03 02 07 6D 65 73 73 61 67 65 02 02 48 69

Message 1 after first pass of byte pair encoding (Replace 03 02 with FF):  
03 02 FF 04 03 FF 09 74 69 6D 65 73 74 61 6D 70 01 00 00 00 01 FF 08 75 73 65 72 6E 61 6D 65 02 06 6A 63 6F 32 32 32 FF 07 6D 65 73 73 61 67 65 02 02 48 69

Message 1 after second pass of byte pair encoding (Replace 6D 65 with EF):  
6D 65 EF 03 02 FF 04 03 FF 09 74 69 EF 73 74 61 6D 70 01 00 00 00 01 FF 08 75 73 65 72 6E 61 EF 02 06 6A 63 6F 32 32 32 FF 07 EF 73 73 61 67 65 02 02 48 69

More passes would increse the size of the message.  

Final compression ratio = 1  
This is not a good method of compression unless there's a massive amount of repeated pairs. For this message there is no net gain.

## Build Instructions

### Build

```BASH
$> make
```

### Run

```BASH
$> ./build/bin/hashlab
```

### Clean

```BASH
$> make clean
```