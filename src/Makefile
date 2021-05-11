CC = gcc
CFLAGS = -W -Wall
TARGET = LateApply
OBJECTS = main.c dorm_crud.o dorm_file.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
        $(CC) $(CFLAGS) o $@ $^

deltxt :
        rm dorms.txt

clean :
        rm *.o LateApply
