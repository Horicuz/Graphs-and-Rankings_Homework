# Grafuri si clasamente ~ TEMA 2 PROIECTAREA ALGORITIMILOR

## Setup ~ COMPLETE
Am realizat setup-ul temei:

-Am creat folderul proiectului in care am introdus checkerul impreuna cu fisierele de intrare/iesire.  
-Am creat Makefile-ul corespunzator checkerului.  

## TASK 1 ~ COMPLETE
-Am citit cele 32 de echipe din fisierul de input.  
-Am realizat meciurile 2 cate 2, adaugand castigatorii si invinsii in doua cozi diferite.  
-Am repetat procesul de a lua 2 echipe din coada de castigatori, de a pune invisul in coada de invinsi si castigatorul la loc in coada de castigatori, pana s-au jucat toate meciurile.  
-In timpul acestui proces am modificat matricea de adiacenta a grafului, unde daca j il bate pe i, atunci de la varful i la j exista o muchie.  
-Am afisat matricea de adiacenta la final.  

## TASK 2 ~ COMPLETE
-Dupa ce am aflat toate rezultatele, toate echipele sunt salvate in coada de losers, astfel am putut elibera coada winner.  
-Stiind ca sunt 32 de echipe am scos din coada si am eliberat in acelasi timp nodurile cu echipele pentru care am calculat Pr si l-am afisat alaturi de numele respectiv (float cu 4 zecimale).  
-Ordinea dorita facea referire la ordinea din coada de loseri unde rear = winner si front = primul loser.  
-La final am eliberat memoria si pentru matricea de adiacenta.  
 

## INFO
-Am lucrat cu un singur set de noduri, mutandu-le dintr-o coada in alta, acest lucru avand ca efect nefunctionalitatea functiei isEmptyQ().  
-Fiecare nod adaugat la finalul unei cozi era un nod deja existent, astfel ca avea ocupata deja pozitia de ->next. Cu alte cuvinte, cand ajungeam cu un singur element in coada (rear = front), front->next nu era null, ci "pointa" catre o valoare, iar eliberarea pointerului ->next ducea la pierderea memoriei nodului care se alfa in cealalta coada.(Losers).    
-Am realizat mai multe functii cum ar fi CompareTeams 1,2,3 si m-am folosit de functiile specifice pentru cozi.  