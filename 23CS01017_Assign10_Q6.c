#include <stdio.h>
#include <string.h>

typedef union
{
    struct
    {
        int opcode;
        int status;
    } control;
    char data[100];
} Packet;

typedef struct
{
    int isControl;
    Packet packet;
} DataPacket;

void assignControlPacket(DataPacket *packet, int opcode, int status)
{
    packet->isControl = 1;
    packet->packet.control.opcode = opcode;
    packet->packet.control.status = status;
}

void assignDataPacket(DataPacket *packet, const char *data)
{
    packet->isControl = 0;
    strncpy(packet->packet.data, data, sizeof(packet->packet.data) - 1);
    packet->packet.data[sizeof(packet->packet.data) - 1] = '\0';
}

void printPacket(const DataPacket *packet)
{
    if (packet->isControl)
        printf("Control Packet: Opcode = %d, Status = %d\n", packet->packet.control.opcode, packet->packet.control.status);
    else
        printf("Data Packet: Data = %s\n", packet->packet.data);
}

int main()
{
    DataPacket packets[3];
    int test, opcode[3], status[3];
    char data[3][100];

    printf("Enter the number of Tests: ");
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        printf("Enter your choice: 1-Control Packet OR 2-Data Packet\n");
        int type;
        scanf("%d", &type);
        switch (type - 1)
        {
        case 0:
            printf("Enter OPCODE and STATUS: \n");
            scanf("%d %d", &opcode[i], &status[i]);
            assignControlPacket(&packets[i], opcode[i], status[i]);
            break;
        case 1:
            printf("Enter DATA: \n");
            scanf("%s", data[i]);
            assignDataPacket(&packets[i], data[i]);
            break;
        }
    }

    for (int i = 0; i < 3; i++)
        printPacket(&packets[i]);

    return 0;
}