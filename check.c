#include <string.h>
#include <check.h>

char* alphabet = "abcdefghijklmnopqrstuvwxyz1234567890";

void printfailure() {
	settextcolor(12, 0);
	puts("\nAccess Denied!\n");
	settextcolor(0, 15);
}

void printsuccess() {
	settextcolor(13, 0);
	puts("\nAcces Granted!\n");
	settextcolor(0,15);
}

void check(char* input) {
	if(strlen(input) < 32) {
		printfailure();
		return;
	}

	if(input[0] != alphabet[26]) {
		printfailure();
		return;
	}


	if(input[1] != alphabet[0]) {
		printfailure();
		return;
	}


	if(input[2] != alphabet[12]) {
		printfailure();
		return;
	}

	if(input[3] != alphabet[12]) {
		printfailure();
		return;
	}

	if(input[4] != alphabet[12]) {
		printfailure();
		return;
	}

	if(input[5] != alphabet[10]) {
		printfailure();
		return;
	}

	if(input[6] != alphabet[0]) {
		printfailure();
		return;
	}

	if(input[7] != alphabet[13]) {
		printfailure();
		return;
	}

	if(input[8] != alphabet[3]) {
		printfailure();
		return;
	}

	if(input[9] != alphabet[24]) {
		printfailure();
		return;
	}

	if(input[10] != alphabet[35]) {
		printfailure();
		return;
	}

	if(input[11] != alphabet[20]) {
		printfailure();
		return;
	}

	if(input[12] != alphabet[0]) {
		printfailure();
		return;
	}

	if(input[13] != alphabet[17]) {
		printfailure();
		return;
	}

	if(input[14] != alphabet[4]) {
		printfailure();
		return;
	}

	if(input[15] != alphabet[26]) {
		printfailure();
		return;
	}

	if(input[16] != alphabet[12]) {
		printfailure();
		return;
	}

	if(input[17] != alphabet[12]) {
		printfailure();
		return;
	}

	if(input[18] != alphabet[15]) {
		printfailure();
		return;
	}

	if(input[19] != alphabet[17]) {
		printfailure();
		return;
	}

	if(input[20] != alphabet[4]) {
		printfailure();
		return;
	}

	if(input[21] != alphabet[18]) {
		printfailure();
		return;
	}

	if(input[22] != alphabet[18]) {
		printfailure();
		return;
	}

	if(input[23] != alphabet[18]) {
		printfailure();
		return;
	}

	if(input[24] != alphabet[18]) {
		printfailure();
		return;
	}

	if(input[25] != alphabet[26]) {
		printfailure();
		return;
	}

	if(input[26] != alphabet[26]) {
		printfailure();
		return;
	}

	if(input[27] != alphabet[21]) {
		printfailure();
		return;
	}

	if(input[28] != alphabet[21]) {
		printfailure();
		return;
	}

	if(input[29] != alphabet[4]) {
		printfailure();
		return;
	}

	if(input[30] != alphabet[4]) {
		printfailure();
		return;
	}

	if(input[31] != alphabet[4]) {
		printfailure();
		return;
	}

	printsuccess();	
}



