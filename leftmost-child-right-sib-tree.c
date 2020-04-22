#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    char letter;
    int is_word;
    struct NODE *leftmost_child, *right_sib, *parent;
};

typedef struct NODE *pNODE;


//create the empty tree
pNODE create_tree() {
    pNODE root = malloc(sizeof(struct NODE));
    root->leftmost_child = NULL;
    root->parent = NULL;
    return root;
}

pNODE append_child(pNODE _parent, char _letter, int _isword) {
    pNODE ph = _parent;
    if(ph->leftmost_child == NULL) {
        ph->leftmost_child = malloc(sizeof(struct NODE));
        ph->leftmost_child->parent = ph;
        ph = ph->leftmost_child;
        ph->letter = _letter;
        ph->is_word = _isword;
        ph->leftmost_child = NULL;
        ph->right_sib = NULL;
        return ph;
    }
    else {
        pNODE php_p = ph;
        ph = ph->leftmost_child;
        while ( ph->right_sib != NULL) {
            ph = ph->right_sib;
        }
        ph->right_sib = malloc(sizeof(struct NODE));
        ph->right_sib->parent = php_p;
        ph = ph->right_sib;
        ph->letter = _letter;
        ph->is_word = _isword;
        ph->leftmost_child = NULL;
        ph->right_sib = NULL;
        return ph;
    }
}

void insert_word(pNODE root, char *word) {
    pNODE ph;
    int is = 0;
    //base case
    if(*(word + 1) == '\0') {
        ph = root->leftmost_child;
        while (ph  != NULL )
        {   
            if(ph->letter == *(word)) {
                ph->is_word = 1;
                return;
            }
            ph = ph->right_sib;
        }
        ph = append_child(root, *word, 1);
        return;        
    }
    else {     //inductive case
        ph = root->leftmost_child;
        while (ph  != NULL )
        {   
            if(ph->letter == *(word)) {
                is = 1;
                break;
            }
            ph = ph->right_sib;
        }
        if(is == 0) {
            ph = append_child(root, *word, 0);
        }
        insert_word(ph, (word + 1));
    }
}

int check_word(pNODE root, char *word) {
    //base_case
    pNODE ph = root->leftmost_child;
}

int main() {
    pNODE fam = create_tree();
    insert_word(fam, "ayush");
    insert_word(fam, "mona");
    insert_word(fam, "omkar");
    insert_word(fam, "hansi");

    if(check_word(fam, "ayush")) {
        puts("Yes ayush is in the fam tree!");
    }

    getchar();

}