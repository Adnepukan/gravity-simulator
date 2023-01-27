# /usr/bin/make

TARGET		=gravity-simulator
OBJS_FORCE	=force.o force-gravity.o
OBJS_ITEM	=item.o item-circle.o
OBJS_DISP	=display.o display-circle.o
OBJS_CMD	=command.o command-display.o command-update.o command-queue.o
OBJS_ELSE	=vector3d.o graph.o 
OBJS_MAIN	=main.o
OBJS		=${OBJS_FORCE} ${OBJS_DISP} ${OBJS_ITEM} ${OBJS_CMD} ${OBJS_ELSE} ${OBJS_MAIN}
CC			=g++
SFMLFLAGS	=-lpthread -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network


$(TARGET):	$(OBJS)
	$(CC) $(SFMLFLAGS) -o $@ $^

%.o:	%.c
	$(CC) -Wall -g -c $^

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)

test:
	g++ -g test.cpp -o test
