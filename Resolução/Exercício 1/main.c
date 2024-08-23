#include <stdio.h>
#include <string.h>

// tamanho da pilha
#define TAMANHO_MAXIMO 10 

// define a estrutura do endereco da pagina e o tipo de conexao
struct pagina {
  char endereco[30]; // url
  int tipoConexao; // 1 = http , 2= https
};

// define a estrutura da pilha
struct Pilha {
  struct pagina paginas[TAMANHO_MAXIMO]; // array de paginas
  int topo; // variavel topo para rastrear o elemento no topo
};

// funcao para inicializar a pilha
void inicializarPilha(struct Pilha *pilha) {
  pilha->topo = -1; // topo = -1 para indicar que a pilha esta vazia
}

// funcao para ver se pilha esta cheia
int estaCheia(struct Pilha *pilha) {
  return pilha->topo ==
         TAMANHO_MAXIMO -1; // ve se alcancou o tamanho maximo
}

// funcao para verificar se esta vazia
int estaVazia(struct Pilha *pilha) {
  return pilha->topo == -1; // verifica se o topo é -1
}

// funcao para inserir uma pilha
void empilhar(struct Pilha *pilha, struct pagina p) {
  if (estaCheia(pilha)) {
    printf("A pilha está cheia. Não é possível inserir a página.\n");
  } else {
    pilha->paginas[++(pilha->topo)] = p;
    printf("Página '%s' adicionada à pilha.\n", p.endereco);
  }
}

// funcao para remover uma pagina
struct pagina desempilhar(struct Pilha *pilha) {
  if (estaVazia(pilha)) {
    printf("A pilha está vazia. Não é possível remover uma página.\n");
    struct pagina paginaVazia = {
        "", -1}; // cria uma pagina vazia para retornar
    return paginaVazia;
  } else {
    return pilha->paginas[(pilha->topo)--]; // retorna a pagina do topo
    // decrementa o índice do topo
  }
}

// funcao para imprimir a pilha
void imprimirPilha(struct Pilha *pilha) {
  if (estaVazia(pilha)) {
    printf("A pilha está vazia.\n");
  } else {
    printf("Elementos na pilha:\n");
    for (int i = pilha->topo; i >= 0;
         i--) {
      printf("Endereço: %s, Tipo de Conexão: %d\n", pilha->paginas[i].endereco,
             pilha->paginas[i].tipoConexao);
    }
  }
}

int main() {
  struct Pilha pilha;       // variavel to tipo pilha
  inicializarPilha(&pilha); // inicializa para usar

  // cria e adiciona
  struct pagina pagina1 = {"www.exemplo.com", 1};
  struct pagina pagina2 = {"www.teste.com", 2};
  struct pagina pagina3 = {"www.site.com", 1};

  // empilha
  empilhar(&pilha, pagina1);
  empilhar(&pilha, pagina2);
  empilhar(&pilha, pagina3); 

  imprimirPilha(&pilha); // imprime

  struct pagina paginaRemovida =
      desempilhar(&pilha); // remove e retorna a pagina removida
  printf("Página removida: %s\n", paginaRemovida.endereco);

  imprimirPilha(&pilha); // imprime

  return 0;
}
