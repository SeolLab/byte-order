#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>
#include <arpa/inet.h>

/*
void dump(void* p, size_t n) {
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}


void write_4660() {
	uint16_t port = 4660; // 0x1234
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}

uint16_t my_ntohs(uint16_t a){
	uint16_t a1 = (a & 0xFF00) >> 8;
       	uint16_t a2 = (a & 0x00FF) << 8; 	
      	printf("a1 = 0x%x\n", a1); 	
	printf("a2 = 0x%x\n", a2);  
	a = a1 | a2;
	printf("a = 0x%x\n" , a);	
	return a;
}	


void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	// uint16_t n = *p; // TODO
	uint16_t n = my_ntohs(*p);  
	printf("16 bit number=0x%x\n", n);
}


uint32_t my_ntol(uint32_t a){
	uint32_t a1 = (a & 0xFF000000) >> 24; 
	uint32_t a2 = (a & 0x00FF0000) >> 8;
	uint32_t a3 = (a & 0x0000FF00) << 8;
	uint32_t a4 = (a & 0x000000FF) << 24; 

	return (a1 | a2 | a3 | a4); 

}

void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	// uint32_t n = *p; // TODO
	uint32_t n = my_ntohs(*p)
	printf("32 bit number=0x%x\n", n);
}
*/




uint32_t ReadFile(const char* File) {
	uint32_t num;
	FILE* file = fopen(File, "rb");  // read as binary file 
	if (file == NULL) { // exit program if fail to open file
		fprintf(stderr, "Error \n");
		exit(1);  
	}
	fread(&num, sizeof(num), 1, file); // data read from file
	fclose(file);					   // close the file 
	return ntohl(num);				   // network byte order -> host byte order 
}


int main(int argc, char* argv[]) {
	if (argc != 3) {      // exit the program if argc number is not 3
		printf("error \n");
		return -1;     
	}
	uint32_t num1 = ReadFile(argv[1]);
	uint32_t num2 = ReadFile(argv[2]);
	uint32_t sum = num1 + num2;

	printf("%u(0x%x)+%u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum); 
}

