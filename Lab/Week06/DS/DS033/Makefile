CC = clang++
SRC = main.cpp CouponStack.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(EXEC)
