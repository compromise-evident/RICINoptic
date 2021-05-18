/*Import this produced file as raw data using Audacity with settings:

  Encoding:  Unsigned 8-bit PCM
Byte order:  Little-endian
  Channels:  1 Channel (Mono)

Then export as mp3.   */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	out_stream.open("untitled.raw");
	/*Writes silence (~1 second.) Incidentally, this helps recognize noisy equipment upon decoding.
	Beginning silence ensures the program reads all data if the user plays & records in simultaneity. */
	for(int a = 0; a < 45000; a++) {out_stream.put(127);}
	
	/*Writes plenty of header-garbage '1' to initialize the LED and let it normalize in brightness (~1 second.)
	Unfortunately, the LED brightness must remain stable until it's finished blinking. This step provides many
	garbage items which can be skipped upon decoding due to uncontrollable brightness when the LED first comes
	on. Additionally, an opposite bit is appended to all bits then ignored upon decoding. Now LED brightness
	can remain the same. Zeros are "01" while ones are "10" meaning the stream is evenly distributed. */
	for(int a = 0; a < 2700; a++)
	{	out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait = 1
	}
	
	//Writes one header-garbage '0' to signify the beginning of the data.
	out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait
	out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait = 0
	
	//Number of bytes to produce (repeats this pattern n times, currently set to 1kB.)
	for(int n = 0; n < 1000; n++)
	{	out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait = 0
		
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait = 0
		
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait = 1
		
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait = 0
		
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait = 1
		
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait = 0
		
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait = 1
		
		out_stream.put(-1); for(int a = 0; a < 5; a++) {out_stream.put(127);} //Spike, short wait
		out_stream.put(-1); for(int a = 0; a < 9; a++) {out_stream.put(127);} //Spike, long  wait = 1
	}
	
	//Writes one '0' bit with an extra long wait at the end to signify end-of-stream.
	out_stream.put(-1); for(int a = 0; a <   9; a++) {out_stream.put(127);} //Spike, long  wait
	out_stream.put(-1); for(int a = 0; a < 100; a++) {out_stream.put(127);} //Spike, VERY LONG WAIT = end
	
	out_stream.close();
}
