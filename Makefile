.PHONY: all debug release clean

RELEASE_FLAGS = -O2 -Wall -DNDEBUG
DEBUG_FLAGS   = -g -O0 -Wall
RELEASE_EXEC  = calc
DEBUG_EXEC    = calc-dbg
SOURCE        = calc.cpp

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): $(SOURCE)
	g++ $(DEBUG_FLAGS) $(SOURCE) -o $(DEBUG_EXEC) 

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): $(SOURCE)
	g++ $(RELEASE_FLAGS) $(SOURCE) -o $(RELEASE_EXEC)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)

