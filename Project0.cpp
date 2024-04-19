/* CSI 3334
 * Project 0 -- Undo Redo
 * Filename: driver-proj0.cpp
 * Student name: Eugene Pak
 */
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
#include <sstream>

using namespace std;

/* main
 *  parameters:
 *      argc -- the number of arguments from the command line
 *      argv -- the command line argument values
 *  return value: 0 (indicating a successful run)
 *
 *  Takes in command arguments to determine which stack a word will go to
 */
int main(int argc, char** argv) {
    // these are the two stacks used to store the typed words and the undone
    // words
    stack<string> typing, undo;
    stack<string> output, mistake;
    stack<int> holder, reverse;
    int num;
    char command;
    string word;

    cin >> num;
    if (num < 1000 && num > 0) {
        for (int i = 0; i < num; i++) {
            cin >> command;
            if (command == 't') {
                cin >> word;
                typing.push(word);
            }
            else if (command == 'u') {
                if (!typing.empty()) {
                    word = typing.top();
                    typing.pop();
                    undo.push(word);
                }
                else {
                    mistake.push("nothing to undo on command ");
                    holder.push(i+1);
                }
            }
            else if (command == 'r') {
                if (!undo.empty()) {
                    word = undo.top();
                    undo.pop();
                    typing.push(word);
                }
                else {
                    mistake.push("nothing to redo on command ");
                    holder.push(i+1);
                }
            }
            else {
                mistake.push("nothing to undo on command ");
                holder.push(i+1);
            }
        }

        if (!mistake.empty()){
            num = mistake.size();
            for (int i = 0; i < num; i++) {
                output.push(mistake.top());
                mistake.pop();
                reverse.push(holder.top());
                holder.pop();
            }
            num = output.size();
            for (int i = 0; i < num; i++) {
                cout << output.top();
                cout << reverse.top() << endl;
                output.pop();
                reverse.pop();
            }
        }

        num = typing.size();
        for (int i = 0; i < num; i++) {
            output.push(typing.top());
            typing.pop();
        }
        num = output.size();
        for (int i = 0; i < num; i++) {
            if ((i + 1) == num) {
                cout << output.top();
            }
            else {
                cout << output.top() << " ";
            }
            output.pop();
        }
        cout << endl;

        num = undo.size();
        for (int i = 0; i < num; i++) {
            output.push(undo.top());
            undo.pop();
        }
        num = output.size();
        for (int i = 0; i < num; i++) {
            if (i + 1 == num) {
                cout << output.top();
            }
            else {
                cout << output.top() << " ";
            }
            output.pop();
        }
        cout << endl;
    }
    return 0;
}