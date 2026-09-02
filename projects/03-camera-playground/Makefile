CXX := c++
CPPFLAGS := $(shell pkg-config --cflags raylib) -MMD -MP
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic
LDLIBS := $(shell pkg-config --libs raylib)

SRC_DIR := src
BUILD_DIR := build
TARGET := $(BUILD_DIR)/03-camera-playground

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEPENDENCIES := $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDLIBS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPENDENCIES)

.PHONY: all run clean