#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <algorithm>

using namespace std;

// Function to count the number of set bits in the binary representation
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

// Function to convert a number to its binary representation as a string
string toBinaryString(int num, int num_bits) {
    string bin = bitset<10>(num).to_string();
    return bin.substr(10 - num_bits); // Adjust to the required number of bits
}

// Function to perform the Quine-McCluskey method
string simplifyBooleanFunction(const vector<int>& minterms, int num_variables) {
    unordered_set<int> minterm_set(minterms.begin(), minterms.end());
    vector<vector<string>> groups(num_variables + 1);

    for (const auto& minterm : minterms) {
        int num_ones = countSetBits(minterm);
        groups[num_ones].push_back(toBinaryString(minterm, num_variables));
    }

    vector<vector<string>> new_groups;
    while (true) {
        new_groups.clear();
        for (int i = 0; i < groups.size() - 1; ++i) {
            for (const auto& term1 : groups[i]) {
                for (const auto& term2 : groups[i + 1]) {
                    int diff_count = 0;
                    string combined_term = "";
                    for (int j = 0; j < term1.size(); ++j) {
                        if (term1[j] != term2[j]) {
                            diff_count++;
                            combined_term += '-';
                        } else {
                            combined_term += term1[j];
                        }
                    }
                    if (diff_count == 1) {
                        new_groups.push_back({ combined_term });
                        minterm_set.erase(stoi(term1, nullptr, 2));
                        minterm_set.erase(stoi(term2, nullptr, 2));
                    }
                }
            }
        }
        if (new_groups.empty()) {
            break;
        }
        groups.clear();
        groups.resize(num_variables + 1);
        for (const auto& term : new_groups) {
            groups[countSetBits(stoi(term[0], nullptr, 2))].push_back(term[0]);
        }
    }

    vector<string> prime_implicants(minterm_set.size());
    transform(minterm_set.begin(), minterm_set.end(), prime_implicants.begin(),
              [](int m) { return toBinaryString(m, num_variables); });

    string simplified_function;
    for (const auto& term : prime_implicants) {
        for (int i = 0; i < term.size(); ++i) {
            if (term[i] != '-') {
                simplified_function += (term[i] == '0') ? char('A' + i) + string("'") : char('A' + i);
            }
        }
        simplified_function += '+';
    }
    simplified_function.pop_back(); // Remove the last '+'
    return simplified_function;
}

int main() {
    int N; // Number of variables
    cout << "Enter the number of variables (N <= 10): ";
    cin >> N;

    vector<int> minterms;
    cout << "Enter minterm IDs (separated by spaces, enter -1 to finish): ";
    int id;
    while (cin >> id && id != -1) {
        minterms.push_back(id);
    }

    string simplified = simplifyBooleanFunction(minterms, N);
    cout << "Simplified Boolean function: " << simplified << endl;

    return 0;
}

