#############################################################################
# VideoStore
#

OBJS=NetVideo.o Video.o Rental.o Subscriber.o
TOBJS=Video_t.o Rental_t.o Subscriber_t.o
EXE=NetVideo Video_t Rental_t Subscriber_t

GCC= g++
CFLAGS=-Wall

.PHONY : all
all : $(EXE) test

# NetVideo
.PHONY : run
run : NetVideo
	@./NetVideo

NetVideo : $(OBJS)
	$(GCC) $^ -o $@

NetVideo.o: NetVideo.cpp Video.hpp Rental.hpp Subscriber.hpp
	$(GCC) $(CFLAGS) -c $<

# Video
Video.o: Video.cpp Video.hpp
	$(GCC) $(CFLAGS) -c $<

Video_t : Video_t.o Video.o
	$(GCC) $^ -o $@

Video_t.o: Video_t.cpp Video.hpp
	$(GCC) $(CFLAGS) -c $<

# Rental
Rental.o: Rental.cpp Rental.hpp Video.hpp
	$(GCC) $(CFLAGS) -c $<

Rental_t : Rental_t.o Rental.o Video.o
	$(GCC) $^ -o $@

Rental_t.o: Rental_t.cpp Rental.hpp
	$(GCC) $(CFLAGS) -c $<

# Subscriber
Subscriber.o: Subscriber.cpp Subscriber.hpp Video.hpp Rental.hpp
	$(GCC) $(CFLAGS) -c $<

Subscriber_t : Subscriber_t.o Subscriber.o Rental.o Video.o
	$(GCC) $^ -o $@

Subscriber_t.o: Subscriber_t.cpp Subscriber.hpp
	$(GCC) $(CFLAGS) -c $<

# clean
.PHONY : clean
clean : cleanobjects
	rm -f $(EXE)

.PHONY : cleanobjects
cleanobjects :
	rm -f $(OBJS) $(TOBJS)

# unit testing
.PHONY : test
test : Video_t Rental_t Subscriber_t
	@./Video_t
	@./Rental_t
	@./Subscriber_t
