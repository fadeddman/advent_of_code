CXX := g++
CXXFLAGS := -std=c++23 -O2 -Wall -Wextra -Wpedantic -Icommon
BIN_DIR := bin

.PHONY: help build run new clean

help:
	@echo "Usage:"
	@echo "  make build YEAR=2015 DAY=1   # compile a day"
	@echo "  make run   YEAR=2015 DAY=1   # compile and run a day (uses its input.txt)"
	@echo "  make new   YEAR=2015 DAY=2   # scaffold a new day from templates/day.cpp.tmpl"
	@echo "  make clean                   # remove build artifacts"

build:
	@if [ -z "$(YEAR)" ] || [ -z "$(DAY)" ]; then \
		echo "Usage: make build YEAR=<year> DAY=<day>"; exit 1; \
	fi
	@mkdir -p $(BIN_DIR)/$(YEAR)
	$(CXX) $(CXXFLAGS) $(YEAR)/day_$(DAY)/day_$(DAY).cpp -o $(BIN_DIR)/$(YEAR)/day_$(DAY)

run: build
	@./$(BIN_DIR)/$(YEAR)/day_$(DAY) $(YEAR)/day_$(DAY)/input.txt

new:
	@if [ -z "$(YEAR)" ] || [ -z "$(DAY)" ]; then \
		echo "Usage: make new YEAR=<year> DAY=<day>"; exit 1; \
	fi
	@mkdir -p $(YEAR)/day_$(DAY)
	@if [ -f $(YEAR)/day_$(DAY)/day_$(DAY).cpp ]; then \
		echo "Already exists: $(YEAR)/day_$(DAY)/day_$(DAY).cpp"; exit 1; \
	fi
	@sed 's/{{DAY}}/$(DAY)/g; s/{{YEAR}}/$(YEAR)/g' templates/day.cpp.tmpl > $(YEAR)/day_$(DAY)/day_$(DAY).cpp
	@touch $(YEAR)/day_$(DAY)/input.txt
	@echo "Created $(YEAR)/day_$(DAY)/day_$(DAY).cpp"

clean:
	rm -rf $(BIN_DIR)
