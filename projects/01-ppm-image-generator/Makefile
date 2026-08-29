CXX := c++
CPPFLAGS := -Iinclude -MMD -MP
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic

SRC_DIR := src
BUILD_DIR := build
TARGET := $(BUILD_DIR)/01-ppm_image_generator

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
DEPENDENCIES := $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPENDENCIES)

.PHONY: all run clean
