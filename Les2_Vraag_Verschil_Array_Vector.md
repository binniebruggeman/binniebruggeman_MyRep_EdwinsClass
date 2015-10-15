**Bekijk de verschillende varianten van de Bounce app in de "Les 2" repository. Wat is het verschil tussen de array- en de 'vector' varianten?**

Bij een array geef je van te voren aan hoeveel objecten er in de array zitten. Een vector is dynamisch; je kunt er objecten aan toevoegen en ook objecten verwijderen. 

Puur naar de code kijkend zit er een verschil in de file ofApp.h. In bounceOOVector wordt slechts een vector aangemaakt en in bounceOOArray wordt een array aangemaakt waarin vooraf het aantal ballen is bepaald, namelijk 20 (MAXBALLS). 

Daarnaast bevat ofApp.cpp ook verschillen. In de setup van bounceOOVector wordt het maximaal aantal ballen gedefinieerd in de for loop: 

for (int i=0; i<10; i++)

Zolang het aantal ballen kleiner is dan 10, voeg ballen toe. 

In de update en draw zie je dat bij de vector variant de term balls.size wordt gebruikt (dynamisch) en in de array variant de term MAXBALLS, (20 stuks).





