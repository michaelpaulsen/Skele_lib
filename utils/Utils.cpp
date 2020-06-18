namespace Skele_lib {
	namespace Utils {
		bool GetKeyDown(int key) {//returns if the key 'key' is pressed 
			return GetAsyncKeyState(key) >> 15;
		}
		char intToChar(int x){ /// returns the LSD of the passed in int as a char
			return (x%10)+48;
		}
		char longToChar(long x){ /// returns the LSD of the passed in int as a char
			return (x%10)+48;
		}
	}
}