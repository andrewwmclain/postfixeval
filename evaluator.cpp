/*
    Title:      Lab 4 – evaluator.cpp
    Purpose:    implement evaluate function to evaluate postfix expression
    Author:     Andrew McLain
    Date:       May 13, 2020
*/

#include "evaluator.h"
#include <stack>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iostream>

using std::stack;

/*
Evaluate
Evaluates a postfix expression
@param const string& postfix - the postfix expression to be evaluated
@param bool& error - assigned true if error found in expression, false if no error found
@returns -1 when error found in expression, result of expression otherwise
*/
double Evaluate(const string& postfix, bool& error){
    std::stringstream ss(postfix);
    stack<double> s;
    string c;
    //take in input
    while(ss >> c){
        //if next input is an operator
        if(c == "+" || c == "-" || c == "*"
           || c == "/" || c == "^"){
            //cannot operate if there is no operand
            if(s.empty()){
                error = true;
                return -1;
            }
            double a = s.top();
            s.pop();
            //cannot do binary operation with no second operand
            if(s.empty()){
                error = true;
                return -1;
            }
            double b = s.top();
            s.pop();
            //do operation on two values and add result to stack
            if(c == "+"){
                double res = b + a;
                s.push(res);
            }else if(c == "-"){
                double res = b - a;
                s.push(res);
            }else if(c == "*"){
                double res = b * a;
                s.push(res);
            }else if(c == "/"){
                double res = b / a;
                s.push(res);
            }else if(c == "^"){
                double res = pow(b, a);
                s.push(res);
            }
        }
        //if next input is not an operator
        else{
            //check if any non digits or non-decimals in string
            for(size_t i = 0; i < c.size(); ++i){
                //if string has non-decimal or non-digit character, it's not a valid operand
                if(!isdigit(c[i]) && c[i] != '.'){
                    error = true;
                    return -1;
                }
            }
            s.push((stod(c)));
        }
    }
    error = false;
	return s.top();
}
