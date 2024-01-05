#include <iostream>
#include <stack>

bool expressaoBalanceada(const std::string& expressao) {
    std::stack<char> pilha;

    for (char caractere : expressao) {
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            // Empilha os caracteres de abertura
            pilha.push(caractere);
        } else if (caractere == ')' || caractere == ']' || caractere == '}') {
            // Verifica se a pilha não está vazia antes de desempilhar
            if (pilha.empty()) {
                return false; // Se estiver vazia, a expressão está desbalanceada
            }

            // Verifica se o caractere de fechamento corresponde ao topo da pilha
            char topo = pilha.top();
            if ((caractere == ')' && topo != '(') ||
                (caractere == ']' && topo != '[') ||
                (caractere == '}' && topo != '{')) {
                return false; // Se não corresponder, a expressão está desbalanceada
            }

            pilha.pop(); // Remove o caractere de abertura correspondente
        }
    }

    // A expressão está balanceada se a pilha estiver vazia no final
    return pilha.empty();
}

int main() {
    std::string expressao1 = "[ { () () } { } ]";
    std::string expressao2 = "{ [ ( [ { } ] ) ] }";
    std::string expressao3 = "{ [ ( } ] )";
    std::string expressao4 = "{ [ ) () ( ] }";

    std::cout << "Expressao 1: " << (expressaoBalanceada(expressao1) ? "Balanceada" : "Desbalanceada") << "\n";
    std::cout << "Expressao 2: " << (expressaoBalanceada(expressao2) ? "Balanceada" : "Desbalanceada") << "\n";
    std::cout << "Expressao 3: " << (expressaoBalanceada(expressao3) ? "Balanceada" : "Desbalanceada") << "\n";
    std::cout << "Expressao 4: " << (expressaoBalanceada(expressao4) ? "Balanceada" : "Desbalanceada") << "\n";

    return 0;
}
