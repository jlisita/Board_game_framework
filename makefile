CC=g++
CFLAGS=-I$(HEADDIR) -W -Wall -ansi -pedantic
LDFLAGS=
SRCDIR=Src
HEADDIR=Includes
SRC= $(wildcard $(SRCDIR)/*.cpp)
OBJ= $(SRC:$(SRCDIR)/%.cpp=$(SRCDIR)/%.o)
EXEC=prog

all: $(EXEC)

prog: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADDIR)/%.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(SRCDIR)/*.o

mrproper: clean
	rm -rf $(EXEC)

