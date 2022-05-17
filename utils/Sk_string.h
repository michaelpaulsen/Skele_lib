bool cp_contains(char* source, const char* comp, size_t max_bytes) {
	bool found; 
	for (size_t x = 0; x < max_bytes; x++) {
		found = true; 
		for (size_t y = 0; y < max_bytes; y++) {
			if (comp[y] == 0) {
				break; 
				// reached the end of the comp string 
			}
			if (comp[y] != source[x + y]) {
				found = false;
				break;
				//if the yth char of the string you are comparing to is not equial to the x+yth char of the source string then
				// set found to false and break [out of the inner loop]. 
			}
		}
		if (found) return true; // then if the whole of the inner loop is done and found is still set to true return true
	}
	return false; // if the function gets to this line then the outer loop would have completed witch means that it 
	//didn't find the string that it is comparing to
	
}
size_t cp_concat(char* source, char* drain, size_t max_bytes, size_t bytes = 0) {
	size_t written_bytes = bytes;
	while (drain[written_bytes] != 0) {
		written_bytes++; //get the last byte of the current dest
	}
	for (size_t x = 0; x < max_bytes; x++) {
		if (!source[x]) {
			drain[written_bytes] = 0;
			break;
		}
		drain[written_bytes++] = source[x];
	}
	return written_bytes;
}
size_t cp_concat(const char* source, char* drain, size_t max_bytes, size_t bytes = 0) {
	size_t written_bytes = bytes;
	while (drain[written_bytes] != 0) {
		written_bytes++; //get the last byte of the current dest
	}
	for (size_t x = 0; x < max_bytes; x++) {
		if (!source[x]) {
			drain[written_bytes] = 0;
			break;
		}
		drain[written_bytes++] = source[x];
	}
	return written_bytes;
}
