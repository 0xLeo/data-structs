CC = gcc
CFLAGS = -O2 -g -std=c99
SRCF = tree.c test.c
EXECF1 = test1
EXECF2 = test2
EXECF3 = test3
EXECF4 = test4

default:
	@$(MAKE) -s build1
	@$(MAKE) -s build2
	@$(MAKE) -s build3
	@$(MAKE) -s build4
	@$(MAKE) -s run1
	@$(MAKE) -s run2
	@$(MAKE) -s run3
	@$(MAKE) -s run4

build1:
	$(CC) $(CFLAGS) -DTEST1 $(SRCF) -o $(EXECF1)
build2:
	$(CC) $(CFLAGS) -DTEST2 $(SRCF) -o $(EXECF2)
build3:
	$(CC) $(CFLAGS) -DTEST3 $(SRCF) -o $(EXECF3) 
build4:
	$(CC) $(CFLAGS) -DTEST4 $(SRCF) -o $(EXECF4)

run1:
	./$(EXECF1) | tee out1.txt
run2:
	./$(EXECF2) | tee out2.txt
	chmod +x test12.sh
	./test12.sh
run3:
	./$(EXECF3) 
run4:
	chmod +x test4.sh
	./test12.sh
	./test4.sh

clean:
	$(RM) $(EXECF1) $(EXECF2) $(EXECF3) $(EXECF4) out1.txt out2.txt 
