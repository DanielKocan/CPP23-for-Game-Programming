#include <iostream>  // cout, cin
#include <string> // string, getline
#include <vector> // vector
#include <stack> // stack
#include <queue>// queue
#include <cmath>// fmod, pow

// higher = more priority
int precedence(char op)
{
    if (op == '^')                           return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-')              return 1;
    return 0;
}

// ^ is right-associative so 2^3^2 = 2^(3^2), not (2^3)^2
bool isRightAssociative(char op)
{
    return op == '^';
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// breaks the raw input string into a list of tokens (numbers and operators) e.g. 12 + 3.5 -> {"12", "+", "3.5"}
std::vector<std::string> tokenise(const std::string& expr)
{
    std::vector<std::string> tokens;
    size_t i = 0;

    while (i < expr.length())
    {
        char c = expr[i];

        // isspace checks if a character is whitespace (space, tab, etc.)
        if (std::isspace(c)) { i++; continue; }

        // isdigit checks if a character is 0-9
        if (std::isdigit(c) || c == '.') // this entire loop is basically figure out how long this number is, grab it whole, then skip past it
        {
            size_t len = 0;
            // substr -  cuts out a piece of the string starting at i
            // stod - converts that piece to a double and tells us how many chars it used
            std::stod(expr.substr(i), &len);
            tokens.push_back(expr.substr(i, len));
            i += len;
            continue;
        }

        // handle a negative number at the start or right after ( or another operator, eg -3 * 2 or (-5 + 1)
        if (c == '-' &&
            (tokens.empty() || tokens.back() == "(" || isOperator(tokens.back()[0])))
        {
            i++; // skip the minus sign itself
            while (i < expr.length() && std::isspace(expr[i])) i++;
            if (i < expr.length() && (std::isdigit(expr[i]) || expr[i] == '.'))
            {
                size_t len = 0;
                std::stod(expr.substr(i), &len);
                tokens.push_back("-" + expr.substr(i, len));
                i += len;
                continue;
            }
            tokens.push_back("-");
            continue;
        }

        if (isOperator(c) || c == '(' || c == ')')
        {
            tokens.push_back(std::string(1, c));
            i++;
            continue;
        }

        std::cout << "Warning: unknown character '" << c << "' ignored." << std::endl;
        i++;
    }

    return tokens;
}

// converts infix tokens to Reverse Polish Notation using the Shunting-Yard algorithm ( was really hard to understand...)
// eg {"3","+","4","*","2"} -> {"3","4","2","*","+"}
// numbers go straight to output, operators wait on a stack until something
// lower-priority arrives, then they get flushed to output
std::queue<std::string> shuntingYard(const std::vector<std::string>& tokens)
{
    std::queue<std::string> output;
    std::stack<char>        ops;

    for (const std::string& tok : tokens)
    {
        if (tok.empty()) continue;

        char first = tok[0];
        bool isNum = std::isdigit(first) || first == '.' || (first == '-' && tok.size() > 1);

        if (isNum)
        {
            output.push(tok);
            continue;
        }

        char c = first;

        if (c == '(')
        {
            ops.push(c);
            continue;
        }

        if (c == ')')
        {
            // pop everything until we hit the matching (
            while (!ops.empty() && ops.top() != '(')
            {
                output.push(std::string(1, ops.top()));
                ops.pop();
            }
            if (ops.empty())
            {
                std::cout << "ERROR: mismatched parentheses, extra ')'" << std::endl;
                return {};
            }
            ops.pop(); // discard the (
            continue;
        }

        if (isOperator(c))
        {
            // flush operators with higher (or equal, left-assoc) precedence first
            while (!ops.empty() && ops.top() != '(' &&
                (precedence(ops.top()) > precedence(c) ||
                    (precedence(ops.top()) == precedence(c) && !isRightAssociative(c))))
            {
                output.push(std::string(1, ops.top()));
                ops.pop();
            }
            ops.push(c);
            continue;
        }
    }

    // flush whatever operators are still on the stack
    while (!ops.empty())
    {
        if (ops.top() == '(')
        {
            std::cout << "ERROR: mismatched parentheses, extra '('" << std::endl;
            return {};
        }
        output.push(std::string(1, ops.top()));
        ops.pop();
    }

    return output;
}

// walks the RPN queue and computes the final answer numbers are pushed onto a value stack when we hit an operator we pop two numbers, compute, push the result back
double evaluateRPN(std::queue<std::string> rpn)
{
    std::stack<double> vals; // A stack is like a pile of plates you can only add or remove from the top.

      // front gives the next item in the queue, pop removes it
    while (!rpn.empty())
    {
        std::string tok = rpn.front();
        rpn.pop();

        bool isNum = !tok.empty() &&
             (std::isdigit(tok[0]) || tok[0] == '.' || (tok[0] == '-' && tok.size() > 1));

        if (isNum)
        {
            vals.push(std::stod(tok));
            continue;
        }

        if (vals.size() < 2)
        {
            std::cout << "ERROR: invalid expression, not enough numbers" << std::endl;
            return 0;
        }

        double b = vals.top(); vals.pop(); // right-hand side
        double a = vals.top(); vals.pop(); // left-hand side

        char op = tok[0];

        if ((op == '/' || op == '%') && b == 0)
        {
            std::cout << "ERROR: cannot divide or modulo by zero" << std::endl;
            return 0;
        }

        switch (op)
        {
            case '+': vals.push(a + b); 
                break;
            case '-': vals.push(a - b); 
                break;
            case '*': vals.push(a * b);  
                break;
            case '/': vals.push(a / b);
                break;
            case '%': vals.push(std::fmod(a, b)); 
                break;
            case '^': vals.push(std::pow(a, b)); 
                break;
            default:
                std::cout << "ERROr: unknown operator" << std::endl;
                return 0;
        }
    }

    if (vals.size() != 1)
    {
        std::cout << "ERROR: invalid expression, too many numbers" << std::endl;
        return 0;
    }

    return vals.top();
}

int main()
{
    std::string input;
    std::cout << "Enter expression (eg 3 + 4 * 2 / (1 - 5)^2): ";
    std::getline(std::cin, input);

    if (input.empty())
    {
        std::cout << "No input provided" << std::endl;
        return 0;
    }

    std::vector<std::string> tokens = tokenise(input);
    std::queue<std::string>  rpn = shuntingYard(tokens);

    if (!rpn.empty()){
        double result = evaluateRPN(rpn);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}