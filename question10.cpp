#include <iostream>
#include <stack>
#include <cctype>

// Função para verificar se um caractere é uma letra
bool isOperando(char c) {
    return std::isalpha(c) != 0; // Usa isalpha() da biblioteca ctype.h
}

// Função para obter a precedência de um operador
int precedencia(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    } else if (operador == '*' || operador == '/') {
        return 2;
    }
    return 0; // Operando ou operador desconhecido
}

// Função para converter expressão infixa para posfixa
std::string infixaParaPosfixa(const std::string& expressaoInfixa) {
    std::string expressaoPosfixa;
    std::stack<char> pilhaOperadores;

    for (char caractere : expressaoInfixa) {
        if (isOperando(caractere)) {
            // Se for um operando, adiciona à expressão posfixa
            expressaoPosfixa += caractere;
        } else if (caractere == '(') {
            // Se for um parêntese de abertura, empilha na pilha de operadores
            pilhaOperadores.push(caractere);
        } else if (caractere == ')') {
            // Se for um parêntese de fechamento, desempilha operadores até encontrar o parêntese de abertura
            while (!pilhaOperadores.empty() && pilhaOperadores.top() != '(') {
                expressaoPosfixa += pilhaOperadores.top();
                pilhaOperadores.pop();
            }
            // Remove o parêntese de abertura da pilha
            pilhaOperadores.pop();
        } else {
            // Se for um operador, desempilha operadores de maior ou igual precedência
            while (!pilhaOperadores.empty() && precedencia(pilhaOperadores.top()) >= precedencia(caractere)) {
                expressaoPosfixa += pilhaOperadores.top();
                pilhaOperadores.pop();
            }
            // Empilha o operador atual
            pilhaOperadores.push(caractere);
        }
    }

    // Desempilha operadores restantes
    while (!pilhaOperadores.empty()) {
        expressaoPosfixa += pilhaOperadores.top();
        pilhaOperadores.pop();
    }

    return expressaoPosfixa;
}

int main() {
    std::string expressaoInfixa;
    
    std::cout << "Digite uma expressao infixa: ";
    std::cin >> expressaoInfixa;

    std::string expressaoPosfixa = infixaParaPosfixa(expressaoInfixa);

    std::cout << "Expressao posfixa: " << expressaoPosfixa << std::endl;

    return 0;
}
