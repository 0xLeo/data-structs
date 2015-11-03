CC = gcc
CFLAGS = -O2 -g -std=c99 -I.
SRC1 = test.c
SRC2 = tree.c
OBJ0 = tree.o
OBJ1 = test1.o
OBJ2 = test2.o
OBJ3 = test3.o
OBJ4 = test4.o
OBJ5 = test5.o
OBJ6 = test6.o
EXE1 = test1
EXE2 = test2
EXE3 = test3
EXE4 = test4
EXE5 = test5
EXE6 = test6

$(OBJ0): $(SRC2)
	$(CC) -c $(CFLAGS) $(SRC2) -o $(OBJ0)

$(OBJ1): $(SRC1)
	$(CC) -c -DTEST1 $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2): $(SRC1)
	$(CC) -c -DTEST2 $(CFLAGS) $(SRC1) -o $(OBJ2)

$(OBJ3): $(SRC1)
	$(CC) -c -DTEST3 $(CFLAGS) $(SRC1) -o $(OBJ3)

$(OBJ4): $(SRC1)
	$(CC) -c -DTEST3 -DTEST4 $(CFLAGS) $(SRC1) -o $(OBJ4)

$(OBJ5): $(SRC1)
	$(CC) -c -DTEST3 -DTEST5 $(CFLAGS) $(SRC1) -o $(OBJ5)

$(OBJ6): $(SRC1) 
	$(CC) -c -DTEST6 $(CFLAGS) $(SRC1) -o $(OBJ6)


$(EXE1): $(OBJ0) $(OBJ1)
	$(CC) $(OBJ0) $(OBJ1) -o $(EXE1)

$(EXE2): $(OBJ0) $(OBJ2)
	$(CC) $(OBJ0) $(OBJ2) -o $(EXE2)

$(EXE3): $(OBJ0) $(OBJ3)
	$(CC) $(OBJ0) $(OBJ3) -o $(EXE3)

$(EXE4): $(OBJ0) $(OBJ4)
	$(CC) $(OBJ0) $(OBJ4) -o $(EXE4)

$(EXE5): $(OBJ0) $(OBJ5)
	$(CC) $(OBJ0) $(OBJ5) -o $(EXE5)

$(EXE6): $(OBJ0) $(OBJ6)
	$(CC) $(OBJ0) $(OBJ6) -o $(EXE6)

build: $(OBJ0) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
	@$(MAKE) $(OBJ0)
	@$(MAKE) $(OBJ1)
	@$(MAKE) $(OBJ2)
	@$(MAKE) $(OBJ3)
	@$(MAKE) $(OBJ4)
	@$(MAKE) $(OBJ5)
	@$(MAKE) $(OBJ6)
	@$(MAKE) $(EXE1)
	@$(MAKE) $(EXE2)
	@$(MAKE) $(EXE3)
	@$(MAKE) $(EXE4)
	@$(MAKE) $(EXE5)
	@$(MAKE) $(EXE6)

run: $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6)
	./$(EXE1)
	./$(EXE2)
	chmod +x test12.sh
	./test12.sh
	./$(EXE3)
	./$(EXE4)
	./$(EXE5)
	./$(EXE6)

time: $(EXE3) $(EXE4) $(EXE5)
	chmod +x test345.sh
	./test345.sh $(EXE3)
	./test345.sh $(EXE4)
	./test345.sh $(EXE5)

clean:
	$(RM) *.o $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6) test?.txt temp a.out
