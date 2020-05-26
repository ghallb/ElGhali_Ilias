# BE_Board_SmartTuner

Notre projet est la simulation d'un accordeur intelligent de guitare.
Les détails du projet seront fournis sur le rapport.

Afin d'utiliser notre SmartTuner, nous expliquons dans ce README, les étapes à suivre.

En temps normal, si nous avions eu tout le matériel à disposition :
- L'utilisateur aura choisi la corde qu'il souhaite accorder en allumant un bouton correspondant à la note.
- L'utilisateur aurait jouer sa note à la guitare.
- Les moteurs auraient été cablés pour chaque piston de chaque corde, le capteur auraient détecté la note, et l'accordage auraient eu lieu, avec notamment des Leds et un écran permettant l'affichage de la note et sa justesse.

Ici, en simulation :

- Vous devrez entrer dans le répertoire ELGhali_Ilias puis src, et compiler une fois notre programme avec cette ligne de code :
g++ -Wall -Wextra -std=c++11 -pthread board.cpp core_simulation.cpp mydevices.\
cpp sketch_ino.cpp accordeur.cpp user.cpp -o arduino

- Ensuite vous devrez écrire cette ligne de commande pour exécuter le programme : ./arduino 

- Des indications s'affichent alors sur le Terminal que nous vous résummons ici.

- Pour choisir la corde que vous souhaiter accorder, vous devez renommer le fichier texte "corde" dans le répertoire scr. Voici les cordes que vous pouvez accorder correspondant au nom des cordes d'une guitare : "mi", "si", "sol","ré", "la", "MI".

- Tapez ensuite ok dans le terminal et appuyer sur Entrer.

- Jouer votre note : vous devrez taper au clavier à quel point la note que vous jouer est plus basse ou plus haute que la note fondamentale. Vous pouvez alors taper : "+", "++", "+++", "-", "--", "---" .
 
- La notation/code de la note correspondant à la corde s'affiche sur le screen :
e pour mi, B pour si, G pour sol, D pour ré, A pour la et E pour MI.

- Puis l'accordage commencera : vous pourrez constater sur le terminal : la EDrouge qui s'allume (si la note est de type + donc trop haute), la LEDbleu qui s'allume (si la note est de type - donc trop basse),le moteur de la bonne corde qui s'allume et qui tourne dans un sens positif (si la note est de type -), dans un sens négatif (si la note est de type +), la LEDrouge qui s'éteint et la LEDverte qui s'allume lorsque l'accordage est terminé. Evidemment, le temps d'accordage ne sera pas le même selon la corde et sa justesse.






