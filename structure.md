UN binary tree avec une root " " qui va de A à - (27 character).
Pas forcément 27 caractere parce que certaines combinaisons n'existenet pas + un pointeur vers NULL si le mot est bon.
Que les verbes a l'infinitf + forme simples de chaques mot qu'on conjugera et accordera après. 
Idée de stocker pronoms dans une array (peut etre structure qui contient leur singulier/pluriels et masculin/feminin).

Structure d'une node :{
  une array de pointeur vers d'autre nodes;
  char '';
  array de forme flechie : flechie[ ];
  
  
Structure d'un mot/forme fleché : 
  string mot;
  string temps;
  string genre;
  string nombre;
  
  
Definition d'un generatetree : t_tree();
Definition chercher mot : chercher_mot(p_node, string mot(au début = NULL));
