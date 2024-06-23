#include <stdio.h>
#include <stdlib.h>

typedef struct Packet {
	unsigned long packetId;
	unsigned short numberOfPacket;
	unsigned short packetNumber;
	char payload[50];
	struct Packet *packet;
} Packet;

void printPacket(Packet packet);
void printPacketPointer(Packet *packet);
void printPacketMemberSizePointer(Packet *packet);

int main() {
	Packet packet1 = {1234, 10, 1, "youngstown ohio"};
	printPacketPointer(&packet1);
	printPacketMemberSizePointer(&packet1);
	printf("packetSize: %ld\n", sizeof(packet1));
	printf("------------------------------------------\n");
	Packet packet2;
	printPacketPointer(&packet2);
	printPacketMemberSizePointer(&packet2);
	printf("packetSize: %ld\n", sizeof(packet2));
	return 0;
}

void printPacket(Packet packet) {
	printf("packetID: %ld\n", packet.packetId);
	printf("numberOfPacket: %d\n", packet.numberOfPacket);
	printf("packetNumber: %d\n", packet.packetNumber);
	printf("payload: %s\n", packet.payload);
}

void printPacketPointer(Packet *packet) {
	printf("packetID: %ld\n", packet->packetId);
	printf("numberOfPacket: %d\n", packet->numberOfPacket);
	printf("packetNumber: %d\n", packet->packetNumber);
	printf("payload: %s\n", packet->payload);
}

void printPacketMemberSizePointer(Packet *packet) {
	printf("size packetID: %ld\n", sizeof(packet->packetId));
	printf("size numberOfPacket: %ld\n", sizeof(packet->numberOfPacket));
	printf("size packetNumber: %ld\n", sizeof(packet->packetNumber));
	printf("size payload: %ld\n",sizeof (packet->payload));
	printf("size packet: %ld\n",sizeof (packet->packet));
}
