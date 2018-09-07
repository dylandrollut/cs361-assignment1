#include <stdio.h>
#include <stdlib.h>

void shiftEncrypt(char *message){

	int i;
	char ch;

	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + 3;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + 3;

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}

			message[i] = ch;
		}
	}
    
    printf("Encrypted message: %s\n", message);
}

void shiftDecrypt(char *message){

	int i;
	char ch;

	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - 3;

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - 3;

			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}

			message[i] = ch;
		}
	}
    
    printf("Decrypted message: %s\n", message);
}

void subEncrypt(char *message){

	int i;
	int chVal;
	char ch;
	char *upperCipher = "OYDCTPWLNXVHUIAFZSREMKGJBQ";
	char *lowerCipher = "oydctpwlnxvhuiafzsremkgjbq";

	for(i = 0; message[i] != '\0'; i++){
		ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			chVal = ch - 'a';

			ch = lowerCipher[chVal];
			message[i] = ch;

		} else if(ch >= 'A' && ch <= 'Z'){
			chVal = ch - 'A';

			ch = upperCipher[chVal];
			message[i] = ch;
		}
		
	}

	printf("Encrypted message: %s\n", message);

}

void subDecrypt(char *message){
	int i;
        int chVal;
        char ch;
        char *upperCipher = "OYDCTPWLNXVHUIAFZSREMKGJBQ";
        char *lowerCipher = "oydctpwlnxvhuiafzsremkgjbq";

        for(i = 0; message[i] != '\0'; i++){
                ch = message[i];

                if(ch >= 'a' && ch <= 'z'){
                        chVal = ch - 'a';

                        ch = lowerCipher[chVal];
                        message[i] = ch;

                } else if(ch >= 'A' && ch <= 'Z'){
                        chVal = ch - 'A';

                        ch = upperCipher[chVal];
                        message[i] = ch;
                }

        }

        printf("Decrypted message: %s\n", message);
}

int main(){

	printf("Enter the message you would like to encrypt/decrypt:\n");

	char *line = NULL;
	size_t size;

	if(getline(&line, &size, stdin) == -1){
		printf("No line entered. \n");
	} else {
		int i = 0;
		while(line[i] != '\n'){
			i++;
		}
		line[i] = '\0';
	}
	
	int encryptOrDecrypt;
	printf("Enter 1 for Encrypt or 2 for Decrypt: ");
	scanf("%d", &encryptOrDecrypt);
	
	if(encryptOrDecrypt != 1 && encryptOrDecrypt != 2){
		printf("Invalid option\n");
		return -1;
	}

	int shiftOrSub;
	printf("Enter 1 for Shift or 2 for Substitution: ");
	scanf("%d", &shiftOrSub);

	if(shiftOrSub != 1 && shiftOrSub != 2){
		printf("Invalid option\n");
		return -1;
	}

	if(encryptOrDecrypt == 1){

		if(shiftOrSub == 1){
			shiftEncrypt(line);
		} else{
			subEncrypt(line);
		}

	} else {

		if(shiftOrSub == 1){
			shiftDecrypt(line);
		} else {
			subDecrypt(line);
		}

	}
}
