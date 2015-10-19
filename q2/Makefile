CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

#EXEC = iterative recursive
EXEC = iterative
all: $(EXEC)
SRCS_common = main.c

iterative: iterative.c
	$(CC) $(CFLAGS_common) -DITER -o $@ \
		$(SRCS_common) $@.c

#recursive: recursive.c
#	$(CC) $(CFLAGS_common) -o $@ $@.c

run:$(EXEC)
	@echo --------Iterative Version Start--------
	@./iterative
	@echo --------Iterative Version End----------

clean:
	$(RM) $(EXEC) *.o perf.*
