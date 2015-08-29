CC = gcc
CFLAGS = -O2 -g -std=c99
SRCF = doubly.c test.c
EXEF = test

default:
	@$(MAKE) -s build1
	@$(MAKE) -s run
	@$(MAKE) -s clean
	@$(MAKE) -s build2
	@$(MAKE) -s run
	@$(MAKE) -s clean

build1:
	$(CC) $(CFLAGS) -DTEST1 $(SRCF) -o $(EXEF) 

build2:
	$(CC) $(CFLAGS) -DTEST2 $(SRCF) -o $(EXEF) 

run: 
	 ./$(EXEF)

clean:
	$(RM) -f $(EXEF)
