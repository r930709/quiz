CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -g3

EXEC = iterative recursive
all: $(EXEC)
SRCS_common = main.c

iterative: $(SRCS_common)
	$(CC) $(CFLAGS_common) -DITER -o $@ \
		$(SRCS_common) Linklist.c $@.c

recursive: $(SRCS_common)
	$(CC) $(CFLAGS_common) -DRECUR -o $@ \
		$(SRCS_common) Linklist.c $@.c
run: $(EXEC)
	@echo --------Recursive Version Start--------
	@./recursive
	@echo --------Recursive Version End----------
	@echo --------Iterative Version Start--------
	@./iterative                                                                                  
	@echo --------Iterative Version End----------

clean:
	$(RM) $(EXEC) *.o perf.*
