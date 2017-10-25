#include <zyre.h>

// this program starts a zyre node, joins a group,
// receives messages and prints the message frame by frame
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./zyre_listener <group name>\n");
        return 1;
    }

    char * group_name = argv[1];

    // create a new node
    zyre_t *node = zyre_new("listener");
    if (!node)
    {
        return 1;                 //  Could not create new node
    }

    // this sends an ENTER message
    zyre_start(node);
    // this sends a JOIN message
    zyre_join(node, group_name);
    // wait for a while
    zclock_sleep(250);
    // print UUID of node
    printf("UUID: %s\n", zyre_uuid(node));
    while (true)
    {
        zmsg_t * msg = zyre_recv(node);

        // loop through the frames in the message
        while(true)
        {
            char * msg_str = zmsg_popstr(msg);
            if (!msg_str)
            {
                break;
            }
            printf("frame: %s\n", msg_str);
            // with zmsg_popstr, you own the frame string
            // so you need to free it
            free(msg_str);
        }
        printf("------\n");
        // you own the message with zyre_recv
        // so you need to destroy it
        zmsg_destroy(&msg);
    }
    // this sends a LEAVE message
    zyre_leave(node, group_name);
    // this sends an EXIT message
    zyre_stop(node);
    // wait for node to stop
    zclock_sleep(100);
    zyre_destroy(&node);
    return 0;
}
