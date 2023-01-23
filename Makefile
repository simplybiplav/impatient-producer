SOURCES=$(shell find . -name "*.cpp")
OBJECTS=$(SOURCES:%.cpp=%.o)
TARGET=impatient-producer

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX)  $^ $(LOADLIBES) -lpthread -lz -ldl -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)
