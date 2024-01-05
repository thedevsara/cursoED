#include <iostream>
#include <stack>

// Função para ordenar uma pilha de números reais
void ordenarPilhas(std::stack<float>& pilhaA) {
    std::stack<float> pilhaB;

    while (!pilhaA.empty()) {
        float temp = pilhaA.top();
        pilhaA.pop();

        // Transferir elementos maiores de pilhaB para pilhaA
        while (!pilhaB.empty() && pilhaB.top() > temp) {
            pilhaA.push(pilhaB.top());
            pilhaB.pop();
        }

        // Empilhar temp em pilhaB
        pilhaB.push(temp);
    }

    // PilhaB já está ordenada, então transferir para pilhaA
    while (!pilhaB.empty()) {
        pilhaA.push(pilhaB.top());
        pilhaB.pop();
    }
}

int main() {
    std::stack<float> pilhaA;

    int n;
    std::cout << "Digite a quantidade de números: ";
    std::cin >> n;

    std::cout << "Digite os números:\n";
    for (int i = 0; i < n; i++) {
        float num;
        std::cin >> num;
        pilhaA.push(num);
    }

    // Ordenar a pilhaA
    ordenarPilhas(pilhaA);

    // Exibir os elementos ordenados
    std::cout << "\nPilha A ordenada:\n";
    while (!pilhaA.empty()) {
        std::cout << pilhaA.top() << " ";
        pilhaA.pop();
    }

    return 0;
}
