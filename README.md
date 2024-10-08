# Prova Finale di Algoritmi e Principi dell'Informatica - A.A. 2020-2021

[![License: GPL v2](https://img.shields.io/badge/License-GPL_v2-blue.svg)](https://github.com/AuroraTes/Progetto-Algoritmi-e-Principi-dell-Informatica/blob/main/LICENSE)

Prova finale di algoritmi e principi dell'informatica per l'anno accademico 2020-2021.

Docente: Martineghi Davide

**Valutazione**: 30/30

## Obiettivo e Specifiche del progetto

Realizzare un programma in C per la gestione di una classifica tra grafi diretti pesati.
La classifica tiene traccia dei k "migliori" grafi.

Il programma non solo deve produrre un output corretto, ma deve rispettare dei vincoli di memoria e tempo CPU.
La valutazione è immediatamente calcolate mediante 3 batterie di test:
- La prima vale 18 punti (pass or fail).
- La seconda fino a 12 punti (6 test da 2 punti ognuno)
- L'ultima per la lode

Di seguito la tabella di valutazione riferita al mio progetto:

| Valutazione |       Esito        |
|-------------|:------------------:|
|     18      | :white_check_mark: |
|     20      | :white_check_mark: |
|     22      | :white_check_mark: |
|     24      | :white_check_mark: |
|     26      | :white_check_mark: |
|     28      | :white_check_mark: |
|     30      | :white_check_mark: |
|     30L     |        :x:         |
Questi risultati possono variare a seconda della potenza di calcolo della macchina.

La specifica completa del progetto è disponibile [qui](https://github.com/AuroraTes/Progetto-Algoritmi-e-Principi-dell-Informatica/blob/main/Documents/Specifiche%20Prova.pdf).
Il codice sorgente è disponibile [qui](https://github.com/AuroraTes/Progetto-Algoritmi-e-Principi-dell-Informatica/blob/main/SourceCode.c).

## Scelte progettuali

Questo codice implementa un sistema per la gestione di grafi e per il calcolo del percorso minimo tramite l'algoritmo di Dijkstra, con l'obiettivo di calcolare il costo cumulativo dei cammini minimi all'interno di ogni grafo aggiunto e mantenere una lista dei grafi ordinati per costo. Le principali scelte progettuali prese sono le seguenti:

1. **Struttura Dati per Grafi e Costi**
    - Uso di una matrice di adiacenza: I grafi sono rappresentati tramite una matrice di adiacenza mat, che è un modo comune per gestire grafi  densi.La matrice mat viene allocata dinamicamente con dimensione d x d, dove d rappresenta il numero di nodi del grafo.
    - Struttura per memorizzare i costi: Il programma utilizza una struttura infografo per memorizzare il costo cumulativo di ciascun grafo e il suo identificatore (id_grafo). Questa struttura è memorizzata in un array dinamico vett_costi.

2. **Algoritmo per il calcolo dei cammini minimi: Dijkstra**
    - Uso dell'algoritmo di Dijkstra: La funzione Dijkstra implementa l'algoritmo di Dijkstra per trovare i cammini minimi a partire dal nodo 0 del grafo e sommare i costi per tutti i nodi raggiungibili. Questo metodo è appropriato per grafi con pesi positivi, come nel caso di questo codice.
    - Uso di una coda semplice (array coda) per tenere traccia dei nodi non visitati: La coda tiene traccia dei nodi che sono ancora in gioco per l'aggiornamento delle distanze minime, ma si basa su un array di dimensioni fisse, piuttosto che una struttura dati ottimizzata come un heap binario. 

3. **Gestione dei grafi: aggiunta e analisi**
    - Funzione AggiungiGrafo: Questa funzione gestisce l'inserimento di un nuovo grafo leggendo la matrice di adiacenza da input. Viene poi calcolato il costo cumulativo dei cammini minimi tramite Dijkstra e questo costo viene aggiunto alla lista vett_costi.
    - Conversione manuale delle stringhe: La funzione conversione gestisce la conversione delle stringhe in numeri interi, simulando il comportamento della funzione atoi. Tuttavia, anziché usare atoi, il codice implementa una versione più manuale della conversione, che aggiunge complessità senza un chiaro beneficio.
    - Parsing della matrice da input: L'input viene fornito come una stringa contenente numeri e virgole, che viene analizzata carattere per carattere per costruire la matrice di adiacenza.

4. **Ordinamento dei grafi per costo**
    - Ordinamento con qsort: I grafi, una volta memorizzati in vett_costi, sono ordinati usando la funzione qsort in base al loro costo, utilizzando la funzione di comparazione ordinacosti. Questo permette di mantenere una classifica dei grafi con i costi più bassi.

5. **Top-K**
    - Selezione dei K grafi con il costo minore: La funzione TopK è progettata per stampare gli identificatori dei k grafi con il costo più basso. Il programma considera il caso in cui ci siano meno di k grafi e gestisce il caso in cui i grafi abbiano costi duplicati, evitando di stampare grafi con lo stesso costo consecutivamente.

    
> [!NOTE]
> I tempi di esecuzione sono molto alti siccome il programma è stato eseguito in una macchina virtuale per questo test.

## Strumenti utilizzati

| Descrizione         | Strumento                                  |
|---------------------|--------------------------------------------|
| IDE                 | [CLion](https://www.jetbrains.com/clion/)  |
| Compilatore         | [gcc](https://gcc.gnu.org/)                |
| Misurazione memoria | [Valgrind - Massif](https://valgrind.org/) |
| Sistema operativo   | Windows 10 e Debian 11                     |

## Copyright e licenza

Il progetto è distribuito sotto [licenza GPL v2](https://github.com/AuroraTes/Progetto-Algoritmi-e-Principi-dell-Informatica/blob/main/LICENSE), si applicano le limitazioni descritte in tale licenza.

