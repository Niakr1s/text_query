CC = g++
CFLAGS = -Wall
LDFLAGS =
SRC_PATH = src/
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

run: release
	@echo -------------
	$(EXECUTABLE)
	@echo -------------

release: CFLAGS := -D NDEBUG $(CFLAGS)
release: build
debug: CFLAGS := -g $(CFLAGS)
debug: build
build: $(PREFIX) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXECUTABLE)

$(PREFIX):
	mkdir -p $@

DEPS := $(OBJS:.o=.d)

-include $(DEPS)

# -MMD flag create .d file with same name as .o
$(PREFIX)%.o: $(SRC_PATH)%.cpp  # for each .cpp in src_path making .o in prefix_path
	$(CC) -c -MMD $(CFLAGS) $< -o $@

clean:
	rm -rf $(RELEASE_PREFIX)* $(DEBUG_PREFIX)*
