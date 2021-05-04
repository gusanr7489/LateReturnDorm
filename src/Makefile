CC = gcc
CFLAGS = -W -Wall
TARGET = LateApply
OBJECTS = main.c dorm_crud.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
        $(CC) -o $@ $^

deltxt :
        rm dorms.txt

clean :
        rm LateApply *.o
