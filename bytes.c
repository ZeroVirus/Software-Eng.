void main() {

#pragma pack(1)

	struct packet {
		char version;
		uint16_t opcode;
		uint16_t length;
		char filename[512-5];
	};

	struct packet buf;
	buf.version=1;
	buf.opcode=htons(2);
	buf.length =htons(4);
	strcpy(&buf.filename,"ABC");

	/*
	char buf[512];
	char *bf = buf;
	*bp++ = 1;
	*bp++ = 0;
	buf[0]=1;
	*((uint16_t*)&buf[1])=htons(2);
	*((uitn16_t*)&buf[3])=htons(4);
	//(uint32_t*)&buf[5]="ABC";
	strcpy(buf+5,"ABCDE");
	*/
}
