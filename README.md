This repository contains various simple [Zyre](https://github.com/zeromq/zyre) examples.

### zyre_listener.c
starts a zyre node, joins a group, receives messages and prints the message frame by frame

### zyre_shouter.c
starts a zyre node, joins a group and shouts messages to all nodes in the group

### zyre_whisperer.c
starts a zyre node and whispers messages to a node with a given UUID


## Usage
#### Compile
```
make
```

#### zyre_listener
```
./zyre_listener <group_name>
```

### zyre_shouter
```
./zyre_shouter <group_name>
```

The `<group_name>` needs to be the same as the one used in `zyre_listener` if you want zyre_listener to receive the messages



### zyre_whisperer
```
./zyre_whisperer <UUID>
```

The `<UUID>` should be the UUID of the node to whom want to send the message (for example, the UUID of `zyre_listener`)
