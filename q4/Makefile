CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99 -g3

EXEC = iterative recursive
all: $(EXEC)
SRCS_commmon = main.c

iterative: main.c iterative.c
	$(CC) $(CFLAGS_common) -DITER -o $@ \
		$(SRCS_commmon) $@.c

recursive: main.c recursive.c
	$(CC) $(CFLAGS_common) -DRECUR -o $@ \
		$(SRCS_commmon) $@.c

run:$(EXEC)
	@echo --------Recursive Version Start--------
	@./recursive
	@echo --------Recursive Version End----------
	@echo --------Iterative Version Start--------                       
	@./iterative
	@echo --------Iterative Version End----------

clean:
	$(RM) $(EXEC) *.o perf.*
