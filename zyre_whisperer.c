#include <zyre.h>

// this program starts a zyre node and whispers
// messages to a node with a specific UUID
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./zyre_whisperer <UUID>\n");
        return 1;
    }

    char * peer_uuid = argv[1];
    // create a new node
    zyre_t *node = zyre_new("whisperer");
    if (!node)
    {
        return 1;                 //  Could not create new node
    }

    // this sends an ENTER message
    zyre_start(node);
    // wait for a while
    zclock_sleep(250);
    // print UUID of node
    printf("UUID: %s\n", zyre_uuid(node));
    for (int i = 0; i < 5; i++)
    {
        // this sends a WHISPER message
        zyre_whispers(node, peer_uuid, "%s", "hello");
        zclock_sleep(1000);
    }
    // this sends an EXIT message
    zyre_stop(node);
    // wait for node to stop
    zclock_sleep(100);
    zyre_destroy(&node);
    return 0;
}
