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

/**
 * Serialize int as [type][data]
 */
vector<unsigned char> serialize_int(int data) {
	vector<unsigned char> serialized;
	serialized.push_back(int_type);
	for (int i = 0; i < 4; i++) {
		unsigned char shifted = (unsigned char)((data << (i * 8)) >> (3 * 8));
		serialized.push_back(shifted);
	}
	return serialized;
}

/**
 * Serialize string as [type][length][c1][c2]...[cn]
 */
vector<unsigned char> serialize_str(string data) {
	vector<unsigned char> serialized;
	serialized.push_back(str_type);
	serialized.push_back((unsigned char) data.size());
	for (int i = 0; i < data.size(); i++)
	{
		serialized.push_back((unsigned char) data.at(i));
	}

	return serialized;
}

/**
 * Serialize field as [type][name][data]
 * Where name is a serialized as a string and data is a serialized as an int
 */
vector<unsigned char> serialize_int_field(string name, int data) {
	vector<unsigned char> serialized;
	serialized.push_back(field_type);

	vector<unsigned char> name_vector = serialize_str(name);
	vector<unsigned char> data_vector = serialize_int(data);
	
	serialized.insert(serialized.end(), name_vector.begin(), name_vector.end());
	serialized.insert(serialized.end(), data_vector.begin(), data_vector.end());

	return serialized;
}

/**
 * Serialize field as [type][name][data]
 * Where name and data are serialized as strings
 */
vector<unsigned char> serialize_str_field(string name, string data) {
	vector<unsigned char> serialized;
	serialized.push_back(field_type);
	
	vector<unsigned char> name_vector = serialize_str(name);
	vector<unsigned char> data_vector = serialize_str(data);
	
	serialized.insert(serialized.end(), name_vector.begin(), name_vector.end());
	serialized.insert(serialized.end(), data_vector.begin(), data_vector.end());

	return serialized;
}

/**
 * Serialize message as [type][number of fields][timestamp][username][message]
 * where timestamp is serialized as an integer field and
 * username and message are serialized as string fields.
 */
vector<unsigned char> serialize_message(Message msg) {
	vector<unsigned char> serialized;
	//Type
	serialized.push_back(msg_type);

	//Number of fields
	serialized.push_back((unsigned char) 3);

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

/**
 * Deserialize an integer
 */
int deserialize_int(vector<unsigned char> stream) {
	if (stream[0] != int_type)
	{
		printf("ERROR: Tried to read non int type as int\n");
		exit(0);
	}

	int deser = 0;
	for (int i = 1; i < 5; i++) {
		deser = ((int)stream[i] << ((4 - i) * 8)) | deser;
	} 
	return deser;
}

/**
 * Deserialize a string
 */
string deserialize_string(vector<unsigned char> stream) {
	if (stream[0] != str_type)
	{
		printf("ERROR: Tried to read non string type as string\n");
		exit(0);
	}

	string deser = "";
	int size = stream[1];
	for (int i = 0; i < size; i++)
	{
		deser += stream[i + 2];
	}
 
	return deser;
}

/**
 * Deserialize a message
 */
Message deserialize_message(vector<unsigned char> stream)
{
	Message msg = Message();
	if (stream[0] != msg_type)
	{
		printf("ERROR: Tried to read non message type as message\n");
		exit(0);
	}

	string name;
	int int_value;
	string string_value;

	int counter = 1;
	int field_count = stream[counter];
	counter++;

	//Read through the fields
	for (int i = 0; i < field_count; i++)
	{
		if (stream[counter] != field_type)
		{
			printf("ERROR: Tried to read non field type as field\n");
			exit(0);
		}
		counter++;

		vector<unsigned char> sub(stream.begin() + counter, stream.end());

		name = deserialize_string(sub);
		counter += 2 + name.size();
		
		if (name == "timestamp")
		{
			vector<unsigned char> sub(stream.begin() + counter, stream.end());
			msg.timestamp = deserialize_int(sub);
			counter += 5;
		}
		else if (name == "username")
		{
			vector<unsigned char> sub(stream.begin() + counter, stream.end());
			string_value = deserialize_string(sub);
			counter += 2 + string_value.size();
			msg.username = string_value;
		}
		else if (name == "message")
		{
			vector<unsigned char> sub(stream.begin() + counter, stream.end());
			string_value = deserialize_string(sub);
			counter += 2 + string_value.size();
			msg.message = string_value;
		}
		else
		{
			//Something's very wrong
			printf("ERROR: unknown field type\n");
			exit(0);
		}
		
	}

	return msg;
}