// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class SearchEngine {
private:
    // You can add attributes/helper functions here
    class Node2{
        public:

            int book_code;
            int page;
            int paragraph;
            int sentence_no;
            string sent;
            Node2();
            Node2(int b_code, int pg, int para, int s_no,string s);
    };
    Node2* head1;

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
    vector<Node2*> kg;
};