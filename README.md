# Monopoly-board-sim

A Monopoly-style game board simulator using a circular linked list.

## How to Build and Run
### CLion
Open the project in CLion and press Run.

### Terminal
g++ -std=c++17 main.cpp -o monopoly  
./monopoly

## Data Structures Used
Space: stores one board space (name + color)

Node: stores a Space and a next pointer

Circular linked list:

head = first node

tail = last node

tail->next points back to head

player pointer: points to the current space

## Functions
addSpace(const Space& s): adds one node to the tail, keeps it circular, max 40.

addMany(const vector<Space>& spaces): adds spaces until full, returns how many.

movePlayer(int steps): moves node-by-node, counts passing GO when tail -> head.

printFromPlayer(int count) const: prints count spaces starting from player.

removeByName(string name): deletes first matching name (head/tail/only-node handled).

findByColor(string color) const: traverses once and returns matching names.

clear(): deletes all nodes safely by breaking the circle first.

## Traversal / Passing GO
Movement follows next pointers for each step. Passing GO is counted when moving from tail back to head.

## 40 Space Limit
The board is limited to 40 spaces. Extra insertions fail without breaking the list.