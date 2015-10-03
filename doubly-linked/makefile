CC = gcc
CFLAGS = -O2 -g -std=c99
SRCF1 = doubly.c
SRCF2 = test.c
OBJ1 = doubly.o
OBJ2 = test1.o
OBJ3 = test2.o
OBJ4 = test3.o
EXE1 = test1
EXE2 = test2
EXE3 = test3

$(OBJ1): $(SRCF1)
	$(CC) -c $(CFLAGS) $(SRCF1) -o $(OBJ1)

$(OBJ2): $(SRCF2)
	$(CC) -c -DTEST1 $(CFLAGS) $(SRCF2) -o $(OBJ2)

$(OBJ3): $(SRCF2)
	$(CC) -c -DTEST2 $(CFLAGS) $(SRCF2) -o $(OBJ3)

$(OBJ4): $(SRCF2)
	$(CC) -c -DTEST2 -DTEST3 $(CFLAGS) $(SRCF2) -o $(OBJ4)

$(EXE1): $(OBJ1) $(OBJ2)
	$(CC) $(OBJ1) $(OBJ2) -o $(EXE1)

$(EXE2): $(OBJ1) $(OBJ3)
	$(CC) $(OBJ1) $(OBJ3) -o $(EXE2)

$(EXE3): $(OBJ1) $(OBJ3)
	$(CC) $(OBJ1) $(OBJ4) -o $(EXE3)

build:
	@$(MAKE) $(OBJ1)
	@$(MAKE) $(OBJ2)
	@$(MAKE) $(OBJ3)
	@$(MAKE) $(OBJ4)
	@$(MAKE) $(EXE1)
	@$(MAKE) $(EXE2)
	@$(MAKE) $(EXE3)

run:
	./$(EXE1)
	./$(EXE2)
	./$(EXE3)

time:

	./timewrapper.sh $(EXE2)
	./timewrapper.sh $(EXE3)

clean:
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(EXE1) $(EXE2) $(EXE3) 
