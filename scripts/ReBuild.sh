#!/bin/bash
set -e  # Stop if any of the called scripts fail

# Define ANSI color codes
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color (resets the text color)

echo -e "${GREEN}--- Starting Rebuild Process ---${NC}"

if [ -f "./Makefile" ]; then
	echo -e "${BLUE}[1] Calling Clean.sh...${NC}"
	./scripts/./Clean.sh
fi

echo -e "${BLUE}[2] Calling Linux-GenProjects.sh...${NC}"
./scripts/./Linux-GenProjects.sh

echo -e "${BLUE}[3] Calling Build.sh...${NC}"
./scripts/./Build.sh

echo -e "${GREEN}--- Rebuild Process Complete ---${NC}"

