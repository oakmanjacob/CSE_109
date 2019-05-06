#include <vector>
#include <stdio.h>
#include <iostream>
#include "serialize.h"

using namespace std;

vector<Message> message_list;

/**
 * Print a vector of unsigned characters as hex
 * Not actually used in final program
 */
void printVector(vector<unsigned char> data)
{
	for (int i = 0; i < data.size(); i++) {
		printf("%X ", data[i]);
	}
	printf("\n");
}

/**
 * Serialize, deserialize and then print a series of 10 faux messages
 */
int main() {
	cout <<
		"======================================================================================================" << endl << endl <<
		"  ██████ ▓█████  ██▀███   ██▓ ▄▄▄       ██▓     ██▓▒███████▒ ▄▄▄     ▄▄▄█████▓ ██▓ ▒█████   ███▄    █ " << endl <<
		"▒██    ▒ ▓█   ▀ ▓██ ▒ ██▒▓██▒▒████▄    ▓██▒    ▓██▒▒ ▒ ▒ ▄▀░▒████▄   ▓  ██▒ ▓▒▓██▒▒██▒  ██▒ ██ ▀█   █ " << endl <<
		"░ ▓██▄   ▒███   ▓██ ░▄█ ▒▒██▒▒██  ▀█▄  ▒██░    ▒██▒░ ▒ ▄▀▒░ ▒██  ▀█▄ ▒ ▓██░ ▒░▒██▒▒██░  ██▒▓██  ▀█ ██▒" << endl <<
		"  ▒   ██▒▒▓█  ▄ ▒██▀▀█▄  ░██░░██▄▄▄▄██ ▒██░    ░██░  ▄▀▒   ░░██▄▄▄▄██░ ▓██▓ ░ ░██░▒██   ██░▓██▒  ▐▌██▒" << endl <<
		"▒██████▒▒░▒████▒░██▓ ▒██▒░██░ ▓█   ▓██▒░██████▒░██░▒███████▒ ▓█   ▓██▒ ▒██▒ ░ ░██░░ ████▓▒░▒██░   ▓██░" << endl <<
		"▒ ▒▓▒ ▒ ░░░ ▒░ ░░ ▒▓ ░▒▓░░▓   ▒▒   ▓▒█░░ ▒░▓  ░░▓  ░▒▒ ▓░▒░▒ ▒▒   ▓▒█░ ▒ ░░   ░▓  ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ " << endl <<
		"░ ░▒  ░ ░ ░ ░  ░  ░▒ ░ ▒░ ▒ ░  ▒   ▒▒ ░░ ░ ▒  ░ ▒ ░░░▒ ▒ ░ ▒  ▒   ▒▒ ░   ░     ▒ ░  ░ ▒ ▒░ ░ ░░   ░ ▒░" << endl <<
		"░  ░  ░     ░     ░░   ░  ▒ ░  ░   ▒     ░ ░    ▒ ░░ ░ ░ ░ ░  ░   ▒    ░       ▒ ░░ ░ ░ ▒     ░   ░ ░ " << endl <<
		"      ░     ░  ░   ░      ░        ░  ░    ░  ░ ░    ░ ░          ░  ░         ░      ░ ░           ░ " << endl << endl <<
		"======================================================================================================" << endl << endl;

	message_list.push_back(Message({
		timestamp: 1,
		username: "jco222",
		message: "Hi"
	}));

	message_list.push_back(Message({
		timestamp: 2,
		username: "bcz222",
		message: "What's up?"
	}));

	message_list.push_back(Message({
		timestamp: 3,
		username: "jco222",
		message: "Have you finished the 109 Lab yet?"
	}));

	message_list.push_back(Message({
		timestamp: 4,
		username: "bcz222",
		message: "Nah, I've been slammed with this databases project."
	}));

	message_list.push_back(Message({
		timestamp: 5,
		username: "jco222",
		message: "Ah ok, I'm trying to figure out what I should write for the messages."
	}));

	message_list.push_back(Message({
		timestamp: 6,
		username: "bcz222",
		message: "I'm gonna head to Rath to get dinner soon. Do you wanna join?"
	}));

	message_list.push_back(Message({
		timestamp: 7,
		username: "jco222",
		message: "Yeah, I've had serialization on the brain for too long. I could use a byte to eat."
	}));

	message_list.push_back(Message({
		timestamp: 8,
		username: "bcz222",
		message: "...I hate you"
	}));

	message_list.push_back(Message({
		timestamp: 9,
		username: "jco222",
		message: "See you in a bit."
	}));

	message_list.push_back(Message({
		timestamp: 10,
		username: "bcz222",
		message: "Alright talk to you then."
	}));

	vector<unsigned char> output;
	Message deserialized;
	float average = 0;

	for (int i = 0; i < message_list.size(); i++)
	{
		output = serialize_message(message_list[i]);
		average = ((i * average) + output.size()) / (i + 1);
		deserialized = deserialize_message(output);
		printf("timestamp: %i,\nusername: \"%s\",\nmessage: \"%s\"\n\n",
			deserialized.timestamp, deserialized.username.c_str(), deserialized.message.c_str());
	}

	printf("Average message length: %f Bytes\n ", average);
	return 0;
}

