#include "Converter.hpp"

namespace Algorithms {

    bool is_operator(const std::string &token) {
        return token == "*" || token == "/" || token == "-" || token == "+";
    }
    int get_operator_priority(const std::string &token) {
        if (token == "*" || token == "/") {
            return 2;
        }
        if (token == "+" || token == "-") {
            return 1;
        }
        return 0;
    }

    LinkedList<std::string> *tokenize(std::istream &source) {
        auto token_list = new LinkedList<std::string>();
        std::string word;
        while (source >> word) {
            token_list->append(new Node<std::string>(word));
        }
        return token_list;
    }

    std::string convert_infix_postfix(std::istream &source) {
        auto token_list = Algorithms::tokenize(source);
        auto output_queue = new LinkedList<std::string>();
        auto operator_stack = new Stack<std::string>();

        while (token_list->head != nullptr) {
            std::string token;
            switch (token_list->head->value[0]) {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    output_queue->append(new Node<std::string>(token_list->head->value));
                    break;
                case '(':
                    operator_stack->push(token_list->head->value);
                    break;
                case ')':
                    try {
                        while ((token = operator_stack->pop()) != "(") {
                            output_queue->append(new Node<std::string>(token));
                        }
                    } catch (std::out_of_range) {
                        throw std::invalid_argument("Non paired parentheses");
                    }
                    break;
                case '*':
                case '/':
                case '+':
                case '-':
                    if (!operator_stack->empty()
                        && Algorithms::is_operator(token = operator_stack->peek())) {
                        auto this_priority
                            = Algorithms::get_operator_priority(token_list->head->value);
                        auto that_priority = Algorithms::get_operator_priority(token);

                        while (this_priority <= that_priority) {
                            output_queue->append(new Node<std::string>(token));
                            operator_stack->pop();
                            if (operator_stack->empty()) {
                                break;
                            }
                            token = operator_stack->peek();
                            that_priority = Algorithms::get_operator_priority(token);
                        }
                    }
                    operator_stack->push(token_list->head->value);
                    break;

                default:
                    throw std::invalid_argument("No such token");
            }
            token_list->remove_first();
        }

        while (!operator_stack->empty()) {
            auto token = operator_stack->pop();
            if (token == "(" || token == ")") {
                throw std::invalid_argument("Non paired parentheses");
            }
            output_queue->append(new Node<std::string>(token));
        }

        delete token_list;

        std::string result = "";
        int length = output_queue->size();
        for (int i = 0; i < length; i++) {
            result.append(output_queue->head->value);
            if (i != length - 1) {
                result.append(" ");
            }
            output_queue->remove_first();
        }
        return result;
    }
}  // namespace Algorithms