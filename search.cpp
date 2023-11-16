// Do NOT add any other includes
#include "search.h"
//#include "Node.cpp"

SearchEngine::Node2::Node2(){
    book_code=-1;
    page=0;
    paragraph=0;
    sentence_no=0;
    sent="";
}

SearchEngine::Node2::Node2(int b_code, int pg, int para, int s_no,string s){
    book_code=b_code;
    page=pg;
    paragraph=para;
    sentence_no=s_no;
    sent=s;
}

SearchEngine::SearchEngine(){

}

SearchEngine::~SearchEngine(){
    for(int i=0;i<kg.size();i++){
        delete kg[i];
    }
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    Node2* gg=new Node2(book_code,page,paragraph,sentence_no,sentence);
    kg.push_back(gg);
}

Node* SearchEngine::search(string pattern, int& n_matches){
    Node* head=new Node();
    head->book_code=-1;
    head->right=NULL;
    head->left=NULL;
    Node* t1=head;
    string sen;
    int m,n;
    for(int k=0;k<kg.size();k++){
        sen=kg[k]->sent;
        m=pattern.size();
        n=sen.size();
        int lps[m];
        int len=0;
        lps[0]=0;
        int i=1;
        char a1,b1;
        while(i<m){
            if(isupper(pattern[i])){
                a1=tolower(pattern[i]);
            }
            else{
                a1=pattern[i];
            }
            if(isupper(pattern[len])){
                b1=tolower(pattern[len]);
            }
            else{
                b1=pattern[len];
            }
            if(a1==b1){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int a,b;
        a=0;
        b=0;
        while(n-a>=m-b){
            if(isupper(sen[a])){
                a1=tolower(sen[a]);
            }
            else{
                a1=sen[a];
            }
            if(isupper(pattern[b])){
                b1=tolower(pattern[b]);
            }
            else{
                b1=pattern[b];
            }
            if(b1==a1){
                a++;
                b++;
            }
            if(b==m){
                t1->book_code=kg[k]->book_code;
                t1->offset=a-b;
                t1->page=kg[k]->page;
                t1->paragraph=kg[k]->paragraph;
                t1->sentence_no=kg[k]->sentence_no;
                t1->right=new Node();
                t1->right->right=NULL;
                t1->right->book_code=-1;
                t1->right->left=t1;
                t1=t1->right;
                n_matches++;
                b=lps[b-1];
            }
            else if(a<n && a1!=b1){
                if(b!=0){
                    b=lps[b-1];
                }
                else{
                    a++;
                }
            }
        }
    }
    if(t1->left!=NULL){
        t1->left->right=NULL;
        delete t1;
        return head;
    }
    else{
        delete head;
        return NULL;
    }
}
// int main(){
//     SearchEngine* s=new SearchEngine();
//     s->insert_sentence(1,1,1,1,"an anty anti nationalist");
//     int a=0;
//     Node* bh=s->search("An",a);
//     while(bh!=NULL){
//         cout<<bh->offset<<endl;
//         bh=bh->right;
//     }
//     cout<<a<<endl;
// }