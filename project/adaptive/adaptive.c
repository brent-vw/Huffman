//
// Created by Brent Van Wynsberge on 5/11/17.
//

#include "adaptive.h"

/**
 * Zoek de gelinkte referentie naar de top
 * @param nng gelinkte lijst
 * @param node gezochte element
 * @return locatie in de gelinkte lijst
 */
order_node* find_node(order_node* nng, huff_node* node){
    order_node* current = nng;
    while (current->node!=node){
        current = current->next;
    }
    return current;
}

/**
 * We hebben nng gelezen, we maken nu een nieuwe top aan.
 * @param c het toe te voegen character
 * @param nng gelinkte lijst
 * @param nodes dictionary van bladeren
 * @param index de waarde gecast naar (unsigned char)
 */
void nng(char c, order_node* nng, order_node** nodes, int index){
    //Maak de nieuwe ouder van nng
    huff_node* node = new_node();
    node->weight = 1;
    node->left = nng->node;
    node->parent = nng->node->parent;
    node->depth = nng->node->depth;

    //Maak de nieuwe top voor het nieuwe character
    huff_node* newChar = new_node();
    newChar->parent = node;
    newChar->weight = 1;
    newChar->value = c;
    newChar->depth = nng->node->depth+1;

    //Pas de referentie van nng aan in de boom.
    nng->node->parent = node;
    nng->node->depth++;

    //Rechterkind van de nieuwe ouder
    node->right = newChar;

    //Pas de ouder referentie aan
    if(node->parent){
        if(node->parent->left==nng->node){
            node->parent->left = node;
        } else {
            node->parent->right = node;
        }
    }

    //Maak gelinkte elementen voor de gelinkte lijst
    order_node* newParent = allocate_order_node(node);
    order_node*  newOrder = allocate_order_node(newChar);

    //Zet de nieuwe elementen in de gelinkte lijst
    newOrder->next = newParent;
    newParent->next = nng->next;
    nng->next = newOrder;

    //Pas de gewichten aan en herbalanceer
    if(newParent->node->parent){
        update(find_node(nng, newParent->node->parent), nodes, nng);
    }

    //Voeg de node toe aan het dictionary
    nodes[index] = newOrder;
}

/**
 * Pas de diepte aan van een gewijzigde node
 * @param node
 */
void makeDepth(huff_node* node){
    if(!node){
        return;
    }

    if(!node->parent){
        node->depth = 0;
    } else {
        node->depth = node->parent->depth+1;
    }
    makeDepth(node->left);
    makeDepth(node->right);
}

/**
 * Wissel 2 nodes om in de boom en de gelinkte lijst
 * @param o_node1 referentie naar de node in de gelinkte lijst
 * @param o_node2 referentie naar de node in de gelinkte lijst
 * @param nodes dictionary van de elementen van de lijst
 */
void swap(order_node* o_node1, order_node* o_node2, order_node** nodes){
    //Neem de nodes zelf
    huff_node* node1 = o_node1->node;
    huff_node* node2 = o_node2->node;

    //Wissel de referentie van de ouders
    if(node1->parent){
        if(node1->parent->left == node1){
            node1->parent->left = node2;
        } else {
            node1->parent->right = node2;
        }
    }

    if(node2->parent){
        if(node2->parent->left == node2){
            node2->parent->left = node1;
        } else {
            node2->parent->right = node1;
        }
    }

    //Wissel de referentie naar de ouders
    huff_node* oldParent = node1->parent;
    node1->parent = node2->parent;
    node2->parent = oldParent;

    //Pas de diepte van de nodes aan
    makeDepth(node1);
    makeDepth(node2);

    //Wissel de gelinkte elementen om
    o_node1->node = node2;
    o_node2->node = node1;

    //Pas de referenties in het dictionary aan
    if(!o_node1->node->left&&o_node1->node->weight>0) {
        nodes[(unsigned char) o_node1->node->value] = o_node1;
    }

    if(!o_node2->node->left&&o_node2->node->weight>0) {
        nodes[(unsigned char) o_node2->node->value] = o_node2;
    }
}

/**
 * Pas het gewicht van de nodes aan en herbalanceer indien nodig
 * @param node de aan te passen node
 * @param nodes dictionary van de nodes
 * @param nng de gelinkte lijst
 */
void update(order_node* node, order_node** nodes, order_node* nng){
    //De node referentie
    huff_node* h_n = node->node;

    //Zoek het element van hetzelfde gewicht met het hoogste ordenummer
    order_node* current = node;
    while(current->next&&current->next->node->weight<=node->node->weight){
        current = current->next;
    }

    //Incrementeer het gewicht
    node->node->weight++;

    //Wissel de nodes indien ze verschillend zijn en de node met het hoogste ordenummer niet de ouder is
    if(current!=node) {
        if (current->node != node->node->parent) {
            swap(node, current, nodes);
        }
    }

    //Als de node nog een ouder heeft, zoek deze en herhaal de operatie
    if(h_n->parent){
        //Ouder referentie
        huff_node* parent = h_n->parent;
        if(parent->weight<=h_n->weight){
            current = nng;
        }

        //Zoek de ouder in de gelinkte lijst
        while(current->next&&current->node!=parent){
            current = current->next;
        }

        //Update de ouder
        update(current, nodes, nng);
    }
}

/**
 * Schrijf een bit uit naar de buffer en flush hem indien hij vol is.
 * @param buffer de buffer
 * @param written hoeveel bits al weggeschreven werden
 * @param bit de te schrijven bit
 * @param fout pointer naar het uitvoerbestand
 */
void write_bit(char* buffer, size_t* written, char bit, FILE* fout){
    //schrijf de bit naar de buffer
    buffer[*written] = bit;

    //update de beschreven bits
    *written = *written + 1;

    //schrijf weg indien vol
    if(*written == 8){
        unsigned char out = (unsigned char) strtoul(buffer, NULL, 2);
        *written = 0;
        fwrite(&out, sizeof(unsigned char), 1, fout);
    }
}

/**
 * Schrijf de code van de huidige node weg
 * @param buffer de buffer
 * @param written hoeveel bits al weggeschreven werden
 * @param code de node waarvan de code weggeschreven moet worden
 * @param fout het uitvoerbestand
 */
void write_code(char *buffer, size_t *written, huff_node *code, FILE *fout) {
    //initialiseer de gegevens
    char out_code[code->depth+1];
    huff_node* current = code;

    //geen ouder
    if(code->parent==NULL){
        return;
    } else {
        int i = code->depth-1;
        while (current->parent){
            //schrijf het pad omhoog op
            if(current==current->parent->left){
                out_code[i--] = '1';
            } else {
                out_code[i--] = '0';
            }
            current = current->parent;
        }

        //sluit het array af
        out_code[code->depth] = '\0';
    }

    //schrijf de bits weg
    for (int i = 0; i < code->depth; ++i) {
        write_bit(buffer, written, out_code[i], fout);
    }
}

/**
 * Schrijf een node weg die nog niet in de boom voorkomt
 * @param buffer de buffer
 * @param written #weggeschreven bits
 * @param nng referentie naar de nng node
 * @param c het weg te schrijven karakter
 * @param fout uitvoerbestand
 */
void write_new(char *buffer, size_t *written, huff_node *nng, char c, FILE *fout) {
    //schrijf nng uit
    write_code(buffer, written, nng, fout);

    //Zet het karakter om naar zijn binaire vorm (om offsets mogelijk te maken)
    char out_code[9];
    sprintf(out_code, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(c));

    //schrijf de bits uit
    for (int i = 0; i < 8; ++i) {
        write_bit(buffer, written, out_code[i], fout);
    }
}

/**
 * Kijk of de boom onder de huidige node een geldige huffmanboom is
 * @param node de huidige wortel
 * @return true als de boom geldig is
 */
bool _valid(huff_node* node){
    //niets te checken
    if(!node){
        return true;
    }

    //kijk of de huidige tak aan de voorwaarde voldoet
    bool valid = true;
    if(node->left){
        valid &= node->left->depth == node->depth+1 && node->left->weight + node->right->weight == node->weight && node->right->depth == node->depth+1;
    }

    //check de kinderen
    return valid && _valid(node->left) && _valid(node->right);
}

/**
 * Zoek de wortel van de boom en check dan of de boom geldig is
 * @param nng pad naar de wortel
 * @return true als de boom geldig is
 */
bool check_tree(huff_node *nng) {
    huff_node* root = nng;
    while (root->parent){
        root = root->parent;
    }

    bool valid = true;
    if(root->left){
        valid &= root->left->depth == root->depth+1 && root->left->weight + root->right->weight == root->weight && root->right->depth == root->depth+1;
    }

    return valid && _valid(root->left) && _valid(root->right);
}

/**
 * Kijk of de nodes in de juiste volgorde zitten
 * @param nng gelinkte lijst
 * @return true als de lijst geldig is
 */
bool check_nodes(order_node *nng) {
    order_node* current = nng;
    while (current->next){
        if(current->next->node->weight<current->node->weight){
            return false;
        }
        current = current->next;
    }
    return true;
}

/**
 * Zoek de wortel, pas de referentie naar de variabele aan zodat die naar de wortel wijst
 * @param oldTree oude referentie
 * @param nng pad naar de wortel
 */
void update_tree(huff_node **oldTree, huff_node *nng) {
    huff_node* current = nng;
    while (current->parent){
        current=current->parent;
    }
    *oldTree = current;
}