/*
 * Feito por:
 *          Thiago Henrique Domingues Botelho - 0041149
 *          Marcus Vinícius Braga Terçariol da Silva - 0040889
 */

#include "avlTree.h"
#include "../helps.h"

void avlTree::run(vector<string> keyWords,ifstream &file){
    this->insertKeyWords_avl(keyWords);
    this->searchWords(file);
    printf("ÍNDICE REMISSIVO \n");
    this->displayInOrden(this->getRoot());
    exportIndexTxt(sortKeywordsAlphabetical(keyWords));
}

/*
 * Insere as palavras chaves nos nós da arvore e realiza a busca no arquivo de texto
 * @param
 *       vector<string> keyWords: Vetor de palavras chaves
 *       ifstream& file: arquivo que contém o texto que será lido
 */
double avlTree::benchmarkAVL(vector<string> keyWords, ifstream &file) {
    chrono::time_point<std::chrono::system_clock> start, end;
    start = chrono::system_clock::now();

    insertKeyWords_avl(std::move(keyWords));
    searchWords(file);
    end = std::chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = runtime(start, end);
    return elapsed_seconds.count();
}

/*
 * Insere as palavras chaves na arvore
 * @param
 *      vector<string> keyWords vetor de palavras chaves
 */
void avlTree::insertKeyWords_avl(vector<string> keyWords) {
    for (const auto &item : keyWords) {
        if (item.size() >= 4)
            this->root = insert_avl(this->getRoot(), item);
    }
}

/*
 * Imprime a arvóre na seguinte ordem: ESQUERDA - RAIZ - DIREITA.
 * Recebe como parámetro inicial a raiz da arvóre
 * @param
 *      Leaf *n rAIZ
 */
void avlTree::displayInOrden(Leaf *n) {
    if (n != nullptr) {
        if (n->getExistingLines() != nullptr) {
            displayInOrden(n->getLeft());
            cout << "\t" << n->getKey() << "\t";
            n->displayTotalLines();
            cout << endl;
            displayInOrden(n->getRight());
        }
    }
}

/*
 * Realiza a busca das palavras chaves em um arquivo texto
 * @param ifstream &file arquivo que contém o texto a ser lido
 * @param
 *         ifstream &file Arquivo txt que contém o texto
 */
void avlTree::searchWords(ifstream &file) {
    if (this->root != nullptr) {
        string line;
        int numLine = 1;

        // Retorna o ponteiro de leitura para o inicio do arquivo
        file.seekg(0);
        while (!file.eof()) {
            getline(file, line);
            std::vector<std::string> words{split(line, ' ')};

            for (const auto &item : words) {
                Leaf *temp = search(this->root, item);
                if (temp != nullptr && item.size() >= 4 && temp->getKey() == item) {
                    temp->setNewLine(numLine);
                }
            }
            numLine++;
        }
    }
}

/*
 * Verifica se determinada palavra está na arvore. Caso esteja retorna o seu nó, se não retorna nullptr
 * @param
 *      Leaf *l Raiz
 *      string s String a ser buscada
 */
Leaf *avlTree::search(Leaf *l, string s) {
    if (l == nullptr || l->getKey() == s)
        return l;

    if (s > this->root->getKey())
        return search(l->getRight(), s);

    if (s < this->root->getKey())
        return search(l->getLeft(), s);
};

/*
 * Insere um novo elemento na arvore AVL
 * @param
 *      Leaf *n
 *      const string &new_key
 */
Leaf *avlTree::insert_avl(Leaf *n, const string &new_key) {
    if (n == nullptr)
        return new Leaf(new_key);
    if (new_key < n->getKey()) {
        n->setLeft(insert_avl(n->getLeft(), new_key));
    } else if (new_key > n->getKey()) {
        n->setRight(insert_avl(n->getRight(), new_key));
    } else
        return n;

    if (n->getLeft() == nullptr || n->getRight() == nullptr)
        n->setHeight(1);
    else
        n->setHeight(1 + maxNumber(n->getLeft()->getHeight(), n->getRight()->getHeight()));

    int balance = heightDifference(n);

    if (balance > 1 && new_key < n->getLeft()->getKey())
        return rightRotate(n);

    // Right Right Case
    if (balance < -1 && new_key > n->getRight()->getKey())
        return leftRotate(n);

    // Left Right Case
    if (balance > 1 && new_key > n->getLeft()->getKey()) {
        n->setLeft(leftRotate(n->getLeft()));
        return rightRotate(n);
    }

    // Right Left Case
    if (balance < -1 && new_key < n->getRight()->getKey()) {
        n->setRight(rightRotate(n->getRight()));
        return leftRotate(n);
    }

    return n;
}

/*
 * Retorna o fator de balanceamento que é a diferença da altura entre dois nós.
 * @param
 *      Leaf *n
 */
int avlTree::heightDifference(Leaf *n) {
    if (n == nullptr)
        return 0;

    if (n->getLeft() == nullptr || n->getRight() == nullptr)
        return 1;;

    return n->getLeft()->getHeight() - n->getRight()->getHeight();
}

/*
 * Realiza a rotação do nó para a direita
 * @param
 *      Leaf *y
 */
Leaf *avlTree::rightRotate(Leaf *y) {
    Leaf *x = y->getLeft();
    Leaf *T2 = x->getRight();

    // Perform rotation
    x->setRight(y);
    y->setLeft(T2);

    // Update heights
    y->setHeight(1 + maxNumber(y->getLeft()->getHeight(), y->getRight()->getHeight()));
    x->setHeight(1 + maxNumber(x->getLeft()->getHeight(), x->getRight()->getHeight()));

    // Return new root
    return x;
}

/*
 * Realiza a rotação do nó para a esquerda
 * @param
 *      Leaf *y
 */
Leaf *avlTree::leftRotate(Leaf *y) {
    Leaf *x = y->getRight();
    Leaf *T2 = x->getLeft();

    // Perform rotation
    x->setRight(T2);
    y->setLeft(x);

    // Update heights
    y->setHeight(1 + maxNumber(y->getLeft()->getHeight(), y->getRight()->getHeight()));
    x->setHeight(1 + maxNumber(x->getLeft()->getHeight(), x->getRight()->getHeight()));

    // Return new root
    return y;
}

/*
 * Exporta o indice remissivo em um arquivo txt
 * @param
 *      vector<string> sort_keywords Palavras chaves em ordem alfabetica
 */
void avlTree::exportIndexTxt(vector<string> sort_keywords) {
    // Definição da tabela
    fort::table table;
    table.set_border_style(FT_PLAIN_STYLE);
    table.row(0).set_cell_text_align(fort::text_align::center);
    table.column(1).set_cell_text_align(fort::text_align::center);
    std::cout << table.to_string() << std::endl;

    printf("ÍNDICE REMISSIVO \n");
    table << fort::header << "Palavra chave" << "Linhas" << fort::endr;

    std::string content;

    for (const auto &keyword : sort_keywords) {
        Leaf *node = this->search(this->root, keyword);
        if (node != nullptr) {
            int *existingLines = node->getExistingLines();
            table << node->getKey();

            for (int i = 0; i < node->getTotalLines(); ++i)
                table << existingLines[i];

            table << fort::endr;
        }
    }
    ofstream file;
    string path = "../outputs/indices_remisivo/index_avl.txt";
    file.open(path, ios::app);
    file << "Indice remissivo - AVL" <<endl;
    file << table.to_string() <<endl;
}