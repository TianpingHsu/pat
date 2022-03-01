#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
map<char, char[7][5]> letters_graph;

bool is_letter(char  &c) {
    char *p = &c;
    if (*p >= 'A' && *p <= 'Z') {
        return true;
    } else {
        return false;
    }
}
int main() {
    for (int k = 0; k < 26; k++) {
        char c = k + 'A';
        char t[7][5];
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 5; j++) {
                scanf(" %c", &t[i][j]);
            }
        }
        memcpy(letters_graph[c][0], t[0], sizeof(char) * 7 * 5);
    }
    char skip_return;
    scanf("%c", &skip_return);
    string sentence;
    getline(cin, sentence);
    vector<string> lines;
    for (size_t i = 0; i < sentence.size(); i++) {
        string line;
        if (is_letter(sentence[i])) {
            do {
                line.push_back(sentence[i++]);
            } while(is_letter(sentence[i]));
            lines.push_back(line);
        }
    }

    for (size_t line_idx = 0; line_idx < lines.size(); line_idx++) {
        string current_line = lines[line_idx];
        for (int i = 0; i < 7; i++) {
            for (size_t letter_idx = 0; letter_idx < current_line.size(); letter_idx++) {
                for (int j = 0; j < 5; j++) {
                    printf("%c", letters_graph[current_line[letter_idx]][i][j]);
                }
                if (lines.size() == 1 && i == 6 && letter_idx == current_line.size() - 1) return 0;
                printf("%c", letter_idx == current_line.size() - 1 ? '\n' :' ');
            }
        }
        if (line_idx != lines.size() - 1 && lines.size() != 1) {
            printf("\n");
        }
    }
}
