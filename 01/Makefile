CXX = g++
CXXFLAGS = --std=c++11 -I/opt/homebrew/Cellar/rapidjson/1.1.0/include -I/opt/homebrew/Cellar/curl/8.0.1/include
LDFLAGS = -L/opt/homebrew/Cellar/curl/8.0.1/lib -lcurl

# Define the program name and source files
PROGRAM = ShoppingKart
SOURCES = Kart.cpp User.cpp Wallet.cpp main.cpp Api.cpp

# Define the default input file name
FILENAME ?= json.txt

# Define the compilation rule
$(PROGRAM): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# Define the execution rule
run: $(PROGRAM)
	./$(PROGRAM) $(FILENAME)

# Define the phony targets
.PHONY: clean run

# Define the clean rule
clean:
	rm -f $(PROGRAM)

