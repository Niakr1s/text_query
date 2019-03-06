CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC_PATH = 
SRCS = $(wildcard $(SRC_PATH)*.cpp)  # get all .cpp in src dir

# making PREFIX
RELEASE_PREFIX = build/release/
DEBUG_PREFIX = build/debug/
ifeq "$(strip $(filter debug, $(MAKECMDGOALS)))" "debug"
PREFIX = $(DEBUG_PREFIX)
else
PREFIX = $(RELEASE_PREFIX)
endif

OBJS = $(addprefix $(PREFIX), $(notdir $(SRCS:.cpp=.o)))
EXECUTABLE = $(PREFIX)main.exe

.PHONY: run release debug build clean

release: build
debug: CFLAGS = -g
debug: build
build: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXECUTABLE)

$(OBJS): | $(PREFIX)  # create PREFIX path if not exists
$(PREFIX):
	mkdir -p $(PREFIX)

$(PREFIX)%.o: $(SRC_PATH)%.cpp  # for each .cpp in src_path making .o in prefix_path
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(RELEASE_PREFIX)* $(DEBUG_PREFIX)*

run: release
	@echo -------------
	$(EXECUTABLE)
	@echo -------------