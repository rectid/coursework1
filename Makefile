SOURCES=$(wildcard src/*.c)
OBJECTS := $(patsubst src/%.c,obj/%.o,$(SOURCES))
CFLAGS = -g

all: cw

cw: $(OBJECTS)
	gcc $(CFLAGS) -std=gnu99 $^ -o bin/cw

obj/%.o : src/%.c
	gcc $(CFLAGS) -std=gnu99 -c $< -o $@


clean_objects:
	rm -f $(OBJECTS)

clean:
	rm -rf obj/*.o bin/cw