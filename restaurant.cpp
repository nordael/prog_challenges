#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Event {
    int time, type, id; // tempo, tipo (chegada=0, saída=1), índice do cliente
    bool operator<(const Event& other) const {
        return time < other.time;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 0, i}); // evento de chegada
        events.push_back({b, 1, i}); // evento de saída
    }
    sort(events.begin(), events.end()); // ordena os eventos em ordem crescente de tempo

    int max_clients = 0, clients = 0;
    for (const auto& e : events) {
        if (e.type == 0) { // chegada de cliente
            clients++;
            max_clients = max(max_clients, clients);
        } else { // saída de cliente
            clients--;
        }
    }
    cout << max_clients << endl;
    return 0;
}
