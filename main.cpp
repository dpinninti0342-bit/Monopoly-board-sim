#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Space {
    string name;
    string color;
    int cost;

    Space(string n = "", string c = "", int co = 0) {
        name = n;
        color = c;
        cost = co;
    }
};

struct Node {
    Space data;
    Node* next;

    Node(const Space& s) {
        data = s;
        next = nullptr;
    }
};

class MonopolyBoard {
private:
    Node* head;
    Node* tail;
    Node* player;
    int boardSize;
    int goPassCount;
    const int MAX_SPACES = 40;

public:
    MonopolyBoard() {
        head = nullptr;
        tail = nullptr;
        player = nullptr;
        boardSize = 0;
        goPassCount = 0;
    }

    ~MonopolyBoard() {
        clear();
    }

    bool addSpace(const Space& s);
    int addMany(const vector<Space>& spaces);
    void movePlayer(int steps);
    void printFromPlayer(int count) const;
    bool removeByName(string name);
    vector<string> findByColor(string color) const;
    void clear();
};

bool MonopolyBoard::addSpace(const Space& s) {
    if (boardSize == MAX_SPACES) {
        return false;
    }

    Node* temp = new Node(s);

    // if this is the first space
    if (head == nullptr) {
        head = temp;
        tail = temp;
        player = temp;
        temp->next = temp;
    } else {
        tail->next = temp;
        temp->next = head;
        tail = temp;
    }

    boardSize++;
    return true;
}
int MonopolyBoard::addMany(const vector<Space>& spaces) {
    int count = 0;

    for (int i = 0; i < spaces.size(); i++) {
        if (addSpace(spaces[i])) {
            count++;
        } else {
            break;
        }
    }

    return count;
}

void MonopolyBoard::movePlayer(int steps) {
    // TODO
}

void MonopolyBoard::printFromPlayer(int count) const {
    // TODO
}

bool MonopolyBoard::removeByName(string name) {
    // TODO
    return false;
}

vector<string> MonopolyBoard::findByColor(string color) const {
    vector<string> matches;
    // TODO
    return matches;
}

void MonopolyBoard::clear() {
    // TODO
}

int main() {
    MonopolyBoard board;

    cout << "Project setup complete." << endl;

    return 0;
}