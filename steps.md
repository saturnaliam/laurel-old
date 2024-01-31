### client side
1. get user input

2. validate input
    1. ensure command is valid
    2. ensure the command has needed arguments

3. validate server
    1. make sure the server can be connected to

4. format the message and send it to the server

### server side
1. recieve message

2. check validity of message
    1. make sure magic number + command type valid
    2. make sure the user isnt trying any goofy stuff w what theyre passing in

3. execute command

4. give back some return code

