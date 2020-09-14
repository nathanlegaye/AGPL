//
//  tree.cpp
//  AGPL
//
//  Created by Nathan Legaye on 14/09/2020.
//  Copyright © 2020 Nathan Legaye. All rights reserved.
//

#include "tree.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std ;

// Construction de l'arbre
ctreep_t create_ctree(char v, ctreep_t left, ctreep_t right) {
    // Allocation dynamique de mémoire
    ctree_t *root = new ctree_t ;
    // Attribution de la valeur
    root -> v = v ;
    // Etablissement du lien avec l'embranchement fils gauche
    root -> left_son = left ;
    // Etablissement du lien avec l'embranchement fils droit
    root -> right_son = right ;
    // On renvoi la structure noeud/fils gauche/fils droit entière
    return root ;
}

// Désallocation mémoire (suppression) de l'arbre
void delete_ctree(ctreep_t root) {
    // On vérifie si l'embranchement fils gauche existe bien et si oui on le supprime ainsi que le pointeur associé
    if (root -> left_son != nullptr) {
        // Fonction récurisve (s'appelle elle-même) qui supprime le noeud
        delete_ctree(root -> left_son) ;
    }
    // On vérifie si l'embranchement fils droit existe bien et si oui on le supprime ainsi que le pointeur associé
    if (root-> right_son != nullptr) {
        delete_ctree(root -> right_son) ;
    }
    // Suppresion du noeud (donc des pointeurs vers les fils)
    delete root ;
}

// Fonction d'affichage de la valeur de chaque noeud (on pourrait imaginer n'importe quelle action et pas seulement un simple affichage)
void afficher(char v) {
    cout << v << endl ;
}

// Lecture de l'arbre à partir de la racine
void prefix(ctreep_t root, visit_node_f f) {
    // On vérifie que le noeud existe bien
    if(root != nullptr) {
        f(root -> v) ;
        // Récursion pour afficher les valeurs des noeuds suivants
        prefix(root -> left_son, f) ;
        prefix(root -> right_son, f) ;
    }
}

void infix(ctreep_t root, visit_node_f f) {
    if(root -> left_son != nullptr)
        infix(root -> left_son, f) ;
    if(root -> right_son != nullptr)
        infix(root -> right_son, f) ;
    f(root -> v) ;
}

void postfix(ctreep_t root, visit_node_f f) {
    if(root -> left_son != nullptr)
        postfix(root -> left_son, f) ;
    f(root -> v) ;
    if(root -> right_son != nullptr)
        postfix(root -> right_son, f) ;
}



//void GenConc(P1, P2 : PTR) : PTR {
//    Var P : PTR ;
//    New (P, conc);
//    P↑.left := P1 ;
//    P↑.right := P2 ;
//    P↑.class := conc ;
//    GenConc := P ;
//}

void GenUnion(nodep_t left_son,nodep_t right_son) {
    
}
void GenStar(nodep_t node) {
    
}

void GenUn(nodep_t node) {
    
}

void GenAtom(COD=code,ACT=action(0),Atomtype=T ou NT) {
    
}

void ImprimArbre(nodep_t node, prof int) {
    k(1) int;
    prof++ ;  // On initialisera prof à zéro dans le main car c’est une procédure récursive ici
    for (k, k <= prof, k++)
        cout << ("---") ;
    switch (node->type) {
        case conc:
            cout << (">conc") >> endl ;
            ImprimArbre(node->left_son, prof);
            ImprimArbre(node->right_son, prof);
            break;
        case unio:
            cout << (">union") >> endl ;
            ImprimArbre(node->left_son, prof);
            ImprimArbre(node->right_son, prof);
            break;
        case un:
            cout << (">un") >> endl ;
            ImprimArbre(node->une, prof);
            break;
        case star:
            cout << (">star") >> endl ;
            ImprimArbre(node->stare, prof);
            break;
        case atome:
            if node.type="T"
                cout << "cod=node.cod, action=node.act, type=T" << endl ;
            else
                cout << "cod=node.cod, action=node.act, type=NT" << endl ;
        default:
            break;
    }
}
