CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -g3

EXEC = iterative recursive bitwise_iterative
all: $(EXEC)
SRCS_common = main.c

iterative: iterative.c
	$(CC) $(CFLAGS_common) -DITER -o $@ \
		$(SRCS_common) $@.c

recursive: main.c recursive.c
	$(CC) $(CFLAGS_common) -DRECUR -o $@ \
		$(SRCS_common) $@.c
bitwise_iterative: main.c
	$(CC) $(CFLAGS_common) -DBITI -o $@ \
		$(SRCS_common) $@.c 

run:$(EXEC)
	@echo --------Recursive Version Start--------                       
	@./recursive
	@echo --------Recursive Version End----------
	@echo --------Iterative Version Start--------
	@./iterative
	@echo --------Iterative Version End----------
	@echo --------Iterative Version Start--------                       
	@./bitwise_iterative
	@echo --------Iterative Version End----------

clean:
	$(RM) $(EXEC) *.o perf.*
