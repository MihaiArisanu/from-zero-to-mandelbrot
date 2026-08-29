PROJECT_DIR := projects/01-ppm-image-generator

all:
	$(MAKE) -C $(PROJECT_DIR) all

run:
	$(MAKE) -C $(PROJECT_DIR) run

clean:
	$(MAKE) -C $(PROJECT_DIR) clean

.PHONY: all run clean