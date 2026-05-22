# 🏆 O Grande Desafio Final: Sistema de Gerenciamento da Guilda (S.G.G)

> **Atenção, Aventureiros Veteranos!** > O Reino está prosperando, mas a nossa Taverna virou um caos. A Guilda cresceu tanto que pergaminhos de papel não dão mais conta. O Grão-Mestre convocou os melhores grupos de programadores para uma missão de nível épico: **Construir o Sistema de Gerenciamento da Guilda em C**. 
> 
> Esta missão vale **5,0 pontos** (Metade da sua alma neste semestre!) e exigirá trabalho em equipe, lógica afiada e controle absoluto da Memória RAM.

---

## 🗺️ O Escopo da Missão (Módulos do Sistema)

O sistema de vocês deverá rodar no terminal através de um grande "Menu Principal" (`do-while` com `switch`), conectando quatro grandes módulos. Cada integrante do grupo deve assumir a responsabilidade por pelo menos um módulo.

### ⚔️ Módulo 1: O Arsenal da Guilda (Vetores e Structs)
O catálogo de equipamentos padrão vendidos na Taverna. O estoque base é fixo.
* **Estrutura Exigida:** Um **Vetor de Structs** (ex: tamanho 10).
* **Funcionalidades:**
  * Visualizar o catálogo completo (Nome da arma, dano e preço).
  * **Lógica Avançada:** O sistema deve ter uma opção para listar as armas **ordenadas pelo preço** (do mais barato para o mais caro), usando um algoritmo de ordenação (ex: *Bubble Sort*).

### 🏥 Módulo 2: A Fila da Enfermaria (Fila / Queue Dinâmica)
Aventureiros voltam feridos das missões e o Clérigo precisa atendê-los.
* **Estrutura Exigida:** Uma **Fila** com alocação dinâmica (Regra FIFO: Entra no fim, sai no início).
* **Funcionalidades:**
  * **Adicionar Ferido:** Pede o nome do herói e insere no fim da fila com `malloc`.
  * **Curar Herói:** Atende quem está no início da fila, exibe uma mensagem de cura e libera a memória com `free`.
  * Visualizar quem está aguardando na fila.

### 📜 Módulo 3: O Mural de Missões (Lista Simplesmente Encadeada)
O quadro onde aldeões penduram pedidos de ajuda. Missões chegam e são resolvidas a todo momento.
* **Estrutura Exigida:** Uma **Lista Simplesmente Encadeada** dinâmica.
* **Funcionalidades:**
  * **Afixar Missão:** Adiciona um novo nó contendo o nome da missão e o Nível de Dificuldade (ex: 1 a 5).
  * **Concluir Missão:** O usuário digita o nome da missão, o sistema busca na lista, remove exatamente aquele nó do meio da corrente, refaz a ligação dos ponteiros e limpa a memória com `free`.
  * **Lógica Avançada:** Uma opção de **Busca por Dificuldade**, onde o usuário digita um nível (ex: 3) e o sistema imprime apenas as missões daquele nível.

### 🧹 Módulo 4: O Fechamento da Taverna (Prevenção de Memory Leak)
A Regra de Ouro do código profissional. O programa não pode ser encerrado deixando lixo na memória RAM.
* **Ação Exigida:** A opção "0 - Fechar Sistema" do Menu Principal não pode apenas dar um `return 0`. Ela deve chamar funções de limpeza que varram a Fila da Enfermaria e a Lista de Missões, executando o `free` em todos os nós sobreviventes antes do programa fechar.

---

## 🛠️ Regras de Ouro (Exigências Técnicas)

1. **Modularização Obrigatória:** O projeto **NÃO** pode ser entregue em um único arquivo `main.c`. Vocês devem dividir o código em Bibliotecas (arquivos `.h` e `.c` para Arsenal, Enfermaria e Mural). Usem o `main.c` apenas para o Menu Principal.
2. **Sistema à Prova de Goblins:** O programa não pode "crashar". Façam a limpeza de buffer correta (`getchar()`) ao ler strings após números e validem as opções do menu (se o menu vai de 0 a 4 e o usuário digitar 9, mostre "Opção Inválida" sem quebrar o loop).

---

## 📊 Tabela de Avaliação (A Rubrica de 5,0 Pontos)

| Critério de Avaliação | Pontuação Máxima | O que o Mestre vai avaliar? |
| :--- | :---: | :--- |
| **1. Estruturas de Dados Nucleares** | **1,5 pts** | O Vetor, a Lista Simples e a Fila foram implementados corretamente? A inserção e remoção respeitam as regras físicas dos ponteiros? |
| **2. Gerenciamento de Memória (Sem Leaks)** | **1,0 pt** | O `malloc` foi validado? O `free` foi usado corretamente ao curar heróis, concluir missões e, **principalmente**, ao fechar o sistema? |
| **3. Lógica Aplicada (Ordenação e Filtros)** | **1,0 pt** | A ordenação de preços no Arsenal funciona? O filtro por Nível de Dificuldade no Mural exibe apenas os itens corretos? |
| **4. Modularização e Código Limpo** | **1,0 pt** | O projeto foi separado em arquivos `.h` e `.c` corretamente? As variáveis e funções têm nomes que fazem sentido? O código está indentado? |
| **5. Robustez e Interface (UX)** | **0,5 pt** | O menu é fácil de entender? O sistema sobrevive a um usuário digitando números errados ou tentando remover itens de listas que já estão vazias? |
| **TOTAL** | **5,0 pts** | *Boa sorte! Confiem na lógica e desenhem as setas no papel antes de codar!* |
