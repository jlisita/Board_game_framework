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


$(SRCDIR)/Game.o: $(HEADDIR)/Board.h $(HEADDIR)/Player.h 

$(SRCDIR)/Board.o: $(HEADDIR)/Piece.h $(HEADDIR)/Square.h

$(SRCDIR)/Player.o: $(HEADDIR)/Piece.h $(HEADDIR)/Board.h

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADDIR)/%.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(SRCDIR)/*.o

mrproper: clean
	rm -rf $(EXEC)

