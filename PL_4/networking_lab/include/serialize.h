#include <vector>
#include <string>

using namespace std;

unsigned char int_type = 1;
unsigned char str_type = 2;
unsigned char field_type = 3;
unsigned char msg_type = 4;


struct Message {
	int timestamp;
	string username;
	string message;
};

vector<unsigned char> serialize_int(int data) {
	vector<unsigned char> serialized;
	serialized.push_back(int_type);
	for (int i=0; i < 4; i++) {
		unsigned char shifted = (unsigned char)((data << (i * 8)) >> (3 * 8));
		serialized.push_back(shifted);
	}
	return serialized;
}

vector<unsigned char> serialize_str(string data) {
	vector<unsigned char> serialized;
	serialized.push_back(str_type);
	serialized.push_back((unsigned char) data.length);
	for (int i = 0; i < data.length; i++)
	{
		serialized.push_back((unsigned char) data.at(i));
	}

	return serialized;
}

vector<unsigned char> serialize_int_field(string name, int data) {
	vector<unsigned char> serialized;
	serialized.push_back(field_type);

	vector<unsigned char> name_vector = serialize_str(name);
	vector<unsigned char> data_vector = serialize_int(data);
	
	serialized.insert(serialized.end(), name_vector.begin(), name_vector.end());
	serialized.insert(serialized.end(), data_vector.begin(), data_vector.end());

	return serialized;
}

vector<unsigned char> serialize_str_field(string name, string data) {
	vector<unsigned char> serialized;
	serialized.push_back(field_type);
	
	vector<unsigned char> name_vector = serialize_str(name);
	vector<unsigned char> data_vector = serialize_str(data);
	
	serialized.insert(serialized.end(), name_vector.begin(), name_vector.end());
	serialized.insert(serialized.end(), data_vector.begin(), data_vector.end());

	return serialized;
}

vector<unsigned char> serialize_message(Message msg) {
	vector<unsigned char> serialized;
	//Type
	serialized.push_back(msg_type);

	//Number of fields
	serialized.push_back(3);

	//Fields
	vector<unsigned char> timestamp_serial = serialize_int_field("timestamp", msg.timestamp);
	vector<unsigned char> username_serial = serialize_str_field("username", msg.username);
	vector<unsigned char> message_serial = serialize_str_field("message", msg.message);

	//Combine all
	serialized.insert(serialized.end(), timestamp_serial.begin(), timestamp_serial.end());
	serialized.insert(serialized.end(), username_serial.begin(), username_serial.end());
	serialized.insert(serialized.end(), message_serial.begin(), message_serial.end());

	return serialized;
}

int deserialize_int(vector<unsigned char> data) {
	int deser = 0;
	for (int i = 1; i < data.size(); i++) {
		deser = ((int)data[i] << ((4 - i) * 8)) | deser;
	} 
	return deser;
}

string deserialize_string(vector<unsigned char> stream) {
	string deser = "";
	int size = stream[1];
	for (int i = 0; i < size; i++)
	{
		deser += stream[i + 2];
	}

	return deser;
}

Message deserialize_message(vector<unsigned char> stream)
{
	Message msg;

	string name;
	int int_value;
	string string_value;

	int counter = 1;

	vector<unsigned char> newVec(stream.begin() + counter, stream.end());

	name = deserialize_string();

	if (name == "timestamp")
	{
		msg.timestamp = int_value;
	}

	if (name == "username")
	{
		msg.username = string_value;
	}

	if (name == "message")
	{
		msg.message = string_value;
	}
}