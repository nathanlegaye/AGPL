//
//  tree.hpp
//  AGPL
//
//  Created by Nathan Legaye on 14/09/2020.
//  Copyright © 2020 Nathan Legaye. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std ;


// Structure d'un noeud avec une valeur, un pointeur vers le fils gauche et un autre pointeur vers le fils droit
struct conc_t {
    void *left_son ;
    void *right_son ;
    
} ;
using concp_t = conc_t* ;

struct union_t {
    void *left_son ;
    void *right_son ;
} ;
using unionp_t = union_t* ;

struct star_t {
    void *stare ;
} ;
using starp_t = star_t* ;

struct un_t {
    void *une ;
} ;
using unp_t = un_t* ;

struct atom_t {
    string cod ;
    int act ;
    string type ;
} ;
using atomp_t = atom_t* ;


// On défini le nom node_t comme un nom de variable étant automatiquement un pointeur sur n'importe quel ctree_t

struct rule_t {
    char v ;
    void *node ;
} ;
using rulep_t = rule_t* ;


// On défini visit_node_f comme étant un nom de paramètre composé d'une fonction et d'un char, si on utilise ce paramètre dans une fonction, ce sera donc équivalent à placer en paramètre une fonction et un char
using visit_node_f = void(*)(char) ;
void afficher(char v) ;

node_t create_ctree(char v, node_t left, node_t right) ;
void delete_ctree(node_t root) ;
void prefix(node_t root, visit_node_f f) ;
void infix(node_t root, visit_node_f f) ;
void postfix(node_t root, visit_node_f f) ;


void GenConc(nodep_t left_son, nodep_t right_son) ;

void GenUnion(nodep_t left_son, nodep_t right_son) ;
void GenStar(nodep_t son) ;
void GenUn(nodep_t son) ;
void GenAtom(cod,action,type) ;

void ImprimArbre(nodep_t);

#endif /* tree_hpp */
