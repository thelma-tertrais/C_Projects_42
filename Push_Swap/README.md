*This activity has been created as part of the 42 curriculum by ttertrai and pthevaku.*

## Description

Push_swap is a sorting algorithm project from 42 school. The constraint is unusual: you have two stacks and a fixed set of operations, and your only way to interact with the numbers is to push, swap, or rotate elements between the two stacks. No random access, no indexing, no comparisons outside of what you implement yourself.
The challenge has two layers. The first is correctness — your program must always produce a valid sorted stack no matter what input it receives, including duplicates (which are forbidden and must be detected), non-numeric input, or an already sorted list. The second layer is performance — the fewer operations your program outputs, the better your grade.
This forces you to actually think about algorithmic complexity. A naive approach like selection sort works perfectly for small inputs but becomes catastrophically slow on 500 numbers. To hit the performance thresholds, you need a smarter strategy that thinks in chunks or bits rather than individual comparisons.
Beyond the algorithm itself, the project teaches you to manage data structures in C from scratch. There is no standard library sort, no built-in stack type — you build your linked lists, your push and rotate operations, and your entire sorting logic by hand. Every memory allocation must be handled and freed correctly.
It is one of the first projects at 42 where the gap between a working solution and an efficient solution is large enough to matter, which makes it a good introduction to thinking about performance as a real constraint rather than an afterthought.

## Instructions

Selection sort
The algorithm works in two phases.
Phase 1 — push to stack B in decreasing order
Each number gets an index from 0 (smallest) to n-1 (largest). We scan stack A and push the element with the highest remaining index to stack B first, then the second highest, and so on. If the current head isn't the one we want, we rotate A until it is.
Phase 2 — rebuild stack A
Once stack B is full, we push everything back to A one by one. Since B has the largest index on top, each pa places elements in increasing order — smallest ends up on top, largest on the bottom.
Why it's simple but slow
For each of the n elements we may need to rotate through the entire stack to find it, giving O(n²) operations. It works well for small inputs (≤ 10 numbers) but is too slow for 100 or 500 numbers.

Chunk-based sorting
The algorithm works in two phases.
Phase 1 — split into chunks
Each number gets an index from 0 (smallest) to n-1 (largest). The stack is divided into chunks of roughly √n numbers. Numbers belonging to the current chunk are pushed to stack B one by one. Within each chunk, numbers in the lower half are rotated to the bottom of B so that B stays roughly sorted from top to bottom.
Phase 2 — rebuild stack A
We repeatedly find the position of the next number to place (starting from the largest index down to 0), rotate B to bring it to the top, then push it back to A. Since we always push in decreasing order, stack A ends up sorted ascending from top to bottom.
Why it's efficient
Instead of comparing every element against every other (O(n²)), we only move elements in bulk by chunk, which gets close to O(n log n) in practice. For 500 numbers it typically uses around 5500 operations.

Radix sort
Imagine que tu tries des cartes en regardant leurs chiffres un par un, de droite à gauche.
Chaque nombre reçoit d'abord un index — 0 pour le plus petit, n-1 pour le plus grand. On travaille ensuite sur ces index en binaire, par exemple avec 8 nombres les index vont de 000 à 111.
On fait plusieurs passages, un par bit. Au premier passage on regarde uniquement le bit le plus à droite. Chaque index dont ce bit vaut 0 est envoyé dans stack B, chaque index dont ce bit vaut 1 reste dans stack A via un rotate. Une fois tout le monde traité, on remet stack B dans stack A. Le premier passage est terminé.
On recommence exactement pareil pour le deuxième bit, puis le troisième, et ainsi de suite jusqu'au dernier bit.
Ce qui est élégant c'est qu'après chaque passage les nombres sont un peu mieux groupés, et après le dernier passage ils sont parfaitement ordonnés — sans jamais avoir comparé deux éléments entre eux. L'algorithme ne se demande jamais "est-ce que A est plus grand que B", il lit juste des bits un par un.
En pratique pour 500 nombres il faut environ 9 passages (car 2⁹ = 512 > 500), ce qui donne un nombre d'opérations très prévisible et efficace.

## Resources

https://www.geeksforgeeks.org/dsa/sorting-algorithms/
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
https://fr.scribd.com/document/636999723/Untitled
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.geeksforgeeks.org/c/c-program-for-radix-sort/
https://www.geeksforgeeks.org/dsa/radix-sort/
https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/visualize/
https://fr.wikipedia.org/wiki/Tri_par_sélection
