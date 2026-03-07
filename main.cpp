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
    if (player == nullptr) {
        return;
    }

    for (int i = 0; i < steps; i++) {
        // if we are on the last node, moving next means we pass GO
        if (player == tail) {
            goPassCount++;
        }

        player = player->next;
    }
}

void MonopolyBoard::printFromPlayer(int count) const {
    if (player == nullptr) {
        cout << "Board is empty." << endl;
        return;
    }

    Node* temp = player;

    for (int i = 0; i < count; i++) {
        cout << temp->data.name << " (" << temp->data.color << ", $" << temp->data.cost << ")" << endl;
        temp = temp->next;
    }
}
bool MonopolyBoard::removeByName(string name) {
    // if board is empty
    if (head == nullptr) {
        return false;
    }

    Node* cur = head;
    Node* prev = tail; // in a circle, tail is right before head

    // go around the circle once
    do {
        if (cur->data.name == name) {

            if (boardSize == 1) {
                delete cur;
                head = nullptr;
                tail = nullptr;
                player = nullptr;
                boardSize = 0;
                return true;
            }

            // if player is standing on the one we delete, move player forward
            if (player == cur) {
                player = cur->next;
            }

            // remove cur from the circle
            prev->next = cur->next;

            // if we delete head, move head
            if (cur == head) {
                head = cur->next;
            }

            // if we delete tail, move tail back
            if (cur == tail) {
                tail = prev;
            }

            delete cur;
            boardSize--;

            // make sure tail points to head (keeps circle correct)
            tail->next = head;

            return true;
        }

        prev = cur;
        cur = cur->next;

    } while (cur != head);

    return false; // not found
}

vector<string> MonopolyBoard::findByColor(string color) const {
    vector<string> matches;

    // if board is empty
    if (head == nullptr) {
        return matches;
    }

    Node* temp = head;

    // go around the circle one time
    do {
        if (temp->data.color == color) {
            matches.push_back(temp->data.name);
        }
        temp = temp->next;
    } while (temp != head);

    return matches;
}

void MonopolyBoard::clear() {
    if (head == nullptr) {
        return;
    }

    // break the circle so we don't loop forever
    tail->next = nullptr;

    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    player = nullptr;
    boardSize = 0;
    goPassCount = 0;
}

int main() {
    MonopolyBoard board;

    cout << "Project setup complete." << endl;

    return 0;
}